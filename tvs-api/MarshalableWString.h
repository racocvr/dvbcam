/** 
 * @file MarshalableString.h
 * @brief Marshalable container for keeping STL string
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

#ifndef _MARSHALABLEWSTRING_H_
#define _MARSHALABLEWSTRING_H_

#include "Marshalable.h"
#include <string>
#include "TVServiceAssert.h"
#include "ClassToTreeFormatter.h"
#include "TreeToClassFormatter.h"
#include "TVServiceDataType.h"

//TODO Duende: this can be merged with TCMarshalableString using std::basic_string<T> and typedefs
class TCMarshalableWString : public TCMarshalable
{
private:
	enum
	{
		TAG_STRING,
	};

private:
	t_wstring *m_data;

	TCMarshalableWString & operator= (const TCMarshalableWString & base) { return *this; }; // using assign operator is not allowed
	TCMarshalableWString(const TCMarshalableWString & base){}; // using copy constructor is not allowed
	
public:
	TCMarshalableWString(t_wstring *in) 
	{ 
		m_data = in; 
	}
	virtual ~TCMarshalableWString() 	{}

	/**
	 * @brief Gets size of marshalled object
	 * @param [out] size size of marshalled object
	 * @return true if success
	 */
	virtual bool GetSizeOfMarshalled(unsigned long &size)
	{
		if(m_data)
		{
			size = (unsigned long) m_data->length()*sizeof(t_wchar_t);
			return true;
		}
		return false;
	}

	/**
	 * @brief Extract Tree from Class
	 * @param [inout] treeParent branch to which object data should be added
	 * @return true if success
	 */
	virtual bool ClassToTree(TCTreeBranch& treeParent)
	{
		API_ASSERT(m_data);

		TCClassToTreeFormatter pHelper(&treeParent);
		unsigned long sizeOfString = (unsigned long) m_data->length();
		
		if(sizeOfString > 0)
		{
			pHelper.PushLengthArray(TAG_STRING, sizeof(t_wchar_t)*sizeOfString, const_cast<t_wchar_t*>(m_data->c_str()));
		}

		return pHelper.Extract();	
	}
	
	/**
	 * @brief Gets size of marshalled object
	 * @param [out] size size of marshalled object
	 * @return true if success
	 */
	virtual bool TreeToClass(TCTreeBranch& treeMine)
	{
		API_ASSERT(m_data);

		TCTreeToClassFormatter pHelper(&treeMine);
		TCTreeNode* pNode = pHelper.FindNode(TAG_STRING);
		if(pNode)
		{
			TCTreeLeaf* pLeaf = static_cast<TCTreeLeaf*>(pNode);
			if(pLeaf)
			{
				m_data->assign( (const t_wchar_t*)pLeaf->GetData(), pLeaf->GetLength() / sizeof(t_wchar_t));
			}
		}
		else
		{
			// this [else] part is fix to problems with different build CXX flags
			// without transparent declaration of empty string, compiler might create one global, static empty string
			// and point all strings created like "t_wstring str" to it.
			// As a result, if another application built with -D_GLIBCXX_FULLY_DYNAMIC_STRING tries to free its memory
			// it will end in a crash. Solution is to always create string (with empty text) and put it on a heap.
			
			m_data->reserve(1);
		}
		return pHelper.FillOut();	
	}

};


#endif // _MARSHALABLESTRING_H_

