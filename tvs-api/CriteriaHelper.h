/** 
 * @file	CriteriaHelper.h
 * @brief	Class declaration for handling criteria for database queries.
 *
 * Copyright 2013 by Samsung Electronics, Inc.,
 * 
 * This software is the confidential and proprietary information
 * of Samsung Electronics, Inc. ("Confidential Information").  You
 * shall not disclose such Confidential Information and shall use
 * it only in accordance with the terms of the license agreement
 * you entered into with Samsung.
 */

#ifndef _CRITERIAHELPER_H_
#define _CRITERIAHELPER_H_

#include <list>
#include <map>
#include <string>
#include <utility>
#include "Marshalable.h"
#include "ServiceData.h"
#include "ServiceDataTag.h"
#include "ServiceDataType.h"

class TCCriteriaHelperExtended;


class TCCriteriaHelper: public TCMarshalable
{
	friend class TCCriteriaHelperExtended;

	// TODO Duende: remove it after app starts using proper navigation mode helper methods
	friend class TCServiceNavigationProxy;
	friend class TCNavigationModeHelper;
	friend class TCServiceNavigation;

public:

	// TODO Duende: remove it after app starts using proper navigation mode helper methods
	TCCriteriaHelper(void) : m_pAuxHelper( NULL ), m_navigationMode( 0 ) {}
	~TCCriteriaHelper(void);
	TCCriteriaHelper( const TCCriteriaHelper& other );
	TCCriteriaHelper& operator=(const TCCriteriaHelper& that);
	// TODO Duende: remove above after app starts using proper navigation mode helper methods


private:
	enum 
	{
		TAG_WHERE,
		TAG_WHERE_NOT,
		TAG_WHERE_IN,
		TAG_WHERE_NOT_IN,
		TAG_SORTORDER,
		TAG_SELECTEDCOLUMNS,
		TAG_GROUPBYCOLUMNS,		
		TAG_STL_ITEM,
	};

public:
	virtual bool ClassToTree(TCTreeBranch& treeParent);
	virtual bool TreeToClass(TCTreeBranch& treeMine);

	/**
	* @brief Specify what data will be returned from database.
	* @param [in] columnName Indicator of column that will be returned.
	*/
	void Fetch(int columnName);

	/**
	* @brief Criteria for returned data. Pattern for search is "columnName = columnValue".
	* @param [in] columnName Indicator of column for specyfied search.
	* @param [in] columnValue Value of the searched column.
	*/
	void Where(int columnName, const std::string& columnValue);
	void Where(int columnName, const int columnValue);
	void Where(int columnName, const unsigned long long& columnValue);

	/**
	* @brief Criteria for returned data. Pattern for search is "columnName != columnValue".
	* @param [in] columnName Indicator of column for specyfied search.
	* @param [in] columnValue Value of the searched column.
	*/
	void WhereNot(int columnName, const int columnValue);
	void WhereNot(int columnName, const unsigned long long& columnValue);
	
	/**
	* @brief Criteria for returned data. Pattern for search is "columnName in (val1, val2, ...)".
	* @param [in] columnName Indicator of column for specyfied search.
	* @param [in] columnValue Value of the searched column.
	*/
	void WhereIn(int columnName, const std::list<int>& columnValues);
	void WhereIn(int columnName, const std::list<TCServiceId>& columnValues);

	/**
	* @brief Criteria for returned data. Pattern for search is "columnName NOT in (val1, val2, ...)".
	* @param [in] columnName Indicator of column for specified search.
	* @param [in] columnValues Values of the searched column.
	*/	
	void WhereNotIn(int columnName, const std::list<int>& columnValues);
	
	/**
	* @brief Specify order on given data. By default it is ascending.
	* @param [in] columnName Indicator of column that will be sorted ascending.
	* @param [in] sorOrder Sorting order of the given column.
	*/
	void OrderBy(int sortColumn, ESortOrder sortOrder = ASCENDING);

	/**
	* @brief Specify how data should be grouped.
	* @param [in] columnName Indicator of column for which result should be grouped.
	*/
	void GroupBy(int groupColumn);

	const std::map<int, std::string>& GetWhere() const;
	const std::map<int, std::string>& GetWhereNot() const;
	const std::map<int, std::list<std::string> >& GetWhereIn() const;
	const std::map<int, std::list<std::string> >& GetWhereNotIn() const;
	const std::list<int>& GetFetch() const;
	const std::list<std::pair<int, ESortOrder> >& GetOrderBy() const;
	const std::list<int>& GetGroupBy() const;

	/**
	* @brief Clear all where conditions for given column in: Where, WhereNot and WhereIn.
	* @param [in] columnName For which column conditions should be erased.
	*/
	void RemoveWhere( int columnName );

	/**
	* @brief Clear settings for orderBy for given column.
	* @param [in] columnName For which column ordering should be erased.
	*/
	void RemoveOrderBy( int columnName );

	/**
	* @brief Clear settings for groupBy for given column.
	* @param [in] columnName For which column grouping should be erased.
	*/
	void RemoveGroupBy( int columnName );

	/**
	* @brief Clear all where conditions for all columns : Where, WhereNot and WhereIn.
	*/
	void RemoveAllWhere(void);

	/**
	* @brief Clear settings for orderBy for all columns.
	*/
	void RemoveAllOrderBy(void);

	/**
	* @brief Clear settings for groupBy for all columns.
	*/
	void RemoveAllGroupBy(void);
 
private:
	std::list<int> m_fetch;
	std::list<std::pair<int, ESortOrder> > m_orderBy;
	std::map<int, std::string> m_where;
	std::map<int, std::string> m_whereNot;
	std::map<int, std::list<std::string> > m_whereIn;
	std::map<int, std::list<std::string> > m_whereNotIn;
	std::list<int> m_groupBy;

	// Extended functionality, not available outside TVS.
	std::list< std::map<int, std::string> > m_orWhere;

	// TODO Duende: remove it after app starts using proper navigation mode helper methods
	TCCriteriaHelper* m_pAuxHelper;

	// Navigation mode upon which criteria were established by GetNavigationCriteria related features
	// TODO Duende: ENavigationMode should be removed from NavigationModeHelper header because of circural include happen right now
	// which prevents explicit usage of type ENavigationMode helper as a type here.
	int m_navigationMode;
};

#endif // _CRITERIAHELPER_H_
