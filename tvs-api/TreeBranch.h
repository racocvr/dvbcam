/** 
 * @file TreeBranch.h
 * @brief Tree Branch class used to send marshalled data
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

#ifndef _TREEBRANCH_H_
#define  _TREEBRANCH_H_

#include "TreeNode.h"
#include "IMarshalable.h"
#include "IPCDataType.h"

class TCTreeBranchMap;
class TCTreeBranchList;
class TCTreeLeafFixed;
class TCTreeLeafVar;

class TCTreeBranch : public TCTreeNode
{
public:
	virtual ~TCTreeBranch(){};

	/**
	 * @brief Returns length of node
	 * @return length of node
	 */
	virtual int GetLength( void ) const { return 0; };

	/**
	 * @brief Deletes given data tag from branch
	 * @param [in] tag data tag to be deleted
	 * @return true if node found
	 */
	virtual bool Remove(int tag) = 0;

	/**
	 * @brief Gets size of array for given node
	 * @param [in] nClassLen length of class object
	 * @return size of array
	 */
	virtual int GetArrayCount(int nClassLen) const = 0;
	
	/**
	 * @brief Deletes all subnodes
	 */
	virtual void DestroySubNodes() = 0;
	
	/**
	 * @brief Finds subnode of given ID
	 * @param [in] tag data  tag to be found
	 * @return pointer to found node or NULL
	 */
	virtual TCTreeNode* Find(int tag) = 0;

	/**
	 * @brief Adds new leaf with fixed length (up to 4 bytes)
	 * @param [in] tag marshal tag
	 * @param [in] value data to be put into leaf
	 * @return pointer to found node or NULL
	 */
	virtual TCTreeLeafFixed* AddLeaf(int tag, int value) = 0;

	/**
	 * @brief Adds new leaf with variable length
	 * @param [in] tag marshal tag
	 * @param [in] len length of data
	 * @param [in] pData data to be put into leaf
	 * @return pointer to found node or NULL
	 */
	virtual TCTreeLeafVar* AddLeaf(int tag, int len, const void* pData) = 0;

	/**
	 * @brief Adds new branch
	 * @param [in] tag marshal tag
	 */
	virtual TCTreeBranchList* AddBranchList(int tag) = 0;

	/**
	 * @brief Adds new mapped branch
	 * @param [in] tag marshal tag
	 */
	virtual TCTreeBranchMap* AddBranchMap(int tag) = 0;

	/**
	 * @brief Adds new node
	 * @param [in] pNode pointer to node to be added
	 */
	virtual void AddNode(TCTreeNode* pNode) = 0;

	/**
	 * @brief Gets length of node with all subnodes
	 * @return length of branch
	 */
	virtual int GetNodeSize( void ) const = 0;

	/**
	 * @brief Puts data into buffer
	 * @param [inout] pBuffer destination buffer
	 */
	virtual void StoreInBuffer( TCMessageBuffer* pBuffer ) = 0;
	
	/**
	 * @brief Gets from message buffer information how data should be stored (map/list).
	 * @param [inout] pBuffer destination buffer.
	 * @param [out] storageType storage type.
	 * @return true if message buffer describes branch, false otherwise.
	 */
	static bool ReadStorageType( TCMessageBuffer* pBuffer, EMarshalableStorageType &storageType );
protected:

	/**
	 * @brief Recreates subnodes out of serialized data in buffer
	 * @param [in] length length of branch
	 * @param [in] pBuffer buffer with serialized data
	 * @param [in] offset starting offset for reading from buffer 
	 */
	void t_RebuildSubnodes(int length, TCMessageBuffer * pBuffer, int offset);

	/**
	 * @brief Adds new node
	 * @param [in] pNode pointer to node to be added
	 */
	virtual void t_AddNode(TCTreeNode* pNode) = 0;
};

#endif // _TREEBRANCH_H_
