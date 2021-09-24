/** 
 * @file MarshalableMapContainer.h
 * @brief Marshalable container for keeping STL map and multimap
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

#ifndef _MARSHALABLEMAPCONTAINER_H_
#define  _MARSHALABLEMAPCONTAINER_H_

#include "TVServiceAssert.h"

template <typename T, class ORIGIN = typename T::mapped_type>
class TCMarshalableMapContainer  : public TCMarshalable
{
private:
	bool m_bNativeContainer;
	T* m_data;
	TINodeCreator* m_pNodeCreatorKey;
	TINodeCreator* m_pNodeCreatorValue;

	TCMarshalableMapContainer & operator= (const TCMarshalableMapContainer & base) { return *this; }; // using assign operator is not allowed
	TCMarshalableMapContainer(const TCMarshalableMapContainer & base){}; // using copy constructor is not allowed
	
public:
	TCMarshalableMapContainer(T* in, bool bNativeContainer=false, TINodeCreator* pNodeCreatorKey = NULL, TINodeCreator* pNodeCreatorValue = NULL) 
	{ 
		m_data = in; 
		m_bNativeContainer = bNativeContainer;
		if(pNodeCreatorKey)
		{
			m_pNodeCreatorKey = pNodeCreatorKey;
		}
		else
		{
			m_pNodeCreatorKey = new DefaultNodeCreator;
		}

		if(pNodeCreatorValue)
		{
			m_pNodeCreatorValue = pNodeCreatorValue;
		}
		else
		{
			m_pNodeCreatorValue = new DefaultNodeCreator;
		}
	}

	virtual ~TCMarshalableMapContainer() 
	{
		if(m_bNativeContainer && m_data)
		{
			t_Clear();
		}
		delete m_pNodeCreatorKey;
		m_pNodeCreatorKey = NULL;
		delete m_pNodeCreatorValue;
		m_pNodeCreatorValue = NULL;

	}
	
	/**
	 * @brief Returns pointer to data
	 * @param [in] pData data to be converted
	 * @param [in] nCount number of element in array (not used)
	 * @return pointer
	 */
	ORIGIN* NewPointer(ORIGIN* pData, int& nCount) 
	{
		return (ORIGIN*)pData;
	}

	/**
	 * @brief Returns new pointer of ORIGIN type
	 * @param [in] pData data to be converted (not used)
	 * @param [in] nCount number of element in array
	 * @return pointer
	 */
	ORIGIN* NewPointer(ORIGIN** pData, int& nCount) 
	{
		ORIGIN* pOrigin = NULL; 
		if(m_pNodeCreatorValue->IsArrayData())
		{
			if(m_pNodeCreatorValue->IsNullizedArray())
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
		API_ASSERT(m_pNodeCreatorValue);
		if(m_pNodeCreatorValue->IsArrayData())
		{
			delete[] pData;
		}
		else
		{
			delete pData;
		}
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
			TCTreeNode* pNode = NULL;

			pNode = m_pNodeCreatorKey->MakeNewNode(const_cast<typename T::key_type*>(&it->first), sizeof(typename T::key_type));
			if(pNode)
			{
				treeParent.AddNode(pNode);
			}
			ORIGIN* pOri = ConvertPointer(&it->second);
			pNode = m_pNodeCreatorValue->MakeNewNode(pOri, sizeof(ORIGIN));
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

		for(std::vector<TCTreeNode*>::const_iterator it = pTreeMine->GetSubNodes().begin();it!=pTreeMine->GetSubNodes().end();++it)
		{
			typename T::key_type key;

			m_pNodeCreatorKey->PutNodeDataTo(&key,sizeof(typename T::key_type),sizeof(typename T::key_type), *(*it));

			++it;
			if(it==pTreeMine->GetSubNodes().end())
			{
				API_ASSERT(0);
				return false;
			}

			int nCount = 1;
			if(m_pNodeCreatorValue->IsArrayData() == true)
			{
				//LEAF : Data Size를 보고 개수 판단.
				//BRANCH : 하위 노드의 수.
				nCount = (*it)->GetArrayCount(sizeof(ORIGIN));

			}

			typename T::mapped_type value;
			ORIGIN* pOri = NewPointer(&value, nCount);
			m_pNodeCreatorValue->PutNodeDataTo((void*)pOri,sizeof(ORIGIN),sizeof(ORIGIN)*nCount , *(*it));

			bool bPointer = SetValueWithOrigin(&value, pOri);
			std::pair<typename T::iterator, bool> rtn = m_data->insert(typename T::value_type(key,value));
			if(rtn.second == false && bPointer)
			{
				DeletePointer(pOri);
			}
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

		if( IsPointer( static_cast<typename T::mapped_type *>(NULL) ) )
		{
			for(typename T::iterator it = m_data->begin(); it != m_data->end(); ++it)
			{
				//const_cast< typename T::mapped_type* >
				DeletePointer(ConvertPointer( (&(it->second)) )); 
			}
		}
		else if(m_pNodeCreatorValue->NodeCreatorType() == eOneDimensionContainerNodeCreator || m_pNodeCreatorValue->NodeCreatorType() == eTwoDimensionContainerNodeCreator)
		{
			for(typename T::iterator it = m_data->begin(); it != m_data->end(); ++it)
			{
				m_pNodeCreatorValue->ClearSubContainers(ConvertPointer( (&(it->second)) )); 
			}
		}
		m_data->clear();

		return true;
	}
};

template <typename T, class ORIGIN = typename T::mapped_type>
class TCMarshalableMultiMapContainer  : public TCMarshalable
{
private:
	bool m_bNativeContainer;
	T* m_data;
	TINodeCreator* m_pNodeCreatorKey;
	TINodeCreator* m_pNodeCreatorValue;

	TCMarshalableMultiMapContainer & operator= (const TCMarshalableMultiMapContainer & base); // using assign operator is not allowed
	TCMarshalableMultiMapContainer(const TCMarshalableMultiMapContainer & base); // using copy constructor is not allowed

public:
	TCMarshalableMultiMapContainer(T* in, bool bNativeContainer=false, TINodeCreator* pNodeCreatorKey = NULL, TINodeCreator* pNodeCreatorValue = NULL) 
	{ 
		m_data = in; 
		m_bNativeContainer = bNativeContainer;
		if(pNodeCreatorKey)
		{
			m_pNodeCreatorKey = pNodeCreatorKey;
		}
		else
		{
			m_pNodeCreatorKey = new DefaultNodeCreator;
		}

		if(pNodeCreatorValue)
		{
			m_pNodeCreatorValue = pNodeCreatorValue;
		}
		else
		{
			m_pNodeCreatorValue = new DefaultNodeCreator;
		}
	}

	virtual ~TCMarshalableMultiMapContainer() 
	{
		if(m_bNativeContainer && m_data)
		{
			t_Clear();
		}
		delete m_pNodeCreatorKey;
		m_pNodeCreatorKey = NULL;
		delete m_pNodeCreatorValue;
		m_pNodeCreatorValue = NULL;

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
		if(m_pNodeCreatorValue->IsArrayData())
		{
			if(m_pNodeCreatorValue->IsNullizedArray())
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
		API_ASSERT(m_pNodeCreatorValue);
		if(m_pNodeCreatorValue->IsArrayData())
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
	 * @return pointer
	 */
	ORIGIN* ConvertPointer(ORIGIN* data, bool* pBool = NULL) 
	{
		if(pBool != NULL)
		{
			*pBool = false;
		}	
		return data;
	}

	/**
	 * @brief Returns pointer to data
	 * @param [in] pData data to be converted
	 * @param [out] pBool true if success
	 * @return pointer
	 */
	ORIGIN* ConvertPointer(ORIGIN** data, bool* pBool = NULL) 
	{
		if(pBool != NULL)
		{
			*pBool = true;
		}
		return (*data);
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
			TCTreeNode* pNode = NULL;

			pNode = m_pNodeCreatorKey->MakeNewNode(const_cast<typename T::key_type*>(&it->first), sizeof(typename T::key_type));
			if(pNode)
			{
				treeParent.AddNode(pNode);
			}

			ORIGIN* pOri = ConvertPointer(&it->second);
			pNode = m_pNodeCreatorValue->MakeNewNode(pOri, sizeof(ORIGIN));
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

		for(std::vector<TCTreeNode*>::const_iterator it = pTreeMine->GetSubNodes().begin();it!=pTreeMine->GetSubNodes().end();++it)
		{
			typename T::key_type key;

			m_pNodeCreatorKey->PutNodeDataTo(&key,sizeof(typename T::key_type),sizeof(typename T::key_type), *(*it));

			++it;
			if(it==pTreeMine->GetSubNodes().end())
			{
				API_ASSERT(0);
				return false;
			}

			int nCount = 1;
			if(m_pNodeCreatorValue->IsArrayData() == true)
			{
				//LEAF : Data Size를 보고 개수 판단.
				//BRANCH : 하위 노드의 수.
				nCount = (*it)->GetArrayCount(sizeof(ORIGIN));

			}

			typename T::mapped_type value;
			ORIGIN* pOri = NewPointer(&value, nCount);
			m_pNodeCreatorValue->PutNodeDataTo((void*)pOri,sizeof(ORIGIN),sizeof(ORIGIN)*nCount , *(*it));

			SetValueWithOrigin(&value, pOri);
			m_data->insert(typename T::value_type(key,value));
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
		
		if( IsPointer( static_cast<typename T::mapped_type *>(NULL) ) )
		{
			for(typename T::iterator it = m_data->begin(); it != m_data->end(); ++it)
			{
				//const_cast< typename T::mapped_type* >
				DeletePointer(ConvertPointer( (&(it->second)) )); 
			}
		}
		else if(m_pNodeCreatorValue->NodeCreatorType() == eOneDimensionContainerNodeCreator || m_pNodeCreatorValue->NodeCreatorType() == eTwoDimensionContainerNodeCreator)
		{
			for(typename T::iterator it = m_data->begin(); it != m_data->end(); ++it)
			{
				m_pNodeCreatorValue->ClearSubContainers(ConvertPointer( (&(it->second)) )); 
			}
		}
		m_data->clear();

		return true;
	}
};


#endif//_MARSHALABLEMAPCONTAINER_H_

