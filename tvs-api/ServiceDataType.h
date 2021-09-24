/** 
 * @file ServiceDataType.h
 * @brief Data types related to services.
 *
 * Copyright 2013 by Samsung Electronics, Inc.,
 * 
 * This software is the confidential and proprietary information
 * of Samsung Electronics, Inc. ("Confidential Information"). You
 * shall not disclose such Confidential Information and shall use
 * it only in accordance with the terms of the license agreement
 * you entered into with Samsung.
 */


#ifndef _SERVICEDATATYPE_H_
#define _SERVICEDATATYPE_H_

#include "Marshalable.h"
#include "TVServiceDataType.h"


typedef enum
{
	CHANNEL_TYPE_UNKNOWN = -1,
	CHANNEL_TYPE_ATV = 1,
	CHANNEL_TYPE_DTV,
	CHANNEL_TYPE_CATV,
	CHANNEL_TYPE_CDTV = 4,
	CHANNEL_TYPE_SDTV = 7,

	CHANNEL_TYPE_MEDIA,
	CHANNEL_TYPE_VIRTUAL,
	CHANNEL_TYPE_MAX
}EChannelType; 

typedef enum
{
	PROFILE_UNKNOWN = -1,
	PROFILE_ATSC = 0,			// ATSC profile (includes both terrestrial and cable services)
	PROFILE_ISDB,				// ISDB profile
	PROFILE_DVB,				// general DVB profile (includes terrestrial/cable/satellite services, use it when there is no service provider, like Freesat, specified)
	PROFILE_FREESAT,			// Freesat (satellite profile, available in UK)
	PROFILE_CANALDIGITAL_SAT,	// CanalDigital (satellite profile, available in Sweden, Norway, Denmark and Finland)
	PROFILE_TIVUSAT,			// TivuSat (satellite profile, available in Italy)
	PROFILE_CD_TVV_TELESAT,		// CanalDigital TV Vlaanderen Telesat (satellite profile, available in Netherlands and Belgium)
	PROFILE_ASTRA_192E,			// Astra HD+ (satellite profile, available in Germany)
	PROFILE_DIGITAL_PLUS,		// Digital+ (satellite profile, operated by Sogecable, available in Spain)
	PROFILE_DSMART,				// DSmart (satellite profile, available in Turkey)
	PROFILE_DIGITURK,			// Digiturk (satellite profile, available in Turkey)
	PROFILE_FRANSAT,			// Fransat (satellite profile, available in France)
	PROFILE_FREEVIEWNZ_SAT,		// Freeview (satellite profile, available in New Zealand)
	PROFILE_NC_PLUS,			// nc+ (satellite profile, available in Poland)
	PROFILE_NNK,				// cyfra plus card
	PROFILE_SKYLINK,			// Skylink (satellite profile, available in Czech Republic and Slovakia)
	PROFILE_AIRTEL,				// airtel (satellite profile, available in India)
	PROFILE_HD_AUSTRIA,			// HD Austria (satellite profile, available in Austria)
	PROFILE_OTAU,				// OTAU TV (satellite profile, available in Kazakhstan)
	PROFILE_CIOP1,				// CI Operator Profile [1]
	PROFILE_CIOP2,				// CI Operator Profile [2]
	PROFILE_DVBNT,				// DVB NT Profile
	PROFILE_MAGYARORSZAG,		// AustriaSat Magyarorszag (satellite profile, available in Hungary)
	PROFILE_STB,				// Profile for virtual services that should be displayed only when STB is attached to TV set and active
	PROFILE_POLSAT,				// Cyfrowy Polsat (satellite profile, available in Poland)
	PROFILE_TRICOLOR,			// Tricolor TV (satellite profile, available in Russia)
	PROFILE_TELEKARTA,			// Telekarta (satellite profile, available in Russia)
	PROFILE_NTV_PLUS,			// NTV +  (satellite profile, available in Russia)
	PROFILE_SUNDIRECT,			// SunDirect  (satellite profile, available in India)
	PROFILE_NAGSAM_OP1,			// NagSam Operator Profile [1]
	PROFILE_CIOP3 = PROFILE_NAGSAM_OP1, //ToDo Duende: Remove
	PROFILE_NAGSAM_OP2,			// NagSam Operator Profile [2]
	PROFILE_NAGSAM_OP3,			// NagSam Operator Profile [3]
	PROFILE_NAGSAM_OP4,			// NagSam Operator Profile [4]
}EServiceProfile; 

typedef enum
{
	VCT_SERVICE_NAME_LENGTH= 14,
	ATSC_SERVICE_NAME_LENGTH = 50,
	DVB_SERVICE_NAME_LENGTH = 100,
	DVB_SHORT_SERVICE_NAME_LENGTH = 18,
	ANALOG_SERVICE_NAME_LENGTH = 12,
	MAX_SERVICE_NAME_LENGTH = 255,
	MAX_RADIO_SERVICE_NAME_LENGTH = 4,
	MAX_NETWORK_NAME_LENGTH = 255,
	MAX_SERVICE_PROVIDER_NAME_LENGTH = 255,
	MAX_SATELLITE_NAME_LENGTH = 64,
}ENameLength; 

typedef enum
{
	MINOR_NUMBER_ONE_PART = -2,
	MINOR_NUMBER_ANALOG = 0,
	MINOR_NUMBER_PTC = -3,
	MINOR_NUMBER_AGING = -4,
}EMinorNumber; 

typedef enum
{
	FINE_TUNE_TYPE_UNKNOWN = -1,
	FINE_TUNE_TYPE_AFT = 0,
	FINE_TUNE_TYPE_MFT = 1,
	FINE_TUNE_TYPE_AFT_FAST = 2,
	FINE_TUNE_TYPE_AFT_SIMPLE = 3,
	FINE_TUNE_TYPE_AFT_SIMPLE_DTV_ONLY = 4,
	FINE_TUNE_TYPE_NO_AFT = 5,
	FINE_TUNE_TYPE_RESET = 6,
}EFineTuneType; 

typedef enum
{
	COLOR_MIN = 0,
	COLOR_PAL = COLOR_MIN,//! color system PAL
	COLOR_SECAM = 1,//! color system SECAM
	COLOR_NTSC4_43 = 2,//! color system NTSC4.43
	COLOR_NTSC3_58 = 3,//! color system NTSC3.58
	COLOR_PAL_M = 4,//! for Brazil
	COLOR_PAL_N = 5,//! for Brazil
	COLOR_AUTO = 6,//! color system auto -manual store에서 auto 로 설정시 사용.
	COLOR_MAX = COLOR_AUTO, //! color system maximum value
}EChannelColor; 

typedef enum
{
	SYSTEM_MIN,
	SYSTEM_MANUAL = SYSTEM_MIN,
	SYSTEM_AUTO,
	SYSTEM_MAX = SYSTEM_AUTO,
}EChannelColorSystem; 

typedef enum
{
	SOUND_SYSTEM_MIN,
	SOUND_SYSTEM_MANUAL = SOUND_SYSTEM_MIN,
	SOUND_SYSTEM_AUTO,
	SOUND_SYSTEM_MAX = SOUND_SYSTEM_AUTO,
}EChannelSoundSystem; 

//! channel sound system for PAL
typedef enum
{
	SOUND_UNDEFINED = -1,
	SOUND_MIN = 0,
	SOUND_AUTO = SOUND_MIN,//! sound system AUTO - auto store에서 사용.
	SOUND_B_G = 1,//! sound system B/G
	SOUND_I = 2,//! sound system I
	SOUND_D_K = 3,//! sound system D/k
	SOUND_M = 4,//! sound system M
	SOUND_L = 5,//! sound system L
	SOUND_MAX = SOUND_L, //! sound system maximum value
}EChannelSound; 

typedef enum
{
	DVBT_HIERARCHY_PRIORITY_MIN,
	DVBT_HIERARCHY_PRIORITY_HP = DVBT_HIERARCHY_PRIORITY_MIN,
	DVBT_HIERARCHY_PRIORITY_LP,
	DVBT_HIERARCHY_PRIORITY_UNKNOWN,
	DVBT_HIERARCHY_PRIORITY_MAX = DVBT_HIERARCHY_PRIORITY_UNKNOWN,
}EDVBTHierachyPriority; 

typedef enum
{
	DVBT_HIERARCHY_INFORMATION_NON = 0,
	DVBT_HIERARCHY_INFORMATION_A_1 = 1,
	DVBT_HIERARCHY_INFORMATION_A_2 = 2,
	DVBT_HIERARCHY_INFORMATION_A_4 = 3,
	DVBT_HIERARCHY_INFORMATION_UNKNOWN = 8, //max
}EDVBTHierarchyInfo; 


typedef enum
{
	SERVICE_STATE_NORMAL,
	SERVICE_STATE_DYNAMIC_SI_NEW,
	SERVICE_STATE_DYNAMIC_SI_DELETED,
	SERVICE_STATE_DYNAMIC_SI_DUPLICATED,
	SERVICE_STATE_UNSELECTED_REGION_POOL, 	// TODO Duende: remove, it was used for TNTSat, not supported on Tizen
	SERVICE_STATE_STANDBY_SCAN_SI_NEW,
}EServiceState; 


typedef enum 
{
	RUNNING_STATUS_UNDEFINED = -1,
	RUNNING_STATUS_NOT_RUNNING = 1,
	RUNNING_STATUS_STARTS_SOON = 2,
	RUNNING_STATUS_PAUSING = 3,
	RUNNING_STATUS_RUNNING = 4,
	RUNNING_STATUS_OFF_AIR = 5
}ERunningStatus;

typedef enum
{
	ATSC_SERVICE_TYPE_UNKNOWN = -1,
	ATSC_SERVICE_TYPE_RESERVED = 0x00, //Reserved
	ATSC_SERVICE_TYPE_ANALOG_TV  = 0x01, // analog_television
	ATSC_SERVICE_TYPE_DIGITAL_TV = 0x02, //ATSC_digital_television
	ATSC_SERVICE_TYPE_AUDIO = 0x03, // ATSC_audio
	ATSC_SERVICE_TYPE_DATA_ONLY = 0x04, // ATSC_data_only_service
	ATSC_SERVICE_TYPE_SDDS = 0x05, //A97_softewareDownloadDataService
	ATSC_SERVICE_TYPE_PARAMETERIZED = 0x07,//Video Codec for K-View
	ATSC_SERVICE_TYPE_RESERVED_MAX = 0x0A, // Reserved for future ATSC use
	ATSC_SERVICE_TYPE_UHD = 0x10, //ATSC_uhd_television	
}EATSCServiceType;

typedef enum
{
	DVB_SERVICE_TYPE_UNKNOWN = -1,
	DVB_SERVICE_TYPE_RESERVED = 0x00,
	DVB_SERVICE_TYPE_TELEVISION = 0x01,
	DVB_SERVICE_TYPE_RADIO = 0x02,
	DVB_SERVICE_TYPE_TELETEXT = 0x03,
	DVB_SERVICE_TYPE_NVOD_REF = 0x04,
	DVB_SERVICE_TYPE_NVOD_SHIFT = 0x05,
	DVB_SERVICE_TYPE_MOSAIC = 0x06,
	DVB_SERVICE_TYPE_PAL = 0x07,
	DVB_SERVICE_TYPE_SECAM = 0x08,
	DVB_SERVICE_TYPE_D_D2_MAC = 0x09,
	DVB_SERVICE_TYPE_FM_RADIO = 0x0A,
	DVB_SERVICE_TYPE_NTSC = 0x0B,
	DVB_SERVICE_TYPE_DATA = 0x0C,
	DVB_SERVICE_TYPE_RCS_MAP = 0x0E,
	DVB_SERVICE_TYPE_RCS_FLS = 0x0F,
	DVB_SERVICE_TYPE_MHP = 0x10,
	DVB_SERVICE_TYPE_HD = 0x11,
	DVB_SERVICE_TYPE_ADV_SD = 0x16,
	DVB_SERVICE_TYPE_ADV_SD_NVODt = 0x17,
	DVB_SERVICE_TYPE_ADV_SD_NVODr = 0x18,
	DVB_SERVICE_TYPE_ADV_HD = 0x19,
	DVB_SERVICE_TYPE_ADV_HD_NVODt = 0x1A,
	DVB_SERVICE_TYPE_ADV_HD_NVODr = 0x1B,
	DVB_SERVICE_TYPE_3D_HD = 0x1C,	//Advanced codec fram compatible plano-stereoscopic HD digital television service (TS 101 547-2 V1.2.1)
	DVB_SERVICE_TYPE_3D_HD_NVODt = 0x1D,	//Advanced codec fram compatible plano-stereoscopic HD NVOD time-shifted service (TS 101 547-2 V1.2.1)
	DVB_SERVICE_TYPE_3D_HD_NVODr = 0x1E,	//Advanced codec fram compatible planostereoscopic HD reference service (TS 101 547-2 V1.2.1)
	DVB_SERVICE_TYPE_HEVC = 0x1F,	//HEVC(High Efficiency Video Coding) digital television service. Combined with DescComponent::StreamContent() = 0x9  (EN 300 468 V1.15.1)
	DVB_SERVICE_TYPE_CN_BJ_NEWVISION = 0xF9, //China Cable DTV Beijing NewVision HD Channel
	DVB_SERVICE_TYPE_CN_BJ_STOCK = 0xF0, //China Cable DTV Beijing STOCK SD Channel
	DVB_SERVICE_TYPE_CN_SH_HDTV = 0x81, //China Cable DTV Shanghai CHC-HD CCTV-HD Channel
	DVB_SERVICE_TYPE_SKYD = 0xD3,
	DVB_SERVICE_TYPE_DIGITURK_RADIO = 0x82, //Digiturk private radio service

	// Open TV hidden services.
	DVB_SERVICE_TYPE_OPEN_TV_1 = 0x98,
	DVB_SERVICE_TYPE_OPEN_TV_2 = 0x99,
	DVB_SERVICE_TYPE_OPEN_TV_3 = 0x9A,
	DVB_SERVICE_TYPE_OPEN_TV_4 = 0x9B,

}EDVBServiceType;

typedef enum
{
	ISDB_SERVICE_TYPE_UNKNOWN = -1, 
	ISDB_SERVICE_TYPE_DIGITAL_TV = 0x01,
	ISDB_SERVICE_TYPE_DIGITAL_RADIO= 0x02,
	ISDB_SERVICE_TYPE_SPECIAL_VIDEO = 0xA1,
	ISDB_SERVICE_TYPE_SPECIAL_AUDIO = 0xA2,
	ISDB_SERVICE_TYPE_SPECIAL_DATA = 0xA3,
	ISDB_SERVICE_TYPE_ENGINEEING = 0xA4,
	ISDB_SERVICE_TYPE_PROMOTION_VIDEO = 0xA5,
	ISDB_SERVICE_TYPE_PROMOTION_AUDIO = 0xA6,
	ISDB_SERVICE_TYPE_PROMOTION_DATA = 0xA7,
	ISDB_SERVICE_TYPE_IN_ADVANCE_ACCUMULATION = 0xA8,
	ISDB_SERVICE_TYPE_EXCLUSIVE_ACCUMULATION = 0xA9,
	ISDB_SERVICE_TYPE_BOOK_MARK_LIST = 0xAA,
	ISDB_SERVICE_TYPE_SERVER_TYPE_SIMULTANEOUS = 0xAB,
	ISDB_SERVICE_TYPE_INDEPENDENT_FILE = 0xAC,
	ISDB_SERVICE_TYPE_DATA = 0xC0,
}EISDBServiceType; 

typedef enum
{
	SERVICE_TYPE_UNKNOWN = -1,
	SERVICE_TYPE_TV = 1,
	SERVICE_TYPE_RADIO = 2,
	SERVICE_TYPE_OTHER = 3, //Data+Other
	SERVICE_TYPE_EXT = 4, //External
}EServiceType; 

typedef enum
{
	GENRE_UNKNOWN = 0xFF,
	GENRE_HAUPTPROGRAMME = 0x00,
	GENRE_SPIELFILM_SERIE = 0x01,
	GENRE_SPOT = 0x02,
	GENRE_NEWS_DOKU_KULTUR = 0x03,
	GENRE_MUSIK_LIFESTYLE_COMEDY = 0x04,
	GENRE_KINDER = 0x05,
	GENRE_SHOPPING = 0x06,
	GENRE_QUIZ_SPIELE = 0x07,
	GENRE_REGIONAL_BADEN_WURTTEMBERG = 0x64,
	GENRE_REGIONAL_BAYERN = 0x65,
	GENRE_REGIONAL_BERLIN_BRANDENBURG = 0x66,
	GENRE_REGIONAL_BREMEN = 0x67,
	GENRE_REGIONAL_HAMBURG = 0x68,
	GENRE_REGIONAL_HESSEN = 0x69,
	GENRE_REGIONAL_MECKLENBURG_VORPOMMERN = 0x6A,
	GENRE_REGIONAL_NIEDERSACHSEN = 0x6B,
	GENRE_REGIONAL_NORDRHEIN_WESTFALEN = 0x6C,
	GENRE_REGIONAL_RHEINLAND_PFALZ = 0x6D,
	GENRE_REGIONAL_SAARLAND = 0x6E,
	GENRE_REGIONAL_SACHSEN = 0x6F,
	GENRE_REGIONAL_SACHSEN_ANHALT = 0x70,
	GENRE_REGIONAL_SCHLESWIG_HOLSTEIN = 0x71,
	GENRE_REGIONAL_THURINGEN = 0x72,
	GENRE_WEITERE_FREMDSPRACHEN = 0xC8,
	GENRE_WEITERE_EROTIK = 0xC9,
	GENRE_WEITERE_ANDERE = 0xCA,
}EGenreCode; 

typedef enum
{
	AUDIO_TYPE_INVALID = -1,
	AUDIO_TYPE_UNDEFINED = 0,
	AUDIO_TYPE_CLEAN_EFFECTS  = 1,  //!< This field indicates that the referenced program element has no language.
	AUDIO_TYPE_HEARING_IMPAIRED = 2,  //!<This field indicates that the referenced program element is prepared for the hearing impaired.
	AUDIO_TYPE_VISUAL_IMPAIRED = 3,  //!<This field indicates that the referenced program element is prepared for the visually impaired viewer. 
}EAudioType; 

typedef enum
{
	LOCKED_MODE_OFF,
	LOCKED_MODE_NORMAL,
	LOCKED_MODE_TIME, // For Norway
	LOCKED_MODE_MAX,
}ELockedMode; 

typedef enum
{
	PREDEFINED_RCN_MIN = 1, //!< Min RCN of predefined services in Astra HD+ mode.
	PREDEFINED_RCN_MAX = 99, //!< Max RCN of predefined services in Astra HD+ mode.
}EPreDefinedRange; 

typedef enum
{
	THEME_UNDEFINED = 0x00,
	THEME_SPORTS = 0x01,
	THEME_NEWS = 0x02,
	THEME_MUSIC = 0x03,
	THEME_KIDS = 0x04,
	THEME_MOVIE_SERIES = 0x05,
	THEME_DOCUMENTARY = 0x06,
	THEME_ENTERTAINMENT_LIFE = 0x07,
	THEME_NATIONAL = 0x0B,
	THEME_WORLD = 0x0C,
	THEME_EROTIC = 0x0D,
}EDPServiceTheme;

typedef enum
{
	EIT_PF_UNKNOWN = -1,
	EIT_PF_OFF,
	EIT_PF_ON,
}EEITPFFlag;

typedef enum
{
	ASCENDING,
	DESCENDING
}ESortOrder;

typedef enum
{
	MODULATION_TYPE_UNKNOWN = -1,
	MODULATION_TYPE_QAM16 = 0,
	MODULATION_TYPE_QAM64 = 1,
	MODULATION_TYPE_QAM128 = 2,
	MODULATION_TYPE_QAM256 = 3,
	MODULATION_TYPE_VSB8 = 4,
	MODULATION_TYPE_VSB16 = 5,
	MODULATION_TYPE_NTSC = 6,
	MODULATION_TYPE_QPSK = 7,
	MODULATION_TYPE_PAL = 8,
	MODULATION_TYPE_DMBT = 9,
	MODULATION_TYPE_OFDM = 10,
	MODULATION_TYPE_ISDB_T = 11,
	MODULATION_TYPE_ISDB_S = 12,
	MODULATION_TYPE_GB_S = 13,
	MODULATION_TYPE_GB_M = 14,
	MODULATION_TYPE_QAM32 = 15,
	MODULATION_TYPE_8PSK = 16,
	MODULATION_TYPE_16APSK = 17,
	MODULATION_TYPE_32APSK = 18,
	MODULATION_TYPE_OFDM_T2 = 19,
	MODULATION_TYPE_MAX = MODULATION_TYPE_OFDM_T2,
}EModulation; 

typedef enum
{
	BANDWIDTH_UNKNOWN = -1,
	BANDWIDTH_5M,
	BANDWIDTH_6M,
	BANDWIDTH_7M,
	BANDWIDTH_8M,
	BANDWIDTH_10M,
	BANDWIDTH_1_712M,
	BANDWIDTH_MAX = BANDWIDTH_1_712M,
}EBandwidth;

typedef enum
{
	DVBS_POL_UNKNOWN = -1,
	DVBS_POL_HL,
	DVBS_POL_VR,
}EDVBSPolarisation;

typedef enum
{
	DVB_FEC_INNER_UNDEFINED  = -1,
	DVB_FEC_INNER_1_2,
	DVB_FEC_INNER_2_3,
	DVB_FEC_INNER_3_4,
	DVB_FEC_INNER_5_6,
	DVB_FEC_INNER_7_8,
	DVB_FEC_INNER_1_4,
	DVB_FEC_INNER_1_3,
	DVB_FEC_INNER_2_5,
	DVB_FEC_INNER_3_5,
	DVB_FEC_INNER_4_5,
	DVB_FEC_INNER_8_9,
	DVB_FEC_INNER_9_10,
	DVB_FEC_INNER_NO_CONV,
}EDVBFECInner; 

typedef enum
{
	DTV_MODE_DEMUX_ONLY,
	DTV_MODE_AUDIO_ONLY, 
	DTV_MODE_VIDEO_ONLY,  
	DTV_MODE_ALL
}EDTVModeType;

typedef enum
{
	AIRTEL_ALL_CHANNEL   = 0x00,
	AIRTEL_MOVIES_ALL        = 0x01,
	AIRTEL_SPORTS_ALL        = 0x02,
	AIRTEL_NEWS_ALL          = 0x03,
	AIRTEL_INFOTAINMENT_ALL  = 0x04,
	AIRTEL_KIDS_ALL          = 0x05,
	AIRTEL_MUSIC_ALL         = 0x06,
	AIRTEL_REGIONAL_ALL      = 0x07,
	AIRTEL_LIFESTYLE_ALL     = 0x08,
	AIRTEL_DEVOTIONAL_ALL    = 0x09,
	AIRTEL_AIRTELMOVIES_ALL = 0x0B,
	AIRTEL_ENTERTAINMENT_ALL = 0x0E,
	AIRTEL_HD_ALL            = 0x0F,

	//sub genre
	AIRTEL_ENTERTAINMENT_HINDI = 0x11,
	AIRTEL_ENTERTAINMENT_ENGLISH = 0x12,
	AIRTEL_ENTERTAINMENT_TAMIL = 0x13,
	AIRTEL_ENTERTAINMENT_TELUGU = 0x14,
	AIRTEL_ENTERTAINMENT_MARATHI = 0x15,
	AIRTEL_ENTERTAINMENT_KANNADA = 0x16,
	AIRTEL_ENTERTAINMENT_BENGALI = 0x17,
	AIRTEL_ENTERTAINMENT_MALAYALAM = 0x18,
	AIRTEL_ENTERTAINMENT_GUJARATI = 0x19,
	AIRTEL_ENTERTAINMENT_PUNJABI = 0x1A,
	AIRTEL_ENTERTAINMENT_ORIYA = 0x1B,
	AIRTEL_ENTERTAINMENT_BHOJPURI = 0x1C,
	AIRTEL_ENTERTAINMENT_ASSAMESE = 0x1D,
	AIRTEL_ENTERTAINMENT_URDU = 0x1E,
	AIRTEL_ENTERTAINMENT_OTHERS = 0x1F,

	AIRTEL_MOVIES_HINDI = 0x20,
	AIRTEL_MOVIES_ENGLISH = 0x21,
	AIRTEL_MOVIES_TAMIL = 0x22,
	AIRTEL_MOVIES_TELUGU = 0x23,
	AIRTEL_MOVIES_MARATHI = 0x24,
	AIRTEL_MOVIES_KANNADA = 0x25,
	AIRTEL_MOVIES_BENGALI = 0x26,
	AIRTEL_MOVIES_MALAYALAM = 0x27,
	AIRTEL_MOVIES_GUJARATI = 0x28,
	AIRTEL_MOVIES_PUNJABI = 0x29,
	AIRTEL_MOVIES_ORIYA = 0x2A,
	AIRTEL_MOVIES_BHOJPURI = 0x2B,
	AIRTEL_MOVIES_ASSAMESE = 0x2C,
	AIRTEL_MOVIES_URDU = 0x2D,
	AIRTEL_MOVIES_OTHERS = 0x22E,

	AIRTEL_NEWS_HINDI = 0x2F,
	AIRTEL_NEWS_ENGLISH = 0x30,
	AIRTEL_NEWS_TAMIL = 0x31,
	AIRTEL_NEWS_TELUGU = 0x32,
	AIRTEL_NEWS_MARATHI = 0x33,
	AIRTEL_NEWS_KANNADA = 0x34,
	AIRTEL_NEWS_BENGALI = 0x35,
	AIRTEL_NEWS_MALAYALAM = 0x36,
	AIRTEL_NEWS_GUJARATI = 0x37,
	AIRTEL_NEWS_PUNJABI = 0x38,
	AIRTEL_NEWS_ORIYA = 0x39,
	AIRTEL_NEWS_BHOJPURI = 0x3A,
	AIRTEL_NEWS_ASSAMESE = 0x3B,
	AIRTEL_NEWS_URDU = 0x3C,
	AIRTEL_NEWS_OTHERS = 0x3D,

	AIRTEL_REGIONAL_TAMIL = 0x3E,
	AIRTEL_REGIONAL_TELUGU = 0x3F,
	AIRTEL_REGIONAL_MARATHI = 0x40,
	AIRTEL_REGIONAL_KANNADA = 0x41,
	AIRTEL_REGIONAL_BENGALI = 0x42,
	AIRTEL_REGIONAL_MALAYALAM = 0x43,
	AIRTEL_REGIONAL_GUJARATI = 0x44,
	AIRTEL_REGIONAL_PUNJABI = 0x45,
	AIRTEL_REGIONAL_ORIYA = 0x46,
	AIRTEL_REGIONAL_BHOJPURI = 0x47,
	AIRTEL_REGIONAL_ASSAMESE = 0x48,
	AIRTEL_REGIONAL_URDU = 0x49,
	AIRTEL_REGIONAL_OTHERS = 0x4A,
} EAirTelGenre; //India Airtel

typedef enum
{
	REPLACEMENT_SUCCESS = 0,			// Operation was successfull
	REPLACEMENT_FAILED_MAPVERSION = 1,	// Channel list replacement failed because of mismatch in stored and current channel list version
	REPLACEMENT_FAILED_COUNTRY = 2,		// Channel list replacement failed because of mismatch in stored and current country setting
	REPLACEMENT_FAILED_FILE = 3,		// Channel list replacement failed because of wrong format of imported file
	REPLACEMENT_FAILED_NO_CHANNELS = 4, // Channel list replacement failed because of there were not channels in the imported file
} EServiceDbReplacementStatus;

typedef enum 
{
	HOTEL_GENRE_UNKNOWN = -1,
	HOTEL_GENRE_NONE = 0,
	HOTEL_GENRE_NEWS = 1,
	HOTEL_GENRE_RADIO = 2,
	HOTEL_GENRE_ENTERTAINMENT = 3,
	HOTEL_GENRE_SPORT = 4,
	HOTEL_GENRE_HOTEL = 5,
} EHotelGenre;

typedef enum 
{
	HOTEL_COUNTRY_UNKNOWN = -1,
	HOTEL_COUNTRY_AUSTRIA,
	HOTEL_COUNTRY_BELGIUM,
	HOTEL_COUNTRY_CHINA,
	HOTEL_COUNTRY_DENMARK,
	HOTEL_COUNTRY_FINLAND,
	HOTEL_COUNTRY_FRA,
	HOTEL_COUNTRY_GERMANY,
	HOTEL_COUNTRY_GREECE,
	HOTEL_COUNTRY_ITALY,
	HOTEL_COUNTRY_JPN,
	HOTEL_COUNTRY_NETHERLANDS,
	HOTEL_COUNTRY_NORWAY,
	HOTEL_COUNTRY_PORTUGAL,
	HOTEL_COUNTRY_RUSSIA,
	HOTEL_COUNTRY_KOR,
	HOTEL_COUNTRY_SPA,
	HOTEL_COUNTRY_SWEDEN,
	HOTEL_COUNTRY_TURKEY,
	HOTEL_COUNTRY_UK,
	HOTEL_COUNTRY_USA,
	HOTEL_COUNTRY_MAX,
	HOTEL_COUNTRY_ALL = 0xFF
} EHotelCountry;

typedef enum 
{
	HOTEL_BANK_1 = 0,
	HOTEL_BANK_2 = 1,
	HOTEL_BANK_3 = 2,
	HOTEL_BANK_4 = 3,
	HOTEL_BANK_5 = 4,
	HOTEL_BANK_MAX = 5,
} EHotelBank;

typedef enum 
{
	 HOTEL_PROGRAM_TYPE_MIN = -1,
	 HOTEL_PROGRAM_TYPE_NORMAL = 1,
	 HOTEL_PROGRAM_TYPE_PROTECTED = 2,
	 HOTEL_PROGRAM_TYPE_INFO = 3,
	 HOTEL_PROGRAM_TYPE_RADIO = 4,
	 HOTEL_PROGRAM_TYPE_DELETE = 5,
	 HOTEL_PROGRAM_TYPE_MAX = 5
}EHotelProgramType;


struct TSServiceProvider : public TCMarshalable
{
	unsigned long long id;
	t_wstring name;

	TSServiceProvider( unsigned long long provId = TVS_INVALID_ID, t_wstring providerName = t_wstring() )
		: id(provId), name(providerName)
	{
	}
	
public:
	/**
	 * @see See base class comment.
	 */
	virtual bool ClassToTree(TCTreeBranch& treeParent);

	/**
	 * @see See base class comment.
	 */
	virtual bool TreeToClass(TCTreeBranch& treeMine);

private:
	enum
	{	
		TAG_ID,
		TAG_SERVICEPROVIDER_NAME,
	};
};

struct TSBouquet : public TCMarshalable
{
	unsigned long long id;
	t_wstring name;

	TSBouquet( unsigned long long bouquetId = TVS_INVALID_ID, t_wstring bouquetName = t_wstring() )
		: id(bouquetId), name(bouquetName)
	{
	}

public:
	/**
	 * @see See base class comment.
	 */
	virtual bool ClassToTree(TCTreeBranch& treeParent);

	/**
	 * @see See base class comment.
	 */
	virtual bool TreeToClass(TCTreeBranch& treeMine);

private:
	enum
	{
		TAG_BOUQUET_ID,
		TAG_BOUQUET_NAME,
	};
};

#endif // _SERVICEDATATYPE_H_
