/** 
 * @file TreeLeafVar.h
 * @brief Tree Leaf class (with variable size) used to send marshalled data
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

#ifndef _TREELEAFVAR_H_
#define  _TREELEAFVAR_H_

#include "TreeLeaf.h"

class TCTreeLeafVar : public TCTreeLeaf
{
public:
	~TCTreeLeafVar();

	TCTreeLeafVar(int tag, int length, const void* pData );
	TCTreeLeafVar(int tag, int length, TCMessageBuffer* pBuffer, int offset);

	TCTreeLeafVar(const TCTreeLeafVar& leaf);
	TCTreeLeafVar& operator=(const TCTreeLeafVar& leaf);

	/**
	 * @brief Returns length of node
	 * @return length of node
	 */
	int GetLength( void ) const { return m_length; };

	/**
	 * @brief Calculates length of node
	 * @return length of node
	 */
	int GetNodeSize( void ) const;
	/**
	 * @brief Puts data into buffer
	 * @param [inout] pBuffer destination buffer
	 */
	void StoreInBuffer( TCMessageBuffer* pBuffer );

	/**
	 * @brief Gets size of array for given node
	 * @param [in] nClassLen length of class object
	 * @return size of array
	 */
	int GetArrayCount(int nClassLen) const;

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
	void* m_pData;
	int m_length;
};

#endif // _TREELEAFVAR_H_

