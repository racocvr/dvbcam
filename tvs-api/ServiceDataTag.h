/** 
 * @file	ServiceDataTag.h
 * @brief	Tags for service data fields.
 * @remarks	This file should be compliant with SEI file used for describing service DB structure.
 *
 * Copyright 2013 by Samsung Electronics, Inc.,
 * 
 * This software is the confidential and proprietary information
 * of Samsung Electronics, Inc. ("Confidential Information").  You
 * shall not disclose such Confidential Information and shall use
 * it only in accordance with the terms of the license agreement
 * you entered into with Samsung.
 */


#ifndef _SERVICEDATATAG_H_
#define _SERVICEDATATAG_H_

typedef enum
{
	SERVICE_DATA_TAG_MIN = -1,			// !!! DO NOT USE THIS TAG !!!

	// CHANNEL
	CHANNEL_TYPE = 1,					// [EChannelType] type of channel
	CHANNEL_NUMBER = 2,					// [unsigned short] channel number, in case of satellite - it is transponder id
	SERVICE_PROFILE = 3,				// [EServiceProfile] //id of profile to which service belongs
	FREQUENCY = 4,						// [int] frequency in [kHz]
	BANDWIDTH = 5,						// [EBandwidth] bandwidth
	MODULATION = 6,						// [EModulation] modulation
	SYMBOL_RATE = 7,					// [unsigned short] symbol rate in [kS/s]
	POLARISATION = 93,					// [EDVBSPolarisation] polarisation
	LNA = 8,							// [bool] low noise amplifier
	DIGITAL = 9,						// [bool] is service digital?
	GROUP_ID = 10,						// [unsigned short] id of group of services, used to sort services
	SYNC_SERVICE = 11,					// [bool] synchronize service to file, true by default
	TUNE_TIME = 85,						// [unsigned int] time of latest tuning to channel (to whole channel, not to specific service)

	// SIGNAL
	SIGNAL_STRENGTH = 99,				// [unsigned char] signal strength for DVB spec
	SIGNAL_QUALITY = 100,				// [unsigned char] signal quality for DVB spec
	BIT_ERROR_RATE = 102,				// [unsigned int] bit error rate for DVB spec
	FIRST_SGNL_LOSS_TIME = 109,			// [unsigned short] first signal loss, Norway only

	// SERVICE
	SERVICE_ID = 12,					// [TCServiceId] id of service
	MAJOR = 13,							// [unsigned short] in ATSC - major number, in other cases - RCN (receiver channel number)
	MINOR = 14,							// [unsigned short] in ATSC - minor number
	PROGRAM_NUMBER = 15,				// [unsigned short] program number
	SERVICE_NAME = 16,					// [t_wchar_t*] service name
	SERVICE_TYPE = 17,					// [unsigned short] service type (see EATSCServiceType, EDVBServiceType, EISDBServiceType)
	TRANSPORT_STREAM_ID = 18,			// [unsigned short] transport stream id
	VIDEO_ENCODE_TYPE = 19,				// [EVideoEncodeType] type of video
	VIDEO_PID = 20,						// [unsigned short] video pid
	PROGRAM_CLOCK_REFERENCE_PID = 21,	// [unsigned short] program clock reference pid
	LOCKED_MODE = 22,					// [ELockedMode] service lock type
	REMEMBERED = 23,					// [bool] is service remembered? - in some cases when service is removed, it is not removed from DB, just remembered=false
	REMEMBERED_BY_SI = 24,				// [bool] is service remembered by SI? - TODO Duende: find out how it is used
	ELIMINATED = 25,					// [bool] TODO Duende: find out what is the difference between remembered and eliminated
	HIDE_GUIDE = 26,					// [bool] TODO Duende: find out the meaning
	HIDDEN = 27,						// [bool] is service hidden?
	SERVICE_3D = 28,
	SCRAMBLED = 29,						// [bool] is service scrambled? - this information comes from SI tables and is not always accurate
	SCRAMBLED_IN_PMT = 101,				// [bool] service is scrambled in PMT
	DEFAULT_SERVICE = 30,				// [bool] default service
	RESOLUTION_INFO_TYPE = 117,			// [RESResolution_k] type of resolution
	RESOLUTION_INFO_WIDTH = 118,		// [unsigned int] resolution width
	RESOLUTION_INFO_HEIGHT = 119,		// [unsigned int] resolution height
	RESOLUTION_INFO_FR_NUM = 120,		// [unsigned int] resolution frame rate numerator
	RESOLUTION_INFO_FR_DENOM = 121,		// [bool] resolution frame rate denominator
	MODIFIED_BY_USER = 129,				// [bool] marks whethever major was modified by user thorough application layer (channel-manager etc.)

	// SERVICE_ANALOG
	MFT_TYPE = 31,						// [EFineTuneType] manual fine tune type, for analog services
	MFT_FREQUENCY = 32,					// [unsigned char] manual fine tune frequency, for analog services
	AUTO_COLOR = 33,					// [bool] flag color system for PAL
	COLOR_SYSTEM = 34,					// [EChannelColor] color system value for analog services
	SOUND_SYSTEM = 35,					// [EChannelSound] sound system value for analog services
	CROSS_TALK_NR = 36,					// [bool] Cross Talk Noise Reduction for analog services

	// SERVICE_ATSC
	SOURCE_ID = 37,						// [unsigned short] in ATSC - source id, related to merging service data with EPG data
	SUB_VIDEO_PID_3D = 38,				// [unsigned short] sub video pid for Korean 3D service
	SUB_VIDEO_ENCODE_TYPE_3D = 39,		// [EVideoEncodeType] sub video encode type for Korean 3D service
	STREAM_COUNT = 111,					// [unsigned short] stream count
	META_DATA_FORMAT = 112,				// [unsigned short] meta data format

	// SERVICE_DVB
	NETWORK_ID = 40,
	ORIGINAL_NETWORK_ID = 41,			// [unsigned short] original network id
	LCN = 42,							// [unsigned short] in DVB - logical channel number
	HD_LCN = 43,						// [unsigned short] in DVB - high definition logical channel number
	HD_SIMULCAST = 44,					// [bool] in DVB - high definition simulcast
	SERVICE_STATE = 45,					// [EServiceState] service state - normal/new/duplicated/...
	GUIDANCE = 46,						// [t_wchar_t*] guidance text for TV watcher
	BOUQUET_ID = 65,					// [unsigned long long] bouquet id
	PROVIDER_ID = 68,					// [unsigned long long] provider id
	PROVIDER_NAME = 69,				// [t_wstring] provider name / NOTE: USE THIS FOR 'Fetch' and 'Get' ONLY. Trying to set provider name or search by it will fail
	MULTILANG_SERVICE_NAME_LANG = 86,	// [ELanguageCode] multilingual service name language code
	MULTILANG_SERVICE_NAME = 87,		// [t_wchar_t*] multilingual service name
	SHORT_SERVICE_NAME = 88,			// [t_wchar_t*] short service name
	DEFAULT_AUTHORITY_ID = 89,			// [unsigned long long] default authority id	
	DEFAULT_AUTHORITY = 90,				// [std::string] default authority name
	NUMERIC_SELECT = 91,				// [bool] flag indicating whether service can be selected via remote 
	DATA_STREAM = 92,					// [bool] dsm-cc data in service
	RUNNING_STATUS = 94,				// [ERunningStatus] service running status
	EIT_PF_FLAG = 95,					// [EEITPFFlag] EIT present following flag
	CAROUSEL_ID = 106,					// [unsigned int] DSM carousel ID

	// SERVICE_DVB_EXT
	HIERARCHY_PRIORITY = 47,
	RCT_PID = 98,						// [unsigned short] related content table descriptor pid
	PLP_ID = 48,						// [unsigned short] physical layer pipe pid
	LOCKED_TIME_START = 49,				// [unsigned short] start of service lock time
	LOCKED_TIME_END = 50,				// [unsigned short] end of service lock time

	// SERVICE_SO
	FREESAT_ID = 51,
	FREESAT_ADULT_SERVICE = 52,			// [bool] in Freesat - information if this is adult service
	FREESAT_REGION = 53,
	DP_SERVICE_ID = 54,
	DP_TRANSPORT_STREAM_ID = 55,
	DP_SERVICE_THEME = 56,
	HD_VIRTUAL_SERVICE_ID = 57,
	NC_SERVICE_LOOKED_BY_SI = 61,		// [bool] lock flag used in NC+ profile

	//FAVORITES
	SERVICE_FAV = 63,					// [bool] is service belongs to any favorites?
	FAVORITE_ID = 63,					// [unsigned int] favorite profile id (>0)
	FAVORITE_ORDER = 64,				// [unsigned int] service position on favorites list

	TRANSPONDER_ID = 75,				// [unsigned short] transponder id
	SATELLITE_ID = 71,					// [ESatelliteId] id of satellite

	//for isdb
	LOGO_ID = 103,
	LOGO_VERSION = 104,

	// genre
	AIRTEL_GENRE = 114,					// [EAirTelGenre] Genre in Airtel India.
	
	// virtual services (CEPG)
	ONTV_JSON_META = 110,				// [t_wchar_t*] metadata obtained from the OnTV server as a JSON string
	RELATED_ANTENNA_MODE = 115,			// [EAntennaMode] the related antenna mode of a virtual service
	HOTEL_PROGRAM_TYPE = 122,			// [EHotelProgramType] Hotel program type
	BANK_ID = 123,						// [unsigned short] Id of bank for hotel tv
	COUNTRY_ID = 124,					// [unsigned short]	Id of country for hotel tv
	HOTEL_GENRE_ID = 127,				// [unsigned short]	Id of genre for hotel tv

	
	SERVICE_DATA_TAG_MAX = 130,			// !!! DO NOT USE THIS TAG !!!
} EServiceDataTag;

#define CORRECT_SERVICE_DATA_TAG(tag) ( (tag)>SERVICE_DATA_TAG_MIN && (tag)<SERVICE_DATA_TAG_MAX)

#endif // _SERVICEDATATAG_H_

