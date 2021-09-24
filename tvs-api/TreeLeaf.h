/** 
 * @file TreeLeaf.h
 * @brief Tree Leaf class used to send marshalled data
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

#ifndef _TREELEAF_H_
#define  _TREELEAF_H_

#include "TreeNode.h"

class TCTreeLeaf : public TCTreeNode
{
public:
	virtual ~TCTreeLeaf(){};

	/**
	 * @brief Returns length of node
	 * @return length of node
	 */
	virtual int GetLength( void ) const = 0;

	/**
	 * @brief Calculates length of node
	 * @return length of node
	 */
	virtual int GetNodeSize( void ) const = 0;

	/**
	 * @brief Gets size of array for given node
	 * @param [in] nClassLen length of class object
	 * @return size of array
	 */
	int GetArrayCount(int nClassLen) const = 0;

	/**
	 * @brief Puts data into buffer
	 * @param [inout] pBuffer destination buffer
	 */
	virtual void StoreInBuffer( TCMessageBuffer* pBuffer ) = 0;

	/**
	 * @brief Copies data from node to given destination
	 * @param [in] pOutput destination of copied data
	 * @param [in] len number of bytes to be copied
	 * @return true if success
	 */
	virtual bool CopyData(void* pOutput, int len) const = 0; // TODO Duende - should be only for Var ??

	/**
	 * @brief Returns pointer to node data
	 * @return constant pointer to data kept in leaf
	 */
	virtual const void* GetData() const = 0; // TODO Duende - should be only for Var ??
};

#endif // _TREELEAF_H_