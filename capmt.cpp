#include "capmt.h"

void send_client_info(int socket)
{
	#define INFO_VERSION "dvbcam_tizen"
	#define DVBAPI_PROTOCOL_VERSION         2
	
	int len = sizeof(INFO_VERSION) - 1;                     //ignoring null termination
	unsigned char buff[7 + len];

	uint32_t req = htonl(DVBAPI_CLIENT_INFO);               //type of request
	memcpy(&buff[0], &req, 4);
	int16_t proto_version = htons(DVBAPI_PROTOCOL_VERSION); //supported protocol version
	memcpy(&buff[4], &proto_version, 2);
	buff[6] = len;
	memcpy(&buff[7], &INFO_VERSION, len);                   //copy info string
	write(socket, buff, sizeof(buff));
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int recv_server_info(int socket)
{
	uint32_t *request;
	unsigned char buff[262];	
  	int cRead = recv(socket, &buff[0], 6, 0);
	if (cRead == 6)
	{
		request = (uint32_t *) &buff;
		if (ntohl(*(uint32_t *) &buff) == DVBAPI_SERVER_INFO)
		{
		  unsigned char len;

		  uint16_t *proto_ver_ptr = (uint16_t *) &buff[4];
		  uint16_t protocol_version = ntohs(*proto_ver_ptr);

		  recv(socket, &len, 1, 0);               	//string length
		  recv(socket, buff+6, len, 0);
		  buff[6+len] = 0;                              //terminate the string
		  g_message("Got SERVER_INFO: %s, protocol_version = %d", &buff[6], protocol_version);
		  return 1;
		}
	}
	
	return 0;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void send_stop_dmx(int socket, char dmx)
{
	unsigned char cmd[8] = {0x9F, 0x80, 0x3f, 0x04, 0x83, 0x02, 0x00}; 
	cmd[7] = dmx;
		
	write(socket, cmd, 8);
	g_message("Stop descrambling sent for dmx %d", dmx);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void send_filter_data(int socket, char idx, char flt, unsigned char *data, int len)
{
  unsigned char buff[6 + len];

  uint32_t req = htonl(DVBAPI_FILTER_DATA);             //type of request
  memcpy(&buff[0], &req, 4);
  buff[4] = idx;                                   		//demux
  buff[5] = flt;                                   		//filter
  memcpy(buff + 6, data, len);                          //copy filter data
  write(socket, buff, sizeof(buff));
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void send_empty_capmt(int socket, char lm, uint16_t service_id, int idx)
{	
	uint8_t caPMT[17];
	
	//ca_pmt_tag
	caPMT[0] = 0x9F;
	caPMT[1] = 0x80;
	caPMT[2] = 0x32;
	caPMT[3] = 0x82;              //2 following bytes for size

	caPMT[4] = 0;				//packet length
	caPMT[5] = 11;
	
	caPMT[6] = lm; 				//list management
	caPMT[7] = service_id >> 8 ; 	        //program_number
	caPMT[8] = service_id & 0xFF;   	   	//program_number
	caPMT[9] = 0;               //version_number, current_next_indicator
	
	caPMT[10] = 0;            //reserved+program_info_length
	caPMT[11] = 0;          //reserved+program_info_length (+1 for ca_pmt_cmd_id, +4 for above CAPMT_DESC_DEMUX)
	
	caPMT[12] = 0x01;             //ca_pmt_cmd_id = CAPMT_CMD_OK_DESCRAMBLING
	//adding own descriptor with demux and adapter_id
	caPMT[13] = 0x82;           //CAPMT_DESC_DEMUX
	caPMT[14] = 0x02;           //length
	caPMT[15] = (char)idx;      //demux id
	caPMT[16] = (char)idx;   	//adapter id

	write(socket, caPMT, 17);	
}

void send_pmt(int socket, char lm, unsigned char* buf, int idx)
{	
	int len = 3 + ((buf[1] & 0x0F) << 8) + buf[2];
	if( len > 4096 )
	{
		g_message("Unable to send pmt, wrong length: %d", len);
		return;
	}
	
	unsigned char caPMT[4112]; 
	int program_info_length = ((buf[10] & 0x0F) << 8) + buf[11] + 4 + 1;	//program_info_length (+1 for ca_pmt_cmd_id, +4 for CAPMT_DESC_DEMUX)
	int length_field = len - 5;	// 17 - 6 + len - 4 - 12

	//ca_pmt_tag
	caPMT[0] = 0x9F;
	caPMT[1] = 0x80;
	caPMT[2] = 0x32;
	caPMT[3] = 0x82;              //2 following bytes for size

	caPMT[4] = length_field >> 8;
	caPMT[5] = length_field & 0xff;
	
	caPMT[6] = lm; 				//list management
	caPMT[7] = buf[3];          //program_number
	caPMT[8] = buf[4];        	//program_number
	caPMT[9] = 0;               //version_number, current_next_indicator
	
	caPMT[10] = program_info_length >> 8;            //reserved+program_info_length
	caPMT[11] = program_info_length & 0xFF;          //reserved+program_info_length (+1 for ca_pmt_cmd_id, +4 for above CAPMT_DESC_DEMUX)
	
	caPMT[12] = 0x01;             //ca_pmt_cmd_id = CAPMT_CMD_OK_DESCRAMBLING
	//adding own descriptor with demux and adapter_id
	caPMT[13] = 0x82;           //CAPMT_DESC_DEMUX
	caPMT[14] = 0x02;           //length
	caPMT[15] = (char)idx;      //demux id
	caPMT[16] = (char)idx;  	//adapter id

	memcpy(caPMT + 17, buf + 12, len - 16);  //copy pmt data starting at program_info block

	write(socket, caPMT, length_field + 6);	// dont send the last 4 bytes (CRC)
	
	g_message("PMT sent for demux: %d", idx);
}