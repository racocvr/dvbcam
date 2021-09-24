/** 
 * @file TreeNode.h
 * @brief Tree node class used to send marshalled data
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

#ifndef _TREENODE_H_
#define  _TREENODE_H_

#include "MessageBuffer.h"

#define TREE_NODETYPE(x)	(ETreeNodeType)(((x)&0xfc00)>>10) // first 6 bits
#define TREE_NODEID(x)		(short) ((x)&0x3ff) // 7-16 bits
#define TREE_HEAD(a,b)		(short)((((a)&0x3f)<<10)|((b)&0x3ff));

#define TREE_HEAD_SIZE 				2 // 16 bits
#define TREE_LENGTH_SIZE 			4 // size is kept in INTEGER
#define TREE_HEAD_WITH_LENGTH_SIZE 	(TREE_HEAD_SIZE+TREE_LENGTH_SIZE)

enum ETreeNodeType
{
	TREE_NODE_LEAF_FIXED,
	TREE_NODE_LEAF_VAR,
	TREE_NODE_BRANCH_LIST,
	TREE_NODE_BRANCH_MAP,
};

class TCTreeNode
{

public:
	virtual ~TCTreeNode(){}

	/**
	 * @brief Returns length of node
	 * @return length of node
	 */
	virtual int GetLength( void ) const = 0;

	/**
	 * @brief Returns length of node
	 * @return length of node
	 */
	virtual int GetNodeSize( void ) const = 0;
	
	/**
	 * @brief Returns node type
	 * @return type of node
	 */
	virtual ETreeNodeType GetNodeType( void ) const { return t_type; }
	
	/**
	 * @brief Returns node's marshal tag
	 * @return marshal tag of node
	 */
	virtual short GetTag( void ) const { return t_tag; }
	
	/**
	 * @brief Gets size of array for given node
	 * @param [in] nClassLen length of class object
	 * @return size of array
	 */
	virtual int GetArrayCount(int nClassLen) const = 0;

	/**
	 * @brief Puts data into buffer
	 * @param [inout] pBuffer destination buffer
	 */
	virtual void StoreInBuffer( TCMessageBuffer* pBuffer ) = 0;
	
protected:
	short t_tag;
	ETreeNodeType t_type;
};

#endif // _TREENODE_H_
