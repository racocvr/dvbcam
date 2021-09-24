/** 
 * @file Marshalable.h
 * @brief Implementation of interface inherited by classes that can be marshalled
 *
 * Copyright 2013 by Samsung Electronics, Inc.,
 * 
 * This software is the confidential and proprietary information
 * of Samsung Electronics, Inc. ("Confidential Information"). You
 * shall not disclose such Confidential Information and shall use
 * it only in accordance with the terms of the license agreement
 * you entered into with Samsung.
 */

#ifndef _MARSHALABLE_H_
#define _MARSHALABLE_H_

#ifdef _WIN32
#pragma once
#endif

#include "IMarshalable.h"
#include "IPCDataType.h"
#include "MessageBuffer.h"

class TCMarshalable : public TIMarshalable
{

private:
	int m_tag;
	bool m_secure;
	
public:
	TCMarshalable();
	virtual ~TCMarshalable(){}
	
	/**
	 * @brief Returns how marshalable data should be stored
	 * @return Returns storage type
	 */
	virtual EMarshalableStorageType GetMarshalableStorageType(void);

	//virtual void SetSecure();

	/**
	 * @brief Inputs data into data buffer
	 * @param [out] msgBuffer char buffer with marshalled object(s)
	 */
	virtual void Store(TCMessageBuffer* msgBuffer);
	
	/**
	 * @brief Loads data from data buffer
	 * @param [in] msgBuffer char buffer with marshalled object(s)
	 */
	virtual void Load(TCMessageBuffer* msgBuffer);

	/**
	 * @brief Extract Tree from Class
	 * @param [inout] tree branch to which object data should be added
	 * @return true if success
	 */
	virtual bool ClassToTree(TCTreeBranch& tree) ;

	/**
	 * @brief Fill out Class from Tree
	 * @param [inout] tree branch from which object data should be fetched
	 * @return true if success
	 */
	virtual bool TreeToClass(TCTreeBranch& tree) ;

	/**
	 * @brief Gets size of marshalled object
	 * @param [out] size size of marshalled object
	 * @return true if success
	 */
	virtual bool GetSizeOfMarshalled(unsigned long& size) ;
	
};

#endif // _MARSHALABLE_H_