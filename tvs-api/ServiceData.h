/** 
 * @file	ServiceData.h
 * @brief	Class declaration for managing single service data
 *
 * Copyright 2013 by Samsung Electronics, Inc.,
 * 
 * This software is the confidential and proprietary information
 * of Samsung Electronics, Inc. ("Confidential Information").  You
 * shall not disclose such Confidential Information and shall use
 * it only in accordance with the terms of the license agreement
 * you entered into with Samsung.
 */


#ifndef _SERVICEDATA_H_
#define _SERVICEDATA_H_

#include "Marshalable.h"
#include "TreeBranchMap.h" // TODO Duende - to be moved to CPP when inline functions removed
#include "TreeLeafVar.h" // TODO Duende - to be moved to CPP when inline functions removed

#include "TVServiceDataType.h"
#include "ServiceDataType.h"
#include "SOSpecDataType.h"
#include "AVControlDataType.h"
#include "ServiceDataTag.h"
#include "TreeLeafFixed.h"
#include "TVServiceAssert.h"
#include <cstdio>
#include <cstdlib> // TODO Duende - to be removed: malloc() and free(), some applications will not build without it

class TCServiceDataExtended;

class TCServiceData: public TCMarshalable
{
	friend class TCServiceDataExtended;

private:
	enum 
	{
		TAG_TREE,
		TAG_TREE_SIZE,
		TAG_TREE_DATA,
		TAG_FAVORITES,	
	};

protected:
	template<typename T>
	class TCServiceDataOperator;

public:
	TCServiceData();
	TCServiceData(const TCServiceData& other);
	~TCServiceData();
	TCServiceData& operator=(const TCServiceData& that);

	void Clear();

	virtual bool ClassToTree(TCTreeBranch& treeParent);
	virtual bool TreeToClass(TCTreeBranch& treeMine);

	/**
	* @brief Check if given tag exists in TCServiceData object.
	* @param[in] tag Service data tag.
	* @return True if given tag exists in TCServiceData object, otherwise false.
	*	@paragraph <Example>
	*	This is recomended way of handling TCServiceData objects if you do not know what was Fetch in it.
	*	
	*	@verbatim
	*	TCServiceData service;// some service acquired from DB
	*	EChannelType channelType = ( EChannelType )INVALID;
	*	if ( service.Check( CHANNEL_TYPE ) )
	*	{
	*		EChannelType channelType = service.Get< EChannelType >( CHANNEL_TYPE );
	*	}
	*	@endverbatim
	*/
	bool Check(int tag) const;

	/**
	 * @brief Get fixed-size service data.
	 * @remarks Only fixed-size service data (like channel type, major, ...) can be acquired using this method.
	 * @param [in] tag Service data tag.
	 * @return Requested service data.
	 *	@paragraph <Example>
	 *	This example will return some of fixed-size service data - channel type, channel number, major and scrambled.
	 *	
	 *	@verbatim
	 *	TCServiceData service;   // some service acquired from DB
	 *	EChannelType channelType = service.Get<EChannelType>(CHANNEL_TYPE);
	 *	unsigned short channelNumber = service.Get<unsigned short>(CHANNEL_NUMBER);
	 *	unsigned short major = service.Get<unsigned short>(MAJOR);
	 *	bool scrambled = service.Get<bool>(SCRAMBLED);
	 *	@endverbatim
	 */
	template <typename T>
	T Get(int tag) const
	{
		return TCServiceDataOperator<T>::Get(t_pServiceDataTree, tag);
	}

	/**
	 * @brief Set fixed-size service data.
	 * @remarks Only fixed-size service data should be set using this method.
	 * @param [in] tag Service data tag.
	 * @param [in] data Service data to be set.
	 *	@paragraph <Example>
	 *	This example will set some of fixed-size service data - channel type, channel number, major and scrambled.
	 *	
	 *	@verbatim
	 *	TCServiceData service;   // new service
	 *	service.Set<EChannelType>(CHANNEL_TYPE, CHANNEL_TYPE_DTV);
	 *	service.Set<unsigned short>(CHANNEL_NUMBER, 70 );
	 *	service.Set<unsigned short>(MAJOR, 5);
	 *	service.Set<bool>(SCRAMBLED, 0);
	 *	@endverbatim
	 */
	template <typename T>
	void Set(int tag, const T& data)
	{
		TCServiceDataOperator<T>::Set(t_pServiceDataTree, tag, data);
	}

	/**
	 * @brief Get service data.
	 * @remarks Only variable-size service data (like name) can be acquired using this method.
	 * @param [in] tag Service data tag.
	 * @param [out] pData Requested service data.
	 *	@paragraph <Example>
	 *	This example will return one of variable-size service data - service name.
	 *	
	 *	@verbatim
	 *	TCServiceData service;   // some service acquired from DB
	 *	t_wchar_t* pName = new t_wchar_t[service.GetLength(SERVICE_NAME)];
	 *	service.Get(SERVICE_NAME, pName);
	 *	@endverbatim
	 */
	void Get(int tag, t_wchar_t* pData) const;

	/**
	 * @brief Set variable-size service data.
	 * @remarks Only variable-size service data should be set using this method.
	 * @param [in] tag Service data tag.
	 * @param [in] len Service data length (number of t_wchar_t characters, NOT number of bytes).
	 * @param [in] pData Service data to be set.
	 *	@paragraph <Example>
	 *	This example will set one of variable-size service data - service name.
	 *	
	 *	@verbatim
	 *	TCServiceData service;   // new service
	 *	t_wchar_t* pName = new t_wchar_t[N];
	 *	// copy N t_wchar_t characters to pName
	 *	service.Set(SERVICE_NAME, N, pName);
	 *	@endverbatim
	 */
	void Set(int tag, unsigned short len, const t_wchar_t* pData);

	/**
	 * @brief Get wide-string service data.
	 * @remarks Only variable-size service data should be set using this method.
	 * @param [in] tag Service data tag.
	 * @param [out] str Requested wide-string
	 *	@paragraph <Example>
	 *	This example will return one of variable-size service data - provider name.
	 *	
	 *	@verbatim
	 *	TCServiceData service;   // some service acquired from DB
	 *	t_wstring name;
	 *	service.Get(PROVIDER_NAME, name);
	 *	//use name.c_str() to get t_wchar_t* pointer
	 *	@endverbatim
	 */
	void Get(int tag, t_wstring& str) const;

	/**
	 * @brief Set wide-string service data.
	 * @remarks Only variable-size service data should be set using this method.
	 * @param [in] tag Service data tag.
	 * @param [in] str Service wide-string to be set
	 *	@paragraph <Example>
	 *	Currently there is no case where you should use this method.
	 */
	void Set(int tag, const t_wstring& str);

	/**
	 * @brief Get length of variable-size service data.
	 * @param [in] tag Service data tag.
	 * @return Requested service data length (in characters, NOT bytes).
	 *	@paragraph <Example>
	 *	This example will return one of variable-size service data - service name.
	 *	
	 *	@verbatim
	 *	TCServiceData service;   // some service acquired from DB
	 *	t_wchar_t* pName = new t_wchar_t[service.GetLength(SERVICE_NAME)];
	 *	service.Get(SERVICE_NAME, pName);
	 *	@endverbatim
	 */
	unsigned short GetLength(int tag) const;

	/**
	 * @brief Get string from service data.
	 * @param [in] tag Service data tag.
	 * @param [out] str Requested string
	 *	@paragraph <Example>
	 *	This example will return one of variable-size service data - default authority name.
	 *	
	 *	@verbatim
	 *	TCServiceData service;   // some service acquired from DB
	 *	std::string name;
	 *	service.Get(DEFAULT_AUTHORITY, name);
	 *	@endverbatim
	 */
	void Get(int tag, std::string& str) const;

protected:
	TCTreeBranchMap* t_pServiceDataTree;
};

template<>
class TCServiceData::TCServiceDataOperator<TCServiceId>
{
public:
	static TCServiceId Get(TCTreeBranchMap* tree, int tag)
	{
		TCTreeNode* node = tree->Find(tag);
		if(node)
		{
			TCTreeLeafVar* pLeaf = static_cast<TCTreeLeafVar*>(node);
			if (pLeaf)
			{
				return *(reinterpret_cast<const TCServiceId*>(pLeaf->GetData()));
			}
		}
		else
		{
			PRINT_API_MESSAGE( "*************************** ASSERT TAG ***************************" );
			PRINT_API_MESSAGE( "******************* ASSERT: missing tag[%3d] *********************", tag );
			PRINT_API_MESSAGE( "*************************** ASSERT TAG ***************************" );
		}
		return INVALID_SERVICE_ID;
	}

	static void Set(TCTreeBranchMap* tree, int tag, const TCServiceId& data)
	{
		tree->AddLeaf(tag, sizeof(TCServiceId), &(const_cast<TCServiceId&>(data)));
	}
};

template<typename T>
class TCServiceData::TCServiceDataOperator
{
public:
	static T Get(TCTreeBranchMap* tree, int tag)
	{
		TCTreeNode* node = tree->Find(tag);
		if(node)
		{
			TCTreeLeafFixed* pLeaf = static_cast<TCTreeLeafFixed*>(node);
			if (pLeaf)
			{
				return (T)(pLeaf->GetValue());
			}
		}
		else
		{
			PRINT_API_MESSAGE( "*************************** ASSERT TAG ***************************" );
			PRINT_API_MESSAGE( "******************* ASSERT: missing tag[%3d] *********************", tag );
			PRINT_API_MESSAGE( "*************************** ASSERT TAG ***************************" );
		}
		return (T)INVALID;
	}

	static void Set(TCTreeBranchMap* tree, int tag, const T& data)
	{
		tree->AddLeaf(tag, data);
	}
};

template<>
class TCServiceData::TCServiceDataOperator<bool>
{
public:
	static bool Get(TCTreeBranchMap* tree, int tag)
	{
		TCTreeNode* node = tree->Find(tag);
		if(node)
		{
			TCTreeLeafFixed* pLeaf = static_cast<TCTreeLeafFixed*>(node);
			if (pLeaf)
			{
				return pLeaf->GetValue() != 0;
			}
		}
		else
		{
			PRINT_API_MESSAGE( "*************************** ASSERT TAG ***************************" );
			PRINT_API_MESSAGE( "******************* ASSERT: missing tag[%3d] *********************", tag );
			PRINT_API_MESSAGE( "*************************** ASSERT TAG ***************************" );
		}
		return false;
	}

	static void Set(TCTreeBranchMap* tree, int tag, const bool& data)
	{
		tree->AddLeaf(tag, data);
	}
};

#endif //_SERVICEDATA_H_
