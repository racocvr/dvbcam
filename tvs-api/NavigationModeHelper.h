/** 
* @file		NavigationModeHelper.h
* @brief	Helper class to deliver predefined TCCriteriaObject.
*
* Copyright 2014 by Samsung Electronics, Inc.,
*
* This software is the confidential and proprietary information
* of Samsung Electronics, Inc. ("Confidential Information").  You
* shall not disclose such Confidential Information and shall use
* it only in accordance with the terms of the license agreement
* you entered into with Samsung.
*/

#ifndef _NAVIGATIONMODEHELPER_H_
#define _NAVIGATIONMODEHELPER_H_

#include <list>
#include "ServiceNavigationDataType.h"
#include "CriteriaHelper.h"
#include "ServiceDataType.h"
#include "ServiceData.h"


typedef enum
{
	// Navigate through all services allowed in current system state/configuration and in current broadcast system (ATSC/DVB/...) - excluding removed services.
	// This should be default navigation mode used for channel up/down and for getting service list.
	// Use it to display 'Added Channels' service list (to display 'All Channels' service list - use NAVIGATION_MODE_FULL).
	// see: NAVIGATION_MODE_FULL
	//     Required params: none
	NAVIGATION_MODE_ALL,

	// Navigate through digital services only.
	//     Required params: none
	NAVIGATION_MODE_DIGITAL,

	// Navigate through analog services only.
	//     Required params: none
	NAVIGATION_MODE_ANALOG,

	// Navigate through favourites services.
	//     Required params: id of favourite list that should be used for navigation
	NAVIGATION_MODE_FAVORITES,

	// Navigate through services linked to specified satellite.
	// see: ESatelliteId
	//     Required params: id of satellite
	NAVIGATION_MODE_SATELLITE,

	// Navigate through services linked to specified provider.
	//     Required params: id of provider
	NAVIGATION_MODE_PROVIDER,

	// Navigate through scrambled services only.
	//     Required params: none
	NAVIGATION_MODE_SCRAMBLE,

	// Navigate through FTA (free-to-air) services only.
	//     Required params: none
	NAVIGATION_MODE_FREE,

	// Navigate through services linked to specified bouquet.
	//     Required params: id of bouquet
	NAVIGATION_MODE_BOUQUETS,

	// Navigate through services linked to specified bouquet.
	// see: Digiturk specification & EDPServiceTheme
	//     Required params: id of theme
	NAVIGATION_MODE_THEMES,

	// Navigate through services linked to specified genre.
	// see: Freesat/AirTel (India) specification & EGenreCode & EAirTelGenre
	//     Required params: id of genre
	NAVIGATION_MODE_GENRES,

	// Navigate through TV services only.
	// see: EATSCServiceType & EDVBServiceType & EISDBServiceType
	//     Required params: none
	NAVIGATION_MODE_TV,

	// Navigate through RADIO services only.
	// see: EATSCServiceType & EDVBServiceType & EISDBServiceType
	//     Required params: none
	NAVIGATION_MODE_RADIO,

	// Navigate through other (non TV and non RADIO) services only.
	// see: EATSCServiceType & EDVBServiceType & EISDBServiceType
	//     Required params: none
	NAVIGATION_MODE_OTHER,

	// Navigate through all services allowed in current system state/configuration and in current broadcast system (ATSC/DVB/...) - including removed services if applicable.
	// If required by broadcast system, removed services shall be considered too
	// (that is requirement for ATSC and ISDB; for DVB and DVBNT this mode works exactly like NAVIGATION_MODE_ALL)
	// Use it to display 'All Channels' service list (to display 'Added Channels' service list - use NAVIGATION_MODE_ALL).
	// see: NAVIGATION_MODE_ALL
	//     Required params: none
	NAVIGATION_MODE_FULL,


	//
	// TODO Duende: don't use 3D mode - to be removed
	NAVIGATION_MODE_WITHOUT_3D, 
	
	// Navigate through virtual (IP) services only.
	//     Required params: none
	NAVIGATION_MODE_VIRTUAL,

	// Navigate through services linked to specified hotel bank.
	//     Required params: bank id
	NAVIGATION_MODE_HOTEL_BANK,

	// Navigate through services linked to specified hotel genre.
	//     Required params: hotel genre id
	NAVIGATION_MODE_HOTEL_GENRE,

	// Navigate through services linked to specified hotel country.
	//     Required params: hotel country
	NAVIGATION_MODE_HOTEL_COUNTRY,
}ENavigationMode;

typedef enum
{
	SORT_BY_DEFAULT = 0,
	SORT_BY_NAME = 1,
}ENavigationSortMode; 

class TCNavigationModeHelper
{
public:

	/**
	 * @brief Get predefined navigation criteria for given navigation mode.
	 * @remarks This method should be used only for navigation-related purpose
	 *	(like getting next/previous/optimum service or service list related to one of navigation modes),
	 *	since it applies some navigation-related criteria.
	 * @see Use GetSearchCriteria if you just want to get service list related to specified tv mode.
	 * @remarks This method will NOT add fetches to criteria! They need to be set manually by caller.
	 * @param[in] naviMode Navigation mode.
	 * @param[out] criteria Navigation criteria.
	 * @param[in] sortMode Sort mode.
	 * @return True if getting navigation criteria succeeded.
	 *
	 *	@paragraph <Example>
	 *	This code will get navigation criteria when you want to navigate through TV services only.
	 *
	 *	@verbatim
	 *		TCCriteriaHelper criteria;
	 *		TCNavigationModeHelper::GetNavigationCriteria( NAVIGATION_MODE_TV, criteria );
	 *	@endverbatim
	 */
	static bool GetNavigationCriteria(
		ENavigationMode naviMode,
		TCCriteriaHelper& criteria,
		ENavigationSortMode sortMode = SORT_BY_DEFAULT );


	/**
	 * @brief Get predefined navigation criteria for given navigation mode.
	 * @remarks This method should be used only for navigation-related purpose
	 *	(like getting next/previous/optimum service or service list related to one of navigation modes),
	 *	since it applies some navigation-related criteria.
	 * @see Use GetSearchCriteria if you just want to get service list related to specified tv mode.
	 * @remarks This method will NOT add fetches to criteria! They need to be set manually by caller.
	 * @remark ID param shoud follow below rules:
	 *		NAVIGATION_MODE_FAVORITES - favorite profile
	 *		NAVIGATION_MODE_SATELLITE - satellite id
	 *		NAVIGATION_MODE_BOUQUETS - bouquet id
	 * @param[in] naviMode Navigation mode.
	 * @param[in] id Proper id for given navigation mode.
	 * @param[out] criteria Navigation criteria.
	 * @return True if getting navigation criteria succeeded.
	 *
	 *	@paragraph <Example>
	 *	This code will get navigation criteria for favorite services assigned to FAVOURITE_1 list.
	 *
	 *	@verbatim
	 *		TCCriteriaHelper criteria;
	 *		TCNavigationModeHelper::GetNavigationCriteria( NAVIGATION_MODE_FAVORITES, FAVOURITE_1, criteria );
	 *	@endverbatim
	 */
	static bool GetNavigationCriteria(
		ENavigationMode naviMode,
		unsigned long long id,
		TCCriteriaHelper& criteria);


	/**
	* @brief Get predefined CriteriaHelper for GetOptimumService.
	* @param [in] major Major of direct service.
	* @param [in] minor Minor of direct service. Set to INVALID (-1) if not present.
	* @param [in] naviMode Navigation mode. Defalut NAVIGATION_MODE_ALL.
	* @param [out] criteria Predefined criteria for GetOptimumService.
	* @return true if there are no errors
	*/
	static bool GetOptimumCriteria(
			unsigned short major,
			unsigned short minor,
			TCCriteriaHelper& criteria,
			ENavigationMode naviMode = NAVIGATION_MODE_ALL );

	/**
	 * @brief Get predefined navigation criteria for given tv mode.
	 * @remarks This is general purpose method - use it if you just want to acquire list of services related to input tv mode.
	 *		No navigation-related criteria shall be applied.
	 * @see Use GetNavigationCriteria if you want to get service list related to navigation mode.
	 * @remarks This method will NOT add fetches to criteria! They need to be set manually by caller.
	 * @param[in] tvMode Tv mode for which search criteria will be prepared.
	 * @param[out] criteria Navigation criteria.
	 * @return True if getting navigation criteria succeeded.
	 *
	 *	@paragraph <Example>
	 *	This code will get criteria that can be used to get list of all terrestrial services present in service db.
	 *
	 *	@verbatim
	 *		TCCriteriaHelper criteria;
	 *		TCNavigationModeHelper::GetSearchCriteria( TSTvMode(ANTENNA_MODE_AIR, SERVICE_MODE_DVB), criteria );
	 *	@endverbatim
	 */
	static bool GetSearchCriteria(
		const TSTvMode& tvMode,
		TCCriteriaHelper& criteria );



	// TODO Duende: remove below 3 methods - use methods from ServiceUtility instead !!!!!!!!!!!!!!!!
	static void GetChannelTypeList(
			const TSTvMode& tvMode,
			std::list< int >& channelTypeList);
	static void GetServiceProfileList(
			const TSTvMode& tvMode,
			std::list< int >& serviceProfileList);
	static void GetServiceTypeList(
			const TSTvMode& tvMode,
			EServiceType serviceType,
			std::list< int >& serviceTypeList);


	// TODO Duende: remove below 4 methods - use versions from above !!!!!!!!!!!!!!!!
	static bool GetNavigationCriteria(
			const TSTvMode tvMode,
			const ENavigationMode mode,
			TCCriteriaHelper& criteria,
			unsigned long long id = INVALID );
	static bool GetNavigationCriteria(
			const TSTvMode tvMode,
			const ENavigationMode mode,
			TCCriteriaHelper& criteria,
			std::list< unsigned long long > ids );
	static bool GetNavigationCriteria(
			const ENavigationMode mode,
			const TSTvMode tvMode,
			TCCriteriaHelper& criteria,
			unsigned long long id = INVALID );
	static bool GetNavigationCriteria(
			const ENavigationMode mode,
			const TSTvMode tvMode,
			TCCriteriaHelper& criteria,
			std::list< unsigned long long >& ids );
	// TODO Duende: don't use above 4 methods !!!!!!!!!!!!!!!!!!!

protected:

	static bool t_GetNavigationCriteria(
			ENavigationMode naviMode,
			ENavigationSortMode sortMode,
			unsigned long long id,
			TCCriteriaHelper& criteria);

	static bool t_GetNavigationCriteriaToRemove(
		const TSTvMode tvMode,
		const ENavigationMode mode,
		unsigned long long id,
		std::list< unsigned long long > ids,
		TCCriteriaHelper& criteria);
};

#endif // _NAVIGATIONMODEHELPER_H_
