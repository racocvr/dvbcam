/** 
* @file		NavigationModeHelperHotel.h
* @brief	Helper class to deliver predefined TCCriteria object for navigation modes specific for Hotel TV.
*
* Copyright 2015 by Samsung Electronics, Inc.,
*
* This software is the confidential and proprietary information
* of Samsung Electronics, Inc. ("Confidential Information").  You
* shall not disclose such Confidential Information and shall use
* it only in accordance with the terms of the license agreement
* you entered into with Samsung.
*/

#ifndef _NAVIGATIONMODEHELPERHOTEL_H_
#define _NAVIGATIONMODEHELPERHOTEL_H_

#include "NavigationModeHelper.h"

class TCNavigationModeHelperHotel : public TCNavigationModeHelper
{
public:
	/**
	 * @see Base class.
	 */
	static bool GetNavigationCriteria(
		ENavigationMode naviMode,
		TCCriteriaHelper& criteria,
		ENavigationSortMode sortMode = SORT_BY_DEFAULT );


	/**
	 * @see Base class.
	 */
	static bool GetNavigationCriteria(
		ENavigationMode naviMode,
		unsigned long long id,
		TCCriteriaHelper& criteria);

protected:

	/**
	 * @see Base class.
	 */
	static bool t_GetNavigationCriteria(
			ENavigationMode naviMode,
			ENavigationSortMode sortMode,
			unsigned long long id,
			TCCriteriaHelper& criteria);
};

#endif // _NAVIGATIONMODEHELPERHOTEL_H_
