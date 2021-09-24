/** 
 * @file MarshalableObjectArray.h
 * @brief Marshalable container for keeping array of objects
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

#ifndef _MARSHALABLEOBJECTARRAY_H_
#define  _MARSHALABLEOBJECTARRAY_H_

#include "TVServiceAssert.h"
#include <vector>

#include "Marshalable.h"
#include "MarshalableNodeCreator.h"

template <typename T, class ORIGIN = T>
class TCMarshalableObjectArray  : public TCMarshalable
{

public:

private:

	T* m_data;
	int m_arrayLength;
	TINodeCreator* m_NodeCreator;
	
	TCMarshalableObjectArray & operator= (const TCMarshalableObjectArray & base) { return *this; }; // using assign operator is not allowed
	TCMarshalableObjectArray(const TCMarshalableObjectArray & base){}; // using copy constructor is not allowed

public:
	TCMarshalableObjectArray(T* in, int arrayLength, TINodeCreator* pNodeCreator = NULL) 
	{ 
		m_data = in; 
		m_arrayLength = arrayLength;

		API_ASSERT(pNodeCreator);
		m_NodeCreator = pNodeCreator;
	}

	virtual ~TCMarshalableObjectArray() 
	{
		delete m_NodeCreator;
		m_NodeCreator = NULL;
	}

	ORIGIN* NewPointer(ORIGIN* pData) 
	{
		return (ORIGIN*)pData;
	}          

	ORIGIN* NewPointer(ORIGIN** pData) 
	{
		return new ORIGIN;
	}

	ORIGIN* ConvertPointer(ORIGIN* pData) 
	{
		return pData;
	}          

	ORIGIN* ConvertPointer(ORIGIN** pData) 
	{
		return (*pData);
	}	

	bool SetValueWithOrigin(ORIGIN* pData, ORIGIN* pOrigin) 
	{		
		API_ASSERT(pData == pOrigin);
		return false;
	}          

	bool SetValueWithOrigin(ORIGIN** pData, ORIGIN* pOrigin) 
	{
		*pData = pOrigin;
		return true;
	}
	
	/**
	 * @see Base class.
	 */
	virtual EMarshalableStorageType GetMarshalableStorageType(void)
	{ 
		return MARSHALABLE_STORAGE_LIST; 
	}

	virtual bool ClassToTree(TCTreeBranch& treeParent)
	{
		if(m_data==NULL)
		{
			return true;
		}
		for(int arrayLoop = 0; arrayLoop < m_arrayLength; ++arrayLoop, ++m_data )
		{
			TCTreeNode* pNode = m_NodeCreator->MakeNewNode(ConvertPointer(m_data), sizeof(ORIGIN));
			
			if(pNode)
			{
				treeParent.AddNode(pNode);
			}
		}
		return true;
	}
	virtual bool TreeToClass(TCTreeBranch& treeMine)
	{
		TCTreeBranchList* pTreeMine = static_cast<TCTreeBranchList*>(&treeMine);

		if(m_data==NULL)
		{
			return true;
		}

		for(std::vector<TCTreeNode*>::const_iterator it = pTreeMine->GetSubNodes().begin();it!=pTreeMine->GetSubNodes().end();++it, ++m_data)
		{
			ORIGIN* pOrg = NewPointer(m_data);
			m_NodeCreator->PutNodeDataTo((void*)pOrg, sizeof(ORIGIN), sizeof(ORIGIN), *(*it));

			SetValueWithOrigin(m_data, pOrg);
		}

		return true;
	}

};


#endif // _MARSHALABLEOBJECTARRAY_H_

