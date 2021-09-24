/** 
 * @file TreeFormatter.h
 * @brief Tool class for External API that helps to convert data between object and tree
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

#ifndef _TREEFORMATTER_H_
#define _TREEFORMATTER_H_

#include "MarshallingHelper.h" // TODO Duende - move TILengthInfo to new file
#include "IMarshalable.h"
#include "MarshalableNodeCreator.h"

/* TODO Duende - to test if this can be removed
template<typename T>
int GetCount(TCTreeNode* pNode)
{
	T ret = 0;

	if( pNode && 
		pNode->GetLength() == sizeof(T) &&
		(pNode->GetNodeType() == TREE_NODE_LEAF_VAR))
	{
		pNode->CopyData((void*)&ret, sizeof(T));
	}

	return (int)ret;
}
*/

class TCTreeFormatter 
{
public:
	TCTreeFormatter(TCTreeBranch* pTree){ m_pTree = pTree; }
	virtual ~TCTreeFormatter(){}
	
	/**
	 * @brief Adds integer element to tree
	 * @param [in] tag tag of element
	 * @param [in] value value of element
	 */
	virtual void PushInt(short tag, int value) = 0;
	
	/**
	 * @brief Controls flow of raw type element between object and tree
	 * @param [in] tag tag of element
	 * @param [in] len length
	 * @param [in] pData data to be passed
	 */
	virtual void PushValue(short tag, int len, void* pData) = 0;

	/**
	 * @brief Controls flow of array element between object and tree
	 * @param [in] tag tag of element
	 * @param [in] len length
	 * @param [in] pData data to be passed
	 * @param [in] pLen TCLengthInfoContainer for given array
	 */
	virtual void PushLengthArray(short tag, int len, void* pData, TILengthInfoContainer* pLen=NULL) = 0;

	/**
	 * @brief Controls flow of class/object element between object and tree
	 * @param [in] tag tag of element
	 * @param [in] pData data to be passed
	 */
	virtual void PushMarshalableClass(short tag, TIMarshalable* pData) = 0;

	/**
	 * @brief Defines if operation ended with success
	 * @return true if at least one element was added to tree
	 */
	virtual bool Extract(){ return true; }

	/**
	 * @brief Defines if operation ended with success
	 * @return false if at least one element was not fetched from tree
	 */
	virtual bool FillOut(){ return true; }

protected:
	TCTreeBranch* m_pTree;

	DefaultNodeCreator m_DefaultNodeCreator;
	TCMarshalableNodeCreator m_MarshalableNodeCreator;

};

#endif//_TREEFORMATTER_H_

