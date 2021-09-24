/** 
 * @file IScanData.h
 * @brief Application interface for manage option of scanning.
 *
 * Copyright 2013 by Samsung Electronics, Inc.,
 * 
 * This software is the confidential and proprietary information
 * of Samsung Electronics, Inc. ("Confidential Information"). You
 * shall not disclose such Confidential Information and shall use
 * it only in accordance with the terms of the license agreement
 * you entered into with Samsung.
 */

	
#ifndef _ISCANDATA_H_
#define _ISCANDATA_H_


#include <vector>
#include <map>
#include <list>
#include <string>

#include "MarshallingMarks.h"
#include "ScanDataDataType.h"
#include "ServiceNavigationDataType.h"
#include "ServiceData.h"
#include "CriteriaHelper.h"
#include "TVServiceDataType.h"

class IScanData
{

protected:
	virtual ~IScanData(){};

public:

	/**
	 * @brief Gets scan info for due scan mode.
	 * @param [in] scanMode Defines scan mode.
	 * @param [out] info Consists of values like: numberOfChannel.
	 * @param [in] cloudScan determines if cloud scan is enabled or not
	 * @return Returns 1 if search option was available, otherwise returns 0.
	 * @return When calling method failed returns -1.
	 *
	 *	@paragraph <Example>
	 *	This example will return scan info structure to due scanMode like SCAN_MODE_AIR_CABLE.
	 *	
	 *	@verbatim
	 *	IScanData* pScanData = NULL;
	 *	TVServiceAPI::CreateScanData(&pScanData);
	 *	EScanMode scanMode = SCAN_MODE_AIR_CABLE;
	 *	TSScanInfo info;
	 *	if(pScanData->GetScanInfo( scanMode, info) > 0)
	 *	{
	 *		//Do something when operation successful
	 *	}
	 *	@endverbatim
	 */
	virtual int GetScanInfo(_IN_ EScanMode mode, _OUT_ TSScanInfo& info, _IN_ ECloudScan cloudScan = CLOUD_SCAN_DISABLED) = 0;
	
	
	/**
	 * @brief Gets scan option for due kind.
	 * @param [inout] option include specified value.
	 * @return Returns 1 if search option was available, otherwise returns 0.
	 * @return When calling method failed returns -1.
	 *
	 *	@paragraph <Example>
	 *	This example will return scan option for due kind enum like OPTION_SCAN_MODE.
	 *	
	 *	@verbatim
	 *	IScanData* pScanData = NULL;
	 *	TVServiceAPI::CreateScanData(&pScanData);
	 *	TCScanOption option(OPTION_SCAN_MODE);
	 *	if(pScanData->GetScanOption( option ) > 0)
	 *	{
	 *		//Do something when operation successful
	 *	}
	 *	@endverbatim
	 */
	virtual int GetScanOption( _INOUT_ TCScanOption& option, _IN_ TSScanOptionCriteria scanOptionCriteria = TSScanOptionCriteria() ) = 0;
	
	/**
	 * @brief Sets scan option for due kind.
	 * @param [in] option include specified value.
	 * @return Returns 1 if search option was available, otherwise returns 0.
	 * @return When calling method failed returns -1.
	 *
	 *	@paragraph <Example>
	 *	This example will return set scan option for due kind enum like OPTION_SCAN_MODE.
	 *	
	 *	@verbatim
	 *	IScanData* pScanData = NULL;
	 *	TVServiceAPI::CreateScanData(&pScanData);
	 *	TCScanOption option(OPTION_SCAN_MODE);
	 *	option.SetValue<EScanMode>(SCAN_MODE_AIR_CABLE);
	 *	if(pScanData->SetScanOption( option ) > 0)
	 *	{
	 *		//Do something when operation successful
	 *	}
	 *	@endverbatim
	 */
	virtual int SetScanOption( _IN_ const TCScanOption& option, _IN_ TSScanOptionCriteria scanOptionCriteria = TSScanOptionCriteria() ) = 0;
	
	/**
	 * @brief Store scan option for due kind.
	 * @param [in] option include specified value.
	 * @param [in] mode include specified saving mode to NVRAM.
	 * @return Returns 1 if search option was available, otherwise returns 0.
	 * @return When calling method failed returns -1.
	 *
	 *	@paragraph <Example>
	 *	This example will store scan option.
	 *	
	 *	@verbatim
	 *	IScanData* pScanData = NULL;
	 *	TVServiceAPI::CreateScanData(&pScanData);
	 *	if(pScanData->StoreScanOption( option, mode ) > 0)
	 *	{
	 *		//Do something when operation successful
	 *	}
	 *	@endverbatim
	 */
	virtual int StoreScanOption( _IN_ EScanOption option, _IN_ EStoreMode mode, _IN_ TSScanOptionCriteria scanOptionCriteria = TSScanOptionCriteria() ) = 0;
	
	/**
	 * @brief Set homing channel.
	 * @param [in] tvMode Defines current TV mode.
	 * @param [in] homingChannel Defines current homing channel.
	 * @return Returns 1 if homing channel was set, otherwise returns 0.
	 * @return When calling method failed returns -1.
	 *
	 *	@paragraph <Example>
	 *	This example will set homing channel for due TV mode.
	 *	
	 *	@verbatim
	 *	IScanData* pScanData = NULL;
	 *	TVServiceAPI::CreateScanData(&pScanData);
	 *	if(pScanData->SetHomingChannel( tvMode, homingChannel ) > 0)
	 *	{
	 *		//Do something when operation successful
	 *	}
	 *	@endverbatim
	 */
	virtual int SetHomingChannel( _IN_ const TSTvMode& tvMode,  _IN_  const TSHomingChannelLocator& homingChannel ) = 0;
	
	/**
	 * @brief Get homing channel.
	 * @param [in] tvMode Defines current TV mode.
	 * @param [in] broadcasterId Defines current broadcaster.
	 * @param [out] homingChannel Defines current homing channel.
	 * @return Returns 1 if homing channel was available, otherwise returns 0.
	 * @return When calling method failed returns -1.
	 *
	 *	@paragraph <Example>
	 *	This example will get homing channel for due TV mode.
	 *	
	 *	@verbatim
	 *	IScanData* pScanData = NULL;
	 *	TVServiceAPI::CreateScanData(&pScanData);
	 *	if(pScanData->GetHomingChannel( tvMode, broadcasterId, homingChannel ) > 0)
	 *	{
	 *		//Do something when operation successful
	 *	}
	 *	@endverbatim
	 */
	virtual int GetHomingChannel( _IN_ const TSTvMode& tvMode, _IN_ const EBroadCaster& broadCasterId, _OUT_ TSHomingChannelLocator& homingChannel ) = 0;
	
	/**
	 * @brief Get homing channel candidates.
	 * @param [in] tvMode Defines current TV mode.
	 * @param [out] homingChannelCandidates Defines candidates homing channel.
	 * @return Returns 1 if homing channels was available, otherwise returns 0.
	 * @return When calling method failed returns -1.
	 *
	 *	@paragraph <Example>
	 *	This example will get homing channels for due TV mode.
	 *	
	 *	@verbatim
	 *	IScanData* pScanData = NULL;
	 *	TVServiceAPI::CreateScanData(&pScanData);
	 *	if(pScanData->GetHomingChannelCandidates( tvMode, hominChannelCandidates ) > 0)
	 *	{
	 *		//Do something when operation successful
	 *	}
	 *	@endverbatim
	 */
	virtual int GetHomingChannelCandidates( _IN_ const  TSTvMode& tvMode,  _OUT_ std::vector< TSHomingChannelLocator>& homingChannelCandidates ) = 0;
	
	/**
	 * @brief Reset homing channel.
	 * @return Returns 1 if homing channels was reset, otherwise returns 0.
	 * @return When calling method failed returns -1.
	 *
	 *	@paragraph <Example>
	 *	This example will reset homing channel.
	 *	
	 *	@verbatim
	 *	IScanData* pScanData = NULL;
	 *	TVServiceAPI::CreateScanData(&pScanData);
	 *	if(pScanData->ResetHomingChannel() > 0)
	 *	{
	 *		//Do something when operation successful
	 *	}
	 *	@endverbatim
	 */
	virtual int ResetHomingChannel( void ) = 0;
	
	/**
	 * @brief Set preferred target region the system should use for RCN conflict resolution.
	 * @remark Calling this method with a valid target region ID will cause the MW to recalculate the current channel lineup (RCN values).
	 * @param [in] regionId Define target region ID to set.
	 * @return Returns 1 if preferred region was set, otherwise returns 0.
	 * @return When calling method failed returns -1.
	 *
	 *	@paragraph <Example>
	 *	This example will set preferred target region.
	 *	
	 *	@verbatim
	 *	IScanData* pScanData = NULL;
	 *	TVServiceAPI::CreateScanData(&pScanData);
	 *	if(pScanData->SetPreferredTargetRegion(regionId) > 0)
	 *	{
	 *		//Do something when operation successful
	 *	}
	 *	@endverbatim
	 */
	virtual int SetPreferredTargetRegion( _IN_ unsigned int regionId ) = 0;
	
	/**
	 * @brief Get preferred target region.
	 * @param [in] depth Define the depth of the preferred region requested.
	 * @param [out] regionId Define the region index of the target region that shall be used for RCN allocation processing.
	 * @return Returns 1 if preferred region was get, otherwise returns 0.
	 * @return When calling method failed returns -1.
	 *
	 *	@paragraph <Example>
	 *	This example will get preferred target region.
	 *	
	 *	@verbatim
	 *	IScanData* pScanData = NULL;
	 *	TVServiceAPI::CreateScanData(&pScanData);
	 *	if(pScanData->GetPreferredTargetRegion(depth,regionId) > 0)
	 *	{
	 *		//Do something when operation successful
	 *	}
	 *	@endverbatim
	 */
	virtual int GetPreferredTargetRegion( _IN_ unsigned char depth, _OUT_ unsigned int& regionId ) = 0;
	
	/**
	 * @brief Set cam operator profile scan active.
	 * @param [in] active Define whether CAM Operator Profile exclusive network scan is active or not (true/false).
	 * @return Returns 1 if cam operator profile was activate, otherwise returns 0.
	 * @return When calling method failed returns -1.
	 *
	 *	@paragraph <Example>
	 *	This example will set cam operator profile scan active.
	 *	
	 *	@verbatim
	 *	IScanData* pScanData = NULL;
	 *	TVServiceAPI::CreateScanData(&pScanData);
	 *	if(pScanData->SetCamOperatorProfileScanActive(active) > 0)
	 *	{
	 *		//Do something when operation successful
	 *	}
	 *	@endverbatim
	 */
	virtual int SetCamOperatorProfileScanActive( _IN_  bool active ) = 0;
	
	/**
	 * @brief Set app scan active.
	 * @param [in] active Define whether Application exclusive scan is Active or not (true/false).
	 * @return Returns 1 if app scan was activated, otherwise returns 0.
	 * @return When calling method failed returns -1.
	 *
	 *	@paragraph <Example>
	 *	This example will set app scan active.
	 *	
	 *	@verbatim
	 *	IScanData* pScanData = NULL;
	 *	TVServiceAPI::CreateScanData(&pScanData);
	 *	if(pScanData->SetAppScanActive(active) > 0)
	 *	{
	 *		//Do something when operation successful
	 *	}
	 *	@endverbatim
	 */
	virtual int SetAppScanActive( _IN_  bool active ) = 0;
	
	/**
	 * @brief Check service registered list.
	 * @param [out] flag Define whether service list is registered.
	 * @return Returns 1 if service list was registered, otherwise returns 0.
	 * @return When calling method failed returns -1.
	 *
	 *	@paragraph <Example>
	 *	This example will check registered service list.
	 *	
	 *	@verbatim
	 *	IScanData* pScanData = NULL;
	 *	TVServiceAPI::CreateScanData(&pScanData);
	 *	if(pScanData->CheckServiceListsRegistered(flag) > 0)
	 *	{
	 *		//Do something when operation successful
	 *	}
	 *	@endverbatim
	 */
	virtual int CheckServiceListsRegistered( _OUT_ bool& flag ) = 0;
	
	/**
	 * @brief Get networks.
	 * @param [out] networks Define networks.
	 * @return Returns 1 if networks is available, otherwise returns 0.
	 * @return When calling method failed returns -1.
	 *
	 *	@paragraph <Example>
	 *	This example will get networks.
	 *	
	 *	@verbatim
	 *	IScanData* pScanData = NULL;
	 *	TVServiceAPI::CreateScanData(&pScanData);
	 *	if(pScanData->GetNetworks(networks) > 0)
	 *	{
	 *		//Do something when operation successful
	 *	}
	 *	@endverbatim
	 */
	virtual int GetNetworks( _OUT_ std::map<unsigned short, t_wstring >& networks) = 0;
	
	/**
	 * @brief Set preferred networks with tvMode .
	 * @param [in] prefereNetworkId Define preferred network id.
	 * @param [in] tvMode Define tvMode.
	 * @return Returns 1 if networks is set, otherwise returns 0.
	 * @return When calling method failed returns -1.
	 *
	 *	@paragraph <Example>
	 *	This example will set preferred networks.
	 *	
	 *	@verbatim
	 *	IScanData* pScanData = NULL;
	 *	TVServiceAPI::CreateScanData(&pScanData);
	 *	if(pScanData->SetPreferredNetwork(preferNetworkId, tvMode) > 0)
	 *	{
	 *		//Do something when operation successful
	 *	}
	 *	@endverbatim
	 */
	virtual int SetPreferredNetwork( _IN_  unsigned short preferNetworkId, _IN_ TSTvMode tvMode) = 0;
	
	/**
	 * @brief Delete networks.
	 * @return Returns 1 if networks is remove, otherwise returns 0.
	 * @return When calling method failed returns -1.
	 *
	 *	@paragraph <Example>
	 *	This example will delete networks.
	 *	
	 *	@verbatim
	 *	IScanData* pScanData = NULL;
	 *	TVServiceAPI::CreateScanData(&pScanData);
	 *	if(pScanData->DeleteNetworks() > 0)
	 *	{
	 *		//Do something when operation successful
	 *	}
	 *	@endverbatim
	 */
	virtual int DeleteNetworks( void ) = 0;

	/**
	 * @brief Get service lists.
	 * @remark Value of country identifier should be compatible with system_info_country_e.
	 * @param [out] serviceLists Define service list.
	 * @param [out] serviceListId Define default id for service list.
	 * @param [in] menuLanguage Define specific language code.
	 * @param [in] country Define specific country.
	 * @return Returns 1 if service lists is available, otherwise returns 0.
	 * @return When calling method failed returns -1.
	 *
	 *	@paragraph <Example>
	 *	This example will get service lists.
	 *	
	 *	@verbatim
	 *	IScanData* pScanData = NULL;
	 *	TVServiceAPI::CreateScanData(&pScanData);
	 *	if(pScanData->GetServiceLists(serviceLists,defaultServiceListsId,menuLanguage,country) > 0)
	 *	{
	 *		//Do something when operation successful
	 *	}
	 *	@endverbatim
	 */
	virtual int GetServiceLists(
			_OUT_ std::map< unsigned short, t_wstring >& serviceLists,
			_OUT_ unsigned short& defaultServiceListId,
			_IN_ ELanguageCode menuLanguage = LANGUAGE_CODE_DIGITAL_MIN,
			_IN_ int country = 0) = 0;

	/**
	 * @brief	  Get available regional service lists from LCNV2 Desc.
	 * @return Returns 1 if regional service lists are available, otherwise returns 0.
	 * @return When calling method failed returns -1.
	 *
	 * 	@paragraph <Example>
	 * 	This example will get regional service lists.
	 *   
	 *	@verbatim
	 * 	IScanData* pScanData = NULL;
	 * 	TVServiceAPI::CreateScanData(&pScanData);
	 * 	std::map<unsigned short, t_wstring > serviceLists;
	 * 	if(pScanData->GetRegionalServiceLists(serviceLists) > 0)
	 * 	{
	 * 		//Do something when operation successful
	 *	}
	 * 	@endverbatim
	 */
	virtual int GetRegionalServiceLists( _OUT_ std::map<unsigned short, t_wstring >& serviceLists ) = 0;

	/**
	 * @brief Set service list.
	 * @param [in] serviceListId Define id for service list.
	 * @return Returns 1 if service list is set, otherwise returns 0.
	 * @return When calling method failed returns -1.
	 *
	 *	@paragraph <Example>
	 *	This example will set service list.
	 *	
	 *	@verbatim
	 *	IScanData* pScanData = NULL;
	 *	TVServiceAPI::CreateScanData(&pScanData);
	 *	if(pScanData->SetServiceList(serviceListId) > 0)
	 *	{
	 *		//Do something when operation successful
	 *	}
	 *	@endverbatim
	 */
	virtual int SetServiceList( _IN_ unsigned short serviceListId ) = 0;

	/**
	 * @brief Set preferred regional service list from LCNV2 Desc.
	 * @param [in] region Selected regional service list.
	 * @return Returns 1 if preferred regional service list is set, otherwise returns 0.
	 * @return When calling method failed returns -1.
	 *
	 *	@paragraph <Example>
	 *	This example will set preferred regional service list.
	 *		 
	 *	@verbatim
	 *	IScanData* pScanData = NULL;
	 *	TVServiceAPI::CreateScanData(&pScanData);
	 *	unsigned short serviceListId;
	 *	if(pScanData->SetRegionalServiceList(serviceListId) > 0)
	 *	{
	 *		//Do something when operation successful
	 *	}
	 *	@endverbatim
	 */
	virtual int SetRegionalServiceList( _IN_ unsigned short serviceListId ) = 0;	
	
	/**
	 * @brief Get services for replacement.
	 * @param [out] services defines sevices for replacement.
	 * @return Returns 1 if services list is available, otherwise returns 0.
	 * @return When calling method failed returns -1.
	 *
	 *	@paragraph <Example>
	 *	This example will get services for replacement.
	 *	
	 *	@verbatim
	 *	IScanData* pScanData = NULL;
	 *	TVServiceAPI::CreateScanData(&pScanData);
	 *	if(pScanData->GetServicesForReplacement(services) > 0)
	 *	{
	 *		//Do something when operation successful
	 *	}
	 *	@endverbatim
	 */
	virtual int GetServicesForReplacement( _OUT_ std::multimap< TCServiceId, std::list< TCServiceId > > &services ) = 0;

	/**
	 * @brief Check services for replacement.
	 * @param [out] flag Defines whether exist service for replacament.
	 * @return Returns 1 if services list flag is available, otherwise returns 0.
	 * @return When calling method failed returns -1.
	 *
	 *	@paragraph <Example>
	 *	This example will check flag of services for replacement.
	 *	
	 *	@verbatim
	 *	IScanData* pScanData = NULL;
	 *	TVServiceAPI::CreateScanData(&pScanData);
	 *	if(pScanData->CheckServicesForReplacement(flag) > 0)
	 *	{
	 *		//Do something when operation successful
	 *	}
	 *	@endverbatim
	 */
	virtual int CheckServicesForReplacement( _OUT_ bool& flag ) = 0;

	/**
	 * @brief Check scan active.
	 * @param [out] flag Defines state of scanning. 
	 * @return Returns 1 if scan active flag is available, otherwise returns 0.
	 * @return When calling method failed returns -1.
	 *
	 *	@paragraph <Example>
	 *	This example will check activation flag of scannig.
	 *	
	 *	@verbatim
	 *	IScanData* pScanData = NULL;
	 *	TVServiceAPI::CreateScanData(&pScanData);
	 *	if(pScanData->CheckScanActive(flag) > 0)
	 *	{
	 *		//Do something when operation successful
	 *	}
	 *	@endverbatim
	 */
	virtual int CheckScanActive( _OUT_ bool& flag ) = 0;
	
	/**
	 * @brief Check manual scan performed.
	 * @param [in] tvMode Defines current TV mode. 
	 * @param [out] flag Defines last perform mode of scanning. 
	 * @return Returns 1 if scan manual scan flag is available, otherwise returns 0.
	 * @return When calling method failed returns -1.
	 *
	 *	@paragraph <Example>
	 *	This example will check activation flag of manual scannig.
	 *	
	 *	@verbatim
	 *	IScanData* pScanData = NULL;
	 *	TVServiceAPI::CreateScanData(&pScanData);
	 *	if(pScanData->CheckManualScanPerformed(tvMode,flag) > 0)
	 *	{
	 *		//Do something when operation successful
	 *	}
	 *	@endverbatim
	 */
	virtual int CheckManualScanPerformed( _IN_ TSTvMode tvMode, _OUT_ bool& flag ) = 0;
	
	/**
	 * @brief Get target sub regions.
	 * @param [in] parentRegion  Defines the ID of the parent region we wish to find the available sub-regions.                    
	 * @param [out] subRegions Defines regions map of ID to name for all available sub-regions.
	 * @return Returns 1 if target sub regions is available, otherwise returns 0.
	 * @return When calling method failed returns -1.
	 *
	 *	@paragraph <Example>
	 *	This example will get target sub regions.
	 *	
	 *	@verbatim
	 *	IScanData* pScanData = NULL;
	 *	TVServiceAPI::CreateScanData(&pScanData);
	 *	if(pScanData->GetTargetSubRegions(parentRegion,subRegions) > 0)
	 *	{
	 *		//Do something when operation successful
	 *	}
	 *	@endverbatim
	 */
	virtual int GetTargetSubRegions( _IN_  unsigned int parentRegion, _OUT_  std::map<unsigned int, t_wstring >& subRegions ) = 0;
	
	/**
	 * @brief Get interactive storage allocations.
	 * @param [in,out] groupAlloc Defines reference to a map of service group ID to allocation block size (in bytes).                         
	 * @param [in,out] serviceAllocReference Defines reference to a map of service ID to allocation block size (in bytes).
	 * @return Returns 1 if storage allocations is available, otherwise returns 0.
	 * @return When calling method failed returns -1.
	 *
	 *	@paragraph <Example>
	 *	This example will get interactive storage allocations.
	 *	
	 *	@verbatim
	 *	IScanData* pScanData = NULL;
	 *	TVServiceAPI::CreateScanData(&pScanData);
	 *	if(pScanData->GetInteractiveStorageAllocations(groupAlloc,serviceAlloc) > 0)
	 *	{
	 *		//Do something when operation successful
	 *	}
	 *	@endverbatim
	 */
	virtual int GetInteractiveStorageAllocations( _INOUT_  std::map< unsigned short, unsigned int >& groupAlloc, _INOUT_  std::map< unsigned short, unsigned int >& serviceAlloc ) = 0;
	
	/**
	 * @brief Set post code.
	 * @param [in] postCode Defines post code.
	 * @return Returns 1 if post code was set, otherwise returns 0.
	 * @return When calling method failed returns -1.
	 *
	 *	@paragraph <Example>
	 *	This example will set post code.
	 *	
	 *	@verbatim
	 *	IScanData* pScanData = NULL;
	 *	TVServiceAPI::CreateScanData(&pScanData);
	 *	if(pScanData->SetPostCode(postCode) > 0)
	 *	{
	 *		//Do something when operation successful
	 *	}
	 *	@endverbatim
	 */
	virtual int SetPostCode( _IN_ const std::string& postCode ) = 0;
	
	/**
	 * @brief Get post code.
	 * @param [out] postCode Defines post code.
	 * @return Returns 1 if post code is get, otherwise returns 0.
	 * @return When calling method failed returns -1.
	 *
	 *	@paragraph <Example>
	 *	This example will get post code.
	 *	
	 *	@verbatim
	 *	IScanData* pScanData = NULL;
	 *	TVServiceAPI::CreateScanData(&pScanData);
	 *	if(pScanData->GetPostCode(postCode) > 0)
	 *	{
	 *		//Do something when operation successful
	 *	}
	 *	@endverbatim
	 */
	virtual int GetPostCode(  _OUT_ std::string& postCode ) = 0;

	/**
	 * @brief Verify post code.
	 * @param [in] postCode Defines post code.
	 * @return Returns 1 if post code is available, otherwise returns 0.
	 * @return When calling method failed returns -1.
	 *
	 *	@paragraph <Example>
	 *	This example will verify post code.
	 *	
	 *	@verbatim
	 *	IScanData* pScanData = NULL;
	 *	TVServiceAPI::CreateScanData(&pScanData);
	 *	if(pScanData->VerifyPostCode(postCode) > 0)
	 *	{
	 *		//Do something when operation successful
	 *	}
	 *	@endverbatim
	 */
	virtual int VerifyPostCode( _IN_ const std::string& postCode ) = 0;

	/**
	 * @brief Check if there are missing transponders cached.
	 * @remark Currently used only for Digiturk
	 * @param [out] flag Defines if there are some missing transponders cached.
	 * @return Returns 1 if calling method was successful.
	 * @return When calling method failed returns -1.
	 *
	 *	@paragraph <Example>
	 *	This example will check if there are missing transponders cached.
	 *	
	 *	@verbatim
	 *	IScanData* pScanData = NULL;
	 *	TVServiceAPI::CreateScanData(&pScanData);
	 *
	 *	bool flag;
	 *	if(pScanData->CheckMissingTranspondersFound(flag) > 0)
	 *	{
	 *		if(flag)
	 *		{
	 *			// there are missing transponders cached
	 *		}
	 *		else
	 *		{
	 *			// no missing transponders cached
	 *		}
	 *	}
	 *	@endverbatim
	 */
	virtual int CheckMissingTranspondersFound( _OUT_ bool& found ) = 0;

	/**
	 * @brief Fetch information about color system settings of currently tuned analog service
	 * @remarks This functionality is only for analog TV
	 * @param [out] mode color system mode of currently tuned analog service
	 * @param [out] value color system of currently tuned analog service
 	 * @return Returns 1 if calling method was successful.
	 * @return When calling method failed returns -1.
	 *
	 *	@paragraph <Example>
	 *	This example will get color system for currently tuned analog service.
	 *
	 *	@verbatim
	 *	IScanData* pScanData = NULL;
	 *	TVServiceAPI::CreateScanData(&pScanData);
	 *	if(pScanData->GetColorSystem(mode, value) > 0)
	 *	{
	 *		//Do something when operation successful
	 *	}
	 *	@endverbatim
	 */
	virtual int GetColorSystem(_OUT_ EChannelColorSystem& mode, _OUT_ EChannelColor& value) = 0;

	/**
	 * @brief Set information of color system settings for currently tuned analog service
	 * @remarks This functionality is only for analog TV
	 * @param [in] mode color system mode to set for currently tuned analog service
	 * @param [in] value color system to set for currently tuned analog service
 	 * @return Returns 1 if calling method was successful.
	 * @return When calling method failed returns -1.
	 *
	 *	@paragraph <Example>
	 *	This example will set color system for currently tuned analog service.
	 *
	 *	@verbatim
	 *	IScanData* pScanData = NULL;
	 *	TVServiceAPI::CreateScanData(&pScanData);
	 *	if(pScanData->SetColorSystem(mode, value) > 0)
	 *	{
	 *		//Do something when operation successful
	 *	}
	 *	@endverbatim
	 */
	virtual int SetColorSystem(_IN_ EChannelColorSystem mode, _IN_ EChannelColor value) = 0;

	/**
	 * @brief Fetch information about sound system settings of currently tuned analog service
	 * @remarks This functionality is only for analog TV
	 * @param [out] mode sound system mode of currently tuned analog service
	 * @param [out] value sound system of currently tuned analog service
 	 * @return Returns 1 if calling method was successful.
	 * @return When calling method failed returns -1.
	 *
	 *	@paragraph <Example>
	 *	This example will get sound system for currently tuned analog service.
	 *
	 *	@verbatim
	 *	IScanData* pScanData = NULL;
	 *	TVServiceAPI::CreateScanData(&pScanData);
	 *	if(pScanData->GetSoundSystem(mode, value) > 0)
	 *	{
	 *		//Do something when operation successful
	 *	}
	 *	@endverbatim
	 */
	virtual int GetSoundSystem(_OUT_ EChannelSoundSystem& mode, _OUT_ EChannelSound& value) = 0;

	/**
	 * @brief Set information of sound system settings for currently tuned analog service
	 * @remarks This functionality is only for analog TV
	 * @param [in] mode sound system mode to set for currently tuned analog service
	 * @param [in] value sound system to set for currently tuned analog service
 	 * @return Returns 1 if calling method was successful.
	 * @return When calling method failed returns -1.
	 *
	 *	@paragraph <Example>
	 *	This example will set sound system for currently tuned analog service.
	 *
	 *	@verbatim
	 *	IScanData* pScanData = NULL;
	 *	TVServiceAPI::CreateScanData(&pScanData);
	 *	if(pScanData->SetSoundSystem(mode, value) > 0)
	 *	{
	 *		//Do something when operation successful
	 *	}
	 *	@endverbatim
	 */
	virtual int SetSoundSystem(_IN_ EChannelSoundSystem mode, _IN_ EChannelSound value) = 0;
};

#endif // _ISCANDATA_H_
