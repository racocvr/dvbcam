/** 
 * @file SectionFeederDataType.h
 * @brief Data types related to feeding sections.
 *
 * Copyright 2014 by Samsung Electronics, Inc.,
 * 
 * This software is the confidential and proprietary information
 * of Samsung Electronics, Inc. ("Confidential Information"). You
 * shall not disclose such Confidential Information and shall use
 * it only in accordance with the terms of the license agreement
 * you entered into with Samsung.
 */

#ifndef _SECTIONFEEDERDATATYPE_H_
#define _SECTIONFEEDERDATATYPE_H_

#include "Marshalable.h"


class TCSectionData : public TCMarshalable
{
private:
	enum
	{
		TAG_PID,
		TAG_DATA,
	};

public:

	/**
	 * @brief Set section pid.
	 * @param [in] pid Section pid.
	 */
	void SetPid( unsigned short pid );

	/**
	 * @brief Get section pid.
	 * @return Section pid.
	 */
	unsigned short GetPid( void ) const;

	/**
	 * @brief Set section data.
	 * @param [in] pData Section data.
	 * @param [in] len Section data length.
	 */
	void SetData( const unsigned char* pData, unsigned int len );

	/**
	 * @brief Get section length.
	 * @return Section length.
	 */
	unsigned int GetDataLength( void ) const;

	/**
	 * @brief Get section data.
	 * @return Section data.
	 */
	const unsigned char* GetData( void ) const;

public:
	virtual bool ClassToTree(TCTreeBranch& treeParent);
	virtual bool TreeToClass(TCTreeBranch& treeMine);

private:
	unsigned short m_pid;
	std::vector<unsigned char> m_data;
};

#endif // _SECTIONFEEDERDATATYPE_H_

