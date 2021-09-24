/** 
 * @file DataSubscriberDataType.h
 * @brief Data subscriber related types.
 *
 * Copyright 2013 by Samsung Electronics, Inc.,
 * 
 * This software is the confidential and proprietary information
 * of Samsung Electronics, Inc. ("Confidential Information"). You
 * shall not disclose such Confidential Information and shall use
 * it only in accordance with the terms of the license agreement
 * you entered into with Samsung.
 */

#ifndef _PESDATASUBSCRIBERDATATYPE_H_
#define _PESDATASUBSCRIBERDATATYPE_H_


#include <vector>

#include "Marshalable.h"
#include "DataControlDataType.h"
#include "ServiceData.h"


#define PROFILE_LOG_PES_DATA false

struct TSPESData : public TCMarshalable
{
	enum
	{	
		TAG_TYPE,
		TAG_PID,
		TAG_PTS,		
		TAG_DATA,
	};
	
	EPESDataType type;
	short pid;				// PES PID
	unsigned long pts;		// PES PTS for Subtitle Sync
	std::vector<unsigned char> data;

public:

	TSPESData();

	/* Methods which implement marshaling */
	virtual bool ClassToTree(TCTreeBranch& treeParent);
	virtual bool TreeToClass(TCTreeBranch& treeMine);
};

//<- Definition of struct for internal use.
struct TSExPESData : public TCMarshalable
{
	enum
	{	
		TAG_SERVICEID,
		TAG_COMPONENTTAG,		
		TAG_PESDATA,
	};
	
	TCServiceId serviceId;
	int componentTag;
	TSPESData pesData;

public:

	TSExPESData();

	/* Methods which implement marshaling */
	virtual bool ClassToTree(TCTreeBranch& treeParent);
	virtual bool TreeToClass(TCTreeBranch& treeMine);
};


#endif //_PESDATASUBSCRIBERDATATYPE_H_