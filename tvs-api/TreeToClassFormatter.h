/** 
 * @file TreeToClassFormatter.h
 * @brief Tool class for External API that helps to fetch class data fields from tree
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

#ifndef _TREETOCLASSFORMATTER_H_
#define _TREETOCLASSFORMATTER_H_

#include "TreeFormatter.h"

class TCTreeNode;

class TCTreeToClassFormatter  : public TCTreeFormatter
{
public:
	TCTreeToClassFormatter(TCTreeBranch* pTree) : TCTreeFormatter(pTree) { m_bFillOutSuccess = true; }
	
	/**
	 * @brief Adds integer element to tree
	 * @param [in] tag tag of element
	 * @param [in] value value of element
	 */
	virtual void PushInt(short tag, int value);
	
	/**
	 * @brief Fetches raw type element from tree
	 * @param [in] type type of element
	 * @param [in] len length
	 * @param [in] pData data to be passed
	 */
	virtual void PushValue(short tag, int len, void* pData);
	
	/**
	 * @brief Fetches array element from tree
	 * @param [in] type type of element
	 * @param [in] len length
	 * @param [in] pData data to be passed
	 * @param [in] pLen TCLengthInfoContainer for given array
	 */
	virtual void PushLengthArray(short tag, int len, void* pData, TILengthInfoContainer* pLen=NULL);

	/**
	 * @brief Fetches class/object element from tree
	 * @param [in] type type of element
	 * @param [in] pData data to be passed
	 */
	virtual void PushMarshalableClass(short tag, TIMarshalable* pData);

	/**
	 * @brief Defines if operation ended with success
	 * @return false if at least one element was not fetched from tree
	 */
	virtual bool FillOut();

	/**
	 * @brief Find node for given marshal tag
	 * @param [in] type marshal tag to be found in tree
	 * @return pointer to found tree node or NULL
	 */
	TCTreeNode* FindNode(short tag);
	
protected:
	bool m_bFillOutSuccess;
};

#endif//_TREETOCLASSFORMATTER_H_

