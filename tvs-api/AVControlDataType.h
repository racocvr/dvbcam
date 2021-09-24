/** 
 * @file AVControlDataType.h
 * @brief Audio and video related data types.
 *
 * Copyright 2013 by Samsung Electronics, Inc.,
 * 
 * This software is the confidential and proprietary information
 * of Samsung Electronics, Inc. ("Confidential Information"). You
 * shall not disclose such Confidential Information and shall use
 * it only in accordance with the terms of the license agreement
 * you entered into with Samsung.
 */


#ifndef _AVCONTROLDATATYPE_H_
#define _AVCONTROLDATATYPE_H_


#include <string>

#include "ServiceDataType.h"
#include "TVServiceDataType.h"
#include "SOSpecDataType.h"
#include "Marshalable.h"


#define MAX_AUDIO_NAME_LENGTH 4

// TODO Duende, obsolete? remove?
enum EPid
{
//	VIDEO_PID, //TODO Duende, redefinition with EServiceDataTag
	SUB_VIDEO_PID,
	AUDIO_PID,
	PCR_PID,
	TTX_PID,
	SBT_PID,
	AD_PID,
	SECTION_PID,
};

/**
 * @brief Enumeration of possible ES pid types for CAS to descramble
 */
enum ECasPidType
{
	CAS_PID_TYPE_UNKNOWN,
	CAS_PID_TYPE_VIDEO,
	CAS_PID_TYPE_AUDIO,
	CAS_PID_TYPE_TTX,
	CAS_PID_TYPE_SUBTITLE,
	CAS_PID_TYPE_AUDIO_DESCRIPTION,
};

typedef enum
{
	MULTI_SOUND_UNKNOWN,					//!< Unknown Multi Sound Mode
	MULTI_SOUND_MONO,          //!< Multi Sound 모드를 MONO로 한다.
	MULTI_SOUND_STEREO,        //!< Multi Sound 모드를 STEREO로 한다.
	MULTI_SOUND_SAP,           //!< Multi Sound 모드를 SAP로 한다.
	MULTI_SOUND_STEREO_SAP,    //!< Multi Sound 모드를 STEREO SAP로 한다.
	MULTI_SOUND_LANGUAGE1,     //!< Multi Sound 모드를 LANGUAGE1로 한다.(국판의 2개 국어)
	MULTI_SOUND_LANGUAGE2,     //!< Multi Sound 모드를 LANGUAGE2로 한다.(국판의 2개 국어)
	MULTI_SOUND_DUAL,			//!< Multi Sound 모드를 Dual로 한다.(국판의 2개 국어)
	MULTI_SOUND_NICAM_MONO,			//!< Multi Sound 모드를 Nicam Mono로 한다.(PAL 제품)
	MULTI_SOUND_NICAM_STEREO,			//!< Multi Sound 모드를 Nicam Stereo로 한다.(PAL 제품)
	MULTI_SOUND_NICAM_LANGUAGE1,			//!< Multi Sound 모드를 Nicam Language1로 한다.(PAL 제품)
	MULTI_SOUND_NICAM_LANGUAGE2,			//!< Multi Sound 모드를 Nicam Language2로 한다.(PAL 제품)
	MULTI_SOUND_NICAM_DUAL,			//!< Multi Sound 모드를 Nicam Dual로 한다.(PAL 제품)
}EMultiSoundMode;

typedef enum
{
}EAnalogMts;

typedef enum
{
}EDigitalMts;

typedef enum
{
	AV_DECODER_STATUS_DATA_SERVICE,				// on data service
	AV_DECODER_STATUS_SCRAMBLE,					// scramble service
	AV_DECODER_STATUS_NO_SCRAMBLE,				// no scramble service
	AV_DECODER_STATUS_NOT_AVAILABLE_SERVICE,	// service is not available
}EAVStatus;

typedef enum
{
	COMPONENT_TYPE_ALL,
	COMPONENT_TYPE_VIDEO,
	COMPONENT_TYPE_AUDIO,
	COMPONENT_TYPE_SUBTITLE_TTX,
	COMPONENT_TYPE_MAX,
}EComponentType;

typedef enum
{
	VIDEO_ENCODE_TYPE_UNKNOWN = -1,
	VIDEO_ENCODE_TYPE_MPEG2,
	VIDEO_ENCODE_TYPE_H264,
	VIDEO_ENCODE_TYPE_JPEG,	// still picture for ginga
	VIDEO_ENCODE_TYPE_AVS,
	VIDEO_ENCODE_TYPE_H265,
}EVideoEncodeType;

typedef enum
{
	AUDIO_ENCODE_UNKNOWN = -1,
	AUDIO_ENCODE_TYPE_AC3,//!< AC3 Audio Encode Mode
	AUDIO_ENCODE_TYPE_MPEG2,//!< MPEG2 Audio Encde Mode
	AUDIO_ENCODE_TYPE_AAC,//! < MPEG2 AAC Encode Mode
	AUDIO_ENCODE_TYPE_HE_AAC,// <  MPEG-4 HE-AAC Audio
	AUDIO_ENCODE_TYPE_ENHANCED_AC3,//!< Enhanced AC3 Audio Encode Mode (Dolby Digital Plus)
	AUDIO_ENCODE_TYPE_AC3_5_1,//!< AC3 Audio Encode Mode
	AUDIO_ENCODE_TYPE_ENHANCED_AC3_5_1,
	AUDIO_ENCODE_TYPE_MPEG4_AAC,//! < MPEG4 AAC Encode Mode
	AUDIO_ENCODE_TYPE_DTS,//! Used by a multimedia source
	AUDIO_ENCODE_TYPE_HE_AAC_5_1,// <  MPEG-4 HE-AAC Audio L4(5.1ch)
	AUDIO_ENCODE_TYPE_DRA,// <  DRA Audio
	AUDIO_ENCODE_TYPE_DTSHD_LBR,//!< DTS-LBR audio Encode Mode
	AUDIO_ENCODE_TYPE_DTSHD,//!< DTS-HD audio Encode Mode(UHD)
	AUDIO_ENCODE_TYPE_HE_AAC_V2,// <  MPEG-4 HE-AAC V2 Audio
	AUDIO_ENCODE_TYPE_HE_AAC_V2_5_1,// <  MPEG-4 HE-AAC V2 Audio L4, 5(5.1ch)
	AUDIO_ENCODE_TYPE_DRA_1_0,// < DRA 1.0
	AUDIO_ENCODE_TYPE_DRA_2_0,// DRA 2.0
	AUDIO_ENCODE_TYPE_DRA_2_1,// DRA 2.1
	AUDIO_ENCODE_TYPE_DRA_3_0,// DRA 3.0
	AUDIO_ENCODE_TYPE_DRA_3_1,// DRA 3.1
	AUDIO_ENCODE_TYPE_DRA_4_0,// DRA 4.0
	AUDIO_ENCODE_TYPE_DRA_4_1,// DRA 4.1
	AUDIO_ENCODE_TYPE_DRA_5_0,// DRA 5.0
	AUDIO_ENCODE_TYPE_DRA_5_1,// DRA 5.1
	AUDIO_ENCODE_MAX,
}EAudioEncodeType;

typedef enum
{
        TVS_AVE_RESOLUTION_NT,
        TVS_AVE_RESOLUTION_1080I,
        TVS_AVE_RESOLUTION_1080P,  // 60Hz
        TVS_AVE_RESOLUTION_720P,
        TVS_AVE_RESOLUTION_480P,
        TVS_AVE_RESOLUTION_480I,
        TVS_AVE_RESOLUTION_480P_861B,
        TVS_AVE_RESOLUTION_480P_SMPTE,
        TVS_AVE_RESOLUTION_1080P_24Hz,     // 50Hz
        TVS_AVE_RESOLUTION_1080P_30Hz,     // 60Hz
        TVS_AVE_RESOLUTION_640X480P,
        TVS_AVE_RESOLUTION_1440X480I,
        TVS_AVE_RESOLUTION_1440X240P,
        TVS_AVE_RESOLUTION_240P,
        TVS_AVE_RESOLUTION_540P,

        //for DVB/PAL
        TVS_AVE_RESOLUTION_PAL,
        TVS_AVE_RESOLUTION_PAL_M,
        TVS_AVE_RESOLUTION_PAL_N,
        TVS_AVE_RESOLUTION_PAL_60,
        TVS_AVE_RESOLUTION_SECAM,
        TVS_AVE_RESOLUTION_NT_443,
        TVS_AVE_RESOLUTION_576P,
        TVS_AVE_RESOLUTION_576I,
        TVS_AVE_RESOLUTION_1440X576I,
        TVS_AVE_RESOLUTION_1440X288P,
        TVS_AVE_RESOLUTION_1080I_50Hz,
        TVS_AVE_RESOLUTION_1080P_25Hz,     // 50Hz
        TVS_AVE_RESOLUTION_1080P_50Hz,
        TVS_AVE_RESOLUTION_720P_50Hz,
        TVS_AVE_RESOLUTION_288I,
        TVS_AVE_RESOLUTION_288P,

        // for 3D
        TVS_AVE_RESOLUTION_720P_3D,
        TVS_AVE_RESOLUTION_720P_50Hz_3D,
        TVS_AVE_RESOLUTION_1080I_50Hz_3D,
        TVS_AVE_RESOLUTION_1080I_60Hz_3D,
        TVS_AVE_RESOLUTION_1080P_24Hz_3D,  // 50Hz
        TVS_AVE_RESOLUTION_1080P_25Hz_3D,
        TVS_AVE_RESOLUTION_1080P_30Hz_3D,
        TVS_AVE_RESOLUTION_1080P_48Hz_3D,  // 50Hz
        TVS_AVE_RESOLUTION_1080P_50Hz_3D,
        TVS_AVE_RESOLUTION_1080P_60Hz_3D,

        //ADD PC INPUT RESOLUTION BY YCSONG
        TVS_AVE_RESOLUTION_PC_START,
        TVS_AVE_RESOLUTION_640X240_60HZ = TVS_AVE_RESOLUTION_PC_START,
        TVS_AVE_RESOLUTION_640X350_70HZ,
        TVS_AVE_RESOLUTION_640X350_85HZ,
        TVS_AVE_RESOLUTION_VGA_60HZ,                      /*VGA: 640x480*/
        TVS_AVE_RESOLUTION_656X496_60HZ,   // HDMI Only, NVIDIA Æ??¤ ±×·¡?? ?"?? ´???
        TVS_AVE_RESOLUTION_VGA_67HZ,
        TVS_AVE_RESOLUTION_VGA_70HZ,
        TVS_AVE_RESOLUTION_VGA_72HZ,
        TVS_AVE_RESOLUTION_656X496_72HZ, // HDMI Only, NVIDIA Æ??¤ ±×·¡?? ?"?? ´???
        TVS_AVE_RESOLUTION_VGA_75HZ,
        TVS_AVE_RESOLUTION_VGA_85HZ,
        TVS_AVE_RESOLUTION_720X400_70HZ,
        TVS_AVE_RESOLUTION_720X400_85HZ,
        TVS_AVE_RESOLUTION_720X480I_60HZ,
        TVS_AVE_RESOLUTION_720X576I_50HZ,
        TVS_AVE_RESOLUTION_720X576_50HZ,
        TVS_AVE_RESOLUTION_720X576_60HZ,
//      AVE_RESOLUTION_720X576_70HZ,
        TVS_AVE_RESOLUTION_720X576_75HZ,
        TVS_AVE_RESOLUTION_720X576_85HZ,
        TVS_AVE_RESOLUTION_SVGA_56HZ,                     /*SVGA: 800x600*/
        TVS_AVE_RESOLUTION_SVGA_60HZ,
        TVS_AVE_RESOLUTION_SVGA_70HZ,
        TVS_AVE_RESOLUTION_SVGA_72HZ,
        TVS_AVE_RESOLUTION_SVGA_75HZ,
        TVS_AVE_RESOLUTION_SVGA_85HZ,
        TVS_AVE_RESOLUTION_832X624_75HZ,
//      AVE_RESOLUTION_WVGA_59HZ,             /*WVGA:848x480*/
        TVS_AVE_RESOLUTION_WVGA_60HZ,
//      AVE_RESOLUTION_WVGA_75HZ,
        TVS_AVE_RESOLUTION_1024X576_56HZ,         /*IKUSI Spec*/
        TVS_AVE_RESOLUTION_XGA_60HZ,                      /*XGA: 1024x768*/
        TVS_AVE_RESOLUTION_XGA_70HZ,
        TVS_AVE_RESOLUTION_XGA_72HZ,
        TVS_AVE_RESOLUTION_XGA_75HZ,
        TVS_AVE_RESOLUTION_XGA_75HZ_MAC,
        TVS_AVE_RESOLUTION_XGA_85HZ,
        TVS_AVE_RESOLUTION_1152X864_60HZ,
        TVS_AVE_RESOLUTION_1152X864_70HZ,
        TVS_AVE_RESOLUTION_1152X864_72HZ,
        TVS_AVE_RESOLUTION_1152X864_75HZ,
        TVS_AVE_RESOLUTION_1152X870_75HZ,
        //AVE_RESOLUTION_1152X864_85HZ,
        TVS_AVE_RESOLUTION_1152X900_66HZ,
        TVS_AVE_RESOLUTION_1152X900_76HZ,
        TVS_AVE_RESOLUTION_1280X720_50HZ,
        TVS_AVE_RESOLUTION_1280X720_60HZ,
        TVS_AVE_RESOLUTION_1280X720_60HZCVT,
        TVS_AVE_RESOLUTION_1280X720_70HZ,
        TVS_AVE_RESOLUTION_1280X720_72HZ,
        TVS_AVE_RESOLUTION_1280X720_75HZ,
        TVS_AVE_RESOLUTION_1280X720_85HZ,
        TVS_AVE_RESOLUTION_1280X768_60HZ,
        TVS_AVE_RESOLUTION_1280X768_75HZ,
        TVS_AVE_RESOLUTION_1280X800_60HZ,
        TVS_AVE_RESOLUTION_1280X800_75HZ,
        TVS_AVE_RESOLUTION_1280X960_60HZ,
        TVS_AVE_RESOLUTION_1280X960_70HZ,
        TVS_AVE_RESOLUTION_1280X960_72HZ,
        TVS_AVE_RESOLUTION_1280X960_75HZ,
        TVS_AVE_RESOLUTION_1280X960_85HZ,
//      AVE_RESOLUTION_SXGA_48HZ,
        TVS_AVE_RESOLUTION_SXGA_60HZ,             /*SXGA: 1280x1024*/
//      AVE_RESOLUTION_SXGA_60HZ_SOG,
//      AVE_RESOLUTION_SXGA_67HZ,
        TVS_AVE_RESOLUTION_SXGA_70HZ,
        TVS_AVE_RESOLUTION_SXGA_72HZ,
        TVS_AVE_RESOLUTION_SXGA_75HZ,
        TVS_AVE_RESOLUTION_SXGA_76HZ,
        TVS_AVE_RESOLUTION_SXGA_85HZ,
        TVS_AVE_RESOLUTION_WXGA_60HZ,             /*WXGA:1360x768*/
        TVS_AVE_RESOLUTION_1366X768_60HZ,
        TVS_AVE_RESOLUTION_1400X1050_60HZRB,
        TVS_AVE_RESOLUTION_1400X1050_60HZ,
        TVS_AVE_RESOLUTION_1400X1050_75HZ,
//      AVE_RESOLUTION_1440X900_60HZRB,
        TVS_AVE_RESOLUTION_1440X900_60HZ,
        TVS_AVE_RESOLUTION_1440X900_75HZ,
        TVS_AVE_RESOLUTION_1600X900_60HZRB,
//      AVE_RESOLUTION_1600X1024_75HZ,
//      AVE_RESOLUTION_UXGA_60HZRB,
        TVS_AVE_RESOLUTION_UXGA_60HZ,             /*UXGA: 1600x1200*/
//      AVE_RESOLUTION_UXGA_64HZ,
        TVS_AVE_RESOLUTION_UXGA_65HZ,
        TVS_AVE_RESOLUTION_UXGA_67HZ,
        TVS_AVE_RESOLUTION_UXGA_70HZ,
        TVS_AVE_RESOLUTION_UXGA_75HZ,
//      AVE_RESOLUTION_UXGA_85HZ,
        TVS_AVE_RESOLUTION_1680X1050_60HZRB,
        TVS_AVE_RESOLUTION_1680X1050_60HZ,
        TVS_AVE_RESOLUTION_1680X1050_75HZ,
//      AVE_RESOLUTION_1680X1050_85HZ,
        TVS_AVE_RESOLUTION_1920X1080_24HZ,
        TVS_AVE_RESOLUTION_1920X1080_25HZ,
        TVS_AVE_RESOLUTION_1920X1080_30HZ,
        TVS_AVE_RESOLUTION_1920X1080I_50HZ,
        TVS_AVE_RESOLUTION_1920X1080_50HZ,
        TVS_AVE_RESOLUTION_1920X1080_60HZRB,
        TVS_AVE_RESOLUTION_1920X1080_60HZCVT,
        TVS_AVE_RESOLUTION_1920X1080I_60HZ,
        TVS_AVE_RESOLUTION_1920X1080_60HZ,
//      AVE_RESOLUTION_1920X1080_75HZ,
        TVS_AVE_RESOLUTION_1920X1200_60HZRB,
        TVS_AVE_RESOLUTION_1920X1200_60HZ,
        TVS_AVE_RESOLUTION_2048X1152_60HZRB,
        TVS_AVE_RESOLUTION_2560X1600_60HZRB,
        TVS_AVE_RESOLUTION_PC_END                         = TVS_AVE_RESOLUTION_2560X1600_60HZRB,
        TVS_AVE_RESOLUTION_2560X1080_60HZ,
        TVS_AVE_RESOLUTION_NOSIGNAL,
        TVS_AVE_RESOLUTION_NOVIDEO,
        TVS_AVE_RESOLUTION_NOTDEFINE,
        TVS_AVE_RESOLUTION_NOTSUPPORTED,

        //For UD
        TVS_AVE_RESOLUTION_2160P_START,
        TVS_AVE_RESOLUTION_2160P_30HZ = TVS_AVE_RESOLUTION_2160P_START,
        TVS_AVE_RESOLUTION_2160P_24HZ,
        TVS_AVE_RESOLUTION_2160P_25HZ,
        TVS_AVE_RESOLUTION_2160P_60HZ_HALF,
        TVS_AVE_RESOLUTION_2160P_60HZ,
        TVS_AVE_RESOLUTION_2160P_50HZ_HALF,
        TVS_AVE_RESOLUTION_2160P_50HZ,
        TVS_AVE_RESOLUTION_4096X2160P_START,
        TVS_AVE_RESOLUTION_4096X2160P_24HZ = TVS_AVE_RESOLUTION_4096X2160P_START, // UD ?Ø"????ß 4096x2160P ?Ø"??? ±¸ºÐ.
        TVS_AVE_RESOLUTION_4096X2160P_25HZ,
        TVS_AVE_RESOLUTION_4096X2160P_30HZ,
        TVS_AVE_RESOLUTION_4096X2160P_60HZ_HALF,
        TVS_AVE_RESOLUTION_4096X2160P_60HZ,
        TVS_AVE_RESOLUTION_4096X2160P_50HZ_HALF,
        TVS_AVE_RESOLUTION_4096X2160P_50HZ,
        TVS_AVE_RESOLUTION_4096X2160P_END = TVS_AVE_RESOLUTION_4096X2160P_50HZ,
        TVS_AVE_RESOLUTION_2160P_NOTDEFINE,
        TVS_AVE_RESOLUTION_2160P_END = TVS_AVE_RESOLUTION_2160P_NOTDEFINE,
        TVS_AVE_RESOLUTION_MAX,
}AVEResolution;

typedef enum
{

	TVS_RESOLUTION_YC_SECAM = -2,			//!TODO: it will be eliminated after developing taiwan product
	TVS_RESOLUTION_UNSTABLE = -1,			//!< Unstable Resolution
	
	TVS_RESOLUTION_NT	=	TVS_AVE_RESOLUTION_NT	,
	TVS_RESOLUTION_1080I	=			TVS_AVE_RESOLUTION_1080I	,
	TVS_RESOLUTION_1080P	=			TVS_AVE_RESOLUTION_1080P	,
	TVS_RESOLUTION_720P =			TVS_AVE_RESOLUTION_720P ,
	TVS_RESOLUTION_480P =			TVS_AVE_RESOLUTION_480P ,
	TVS_RESOLUTION_480I =			TVS_AVE_RESOLUTION_480I ,
	TVS_RESOLUTION_480P_861B	=			TVS_AVE_RESOLUTION_480P_861B	,
	TVS_RESOLUTION_480P_SMPTE	=			TVS_AVE_RESOLUTION_480P_SMPTE	,
	TVS_RESOLUTION_1080P_24Hz	=			TVS_AVE_RESOLUTION_1080P_24Hz	,
	TVS_RESOLUTION_1080P_30Hz	=			TVS_AVE_RESOLUTION_1080P_30Hz	,
	TVS_RESOLUTION_640X480P =			TVS_AVE_RESOLUTION_640X480P ,
	TVS_RESOLUTION_1440X480I	=			TVS_AVE_RESOLUTION_1440X480I	,
	TVS_RESOLUTION_1440X240P	=			TVS_AVE_RESOLUTION_1440X240P	,
	TVS_RESOLUTION_240P =			TVS_AVE_RESOLUTION_240P ,
	TVS_RESOLUTION_540P =			TVS_AVE_RESOLUTION_540P ,
		
	//for DVB/PAL	=			//for DVB/PAL	
	TVS_RESOLUTION_PAL	=			TVS_AVE_RESOLUTION_PAL	,
	TVS_RESOLUTION_PAL_M	=			TVS_AVE_RESOLUTION_PAL_M	,
	TVS_RESOLUTION_PAL_N	=			TVS_AVE_RESOLUTION_PAL_N	,
	TVS_RESOLUTION_PAL_60	=			TVS_AVE_RESOLUTION_PAL_60	,
	TVS_RESOLUTION_SECAM	=			TVS_AVE_RESOLUTION_SECAM	,
	TVS_RESOLUTION_NT_443	=			TVS_AVE_RESOLUTION_NT_443	,
	TVS_RESOLUTION_576P =			TVS_AVE_RESOLUTION_576P ,
	TVS_RESOLUTION_576I =			TVS_AVE_RESOLUTION_576I ,
	TVS_RESOLUTION_1440X576I	=			TVS_AVE_RESOLUTION_1440X576I	,
	TVS_RESOLUTION_1440X288P	=			TVS_AVE_RESOLUTION_1440X288P	,
	TVS_RESOLUTION_1080I_50Hz	=			TVS_AVE_RESOLUTION_1080I_50Hz	,
	TVS_RESOLUTION_1080P_25Hz	=			TVS_AVE_RESOLUTION_1080P_25Hz	,
	TVS_RESOLUTION_1080P_50Hz	=			TVS_AVE_RESOLUTION_1080P_50Hz	,
	TVS_RESOLUTION_720P_50Hz	=			TVS_AVE_RESOLUTION_720P_50Hz	,
	TVS_RESOLUTION_288I =			TVS_AVE_RESOLUTION_288I ,
	TVS_RESOLUTION_288i = 			TVS_AVE_RESOLUTION_288I, // application 에서 정리되면 삭제. 
	TVS_RESOLUTION_288P =			TVS_AVE_RESOLUTION_288P ,
		
	// for 3D	=			// for 3D	,
	TVS_RESOLUTION_720P_3D	=			TVS_AVE_RESOLUTION_720P_3D	,
	TVS_RESOLUTION_720P_50Hz_3D =			TVS_AVE_RESOLUTION_720P_50Hz_3D ,
	TVS_RESOLUTION_1080I_50Hz_3D	=			TVS_AVE_RESOLUTION_1080I_50Hz_3D	,
	TVS_RESOLUTION_1080I_60Hz_3D	=			TVS_AVE_RESOLUTION_1080I_60Hz_3D	,
	TVS_RESOLUTION_1080P_24Hz_3D	=			TVS_AVE_RESOLUTION_1080P_24Hz_3D	,
	TVS_RESOLUTION_1080P_25Hz_3D	=			TVS_AVE_RESOLUTION_1080P_25Hz_3D	,
	TVS_RESOLUTION_1080P_30Hz_3D	=			TVS_AVE_RESOLUTION_1080P_30Hz_3D	,
	TVS_RESOLUTION_1080P_48Hz_3D	=			TVS_AVE_RESOLUTION_1080P_48Hz_3D	,
	TVS_RESOLUTION_1080P_50Hz_3D	=			TVS_AVE_RESOLUTION_1080P_50Hz_3D	,
	TVS_RESOLUTION_1080P_60Hz_3D	=			TVS_AVE_RESOLUTION_1080P_60Hz_3D	,
		
	//ADD PC INPUT RESOLUTION BY YCSONG =			//ADD PC INPUT RESOLUTION BY YCSONG ,
	TVS_RESOLUTION_PC_START =			TVS_AVE_RESOLUTION_PC_START ,
	TVS_RESOLUTION_640X240_60HZ =			TVS_AVE_RESOLUTION_640X240_60HZ ,
	TVS_RESOLUTION_640X350_70HZ =			TVS_AVE_RESOLUTION_640X350_70HZ ,
	TVS_RESOLUTION_640X350_85HZ =			TVS_AVE_RESOLUTION_640X350_85HZ ,
	TVS_RESOLUTION_VGA_60HZ =			TVS_AVE_RESOLUTION_VGA_60HZ ,
	TVS_RESOLUTION_656X496_60HZ =			TVS_AVE_RESOLUTION_656X496_60HZ ,
	TVS_RESOLUTION_VGA_67HZ =			TVS_AVE_RESOLUTION_VGA_67HZ ,
	TVS_RESOLUTION_VGA_70HZ =			TVS_AVE_RESOLUTION_VGA_70HZ ,
	TVS_RESOLUTION_VGA_72HZ =			TVS_AVE_RESOLUTION_VGA_72HZ ,
	TVS_RESOLUTION_656X496_72HZ =			TVS_AVE_RESOLUTION_656X496_72HZ ,
	TVS_RESOLUTION_VGA_75HZ =			TVS_AVE_RESOLUTION_VGA_75HZ ,
	TVS_RESOLUTION_VGA_85HZ =			TVS_AVE_RESOLUTION_VGA_85HZ ,
	TVS_RESOLUTION_720X400_70HZ =			TVS_AVE_RESOLUTION_720X400_70HZ ,
	TVS_RESOLUTION_720X400_85HZ =			TVS_AVE_RESOLUTION_720X400_85HZ ,
	TVS_RESOLUTION_720X480I_60HZ	=			TVS_AVE_RESOLUTION_720X480I_60HZ	,
	TVS_RESOLUTION_720X576I_50HZ	=			TVS_AVE_RESOLUTION_720X576I_50HZ	,
	TVS_RESOLUTION_720X576_50HZ =			TVS_AVE_RESOLUTION_720X576_50HZ ,
	TVS_RESOLUTION_720X576_60HZ =			TVS_AVE_RESOLUTION_720X576_60HZ ,
		
	TVS_RESOLUTION_720X576_75HZ =			TVS_AVE_RESOLUTION_720X576_75HZ ,
	TVS_RESOLUTION_720X576_85HZ =			TVS_AVE_RESOLUTION_720X576_85HZ ,
	TVS_RESOLUTION_SVGA_56HZ	=			TVS_AVE_RESOLUTION_SVGA_56HZ	,
	TVS_RESOLUTION_SVGA_60HZ	=			TVS_AVE_RESOLUTION_SVGA_60HZ	,
	TVS_RESOLUTION_SVGA_70HZ	=			TVS_AVE_RESOLUTION_SVGA_70HZ	,
	TVS_RESOLUTION_SVGA_72HZ	=			TVS_AVE_RESOLUTION_SVGA_72HZ	,
	TVS_RESOLUTION_SVGA_75HZ	=			TVS_AVE_RESOLUTION_SVGA_75HZ	,
	TVS_RESOLUTION_SVGA_85HZ	=			TVS_AVE_RESOLUTION_SVGA_85HZ	,
	TVS_RESOLUTION_832X624_75HZ =			TVS_AVE_RESOLUTION_832X624_75HZ ,
		
	TVS_RESOLUTION_WVGA_60HZ	=			TVS_AVE_RESOLUTION_WVGA_60HZ	,
		
	TVS_RESOLUTION_1024X576_56HZ	=			TVS_AVE_RESOLUTION_1024X576_56HZ	,
	TVS_RESOLUTION_XGA_60HZ =			TVS_AVE_RESOLUTION_XGA_60HZ ,
	TVS_RESOLUTION_XGA_70HZ =			TVS_AVE_RESOLUTION_XGA_70HZ ,
	TVS_RESOLUTION_XGA_72HZ =			TVS_AVE_RESOLUTION_XGA_72HZ ,
	TVS_RESOLUTION_XGA_75HZ =			TVS_AVE_RESOLUTION_XGA_75HZ ,
	TVS_RESOLUTION_XGA_75HZ_MAC =			TVS_AVE_RESOLUTION_XGA_75HZ_MAC ,
	TVS_RESOLUTION_XGA_85HZ =			TVS_AVE_RESOLUTION_XGA_85HZ ,
	TVS_RESOLUTION_1152X864_60HZ	=			TVS_AVE_RESOLUTION_1152X864_60HZ	,
	TVS_RESOLUTION_1152X864_70HZ	=			TVS_AVE_RESOLUTION_1152X864_70HZ	,
	TVS_RESOLUTION_1152X864_72HZ	=			TVS_AVE_RESOLUTION_1152X864_72HZ	,
	TVS_RESOLUTION_1152X864_75HZ	=			TVS_AVE_RESOLUTION_1152X864_75HZ	,
	TVS_RESOLUTION_1152X870_75HZ	=			TVS_AVE_RESOLUTION_1152X870_75HZ	,
		
	TVS_RESOLUTION_1152X900_66HZ	=			TVS_AVE_RESOLUTION_1152X900_66HZ	,
	TVS_RESOLUTION_1152X900_76HZ	=			TVS_AVE_RESOLUTION_1152X900_76HZ	,
	TVS_RESOLUTION_1280X720_50HZ	=			TVS_AVE_RESOLUTION_1280X720_50HZ	,
	TVS_RESOLUTION_1280X720_60HZ	=			TVS_AVE_RESOLUTION_1280X720_60HZ	,
	TVS_RESOLUTION_1280X720_60HZCVT =			TVS_AVE_RESOLUTION_1280X720_60HZCVT ,
	TVS_RESOLUTION_1280X720_70HZ	=			TVS_AVE_RESOLUTION_1280X720_70HZ	,
	TVS_RESOLUTION_1280X720_72HZ	=			TVS_AVE_RESOLUTION_1280X720_72HZ	,
	TVS_RESOLUTION_1280X720_75HZ	=			TVS_AVE_RESOLUTION_1280X720_75HZ	,
	TVS_RESOLUTION_1280X720_85HZ	=			TVS_AVE_RESOLUTION_1280X720_85HZ	,
	TVS_RESOLUTION_1280X768_60HZ	=			TVS_AVE_RESOLUTION_1280X768_60HZ	,
	TVS_RESOLUTION_1280X768_75HZ	=			TVS_AVE_RESOLUTION_1280X768_75HZ	,
	TVS_RESOLUTION_1280X800_60HZ	=			TVS_AVE_RESOLUTION_1280X800_60HZ	,
	TVS_RESOLUTION_1280X800_75HZ	=			TVS_AVE_RESOLUTION_1280X800_75HZ	,
	TVS_RESOLUTION_1280X960_60HZ	=			TVS_AVE_RESOLUTION_1280X960_60HZ	,
	TVS_RESOLUTION_1280X960_70HZ	=			TVS_AVE_RESOLUTION_1280X960_70HZ	,
	TVS_RESOLUTION_1280X960_72HZ	=			TVS_AVE_RESOLUTION_1280X960_72HZ	,
	TVS_RESOLUTION_1280X960_75HZ	=			TVS_AVE_RESOLUTION_1280X960_75HZ	,
	TVS_RESOLUTION_1280X960_85HZ	=			TVS_AVE_RESOLUTION_1280X960_85HZ	,
		
	TVS_RESOLUTION_SXGA_60HZ	=			TVS_AVE_RESOLUTION_SXGA_60HZ	,
		
		
	TVS_RESOLUTION_SXGA_70HZ	=			TVS_AVE_RESOLUTION_SXGA_70HZ	,
	TVS_RESOLUTION_SXGA_72HZ	=			TVS_AVE_RESOLUTION_SXGA_72HZ	,
	TVS_RESOLUTION_SXGA_75HZ	=			TVS_AVE_RESOLUTION_SXGA_75HZ	,
	TVS_RESOLUTION_SXGA_76HZ	=			TVS_AVE_RESOLUTION_SXGA_76HZ	,
	TVS_RESOLUTION_SXGA_85HZ	=			TVS_AVE_RESOLUTION_SXGA_85HZ	,
	TVS_RESOLUTION_WXGA_60HZ	=			TVS_AVE_RESOLUTION_WXGA_60HZ	,
	TVS_RESOLUTION_1366X768_60HZ	=			TVS_AVE_RESOLUTION_1366X768_60HZ	,
	TVS_RESOLUTION_1400X1050_60HZRB =			TVS_AVE_RESOLUTION_1400X1050_60HZRB ,
	TVS_RESOLUTION_1400X1050_60HZ	=			TVS_AVE_RESOLUTION_1400X1050_60HZ	,
	TVS_RESOLUTION_1400X1050_75HZ	=			TVS_AVE_RESOLUTION_1400X1050_75HZ	,
		
	TVS_RESOLUTION_1440X900_60HZ	=			TVS_AVE_RESOLUTION_1440X900_60HZ	,
	TVS_RESOLUTION_1440X900_75HZ	=			TVS_AVE_RESOLUTION_1440X900_75HZ	,
	TVS_RESOLUTION_1600X900_60HZRB	=			TVS_AVE_RESOLUTION_1600X900_60HZRB	,
		
		
	TVS_RESOLUTION_UXGA_60HZ	=			TVS_AVE_RESOLUTION_UXGA_60HZ	,
		
	TVS_RESOLUTION_UXGA_65HZ	=			TVS_AVE_RESOLUTION_UXGA_65HZ	,
	TVS_RESOLUTION_UXGA_67HZ	=			TVS_AVE_RESOLUTION_UXGA_67HZ	,
	TVS_RESOLUTION_UXGA_70HZ	=			TVS_AVE_RESOLUTION_UXGA_70HZ	,
	TVS_RESOLUTION_UXGA_75HZ	=			TVS_AVE_RESOLUTION_UXGA_75HZ	,
		
	TVS_RESOLUTION_1680X1050_60HZRB =			TVS_AVE_RESOLUTION_1680X1050_60HZRB ,
	TVS_RESOLUTION_1680X1050_60HZ	=			TVS_AVE_RESOLUTION_1680X1050_60HZ	,
	TVS_RESOLUTION_1680X1050_75HZ	=			TVS_AVE_RESOLUTION_1680X1050_75HZ	,
		
	TVS_RESOLUTION_1920X1080_24HZ	=			TVS_AVE_RESOLUTION_1920X1080_24HZ	,
	TVS_RESOLUTION_1920X1080_25HZ	=			TVS_AVE_RESOLUTION_1920X1080_25HZ	,
	TVS_RESOLUTION_1920X1080_30HZ	=			TVS_AVE_RESOLUTION_1920X1080_30HZ	,
	TVS_RESOLUTION_1920X1080I_50HZ	=			TVS_AVE_RESOLUTION_1920X1080I_50HZ	,
	TVS_RESOLUTION_1920X1080_50HZ	=			TVS_AVE_RESOLUTION_1920X1080_50HZ	,
	TVS_RESOLUTION_1920X1080_60HZRB =			TVS_AVE_RESOLUTION_1920X1080_60HZRB ,
	TVS_RESOLUTION_1920X1080_60HZCVT	=			TVS_AVE_RESOLUTION_1920X1080_60HZCVT	,
	TVS_RESOLUTION_1920X1080I_60HZ	=			TVS_AVE_RESOLUTION_1920X1080I_60HZ	,
	TVS_RESOLUTION_1920X1080_60HZ	=			TVS_AVE_RESOLUTION_1920X1080_60HZ	,
		
	TVS_RESOLUTION_1920X1200_60HZRB =			TVS_AVE_RESOLUTION_1920X1200_60HZRB ,
	TVS_RESOLUTION_1920X1200_60HZ	=			TVS_AVE_RESOLUTION_1920X1200_60HZ	,
	TVS_RESOLUTION_2048X1152_60HZRB =			TVS_AVE_RESOLUTION_2048X1152_60HZRB ,
	TVS_RESOLUTION_2560X1600_60HZRB =			TVS_AVE_RESOLUTION_2560X1600_60HZRB ,
	TVS_RESOLUTION_PC_END	=			TVS_AVE_RESOLUTION_PC_END	,
	TVS_RESOLUTION_2560X1080_60HZ =			TVS_AVE_RESOLUTION_2560X1080_60HZ,
	TVS_RESOLUTION_NOSIGNAL =			TVS_AVE_RESOLUTION_NOSIGNAL ,
	TVS_RESOLUTION_NOVIDEO	=			TVS_AVE_RESOLUTION_NOVIDEO	, 	// Banner 의 표시 없이 AV Mute 만 제어해야 하는 경우 사용 (to control AV Mute without showing banner)
	TVS_RESOLUTION_UNKNOWN	=			TVS_AVE_RESOLUTION_NOTDEFINE	,
	TVS_RESOLUTION_NOTSUPPORT =			TVS_AVE_RESOLUTION_NOTSUPPORTED ,
		
	//For UD	=			//For UD	,
	TVS_RESOLUTION_2160P_START	=			TVS_AVE_RESOLUTION_2160P_START	,
	TVS_RESOLUTION_2160P_30HZ	=			TVS_AVE_RESOLUTION_2160P_30HZ	,
	TVS_RESOLUTION_2160P_24HZ	=			TVS_AVE_RESOLUTION_2160P_24HZ	,
	TVS_RESOLUTION_2160P_25HZ	=			TVS_AVE_RESOLUTION_2160P_25HZ	,
	TVS_RESOLUTION_2160P_60HZ_HALF	=			TVS_AVE_RESOLUTION_2160P_60HZ_HALF	,
	TVS_RESOLUTION_2160P_60HZ	=			TVS_AVE_RESOLUTION_2160P_60HZ	,
	TVS_RESOLUTION_2160P_50HZ_HALF	=			TVS_AVE_RESOLUTION_2160P_50HZ_HALF	,
	TVS_RESOLUTION_2160P_50HZ	=			TVS_AVE_RESOLUTION_2160P_50HZ	,
	TVS_RESOLUTION_4096X2160P_START =			TVS_AVE_RESOLUTION_4096X2160P_START ,
	TVS_RESOLUTION_4096X2160P_24HZ	=			TVS_AVE_RESOLUTION_4096X2160P_24HZ	,
	TVS_RESOLUTION_4096X2160P_25HZ	=			TVS_AVE_RESOLUTION_4096X2160P_25HZ	,
	TVS_RESOLUTION_4096X2160P_30HZ	=			TVS_AVE_RESOLUTION_4096X2160P_30HZ	,
	TVS_RESOLUTION_4096X2160P_60HZ_HALF =			TVS_AVE_RESOLUTION_4096X2160P_60HZ_HALF ,
	TVS_RESOLUTION_4096X2160P_60HZ	=			TVS_AVE_RESOLUTION_4096X2160P_60HZ	,
	TVS_RESOLUTION_4096X2160P_50HZ_HALF =			TVS_AVE_RESOLUTION_4096X2160P_50HZ_HALF ,
	TVS_RESOLUTION_4096X2160P_50HZ	=			TVS_AVE_RESOLUTION_4096X2160P_50HZ	,
	TVS_RESOLUTION_4096X2160P_END	=			TVS_AVE_RESOLUTION_4096X2160P_END	,
	TVS_RESOLUTION_2160P_NOTDEFINE	=			TVS_AVE_RESOLUTION_2160P_NOTDEFINE	,
	TVS_RESOLUTION_2160P_END	=			TVS_AVE_RESOLUTION_2160P_END	,
	TVS_RESOLUTION_PC = TVS_AVE_RESOLUTION_MAX + 1,
	TVS_RESOLUTION_MAX,
	
}EResolution;

typedef enum
{
	RES_CLASS_RESERVED = 0, //reserved
	RES_CLASS_HD_AV = 1,	// HD A/V
	RES_CLASS_SD_AV = 2,	// SD A/V
	RES_CLASS_HD_DATA = 3,	//HD data service
	RES_CLASS_SD_DATA = 4,	// SD data service
	RES_CLASS_H264_HD_AV = 5,	// H.264 HD A/V
	RES_CLASS_H264_HD_DATA = 6, // H.264 HD data service
}EResolutionClass;

typedef enum
{
	PLUGGED_SOURCE_NONE = 0x00000000,
	PLUGGED_SOURCE_AV1 = 0x00000001,
	PLUGGED_SOURCE_AV2 = 0x00000002,
	PLUGGED_SOURCE_AV3 = 0x00000004,
	PLUGGED_SOURCE_SV1 = 0x00000008,
	PLUGGED_SOURCE_SV2 = 0x00000010,
	PLUGGED_SOURCE_SV3 = 0x00000020,
	PLUGGED_SOURCE_COMP1 = 0x00000040,
	PLUGGED_SOURCE_COMP2 = 0x00000080,
	PLUGGED_SOURCE_COMP3 = 0x00000100,
	PLUGGED_SOURCE_PC1 = 0x00000200,
	PLUGGED_SOURCE_PC2 = 0x00000400,
	PLUGGED_SOURCE_PC3 = 0x00000800,
	PLUGGED_SOURCE_HDMI1 = 0x00001000,
	PLUGGED_SOURCE_HDMI2 = 0x00002000,
	PLUGGED_SOURCE_HDMI3 = 0x00004000,
	PLUGGED_SOURCE_HDMI4 = 0x00008000,
	PLUGGED_SOURCE_SCART1 = 0x00010000,
	PLUGGED_SOURCE_SCART2 = 0x00020000,
	PLUGGED_SOURCE_SCART3 = 0x00040000,
	PLUGGED_SOURCE_DVI1 = 0x00080000,
	PLUGGED_SOURCE_DVI2 = 0x00100000,
	PLUGGED_SOURCE_DVI3 = 0x00200000,
	PLUGGED_SOURCE_DP1 = 0x00400000,
	PLUGGED_SOURCE_MAGIC_INFO = 0x00800000,
	PLUGGED_SOURCE_DIIVA = 0x01000000,
	PLUGGED_SOURCE_ALL = 0xFFFFFFFF,
}EPluggedType;

typedef enum
{
	DUALVIEW_TYPE_DUALTV,
	DUALVIEW_TYPE_TV2MOBILE
}EDualViewType;

typedef enum
{
	MUTE_MODE_NORMAL,			// regular lock used by app
	MUTE_MODE_MASTER,			// highest priority lock, intended for CI, cannot be unlocked by NORMAL unmute
	MUTE_MODE_CHANNELLOCK,		// lock related to user 'channel lock' functionality
}EMuteMode;

struct TSAudio: public TCMarshalable
{
	enum
	{
		TAG_MULTISOUND,
		TAG_DECODETYPE,
		TAG_PID,
		TAG_AUDIOMODE,
		TAG_COMPONENTTAG,
		TAG_AUDIOTYPE,
		TAG_AUDIONAME,
	};
	//! Multi sound 모드
	ELanguageCode multiSound;
	//! Decode type
	EAudioEncodeType decodeType;
	//! PID
	unsigned short pid;
	//! Audio mode : Dual I, II, Stereo
	EMultiSoundMode audioMode;

	int componentTag;

	EAudioType audioType;

	t_wchar_t audioName[MAX_AUDIO_NAME_LENGTH];

public:

	TSAudio();

	bool Initialize(void);

	bool operator==(const TSAudio& src) const;

	TSAudio& operator=(const TSAudio& src);

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

struct TSVideo: public TCMarshalable
{
	enum
	{
		TAG_VIDEOPID,
		TAG_VIDEOENCODETYPE,
		TAG_PCR,
	};

	unsigned short videoPid;

	EVideoEncodeType encodeType;

	// program clock reference pid
	unsigned short pcrPid;

public:

	TSVideo();

	bool Initialize(void);

	bool operator==(const TSVideo& src) const;

	TSVideo& operator=(const TSVideo& src);

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




typedef enum  {
	ASPECTRATIO_TYPE_UNKNOWN = 0,
	ASPECTRATIO_TYPE_100_100    = 1, // 1:1
	ASPECTRATIO_TYPE_300_400    = 2, // 3:4
	ASPECTRATIO_TYPE_900_1600   = 3, // 9:16
	ASPECTRATIO_TYPE_100_221    = 4, // 1:2.21
} EAspectratioType;

struct TSResolution: public TCMarshalable
{
	enum
	{
		TAG_HORIZONTAL,
		TAG_VERTICAL,
		TAG_FREQUENCY,
		TAG_HFREQUENCY,
		TAG_STATE,
		TAG_SCANTYPE,
		TAG_ASPECTRATIO,
		TAG_NEARFREQUENCY,
	};
	//!< Standard Resolution Data for APP, if you want more value, pleases contact with inhwan10.kim
	unsigned int horizontal;		//!< Horizontal size
	unsigned int vertical;			//!< Vertical size
	unsigned int frequency;		//!< Vertical Frequency Rate : Usually this frequency value is used to determine video frequency
	unsigned int hFrequency;		// Horizontal Frequency Rate
	unsigned int status;
	unsigned int scantype; 
	EAspectratioType aspectratio; 
	bool nearfreqency;

	void Initialize(void)
	{
		horizontal = 0;
		vertical = 0;
		frequency = 0;
		hFrequency = 0;
		status = 0;
		scantype = 0;
		aspectratio = ASPECTRATIO_TYPE_UNKNOWN;
		nearfreqency = false;
	}

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


class TCComponent
{
public:
	//! PID
	unsigned short pid;
	//! component_tag in stream identifier descriptor
	unsigned char componentTag;
	unsigned char streamType;
	// 4 byte

	// Hierarchical Transmission Level 정보
	bool mhLevel;	// true: HIGH , false:LOW level
	char dummy_char;
	unsigned short mhAlternativePid;
	// 4 byte

	TCComponent( void );
	bool FlagEqual( TCComponent* src );

	/*
	// For Serialize 
	virtual TISerializable::ESerializableType GetSerializedType(void);
	virtual bool ClassToTree(TCMarshalTreeBranch& treeParent);
	virtual bool TreeToClass(TCMarshalTreeBranch& treeMine);
	*/
};



typedef struct
{
}TSESPidSet;

typedef enum
{
	TVSTREAM_PROPERTY_DEMUX_ID,
	TVSTREAM_PROPERTY_ADAPTER_ID,
}ETVStreamProperty;


#endif // _AVCONTROLDATATYPE_H_

