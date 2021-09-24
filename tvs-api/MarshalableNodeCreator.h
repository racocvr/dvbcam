/** 
 * @file MarshalableNodeCreator.h
 * @brief Tool class that helps to create nodes,, modify and add them to tree
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

#ifndef _MARSHALABLENODECREATOR_H_
#define  _MARSHALABLENODECREATOR_H_

#include <string>
#include "TVServiceAssert.h"

#include "IMarshalable.h"
#include "IPCDataType.h"

#include "TreeBranchMap.h"
#include "TreeBranchList.h"
#include "TreeLeafVar.h"
#include "TreeLeafFixed.h"

enum EMarshalableNodeCreatorType
{
	eUnkownNodeCreator=-1,
	eDefaultNodeCreator = 0,
	eEnumNodeCreator,
	eNullizedStringNodeCreator,
	eNullizedWStringNodeCreator,
	eSTDStringNodeCreator,
	eSTDWStringNodeCreator,
	eMarshalableNodeCreator,
	eOneDimensionContainerNodeCreator,
	eTwoDimensionContainerNodeCreator,
};

#define NO_TAG (-1)

class TINodeCreator
{
public:
	virtual ~TINodeCreator() {}

	/**
	 * @brief Returns node creator
	 * @return node creator
	 */
	virtual TINodeCreator* Fork() = 0;
	
	/**
	 * @brief Returns true if its array
	 * @return true if array
	 */
	virtual bool IsArrayData() = 0;
	
	/**
	 * @brief Returns true if string
	 * @return true if string
	 */
	virtual bool IsNullizedArray() = 0;

	/**
	 * @brief Returns type of node creator
	 * @return EMarshalableNodeCreatorType
	 */
	virtual EMarshalableNodeCreatorType NodeCreatorType() =0; 
	
	/**
	 * @brief Clears sub containers for nesting containers
	 * @param [in] value container to be cleared
	 * @return EMarshalableNodeCreatorType
	 */
	virtual void ClearSubContainers(void* value) = 0; //for nesting containers
	
	/**
	 * @brief Creates new node
	 * @param [in] value data to be put into node
	 * @param [in] length length of data
	 * @param [in] payload marshal tag of data
	 * @return tree node pointer
	 */
	virtual TCTreeNode* MakeNewNode(void* value, int length, int payload = NO_TAG, EMarshalableStorageType storageType = MARSHALABLE_STORAGE_LIST)  = 0;
	
	/**
	 * @brief Creates new node
	 * @param [in] value data to be put into node
	 * @param [in] length length of data
	 * @param [in] nTotalBufLen length of char buffer
	 * @param [inout] node node to be modified
	 * @return tree node pointer
	 */	
	virtual bool PutNodeDataTo(void* value, int length,int nTotalBufLen, const TCTreeNode& node) = 0;
};

class TCNodeCreatorProperty : public TINodeCreator
{
protected:
	enum
	{
		TAG_DEFAULT,
	};

public:
	virtual ~TCNodeCreatorProperty () {}

	/**
	 * @brief Returns true if its array
	 * @return true if array
	 */
	virtual bool IsArrayData(); 
	
	/**
	 * @brief Returns true if string
	 * @return true if string
	 */
	virtual bool IsNullizedArray(); 
	
	/**
	 * @brief Returns type of node creator
	 * @return EMarshalableNodeCreatorType
	 */
	virtual EMarshalableNodeCreatorType NodeCreatorType();
	
	/**
	 * @brief Clears sub containers for nesting containers
	 * @param [in] value container to be cleared
	 * @return EMarshalableNodeCreatorType
	 */
	virtual void ClearSubContainers(void* value);
	
protected:
	int m_putTag;
	bool m_bArrayData;
	bool m_bNullizedArray;
	EMarshalableNodeCreatorType m_eNodeCreatorType;
};

class TCMarshalableNodeCreator :public TCNodeCreatorProperty
{
public:
	TCMarshalableNodeCreator(); 
	~TCMarshalableNodeCreator() {};

	/**
	 * @brief Returns node creator
	 * @return node creator
	 */
	TINodeCreator* Fork(); 
	
	/**
	 * @brief Creates new node
	 * @param [in] value data to be put into node
	 * @param [in] length length of data
	 * @param [in] payload marshal tag of data
	 * @return tree node pointer
	 */
	TCTreeNode* MakeNewNode(void* value, int length, int payload = NO_TAG, EMarshalableStorageType storageType = MARSHALABLE_STORAGE_LIST); 
	
	/**
	 * @brief Creates new node
	 * @param [in] value data to be put into node
	 * @param [in] length length of data
	 * @param [in] nTotalBufLen length of char buffer
	 * @param [inout] node node to be modified
	 * @return tree node pointer
	 */	
	bool PutNodeDataTo(void* value, int length, int nTotalBufLen, const TCTreeNode& node);

};

class STDStringNodeCreator : public TCNodeCreatorProperty
{
public:
	STDStringNodeCreator ();
	~STDStringNodeCreator() {};

	/**
	 * @brief Returns node creator
	 * @return node creator
	 */
	TINodeCreator* Fork(); 
	
	/**
	 * @brief Creates new node
	 * @param [in] value data to be put into node
	 * @param [in] length length
	 * @param [in] payload marshal tag of data
	 * @return tree node pointer
	 */
	TCTreeNode* MakeNewNode(void* value, int length, int payload = NO_TAG, EMarshalableStorageType storageType = MARSHALABLE_STORAGE_LIST); 
	
	/**
	 * @brief Creates new node
	 * @param [in] value data to be put into node
	 * @param [in] lenOriginalClass length of class object
	 * @param [in] nTotalBufLen length of char buffer
	 * @param [inout] node node to be modified
	 * @return tree node pointer
	 */	
	bool PutNodeDataTo(void* value, int length, int nTotalBufLen, const TCTreeNode& node);

};

class STDWStringNodeCreator : public TCNodeCreatorProperty
{
public:
	STDWStringNodeCreator ();
	~STDWStringNodeCreator() {};

	/**
	 * @brief Returns node creator
	 * @return node creator
	 */
	TINodeCreator* Fork(); 
	
	/**
	 * @brief Creates new node
	 * @param [in] value data to be put into node
	 * @param [in] length length
	 * @param [in] payload marshal tag of data
	 * @return tree node pointer
	 */
	TCTreeNode* MakeNewNode(void* value, int length, int payload = NO_TAG, EMarshalableStorageType storageType = MARSHALABLE_STORAGE_LIST); 
	
	/**
	 * @brief Creates new node
	 * @param [in] value data to be put into node
	 * @param [in] lenOriginalClass length of class object
	 * @param [in] nTotalBufLen length of char buffer
	 * @param [inout] node node to be modified
	 * @return tree node pointer
	 */	
	bool PutNodeDataTo(void* value, int length, int nTotalBufLen, const TCTreeNode& node);

};

class NullizedStringNodeCreator : public TCNodeCreatorProperty
{
public:
	NullizedStringNodeCreator ();
	~NullizedStringNodeCreator() {};

	/**
	 * @brief Returns node creator
	 * @return node creator
	 */
	TINodeCreator* Fork();
	
	/**
	 * @brief Creates new node
	 * @param [in] value data to be put into node
	 * @param [in] length length of data
	 * @param [in] payload marshal tag of data
	 * @return tree node pointer
	 */
	TCTreeNode* MakeNewNode(void* value, int length, int payload = NO_TAG, EMarshalableStorageType storageType = MARSHALABLE_STORAGE_LIST); 
	
	/**
	 * @brief Creates new node
	 * @param [in] value data to be put into node
	 * @param [in] length length of data
	 * @param [in] nTotalBufLen length of char buffer
	 * @param [inout] node node to be modified
	 * @return tree node pointer
	 */	
	bool PutNodeDataTo(void* value, int length, int nTotalBufLen, const TCTreeNode& node);

};

class NullizedWStringNodeCreator : public TCNodeCreatorProperty
{
public:
	NullizedWStringNodeCreator ();
	~NullizedWStringNodeCreator() {};

	/**
	 * @brief Returns node creator
	 * @return node creator
	 */
	TINodeCreator* Fork(); 
	
	/**
	 * @brief Creates new node
	 * @param [in] value data to be put into node
	 * @param [in] length length of data
	 * @param [in] payload marshal tag of data
	 * @return tree node pointer
	 */
	TCTreeNode* MakeNewNode(void* value, int length, int payload = NO_TAG, EMarshalableStorageType storageType = MARSHALABLE_STORAGE_LIST); 
	
	/**
	 * @brief Creates new node
	 * @param [in] value data to be put into node
	 * @param [in] length length of data
	 * @param [in] nTotalBufLen length of char buffer
	 * @param [inout] node node to be modified
	 * @return tree node pointer
	 */	
	bool PutNodeDataTo(void* value, int length, int nTotalBufLen, const TCTreeNode& node);

};

class TCEnumNodeCreator : public TCNodeCreatorProperty
{
public:
	TCEnumNodeCreator(std::string enumtype, bool bUsedefault = false, int defaultEnumValue = 0); 
	~TCEnumNodeCreator() {};

	/**
	 * @brief Returns node creator
	 * @return node creator
	 */
	TINodeCreator* Fork(); 
	
	/**
	 * @brief Creates new node
	 * @param [in] value data to be put into node
	 * @param [in] length length of data
	 * @param [in] payload marshal tag of data
	 * @return tree node pointer
	 */
	TCTreeNode* MakeNewNode(void* value, int length, int payload = NO_TAG, EMarshalableStorageType storageType = MARSHALABLE_STORAGE_LIST); 
	
	/**
	 * @brief Creates new node
	 * @param [in] value data to be put into node
	 * @param [in] length length of data
	 * @param [in] nTotalBufLen length of char buffer
	 * @param [inout] node node to be modified
	 * @return tree node pointer
	 */	
	bool PutNodeDataTo(void* value, int length, int nTotalBufLen, const TCTreeNode& node);

protected:
	std::string m_strEnumType;
	bool m_bUsedefault;
	int	m_defaultEnumValue;
};


class DefaultNodeCreator : public TCNodeCreatorProperty
{
public:
	DefaultNodeCreator(); 
	~DefaultNodeCreator() {};

	/**
	 * @brief Returns node creator
	 * @return node creator
	 */
	TINodeCreator* Fork(); 
	
	/**
	 * @brief Creates new node
	 * @param [in] value data to be put into node
	 * @param [in] length length of data
	 * @param [in] payload marshal tag of data
	 * @return tree node pointer
	 */
	TCTreeNode* MakeNewNode(void* value, int length, int payload = NO_TAG, EMarshalableStorageType storageType = MARSHALABLE_STORAGE_LIST); 
	
	/**
	 * @brief Creates new node
	 * @param [in] value data to be put into node
	 * @param [in] length length of data
	 * @param [in] nTotalBufLen length of char buffer
	 * @param [inout] node node to be modified
	 * @return tree node pointer
	 */	
	bool PutNodeDataTo(void* value, int length, int nTotalBufLen, const TCTreeNode& node);
};

template < typename ContainT, typename T >
class TCOneDimensionContainerNodeCreator: public TCNodeCreatorProperty
{
private:
	TCOneDimensionContainerNodeCreator & operator= (const TCOneDimensionContainerNodeCreator & base) { return *this; }; // using assign operator is not allowed
	TCOneDimensionContainerNodeCreator(const TCOneDimensionContainerNodeCreator & base){}; // using copy constructor is not allowed
	
public:
	TCOneDimensionContainerNodeCreator(int tag = TAG_DEFAULT, bool bNative=false, TINodeCreator* pFirstNodeCreator = NULL) 
	{
		m_putTag = tag;
		m_bNative = bNative;
		m_bArrayData = false;
		m_bNullizedArray = false;
		m_eNodeCreatorType = eOneDimensionContainerNodeCreator;

		if(pFirstNodeCreator)
		{
			m_pFirstNodeCreator = pFirstNodeCreator;
		}
		else
		{
			m_pFirstNodeCreator= new DefaultNodeCreator;
		}
	};

	~TCOneDimensionContainerNodeCreator() 
	{
		delete m_pFirstNodeCreator;
		m_pFirstNodeCreator = NULL;
	};

	/**
	 * @brief Returns node creator
	 * @return node creator
	 */
	TINodeCreator* Fork() 
	{
		return new TCOneDimensionContainerNodeCreator(m_putTag, m_bNative, m_pFirstNodeCreator->Fork());
	}

	/**
	 * @brief Clears sub containers for nesting containers
	 * @param [in] value container to be cleared
	 * @return EMarshalableNodeCreatorType
	 */
	void ClearSubContainers(void* value)
	{
		if(m_bNative == false)
		{ 
			return;
		}

		// Clear Sub Continer elements
		T* pT = (T*)(value);
		ContainT oneContainer(pT, m_bNative, m_pFirstNodeCreator->Fork());
	}


	/**
	 * @brief Creates new node
	 * @param [in] value data to be put into node
	 * @param [in] length length of data
	 * @param [in] payload marshal tag of data
	 * @return tree node pointer
	 */
	TCTreeNode* MakeNewNode(void* value, int length, int payload = NO_TAG, EMarshalableStorageType storageType = MARSHALABLE_STORAGE_LIST) 
	{
		if(value == NULL)
		{
			int tag = (payload ==-1)?m_putTag:payload;
			return new TCTreeBranchList(tag);
		}
		T* pT = ( T*)(value);
		// bNative is false because in this function, don't allocate element pointers
		ContainT oneContainer(pT, false, m_pFirstNodeCreator->Fork());

		TIMarshalable* pMarshalable = static_cast<TIMarshalable*>(&oneContainer);
	
		int tag = (payload ==-1)?m_putTag:payload;
		TCTreeBranch* pBranch = new TCTreeBranchList(tag);
		pMarshalable->ClassToTree(*pBranch);
		return pBranch;

	}   

	/**
	 * @brief Creates new node
	 * @param [in] value data to be put into node
	 * @param [in] length length of data
	 * @param [in] nTotalBufLen length of char buffer
	 * @param [inout] node node to be modified
	 * @return tree node pointer
	 */
	bool PutNodeDataTo(void* value, int length, int nTotalBufLen, const TCTreeNode& node)
	{
		if(value == NULL)
		{
			return true;
		}

		API_ASSERT(node.GetNodeType() == TREE_NODE_BRANCH_MAP|| node.GetNodeType() == TREE_NODE_BRANCH_LIST);
		// this class don't use lenOriginalClass and nTotalBufLen

		T* pT = (T*)(value);
		ContainT oneContainer(pT, false, m_pFirstNodeCreator->Fork());

		TIMarshalable* pMarshalable = static_cast<TIMarshalable*>(&oneContainer);
		TCTreeBranch* pBr = reinterpret_cast<TCTreeBranch*>(const_cast<TCTreeNode*>(&node));
		return pMarshalable->TreeToClass(*pBr);

	}

protected:
	bool m_bNative;
	TINodeCreator* m_pFirstNodeCreator;
};


template < typename ContainT, typename T >
class TCTwoDimensionContainerNodeCreator: public TCNodeCreatorProperty
{
private:
	TCTwoDimensionContainerNodeCreator & operator= (const TCTwoDimensionContainerNodeCreator & base) { return *this; }; // using assign operator is not allowed
	TCTwoDimensionContainerNodeCreator(const TCTwoDimensionContainerNodeCreator & base){}; // using copy constructor is not allowed
	
public:
	TCTwoDimensionContainerNodeCreator(int tag = TAG_DEFAULT, bool bNative=false, TINodeCreator* pKeyNodeCreator = NULL, TINodeCreator* pValueNodeCreator = NULL) 
	{
		m_putTag = tag;
		m_bNative = bNative;
		m_bArrayData = false;
		m_bNullizedArray = false;
		m_eNodeCreatorType = eTwoDimensionContainerNodeCreator;

		if(pKeyNodeCreator)
		{
			m_pKeyNodeCreator = pKeyNodeCreator;
		}
		else
		{
			m_pKeyNodeCreator = new DefaultNodeCreator;
		}

		if(pValueNodeCreator)
		{
			m_pValueNodeCreator = pValueNodeCreator;
		}
		else
		{
			m_pValueNodeCreator = new DefaultNodeCreator;
		}
	};

	~TCTwoDimensionContainerNodeCreator() 
	{
		delete m_pKeyNodeCreator;
		delete m_pValueNodeCreator;
		m_pKeyNodeCreator = NULL;
		m_pValueNodeCreator = NULL;
	};

	/**
	 * @brief Returns node creator
	 * @return node creator
	 */
	TINodeCreator* Fork() 
	{
		return new TCTwoDimensionContainerNodeCreator(m_putTag, m_bNative, m_pKeyNodeCreator->Fork(), m_pValueNodeCreator->Fork());
	}

	/**
	 * @brief Clears sub containers for nesting containers
	 * @param [in] value container to be cleared
	 * @return EMarshalableNodeCreatorType
	 */
	void ClearSubContainers(void* value)
	{
		if(m_bNative == false)
		{ 
			return;
		}

		// Clear Sub Continer elements
		T* pT = (T*)(value);
		ContainT subContainer(pT, m_bNative, m_pKeyNodeCreator->Fork(), m_pValueNodeCreator->Fork());
	}


	/**
	 * @brief Creates new node
	 * @param [in] value data to be put into node
	 * @param [in] length length of data
	 * @param [in] payload marshal tag of data
	 * @return tree node pointer
	 */
	TCTreeNode* MakeNewNode(void* value, int length, int payload = NO_TAG, EMarshalableStorageType storageType = MARSHALABLE_STORAGE_LIST) 
	{
		if(value == NULL)
		{
			int tag = (payload ==-1)?m_putTag:payload;
			return new TCTreeBranchList(tag);
		}
		T* pT = (T*)(value);
		// bNative is false because in this function, don't allocate element pointers
		ContainT subContainer(pT, false, m_pKeyNodeCreator->Fork(), m_pValueNodeCreator->Fork());

		TIMarshalable* pMarshalable = static_cast<TIMarshalable*>(&subContainer);
	
		int tag = (payload ==-1)?m_putTag:payload;
		TCTreeBranch* pBranch = new TCTreeBranchList(tag);
		pMarshalable->ClassToTree(*pBranch);
		return pBranch;

	}   

	/**
	 * @brief Creates new node
	 * @param [in] value data to be put into node
	 * @param [in] length length of data
	 * @param [in] nTotalBufLen length of char buffer
	 * @param [inout] node node to be modified
	 * @return tree node pointer
	 */
	bool PutNodeDataTo(void* value, int length, int nTotalBufLen, const TCTreeNode& node)
	{
		if(value == NULL)
		{
			return true;
		}

		API_ASSERT(node.GetNodeType() == TREE_NODE_BRANCH_MAP|| node.GetNodeType() == TREE_NODE_BRANCH_LIST);
		// this class don't use lenOriginalClass and nTotalBufLen

		T* pT = (T*)(value);
		ContainT subContainer(pT, false, m_pKeyNodeCreator->Fork(), m_pValueNodeCreator->Fork());

		TIMarshalable* pMarshalable = static_cast<TIMarshalable*>(&subContainer);
		TCTreeBranch* pBr = reinterpret_cast<TCTreeBranch*>(const_cast<TCTreeNode*>(&node));
		return pMarshalable->TreeToClass(*pBr);

	}

protected:
	bool m_bNative;
	TINodeCreator* m_pKeyNodeCreator;
	TINodeCreator* m_pValueNodeCreator;
};


#endif//_MARSHALABLENODECREATOR_H_
