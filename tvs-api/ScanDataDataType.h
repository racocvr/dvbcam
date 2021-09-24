/** 
 * @file ScanDataDataType.h
 * @brief Types for scan-related interfaces.
 *
 * Copyright 2013 by Samsung Electronics, Inc.,
 * 
 * This software is the confidential and proprietary information
 * of Samsung Electronics, Inc. ("Confidential Information"). You
 * shall not disclose such Confidential Information and shall use
 * it only in accordance with the terms of the license agreement
 * you entered into with Samsung.
 */

#ifndef _SCANDATADATATYPE_H_
#define _SCANDATADATATYPE_H_

#include "TVServiceDataType.h"
#include "Marshalable.h"
#include "ServiceDataType.h"
#include "ServiceNavigationDataType.h"
#include "SatelliteDataType.h"

struct TSScanInfo : public TCMarshalable
{
	enum
	{
		TAG_NUMBEROFCHANNELS,
	};

	int numberOfChannels;

	TSScanInfo();

	/**
	 * @brief Extract Tree from Class
	 * @param [inout] treeParent branch to which object data should be added
	 * @return true if success
	 */
	virtual bool ClassToTree(TCTreeBranch& treeParent);
	
	/**
	 * @brief Fill out Class from Tree
	 * @param [inout] treeMine branch from which object data should be fetched
	 * @return true if success
	 */
	virtual bool TreeToClass(TCTreeBranch& treeMine);

};

//ENUMS

typedef enum
{
	SCAN_STOP_USER,			///< User requested stop.
	SCAN_STOP_COMPLETE,		///< Scan complete stop.
	SCAN_STOP_FORCED,		///< Forced stop. this flag indicate user turn off/on TV while  autostore or locatehometp

}EScanStopRequest;

typedef enum
{
	COMMAND_STOP,						//!< Stop Command
	COMMAND_START,					//!<Start Command
	COMMAND_PAUSE,					//!<Pause Command
	COMMAND_RESUME,					//!<Resume Command
	COMMAND_STOP_FORCED,				//!< Forced Stop Command
}EScanCommand;

typedef enum
{
	MODE_STORE,		// Force saving scan options in NVRAM.
	MODE_RESTORE,	// Restore scan options values from NVRAM. 
}
EStoreMode;

typedef enum
{
	BROADCASTER_UNKNOWN = -1,
	BROADCASTER_NONE,
	BROADCASTER_MIN,
	BROADCASTER_TDC = BROADCASTER_MIN, //DENMARK CABLE
	BROADCASTER_TELIA_STOFA, //DENMARK
	BROADCASTER_COM_HEM,//SWEDEN CABLE
	BROADCASTER_ZIGGO, //NETHERLANDS CABLE
	BROADCASTER_CANAL_DIGITAL, //NORWAY CABLE
	BROADCASTER_GET, //NORWAY CABLE
	BROADCASTER_UPC, //NEHTERLANDS/SWISS CABLE
	BROADCASTER_GENERAL_CABLE, //General CABLE
	BROADCASTER_MEIDASET,//italy terrestrial
	BROADCASTER_NUMERICABLE,
	BROADCASTER_SMARTCITY, // DSmart cable network
	BROADCASTER_TELENET,	// Begium Cable
	BROADCASTER_BLIZOO,		// Bulgaria cable
	BROADCASTER_OTHER,
	BROADCASTER_SATELLITE_TIVU,
	BROADCASTER_SATELLITE_CANAL_DIGITAL,
	BROADCASTER_SATELLITE_FREE_SAT,
	BROADCASTER_SATELLITE_CD_TVV,
	BROADCASTER_SATELLITE_ASTRA_HD_PLUS,
	BROADCASTER_SATELLITE_DIGITAL_PLUS,
	BROADCASTER_SATELLITE_CYFRA_PLUS,
	BROADCASTER_SATELLITE_DSMART,
	BROADCASTER_SATELLITE_DIGITURK,
	BROADCASTER_SATELLITE_SKYD,
	BROADCASTER_SATELLITE_FRANSAT,
	BROADCASTER_SATELLITE_FREEVIEWNZ,
	BROADCASTER_SATELLITE_NNK,
	BROADCASTER_SATELLITE_ORF,
	BROADCASTER_SATELLITE_SKYLINK,
	BROADCASTER_SATELLITE_AIRTEL,
	BROADCASTER_SATELLITE_HD_AUSTRIA,
	BROADCASTER_SATELLITE_OTAU,
	BROADCASTER_RCS, //Romania Cable
	BROADCASTER_SATELLITE_MAGYARORSZAG,
	BROADCASTER_VIETNAM_VTV_CAB,
	BROADCASTER_VIETNAM_HTVC,
	BROADCASTER_VIETNAM_SCTV,
	BROADCASTER_SATELLITE_POLSAT,
	BROADCASTER_SATELLITE_TRICOLOR,
	BROADCASTER_SATELLITE_TELEKARTA,
	BROADCASTER_SATELLITE_NTV_PLUS,
	BROADCASTER_MTS_CABLE,
	BROADCASTER_SATELLITE_SUNDIRECT,
	BROADCASTER_ROSTELECOM,		// Russia cable
	BROADCASTER_VOO,	// Belgium cable	
	BROADCASTER_MAX,
}EBroadCaster;

typedef enum
{
	NETWORK_ID_AUTO,
	NETWORK_ID_MANUAL,
}ENetworkIDMode;

//OPTIONS

// OPTION_SCAN_MODE
typedef enum
{
	SCAN_MODE_UNKNOWN = INVALID,
												
	// KR ATSC
	SCAN_MODE_AIR_CABLE,

	// USA ATSC
	SCAN_MODE_AIR,										//!< AIR TV 채널 검색(미주향)
	SCAN_MODE_CABLE,									//!< Cable TV 채널 검색(미주향)

	// DVB - 구주향 AutoStore 는 DTV+ATV, DTV, ATV 세가지 모드가 존재하며 각각의 AutoProgramTable 을 관리 한다.
	SCAN_MODE_AIR_DIGITAL,								//!< TV Mode = AIR, Channel Type = Digital	채널만	검색(DVB)
	SCAN_MODE_AIR_ANALOG, 								//!< TV Mode = AIR, Channel Type = Analog 채널만 검색(DVB)
	SCAN_MODE_CABLE_DIGITAL,							//!< TV Mode = CABLE, Channel Type = Digital 채널만 검색(DVB)
	SCAN_MODE_CABLE_ANALOG,								//!< TV Mode = CABLE, Channel Type = Analog 채널만 검색(DVB)
	SCAN_MODE_TURBO_SCAN, 								//!< this mode is reated with Indian analogue turbe scan
	SCAN_MODE_AIR_ANALOG_SECAM,							//!< this mode is reated with secam france air analogue scan
	SCAN_MODE_CABLE_ANALOG_SECAM,						//!< this mode is reated with secam france air analogue scan
	SCAN_MODE_SATELLITE,								//!< Satellite
	SCAN_MODE_FREESAT,									//!< Freesat
	SCAN_MODE_TIVUSAT,									//!< TIVU SAT
	SCAN_MODE_CANALDIGITAL_SAT,							//!< Canal Digital SAT
	SCAN_MODE_CD_TVV_TELESAT, 							//!< TV Vlaanderen SAT - netherland sat
	SCAN_MODE_ASTRA_192E,								//!< Astra HD+
	SCAN_MODE_DIGITAL_PLUS,								//!< SogeCable
	SCAN_MODE_NC_PLUS, 									//!< Cyfra+
	SCAN_MODE_DSMART, 									//!< DSmart
	SCAN_MODE_DIGITURK,									//!< Digiturk
	SCAN_MODE_AIRTEL,									//!< AirTel
	SCAN_MODE_FRANSAT,
	SCAN_MODE_FREEVIEWNZ_SAT,
	SCAN_MODE_SKYLINK,									//!< Skylink
	SCAN_MODE_NNK,
	
	SCAN_MODE_DVBNT_AIR_DIGITAL,						//!< TV Mode = AIR, Channel Type = Digital	채널만	검색(DVBNT)
	SCAN_MODE_DVBNT_AIR_ANALOG,							//!< TV Mode = AIR, Channel Type = Analog 채널만 검색(DVBNT)
	SCAN_MODE_DVBNT_CABLE_DIGITAL,						//!< TV Mode = CABLE, Channel Type = Digital 채널만 검색(DVBNT)
	SCAN_MODE_DVBNT_CABLE_ANALOG, 						//!< TV Mode = CABLE, Channel Type = Analog 채널만 검색(DVBNT)

	SCAN_MODE_HD_AUSTRIA,								//!< HD Austria (M7)
	SCAN_MODE_OTAU,										//!< OTAU TV
	SCAN_MODE_MAGYARORSZAG,								//!< AustriaSat Magyarorszag
	SCAN_MODE_POLSAT,									//!<  Cyfrowy Polsat (satellite profile, available in Poland)
	SCAN_MODE_TRICOLOR,									//!< Tricolor TV (satellite profile, available in Russia)
	SCAN_MODE_TELEKARTA,								//!<  Telekarta (satellite profile, available in Russia)
	SCAN_MODE_NTV_PLUS,									//!<  NTV +  (satellite profile, available in Russia)

	SCAN_MODE_ISDBPAL_AIR_DIGITAL,						//!< TV Mode = AIR, Channel Type = Digital	채널만	검색(ISDBPAL)
	SCAN_MODE_ISDBPAL_AIR_ANALOG,						//!< TV Mode = AIR, Channel Type = Analog 채널만 검색(ISDBPAL)
	SCAN_MODE_ISDBPAL_CABLE_DIGITAL,					//!< TV Mode = CABLE, Channel Type = Digital 채널만 검색(ISDBPAL)
	SCAN_MODE_ISDBPAL_CABLE_ANALOG,					//!< TV Mode = CABLE, Channel Type = Analog 채널만 검색(ISDBPAL)	

	SCAN_MODE_SUNDIRECT,								//!<  SunDirect  (satellite profile, available in India)	
}EScanMode;

// OPTION_SCAN_NETWORK
typedef enum
{
	SCAN_NETWORK_UNKNOWN = INVALID,
	SCAN_NETWORK_CANALDIGITAL,
	SCAN_NETWORK_TV_VLAANDEREN,
	SCAN_NETWORK_SKYLINK_CZECH,
	SCAN_NETWORK_SKYLINK_SLOVAK,
	SCAN_NETWORK_TELESAT_BELGIUM,
	SCAN_NETWORK_TELESAT_LUXEMBOURG,
	SCAN_NETWORK_TRICOLOR_GENERAL,
	SCAN_NETWORK_TRICOLOR_SIBERIA,
	SCAN_NETWORK_TELEKARTA_HD,
	SCAN_NETWORK_TELEKARTA_VOSTOK,
	SCAN_NETWORK_NTV_PLUS,
	SCAN_NETWORK_NTV_PLUS_VOSTOK,
}EScanNetwork;

// OPTION_SCAN_TYPE
typedef enum
{
	SCAN_TYPE_UNKNOWN = INVALID,

	SCAN_TYPE_QUICK,
	SCAN_TYPE_FULL,

	SCAN_TYPE_SDU_EUTELSAT,
	SCAN_TYPE_SDU_TURKSAT,
	SCAN_TYPE_MDU1,
	SCAN_TYPE_MDU2,
	SCAN_TYPE_MDU3,
	SCAN_TYPE_MDU4,
	SCAN_TYPE_MDU5,
}EScanType;

// OPTION_CLEAN_SCAN
typedef enum
{
	CLEAN_SCAN_UNKNOWN = INVALID,
	CLEAN_SCAN_DISABLED,		// scanning keeps previous seervice list data (e.g. favourites, RCNs)
	CLEAN_SCAN_ENABLED,		// scanning creates service list from scratch, user data is removed
}ECleanScan;

// OPTION_NETWORK_SCAN
typedef enum
{
	NETWORK_SCAN_DISABLED, 	 // Network scan disabled.
	NETWORK_SCAN_ENABLED,		// Network scan enabled.
}ENetworkScan;

// OPTION_NETWORK_MODE
typedef enum
{
	NETWORK_MODE_CABLE, 			// Cable network
	NETWORK_MODE_SMATV_UNMANAGED,	// SMATV unmanaged network
}ENetworkMode;

// OPTION_CLOUD_SCAN
typedef enum
{
	CLOUD_SCAN_DISABLED, 	 // Cloud scan disabled.
	CLOUD_SCAN_ENABLED,		// Cloud scan enabled.
}ECloudScan;


// OPTION_SCAN_SERVICE_MODE
typedef enum
{
	SCAN_SERVICE_MODE_UNKNOWN = INVALID,
	SCAN_SERVICE_MODE_NONE,
	SCAN_SERVICE_MODE_ALL,
	SCAN_SERVICE_MODE_FREE,
	SCAN_SERVICE_MODE_SCRAMBLED,
}EScanServiceMode;

// OPTION_SCAN_SERVICE_TYPE
typedef enum
{
	SCAN_SERVICE_TYPE_ALL,	// store all services
	SCAN_SERVICE_TYPE_TV, 	// store only Tv services
	SCAN_SERVICE_TYPE_RADIO,	// store only Radio services
	SCAN_SERVICE_TYPE_DATA,	// store only Data services
}EScanServiceType;

// OPTION_SCAN_SERVICE_SELECTION
typedef enum
{
	SCAN_SERVICE_SELECTION_NONE = INVALID,
	SCAN_SERVICE_SELECTION_HD,		//!< HD services should have higher priority when allocating RCNs.
	SCAN_SERVICE_SELECTION_SD,
	SCAN_SERVICE_SELECTION_FREE,	//!< Free-to-air services should have higher priority when allocation RCNs.
}EScanServiceSelection;

// OPTION_HOMING_CHANNEL_MODE
typedef enum 
{
	HOMING_CHANNEL_MODE_AUTO,	// cable network 설정시 dedicated hometp로 scan
	HOMING_CHANNEL_MODE_MANUAL, //user가 지정한 home tp로 scan
}EHomingChannelMode;

// OPTION_FREQUENCY_SCAN_MODE
typedef enum
{
	FREQUENCY_SCAN_DIRECT,
	FREQUENCY_SCAN_UP,
	FREQUENCY_SCAN_DOWN,
}EFrequencyScanMode;

// OPTION_LNB_TELESUPPLY
typedef enum
{
	LNB_TELESUPPLY_DISABLED,
	LNB_TELESUPPLY_ENABLED,
}ELnbTelesupply;

// OPTION_FREEVIEWNZ_PLACE
typedef enum
{
	FREEVIEWNZ_PLACE_NORTHLAND,
	FREEVIEWNZ_PLACE_AUCKLAND,
	FREEVIEWNZ_PLACE_WAIKATO,
	FREEVIEWNZ_PLACE_ROTORUA,
	FREEVIEWNZ_PLACE_BAY_OF_PLENTY,
	FREEVIEWNZ_PLACE_TAUPO,
	FREEVIEWNZ_PLACE_GISBORNE,
	FREEVIEWNZ_PLACE_NAPIER,
	FREEVIEWNZ_PLACE_HASTINGS,
	FREEVIEWNZ_PLACE_TARANAKI,
	FREEVIEWNZ_PLACE_WANGANUI, 
	FREEVIEWNZ_PLACE_MANAWATU,
	FREEVIEWNZ_PLACE_WAIRARAPA,
	FREEVIEWNZ_PLACE_WELLINGTON, 
	FREEVIEWNZ_PLACE_WEST_COAST, 
	FREEVIEWNZ_PLACE_CANTERBURY,
	FREEVIEWNZ_PLACE_SOUTHERN_LAKES, 
	FREEVIEWNZ_PLACE_OTAGO, 
	FREEVIEWNZ_PLACE_SOUTHLAND,
}EFreeviewNZPlace;

//OPTION_CABLE_CITY
typedef enum
{
	CABLE_CITY_UNKNOWN 		= INVALID, //-1
	
	CC_BLIZOO_BURGAS			= 0,
	CC_BLIZOO_DOBRICH			= 1,
	CC_BLIZOO_GABROVO			= 2,
	CC_BLIZOO_HASKOVO			= 3,
	CC_BLIZOO_KOZLOD			= 4,
	CC_BLIZOO_KURDZALI			= 5,
	CC_BLIZOO_KUSTEN			= 6,
	CC_BLIZOO_LOVECH			= 7,
	CC_BLIZOO_MONTANA			= 8,
	CC_BLIZOO_NOVAZAGORA		= 9,
	CC_BLIZOO_PANAGURISHTE		= 10,
	CC_BLIZOO_PAZARDJIK			= 11,
	CC_BLIZOO_PETRICH			= 12,
	CC_BLIZOO_PLEVEN			= 13,
	CC_BLIZOO_PLOVDIV			= 14,
	CC_BLIZOO_RAZGRAD			= 15,
	CC_BLIZOO_RAZLOG			= 16,
	CC_BLIZOO_ROUSE				= 17,
	CC_BLIZOO_SIMITLI			= 18,
	CC_BLIZOO_SHUMEN			= 19,
	CC_BLIZOO_SLBRIAG			= 20,
	CC_BLIZOO_SLIVEN			= 21,
	CC_BLIZOO_SOFIA				= 22,
	CC_BLIZOO_STZAGORA			= 23,
	CC_BLIZOO_TARGOVISHTE		= 24,
	CC_BLIZOO_VARNA				= 25,
	CC_BLIZOO_VELINGRAD			= 26,
	CC_ROSTELECOM_MOSCOW_ON_LIME	= 27,
	CC_ROSTELECOM_ST_PETERSBURG		= 28,
	CC_ROSTELECOM_YEKATERINBURG		= 29,
}ECableCity;


typedef enum
{
	// Search options:
	OPTION_UNKNOWN,
	OPTION_SCAN_MODE,				// [EScanMode] Scan Mode.
	OPTION_SCAN_NETWORK,			// [EScanNetwork] Scan Network.
	OPTION_SCAN_TYPE,				// [EScanType] Scan type (stored per tvMode - give tv mode in criteria)
	OPTION_CLEAN_SCAN,				// [ECleanScan] Clean scan (stored per tvMode - give tv mode in criteria)
	OPTION_NETWORK_SCAN,			// [ENetworkScan] Network scan.
	OPTION_NETWORK_MODE,			// [ENetworkMode] Network mode.
	OPTION_SCAN_SERVICE_MODE,		// [EScanServiceMode] Scan service mode.
	OPTION_SCAN_SERVICE_TYPE,		// [EScanServiceType] Scan service type.
	OPTION_SCAN_SERVICE_SELECTION,	// [EScanServiceSelection] Scan service selection (stored per tvMode - give tv mode in criteria)
	OPTION_HOMING_CHANNEL_MODE,		// [EHomingChannelMode] Home channel mode - auto/manual.
	OPTION_FREQUENCY_SCAN_MODE,		// [EFrequencyScanMode] Frequency scan mode.
	OPTION_LNB_TELESUPPLY,			// [ELnbTelesupply] LNB telesupply (Digital+ specific).
	OPTION_FREEVIEWNZ_PLACE,		// [EFreeviewNZPlace] Freeview place.
	OPTION_SATELLITE_ID,			// [ESatelliteId] Satellite used during full search.
	OPTION_AUTO_TUNING_BANDWIDTH,	// [EBandwidth] Bandwidth.
	OPTION_CABLE_CITY,				// [ECableCity] Network/City name for cable operators [ex. Blizoo, Rostelecom]
	OPTION_BLIZOO_CITY,				// [EBlizooeCity] Depracated! to do: to be removed
	OPTION_CLOUD_SCAN,              // [ECloudScan] Cloud scan..
}EScanOption;




class TCScanOption : public TCMarshalable
{
public:
	TCScanOption( EScanOption scanOption ) : option(scanOption), value(INVALID) {};

	template <typename T>
	T GetValue( void ) const { return (T)value; };
	template <typename T>
	void SetValue( const T& data ) { value = data; };
	EScanOption GetOption( void ) const { return option;}

	/**
	 * @brief Extract Tree from Class
	 * @param [inout] treeParent branch to which object data should be added
	 * @return true if success
	 */
	virtual bool ClassToTree(TCTreeBranch& treeParent);
	
	/**
	 * @brief Fill out Class from Tree
	 * @param [inout] treeMine branch from which object data should be fetched
	 * @return true if success
	 */
	virtual bool TreeToClass(TCTreeBranch& treeMine);

protected:
	enum
	{
		TAG_ESCANOPTION,
		TAG_VALUE
	};

private:
	EScanOption option;
	int value;
};

struct TSScanOptionCriteria : public TCMarshalable
{
	enum
	{
		TAG_TVMODE,
	};

	TSTvMode tvMode;

	unsigned long long GetId() const { return tvMode.GetId(); };

	/**
	 * @brief Extract Tree from Class
	 * @param [inout] treeParent branch to which object data should be added
	 * @return true if success
	 */
	virtual bool ClassToTree(TCTreeBranch& treeParent);
	
	/**
	 * @brief Fill out Class from Tree
	 * @param [inout] treeMine branch from which object data should be fetched
	 * @return true if success
	 */
	virtual bool TreeToClass(TCTreeBranch& treeMine);
};

struct TSHomingChannelLocator : public TCMarshalable
{

	enum
	{
		TAG_FREQUENCY,
		TAG_SATELLITEID,
		TAG_MODULATION,
		TAG_PROGRAMNUMBER,
		TAG_SYMBOLRATE,
		TAG_NETWORKIDMODE,
		TAG_NETWORKID,
		TAG_TRANSPONDERID,
		TAG_TRANSPORTSTREAMID,
		TAG_ORIGINNETWORKID,
	};

	struct Data
	{
		int frequency;
		ESatelliteId satelliteId;
		EModulation modulation;
		unsigned short programNumber;
		unsigned short symbolRate;
		ENetworkIDMode networkIdMode;
		unsigned short networkId;
		unsigned short transponderId;
		unsigned short transportStreamId;
		unsigned short originNetworkId;
	}data;
	/**
	 * @brief Extract Tree from Class
	 * @param [inout] treeParent branch to which object data should be added
	 * @return true if success
	 */
	virtual bool ClassToTree(TCTreeBranch& treeParent);
	
	/**
	 * @brief Fill out Class from Tree
	 * @param [inout] treeMine branch from which object data should be fetched
	 * @return true if success
	 */
	virtual bool TreeToClass(TCTreeBranch& treeMine);

	TSHomingChannelLocator(void)
	{
		data.frequency  = INVALID;
		data.satelliteId = SATID_UNKNOWN;
		data.modulation = MODULATION_TYPE_UNKNOWN;
		data.programNumber = INVALID;
		data.symbolRate = INVALID;
		data.networkIdMode = NETWORK_ID_AUTO;
		data.networkId = INVALID;
		data.transponderId = INVALID;
		data.transportStreamId = INVALID;
		data.originNetworkId = INVALID;
	}
	
	//Constructor used for cable case
	TSHomingChannelLocator (int freq, EModulation mod, unsigned short symRate, unsigned short nid = INVALID, unsigned short onid = INVALID, ENetworkIDMode nidMode = NETWORK_ID_AUTO)
	{
		SetCableParameters (freq, mod, symRate, nid, onid);
		data.satelliteId = SATID_UNKNOWN;
		data.programNumber = INVALID;
		data.transponderId = INVALID;
		data.transportStreamId = INVALID;
	}

	void SetCableParameters (int freq, EModulation mod, unsigned short symRate, unsigned short nid = INVALID, unsigned short onid = INVALID, ENetworkIDMode nidMode = NETWORK_ID_AUTO)
	{
		data.frequency  = freq;
		data.modulation = mod;
		data.symbolRate = symRate;
		data.networkId = nid;
		data.originNetworkId = onid;
		data.networkIdMode = nidMode;
	}
};

struct TSScanChannel : public TCMarshalable
{

	enum
	{
		TAG_FREQUENCY,
		TAG_MODULATION,
		TAG_SYMBOLRATE,
		TAG_BANDWIDTH,
		TAG_CHANNELNUMBER,
		TAG_SATELLITEID,
		TAG_TRANSPONDERID,
		TAG_POLARISATION,
		TAG_COLORSYSTEM,
		TAG_SOUNDSYSTEM,
		TAG_MAJOR,
		TAG_ENABLEPOSITIONER,
	};

	struct Data
	{
		int frequency;
		EModulation modulation;
		unsigned short symbolRate;
		EBandwidth bandwidth;
		ESatelliteId satelliteId;
		unsigned short transponderId;
		EDVBSPolarisation polarisation;
		EChannelColor colorSystem;
		EChannelSound soundSystem;
		unsigned short major;
		bool enablePositioner;		//Comment from Orsay: "Temporal positioner flag for TuneAlone(). if 'FALSE', positioner should not move"
	} data;

	/**
	 * @brief Extract Tree from Class
	 * @param [inout] treeParent branch to which object data should be added
	 * @return true if success
	 */
	virtual bool ClassToTree(TCTreeBranch& treeParent);
	
	/**
	 * @brief Fill out Class from Tree
	 * @param [inout] treeMine branch from which object data should be fetched
	 * @return true if success
	 */
	virtual bool TreeToClass(TCTreeBranch& treeMine);

	TSScanChannel(void)
	{
		data.frequency = INVALID;
		data.modulation = MODULATION_TYPE_UNKNOWN;
		data.symbolRate = INVALID;
		data.bandwidth = BANDWIDTH_UNKNOWN;
		data.satelliteId = SATID_UNKNOWN;
		data.transponderId = INVALID;
		data.polarisation = DVBS_POL_UNKNOWN;
		data.colorSystem = COLOR_MIN;
		data.soundSystem = SOUND_UNDEFINED;
		data.major = INVALID;
		data.enablePositioner = true;
	}
};

#endif // _SCANDATADATATYPE_H_
