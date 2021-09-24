/** 
 * @file SourceControlDataType.h
 * @brief Enums for TCSourceControl class.
 *
 * Copyright 2013 by Samsung Electronics, Inc.,
 * 
 * This software is the confidential and proprietary information
 * of Samsung Electronics, Inc. ("Confidential Information"). You
 * shall not disclose such Confidential Information and shall use
 * it only in accordance with the terms of the license agreement
 * you entered into with Samsung.
 */

#ifndef _SOURCECONTROLDATATYPE_H_
#define _SOURCECONTROLDATATYPE_H_

#include "Marshalable.h"

#define FLAG_SOURCE_TYPE_AV( sourceType )			( (sourceType) == SOURCE_TYPE_AV1 || (sourceType) == SOURCE_TYPE_AV2 || (sourceType) == SOURCE_TYPE_AV3)
#define FLAG_SOURCE_TYPE_SVIDEO( sourceType )		( (sourceType) == SOURCE_TYPE_SVIDEO1 || (sourceType) == SOURCE_TYPE_SVIDEO2 || (sourceType) == SOURCE_TYPE_SVIDEO3)
#define FLAG_SOURCE_TYPE_COMP( sourceType )			( (sourceType) == SOURCE_TYPE_COMP1 || (sourceType) == SOURCE_TYPE_COMP2 || (sourceType) == SOURCE_TYPE_COMP3)
#define FLAG_SOURCE_TYPE_PC( sourceType )			( (sourceType) == SOURCE_TYPE_PC1 || (sourceType) == SOURCE_TYPE_PC2 || (sourceType) == SOURCE_TYPE_PC3)
#define FLAG_SOURCE_TYPE_HDMI( sourceType )			( (sourceType) == SOURCE_TYPE_HDMI1 || (sourceType) == SOURCE_TYPE_HDMI2 || (sourceType) == SOURCE_TYPE_HDMI3 || (sourceType) == SOURCE_TYPE_HDMI4)
#define FLAG_SOURCE_TYPE_SCART( sourceType )		( (sourceType) == SOURCE_TYPE_SCART1 || (sourceType) == SOURCE_TYPE_SCART2 || (sourceType) == SOURCE_TYPE_SCART3)
#define FLAG_SOURCE_TYPE_DVI( sourceType )			( (sourceType) == SOURCE_TYPE_DVI1 || (sourceType) == SOURCE_TYPE_DVI2 || (sourceType) == SOURCE_TYPE_DVI3)
#define FLAG_SOURCE_TYPE_DUAL_VIEW( sourceType )			( (sourceType) == SOURCE_DUAL_VIEW_DTV || (sourceType) == SOURCE_DUAL_VIEW_HDMI || (sourceType) == SOURCE_DUAL_VIEW_AV || (sourceType) == SOURCE_DUAL_VIEW_SCART || (sourceType) == SOURCE_DUAL_VIEW_COMP || (sourceType) == SOURCE_DUAL_VIEW_PC)
#define FLAG_SOURCE_TYPE_HDMI_GROUP( sourceType )			( FLAG_SOURCE_TYPE_HDMI(sourceType) || FLAG_SOURCE_TYPE_DVI(sourceType) ||(sourceType) == SOURCE_TYPE_MAGICINFO|| (sourceType) == SOURCE_TYPE_DISPLAY_PORT || (sourceType) == SOURCE_TYPE_OPS || (sourceType) == SOURCE_TYPE_HDBT)
#define FLAG_SOURCE_TYPE_PLAYBACK( sourceType )			( (sourceType) == SOURCE_TYPE_PLAYBACK || (sourceType) == SOURCE_TYPE_PLAYBACK_AV )

#define FLAG_SOURCE_TYPE_EXT( sourceType )	( FLAG_SOURCE_TYPE_AV( (sourceType) ) || FLAG_SOURCE_TYPE_SVIDEO( (sourceType) ) || FLAG_SOURCE_TYPE_COMP( (sourceType) ) || FLAG_SOURCE_TYPE_PC( (sourceType) ) || FLAG_SOURCE_TYPE_HDMI( (sourceType) ) || FLAG_SOURCE_TYPE_SCART( (sourceType) ) || FLAG_SOURCE_TYPE_DVI( (sourceType) ) ||(sourceType) == SOURCE_TYPE_MAGICINFO|| (sourceType) == SOURCE_TYPE_DISPLAY_PORT || (sourceType) == SOURCE_TYPE_OPS || (sourceType) == SOURCE_TYPE_HDBT)

#define IS_SOURCE_PVR( sourceType )			( (sourceType) == PIPELINE_SOURCE_PLAYBACK )
#define IS_SOURCE_PC( pipelineType, sourceType )			( (pipelineType) == PIPELINE_SOURCE_PLAYBACK && FLAG_SOURCE_TYPE_PC(sourceType))
#define IS_RESOLUTION_3840_2160P( resolution )			((resolution) >= TVS_RESOLUTION_2160P_START && (resolution) <= TVS_RESOLUTION_2160P_50HZ)
#define IS_RESOLUTION_4096_2160P( resolution )			((resolution) >= TVS_RESOLUTION_4096X2160P_START && (resolution) <= TVS_RESOLUTION_4096X2160P_END)
#define IS_RESOLUTION_2160P( resolution )		( IS_RESOLUTION_3840_2160P(resolution) || IS_RESOLUTION_4096_2160P(resolution) )
#define IS_RESOLUTION_1080P( resolution )		( (resolution) == TVS_RESOLUTION_1080P || (resolution) == TVS_RESOLUTION_1080P_24Hz || (resolution) == TVS_RESOLUTION_1080P_30Hz || (resolution) == TVS_RESOLUTION_1080P_25Hz || (resolution) == TVS_RESOLUTION_1080P_50Hz || (resolution) == TVS_RESOLUTION_1080P_24Hz_3D || (resolution) == TVS_RESOLUTION_1080P_25Hz_3D || (resolution) == TVS_RESOLUTION_1080P_30Hz_3D || (resolution) == TVS_RESOLUTION_1080P_48Hz_3D || (resolution) == TVS_RESOLUTION_1080P_50Hz_3D || (resolution) == TVS_RESOLUTION_1080P_60Hz_3D)
#define IS_RESOLUTION_1080I( resolution )		( (resolution) == TVS_RESOLUTION_1080I || (resolution) == TVS_RESOLUTION_1080I_50Hz || (resolution) == TVS_RESOLUTION_1080I_50Hz_3D || (resolution) == TVS_RESOLUTION_1080I_60Hz_3D)
#define IS_RESOLUTION_720P( resolution )		( (resolution) == TVS_RESOLUTION_720P || (resolution) == TVS_RESOLUTION_720P_50Hz || (resolution) == TVS_RESOLUTION_720P_3D || (resolution) == TVS_RESOLUTION_720P_50Hz_3D)
#define IS_RESOLUTION_480P( resolution )		( (resolution) == TVS_RESOLUTION_480P || (resolution) == TVS_RESOLUTION_480P_861B || (resolution) == TVS_RESOLUTION_480P_SMPTE || (resolution) == TVS_RESOLUTION_640X480P)
#define IS_RESOLUTION_480I( resolution )		( (resolution) == TVS_RESOLUTION_480I || (resolution) == TVS_RESOLUTION_1440X480I)



typedef enum
{
		SOURCE_TYPE_UNDEFINED = -1,
		SOURCE_TYPE_TV = 0,

		SOURCE_TYPE_AV1,
		SOURCE_TYPE_AV2,
		SOURCE_TYPE_AV3,

		SOURCE_TYPE_SVIDEO1,
		SOURCE_TYPE_SVIDEO2,
		SOURCE_TYPE_SVIDEO3,

		SOURCE_TYPE_COMP1,
		SOURCE_TYPE_COMP2,
		SOURCE_TYPE_COMP3,

		SOURCE_TYPE_PC1,	
		SOURCE_TYPE_PC2,	
		SOURCE_TYPE_PC3,	

		SOURCE_TYPE_HDMI1,
		SOURCE_TYPE_HDMI2,
		SOURCE_TYPE_HDMI3,
		SOURCE_TYPE_HDMI4,
		
		SOURCE_TYPE_SCART1,
		SOURCE_TYPE_SCART2,
		SOURCE_TYPE_SCART3,

		SOURCE_TYPE_DVI1,
		SOURCE_TYPE_DVI2,
		SOURCE_TYPE_DVI3,

		SOURCE_DUAL_VIEW_DTV,
		SOURCE_DUAL_VIEW_HDMI,
		SOURCE_DUAL_VIEW_AV,
		SOURCE_DUAL_VIEW_SCART,
		SOURCE_DUAL_VIEW_COMP,
		SOURCE_DUAL_VIEW_PC,
		
		SOURCE_TYPE_PLAYBACK, 	//temp code, need to refactorying
		SOURCE_TYPE_ANALYSIS,

		SOURCE_TYPE_HYBRID_TV,
		
		SOURCE_TYPE_MAGICINFO,
		SOURCE_TYPE_DISPLAY_PORT,
		SOURCE_TYPE_OPS,
		SOURCE_TYPE_HDBT,
		SOURCE_TYPE_PLAYBACK_AV,
		
}ESource;

typedef enum
{
	SOURCE_NAME_NONE,
	SOURCE_NAME_VCR,
	SOURCE_NAME_DVD,
	SOURCE_NAME_CABLE_STB,
	SOURCE_NAME_SATI_STB,
	SOURCE_NAME_PVR_STB,
	SOURCE_NAME_AV_RCV,
	SOURCE_NAME_GAME,
	SOURCE_NAME_CAM,
	SOURCE_NAME_PC,
	SOURCE_NAME_DVI,	// To do : DELETE
	SOURCE_NAME_DVI_PC,
	SOURCE_NAME_DVI_DEVICES,
	SOURCE_NAME_TV,
	SOURCE_NAME_IPTV,
	SOURCE_NAME_BLUE_RAY,
	SOURCE_NAME_HD_DVD,
	SOURCE_NAME_DIGITAL_MEDIA_ADAPTER,
	SOURCE_NAME_MAGICINFO,
	SOURCE_NAME_DISPLAY_PORT,
	SOURCE_NAME_OPS,
	SOURCE_NAME_HDBT,
}ESourceName;

typedef enum
{
	SOURCE_STATE_NONE = -1,
	SOURCE_STATE_SETTING = 0,
	SOURCE_STATE_SIGNAL_OK = 1,
	SOURCE_STATE_NO_SIGNAL = 2,
	SOURCE_STATE_NOT_SUPPORT = 3,
	SOURCE_STATUS_NO_UHD_RESOURCE = 4,	// This is because of resource restrict.
}ESourceState;

typedef enum
{
	SOURCE_STATUS_UNKNOWN = -1, 
	SOURCE_STATUS_AVAILABLE, 		// ready to use
	SOURCE_STATUS_NOT_AVAILABLE,	// supported but not available at the moment (ex. this TV set has HDMI4 port but it is disconnected at the moment)
	SOURCE_STATUS_NOT_SUPPORTED,	// not supported by TV set
}ESourceStatus;

typedef enum
{
	SOURCE_OPTION_SOURCE_NAME,
	SOURCE_OPTION_PC_IMAGE_COARSE,
	SOURCE_OPTION_PC_IMAGE_FINE,
	SOURCE_OPTION_PC_AUTO_ADJUST,
	SOURCE_OPTION_PC_POSITION_CALIBRATION,
	SOURCE_OPTION_PC_RESET,
	SOURCE_OPTION_PC_DPMS,
	SOURCE_OPTION_PC_CHECK,
	SOURCE_OPTION_SCART_STATE,
	SOURCE_OPTION_DECODER_PCRERRORS,
	SOURCE_OPTION_DECODER_PTSERRORS,
	SOURCE_OPTION_CAM_ERROR_STATE,
	SOURCE_OPTION_MAX,
}ESourceOptionPC;

#define MAX_PATH 256

struct TVSHMSinkAttr : public TCMarshalable
{
public:
	enum
	{	
		TAG_SOCKET_PATH,
		TAG_SHM_SIZE,
		TAG_WAIT_FOR_CONNECTION,
		TAG_ASYNC,
		TAG_PERMS,
	};

	char socket_path[MAX_PATH]; 	// TV_PROPERTY_SHMSINK_SOCKET_PATH
	int shm_size; 		// TV_PROPERTY_SHMSINK_SHM_SIZE
	int wait_for_connection; //TV_PROPERTY_SHMSINK_WAIT_FOR_CONNECTION
	bool async;				// TV_PROPERTY_SHMSINK_ASYNC
	unsigned int perms; // TV_PROPERTY_SHMSINK_PERMS

	/**
	 * @see base class
	 */
	virtual bool ClassToTree(TCTreeBranch& treeParent);

	/**
	 * @see base class
	 */
	virtual bool TreeToClass(TCTreeBranch& treeMine);
};

#endif // _SOURCECONTROLDATATYPE_H_
