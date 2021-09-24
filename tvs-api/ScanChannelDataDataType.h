/** 
* @file ScanChannelDataDataType.h
* @brief  Types for scan channel data related interfaces.
*
* Copyright 2014 by Samsung Electronics, Inc.,
* 
* This software is the confidential and proprietary information
* of Samsung Electronics, Inc. ("Confidential Information"). You
* shall not disclose such Confidential Information and shall use
* it only in accordance with the terms of the license agreement
* you entered into with Samsung.
*/

#ifndef _SCANCHANNELDATADATATYPE_H_
#define _SCANCHANNELDATADATATYPE_H_

#include "Marshalable.h"
#include "ServiceDataType.h"
#include "TVServiceDataType.h"
#include <cstring>

typedef enum
{
	FREQUENCY_TYPE_UNKNOWN = -1,
	FREQUENCY_TYPE_STD,
	FREQUENCY_TYPE_HRC,
	FREQUENCY_TYPE_IRC,
}EFrequencyType;

struct TSChannelData: public TCMarshalable
{
	enum
	{
		TAG_CHANNELNUMBERTEXT,
		TAG_CHANNELNUMBER,
		TAG_FREQUENCY,
		TAG_BANDWIDTH,
		TAG_SATELITEID,
		TAG_TRANSPONDERID,
		TAG_POLARISATION,
	};

	char channelNumberText[8];// TODO Duende -> move this text outside - it is used only by APP
	unsigned short channelNumber;
	int frequency;// in [kHz]
	EBandwidth bandwidth;

	int satelliteId;
	int transponderId;
	EDVBSPolarisation polarisation;

	TSChannelData() : channelNumber( INVALID ), frequency( 0 ), bandwidth( BANDWIDTH_UNKNOWN ),
		satelliteId( INVALID ), transponderId( INVALID ), polarisation( DVBS_POL_UNKNOWN )
	{
		std::memset( channelNumberText, 0, 8 );
	}

	/**
	 * @brief Extract Tree from Class
	 * @param [inout] treeParent branch to which object data should be added
	 * @return true if success
	 */
	virtual bool ClassToTree( TCTreeBranch& treeParent );

	/**
	 * @brief Fill out Class from Tree
	 * @param [inout] treeMine branch from which object data should be fetched
	 * @return true if success
	 */
	virtual bool TreeToClass( TCTreeBranch& treeMine );
};

#endif // _SCANCHANNELDATADATATYPE_H_
