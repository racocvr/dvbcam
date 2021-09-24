/** 
 * @file IService.h
 * @brief Application interface for managing services.
 *
 * Copyright 2013 by Samsung Electronics, Inc.,
 * 
 * This software is the confidential and proprietary information
 * of Samsung Electronics, Inc. ("Confidential Information"). You
 * shall not disclose such Confidential Information and shall use
 * it only in accordance with the terms of the license agreement
 * you entered into with Samsung.
 */

#ifndef _ISERVICE_H_
#define _ISERVICE_H_

#include <vector>

#include "MarshallingMarks.h"
#include "CriteriaHelper.h"
#include "ServiceData.h"
#include "ServiceDataType.h"
#include "ServiceNavigationDataType.h"

class IService
{
protected:
	virtual ~IService(){};

public:

	/**
	 * @brief Finds list of services that fit in given criteria.
	 * @param [in] criteria Search criteria for services.
	 * @param [out] services List of found services.	 
	 * @return Returns 1 if at least one service was found, otherwise returns 0.
	 * @return When calling method failed returns -1.
	 *
	 *	@paragraph <Example>
	 *	This example will return list of services ordered by ServiceName
	 *	(from A to Z) where ProgramNumber is equal to 5 and Minor is equal to 3. 
	 *	Each service will contain ServiceId, ServiceName, Major and Minor fields.
	 *	
	 *	@verbatim
	 *	IService* serviceMgr;
	 *	TVServiceAPI::CreateService(&serviceMgr);
	 *	TCCriteriaHelper criteria;
	 *	criteria.Fetch(SERVICE_ID);
	 *	criteria.Fetch(SERVICE_NAME);
	 *	criteria.Fetch(MAJOR);
	 *	criteria.Fetch(MINOR);
	 *	criteria.Where(PROGRAM_NUMBER, 5);
	 *	criteria.Where(MINOR, 3);
	 *	criteria.OrderBy(SERVICE_NAME);
	 *	std::list<TCServiceData* > services;
	 *	if(serviceMgr->FindServiceList(searchCriteria, services) > 0)
	 *	{
	 *		//Do something with returned services list
	 *	}
	 *	@endverbatim
	 */
	virtual int FindServiceList(_IN_ const TCCriteriaHelper& criteria, _OUT_ std::list<TCServiceData*>& services ) = 0;

	/**
	 * @brief Finds first service that fits in given criteria.
	 * @param [in] criteria Search criteria.
	 * @param [out] service First found service for given criteria.	 
	 * @param [in] onlyStored Flag which indicated if in non stored services should be included in results.
	 * @return Returns 1 if at least one service was found, otherwise returns 0.
	 * @return When calling method failed returns -1.
	 *
	 *	@paragraph <Example>
	 *	This example will return first service from sorted by Major list 
	 *	(order is always ascending) with ServiceId, ServiceName and 
	 *	OriginNetworkId where ChannelType is equal to 3 (CATV). Notice 
	 *	that it is one service only, so it is good to control what service 
	 *	is returned by OrderBy.
	 *	
	 *	@verbatim
	 *	IService* serviceMgr;
	 *	TVServiceAPI::CreateService(&serviceMgr);
	 *	TCCriteriaHelper criteria;
	 *	criteria.Fetch(SERVICE_ID);
	 *	criteria.Fetch(SERVICE_NAME);
	 *	criteria.Fetch(ORIGIN_NETWORK_ID);
	 *	criteria.Where(CHANNEL_TYPE, 3);
	 *	criteria.OrderBy(MAJOR);
	 *	TCServiceData service;
	 *	if(serviceMgr->FindService(criteria, service) > 0)
	 *	{ 
	 *		//Do something with returned service
	 *	}
	 *	@endverbatim
	 */
	virtual int FindService(_IN_ const TCCriteriaHelper& criteria, _OUT_ TCServiceData& service, _IN_ const bool onlyStored = true ) = 0;
	
	/**
	 * @brief Gets number of services that fits in given criteria.
	 * @param [in] search Search criteria.
	 * @param [out] count Number of found services.
	 * @return Returns 1 if calling method succeeded, otherwise returns -1.
	 *
	 *	@paragraph <Example>
	 *	This code will return service count that meet given criteria.
	 *	Following code will return number of services with ChannelType = 3 (CATV).
	 *	
	 *	@verbatim
	 *	IService* serviceMgr;
	 *	TVServiceAPI::GetCurrentService(&serviceMgr);
	 *	TCCriteriaHelper criteria;
	 *	criteria.Where(CHANNEL_TYPE, 3);
	 *	int count = 0;
	 *	if(serviceMgr->GetServiceCount(criteria, count) > 0)
	 *	{
	 *		//Service count was successfully obtained.
	 *	}
	 *	@endverbatim
	 */
	virtual int GetServiceCount(_IN_ const TCCriteriaHelper& criteria, _OUT_ int& count) = 0;

	/**
	 * @brief Updates specified service.
	 * @param [in] service Service which will be updated.
	 * @return Returns 1 if service was successfully updated, otherwise returns 0.
	 * @return When calling method failed returns -1.
	 * @remark ServiceId and Service profile must be specified.
	 * @remark Only fields that are present in TCServiceData will be updated
	 *	
	 *	@paragraph <Example>
	 *	Following example will change frequency for service with ID = 845524458537987.
	 *
	 *	@verbatim
	 *	IService* serviceMgr;
	 *	TVServiceAPI::CreateService(&serviceMgr);
	 *
	 *	TCServiceData service;
	 *	service.Set<TCServiceId>(SERVICE_ID, 845524458537987);
	 *  service.Set<EServiceProfile>(SERVICE_PROFILE, PROFILE_ATSC);
	 *	service.Set<int>(FREQUENCY, 700000); 
	 *	if(serviceMgr->UpdateService(service) > 0)
	 *	{
	 *		//Service was updated successfully.
	 *	}
	 *	@endverbatim
	 */
	virtual int UpdateService(_IN_ const TCServiceData& service) = 0;

	/**
	 * @brief Updates specified services.
	 * @param [in] services Services list which will be updated.
	 * @return Returns 1 if all services were successfully updated, otherwise returns 0.
	 * @return When calling method failed returns -1.
	 * @remark ServiceId and Service profile must be specified for every service.
	 *	
	 *	@paragraph <Example>
	 *	Following example will change frequency for two services.
	 *
	 *	@verbatim
	 *	IService* serviceMgr;
	 *	TVServiceAPI::CreateService(&serviceMgr);
	 *
	 *	std::list<TCServiceData*> services;
	 *
	 *	TCServiceData service1;
	 *	service1.Set<TCServiceId>(SERVICE_ID, 845524458537987);
	 *  service.Set<EServiceProfile>(SERVICE_PROFILE, PROFILE_ATSC);
	 *	service1.Set<int>(FREQUENCY, 700000); 
	 *	services.push_back(&service1);
	 *
	 *	TCServiceData service2;
	 *	service2.Set<TCServiceId>(SERVICE_ID, 815524258533215);
	 *  service.Set<EServiceProfile>(SERVICE_PROFILE, PROFILE_ATSC);
	 *	service2.Set<int>(FREQUENCY, 750000); 
	 *	services.push_back(&service2);
	 *
	 *	if(serviceMgr->UpdateServiceList(services) > 0)
	 *	{
	 *		//Services were updated successfully.
	 *	}
	 *	@endverbatim
	 */
	virtual int UpdateServiceList(_IN_ const std::list<TCServiceData*>& services) = 0;

	/**
	 * @brief Inserts new services.
	 * @remark Services inserted into database will have SERVICE_ID and CHANNEL_ID fields automatically added.
	 * @param[in] newServices List of services to insert into database.
	 * @return If all services were inserted successfully returns 1, otherwise returns 0.
	 * @return When calling method failed returns -1.
	 *	
	 *	@paragraph <Example>
	 *	Following example will add two services.
	 *
	 *	@verbatim
	 *	IService* serviceMgr;
	 *	TVServiceAPI::CreateService(&serviceMgr);
	 *
	 *	std::list<TCServiceData*> services;
	 *
	 *	TCServiceData service1;
	 *	service1.Set<EChannelType>(CHANNEL_TYPE, CHANNEL_TYPE_ATV);
	 *	service1.Set<unsigned short>(CHANNEL_NUMBER, 8);
	 *	service1.Set<EServiceProfile>(SERVICE_PROFILE, PROFILE_ATSC);
	 *	service1.Set<unsigned short>(MAJOR, 6);
	 *	service1.Set<unsigned short>(MINOR, 1);
	 *	service1.Set<unsigned short>(PROGRAM_NUMBER, 1);
	 *	services.push_back(&service1);
	 *
	 *	TCServiceData service2;
	 *	service2.Set<EChannelType>(CHANNEL_TYPE, CHANNEL_TYPE_ATV);
	 *	service2.Set<unsigned short>(CHANNEL_NUMBER, 8);
	 *	service2.Set<EServiceProfile>(SERVICE_PROFILE, PROFILE_ATSC);
	 *	service2.Set<unsigned short>(MAJOR, 6);
	 *	service2.Set<unsigned short>(MINOR, 1);
	 *	service2.Set<unsigned short>(PROGRAM_NUMBER, 2);
	 *	services.push_back(&service2);
	 *
	 *	if(serviceMgr->InsertServiceList(services) > 0)
	 *	{
	 *		//Services were added successfully.
	 *	}
	 *	@endverbatim
	 */
	virtual int InsertServiceList(_IN_ std::list<TCServiceData*>& services) = 0;

	/**
	 * @brief Gets information to what favorites belongs specified service.
	 * @remark Each favorite profile is specified by "unsigned char" value/index.
	 * @remark Index of profile can never be equal to 0.
	 * @param [in] serviceId Service id.
	 * @param [out] favorites Stores information to what favorite profiles belong service.
	 * @return Returns 1 if favorites were retrieved successfully, otherwise returns 0.
	 * @return When calling method failed returns -1.
	 *
	 *	@paragraph <Example>
	 *	This example will get information about service favorites list.
	 *	
	 *	@verbatim
	 *	IService* serviceMgr;
	 *	TVServiceAPI::CreateService(&serviceMgr);
	 *
	 *	TCServiceId serviceId = 144123984219217923;
	 *	std::map<unsigned  char, bool> favorites;
	 *	if(serviceMgr->GetFavorites(serviceId, favorites) > 0)
	 *	{
	 *		if(favorites[4] == true)
	 *		{
	 *			//service 144123984219217923 bolongs to favorite profile 4;
	 *		}
	 *	}
	 *	@endverbatim
	 */
	virtual int GetFavorites(_IN_ const TCServiceId& serviceId, _OUT_ std::map<unsigned char, bool>& favorites) = 0;

	/**
	 * @brief Adds or removes specified services to/from favorite lists.
	 * @remark Services are always added at the end of favorite list.
	 * @remark Order of adding and deleting is specified by order in the list.
	 * @remark Given favorite profile is 'unsigned char' type and can never be equal to 0.
	 * @remark If specified for add service is already present in 'fav' profile, operation is ignored and update proceed to the next service on the list.
	 * @remark If specified for delete service is not present in 'fav' profile, operation is ignored and update proceed to the next service on the list.
	 * @param [in] services Specify list of services for update. Each service can be added or removed from given 'fav' profile.
	 * @param [in] fav Favorite profile.
	 * @return Returns 1 if all services were updated successfully, otherwise returns 0.
	 * @return When calling method failed returns -1.
	 *
	 *	@paragraph <Example>
	 *	This functionality implements algorithms for adding and removing services to/from favorite list.
	 *	Bellow is presented code sample which adds services AAA and BBB to FAV_SERVICES favorite list and
	 *	removes service CCC from it.
	 *
	 *	@verbatim
	 *	enum
	 *	{
	 *		FAV_SERVICES = 63;
	 *	};
	 *	std::vector<std::pair<TCServiceId, bool> > services;
	 *	services.push_back(std::make_pair(AAA, true); //add
	 *	services.push_back(std::make_pair(BBB, true); //add
	 *	services.push_back(std::make_pair(CCC, false); //remove
	 *
	 *	IService* serviceMgr;
	 *	TVServiceAPI::CreateService(&serviceMgr);
	 *	if(serviceMgr->UpdateFavorites(favoritesList, FAV_SERVICES) > 0)
	 *	{
	 *		//service AAA and BBB are now present in FAV_SERVICES favorite list
	 *		//service CCC was removed form FAV_SERVICES favorite list
	 *	}
	 *	@endverbatim
	 */
	virtual int UpdateFavorites(_IN_ const std::vector<std::pair<TCServiceId, bool> >& services, _IN_ unsigned char fav) = 0;

	/**
	 * @brief Moves group of services to specified position on favorite list.
	 * @remark Given favorite profile is 'unsigned char' type and can never be equal to 0.
	 * @remark Position 'targetPos' is a number >=0, which specifies new position on given group of services.
	 * @remark If one of specified service is not present in the 'fav' list, operation move proceed with the rest services.
	 * @remark Order of the services in the list defines order of specified services after operation.
	 * @param [in] services List of services which will be moved.
	 * @param [in] targetPos New position for group of services.
	 * @param [in] fav Favorite profile where services will be moved.
	 * @return Returns 1 if all services were successfully moved, otherwise returns 0.
	 * @return When calling method failed returns -1.
	 *
	 *	@paragraph <Example>
	 *	This functionality implements algorithms for moving group of services to specified position.
	 *	Bellow is presented sample of code which moves services AAA and CCC to the '2' position on 'on' FAV_SERVICES favorite list.
	 *	Services order on FAV_SERVICES favorite list before operation: AAA, BBB, CCC, DDD, EEE;
	 *	Services order on FAV_SERVICES favorite list after operation : BBB, DDD, AAA, CCC, EEE;
	 *
	 *	@verbatim
 	 *	enum
	 *	{
	 *		FAV_SERVICES = 63;
	 *	};
	 *	std::vector<TCServiceId> servicesList;
	 *	servicesList.push_back(AAA);
	 *	servicesList.push_back(CCC);
	 *
	 *	IService* serviceMgr;
	 *	TVServiceAPI::CreateService(&serviceMgr);
	 *	if(serviceMgr->MoveFavorites(servicesList, 2, FAV_SERVICES) > 0)
	 *	{
	 *		//Do something.
	 *	}
	 *	@endverbatim
	 */
	virtual int MoveFavorites(_IN_ const std::vector<TCServiceId>& services, _IN_ unsigned short targetPos, _IN_ unsigned char fav) = 0;
	
	//ToDo Duende: fill the comments
	/**
	 * @brief Copy services to new Rcn.
	 * @param [in] services Map of ids of services and coresponding new Rcn.
	 * @return Returns 1 if all services were successfully copied, otherwise returns 0.
	 * @return When calling method failed returns -1.
	 **/
	virtual int CopyServiceList(  _IN_ std::map<TCServiceId, unsigned short>& services ) = 0;

	/**
	* @brief Reorder service list for given tvMode.
	* @param [in] tvMode TvMode for service list that should be reordered.
	* @return Returns 1 when reordering was successfull, otherwise returns 0.
	* @return When calling method failed returns -1.
	*
	* @paragraph <Example>
	* This example will reorder list of services for current tvMode
	*	
	* @verbatim
	* IServiceNavigation* serviceNav;
	* TVServiceAPI::CreateServiceNavigation(PROFILE_TYPE_MAIN, 0, &serviceNav);
	* TSTvMode tvMode;
	* if(serviceNav->GetTvMode(tvMode) > 0)
	* {
	*	IService* serviceMgr;
	*	TVServiceAPI::CreateService(&serviceMgr);
	*	if(serviceMgr->ReorderServiceList(tvMode))
	*	{
	*		//Reorder list successful.
	*	}
	* }	
	* @endverbatim
	*/
	virtual int ReorderServiceList(_IN_ const TSTvMode& tvMode) = 0;

	/**
	* @brief Deletes list of services that fit in given criteria.
	* @param [in] criteria Delete criteria for services.
	* @param [in] forceDelete Delete services without checking any further conditions.
	* @return Returns 1 when delete was successfull, otherwise returns 0.
	* @return When calling method failed returns -1.
	*
	* @paragraph <Example>
	* This example will remove list of services 
	* where ProgramNumber is equal to 5 and Minor is equal to 3. 
	*	
	* @verbatim
	* IService* serviceMgr;
	* TVServiceAPI::CreateService(&serviceMgr);
	* TCCriteriaHelper criteria;
	* criteria.Where(PROGRAM_NUMBER, 5);
	* criteria.Where(MINOR, 3);
	* if(serviceMgr->DeleteServiceList(searchCriteria, services) > 0)
	* {
	*	//Delete was successfull
	* }
	* @endverbatim
	*/
	virtual int DeleteServiceList( _IN_ const TCCriteriaHelper& criteria, _IN_ bool forceDelete = false ) = 0;

	/**
	* @brief (DVB-only) Find list of providers matching given criteria.
	* @remarks Complete provider objects shall be returned, so DO NOT USE FETCH.
	* @remarks MEMORY ALLOCATED FOR SERVICE PROVIDER OBJECTS IN OUTPUT LIST MUST BE DEALLOCATED BY CALLER.
	* @remarks Use EServiceDataTag to specify search conditions.
	* @param[in] criteria Search criteria for satellites. FETCH shall NOT be used.
	* @param[out] providers List of found providers.
	* @return Returns 1 when getting providers was successfull, otherwise returns 0.
	* @return When calling method failed returns -1.
	*
	* @paragraph <Example>
	* This example will return list of providers on a given satellite.
	*
	* @verbatim
	* IService* serviceMgr;
	* TVServiceAPI::CreateService(&serviceMgr);
	* TCCriteriaHelper criteria;
	* std::vector< TSServiceProvider* > provList;
	* criteria.Where( SATELLITE_ID, 1 );
	* if (serviceMgr.GetProviderList( criteria, provList ))
	* {
	*	//Do something with returned providers
	* }
	* @endverbatim
	*/
	virtual int GetProviderList( _IN_ const TCCriteriaHelper& criteria, _OUT_ std::vector< TSServiceProvider* >& providers) = 0;
	
	/**
	* @brief (DVB-only) Get current bouquets map (bouquete id and name).
	* @remark Only bouquets with navigable services will be returned.
	* @param[in] tvmode TV mode for which bouquets should be received.
	* @param[out] bouquets list of bouquests with names.
	* @return Returns 1 when receiving was successfull, otherwise returns 0.
	* @return When calling method failed returns -1.
	*
	* @paragraph <Example>
	* This example will return list of current bouquets.
	*	
	* @verbatim
	* TSTvMode tvMode( ANTENNA_MODE_SATELLITE, SERVICE_MODE_ASTRA_192E );
	* IService* serviceMgr;
	* TVServiceAPI::CreateService(&serviceMgr);
	* std::map< unsigned long long, t_wstring > bouquets;
	* if (serviceMgr->GetBouquets( tvmode, bouquets ))
	* {
	*	//Do something with returned bouquets
	* }
	* @endverbatim
	*/
	virtual int GetBouquets( _IN_ const TSTvMode& tvmode, _OUT_ std::map< unsigned long long, t_wstring >& bouquets ) = 0;

	/**
	* @brief (DVB-only) Get current bouquets count.
	* @remark Only bouquets with navigable services will be counted.
	* @param[out] count Number of current bouquets.
	* @return Returns 1 when receiving count was successfull, otherwise returns 0.
	* @return When calling method failed returns -1.
	*
	* @paragraph <Example>
	* This example will return count of current bouquets.
	*	
	* @verbatim
	* TSTvMode tvMode( ANTENNA_MODE_SATELLITE, SERVICE_MODE_ASTRA_192E );
	* IService* serviceMgr;
	* TVServiceAPI::CreateService(&serviceMgr);
	* unsigned int count = 0;
	* if (serviceMgr->GetBouquetCount( tvmode, count ))
	* {
	*	//Do something with returned bouquets count
	* }
	* @endverbatim
	*/
	virtual int GetBouquetCount( _IN_ const TSTvMode& tvmode, _OUT_ unsigned int& count ) = 0;

	/**
	* @brief (DVB-only) Get bouquete name for given bouquete id.
	* @remark If no existing bouquete id is provided then bouquete name shall be empty.
	* @param[in] bouquetId Bouquet id for which name shall be returned.
	* @param[out] bouquetName Name of the bouquet.
	* @return Returns 1 when receiving was successfull, otherwise returns 0.
	* @return When calling method failed returns -1.
	*
	* @paragraph <Example>
	* This example will return name for given bouquet id.
	*	
	* @verbatim
	* IService* serviceMgr;
	* TVServiceAPI::CreateService(&serviceMgr);
	* unsigned long long bouqueteId = 76477;
	* t_wstring bouqueteName;
	* if (serviceMgr.GetBouquetName( bouqueteId, bouqueteName ))
	* {
	*	//Do something with returned bouquet name
	* }
	* @endverbatim
	*/
	virtual int GetBouquetName( _IN_ const unsigned long long& bouquetId, _OUT_ t_wstring& bouquetName ) = 0;

	/**
	* @brief (DVB-only) Return list of bouquetes ids to which given service id belongs.
	* @param[in] serviceId Service id.
	* @param[out] bouquetsIds Vector of bouquetes ids to which given serviceId belongs.
	* @return Returns 1 when receiveing was successfull, otherwise returns 0.
	* @return When calling method failed returns -1.
	*
	* @paragraph <Example>
	* This example will return name for given bouquet id.
	*	
	* @verbatim
	* IService* serviceMgr;
	* TVServiceAPI::CreateService(&serviceMgr);
	* TCServiceId serviceId = 7647788768976;
	* std::vector< unsigned long long > bouquetsIds;
	* if (serviceMgr.GetServiceBouquets( serviceId, bouquetsIds ))
	* {
	*	//Do something with returned bouquets ids
	* }
	* @endverbatim
	*/
	virtual int GetServiceBouquets( _IN_ const TCServiceId& serviceId, _OUT_ std::vector< unsigned long long >& bouquetsIds ) = 0;

	/**
	* @brief (Hotel-only) Set bank to which given service should belong.
	* @param[in] serviceId Service id.
	* @param[in] bank Hotel bank.
	* @return Returns 1 when setting bank was successfull, otherwise returns 0.
	* @return When calling method failed returns -1.
	*
	* @paragraph <Example>
	* This example will set HOTEL_BANK_1 for given serviceId.
	*	
	* @verbatim
	* IService* serviceMgr;
	* TVServiceAPI::CreateService(&serviceMgr);
	* TCServiceId serviceId = 7647788768976;
	* if ( 1 == serviceMgr.SetBank( serviceId, HOTEL_BANK_1 ))
	* {
	*	//setting was succesfull
	* }
	* @endverbatim
	*/
	virtual int SetBank( _IN_ const TCServiceId& serviceId, _IN_ EHotelBank bank ) = 0;

	/**
	* @brief (Hotel-only) Removes service from given bank.
	* @param[in] serviceId Service id.
	* @param[in] bank Hotel bank.
	* @return Returns 1 when removing from banks was successfull, otherwise returns 0.
	* @return When calling method failed returns -1.
	*
	* @paragraph <Example>
	* This example will remove service from HOTEL_BANK_1.
	*	
	* @verbatim
	* IService* serviceMgr;
	* TVServiceAPI::CreateService(&serviceMgr);
	* TCServiceId serviceId = 7647788768976;
	* if (1 == serviceMgr.RemoveBank( serviceId, HOTEL_BANK_1 ))
	* {
	*	//removing was succesfull
	* }
	* @endverbatim
	*/
	virtual int RemoveBank( _IN_ const TCServiceId& serviceId, _IN_ EHotelBank bank ) = 0;

	/**
	* @brief (Hotel-only) Returns list of services ids and banks to which they belongs for given tvMode.
	* @param[in] tvMode Given TvMode.
	* @param[out] serviceBanksIds List of banks for service ids.
	* @return Returns 1 when receiving banks was successfull, otherwise returns 0.
	* @return When calling method failed returns -1.
	*
	* @paragraph <Example>
	* This example will get banks for services in given tvMode.
	*	
	* @verbatim
	* IService* serviceMgr;
	* TVServiceAPI::CreateService(&serviceMgr);
	* TSTvMode tvMode( ANTENNA_MODE_CABLE, SERVICE_MODE_ATSC );
	* std::map< TCServiceId, std::vector< EHotelBank > > servicesWithBanks;
	* if (1 == serviceMgr.GetBanks( tvMode, servicesWithBanks ))
	* {
	*	//obtained map 
	* }
	* @endverbatim
	*/
	virtual int GetBanks( _IN_ const TSTvMode& tvMode, _OUT_ std::map< TCServiceId, std::vector< EHotelBank > >& serviceBanksIds ) = 0;

	/**
	* @brief (Hotel-only) Set countries to given service id.
	* @param[in] serviceId Service id.
	* @param[in] countries Countries to which service belongs.
	* @return Returns 1 when setting countries was successfull, otherwise returns 0.
	* @return When calling method failed returns -1.
	*
	* @paragraph <Example>
	* This example will set countries  for given serviceID.
	*	
	* @verbatim
	* IService* serviceMgr;
	* TVServiceAPI::CreateService(&serviceMgr);
	* TCServiceId serviceId = 7647788768976;
	* std::vector<EHotelCountry> countries;
	* countries.push_back( HOTEL_COUNTRY_AUSTRIA );
	* countries.push_back( HOTEL_COUNTRY_FINLAND );
	* countries.push_back( HOTEL_COUNTRY_SWEDEN );
	* if (1 == serviceMgr.SetCountries( serviceId, countries ))
	* {
	*	//setting was succesfull
	* }
	* @endverbatim
	*/
	virtual int SetCountries( _IN_ const TCServiceId& serviceId, _IN_ const std::vector< EHotelCountry >& countries ) = 0;

	/**
	* @brief (Hotel-only) Returns list of countries to which service belongs.
	* @param[in] serviceId Service id.
	* @param[out] countries List of countries.
	* @return Returns 1 when receiving countries was successfull, otherwise returns 0.
	* @return When calling method failed returns -1.
	*
	* @paragraph <Example>
	* This example will get countries for given service.
	*	
	* @verbatim
	* IService* serviceMgr;
	* TVServiceAPI::CreateService(&serviceMgr);	
	* TCServiceId serviceId = 7647788768976;
	* std::vector< EHotelCountry > countries;
	* if (1 == serviceMgr.GetCountries( serviceId, countries ))
	* {
	*	//obtained countries 
	* }
	* @endverbatim
	*/
	virtual int GetCountries( _IN_ const TCServiceId& serviceId , _OUT_ std::vector< EHotelCountry >& countries ) = 0;

	/**
	* @brief (Hotel-only) Set genre to which given service should belong.
	* @param[in] serviceId Service id.
	* @param[in] genre Hotel genre.
	* @return Returns 1 when setting genre was successfull, otherwise returns 0.
	* @return When calling method failed returns -1.
	*
	* @paragraph <Example>
	* This example will set HOTEL_GENRE_NEWS for given serviceId.
	*	
	* @verbatim
	* IService* serviceMgr;
	* TVServiceAPI::CreateService(&serviceMgr);
	* TCServiceId serviceId = 7647788768976;
	* if ( 1 == serviceMgr.SetHotelGenre( serviceId, HOTEL_GENRE_NEWS ))
	* {
	*	//setting was succesfull
	* }
	* @endverbatim
	*/
	virtual int SetHotelGenre( _IN_ const TCServiceId& serviceId, _IN_ EHotelGenre genre ) = 0;

	/**
	* @brief (Hotel-only) Removes service from given genre.
	* @param[in] serviceId Service id.
	* @param[in] genre Hotel genre.
	* @return Returns 1 when removing from genre was successfull, otherwise returns 0.
	* @return When calling method failed returns -1.
	*
	* @paragraph <Example>
	* This example will remove service from HOTEL_GENRE_NEWS.
	*	
	* @verbatim
	* IService* serviceMgr;
	* TVServiceAPI::CreateService(&serviceMgr);
	* TCServiceId serviceId = 7647788768976;
	* if (1 == serviceMgr.RemoveHotelGenre( serviceId, HOTEL_GENRE_NEWS ))
	* {
	*	//removing was succesfull
	* }
	* @endverbatim
	*/
	virtual int RemoveHotelGenre( _IN_ const TCServiceId& serviceId, _IN_ EHotelGenre genre ) = 0;

	/**
	* @brief (Hotel-only) Returns list of services ids and genres to which they belong for given tvMode.
	* @param[in] tvMode Given TvMode.
	* @param[out] servicesWithGenres List of genres for service ids .
	* @return Returns 1 when receiving genres was successfull, otherwise returns 0.
	* @return When calling method failed returns -1.
	*
	* @paragraph <Example>
	* This example will get genres for services in given tvMode.
	*	
	* @verbatim
	* IService* serviceMgr;
	* TVServiceAPI::CreateService(&serviceMgr);
	* TSTvMode tvMode( ANTENNA_MODE_CABLE, SERVICE_MODE_ATSC );
	* std::map< TCServiceId, std::vector< EHotelGenre > > servicesWithGenres;
	* if (1 == serviceMgr.GetHotelGenres( tvMode, servicesWithGenres ))
	* {
	*	//obtained map 
	* }
	* @endverbatim
	*/
	virtual int GetHotelGenres( _IN_ const TSTvMode& tvMode, _OUT_ std::map< TCServiceId, std::vector< EHotelGenre > >& servicesWithGenres ) = 0;

	/**
	* @brief Reorders satellite services to fill any missing gaps starting from specified major.
	* @remarls DVB-only. The client is responsible for checking if reordering is allowed in requested TV mode
	* @param[in] tvmode TV mode for which services will be reordered.
	* @param[in] startMajor Index (major number) of where to start reordering, it will be assigned as the first major. Only services with MAJOR > startMajor will be updated.
	* @return Returns 1 when operation was successful, otherwise returns 0.
	* @return When calling method failed returns -1.
	*
	* @paragraph <Example>
	* This example will reorder services for General Satellite. Example majors:
	* Before reorder: 1, 2, 3, 7, 10, 15
	* After reorder: 1, 2, 3, 6, 7, 8
	*
	* @verbatim
	* IService* serviceMgr;
	* TVServiceAPI::CreateService(&serviceMgr);
	* if (serviceMgr->ReorderDigitalServices( TSTvMode(ANTENNA_MODE_SATELLITE, SERVICE_MODE_DVB), 6 ) == 1)
	* {
	*	//Operation was successful
	* }
	* @endverbatim
	*/
	virtual int ReorderDigitalServices(_IN_ const TSTvMode& tvmode, _IN_ const unsigned short startMajor ) = 0;

	/*save memory DB to file*/
	virtual int SaveMemoryDBToFile() = 0;

	/**
	 * @brief Restores a deleted service.
	 * @param[in] serviceId Service ID of the deleted service.
	 * @return Returns 1 when successfully updated the specified service, 0 otherwise.
	 * @return When calling method failed returns -1.
	 */
	virtual int RestoreService(_IN_ const TCServiceId& serviceId) = 0;

	/**
	 * @brief Restores deleted services.
	 * @param[in] serviceIds Set of Service IDs identified deleted services to be restored.
	 * @return Returns 1 when successfully updated all specified services, 0 otherwise.
	 * @return When calling method failed returns -1.
	 */
	virtual int RestoreServiceList(_IN_ const std::vector<TCServiceId>& serviceIds) = 0;

	/**
	 * @brief Fetch information regarding favorites for a given service.
	 * @remarks This method should be used to fetch favorites information to a service which will later be INSERTED to channel DB.
	 * @param[inout] serviceData Service data for which favorites information shall be fetched.
	 * @return Returns 1 on a successful favorites fetch(even if service is not on any list), returns 0 when no SERVICE_ID or SERVICE_ID is INVALID, otherwise returns -1(dbus communication error).
	 *
	 * @paragraph <Example>
	 *
	 * @verbatim
	 * IService* serviceMgr;
	 * TVServiceAPI::CreateService(&serviceMgr);
	 * // obtain serviceData using e.g. FindService etc.
	 * if (1 == serviceMgr->FetchFavorites(serviceData))
	 * {
	 * 		//Operation was successful so:
	 *		//	1) Update needed fields in serviceData -> serviceData.Set<unsigned short>(MAJOR, newMajor) etc.
	 *		//	2) Run InsertServiceList which will re-create serviceId key
	 * }
	 * @endverbatim
	 */
	virtual int FetchFavorites(_INOUT_ TCServiceData& serviceData) = 0;
};

#endif // _ISERVICE_H_
