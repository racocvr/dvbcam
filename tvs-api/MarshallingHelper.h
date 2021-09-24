/** 
 * @file MarshallingHelper.h
 * @brief Tool class for External API helping in marshalling process
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

#ifndef _MARSHALLINGHELPER_H_
#define _MARSHALLINGHELPER_H_

#include "TreeBranchMap.h"
#include "TreeBranchList.h"
#include "TreeLeafVar.h"
#include "TreeLeafFixed.h"
#include "MarshalableNodeCreator.h"
#include "TVServiceAssert.h"
#include <cstring>

template <typename T>
T* AllocateMarshalableData(TCTreeNode* pNode, bool useNodeLength = false)
{
	if(pNode == NULL) 
	{
		return NULL;
	}
	if(useNodeLength == false&& ((int) pNode->GetTag()) != 0 )
	{
		return new T;
	}
	else if(useNodeLength == true)
	{
		return new T;
	}

	return NULL;
}

template <typename T>
T* AllocateMarshalableArray(TCTreeNode* pNode, bool useNodeLength = false, bool bMemSet = false)
{
	T* arrayData = NULL;
	int size = 0;

	if(pNode == NULL) 
	{
		return NULL;
	}
	if(useNodeLength == false && pNode->GetLength()> 0 )
	{
		size = pNode->GetLength() / sizeof(T);

		arrayData = new T[size];
		if(arrayData && bMemSet)
		{
			std::memset(arrayData, 0, pNode->GetLength());
		}
		return arrayData;
	}
	else if(useNodeLength == true  && pNode->GetLength() > 0 )
	{
		size = pNode->GetLength() / sizeof(T);

		arrayData = new T[size];
		if(bMemSet)
		{
			std::memset(arrayData, 0, pNode->GetLength());
		}
		return arrayData;
	}

	return NULL;
}

class TILengthInfoContainer
{
public:
	virtual ~TILengthInfoContainer() {};

	/**
	 * @brief Returns kept length
	 * @return length
	 */
	virtual int GetLength() = 0;
};


template <typename LenType = int, typename BufferType = unsigned char >
class TCLengthInfoContainer : public TILengthInfoContainer
{
public:
	TCLengthInfoContainer(LenType* pLen)
	{
		API_ASSERT(pLen);
		m_pLength = pLen;
	}

	/**
	 * @brief Returns kept length
	 * @return length
	 */
	virtual int GetLength()
	{
		return (int)(*m_pLength * sizeof(BufferType) );
	}


private:
	LenType* m_pLength;
};


enum EMarshallingDataTypeTag
{
	MARSHALLING_TAG_VALUE = 0,
	MARSHALLING_TAG_LENGTH_ARRAY,
	MARSHALLING_TAG_MARSHALABLE,
};

enum EMarshallingDirection
{
	MARSHALLING_DIRECTION_OUT,
	MARSHALLING_DIRECTION_IN,
	MARSHALLING_DIRECTION_INOUT,
};

class TCMarshallingHelperItem
{
public:
	TCMarshallingHelperItem()
	{
	}
	
	TCMarshallingHelperItem(EMarshallingDataTypeTag tag, 
						int len, 
						void* pBuffer, 
						TINodeCreator* pNodeCreator=NULL, 
						TILengthInfoContainer* pLengthInfo=NULL) :
		t_DataTypetag(tag),
		t_len(len),
		t_pBuffer(pBuffer), 
		t_pNodeCreator(pNodeCreator),
		t_pLengthInfo(pLengthInfo)
	{
	}

	EMarshallingDataTypeTag t_DataTypetag;
	int t_len;
	void* t_pBuffer;
	TINodeCreator* t_pNodeCreator;
	TILengthInfoContainer* t_pLengthInfo;

};


class TCMarshallingHelper
{
public:
	enum
	{
		TAG_ELEMENT,
	};

	TCMarshallingHelper();
	virtual ~TCMarshallingHelper();
	
	/**
	 * @brief Adds raw type element to item list that should be marshalled
	 * @param [in] type direction of marshalling (in/out/inout)
	 * @param [in] len length
	 * @param [in] pData data to be passed
	 */
	void PushValue(EMarshallingDirection type, int len, void* pData);

	/**
	 * @brief Adds array element to item list that should be marshalled
	 * @param [in] type direction of marshalling (in/out/inout)
	 * @param [in] len length
	 * @param [in] pData data to be passed
	 * @param [in] pLen TCLengthInfoContainer for given array
	 */
	void PushLengthArray(EMarshallingDirection type, int len, void* pData, TILengthInfoContainer* pLen=NULL);

	/**
	 * @brief Adds class/object element to item list that should be marshalled
	 * @param [in] type direction of marshalling (in/out/inout)
	 * @param [in] pData data to be passed
	 */
	void PushMarshalableClass(EMarshallingDirection type, TIMarshalable* pData);

protected:
	std::vector<TCMarshallingHelperItem> m_listItemIn;
	std::vector<TCMarshallingHelperItem> m_listItemOut;

	DefaultNodeCreator m_DefaultNodeCreator;
	TCMarshalableNodeCreator m_MarshalableNodeCreator;
};


#endif // _MARSHALLINGHELPER_H_

