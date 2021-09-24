/** 
 * @file TreeLeafFixed.h
 * @brief Tree Leaf class (with fixed size up to 4 bytes) used to send marshalled data
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

#ifndef _TREELEAFFIXED_H_
#define  _TREELEAFFIXED_H_

#include "TreeLeaf.h"
#include "TVServiceAssert.h"

#define LEAF_FIXED_SIZE 4

class TCTreeLeafFixed : public TCTreeLeaf
{
public:
	~TCTreeLeafFixed(){};

	TCTreeLeafFixed(int tag, int value );
	TCTreeLeafFixed(int tag, TCMessageBuffer* pBuffer, int offset);

	TCTreeLeafFixed(const TCTreeLeafFixed& leaf);
	TCTreeLeafFixed& operator=(const TCTreeLeafFixed& leaf);

	/**
	 * @brief Returns length of node
	 * @return length of node
	 */
	int GetLength( void ) const { return LEAF_FIXED_SIZE; };

	/**
	 * @brief Returns value of the leaf
	 * @return value of the leaf
	 */
	int GetValue( void ) const { return m_value; };

	/**
	 * @brief Calculates length of node
	 * @return length of node
	 */
	int GetNodeSize( void ) const;

	/**
	 * @brief Gets size of array for given node
	 * @param [in] nClassLen length of class object
	 * @return size of array
	 */
	int GetArrayCount(int nClassLen) const { API_ASSERT(0); return 0; }; /// fixed leaf is wrong container for array

	/**
	 * @brief Puts data into buffer
	 * @param [inout] pBuffer destination buffer
	 */
	void StoreInBuffer( TCMessageBuffer* pBuffer );

	/**
	 * @brief Copies data from node to given destination
	 * @param [in] pOutput destination of copied data
	 * @param [in] len number of bytes to be copied
	 * @return true if success
	 */
	bool CopyData(void* pOutput, int len) const;

	/**
	 * @brief Returns pointer to node data
	 * @return constant pointer to data kept in leaf
	 */
	const void* GetData() const;

private:
	int m_value;
};

#endif // _TREELEAFFIXED_H_
