/** 
 * @file MarshallingHelperNative.h
 * @brief DTool class for External API helping in marshalling process (Native side)
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

#ifndef _MARSHALLINGHELPERNATIVE_H_
#define _MARSHALLINGHELPERNATIVE_H_

#include "MarshallingHelper.h"
#include "MessageBuffer.h"


class TCMarshallingHelperNative: public TCMarshallingHelper
{
public:

	TCMarshallingHelperNative();
	virtual ~TCMarshallingHelperNative();

	/**
	 * @brief Adds array element to item list that should be marshalled
	 * @param [in] pReceivedBuffer input buffer
	 * @param [in] pReplyBuffer output buffer
	 */
	void SetBuffers(TCMessageBuffer* pReceivedBuffer, TCMessageBuffer* pReplyBuffer);

	/**
	 * @brief Creates tree from input buffer
	 */
	void CreateTree();

	/**
	 * @brief Creates objects out of tree
	 */
	virtual void FillOutTreeToClass();

	/**
	 * @brief Creates output buffer
	 * @param [in] functionCode function code of called method
	 * @return true if success
	 */
	virtual bool Run( int functionCode );

	/**
	 * @brief Converts given list of items, that should be returned to proxy, into tree
	 * @param [in] treeParent result tree
	 * @return true if success
	 */
	virtual bool ClassToTree(TCTreeBranch& treeParent);

	/**
	 * @brief Converts given tree, that is received from proxy, basing on list of items into objects
	 * @param [in] treeMine tree to be converted
	 * @return true if success
	 */
	virtual bool TreeToClass(TCTreeBranch& treeMine);

	/**
	 * @brief Gets node by given number in order
	 * @param [in] orderNumber number in nodes' order
	 * @return pointer to found node or NULL if not found
	 */
	TCTreeNode* GetNodeByOrder( unsigned char orderNumber );

private:
	TCMessageBuffer*  m_pReceivedBuffer;
	TCMessageBuffer*  m_pReplyBuffer;

	TCTreeBranchList* m_pTree;

	std::vector<TCTreeNode*>::iterator m_itNode;
};

#endif//_MARSHALLINGHELPERNATIVE_H_

