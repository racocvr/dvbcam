/*
	dvbcam - MrB 2021
*/

#include <glib.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <sys/unistd.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <signal.h>
#include <arpa/inet.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <fstream>
#include <string>
#include <unordered_set>

#include <include/uapi/linux/dvb/ca.h>
#include <linux/dvb/dmx.h>

#include "tvs-api/TVServiceAPI.h"
#include "capmt.h"
#include "gst-ext-lib.h"

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

typedef struct profile {
	uint8_t bank;						// dvb bank id
	std::map<uint8_t, int32_t> filters;	// array of handlers to the created ts section filters	<idx, handle>		
	uint8_t cw[16];						// copy of currently used cw [8 * parity0 + 8 * parity1]
} profile_t;

#define MAX_PMTSIZE 4096
 
typedef struct demux {
	int32_t program_number;						// currently played program (-1 if none)
	TCServiceId service_id;						// corresponding service id
	std::map<uint32_t, profile_t> profiles;		// tv profiles tuned on this program
	uint8_t pmt[MAX_PMTSIZE];
} oscam_demux_t;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#define capmt_socket_name "/tmp/.listen.camd.socket"
int g_socket = -1;

#define MAX_DEMUX 2						// one per tv tuner
oscam_demux_t g_demux[MAX_DEMUX];

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void fatal_error( const char* str );
static int onTTSignalCallback(ESignalType stype, EProfile profile, uint16_t screen_id, TSSignalData sigdata, void* pUserData);
static void onSection( bool isDone, unsigned short length, unsigned char* pData, int userParam );

const char* to_str( ESignalType stype )
{
	return stype == SIGNAL_TUNE_SUCCESS ? "SIGNAL_TUNE_SUCCESS" : stype == SIGNAL_TUNE_STOP ? "SIGNAL_TUNE_STOP" : "SIGNAL_UNKNOWN";
}

const char* to_str( EProfile profile )
{
	return profile == PROFILE_TYPE_MAIN ? "PROFILE_TYPE_MAIN" : profile == PROFILE_TYPE_PIP ? "PROFILE_TYPE_PIP" : profile == PROFILE_TYPE_RECORD ? "PROFILE_TYPE_RECORD" : "PROFILE_TYPE_UNKNOWN";
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#define PS_PLAY_START			0
#define PS_PLAY_STOP			7
#define PS_RECORD_START			8
#define PS_RECORD_STOP			11
#define PS_STOP_PVR				13

#define PS_RECORD_STATE_STOP		0
#define PS_RECORD_STATE_PREPARING	1
#define PS_RECORD_STATE_REC			2
#define PS_RECORD_STATE_PENDING		3
#define PS_RECORD_STATE_PAUSE		4
#define PS_RECORD_STATE_MAX			5

#define PS_SIGNAL_TYPE_RECORD_STATE_CHANGE 	1

typedef struct ps_signal
{
	uint32_t 	signal_type;
	uint32_t	useless_data;
	uint32_t 	handle;
	uint32_t	service_id[2];	// for some reason using uint64_t here desyncs the struct on the callback
	uint32_t	profile;
	uint32_t	screen_id;
	uint8_t		uri[255];
	uint8_t 	record_state;
	uint32_t	useless_data2[2];
} ps_signal_t;

typedef void (*pvr_signal_cb)( ps_signal_t signal, void* userparam );

extern "C" 
{
int svc_pvr_service_init();
int svc_pvr_register_signal_cb( pvr_signal_cb cb, void* userparam );
int svc_pvr_unregister_signal_cb( pvr_signal_cb cb );
}

void on_pvr_signal(ps_signal_t signal, void* userparam)
{
	if( userparam != (void*)0xdeadbeef )
		fatal_error("on_pvr_signal: signal data not in sync");
	
	if(signal.signal_type == PS_SIGNAL_TYPE_RECORD_STATE_CHANGE && signal.record_state == PS_RECORD_STATE_STOP)
	{	
		TCServiceId service_id = signal.service_id[0] + ((TCServiceId)(signal.service_id[1]) << 32);
		TSSignalData sigdata = {service_id};
		int8_t screen_id = signal.screen_id;
		
		g_message("%s: service_id=%llx, profile=%d, screen_id=%d", __func__, service_id, signal.profile, screen_id);
		
		// on record error, screen_id == -1, therefore get it from dmx
		if(screen_id == -1)
		{			
			for( int i = 0; i < MAX_DEMUX; i++ )
				if(g_demux[i].service_id == service_id)
					for (auto && p : g_demux[i].profiles)
						if( (EProfile)(p.first & 0xFFFF) == PROFILE_TYPE_RECORD )
						{
							screen_id = p.first >> 16;
							break;
						}
		}

		onTTSignalCallback(SIGNAL_TUNE_STOP, (EProfile)signal.profile, screen_id, sigdata, 0);
	}	
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void init_demux()
{
	for( int i = 0; i < MAX_DEMUX; i++ )
	{		
		g_demux[i].program_number = -1;				
		g_demux[i].service_id = 0;
		g_demux[i].profiles.clear();
		memset(g_demux[i].pmt, 0, sizeof(uint8_t) * MAX_PMTSIZE);
	}			
}

int get_demux_index_by_program_number( int32_t program_number )
{
	if(program_number > -1)
		for( int i = 0; i < MAX_DEMUX; i++ )
			if(g_demux[i].program_number == program_number )
				return i;
			
	return -1;
}

int get_demux_index_by_profile( uint32_t profile )
{
	for( int i = 0; i < MAX_DEMUX; i++ )		
		for (auto && x : g_demux[i].profiles)
			if(x.first == profile)
				return i;
		
	return -1;
}

int get_free_demux_index()
{
	for( int i = 0; i < MAX_DEMUX; i++ )
		if(g_demux[i].program_number == -1)
			return i;
		
	fatal_error("get_free_demux_index: no free demux found");
		
	return -1;
}

void print_demuxes()
{	
	g_message("---------------------------------------------------");
	for( int i = 0; i < MAX_DEMUX; i++ )
	{		
		g_message("demux: %d, program_number: 0x%04X, service_id: %llx", i, g_demux[i].program_number, g_demux[i].service_id);
		
		for (auto && p : g_demux[i].profiles)
			g_message("profile: %d", p.first);			
	}
	g_message("---------------------------------------------------");
}

void swap_demux( int32_t i, int32_t j )
{		
	oscam_demux_t tmp;
	
	// copy i to tmp
	tmp.program_number = g_demux[i].program_number;
	tmp.service_id = g_demux[i].service_id;	
	tmp.profiles = g_demux[i].profiles;
	memcpy(tmp.pmt, g_demux[i].pmt, MAX_PMTSIZE);
	
	// copy j to i
	g_demux[i].program_number = g_demux[j].program_number;
	g_demux[i].service_id = g_demux[j].service_id;	
	g_demux[i].profiles = g_demux[j].profiles;
	memcpy(g_demux[i].pmt, g_demux[j].pmt, MAX_PMTSIZE);
	
	// copy tmp to j
	g_demux[j].program_number = tmp.program_number;
	g_demux[j].service_id = tmp.service_id;	
	g_demux[j].profiles = tmp.profiles;
	memcpy(g_demux[j].pmt, tmp.pmt, MAX_PMTSIZE);
}

void remove_unused_demuxes()
{	
	g_message("removing unused demuxes");
	
	for(int i = 0; i < MAX_DEMUX - 1; i++)
		if(g_demux[i].program_number == -1)
			for(int j = i; j < MAX_DEMUX - 1; j++)
				swap_demux(j, j + 1);
			
	print_demuxes();
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int32_t get_program_number( EProfile profile, uint16_t screen_id )
{
	IServiceNavigation* pServiceNavigation;
	TVServiceAPI::CreateServiceNavigation(profile, screen_id, &pServiceNavigation);
			
	TCCriteriaHelper fetchCriteria;			
	fetchCriteria.Fetch(PROGRAM_NUMBER);
	fetchCriteria.Fetch(SCRAMBLED_IN_PMT);
	fetchCriteria.Fetch(SCRAMBLED);
	TCServiceData service;
	
	if( !pServiceNavigation->GetCurrentServiceInfo(fetchCriteria, service) )
		fatal_error("get_program_number: GetCurrentServiceInfo failed");
	
	return (int32_t)(service.Get<unsigned short>(PROGRAM_NUMBER) + 0x80000000 * !(service.Get<bool>(SCRAMBLED_IN_PMT) || service.Get<bool>(SCRAMBLED)));
}

TCServiceId get_service_id( EProfile profile, uint16_t screen_id )
{
	IServiceNavigation* pServiceNavigation;
	TVServiceAPI::CreateServiceNavigation(profile, screen_id, &pServiceNavigation);
			
	TCCriteriaHelper fetchCriteria;			
	fetchCriteria.Fetch(SERVICE_ID);
	TCServiceData service;
	
	if( !pServiceNavigation->GetCurrentServiceInfo(fetchCriteria, service) )
		fatal_error("get_program_number: GetCurrentServiceInfo failed");
	
	return service.Get<TCServiceId>(SERVICE_ID);
}

int32_t get_bank( EProfile profile, uint16_t screen_id )
{
	IAVControl* pAVControl;
	TVServiceAPI::CreateAVControl(profile, screen_id, &pAVControl);
	
	uint32_t bank;
	if( !pAVControl->GetTVStreamProperty( TVSTREAM_PROPERTY_DEMUX_ID, bank ) )
		bank = -1;
	
	g_message("%s: profile=%d, screen_id=%d, bank=%d", __func__, profile, screen_id, bank);
	
	return (int32_t)bank;
}

void set_descrambling( uint8_t bank, bool enabled )
{
	int32_t device_fd;
	char device_name[128] = {0};
	sprintf(device_name, "/dev/dvb/adapter0/demux%d\0", bank);
	
	if( (device_fd = open(device_name, O_RDONLY)) < 0 )
		g_message("Unable to open device %s (%d): %s", device_name, errno, strerror(errno));

	ca_config_t cfg = { .mode = enabled ? 1 : 0, .matching_type = 0, .ca_type = enabled ? DMX_CA_DVB_CSA : DMX_CA_BYPASS, .pid = 0, .keyidx = 0, .use_hcas = 0 };
	if( ioctl(device_fd, SDP_SET_CA_CTRL, &cfg) )
		g_message("ioctl failed: (device_fd=%d)=%d, bank=%d", device_fd, -1, bank);
		
	close(device_fd);
}

void set_cw( uint32_t bank, uint8_t *cw )
{	
	uint8_t key[256];
	uint32_t outlen;
	
	g_message("%s: bank=%d", __func__, bank);		
	
	void* ctx = pvr_drm_client_context_create();
	if(ctx)
	{
//		if( pvr_drm_client_player_stop_decrypt(ctx) )
//			g_message("%s: pvr_drm_client_player_stop_decrypt failed!", __func__);
		
		if( pvr_drm_client_jackpack_convert_key(ctx, cw, 16, 20110906, key, &outlen) )
			g_message("%s: pvr_drm_client_jackpack_convert_key failed!", __func__);
		
		if( pvr_drm_client_player_start_decrypt(ctx, 0, bank, key, 16, 0) )
			g_message("%s: pvr_drm_client_player_start_decrypt failed!", __func__);
		
		pvr_drm_client_context_destroy(ctx);
	}	
}

void add_profile( uint8_t dmx, uint32_t profile, uint32_t program_number, TCServiceId service_id )
{	
	g_demux[dmx].program_number = program_number;
	g_demux[dmx].service_id = service_id;
		
	// add or update profile to demux
	g_demux[dmx].profiles[profile].bank = get_bank((EProfile)(profile & 0xFFFF), (uint16_t)(profile >> 16));
	
	// enable descrambling
	set_descrambling(g_demux[dmx].profiles[profile].bank, true);
	
	g_message("%s: dmx=%d, profile=%s, screen_id=%d, program number=0x%04x, service_id=%llx, bank=%d", __func__, dmx, to_str((EProfile)(profile & 0xFFFF)), profile >> 16, program_number, service_id, g_demux[dmx].profiles[profile].bank);	
}

void remove_profile( uint8_t dmx, uint32_t profile )
{
	// stop descrambling on bank
	void* ctx = pvr_drm_client_context_create();
	if(ctx)
	{
		if( pvr_drm_client_player_stop_decrypt(ctx) )
			g_message("%s: pvr_drm_client_player_stop_decrypt failed!", __func__);
		
		pvr_drm_client_context_destroy(ctx);
	}

	set_descrambling(g_demux[dmx].profiles[profile].bank, false);
		
	// stop section filters
	ISectionSubscriber* pSectionSubscriber = NULL;
	TVServiceAPI::CreateSectionSubscriber( &onSection, (EProfile)(profile & 0xFFFF), (uint16_t)(profile >> 16), &pSectionSubscriber );
	
	for (auto && x : g_demux[dmx].profiles[profile].filters)
		if( x.second > 0 )			
			g_message("pSectionSubscriber->Unsubscribe=%d, h=%d, profile=%d", pSectionSubscriber->Unsubscribe( x.second ), x.second, profile);
	
	g_demux[dmx].profiles[profile].filters.clear();	
	g_demux[dmx].profiles.erase(profile);
	
	g_message("%s: dmx=%d, %s, screen_id=%d", __func__, dmx, to_str((EProfile)(profile & 0xFFFF)), profile >> 16);
		
	if(g_demux[dmx].profiles.size() == 0)
	{
		g_demux[dmx].program_number = -1;
		g_demux[dmx].service_id = 0;
		send_stop_dmx( g_socket, dmx );	
	}
}

void reset_current_channel(EProfile profile, uint16_t screen_id)
{	
	if(get_bank( profile, screen_id ) < 0)
		return;
	
	IServiceNavigation* serviceNav;
	TVServiceAPI::CreateServiceNavigation(profile, screen_id, &serviceNav);
	
	TCServiceId serviceId;
	ESource source;
	if(serviceNav->GetStartService(serviceId, source) > 0)
	{
		if(source == SOURCE_TYPE_TV)
		{
			TSSignalData sigdata = {serviceId};
			onTTSignalCallback(SIGNAL_TUNE_SUCCESS, profile, screen_id, sigdata, 0);
		}
	}
	else
		fatal_error("reset_current_channel: GetStartService failed");
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

static void onSection( bool isDone, unsigned short length, unsigned char* pData, int userParam )
{	
	uint8_t dmx = userParam & 0xFF;
	uint8_t flt = (userParam >> 8) & 0xFF;

	g_message( "%s: dmx=%d, flt=%d, [%02X %02X %02X %02X %02X %02X %02X %02X ...]", __func__, dmx, flt, pData[0], pData[1], pData[2], pData[3], pData[4], pData[5], pData[6], pData[7] );
		
	if(flt == 255)
	{
		int dmx = get_demux_index_by_program_number( (pData[3] << 8) + pData[4] );
		g_message("%s: got PMT for dmx=%d, program_number=0x%04X, length=%d", __func__, dmx, (pData[3] << 8) + pData[4], length);
		
		memcpy(g_demux[dmx].pmt, pData, length);
		
		remove_unused_demuxes();
					
		for(int i = 0; i < MAX_DEMUX; i++)
			if(g_demux[i].program_number > -1)
				send_pmt( g_socket, i == 0 ? CAPMT_LIST_ONLY : CAPMT_LIST_MORE, g_demux[i].pmt, i );
	}
	else
		send_filter_data( g_socket, dmx, flt, pData, length );
}

static int onTTSignalCallback(ESignalType stype, EProfile profile, uint16_t screen_id, TSSignalData sigdata, void* pUserData)
{		
	TCServiceId service_id = get_service_id(profile, screen_id);
	int32_t program_number = get_program_number(profile, screen_id);
	uint32_t profile_tag = ((uint32_t)screen_id << 16) + profile;
		
	// find a demux using this program number
	int dmx = get_demux_index_by_program_number(program_number);
	
	// find a demux using this profile
	int d = get_demux_index_by_profile(profile_tag);

	g_message("ESignalType=%s, EProfile=%s, screen_id=%d, program_number=0x%08X, dmx=%d, d=%d", to_str(stype), to_str(profile), screen_id, program_number, dmx, d);
	
	if(stype == SIGNAL_TUNE_STOP && d > -1)
		remove_profile( d, profile_tag );
		
	if(stype == SIGNAL_TUNE_SUCCESS)
	{
		// exists demux for profile? (aka channel change)		
		if(d > -1)
		{
			g_message("channel change on %s, screen_id=%d, dmx=%d", to_str(profile), screen_id, d);
			
			// then stop the profile and possibly the demux
			remove_profile( d, profile_tag );
		}
		
		// if channel is scrambled
		if( !(program_number & 0x80000000) )
		{				
			// if exist a demux for program number
			if (dmx > -1)			
				// stop it, since it will be restarted
				send_stop_dmx( g_socket, dmx );			
			else
				// start new demux			
				dmx = get_free_demux_index();			
									
			// add the channel to the demux
			add_profile( dmx, profile_tag, program_number, service_id );
												
			// start PMT filter					
			TCSectionCriteriaHelper sectionHelper;
			sectionHelper.pid = INVALID;
			sectionHelper.tableId = 0x02;	// PMT
			sectionHelper.programNumber = program_number;
			sectionHelper.device = DEVICE_INBAND;
			sectionHelper.subscribeType = SECTION_SUBSCRIBE_CACHE_OR_STREAM;
			sectionHelper.checkVersion = true;
			
			int userParam = (255 << 8) + dmx;
			ISectionSubscriber* pSectionSubscriber = NULL;
			TVServiceAPI::CreateSectionSubscriber( &onSection, profile, screen_id, &pSectionSubscriber );
									
			g_message("PMT Subscribe=%d, handle=%d", pSectionSubscriber->Subscribe( userParam, sectionHelper, g_demux[dmx].profiles[profile_tag].filters[255] ), g_demux[dmx].profiles[profile_tag].filters[255] );
		}
	}
	
	print_demuxes();
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void camd_connection_handler(int socket_desc)
{
    //Get the socket descriptor
    g_socket = socket_desc;
	
	init_demux();
	
	send_client_info(g_socket);
	if(!recv_server_info(g_socket))
		return;
			
	// subscribe to tvs-api signals
	ISignalSubscriber* pSignalSubscriber = NULL;		
	TVServiceAPI::CreateSignalSubscriber(&onTTSignalCallback, &pSignalSubscriber);

	for(int screen_id = 0; screen_id < 2; screen_id++)
	{
		pSignalSubscriber->Subscribe(SIGNAL_TUNE_SUCCESS, 0, PROFILE_TYPE_PIP, screen_id);
		pSignalSubscriber->Subscribe(SIGNAL_TUNE_SUCCESS, 0, PROFILE_TYPE_MAIN, screen_id);
		pSignalSubscriber->Subscribe(SIGNAL_TUNE_SUCCESS, 0, PROFILE_TYPE_RECORD, screen_id);
		pSignalSubscriber->Subscribe(SIGNAL_TUNE_STOP, 0, PROFILE_TYPE_PIP, screen_id);
		pSignalSubscriber->Subscribe(SIGNAL_TUNE_STOP, 0, PROFILE_TYPE_MAIN, screen_id);
		pSignalSubscriber->Subscribe(SIGNAL_TUNE_STOP, 0, PROFILE_TYPE_RECORD, screen_id);	
	}
	
	// subscribe to pvr signals
	g_message("svc_pvr_register_signal_cb=%d", svc_pvr_register_signal_cb(on_pvr_signal, (void*)0xdeadbeef));

	reset_current_channel(PROFILE_TYPE_MAIN, DEFAULT_SCREEN_ID);
	reset_current_channel(PROFILE_TYPE_PIP, DEFAULT_SCREEN_ID);
					
	uint8_t buff[1024];
	int32_t nread;
	uint32_t *request;
	uint8_t adapter_index;
		
	// request
	while (1)	
	{ 	
		nread = recv(g_socket, buff, sizeof(int), MSG_DONTWAIT);
		if (nread <= 0)
		{
			if (nread == 0)
				break;
			usleep(20);
			continue;
		}

		request = (uint32_t *) &buff;
				
	    if (ntohl(*request) != DVBAPI_SERVER_INFO)
		{
			// first byte -> adapter_index
			nread = recv(g_socket, &adapter_index, 1, MSG_DONTWAIT);
			if (nread <= 0)
			{
				if (nread == 0)
					break;
				usleep(20);
				continue;
			}
		}
		
		*request = ntohl(*request);

		if (*request == CA_SET_PID)
		  nread = recv(g_socket, buff+4, sizeof(ca_pid_t), MSG_DONTWAIT);
		else if (*request == DVBAPI_ECM_INFO)
		  nread = recv(g_socket, buff+4, 14, MSG_DONTWAIT);
		else if (*request == CA_SET_DESCR)
		  nread = recv(g_socket, buff+4, sizeof(ca_descr_t), MSG_DONTWAIT);
		else if (*request == DMX_SET_FILTER)
		  nread = recv(g_socket, buff+4, sizeof(dmx_sct_filter_params), MSG_DONTWAIT);
		else if (*request == DMX_STOP)
		  nread = recv(g_socket, buff+4, 2 + 2, MSG_DONTWAIT);
		else
		{		  
			g_message("unknown request received");
			usleep(20);
			continue;
		}
		
		if (nread <= 0)
		{
			if (nread == 0)
				break;
			usleep(20);
			continue;
		}			
		
		if (*request == DVBAPI_ECM_INFO)
		{						
			//g_message("Got DVBAPI_ECM_INFO");
			
			// read 4 strings + 1 byte (hops)
			int p = 14;
			for(int i = 0; i < 4; i++)
			{
				nread = recv(g_socket, buff + p, 1, MSG_DONTWAIT);					// strlen				
				nread = recv(g_socket, buff + p + 1, buff[p], MSG_DONTWAIT);		// str
				p += buff[p] + 1;				
			}			
			
			nread = recv(g_socket, buff + p, 1, MSG_DONTWAIT);		// hops						
		}
		else if (*request == CA_SET_PID)
		{								
			//g_message("Got CA_SET_PID request, adapter=%d, idx=%d, pid=0x%04X", adapter_index, ca_pid.index, ca_pid.pid);			
		}
		else if (*request == CA_SET_DESCR)
		{
			ca_descr_t ca_descr;						
			memcpy(&ca_descr, &buff[sizeof(int)], sizeof(ca_descr_t));
			ca_descr.index = ntohl(ca_descr.index);
			ca_descr.parity = ntohl(ca_descr.parity);	// 0:odd, 1:even
			
			uint8_t dmx = adapter_index;
													
			g_message("Got CA_SET_DESCR request, adapter=%d, idx=%d, cw parity=%d", adapter_index, ca_descr.index, ca_descr.parity);
					
			if(dmx >= MAX_DEMUX) fatal_error("demux idx greater than MAX_DEMUX");
			
			for (auto && x : g_demux[dmx].profiles)
			{									
				memcpy( &x.second.cw[8 * ca_descr.parity], ca_descr.cw, 8 );						
				set_cw( x.second.bank, x.second.cw );
			}
		}		
		else if (*request == DMX_SET_FILTER)
		{				
			uint8_t dmx = buff[4];
			uint8_t flt = buff[5];			
			uint16_t pid = ntohs(*((uint16_t *) &buff[6]));
						
			g_message("Got DMX_SET_FILTER request, idx=0x%02X, flt=0x%02X, pid=0x%04X, tableid=0x%02X, mask=0x%02X", dmx, flt, pid, buff[8], buff[24]);
			
			if(dmx >= MAX_DEMUX) fatal_error("demux idx greater than MAX_DEMUX");
						
			#define MAX_FILTER_SIZE 12	// 16 doesn't work
			
			TCSectionFilterCriteriaHelper filterCriteria;
	
			filterCriteria.filter.resize(MAX_FILTER_SIZE);
			filterCriteria.mask.resize(MAX_FILTER_SIZE);
			filterCriteria.invert.resize(MAX_FILTER_SIZE);
			
			filterCriteria.pid = pid;			
			filterCriteria.filter[0] = buff[8];
			filterCriteria.mask[0] = buff[24];
			filterCriteria.checkCRC = true;
					
			memcpy(&filterCriteria.filter[3], &buff[9], MAX_FILTER_SIZE - 3);
			memcpy(&filterCriteria.mask[3], &buff[25], MAX_FILTER_SIZE - 3);	
			memset(&filterCriteria.invert[0], 0, sizeof(filterCriteria.invert[0]) * MAX_FILTER_SIZE);
			
			uint32_t userParam = (flt << 8) + dmx;
			
			for (auto && x : g_demux[dmx].profiles)
			{			
				ISectionSubscriber* pSectionSubscriber = NULL;
				TVServiceAPI::CreateSectionSubscriber( &onSection, (EProfile)(x.first & 0xFFFF), x.first >> 16, &pSectionSubscriber );
				
				if( x.second.filters[flt] > 0 )
					g_message("pSectionSubscriber->Unsubscribe=%d, h=%d, profile=%d", pSectionSubscriber->Unsubscribe( x.second.filters[flt] ), x.second.filters[flt], x.first);

				g_message("pSectionSubscriber->SubscribeByFilter=%d, h=%d, profile=%d", pSectionSubscriber->SubscribeByFilter( userParam, filterCriteria, x.second.filters[flt] ), x.second.filters[flt], x.first);
			}
		}
		else if (*request == DMX_STOP)
		{			
			uint8_t dmx = buff[4];
			uint8_t flt = buff[5];
			uint16_t pid = ntohs(*((uint16_t *) &buff[6]));
			
			g_message("Got DMX_STOP request, idx=0x%02X, flt=0x%02X, pid=0x%04X", dmx, flt, pid);
			
			if(dmx >= MAX_DEMUX) fatal_error("demux idx greater than MAX_DEMUX");
			
			for (auto && x : g_demux[dmx].profiles)
			{
				ISectionSubscriber* pSectionSubscriber = NULL;
				TVServiceAPI::CreateSectionSubscriber( &onSection, (EProfile)(x.first & 0xFFFF), x.first >> 16, &pSectionSubscriber );
				
				if( x.second.filters[flt] > 0 )
					g_message("pSectionSubscriber->Unsubscribe=%d, h=%d, profile=%d", pSectionSubscriber->Unsubscribe( x.second.filters[flt] ), x.second.filters[flt], x.first);
				
				x.second.filters[flt] = 0;
			}
		}
		else
			g_message("unhandled data found");
	}	

	for(int screen_id = 0; screen_id < 2; screen_id++)
	{
		pSignalSubscriber->Unsubscribe(SIGNAL_TUNE_SUCCESS, PROFILE_TYPE_PIP, screen_id);
		pSignalSubscriber->Unsubscribe(SIGNAL_TUNE_SUCCESS, PROFILE_TYPE_MAIN, screen_id);
		pSignalSubscriber->Unsubscribe(SIGNAL_TUNE_SUCCESS, PROFILE_TYPE_RECORD, screen_id);
		pSignalSubscriber->Unsubscribe(SIGNAL_TUNE_STOP, PROFILE_TYPE_PIP, screen_id);
		pSignalSubscriber->Unsubscribe(SIGNAL_TUNE_STOP, PROFILE_TYPE_MAIN, screen_id);
		pSignalSubscriber->Unsubscribe(SIGNAL_TUNE_STOP, PROFILE_TYPE_RECORD, screen_id);
	}
	
//	g_message("svc_pvr_unregister_signal_cb=%d", svc_pvr_unregister_signal_cb(on_pvr_signal));
       
	close(g_socket);
	g_socket = -1;
	g_message("Client disconnected");    
} 

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

static gpointer camd_socket_handler_thread_start( gpointer _data )
{						
	int socket_desc, client_sock, c;    
	struct sockaddr_un server, client;
	
	unlink(capmt_socket_name);
		     
    //Create socket
    socket_desc = socket(AF_UNIX, SOCK_STREAM, 0);
    if (socket_desc == -1)
    {        
		g_message("Could not create socket: %s", capmt_socket_name);
		return NULL;
    }
     
    //Prepare the sockaddr_un structure
	server.sun_family = AF_UNIX;
    strcpy(server.sun_path, capmt_socket_name);
     
    //Bind
    if( bind(socket_desc,(struct sockaddr *)&server , sizeof(struct sockaddr_un)) < 0)
    {
        //print the error message
		g_message("Socket bind failed: %s", capmt_socket_name);
        return NULL;
    }
     
    //Listen
    listen(socket_desc , 3);
     
    //Accept an incoming connection
	g_message("Waiting for incoming connections...");
    c = sizeof(struct sockaddr_un);
	
    while( (client_sock = accept(socket_desc, (struct sockaddr *)&client, (socklen_t*)&c)) )
    {
        g_message("Client connected");
		camd_connection_handler(client_sock);
    }
     
    if (client_sock < 0)
    {
		g_message("Accept failed");
        return NULL;
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void termination_handler (int signum)
{
	svc_pvr_unregister_signal_cb(on_pvr_signal);	
	
	TVServiceAPI::Destroy();
	
	close(g_socket);	
	unlink(capmt_socket_name);
		
	g_message("exit successful");
		
	exit(EXIT_SUCCESS);
}

static void log_handler_cb( const gchar *log_domain, GLogLevelFlags  log_level, const gchar *message, gpointer user_data )
{	
	g_printerr ("(%s): %s\n", g_date_time_format( g_date_time_new_now_local(), "%H:%M:%S" ), message);    
}

std::string get_fw_version()
{	
	std::ifstream file( "/etc/prd_info.ini");
	std::string   line;
	
	while( std::getline(file, line) )
	{
		std::string::size_type n = line.find("Version=");
		
		if(n != std::string::npos)
			return line.substr(n + 8, line.length() - 8 - 1);
	}
	
	return "unknown version";	
}

void fatal_error( const char* str )
{
	g_message("FATAL ERROR: %s", str);	
	termination_handler(0);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main( int argc, char *argv[] ) 
{
	g_log_set_handler(G_LOG_DOMAIN, G_LOG_LEVEL_MASK, log_handler_cb, NULL);
	
	g_message("### dvbcam (build %s) [%s] - MrB 2021 ###", SVN_REV, get_fw_version().c_str());	
	g_message("svc_pvr_service_init=%d", svc_pvr_service_init());
	
	// some clean up is required before exit
	if (signal (SIGINT, termination_handler) == SIG_IGN)
		signal (SIGINT, SIG_IGN);
	if (signal (SIGHUP, termination_handler) == SIG_IGN)
		signal (SIGHUP, SIG_IGN);
	if (signal (SIGTERM, termination_handler) == SIG_IGN)
		signal (SIGTERM, SIG_IGN);
	
	// redirect stdout to /dev/null to stop annoying teec messages
//	freopen("/dev/null", "w", stdout);
		
	// start oscam socket handler thread
	g_thread_new(NULL, camd_socket_handler_thread_start, NULL);
						
	GMainLoop* loop = g_main_loop_new(NULL, FALSE);
	g_main_loop_run(loop);
}