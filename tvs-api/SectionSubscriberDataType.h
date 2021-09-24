/** 
 * @file SectionSubscriberDataType.h
 * @brief Section subscription related data types.
 *
 * Copyright 2013 by Samsung Electronics, Inc.,
 * 
 * This software is the confidential and proprietary information
 * of Samsung Electronics, Inc. ("Confidential Information"). You
 * shall not disclose such Confidential Information and shall use
 * it only in accordance with the terms of the license agreement
 * you entered into with Samsung.
 */

#ifndef _SECTIONSUBSCRIBERDATATYPE_H_
#define _SECTIONSUBSCRIBERDATATYPE_H_


#include <stddef.h>
#include <vector>
#include "Marshalable.h"
#include "TVServiceDataType.h"

typedef enum
{
	// In that mode only already cached section will be send.
	// Feature not supported right now, behaves as SECTION_SUBSCRIBE_CACHE_OR_STREAM !.
	SECTION_SUBSCRIBE_CACHE,
	// In that mode section will be send from cache in SI and directly from the stream.
	// Since on every subscription SI monitors are restarted this mode beside being a little faster is no different then SECTION_SUBSCRIBE_STREAM.
	SECTION_SUBSCRIBE_CACHE_OR_STREAM,
	// In that mode section will be send only from the stream.
	SECTION_SUBSCRIBE_STREAM,

} ESectionSubscribeType;

typedef enum
{
	DEVICE_INBAND,
	DEVICE_OOB,
	DEVICE_MAX,
} EDevice;


class TCSectionCriteriaHelper : public TCMarshalable
{
private:
	enum
	{
		TAG_PID,
		TAG_TABLEID,
		TAG_PROGRAMNUMBER,
		TAG_DEVICE,
		TAG_SSTYPE,
		TAG_CHECKVERSION,
	};

public : 
	//TCSectionCriteriaHelper();
	
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

public:

	unsigned short pid;
	unsigned short tableId;
	unsigned short programNumber;
	EDevice device;
	// type of subscription
	ESectionSubscribeType subscribeType;
	// if section version should be checked
	bool checkVersion;

};

class TCSectionFilterCriteriaHelper : public TCMarshalable
{
private:
	enum
	{
		TAG_PID,
		TAG_FILTER,
		TAG_MASK,
		TAG_INVERT,
		TAG_CHECK_CRC,
	};

public:

	//TCSectionFilterCriteriaHelper();

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

public:

	// pid number we searching on
	unsigned short pid;
	// filter data on given pid
	std::vector<unsigned char> filter;
	// filter mask - can cover some parts of the filter
	std::vector<unsigned char> mask;
	// filter invertion
	std::vector<unsigned char> invert;
	// checksum enable/disable
	bool checkCRC;

};


#endif // _SECTIONSUBSCRIBERDATATYPE_H_
