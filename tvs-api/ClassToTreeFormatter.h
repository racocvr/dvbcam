/** 
 * @file ClassToTreeFormatter.h
 * @brief Tool class for External API that helps to put class data fields into tree
 *
 * Copyright 2013 by Samsung Electronics, Inc.,
 * 
 * This software is the confidential and proprietary information
 * of Samsung Electronics, Inc. ("Confidential Information"). You
 * shall not disclose such Confidential Information and shall use
 * it only in accordance with the terms of the license agreement
 * you entered into with Samsung.
 */
	  
#ifdef _WIN32
#pragma once
#endif

#ifndef _CLASSTOTREEFORMATTER_H_
#define _CLASSTOTREEFORMATTER_H_

#include "TreeFormatter.h"

class TCClassToTreeFormatter  : public TCTreeFormatter
{
public:
	TCClassToTreeFormatter(TCTreeBranch* pTree) : TCTreeFormatter(pTree){ m_bExtractSuccess = true; }
	
	/**
	 * @brief Adds integer element to tree
	 * @param [in] tag tag of element
	 * @param [in] value value of element
	 */
	virtual void PushInt(short tag, int value);
	
	/**
	 * @brief Adds raw type element to tree
	 * @param [in] tag tag of element
	 * @param [in] len length
	 * @param [in] pData data to be passed
	 */
	virtual void PushValue(short tag, int len, void* pData);
	
	/**
	 * @brief Adds array element to tree
	 * @param [in] tag tag of element
	 * @param [in] len length
	 * @param [in] pData data to be passed
	 * @param [in] pLen TCLengthInfoContainer for given array
	 */
	virtual void PushLengthArray(short tag, int len, void* pData, TILengthInfoContainer* pLen=NULL);

	/**
	 * @brief Adds class/object element to tree
	 * @param [in] tag tag of element
	 * @param [in] pData data to be passed
	 */
	virtual void PushMarshalableClass(short tag, TIMarshalable* pData);

	/**
	 * @brief Defines if operation ended with success
	 * @return true if at least one element was added to tree
	 */
	virtual bool Extract();
protected:
	bool m_bExtractSuccess;
};

#endif//_CLASSTOTREEFORMATTER_H_

