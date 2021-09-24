/** 
 * @file TreeBranchMap.h
 * @brief Tree Branch (subnodes kept in map) class used to send marshalled data
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
 
#ifndef _TREEBRANCHMAP_H_
#define  _TREEBRANCHMAP_H_

#include <map>

#include "TreeBranch.h"

class TCTreeBranchMap : public TCTreeBranch
{
public:
	~TCTreeBranchMap();

	TCTreeBranchMap();
	TCTreeBranchMap(int tag);
	TCTreeBranchMap(TCMessageBuffer* pBuffer);
	TCTreeBranchMap(int tag, int length, TCMessageBuffer * pBuffer, int offset);

	TCTreeBranchMap(const TCTreeBranchMap& branch);
	TCTreeBranchMap& operator=(const TCTreeBranchMap& branch);

	/**
	 * @brief Gets size of array for given node
	 * @param [in] nClassLen length of class object
	 * @return size of array
	 */
	int GetArrayCount(int nClassLen) const;

	/**
	 * @brief Finds subnode of given ID
	 * @param [in] tag data tag to be found
	 * @return pointer to found node or NULL
	 */
	TCTreeNode* Find(int tag);

	/**
	 * @brief Deletes given data tag from branch
	 * @param [in] tag data tag to be deleted
	 * @return true if node found
	 */
	bool Remove(int tag);

	/**
	 * @brief Adds new leaf with fixed length (up to 4 bytes)
	 * @param [in] tag marshal tag
	 * @param [in] value data to be put into leaf
	 * @return pointer to found node or NULL
	 */
	TCTreeLeafFixed* AddLeaf(int tag, int value);

	/**
	 * @brief Adds new leaf with variable length
	 * @param [in] tag marshal tag
	 * @param [in] len length of data
	 * @param [in] pData data to be put into leaf
	 * @return pointer to found node or NULL
	 */
	TCTreeLeafVar* AddLeaf(int tag, int len, const void* pData);

	/**
	 * @brief Adds new branch
	 * @param [in] tag marshal tag
	 */
	TCTreeBranchList* AddBranchList(int tag);

	/**
	 * @brief Adds new mapped branch
	 * @param [in] tag marshal tag
	 */
	TCTreeBranchMap* AddBranchMap(int tag);

	/**
	 * @brief Adds new node
	 * @param [in] pNode pointer to node to be added
	 */
	void AddNode(TCTreeNode* pNode);

	/**
	 * @brief Adds new node
	 * @param [in] pNode pointer to node to be added
	 */
	void t_AddNode(TCTreeNode* pNode);

	/**
	 * @brief Deletes all subnodes
	 */
	void DestroySubNodes();

	/**
	 * @brief Makes a deep copy of subnodes
	 * @param [out] subNodes destination of copied subnodes
	 */
	void DeepCopySubNodes(std::map<int, TCTreeNode*>& subNodes) const;

	/**
	 * @brief Gets length of node with all subnodes
	 * @return length of branch
	 */
	int GetNodeSize( void ) const;

	/**
	 * @brief Puts data into buffer
	 * @param [inout] pBuffer destination buffer
	 */
	void StoreInBuffer( TCMessageBuffer* pBuffer );

	typedef std::map<int, TCTreeNode*>::const_iterator TreeBranchMapIterator;

	TreeBranchMapIterator Begin() const { return m_subNodes.begin(); }

	TreeBranchMapIterator End() const { return m_subNodes.end(); }

private:
	std::map<int, TCTreeNode*> m_subNodes;
};

#endif // _TREEBRANCHMAP_H_
