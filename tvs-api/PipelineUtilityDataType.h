/** 
 * @file PipelineUtilityDataType.h
 * @brief Data types related to pipeline utility.
 *
 * Copyright 2013 by Samsung Electronics, Inc.,
 * 
 * This software is the confidential and proprietary information
 * of Samsung Electronics, Inc. ("Confidential Information"). You
 * shall not disclose such Confidential Information and shall use
 * it only in accordance with the terms of the license agreement
 * you entered into with Samsung.
 */


#ifndef _PIPELINEUTILITYDATATYPE_H_
#define _PIPELINEUTILITYDATATYPE_H_

#include "TunerControlDataType.h"
#include "TVServiceDataType.h"
#include "AVControlDataType.h"
#include "SourceControlDataType.h"
#include "Marshalable.h"
#include "TreeFormatter.h"
#include <map>
#include <vector>

enum EStateChange
{
	STATE_CHANGE_SERVICE,
	STATE_CHANGE_SOURCE,
};

typedef enum
{
	API_TV_RECODER_CREATE 				= 0,
	API_TV_RECODER_CREATE_ATV 			= 1,
	API_TV_STREAM_GET_ATV_RESOLUTION 	= 2,
	API_TV_STREAM_GET_EXT_RESOLUTION 	= 3,
	API_TV_STREAM_SET_ATV_RESOLUTION 	= 4,
	API_TV_STREAM_SET_EXT_RESOLUTION 	= 5,
	API_TV_STREAM_SET_DTV_RESOLUTION 	= 6,
	API_TV_STREAM_SET_ATV_FRAMERATE 	= 7,
	API_TV_STREAM_SET_EXT_FRAMERATE 	= 8,
	API_TV_STREAM_LAST,
}ERecordFailReasonTVPAPI;

typedef enum
{
	TUNER_NONE = -1,
	TUNER_MAIN 	= 0,
	TUNER_SUB 	= 1,
}ETunerIndex;

enum ESIEvent
{
	TVS_SI_MAP_DONE,
	TVS_SI_NO_PSI,
};

class TCPipelineInfo : public TCMarshalable
{
	enum
	{
		TAG_HANDLE,
		TAG_STREAMID,
		TAG_SERVICEID,
		TAG_ACTIVATEDSTATE,
		TAG_CONNECTEDTUNER,
		TAG_SOURCESTATE,
		TAG_RESOLUTION,
		TAG_AVSTATUS,
		TAG_FRAMERATE,
		TAG_SISIGNAL,
	};
public:
	TCPipelineInfo();
	
public:
	
	TVSHandle handle;
	int streamId;
	TCServiceId serviceId;
	int activatedState;
	ETunerIndex connectedTuner;

	ESourceState sourceState;
	EResolution resolution;
	EAVStatus avStatus;
	int frameRate;
	
	std::map<ESIEvent, unsigned long long> siSignal;

	/* Methods which implement marshaling */
	virtual bool ClassToTree(TCTreeBranch& treeParent);
	virtual bool TreeToClass(TCTreeBranch& treeMine);

protected:
		void t_PushTree(TCTreeFormatter& treeFormatter);
};

class TCTPMSStatus : public TCMarshalable
{
	enum
	{
		TAG_RECORDFAILREASON,
		TAG_WAITINGSERVICEID,
		TAG_LASTACTIVATEDPIPELINEHANDLE,
		TAG_POWERSTATE,
		TAG_BOOTREASON,
		TAG_TUNERMUXINFO,
		TAG_PIPELINEPOOL,
	};
public:
	TCTPMSStatus();

	ERecordFailReasonTVPAPI recordFailReason;
	TCServiceId waitingServiceId;
	TVSHandle lastActivatedPipelineHandle;
	int powerState;
	int bootReason;
	std::vector<TSMuxInfo> tunerMuxInfo;
	std::map<TVSHandle, TCPipelineInfo> pipelinePool;


	/* Methods which implement marshaling */
	virtual bool ClassToTree(TCTreeBranch& treeParent);
	virtual bool TreeToClass(TCTreeBranch& treeMine);
	
protected:
		void t_PushTree(TCTreeFormatter& treeFormatter);
};


#endif // _PIPELINEUTILITYDATATYPE_H_
