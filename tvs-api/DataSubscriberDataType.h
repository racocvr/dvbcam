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

#ifndef _DATASUBSCRIBERDATATYPE_H_
#define _DATASUBSCRIBERDATATYPE_H_


#include <vector>

#include "Marshalable.h"


typedef enum
{
	CLOSED_CAPTION_TYPE_UNDEFINED = 0,
	CLOSED_CAPTION_TYPE_ANALOG,			// EIA608, DVS157
	CLOSED_CAPTION_TYPE_DIGITAL,		// EIA708, DVS053
	ANALOG_TTX_DATA,
}EClosedCaptionType;


struct TSCaption: public TCMarshalable
{
	enum
	{	
		TAG_TYPE,
		TAG_DATA,
	};

	EClosedCaptionType type;
	std::vector<unsigned char> data;

	/* Methods which implement marshaling */
	virtual bool ClassToTree(TCTreeBranch& treeParent);
	virtual bool TreeToClass(TCTreeBranch& treeMine);
};



#endif //_DATASUBSCRIBERDATATYPE_H_
