/** 
 * @file TunerControlDataType.h
 * @brief Enums for TCTunerControl class.
 *
 * Copyright 2013 by Samsung Electronics, Inc.,
 * 
 * This software is the confidential and proprietary information
 * of Samsung Electronics, Inc. ("Confidential Information"). You
 * shall not disclose such Confidential Information and shall use
 * it only in accordance with the terms of the license agreement
 * you entered into with Samsung.
 */


#ifndef _TUNERCONTROLDATATYPE_H_
#define _TUNERCONTROLDATATYPE_H_

#include "ServiceNavigationDataType.h"
#include "Marshalable.h"
#include "TreeFormatter.h"

typedef enum
{
	CONNECT_SINGLE,
	CONNECT_DUAL,
}ESatelliteAntennaConnectionType;

typedef enum
{
	TUNER_VOID,//!< no tuner on the board
	TUNER_T,//!< only terrestrial
	TUNER_C,//!< only cable
	TUNER_S,//!< only satellite
	TUNER_TC,//!< terrestrial plus cable
	TUNER_TS,//!< terrestrial plus satellite
	TUNER_CS,//!< cable plus satellite
	TUNER_TCS,//!< terrestrial plus cable plus satellite
	TUNER_T2,//!< only terestrial 2
	TUNER_T2C,//!< terrestrial2 plus cable
	TUNER_T2S,//!< terrestrial2 plus satellite
	TUNER_T2CS,//!< terrestrial2 plus cable plus satellite
}ETunerKind; 

typedef enum
{
	SIGNAL_KIND_NONE,	//!< for no signal
	SIGNAL_KIND_DVB_C, 
	SIGNAL_KIND_DVB_T,
	SIGNAL_KIND_DVB_T2,
	SIGNAL_KIND_DVB_S,
	SIGNAL_KIND_DVB_S2,
	SIGNAL_KIND_DVB_DTMB,//for China 
}ESignalKind;

typedef enum
{
	TUNER_POLICY_UNKNOWN = -1,
	TUNER_POLICY_MAIN ,
	TUNER_POLICY_PIP , 
	TUNER_POLICY_RECORD , 
	TUNER_POLICY_MAX,
}ETunerPolicy;

typedef enum
{
    TUNER_SIGNAL_STATE_NOT_EXIST, 
    TUNER_SIGNAL_STATE_EXIST,
    TUNER_SIGNAL_NOT_SUPPORT,
}ETunerSignalState;

struct TSMuxInfo: public TCMarshalable
{
private:
	enum
	{
		TAG_PTC,
		TAG_ONID,
		TAG_TSID,
		TAG_TVMODE,
		TAG_DTV,
	};
public:
	unsigned short PTC;
	unsigned short onId;
	unsigned short tsId;
	TSTvMode tvMode;
	bool dtv;
	
	TSMuxInfo();
	
	TSMuxInfo(unsigned short chNum , unsigned short originId , unsigned short transId , TSTvMode tvModeInfo , bool dtvService);

	bool operator==(const TSMuxInfo& src);

	TSMuxInfo& operator=(const TSMuxInfo& src);

	/* Methods which implement marshaling */
	virtual bool ClassToTree(TCTreeBranch& treeParent);
	virtual bool TreeToClass(TCTreeBranch& treeMine);
	
protected:
	void t_PushTree(TCTreeFormatter& treeFormatter);
};

#endif // _TUNERCONTROLDATATYPE_H_

