/**
 * @file ICIStatusDataType.h
 * @brief Types and enums related with ICIStatus interface.
 *
 * Copyright 2015 by Samsung Electronics, Inc.,
 *
 * This software is the confidential and proprietary information
 * of Samsung Electronics, Inc. ("Confidential Information"). You
 * shall not disclose such Confidential Information and shall use
 * it only in accordance with the terms of the license agreement
 * you entered into with Samsung.
 */

#ifndef _CISTATUSDATATYPE_H_
#define _CISTATUSDATATYPE_H_


#include <list>
#include <map>
#include <vector>

#include "Marshalable.h"
#include "ServiceData.h"


struct TSCIMStatusSlotInfo: public TCMarshalable
{
private:

	enum
	{
		TAG_ISCAMNEOIONMP4,
		TAG_CASYSTEMID,
	};

public:

	bool isCamNeotionNp4;
	std::list< unsigned short > caSystemId;

	TSCIMStatusSlotInfo();

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

struct TSCIMStatusInfo: public TCMarshalable
{
private:

	enum
	{
		TAG_ISAUTOCAMVIDEOTRANSCODINGENABLED,
		TAG_SLOTINFORMATION,
	};

public:

	bool isAutoCamVideoTranscodingEnabled;
	std::map< unsigned char, TSCIMStatusSlotInfo > slotInformation;

	TSCIMStatusInfo();

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

struct TSCIMStatusHostControlSlotInfo: public TCMarshalable
{
private:

	enum
	{
		TAG_ISHOSTCONTROLACTIVE,
		TAG_ISHOSTCONTROLPMTPROVIDED,
		TAG_SERVICEID,
		TAG_PROGRAMDATA,
	};

public:

	bool isHostControlActive;
	bool isHostControlPmtProvided;
	TCServiceId serviceId;
	std::vector<unsigned char> programData;

	TSCIMStatusHostControlSlotInfo();

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

struct TSCIMStatusHostControl: public TCMarshalable
{
private:

	enum
	{
		TAG_SLOTINFORMATION,
	};

public:

	std::map< unsigned char, TSCIMStatusHostControlSlotInfo > slotInformation;

	TSCIMStatusHostControl();

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


#endif //_CISTATUSDATATYPE_H_
