/** 
 * @file MarshalableSetContainer.h
 * @brief Marshalable container for keeping STL set
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

#ifndef _MARSHALABLESETCONTAINER_H_
#define  _MARSHALABLESETCONTAINER_H_

#include "Marshalable.h"
#include "TVServiceAssert.h"

template <typename T, class ORIGIN = typename T::value_type>
class TCMarshalableSetContainer  : public TCMarshalable
{
private:
	bool m_bNativeContainer;
	T* m_data;
	TINodeCreator* m_NodeCreator;

	TCMarshalableSetContainer & operator= (const TCMarshalableSetContainer & base) { return *this; }; // using assign operator is not allowed
	TCMarshalableSetContainer(const TCMarshalableSetContainer & base){}; // using copy constructor is not allowed
	
public:

	TCMarshalableSetContainer (T* in, bool bNativeContainer=false, TINodeCreator* pNodeCreator = NULL) 
	{ 
		m_data = in; 
		m_bNativeContainer = bNativeContainer;
		if(pNodeCreator)
		{
			m_NodeCreator = pNodeCreator;
		}
		else
		{
			m_NodeCreator = new DefaultNodeCreator;
		}
	}

	virtual ~TCMarshalableSetContainer () 
	{
		if(m_bNativeContainer && m_data)
		{
			t_Clear();
		}
		delete m_NodeCreator;
		m_NodeCreator = NULL;

	}

	/**
	 * @brief Returns pointer to data
	 * @param [in] pData data to be converted
	 * @param [in] nCount number of element in array (not used)
	 * @return converted data
	 */
	ORIGIN* NewPointer(ORIGIN* pData, int& nCount) 
	{
		return (ORIGIN*)pData;
	}
	
	/**
	 * @brief Returns new pointer of ORIGIN type
	 * @param [in] pData data to be converted (not used)
	 * @param [in] nCount number of element in array
	 * @return converted data
	 */
	ORIGIN* NewPointer(ORIGIN** pData, int& nCount) 
	{
		ORIGIN* pOrigin = NULL; 
		if(m_NodeCreator->IsArrayData())
		{
			if(m_NodeCreator->IsNullizedArray())
			{
				nCount++;
			}
			pOrigin = (new ORIGIN[nCount]);
		}
		else
		{
			pOrigin = new ORIGIN;
		}

		return pOrigin;
	}

	/**
	 * @brief Deletes pointer
	 * @param [in] pData pointer to be deleted
	 * @return true if success
	 */
	void DeletePointer(ORIGIN* pData)
	{
		API_ASSERT(m_NodeCreator);
		if(m_NodeCreator->IsArrayData())
		{
			delete[] pData;
		}
		else
		{
			delete pData;
		}
	}

	/**
	 * @brief Checks if pData is pointer to pointer
	 * @param [in] pData data to be checked
	 * @return True if param is pointer, false otherwise
	 */
	bool IsPointer(ORIGIN* pData) 
	{
		return false;
	}

	/**
	 * @brief Checks if pData is pointer to pointer
	 * @param [in] pData data to be checked
	 * @return True if param is pointer, false otherwise
	 */
	bool IsPointer(ORIGIN** pData) 
	{
		return true;
	}
	
	/**
	 * @brief Returns pointer to data
	 * @param [in] pData data to be converted
	 * @param [out] pBool true if success
	 * @return converted data
	 */
	ORIGIN* ConvertPointer(ORIGIN* pData, bool* pBool = NULL) 
	{
		if(pBool != NULL)
		{
			*pBool = false;
		}	
		return pData;
	}

	/**
	 * @brief Returns pointer to data
	 * @param [in] pData data to be converted
	 * @param [out] pBool true if success
	 * @return converted data
	 */
	ORIGIN* ConvertPointer(ORIGIN** pData, bool* pBool = NULL) 
	{
		if(pBool != NULL)
		{
			*pBool = true;
		}
		return (*pData);
	}	

	/**
	 * @brief Sets value of data with given ones (dummy method)
	 * @param [in] data target that should be set
	 * @param [in] pOrigin source of new data that should be used
	 * @return false 
	 */
	bool SetValueWithOrigin(ORIGIN* data, ORIGIN* pOrigin) 
	{		
		API_ASSERT(data == pOrigin);
		return false;
	}   

	/**
	 * @brief Sets value of data with given ones
	 * @param [in] data target that should be set
	 * @param [in] pOrigin source of new data that should be used
	 * @return true 
	 */
	bool SetValueWithOrigin(ORIGIN** data, ORIGIN* pOrigin) 
	{
		*data = pOrigin;
		return true;
	}

	/**
	 * @see Base class.
	 */
	virtual EMarshalableStorageType GetMarshalableStorageType(void)
	{ 
		return MARSHALABLE_STORAGE_LIST; 
	}

	/**
	 * @brief Extract Tree from Class
	 * @param [inout] treeParent branch to which object data should be added
	 * @return true if success
	 */
	virtual bool ClassToTree(TCTreeBranch& treeParent)
	{
		if(m_data==NULL)
		{
			return true;
		}
		for(typename T::iterator it = m_data->begin(); it != m_data->end(); ++it)
		{
			ORIGIN* pOri = ConvertPointer(const_cast< typename T::value_type* >(&(*it)));
			TCTreeNode* pNode = m_NodeCreator->MakeNewNode(pOri, sizeof(ORIGIN));
			if(pNode)
			{
				treeParent.AddNode(pNode);
			}
		}
		return true;
	}
	
	/**
	 * @brief Gets size of marshalled object
	 * @param [out] size size of marshalled object
	 * @return true if success
	 */
	virtual bool TreeToClass(TCTreeBranch& treeMine)
	{
		if(m_data==NULL)
		{
			return true;
		}

		t_Clear();

		TCTreeBranchList* pTreeMine = static_cast<TCTreeBranchList*>(&treeMine);

		std::vector<TCTreeNode*>::const_iterator it = pTreeMine->GetSubNodes().begin();
		for(;it!=pTreeMine->GetSubNodes().end();++it)
		{

			int nCount = 1;
			if(m_NodeCreator->IsArrayData() == true)
			{
				//LEAF : Data Size를 보고 개수 판단.
				//BRANCH : 하위 노드의 수.
				nCount = (*it)->GetArrayCount(sizeof(ORIGIN));
				
			}

			typename T::value_type value;
			ORIGIN* pOri = NewPointer(&value, nCount);
			m_NodeCreator->PutNodeDataTo((void*)pOri,sizeof(ORIGIN),sizeof(ORIGIN)*nCount , *(*it));

			SetValueWithOrigin(&value, pOri);
			m_data->insert(value);
		}

		return true;
	}

protected:
	
	/**
	 * @brief Clears container
	 */
	bool t_Clear()
	{
		if(m_data == NULL)
		{
			return true;
		}

		if( IsPointer( static_cast<typename T::value_type *>(NULL) ) )
		{
			for(typename T::iterator it = m_data->begin(); it != m_data->end(); ++it)
			{
				DeletePointer(ConvertPointer( const_cast< typename T::value_type* >(&(*it)) )); 
			}
		}
		else if(m_NodeCreator->NodeCreatorType() == eOneDimensionContainerNodeCreator || m_NodeCreator->NodeCreatorType() == eTwoDimensionContainerNodeCreator)
		{
			for(typename T::iterator it = m_data->begin(); it != m_data->end(); ++it)
			{
				m_NodeCreator->ClearSubContainers(ConvertPointer( const_cast< typename T::value_type* >(&(*it)) )); 
			}
		}			
		m_data->clear();

		return true;
	}

};

#endif//_MARSHALABLESETCONTAINER_H_
