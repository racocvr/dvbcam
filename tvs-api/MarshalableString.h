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

#ifndef _MARSHALABLESTRING_H_
#define _MARSHALABLESTRING_H_

#include "Marshalable.h"
#include <string>
#include "TVServiceAssert.h"
#include "ClassToTreeFormatter.h"
#include "TreeToClassFormatter.h"

class TCMarshalableString : public TCMarshalable
{
public:
	enum
	{
		TAG_LENGTH,
		TAG_STRING,
	};

private:
	std::string *m_data;

	TCMarshalableString & operator= (const TCMarshalableString & base) { return *this; }; // using assign operator is not allowed
	TCMarshalableString(const TCMarshalableString & base){}; // using copy constructor is not allowed

public:
	TCMarshalableString(std::string *in) 
	{ 
		m_data = in; 
	}
	virtual ~TCMarshalableString() 	{}

	/**
	 * @brief Gets size of marshalled object
	 * @param [out] size size of marshalled object
	 * @return true if success
	 */
	virtual bool GetSizeOfMarshalled(unsigned long &size)
	{
		if(m_data)
		{
			size = (unsigned long) m_data->length();
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
		pHelper.PushValue(TAG_LENGTH, sizeof(unsigned long), &sizeOfString);
		
		if(sizeOfString > 0)
		{
			pHelper.PushLengthArray(TAG_STRING, sizeof(char)*sizeOfString, const_cast<char*>(m_data->c_str()));
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
		unsigned long sizeOfString = 0;
		pHelper.PushValue(TAG_LENGTH, sizeof(unsigned long), &sizeOfString);
		
		if(sizeOfString > 0)
		{
			char* pBuffer = new char[sizeOfString+1];
			pHelper.PushLengthArray(TAG_STRING, sizeof(char)*sizeOfString, pBuffer);

			pBuffer[sizeOfString] = '\0';
			*m_data = std::string(pBuffer, sizeOfString);
			delete [] pBuffer;
		}
		else
		{
			// this [else] part is fix to problems with different build CXX flags
			// without transparent declaration of empty string, compiler might create one global, static empty string
			// and point all strings created like "std::string str" to it.
			// As a result, if another application built with -D_GLIBCXX_FULLY_DYNAMIC_STRING tries to free its memory
			// it will end in a crash. Solution is to always create string (with empty text) and put it on a heap.
			
			m_data->reserve(1);
		}
	
		return pHelper.FillOut();	
	}

};


#endif // _MARSHALABLESTRING_H_

