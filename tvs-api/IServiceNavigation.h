/** 
 * @file IServiceNavigation.h
 * @brief Application interface for service navigation
 *
 * Copyright 2013 by Samsung Electronics, Inc.,
 * 
 * This software is the confidential and proprietary information
 * of Samsung Electronics, Inc. ("Confidential Information"). You
 * shall not disclose such Confidential Information and shall use
 * it only in accordance with the terms of the license agreement
 * you entered into with Samsung.
 */


#ifndef _ISERVICENAVIGATION_H_
#define _ISERVICENAVIGATION_H_

#include "MarshallingMarks.h"
#include "ServiceNavigationDataType.h"
#include "SatelliteSettingsDataType.h"
#include "SourceControlDataType.h"
#include "ServiceData.h"
#include "ServiceDataType.h"
#include "CriteriaHelper.h"
#include "ISignalSubscriber.h"

#include <string>
#include <vector>

class IServiceNavigation
{
protected:
	virtual ~IServiceNavigation(){};

public:

	/**
	 * @brief Sets service to selected one.
	 * @remark If case when cacheOnly == true new current service Id won't be stored in DB,
	 * @remark so after boot-up TV will tune to previously saved current service.
	 * @param [in] serviceId Selected service ID.
	 * @param [in] changeDirection Change direction used for animation for changing channel.
	 * @param [in] cacheOnly Specify if new current service Id should be stored only in cache.
	 * @param [in] appID application ID that calls this API
	 * @return Returns 1 if TV successfully tuned to specified service, otherwise returns 0.
	 * @return When calling method failed returns -1.
	 *
	 *	@paragraph <Example>
	 *	This code will set service to selected one for MAIN profile type and screenId = 0.
	 *	
	 *	@verbatim
	 *	IServiceNavigation* serviceNav;
	 *	TVServiceAPI::CreateServiceNavigation(PROFILE_TYPE_MAIN, 0, &serviceNav);
	 *	TCServiceId serviceId = 845524458537987;
	 *	if(serviceNav->SetService(serviceId) > 0)
	 *	{
	 *		//Service was succesfuly set
	 *	}
	 *	@endverbatim
	 */
	virtual int SetService(_IN_ TCServiceId& serviceId, _IN_ EServiceChangeDirection changeDirection = SERVICE_CHANGE_DIRECTION_NONE,
			_IN_ bool cacheOnly = false, _IN_ const std::string& appID = std::string()) = 0;

	/**
	 * @brief Gets quiet service info.
	 * @param [in] fetchCriteria Specifies which data will be present in service.
	 * @param [out] service Obtained service.
	 * @return Returns 1 if service info was succesfully obtained, otherwise returns 0.
	 * @return When calling method failed returns -1.
	 *
	 *	@paragraph <Example>
	 *	This code will get quiet service info containing data: SERVICE_ID & MAJOR. 
	 *	It will be performed for MAIN profile type, screenId = 0.
	 *	
	 *	@verbatim
	 *	IServiceNavigation* pServiceNav;
	 *	TVServiceAPI::CreateServiceNavigation(PROFILE_TYPE_MAIN, 0, &pServiceNav);
	 *	TCCriteriaHelper fetchCriteria;
	 *	fetchCriteria.Fetch(SERVICE_ID);
	 *	fetchCriteria.Fetch(MAJOR);
	 *	TCServiceData service;
	 *	if(pServiceNav->GetQuietServiceInfo(fetchCriteria, service) > 0)
	 *	{
	 *		//Quiet service was obatined successfully
	 *	}
	 *	@endverbatim
	 */
	virtual int GetQuietServiceInfo(_IN_ const TCCriteriaHelper& fetchCriteria, _OUT_ TCServiceData& service ) = 0;

	/**
	 * @brief Sets quiet service.
	 * @remark This method will initialize tuning to new service.
	 * @param [in] serviceId Selected service ID.
	 * @return Returns 1 if TV successfully tuned to specified service, otherwise returns 0.
	 * @return When calling method failed returns -1.
	 *
	 *	@paragraph <Example>
	 *	This code will set service to quiet service for MAIN profile type and screenId = 0.
	 *	
	 *	@verbatim
	 *	IServiceNavigation* serviceNav;
	 *	TVServiceAPI::CreateServiceNavigation(PROFILE_TYPE_MAIN, 0, &serviceNav);
	 *	TCServiceId serviceId = 845524458537987;
	 *	if(serviceNav->SetQuietService(serviceId) > 0)
	 *	{
	 *		//Quiet service was succesfuly set
	 *	}
	 *	@endverbatim
	 */
	virtual int SetQuietService(_IN_ const TCServiceId& serviceId) = 0;

	/**
	 * @brief Perform quietly non-destructive service replacement.
	 * @param [in] serviceId Selected service ID.
	 * @return Returns 1 if successfully done  quietly non-destructive replacement, otherwise returns 0.
	 * @return When calling method failed returns -1.
	 *
	 * @paragraph <Example>
	 * This code will perform quietly non-destructive replacement for service with ID 845524458537987 for MAIN profile type and screenId = 0.
	 * 
	 * @verbatim
	 * IServiceNavigation* serviceNav;
	 * TVServiceAPI::CreateServiceNavigation(PROFILE_TYPE_MAIN, 0, &serviceNav);
	 * TCServiceId serviceId = 845524458537987;
	 * if(serviceNav->SetQuietServiceNonDestructive(serviceId) > 0)
	 * {
	 *  //Do something when operation successful
	 * }
	 * @endverbatim
	 */
	virtual int SetQuietServiceNonDestructive(_IN_ const TCServiceId& serviceId) = 0;


	/**
	 * @brief Only tune to given parameters.
	 * @remarks Sections monitoring IS NOT started.
	 * @remark Use this API to check signal quality and SNR.
	 * @see See also TuneForFeedingSI
	 * @param [in] tuneParams Tuning parameters - set only parameters mandatory for required antenna mode:
	 *    for satellite:
	 *        always set (satelliteId), additionally set either (transponder id) or (frequency, polarisation, symbol rate)
	 *    for cable:
	 *        set (frequency, modulation, symbol rate)
	 *    for air:
	 *        set (frequency, bandwidth, modulation)
	 * @param [in] appID application ID that calls this API
	 * @return Returns 1 if TV successfully tuned to specified parameters, otherwise returns 0.
	 * @return When calling method failed returns -1.
	 *
	 *	@paragraph <Example>
	 *	This code will perform satellite tuning for MAIN profile type and screenId = 0.
	 *	
	 *	@verbatim
	 *	IServiceNavigation* serviceNav;
	 *	TVServiceAPI::CreateServiceNavigation(PROFILE_TYPE_MAIN, 0, &serviceNav);
	 *	TSScanChannel param;
	 *    param.data.satelliteId = SATID_ASTRA_19_2E;
	 *	param.data.frequency = 12603000;
	 *	param.data.symbolRate = 22000;
	 *	param.data.polarisation = DVBS_POL_VR;
	 *	if(serviceNav->TuneAlone(param) > 0)
	 *	{
	 *		//tuning was successful
	 *	}
	 *	@endverbatim
	 */
	virtual int TuneAlone(_IN_ const TSScanChannel& tuneParams, _IN_ const std::string& appID = std::string()) = 0;

	/**
	 * @brief Tune to given parameters to get section information.
	 * @remarks Sections monitoring is started by this method.
	 * @remark Use this API to check signal quality, SNR and network name.
	 * @see See also TuneAlone
	 * @param [in] tuneParams Tuning parameters - set only parameters mandatory for required antenna mode:
	 *	  for satellite:
	 *		  always set (satelliteId), additionally set either (transponder id) or (frequency, polarisation, symbol rate)
	 *	  for cable:
	 *		  set (frequency, modulation, symbol rate)
	 *	  for air:
	 *		  set (frequency, bandwidth, modulation)
	 * @param [in] appID application ID that calls this API
	 * @return Returns 1 if TV successfully tuned to specified parameters, otherwise returns 0.
	 * @return When calling method failed returns -1.
	 *
	 *	@paragraph <Example>
	 *	This code will perform cable tuning for MAIN profile type and screenId = 0.
	 *	
	 *	@verbatim
	 *	IServiceNavigation* serviceNav;
	 *	TVServiceAPI::CreateServiceNavigation(PROFILE_TYPE_MAIN, 0, &serviceNav);
	 *	TSScanChannel param;
	 *	param.data.frequency = 544000;
	 *	param.data.symbolRate = 6900;
	 *	param.data.modulation = MODULATION_TYPE_QAM256;
	 *	if(serviceNav->TuneAlone(param) > 0)
	 *	{
	 *		//tuning was successful
	 *	}
	 *	@endverbatim
	 */
	virtual int TuneForFeedingSI(_IN_ const TSScanChannel& tuneParams, _IN_ const std::string& appID = std::string()) = 0;

	/**
	 * @brief Gets current TV mode.
	 * @param [in] tvMode Current TV mode.
	 * @return Returns 1 if TV mode was successfully obtained, otherwise returns 0.
	 * @return When calling method failed returns -1.
	 *
	 *	@paragraph <Example>
	 *	This code will get current TvMode.
	 *	
	 *	@verbatim
	 *	IServiceNavigation* serviceNav;
	 *	TVServiceAPI::CreateServiceNavigation(PROFILE_TYPE_MAIN, 0, &serviceNav);
	 *	TSTvMode tvMode;
	 *	if(serviceNav->GetTvMode(tvMode) > 0)
	 *	{
	 *		//TV mode received successfully
	 *	}
	 *	@endverbatim
	 */
	virtual int GetTvMode(_OUT_ TSTvMode& tvMode) = 0;

	/**
	 * @brief Gets all available tvModes.
	 * @param [in] tvModes List of allowed modes.
	 * @return Returns 1 if list was successfully obtained, otherwise returns 0.
	 * @return When calling method failed returns -1.
	 *
	 *	@paragraph <Example>
	 *	This code will get all available TV modes.
	 *	
	 *	@verbatim
	 *	IServiceNavigation* serviceNav;
	 *	TVServiceAPI::CreateServiceNavigation(DEFAULT_PROFILE_TYPE, DEFAULT_SCREEN_ID, &serviceNav);
	 *	std::vector<TSTvMode> tvModes;
	 *	if(serviceNav->GetAvailableTvModes( tvModes ) > 0)
	 *	{
	 *		//TV modes received successfully
	 *	}
	 *	@endverbatim
	 */
	virtual int GetAvailableTvModes(_OUT_ std::vector<TSTvMode>& tvModes) = 0;

	/**
	 * @brief Sets TV mode permamently and tunes to service.
	 * @remarks Use this method if there are no specific operator profiles within given tv mode (e.g when you want to set general terrestrial profile, as in example below),
	 *	otherwise use the other SetTvMode method.
	 * @remarks This sets new SOSpec for the pipeline
	 * @param [in] tvMode Requested TV mode.
	 * @param [in] appID application ID that calls this API
	 * @return Returns 1 if TV mode was successfully set, otherwise returns 0.
	 * @return When calling method failed returns -1.
	 *
	 *	@paragraph <Example>
	 *	This code will set current TvMode.
	 *	
	 *	@verbatim
	 *	IServiceNavigation* serviceNav;
	 *	TVServiceAPI::CreateServiceNavigation(PROFILE_TYPE_MAIN, 0, &serviceNav);
	 *	if(serviceNav->SetTvMode(TSTvMode(ANTENNA_MODE_AIR)) > 0)
	 *	{
	 *		//TV mode was set successfully
	 *	}
	 *	@endverbatim
	 */
	virtual int SetTvMode(_IN_ TSTvMode tvMode, _IN_ const std::string& appID = std::string()) = 0;

	/**
	 * @brief Sets TV mode but does not tune to service.
	 * @param [in] tvMode Requested TV mode.
	 * @param [in] cacheOnly Determines if TV mode should be set permamently or only in cache.
	 * @return Returns 1 if TV mode was successfully set, otherwise returns 0.
	 * @return When calling method failed returns -1.
	 *
	 *	@paragraph <Example>
	 *	This code will set TvMode permamently.
	 *	
	 *	@verbatim
	 *	IServiceNavigation* serviceNav;
	 *	TVServiceAPI::CreateServiceNavigation(PROFILE_TYPE_MAIN, 0, &serviceNav);
	 *	if(serviceNav->SetTvModeInfo(TSTvMode(ANTENNA_MODE_AIR)) > 0)
	 *	{
	 *		//TV mode was set successfully
	 *	}
	 *	@endverbatim
	 */
	virtual int SetTvModeInfo(_IN_ TSTvMode tvMode, _IN_ bool cacheOnly = false) = 0;

	/**
	 * @brief Resets current TV mode to initial value.
	 * @return Returns 1 if TV mode was successfully reset, otherwise returns 0.
	 * @return When calling method failed returns -1.
	 *
	 *	@paragraph <Example>
	 *	This code will reset TvMode.
	 *	It will be done for MAIN profile type and screenId = 0.
	 *	
	 *	@verbatim
	 *	IServiceNavigation* serviceNav;
	 *	TVServiceAPI::CreateServiceNavigation(PROFILE_TYPE_MAIN, 0, &serviceNav);
	 *	if(serviceNav->ResetCurrentTvModeInfo() > 0)
	 *	{
	 *		//TV mode was successfully reset.
	 *	}
	 *	@endverbatim
	 */
	virtual int ResetCurrentTvModeInfo(void) = 0;

	/**
	 * @brief Resets current service to initial value.
	 * @return Returns 1 if current service was successfully reset, otherwise returns 0.
	 * @return When calling method failed returns -1.
	 *
	 *	@paragraph <Example>
	 *	This code will reset current service.
	 *	It will be done for MAIN profile type and screenId = 0.
	 *	
	 *	@verbatim
	 *	IServiceNavigation* serviceNav;
	 *	TVServiceAPI::CreateServiceNavigation(PROFILE_TYPE_MAIN, 0, &serviceNav);
	 *	if(serviceNav->ResetCurrentServiceInfo() > 0)
	 *	{
	 *		//Current service was successfully reset.
	 *	}
	 *	@endverbatim
	 */
	virtual int ResetCurrentServiceInfo(void) = 0;

	/**
	 * @brief Resets previous service.
	 * @return Returns 1 if previous service was successfully reset, otherwise returns 0.
	 * @return When calling method failed returns -1.
	 *
	 *	@paragraph <Example>
	 *	This code will reset previous service.
	 *	It will be done for MAIN profile type and screenId = 0.
	 *	
	 *	@verbatim
	 *	IServiceNavigation* serviceNav;
	 *	TVServiceAPI::CreateServiceNavigation(PROFILE_TYPE_MAIN, 0, &serviceNav);
	 *	if(serviceNav->ResetPreviousServiceInfo() > 0)
	 *	{
	 *		//Previous service was successfully reset.
	 *	}
	 *	@endverbatim
	 */
	virtual int ResetPreviousServiceInfo(void) = 0;

	/**
	 * @brief Resets current and previous service for the specified TV mode.
	 * @param [in] tvMode Requested TV mode.
	 * @return Returns 1 if previous and current service was successfully reset, otherwise returns 0.
	 * @return When calling method failed returns -1.
	 *
	 *	@paragraph <Example>
	 *	This code will reset current and previous service for the specified TV mode.
	 *	It will be done for MAIN profile type and screenId = 0.
	 *	
	 *	@verbatim
	 *	IServiceNavigation* serviceNav;
	 *	TVServiceAPI::CreateServiceNavigation(PROFILE_TYPE_MAIN, 0, &serviceNav);
	 *	if(serviceNav->ResetServiceInfo(TSTvMode(ANTENNA_MODE_AIR)) > 0)
	 *	{
	 *		//Current service was successfully reset.
	 *	}
	 *	@endverbatim
	 */
	virtual int ResetServiceInfo(_IN_ TSTvMode tvMode) = 0;

	/**
	 * @brief Sets current service for specified TV mode.
	 * @remark This method only sets current service Id, nothing more (no tuning is done).
	 * @param [in] tvMode TV mode.
	 * @param [in] service Current service ID.
	 * @return Returns 1 if current service was successfully set, otherwise returns 0.
	 * @return When calling method failed returns -1.
	 *
	 *	@paragraph <Example>
	 *	This code will set service id of current service for the specified TV mode.
	 *	It will be done for MAIN profile type, screenId = 0 and TV mode AIR.
	 *	
	 *	@verbatim
	 *	IServiceNavigation* serviceNav;
	 *	TVServiceAPI::CreateServiceNavigation(PROFILE_TYPE_MAIN, 0, &serviceNav);
	 *	TCServiceId currentServiceId = 845524458537987;
	 *	if(serviceNav->SetCurrentServiceInfo(TSTvMode(ANTENNA_MODE_AIR), currentServiceId) > 0)
	 *	{
	 *		//Service id was succesfuly set
	 *	}
	 *	@endverbatim
	 */
	virtual int SetCurrentServiceInfo(_IN_ TSTvMode tvMode, _IN_ const TCServiceId& service) = 0;

	/**
	 * @brief Gets current service for specified TV mode.
	 * @param [in] tvMode TV mode.
	 * @param [in] fetchCriteria Specify which data will be returned in service.
	 * @param [out] service Current service.
	 * @return Returns 1 if current service was successfully obtained with all required data, otherwise returns 0.
	 * @return When calling method failed returns -1.
	 *
	 *	@paragraph <Example>
	 *	This code will return service with data like SERVICE_ID, MAJOR for the specified TV mode.
	 *	It will be done for MAIN profile type, screenId = 0 and TV mode AIR.
	 *	
	 *	@verbatim
	 *	IServiceNavigation* serviceNav;
	 *	TVServiceAPI::CreateServiceNavigation(PROFILE_TYPE_MAIN, 0, &serviceNav);
 	 *	TCCriteriaHelper fetchCriteria;
	 *	fetchCriteria.Fetch(SERVICE_ID);
	 *	fetchCriteria.Fetch(MAJOR);
	 *	TCServiceData service;
	 *	if(serviceNav->GetCurrentServiceInfo(TSTvMode(ANTENNA_MODE_AIR), fetchCriteria, service) > 0)
	 *	{
	 *		//Service data was succesfuly returned
	 *	}
	 *	@endverbatim
	 */
	virtual int GetCurrentServiceInfo(_IN_ TSTvMode tvMode, _IN_ const TCCriteriaHelper& fetchCriteria, _OUT_ TCServiceData& service) = 0;

	/**
	 * @brief Gets current service for current TV mode.
	 * @param [in] fetchCriteria Specify which data will be returned in service.
	 * @param [out] service Current service.
	 * @return Returns 1 if current service was successfully obtained with all required data, otherwise returns 0.
	 * @return When calling method failed returns -1.
	 *
	 *	@paragraph <Example>
	 *	This code will return service with data like SERVICE_ID, MAJOR for current TV mode.
	 *	It will be done for MAIN profile type, screenId = 0
	 *	
	 *	@verbatim
	 *	IServiceNavigation* serviceNav;
	 *	TVServiceAPI::CreateServiceNavigation(PROFILE_TYPE_MAIN, 0, &serviceNav);
 	 *	TCCriteriaHelper fetchCriteria;
	 *	fetchCriteria.Fetch(SERVICE_ID);
	 *	fetchCriteria.Fetch(MAJOR);
	 *	TCServiceData service;
	 *	if(serviceNav->GetCurrentServiceInfo(fetchCriteria, service) > 0)
	 *	{
	 *		//Service data was succesfuly returned
	 *	}
	 *	@endverbatim
	 */
	virtual int GetCurrentServiceInfo(_IN_ const TCCriteriaHelper& fetchCriteria, _OUT_ TCServiceData& service) = 0;

	/**
	 * @brief Sets previous service for specified TV mode.
	 * @param [in] tvMode TV mode.
	 * @param [out] service Previous service ID.
	 * @return Returns 1 if previous service was successfully set, otherwise returns 0.
	 * @return When calling method failed returns -1.
	 *
	 *	@paragraph <Example>
	 *	This code will set service id of previous service for the specified TV mode.
	 *	It will be done for MAIN profile type, screenId = 0 and TV mode AIR.
	 *	
	 *	@verbatim
	 *	IServiceNavigation* serviceNav;
	 *	TVServiceAPI::CreateServiceNavigation(PROFILE_TYPE_MAIN, 0, &serviceNav);
	 *	TCServiceId previousServiceId = 845524458537987;
	 *	if(serviceNav->SetPreviousServiceInfo(TSTvMode(ANTENNA_MODE_AIR), previousServiceId) > 0)
	 *	{
	 *		//Service id was succesfuly set
	 *	}
	 *	@endverbatim
	 */
	virtual int SetPreviousServiceInfo(_IN_ TSTvMode tvMode, _IN_ const TCServiceId& service) = 0;

	/**
	 * @brief Gets previous service for specified TV mode.
	 * @param [in] tvMode TV mode.
	 * @param [out] service previous service ID.
	 * @return Returns 1 if previous service was successfully obtained, otherwise returns 0.
	 * @return When calling method failed returns -1.
	 *
	 *	@paragraph <Example>
	 *	This code will get service id of previous service for the specified TV mode.
	 *	It will be done for MAIN profile type, screenId = 0 and TV mode AIR.
	 *	
	 *	@verbatim
	 *	IServiceNavigation* serviceNav;
	 *	TVServiceAPI::CreateServiceNavigation(PROFILE_TYPE_MAIN, 0, &serviceNav);
	 *	TCServiceId previousServiceId;
	 *	if(serviceNav->GetPreviousServiceInfo(TSTvMode(ANTENNA_MODE_AIR), previousServiceId) > 0)
	 *	{
	 *		//Service id was succesfuly returned
	 *	}
	 *	@endverbatim
	 */
	virtual int GetPreviousServiceInfo(_IN_ TSTvMode tvMode, _OUT_ TCServiceId& service) = 0;
	
	/**
	 * @brief Checks if given service exists in service list.
	 * @param [in] service Selected service ID.
	 * @return Returns 1 if given service was found, otherwise returns 0.
	 * @return When calling method failed returns -1.
	 *
	 *	@paragraph <Example>
	 *	This code will check if there is service with ID 845524458537987 for MAIN profile type and screenId = 0.
	 *	
	 *	@verbatim
	 *	IServiceNavigation* serviceNav;
	 *	TVServiceAPI::CreateServiceNavigation(PROFILE_TYPE_MAIN, 0, &serviceNav);
	 *	TCServiceId serviceId = 845524458537987;
	 *	if(serviceNav->CheckService(serviceId) > 0)
	 *	{
	 *		//Service exists
	 *	}
	 *	@endverbatim
	 */
	virtual int CheckService(_IN_ const TCServiceId& service) = 0;
	
	/**
	 * @brief Sets service without changing information about current and previous service.
	 * @param [in] serviceId Selected service ID.
	 * @return Returns 1 if TV successfully tuned to specified service, otherwise returns 0.
	 * @return When calling method failed returns -1.
	 *
	 *	@paragraph <Example>
	 *	This code will tune to service with ID 845524458537987 for MAIN profile type and screenId = 0.
	 *	
	 *	@verbatim
	 *	IServiceNavigation* serviceNav;
	 *	TVServiceAPI::CreateServiceNavigation(PROFILE_TYPE_MAIN, 0, &serviceNav);
	 *	TCServiceId serviceId = 845524458537987;
	 *	if(serviceNav->SetServiceWithoutChangingServiceInfo(serviceId) > 0)
	 *	{
	 *		//Service was succesfuly set
	 *	}
	 *	@endverbatim
	 */
	virtual int SetServiceWithoutChangingServiceInfo(_IN_ const TCServiceId& service) = 0;
	
	/**
	 * @brief Sets service without changing information about previous service.
	 * @param [in] serviceId Selected service ID.
	 * @return Returns 1 if TV successfully tuned to specified service, otherwise returns 0.
	 * @return When calling method failed returns -1.
	 *
	 *	@paragraph <Example>
	 *	This code will tune to service with ID 845524458537987 for MAIN profile type and screenId = 0.
	 *	
	 *	@verbatim
	 *	IServiceNavigation* serviceNav;
	 *	TVServiceAPI::CreateServiceNavigation(PROFILE_TYPE_MAIN, 0, &serviceNav);
	 *	TCServiceId serviceId = 845524458537987;
	 *	if(serviceNav->SetServiceWithoutChangingPreviousServiceInfo(serviceId) > 0)
	 *	{
	 *		//Service was succesfuly set
	 *	}
	 *	@endverbatim
	 */
	virtual int SetServiceWithoutChangingPreviousServiceInfo(_IN_ const TCServiceId& service) = 0;

	/**
	* @brief Get next service according to specified criteria.
	* @remarks Caller must specify which next service information should be fetched.
	* @remarks Input criteria should specify only conditions related to application settings (like sort mode),
	*	   criteria related to spec and system state shall be handled on native side.
	* @remarks Next service is determined for current TV mode.
	* @param [in] criteria Specifies what should be fetched. Also specifies application settings (e.g. sort mode) if applicable.
	* @param [in] referenceServiceId Id of service that shall be used as reference to determine next service.
	* @param [out] service Next service  - contains only those tags specified by FETCH in input criteria.
	* @param [in] tvMode TV Mode for which next service will be obtained.
	* @return Returns 1 if next service was found, otherwise returns 0. When calling method failed returns -1
	*
	* @paragraph <Example>
	*	Suppose that we have list of services (ids given in brackets): A(10), C(11), F(12), B(15).
	*	Assuming that current service id is 15 and application sort mode is 'by name', below code will return service C(11).
	*	
	* @verbatim
	*	IServiceNavigation* serviceNav;
	*	TVServiceAPI::CreateServiceNavigation(PROFILE_TYPE_MAIN, 0, &serviceNav);
	*	
	*	TCCriteriaHelper criteria;
	*	criteria.Fetch(SERVICE_ID);
	*	criteria.Fetch(SERVICE_NAME);
	*	criteria.OrderBy(SERVICE_NAME);
	*	TCServiceData nextService;
	*	if(serviceNav->GetNextService(criteria, 15, nextService) > 0)
	*	{
	*		//Do something for returned service
	*	}
	* @endverbatim
	*/
	virtual int GetNextService(_IN_ const TCCriteriaHelper& criteria, _IN_ const TCServiceId& referenceServiceId, _OUT_ TCServiceData& service, _IN_ TSTvMode tvMode = TSTvMode()) = 0;

	/**
	* @brief Get previous service according to specified criteria.
	* @remarks Caller must specify which previous service information should be fetched.
	* @remarks Input criteria should specify only conditions related to application settings (like sort mode),
	*	   criteria related to spec and system state shall be handled on native side.
	* @remarks Previous service is determined for current TV mode.
	* @param [in] criteria Specifies what should be fetched. Also specifies major/minor and application settings (e.g. sort mode) if applicable.
	* @param [in] referenceServiceId Id of service that shall be used as reference to determine previous service.
	* @param [out] service Previous service - contains only those tags specified by FETCH in input criteria.
	* @param [in] tvMode TV Mode for which previous service will be obtained.
	* @return Returns 1 if previous service was found, otherwise returns 0. When calling method failed returns -1.
	*
	* @paragraph <Example>
	*	Suppose that we have list of services (ids given in brackets): A(10), C(11), F(12), B(15).
	*	Assuming that current service id is 15 and application sort mode is 'by name', below code will return service A(10).
	*	
	* @verbatim
	*	IServiceNavigation* pServiceNav = NULL;
	*	TVServiceAPI::CreateServiceNavigation(PROFILE_TYPE_MAIN, 0, &serviceNav);
	*	
	*	TCCriteriaHelper criteria;
	*	criteria.Fetch(SERVICE_ID);
	*	criteria.Fetch(SERVICE_NAME);
	*	TCNavigationModeHelper::GetNavigationCriteria( NAVIGATION_MODE_ALL, criteria, ORDER_BY_NAME );
	*	TCServiceData previousService;
	*	if(serviceNav->GetPreviousService(criteria, 15, previousService) > 0)
	*	{
	*		//Do something for returned service
	*	}
	* @endverbatim
	*/
	virtual int GetPreviousService(_IN_ const TCCriteriaHelper& criteria, _IN_ const TCServiceId& referenceServiceId, _OUT_ TCServiceData& service, _IN_ TSTvMode tvMode = TSTvMode()) = 0;

	/**
	 * @brief Get optimum service for major-minor input by user.
	 * @remarks Caller must specify which service information should be fetched.
	 * @remarks Input criteria should specify only major and minor (if applicable),
	 *		criteria related to spec and system state shall be handled on native side.
	 * @remarks Optimum service is determined for current TV mode.
	 * @param [in] criteria Specifies what should be fetched. Also specifies major/minor.
	 * @param [out] service Found optimum service  - contains only those tags specified by FETCH in input criteria.
	 * @param [in] tvMode TV Mode for which optimum service will be obtained.
	 * @return Returns 1 if optimum service was found, otherwise returns 0.
	 * @return When calling method failed returns -1.
	 *
	 *	@paragraph <Example>
	 *	User enters '5'.
	 *	
	 *	@verbatim
	 *	IServiceNavigation* pServiceNav = NULL;
	 *	TVServiceAPI::CreateServiceNavigation(PROFILE_TYPE_MAIN, 0, &serviceNav);
	 *	
	 *	TCCriteriaHelper criteria;
	 *	criteria.Fetch(SERVICE_ID);
	 *	criteria.Fetch(SERVICE_NAME);
	 *	TCNavigationModeHelper::GetOptimumCriteria( 5, INVALID );
	 *	TCServiceData optimumService;
	 *	if(serviceNav->GetOptimumService(criteria, optimumService) > 0)
	 *	{
	 *		//Do something with returned service.
	 *	}
	 *	@endverbatim
	 */
	virtual int GetOptimumService(_IN_ const TCCriteriaHelper& criteria, _OUT_ TCServiceData& service, _IN_ TSTvMode tvMode = TSTvMode()) = 0;

	/**
	* @brief Sets next service according to navigation mode.
	* @remarks Input criteria should specify only conditions related to application settings (like sort mode),
	*	   criteria related to spec and system state shall be handled on native side.
	* @remarks Next service is determined for current TV mode.
	* @param [in] criteria Specifies which service should be choosen as next.
	* @return Returns 1 if next service was set, otherwise returns 0. When calling method failed returns -1.
	*
	* @paragraph <Example>
	*	Setting next service		
	* @verbatim
	*	IServiceNavigation* pServiceNav = NULL;
	*	TVServiceAPI::CreateServiceNavigation(PROFILE_TYPE_MAIN, 0, &serviceNav);
	*
	*	TCCriteriaHelper criteria;
	*	TCNavigationModeHelper::GetNavigationCriteria( NAVIGATION_MODE_TV, criteria );
	*	if(serviceNav->SetNextService( criteria ) > 0)
	*	{
	*		//Next service was set
	*	}
	* @endverbatim
	*/
	virtual int SetNextService(	_IN_ const TCCriteriaHelper& criteria ) = 0;

	/**
	* @brief Sets next service according to navigation mode.
	* @remarks Input criteria should specify only conditions related to application settings (like sort mode),
	*	   criteria related to spec and system state shall be handled on native side.
	*	   Criteria should include Fetch for the resulting service
	* @remarks Next service is determined for current TV mode.
	* @param [in] criteria Specifies which service should be choosen as next. It also specifies which attributes should be obtained for the result service
	* @param [out] outService Resulting service from Set Next Service operation
	* @return Returns 1 if next service was set, otherwise returns 0. When calling method failed returns -1.
	*
	* @paragraph <Example>
	*	Setting next service		
	* @verbatim
	*	IServiceNavigation* pServiceNav = NULL;
	*	TVServiceAPI::CreateServiceNavigation(PROFILE_TYPE_MAIN, 0, &serviceNav);
	*
	*	TCCriteriaHelper criteria;
	*	criteria.Fetch(MAJOR);
	*	TCNavigationModeHelper::GetNavigationCriteria( NAVIGATION_MODE_TV, criteria );
	*	TCServiceData service;
	*	if(serviceNav->SetNextService( criteria, service ) > 0)
	*	{
	*		//Next service was set. Resulting service can be used.
	*		service.Get<unsigned short>(MAJOR);
	*	}
	* @endverbatim
	*/
	virtual int SetNextService(	_IN_ const TCCriteriaHelper& criteria, _OUT_ TCServiceData& outService ) = 0;

	/**
	* @brief Sets previous service according to navigation mode.
	* @remarks Input criteria should specify only conditions related to application settings (like sort mode),
	*	   criteria related to spec and system state shall be handled on native side.
	* @remarks Previous service is determined for current TV mode.
	* @param [in] criteria Specifies which service should be choosen as previous.
	* @return Returns 1 if previous service was set, otherwise returns 0. When calling method failed returns -1.
	*
	* @paragraph <Example>
	*	Setting previous service		
	* @verbatim
	*	IServiceNavigation* pServiceNav = NULL;
	*	TVServiceAPI::CreateServiceNavigation(PROFILE_TYPE_MAIN, 0, &serviceNav);
	*
	*	TCCriteriaHelper criteria;
	*	TCNavigationModeHelper::GetNavigationCriteria( NAVIGATION_MODE_TV, criteria );
	*	if(serviceNav->SetPreviousService( criteria ) > 0)
	*	{
	*		//Previous service was set
	*	}
	* @endverbatim
	*/
	virtual int SetPreviousService( _IN_ const TCCriteriaHelper& criteria ) = 0;

	/**
	* @brief Sets previous service according to navigation mode.
	* @remarks Input criteria should specify only conditions related to application settings (like sort mode),
	*	   criteria related to spec and system state shall be handled on native side.
	*	   Criteria should include Fetch for the resulting service
	* @remarks Previous service is determined for current TV mode.
	* @param [in] criteria Specifies which service should be choosen as previous.
	* @param [out] outService Resulting service from Set Previous Service operation 
	* @return Returns 1 if previous service was set, otherwise returns 0. When calling method failed returns -1.
	*
	* @paragraph <Example>
	*	Setting previous service		
	* @verbatim
	*	IServiceNavigation* pServiceNav = NULL;
	*	TVServiceAPI::CreateServiceNavigation(PROFILE_TYPE_MAIN, 0, &serviceNav);
	*
	*	TCCriteriaHelper criteria;
	*	criteria.Fetch(MAJOR);
	*	TCNavigationModeHelper::GetNavigationCriteria( NAVIGATION_MODE_TV, criteria );
	*	TCServiceData service;
	*	if(serviceNav->SetPreviousService( criteria, service ) > 0)
	*	{
	*		//Previous service was set. Resulting service can be used.
	*		service.Get<unsigned short>(MAJOR);
	*		
	*	}
	* @endverbatim
	*/
	virtual int SetPreviousService( _IN_ const TCCriteriaHelper& criteria, _OUT_ TCServiceData& outService ) = 0;

	/**
	 * @brief Sets optimum service for criteria given by user.
	 * @remarks Input criteria should specify only major and minor (if applicable),
	 *		criteria related to spec and system state shall be handled on native side.
	 * @remarks Optimum service is determined for current TV mode.
	 * @param [in] criteria Specifies which service should be choosen as optimum.
	 * @return Returns 1 if optimum service was set, otherwise returns 0.
	 * @return When calling method failed returns -1.
	 *
	 *	@paragraph <Example>
	 *	This example shows getting optimum service when user enters '5'.
	 *	
	 *	@verbatim
	 *	IServiceNavigation* pServiceNav = NULL;
	 *	TVServiceAPI::CreateServiceNavigation(PROFILE_TYPE_MAIN, 0, &serviceNav);
	 *		
	 *	TCCriteriaHelper criteria;
	 *	TCNavigationModeHelper::GetOptimumCriteria( 5, INVALID );
	 *	if(serviceNav->SetOptimumService( criteria ) > 0)
	 *	{
	 *		//Opitmum service was set.
	 *	}
	 *	@endverbatim
	 */
	virtual int SetOptimumService( _IN_ const TCCriteriaHelper& criteria ) = 0;

	/**
	 * @brief Sets optimum service for criteria given by user.
	 * @remarks Input criteria should specify only major and minor (if applicable),
	 *		criteria related to spec and system state shall be handled on native side.
	 *	   Criteria should include Fetch for the resulting service
	 * @remarks Optimum service is determined for current TV mode.
	 * @param [in] criteria Specifies which service should be choosen as optimum.
	 * @param [out] outService Resulting service from Set Optimum Service operation  
	 * @return Returns 1 if optimum service was set, otherwise returns 0.
	 * @return When calling method failed returns -1.
	 *
	 *	@paragraph <Example>
	 *	This example shows getting optimum service when user enters '5'.
	 *	
	 *	@verbatim
	 *	IServiceNavigation* pServiceNav = NULL;
	 *	TVServiceAPI::CreateServiceNavigation(PROFILE_TYPE_MAIN, 0, &serviceNav);
	 *		
	 *	TCCriteriaHelper criteria;
	 *	criteria.Fetch(MAJOR);
	 *	TCNavigationModeHelper::GetOptimumCriteria( 5, INVALID );
	 *	TCServiceData service;
	 *	if(serviceNav->SetOptimumService( criteria, service ) > 0)
	 *	{
	 *		//Opitmum service was set. Result service can be used.
	 *		service.Get<unsigned short>(MAJOR);
	 *	}
	 *	@endverbatim
	 */
	virtual int SetOptimumService( _IN_ const TCCriteriaHelper& criteria, _OUT_ TCServiceData& outService ) = 0;

	/**
	 * @brief Get list of services supported by current pipeline.
	 * @remarks This method is pipeline-specific. Example: PIP pipeline might not support analog services, what shall be considered by this method.
	 * @remarks Caller must free memory allocated to services in container.
	 * @remarks Caller must specify which service information should be fetched.
	 * @remarks Application criteria are prepared by NavigationModeHelper, criteria related to system state/configuration are handled on TVS side.
	 * @param [in] criteria Specifies what should be fetched. Also specifies navigation criteria .
	 * @param [out] services Services matching navigation mode -  service objects contain only those tags specified by FETCH in input criteria.
	 * @param [in] tvMode TV mode for which service list should be acquired, if not specified - current TV mode shall be used.
	 * @param [in] serviceListType Type of services which will be included on service list.
 	 * @param [in] includeDefaultCurrent include default current service to service list.
	 * @return Returns 1 if services matching navigation mode were found, otherwise returns 0.
	 * @return When calling method failed returns -1.
	 *
	 *	@paragraph <Example>
	 *	Navigation mode is ALL.
	 *	
	 *	@verbatim
	 *	IServiceNavigation* pServiceNav = NULL;
	 *	TVServiceAPI::CreateServiceNavigation(PROFILE_TYPE_MAIN, 0, &serviceNav);
	 *	
	 *	TCCriteriaHelper criteria;
	 *	criteria.Fetch(SERVICE_ID);
	 *	criteria.Fetch(SERVICE_NAME);
	 *	TCNavigationModeHelper::GetNavigationCriteria( NAVIGATION_MODE_ALL, criteria );
	 *	std::list<TCServiceData*> services;
	 *	if(serviceNav->GetServiceList(criteria, services) > 0)
	 *	{
	 *		//Do something with returned service.
	 *	}
	 *	DELETE_LIST( std::list<TCServiceData*>, services );
	 *	@endverbatim
	 */
	virtual int GetServiceList(
				_IN_ const TCCriteriaHelper& criteria, 
				_OUT_ std::list<TCServiceData*>& services, 
				_IN_ TSTvMode tvMode = TSTvMode(), 
				_IN_ EServiceListType serviceListType = SERVICE_LIST_DISPLAYABLE, 
				_IN_ bool includeDefaultCurrent = false ) = 0;

	/**
	 * @brief Get number of services supported by current pipeline.
	 * @remarks This method is pipeline-specific. Example: PIP pipeline might not support analog services, what shall be considered by this method.
	 * @param [in] critiera Critiera specifying which services shall be counted.
	 * @param [out] count Number of services matching input criteria.
	 * @param [in] tvMode TV mode for which services shall be counted, if not specified - current TV mode shall be used.
	 * @param [in] serviceListType Type of services which will be counted.
	 * @return Returns 1 if services matching navigation mode were found, otherwise returns 0.
	 * @return When calling method failed returns -1.
	 *
	 *	@paragraph <Example>
	 *	This code will count services matching NAVIGATION_MODE_ALL in PIP window.
	 *	
	 *	@verbatim
	 *	IServiceNavigation* pServiceNav = NULL;
	 *	TVServiceAPI::CreateServiceNavigation(PROFILE_TYPE_PIP, 0, &serviceNav);
	 *	
	 *	TCCriteriaHelper criteria;
	 *	TCNavigationModeHelper::GetNavigationCriteria( NAVIGATION_MODE_ALL, criteria );
	 *	int count = 0;
	 *	if(serviceNav->GetServiceCount(criteria, count) > 0)
	 *	{
	 *		//Services matching criteria found.
	 *	}
	 *	@endverbatim
	 */
	virtual int GetServiceCount(
				_IN_ const TCCriteriaHelper& criteria, 
				_OUT_ int& count, 
				_IN_ TSTvMode tvMode = TSTvMode(), 
				_IN_ EServiceListType serviceListType = SERVICE_LIST_DISPLAYABLE ) = 0;


	/**
	 * @brief Gets first service of available services or available source if TV source is not available.
	 * @remark Information returned is decided based on current status (state of Main window, Recording, some special TV mode).
	 * @remark This method can be used to show service info to user before activating profile.
	 * @param [out] serviceId Available service that can be start-up service if TV source is available.
	 * @param [out] source Available source that can be start-up source if TV source is not available.
	 * @return Returns 1 if available service or source was found, otherwise returns 0.
	 * @return When calling method failed returns -1.
	 *
	 *	@paragraph <Example>
	 *	This code will get first available service (or source if TV source is not available)
	 *	
	 *	@verbatim
	 *	IServiceNavigation* serviceNav;
	 *	TVServiceAPI::CreateServiceNavigation(PROFILE_TYPE_MAIN, 0, &serviceNav);
	 *	
	 *	TCServiceId serviceId;
	 *	ESource source;
	 *	if(serviceNav->GetStartService(serviceId, source) > 0)
	 *	{
	 *		//Do something with returned serviceId or source.
	 *	}
	 *	@endverbatim
	 */
	virtual int GetStartService(_OUT_ TCServiceId& serviceId, _OUT_ ESource& source) = 0;

	/**
	 * @brief Gets default service of given Tv Mode.
	 * @param [in] tvMode Tv Mode.
	 * @param [out] service Default Tv Service to be returned.
	 * @return Returns 1 if optimum service was found, otherwise returns 0.
	 * @return When calling method failed returns -1.
	 *
	 *  @paragraph <Example>
	 *	This code will get service id of default service for the specified TV mode.
	 *	It will be done for MAIN profile type, screenId = 0 and TV mode AIR.
	 *
	 *	@verbatim
	 *	IServiceNavigation* serviceNav;
	 *	TVServiceAPI::CreateServiceNavigation(PROFILE_TYPE_MAIN, 0, &serviceNav);
	 *	TCServiceId defaultServiceId;
	 *	if(serviceNav->GetDefaultServiceInfo(TSTvMode(ANTENNA_MODE_AIR), defaultServiceId) > 0)
	 *	{
	 *		//Default service id was succesfuly returned
	 *	}
	 *	@endverbatim
	 */
	virtual int GetDefaultServiceInfo(_IN_ TSTvMode tvMode, _OUT_ TCServiceId& service) = 0;

	virtual int SetDTVMode(_IN_ EDTVModeType mode, _IN_ bool enable) = 0;
	virtual int SetVideoPID(_IN_ unsigned short video_pid, _IN_ EVideoEncodeType vEncType, _IN_ unsigned short pcr_pid) =0;
	virtual int SetAudioPID(_IN_ unsigned short audio_pid, _IN_ EAudioEncodeType aEncType) =0;

	
	/**
	 * @brief Perform non-destructive service replacement.
	 * @param [in] serviceId Selected service ID.
	 * @return Returns 1 if successfully done non-destructive replacement, otherwise returns 0.
	 * @return When calling method failed returns -1.
	 *
	 *	@paragraph <Example>
	 *	This code will perform non-destructive replacement for service with ID 845524458537987 for MAIN profile type and screenId = 0.
	 *	
	 *	@verbatim
	 *	IServiceNavigation* serviceNav;
	 *	TVServiceAPI::CreateServiceNavigation(PROFILE_TYPE_MAIN, 0, &serviceNav);
	 *	TCServiceId serviceId = 845524458537987;
	 *	if(serviceNav->SetServiceNonDestructive(serviceId) > 0)
	 *	{
	 *		//Do something when operation successful
	 *	}
	 *	@endverbatim
	 */
	virtual int SetServiceNonDestructive(_IN_ const TCServiceId& serviceId) = 0;

	/**
	 * @brief Checks if a non-destructive tune should be allowed between two services.
	 * @remarks MHEG and Freesat related method.
	 * @param [in] serviceId1 ID of first service to be checked.
	 * @param [in] serviceId2 ID of second service to be checked.
	 * @param [out] result TRUE if non-destructive tune should be allowed, FALSE otherwise.
	 * @return Returns 1 if information was successfully obtained, otherwise returns 0.
	 * @return When calling method failed returns -1.
	 *
	 *	@paragraph <Example>
	 *	This code will check if a non-destructive tune should be allowed between two given services
	 *	(with IDs 845524458537987 and 815524258533215) for MAIN profile type and screenId = 0.
	 *	
	 *	@verbatim
	 *	IServiceNavigation* serviceNav;
	 *	TVServiceAPI::CreateServiceNavigation(PROFILE_TYPE_MAIN, 0, &serviceNav);
	 *	TCServiceId serviceId1 = 845524458537987;
	 *	TCServiceId serviceId2 = 815524258533215;
	 *	bool result;
	 *	if(serviceNav->NonDestructiveTuneAllowed(serviceId1, serviceId2, result) > 0)
	 *	{
	 *		//Do something with result value
	 *	}
	 *	@endverbatim
	 */
	virtual int NonDestructiveTuneAllowed(const _IN_ TCServiceId& serviceId1, const _IN_ TCServiceId& serviceId2, _OUT_ bool& result) = 0;

	/**
	 * @brief Notify to start satellite setting
	 * @remark Call it before satellite configuration is started to create dummy pipeline required for proper communication with lower layers.
	 * @return Returns 1 if TV successfully create dummy pipeline, otherwise returns 0.
	 * @return When calling method failed returns -1.
	 *
	 *	@paragraph <Example>
	 *	This code will notify start satellite setting
	 *		 
	 *	@verbatim
	 *	IServiceNavigation* serviceNav;
	 *	TVServiceAPI::CreateServiceNavigation(PROFILE_TYPE_MAIN, 0, &serviceNav);
	 *	serviceNav->StartSatelliteSetting();
	 *	@endverbatim
	 */
	virtual int StartSatelliteSetting(void) = 0;

	/**
	 * @brief Notify to stop satellite setting
	 * @remark Call it after satellite setting is completed to destroy dummy pipeline.
	 * @return Returns 1 if TV successfully destroy dummy pipeline, otherwise returns 0.
	 * @return When calling method failed returns -1.
	 *
	 *		  @paragraph <Example>
	 *		  This code will notify to stop satellite setting
	 *		  
	 *		  @verbatim
	 *		  IServiceNavigation* serviceNav;
	 *		  TVServiceAPI::CreateServiceNavigation(PROFILE_TYPE_MAIN, 0, &serviceNav);
	 *		  serviceNav->StopSatelliteSetting();
	 *		  @endverbatim
	 */
	virtual int StopSatelliteSetting(void) = 0;

	/**
	 * @brief Gets if dynamic SI is enabled.
	 * @param [out] active Requested Dynamic SI state (true - active, false - not active).
	 * @return Returns 1 if Dynamic SI state was successfully get, otherwise returns 0.
	 * @return When calling method failed returns -1.
	 *
	 *	@paragraph <Example>
	 *	This code will check if Dynamic SI is enabled
	 *	
	 *	@verbatim
	 *	IServiceNavigation* serviceNav;
	 *	TVServiceAPI::CreateServiceNavigation(PROFILE_TYPE_MAIN, 0, &serviceNav);
	 *
	 *	bool active;
	 *	if( 1 == serviceNav->GetDynamicSIState(active) )
	 *	{
	 *		if(true == active)
	 *		{
	 *			// dynamic SI is active
	 *		}
	 *		else
	 *		{
	 *			// dynamic SI is not active
	 *		}
	 *	}
	 *	@endverbatim
	 */
	virtual int GetDynamicSIState(_OUT_ bool& active) = 0;

	/**
	 * @brief Enables/disables dynamic SI (possible service list update in background)
	 * @param [in] active Requested Dynamic SI state (true - active, false - not active).
	 * @return Returns 1 if Dynamic SI state was successfully set, otherwise returns 0.
	 * @return When calling method failed returns -1.
	 *
	 *	@paragraph <Example>
	 *	This code will disable Dynamic SI
	 *	
	 *	@verbatim
	 *	IServiceNavigation* serviceNav;
	 *	TVServiceAPI::CreateServiceNavigation(PROFILE_TYPE_MAIN, 0, &serviceNav);
	 *	if( 1 == serviceNav->SetDynamicSIState(false) )
	 *	{
	 *		// dynamic SI is not active
	 *	}
	 *	@endverbatim
	 */
	virtual int SetDynamicSIState(_IN_ bool active) = 0;

	/**
	 * @brief Tunes to Barker Channel.
	 * @remark Barker channel parameters are retrieved from stream and stored in TVS.
	 * @param [in] serviceId service ID of Barker Channel
	 * @return Returns 1 if tune was successful, otherwise returns 0.
	 * @return When calling this method failed returns -1.
	 *
	 *	@paragraph <Example>
	 *	This code will tune to Barker Channel.
	 *	
	 *	@verbatim
	 *	IServiceNavigation* pServiceNav;
	 *	TVServiceAPI::CreateServiceNavigation(DEFAULT_PROFILE_TYPE, DEFAULT_SCREEN_ID, &pServiceNav);
	 *	if( 0 < pServiceNav->TuneBarkerChannel() )
	 *	{
	 *		// do something when tune was successful.
	 *	}
	 *	@endverbatim
	 */
	virtual int TuneBarkerChannel(_IN_ const TCServiceId& serviceId = INVALID_SERVICE_ID) = 0;

	/**
	 * @brief Gets latest TVPlus service.
	 * @param [in] fetchCriteria Criteria defining which fields will be available in service.
	 * @param [out] service Obtained latest TVPlus service.
	 * @return Returns 1 if service obtained successfully, otherwise returns 0.
	 * @return When calling this method failed returns -1.
	 *
	 *	@paragraph <Example>
	 *	This code will obtain latest TVPlus service.
	 *	
	 *	@verbatim
	 *	IServiceNavigation* pServiceNav;
	 *	TVServiceAPI::CreateServiceNavigation(DEFAULT_PROFILE_TYPE, DEFAULT_SCREEN_ID, &pServiceNav);
	 *  TCCriteriaHelper fetchCriteria;
	 *	fetchCriteria.Fetch(MAJOR);
	 *	fetchCriteria.Fetch(PROGRAM_NUMBER);
	 *	fetchCriteria.Fetch(SERVICE_PROFILE);
	 *	TCServiceData service;
	 *	if( 0 < pServiceNav->GetLatestTvPlusService(fetchCriteria, service) )
	 *	{
	 *		// do something with service
	 *	}
	 *	@endverbatim
	 */
	virtual int GetLatestTvPlusService(_IN_ const TCCriteriaHelper& fetchCriteria, _OUT_ TCServiceData& service) = 0;
};

#endif // _ISERVICENAVIGATION_H_
