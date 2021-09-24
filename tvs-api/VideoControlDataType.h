/** 
 * @file VideoControlDataType.h
 * @brief Data types for TCVideoControl class.
 *
 * Copyright 2013 by Samsung Electronics, Inc.,
 * 
 * This software is the confidential and proprietary information
 * of Samsung Electronics, Inc. ("Confidential Information"). You
 * shall not disclose such Confidential Information and shall use
 * it only in accordance with the terms of the license agreement
 * you entered into with Samsung.
 */


#ifndef _VIDEOCONTROLDATATYPE_H_
#define _VIDEOCONTROLDATATYPE_H_

#include "SourceControlDataType.h"
#include "AVControlDataType.h"
#include "Marshalable.h"

typedef enum
{
	POSITION_TOPLEFT,
	POSITION_TOPRIGHT,
	POSITION_BOTTOMRIGHT,
	POSITION_BOTTOMLEFT,
	POSITION_MIDDLELEFT,
	POSITION_CUSTOM,
	POSITION_DEFAULT,
}EPosition;

typedef enum
{
	PIP_OFF = 0,
	PIP_ON,
}EPIPState;

typedef enum
{
	RECT_SIZE_PIP_SMALL,
	RECT_SIZE_PIP_MEDIUM,
	RECT_SIZE_PIP_LARGE,
	RECT_SIZE_PIP_DOUBLE_SMALL,
	RECT_SIZE_PIP_DOUBLE_SMALL2,
	RECT_SIZE_PIP_DOUBLE_LARGE,
	RECT_SIZE_PIG,
	RECT_SIZE_PIP_POP,

	RECT_SIZE_DEFALUT,
	RECT_SIZE_CUSTOM,
	RECT_SIZE_WIDEPC,
	RECT_SIZE_PC_4_3,
}ERectSize;

typedef enum
{
	SIZE_MAIN_16_9 = 0,
	SIZE_MAIN_ZOOM1 = 1,
	SIZE_MAIN_ZOOM2 = 2,
	SIZE_MAIN_HZOOM = 3,
	SIZE_MAIN_4_3 = 4,
	SIZE_MAIN_FULL = 5,
	SIZE_MAIN_LETTERBOX = 6,
	SIZE_MAIN_WIDE = 7,
	SIZE_MAIN_AUTO = 8,
	SIZE_MAIN_WIDE_4_3 = 9 ,
	SIZE_MAIN_ZOOM = 10,
	SIZE_MAIN_WIDE_MFM = 11,
	SIZE_MAIN_FILL = 12,
	SIZE_MAIN_ANAMORPHIC = 13,
	SIZE_MAIN_CUSTOM = 14,
	SIZE_MAIN_AUTO1 = 15,
	SIZE_MAIN_AUTO2 = 16,
	SIZE_MAIN_DEFAULT = 17,
	SIZE_MAIN_MEDIA_ORIGINAL = 18,
	SIZE_MAIN_MEDIA_MODE1 = 19,
	SIZE_MAIN_MEDIA_MODE2 = 20,
	SIZE_MAIN_ZOOM1_DW = 21, // For Ginga NCL
	SIZE_MAIN_AFD_14X9 = 22, // For Ginga NCL
	SIZE_MAIN_NORMAL = 23,
	SIZE_MAIN_ORIGINAL_RATIO = 24,
	SIZE_MAIN_ALTERNATIVE_VIEW = 25,	// NTV's Alternaitve View
	SIZE_MAIN_MAX,
}EMainSize;

typedef enum
{
	DIRECTION_HORIZONTAL,
	DIRECTION_VERTICAL,	
}EDirection;

typedef enum
{
	PC_POSITION_MOVE_UP,
	PC_POSITION_MOVE_DOWN,
	PC_POSITION_MOVE_LEFT,
	PC_POSITION_MOVE_RIGHT,
}EPCPosition;

typedef enum
{
	PREFERED_RESOLUTION_OFF,
	PREFERED_RESOLUTION_1024_768,
	PREFERED_RESOLUTION_1280_768,
	PREFERED_RESOLUTION_1360_768,
	PREFERED_RESOLUTION_1366_768,
}EPreferedResolution;

typedef enum
{
	QUICK_REPORT_CHIME1,
	QUICK_REPORT_CHIME2,
	QUICK_REPORT_CHIME3,
	QUICK_REPORT_CHIME4,
	QUICK_REPORT_CHIME5,
	BUTTON_OPERATION_SOUND1,
	BUTTON_OPERATION_SOUND2,
	BUTTON_OPERATION_SOUND3,
	BUTTON_OPERATION_SOUND4,
	BUTTON_OPERATION_SOUND5,
	BUTTON_OPERATION_SOUND6,
	BUTTON_OPERATION_SOUND7,
	BUTTON_OPERATION_SOUND8,
	ALERT_SOUND,
	NOT_AVAILABLE1,
	NOT_AVAILABLE2,
}EBuiltinSound;

typedef enum
{
	EWS_END = 0,
	EWS_START = 1,
}EEmergencyWarningSignalState;

typedef enum
{
	SIGNAL_QUALITY_BAD,
	SIGNAL_QUALITY_GOOD,
}ESignalQuality;

// To support Digital Copy Control in JAPAN
// 
// based on ARIB TR-B14 Version 2.8 (Fascicle 3) 
// - Table 4-2 Operation of Descriptors for Digital TV Service and Special Video Service
// - Table 4-3 Operation of Descriptors for Data Service, Special Data Service and Bookmark List Data Service
// - Table 5-1 Output control rules by the Digital Copy Control Descriptor and Content Availability Descriptor
typedef enum
{
	JPN_COPY_FREE,
	JPN_COPY_TEN_TIMES,
	JPN_COPY_ONCE,
	JPN_COPY_ONCE_TSOUT_DISABLED,
	JPN_COPY_NEVER,
	JPN_COPY_NEVER_TSOUT_DISABLED,
	JPN_OUTPUT_PROHIBITED,			// for digital audio output only
}EDigitalCopyControl;

typedef enum
{
	VIDEO_WALL_FORMAT_FULL,
	VIDEO_WALL_FORMAT_NATURAL,
}EVideoWallFormat;

typedef enum
{
	DLNA_MP_MPEG_DIRECTV_SD = 0,
	DLNA_MP_AVC_TS_HP_HD_AC3,
	DLNA_MP_MPEG_TS_HD_NA,
}EDLNAMediaProfile;

typedef enum
{
	DFC_UNKNOWN = -1,
	DFC_NONE,
	DFC_CCO,
	DFC_LB_16_9,
	DFC_LB_14_9,
}EDFC;

typedef enum
{
	SPEAKER_INVALID = -1,
	SPEAKER_MAIN,
	SPEAKER_SCART,
	SPEAKER_DUAL,
	SPEAKER_BT1,
	SPEAKER_BT2,
	SPEAKER_BT3,
	SPEAKER_BT4,
	SPEAKER_RUIS,
	SPEAKER_MAX,
}ESpeaker;

typedef enum
{
	SIDE_GRAY_DARK,
	SIDE_GRAY_LIGHT,
	SIDE_GRAY_OFF,
}ESideGray;

typedef enum
{
	GAME_MODE_THEATER,
	GAME_MODE_3D,
	GAME_MODE_NORMAL,
}EGameMode;

typedef enum
{
	ZORDER_TOP_VIDEO,///< top video, bottom graphic  
	ZORDER_BOTTOM_GRAPHIC,///< top video, bottom graphic   
	ZORDER_BOTTOM_VIDEO,///< bottom video, top graphic   
	ZORDER_TOP_GRAPHIC,///< bottom video, top graphic   
	ZORDER_S_M_B,///< Sub/Main/Bg (Default Window Order)  
	ZORDER_S_B_M,   
	ZORDER_M_S_B,   
	ZORDER_M_B_S,   
	ZORDER_B_S_M,   
	ZORDER_B_M_S,
} EZOrder;

typedef enum
{
	ASPECTRATIO_AUTO,
	ASPECTRATIOTYPE_16_9,
	ASPECTRATIOTYPE_4_3,
	ASPECTRATIOTYPE_WIDE_4_3,
	ASPECTRATIOTYPE_ZOOM1,
	ASPECTRATIOTYPE_ZOOM2,
	ASPECTRATIOTYPE_ZOOM1_DN,
	ASPECTRATIOTYPE_HZOOM,
	ASPECTRATIOTYPE_FULL,
	ASPECTRATIOTYPE_WIDE,
	ASPECTRATIOTYPE_ZOOM,
	ASPECTRATIOTYPE_AUTO1, // smartview1
	ASPECTRATIOTYPE_AUTO2, // smartview2
	ASPECTRATIOTYPE_AFD_14_9, // for AFD. This is not used on Picture size. 
	ASPECTRATIOTYPE_MAX,	
}EASpectRatioType;

typedef enum
{
	PICTURESIZETYPE_16_9,
	PICTURESIZETYPE_ZOOM,
	PICTURESIZETYPE_CUSTOM,
	PICTURESIZETYPE_4_3,
		
	PICTURESIZETYPE_21_9_NORMAL,
	PICTURESIZETYPE_21_9_AUTO,
	PICTURESIZETYPE_21_9_CAPTION,
	PICTURESIZETYPE_ORIGINAL_RATIO,

	PICTURESIZE_WSS_4_3,
	PICTURESIZE_WSS_16_9,
	PICTURESIZE_WSS_ZOOM1,
	PICTURESIZE_WSS_ZOOM1_DN,
	PICTURESIZE_WSS_ZOOM2,
	PICTURESIZE_WSS_WIDEZOOM,
	PICTURESIZE_WSS_14_9,
}EPictureSizeType;

typedef enum
{
	SCREENFITOPTION_OFF,
	SCREENFITOPTION_ON,
	SCREENFITOPTION_AUTO,
}EScreenFitOptionType;


typedef enum
{
	P_SIZESUB_AUTOWIDE,
	P_SIZESUB_4_3_SCREENMODE,
	P_SIZESUB_SCREENFIT,
	P_SIZESUB_ZOOM_POSITION,
	P_SIZESUB_PANORAMA,
}EPictureSizeSubMenuType;
 
 typedef enum
 {
	 SCREENTYPE_MLS,
	 SCREENTYPE_MHL,
	 SCREENTYPE_PC,
	 SCREENTYPE_3DEFFECT,
	 SCREENTYPE_WIDEMODEL,
 }EExceptionScreenStateType;
  

enum
{
	TPT_SCREEN_FULL_WIDTH  = 1920,
	TPT_SCREEN_FULL_HEIGHT = 1080,

	FULL_X_SIZE = TPT_SCREEN_FULL_WIDTH,
	FULL_Y_SIZE = TPT_SCREEN_FULL_HEIGHT,

	JUSTSCAN_X_SIZE = 1920,
	JUSTSCAN_Y_SIZE = 1080,
	JUSTSCAN_X_START = (FULL_X_SIZE-JUSTSCAN_X_SIZE)/2,
	JUSTSCAN_Y_START = (FULL_Y_SIZE-JUSTSCAN_Y_SIZE)/2,

	PC_FULL_X_SIZE	= 1920,
	PC_FULL_Y_SIZE = 1080,
	PC_WXGA_X_SIZE = 1920,

	WIDEPC_X_SIZE = 1800,
	WIDEPC_Y_SIZE = 1008,

	NORMAL_X_SIZE = (FULL_X_SIZE*3)/4,
	NORMAL_X_START = (FULL_X_SIZE-NORMAL_X_SIZE)/2,

	HALF_X_SIZE = FULL_X_SIZE/2,
	HALF_Y_SIZE = FULL_Y_SIZE/2,
	HALF_WIDE_Y_SIZE = (FULL_Y_SIZE*2)/3,
	HALF_WIDE_Y_START = (FULL_Y_SIZE-HALF_WIDE_Y_SIZE)/2,

	PC_X_START = (FULL_X_SIZE-PC_FULL_X_SIZE)/2,
	PC_Y_START = (FULL_Y_SIZE-PC_FULL_Y_SIZE)/2,

	HALF_X_PCSIZE = PC_FULL_X_SIZE/2,
	HALF_Y_PCSIZE = PC_FULL_Y_SIZE/2,
	HALF_Y_PCWIDE_SIZE = (PC_FULL_Y_SIZE*2)/3,
	HALF_WIDE_Y_PCSTART = (PC_FULL_Y_SIZE-HALF_Y_PCWIDE_SIZE)/2,

	EXTENTION_4_3_X_SIZE = (FULL_X_SIZE * 4)/3,
	EXTENTION_4_3_X_START = (FULL_X_SIZE - EXTENTION_4_3_X_SIZE)/2,
	EXTENTION_14_9_X_SIZE = (FULL_X_SIZE * 7)/8,
	EXTENTION_14_9_X_START = (FULL_X_SIZE - EXTENTION_14_9_X_SIZE)/2,

};

enum
{
	SMARTVIEW1_X = 480,
	SMARTVIEW1_Y = 270,
	SMARTVIEW1_W = 960,
	SMARTVIEW1_H = 540,

	SMARTVIEW2_X = 240,
	SMARTVIEW2_Y = 135,
	SMARTVIEW2_W = 1440,
	SMARTVIEW2_H = 810,
};

typedef enum
{
	WSS_DATA_4_3_FULL = 0x8 ,
	WSS_DATA_14_9_FULL = 0xE,
	WSS_DATA_14_9_CENTER= 0x1,
	WSS_DATA_14_9_TOP = 0x2,
	WSS_DATA_16_9_FULL = 0x7,
	WSS_DATA_16_9_CENTER= 0xB,
	WSS_DATA_16_9_TOP = 0x4,
	WSS_DATA_20_9_CENTER= 0xD,
	WSS_DATA_NONE  = 0x0,	
}EWSSData;

typedef enum
{
	SCREENMODE_16_9,
	SCREENMODE_WIDEZOOM,
	SCREENMODE_ZOOM,
	SCREENMODE_4_3,
	SCREENMODE_21_9,
}EScreenModeData;


typedef enum
{
	 AFD_SCALE_NONE,  /* None Scaling  */
	 AFD_SCALE_CCO,  /* Centre Cutout */
	 AFD_SCALE_16_9_CEN, /* Scaling to 16:9 Frame (Centre)*/
	 AFD_SCALE_16_9_TOP, /* Scaling to 16:9 Frame (Top) */
	 AFD_SCALE_14_9_CEN, /* Increase height and reduce width (Centre)*/
	 AFD_SCALE_14_9_TOP, /* Increase height and reduce width (Top)*/
	 AFD_SCALE_14_9_CCO, /* Centre Cutout and Increase height and reduce width */
	 AFD_SCALE_MAX,
}EAfdScale;

typedef enum
{
	RESOLUTION_MODE_UNKNOWN = -1,
	RESOLUTION_MODE_SD,
	RESOLUTION_MODE_HD,
	RESOLUTION_MODE_FULLHD,
	RESOLUTION_MODE_UD_3840,
	RESOLUTION_MODE_UD,
	RESOLUTION_MODE_PC,
}EResolutionMode;

typedef enum
{
	AUTOADJUSTMENT_STATE_FINISH = 0,
	AUTOADJUSTMENT_STATE_START,
	AUTOADJUSTMENT_STATE_TERMINATE,
}EAutoAdjustmentState;

typedef struct
{
}TSRect;

struct TSRectInfo : public TCMarshalable
{
	enum
	{
		TAG_X,
		TAG_Y,
		TAG_HEIGHT,
		TAG_WIDTH,
	};

	int x;
	int y;
	int width;
	int height;

	TSRectInfo(void) : x(0), y(0), width(0), height(0) {};
	TSRectInfo(int dataX, int dataY, int dataWidth, int dataHeight) : x(dataX), y(dataY), width(dataWidth), height(dataHeight) {};

	/**
	 * @see base class
	 */
	virtual bool ClassToTree(TCTreeBranch& treeParent);

	/**
	 * @see base class
	 */
	virtual bool TreeToClass(TCTreeBranch& treeMine);

	void CopyToRect(TSRectInfo rect)
	{
		x = rect.x;
		y = rect.y;
		width = rect.width;
		height = rect.height;
	}
	
	void CopyToValue(int cx, int cy, int cwidth, int cheight)
	{
		x = cx;
		y = cy;
		width = cwidth;
		height = cheight;
	}

	void Initialization()
	{
		x = 0;
		y = 0;
		width = 0;
		height = 0;
	}
};

typedef struct
{
}TSVideoFrame;

struct TSPictureSizeOption
{
	bool bAutoWide;			// 0 : off, 1 : on
	EScreenModeData screenMode_4_3;
	EScreenFitOptionType screenFitOption;			// 0 : 0ff. 1 : on, 2 : auto
	bool bZoomPositionOption;
	int zoomOffSetX;
	int zoomOffSetY;
	int zoomOffSetH;
	int zoomOffSetW;
	bool bPanoramaOption;			// 0 : 0ff, 1: on

	TSPictureSizeOption(void) : bAutoWide(0), screenMode_4_3(SCREENMODE_16_9) , screenFitOption(SCREENFITOPTION_OFF), bZoomPositionOption(0), zoomOffSetX(0), zoomOffSetY(0), zoomOffSetH(0), zoomOffSetW(0), bPanoramaOption(0){};
};

struct TSAspectRatioKey
{
	ESource source;
	EResolution resolution;
	TSResolution resolutionInfo;
	bool dtv;   // It is valide only when source is TV
	
	
	TSAspectRatioKey(void) : source(SOURCE_TYPE_TV), resolution(TVS_RESOLUTION_UNSTABLE) , dtv(false)
	{
		resolutionInfo.Initialize();
		
	};
	
	TSAspectRatioKey(ESource sourceInfo, EResolution res ,TSResolution resInfo ) : source(sourceInfo), resolution(res) , dtv(false)
	{
		resolutionInfo.horizontal = resInfo.horizontal;
		resolutionInfo.vertical = resInfo.vertical;
		resolutionInfo.frequency = resInfo.frequency;
		resolutionInfo.hFrequency = resInfo.hFrequency;
		resolutionInfo.status = resInfo.status;
		resolutionInfo.scantype = resInfo.scantype;
		resolutionInfo.aspectratio = resInfo.aspectratio;
	};
};

enum EPipelineSourceType
{
	PIPELINE_SOURCE_UNKNOWN = -1,
	PIPELINE_SOURCE_TV = 0,
	PIPELINE_SOURCE_EXT_SOURCE,
	PIPELINE_SOURCE_RECORD,
	PIPELINE_SOURCE_PLAYBACK,
};

struct TSSourceTypeInfo
{
	EProfile profileId;
	EPipelineSourceType pipelineType;
	EASpectRatioType mainSize;
	EPictureSizeType pictureSize;
};


struct TSDisplayInfo
{
	int x;
	int y;
	int height;
	int width;
	EZOrder zOrder;
	
	TSDisplayInfo(void) : x(0), y(0), height(0), width(0), zOrder(ZORDER_S_M_B) {};
	TSDisplayInfo(int aX, int aY, int aHeight, int aWidth, EZOrder aZOrder) : x(aX), y(aY), height(aHeight), width(aWidth), zOrder(aZOrder) {};

	bool operator==(const TSDisplayInfo& src)
	{
		if ( (x != src.x)
			 ||(y != src.y)
			 ||(height != src.height)
			 ||(width != src.width)
			 ||(zOrder != src.zOrder)
			)
		{
			return false;
		}
		
		return true;
	}
};

// 21to9 size info by callback of AVOC
struct TS21to9SizeInfo
{
	bool bletterboxdetected;
	bool bX_able;
	bool bHeight_able;
	int iX_blockLine;
	int iHeight_blockLine;

	TS21to9SizeInfo(void) : bletterboxdetected(false), bX_able(true), bHeight_able(true), iX_blockLine(0), iHeight_blockLine(0){};
};

#endif // _VIDEOCONTROLDATATYPE_H_

