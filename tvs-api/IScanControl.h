/** 
 * @file IScanControl.h
 * @brief Application interface for control scanning.
 *
 * Copyright 2013 by Samsung Electronics, Inc.,
 * 
 * This software is the confidential and proprietary information
 * of Samsung Electronics, Inc. ("Confidential Information"). You
 * shall not disclose such Confidential Information and shall use
 * it only in accordance with the terms of the license agreement
 * you entered into with Samsung.
 */

	
#ifndef _ISCANCONTROL_H_
#define _ISCANCONTROL_H_

#include <list>

#include "MarshallingMarks.h"
#include "ScanDataDataType.h"
#include "ServiceData.h"


class IScanControl
{

protected:
	virtual ~IScanControl(){};

public:

	/**
	 * @brief Start auto scan.
	 * @return Returns 1 if channel scanning has stopped, otherwise returns 0.
	 * @return When calling method failed returns -1.
	 *
	 *	@paragraph <Example>
	 *	This example will start procedure of scanning channels.
	 *	
	 *	@verbatim
	 *	IScanData* pScanData = NULL;
	 *	TVServiceAPI::CreateScanData(&pScanData);
	 *	IScanControl* pScanControl = NULL;
	 *	TVServiceAPI::CreateScanControl(&pScanControl);
	 *	EScanMode scanMode = SCAN_MODE_AIR_CABLE;
	 *	TSScanInfo info;
	 *	pScanData->GetScanInfo( scanMode, info);
	 *	if(pScanControl->StartAutoScan() > 0)
	 *	{
	 *		//Do something when operation successful
	 *	}
	 *	@endverbatim
	 */
	virtual int StartAutoScan( void ) = 0;
	
	/**
	 * @brief Stop auto scan.
	 * @param [in] force Defines kind of stop scanning.
	 * @return Returns 1 if channel scanning has started, otherwise returns 0.
	 * @return When calling method failed returns -1.
	 *
	 *	@paragraph <Example>
	 *	This example will stop procedure of scanning channels.
	 *	
	 *	@verbatim
	 *	IScanControl* pScanControl = NULL;
	 *	TVServiceAPI::CreateScanControl(&pScanControl);
	 *	if(pScanControl->StopAutoScan() > 0)
	 *	{
	 *		//Do something when operation successful
	 *	}
	 *	@endverbatim
	 */
	virtual int StopAutoScan( bool force = false ) = 0;
	
	/**
	 * @brief Pause auto scan.
	 * @return Returns 1 if channel scanning has started, otherwise returns 0.
	 * @return When calling method failed returns -1.
	 *
	 *	@paragraph <Example>
	 *	This example will pause procedure of scanning channels.
	 *	
	 *	@verbatim
	 *	IScanControl* pScanControl = NULL;
	 *	TVServiceAPI::CreateScanControl(&pScanControl);
	 *	if(pScanControl->PauseAutoScan() > 0)
	 *	{
	 *		//Do something when operation successful
	 *	}
	 *	@endverbatim
	 */
	virtual int PauseAutoScan( void ) = 0;
	
	/**
	 * @brief Resume auto scan.
	 * @return Returns 1 if channel scanning has paused, otherwise returns 0.
	 * @return When calling method failed returns -1.
	 *
	 *	@paragraph <Example>
	 *	This example will resume procedure of scanning channels.
	 *	
	 *	@verbatim
	 *	IScanControl* pScanControl = NULL;
	 *	TVServiceAPI::CreateScanControl(&pScanControl);
	 *	if(pScanControl->ResumeAutoScan() > 0)
	 *	{
	 *		//Do something when operation successful
	 *	}
	 *	@endverbatim
	 */
	virtual	int ResumeAutoScan( void ) = 0;
	
	/**
	 * @brief Activate manual analog scanning.
	 * @return Returns 1 if activation was successfull, otherwise returns 0.
	 * @return When calling method failed returns -1.
	 *
	 *	@paragraph <Example>
	 *	This example will activate manual analog scanning.
	 *	
	 *	@verbatim
	 *	IScanControl* pScanControl = NULL;
	 *	TVServiceAPI::CreateScanControl(&pScanControl);
	 *	if(pScanControl->ActivateManualAnalogScan() > 0)
	 *	{
	 *		//Do something when operation successful
	 *	}
	 *	@endverbatim
	 */
	virtual int ActivateManualAnalogScan( void ) = 0;
	
	/**
	 * @brief Deactivate manual analog scanning.
	 * @return Returns 1 if deactivation was successfull, otherwise returns 0.
	 * @return When calling method failed returns -1.
	 *
	 *	@paragraph <Example>
	 *	This example will deactivate manual analog scanning.
	 *	
	 *	@verbatim
	 *	IScanControl* pScanControl = NULL;
	 *	TVServiceAPI::CreateScanControl(&pScanControl);
	 *	if(pScanControl->DeactivateManualAnalogScan() > 0)
	 *	{
	 *		//Do something when operation successful
	 *	}
	 *	@endverbatim
	 */
	virtual int DeactivateManualAnalogScan( void ) = 0;
	
	/**
	 * @brief Start manual scanning.
	 * @param [in] service Defines channel.
	 * @return Returns 1 if channel scanning has stopped, otherwise returns 0.
	 * @return When calling method failed returns -1.
	 *
	 *	@paragraph <Example>
	 *	This example will start manual scanning.
	 *	
	 *	@verbatim
	 *	IScanControl* pScanControl = NULL;
	 *	TVServiceAPI::CreateScanControl(&pScanControl);
	 *	if(pScanControl->StartManualScan(scanChannel) > 0)
	 *	{
	 *		//Do something when operation successful
	 *	}
	 *	@endverbatim
	 */
	virtual int StartManualScan( _IN_ const TSScanChannel& scanChannel ) = 0;

	/**
	 * @brief Stop manual scanning.
	 * @return Returns 1 if channel scanning has started, otherwise returns 0.
	 * @return When calling method failed returns -1.
	 *
	 *	@paragraph <Example>
	 *	This example will stop manual scanning.
	 *	
	 *	@verbatim
	 *	IScanControl* pScanControl = NULL;
	 *	TVServiceAPI::CreateScanControl(&pScanControl);
	 *	if(pScanControl->StopManualScan() > 0)
	 *	{
	 *		//Do something when operation successful
	 *	}
	 *	@endverbatim
	 */
	virtual int StopManualScan( void ) = 0;
	
	/**
	 * @brief Pause manual scanning.
	 * @return Returns 1 if channel scanning has started, otherwise returns 0.
	 * @return When calling method failed returns -1.
	 *
	 *	@paragraph <Example>
	 *	This example will pause manual scanning.
	 *	
	 *	@verbatim
	 *	IScanControl* pScanControl = NULL;
	 *	TVServiceAPI::CreateScanControl(&pScanControl);
	 *	if(pScanControl->PauseManualScan() > 0)
	 *	{
	 *		//Do something when operation successful
	 *	}
	 *	@endverbatim
	 */
	virtual int PauseManualScan( void ) = 0;
	
	/**
	 * @brief Resume manual scanning.
	 * @return Returns 1 if channel scanning has paused, otherwise returns 0.
	 * @return When calling method failed returns -1.
	 *
	 *	@paragraph <Example>
	 *	This example will resume manual scanning.
	 *	
	 *	@verbatim
	 *	IScanControl* pScanControl = NULL;
	 *	TVServiceAPI::CreateScanControl(&pScanControl);
	 *	if(pScanControl->ResumeManualScan() > 0)
	 *	{
	 *		//Do something when operation successful
	 *	}
	 *	@endverbatim
	 */
	virtual int ResumeManualScan( void ) = 0;

	/**
	 * @brief Store service found during manual analog scan.
	 * @return Returns 1 if storing service went successfull, otherwise returns 0.
	 * @return When calling method failed returns -1.
	 *
	 *	@paragraph <Example>
	 *	This example will store service for manual analog scanning.
	 *	
	 *	@verbatim
	 *	IScanControl* pScanControl = NULL;
	 *	TVServiceAPI::CreateScanControl(&pScanControl);
	 *	unsigned short major = 1;
	 *	if(pScanControl->StoreServiceForManualAnalogScan(major) > 0)
	 *	{
	 *		//Do something when operation successful
	 *	}
	 *	@endverbatim
	 */
	virtual int StoreServiceForManualAnalogScan( _IN_ unsigned short major ) = 0;

	/**
	 * @brief Start homing channel scanning.
	 * @param [in] homingCandidates Defines homing candidates.
	 * @param [in] profileId ID of a TV profile.
	 * @param [in] subId ID of a TV screen.
	 * @return Returns 1 if channel scanning has stopped, otherwise returns 0.
	 * @return When calling method failed returns -1.
	 *
	 *	@paragraph <Example>
	 *	This example will start homing channel scanning.
	 *	
	 *	@verbatim
	 *	IScanControl* pScanControl = NULL;
	 *	TVServiceAPI::CreateScanControl(&pScanControl);
	 *	std::vector<TSHomingChannelLocator> homingCandidates;
	 *
	 *	if(pScanControl->StartHomingChannelSearch(homingCandidates) > 0)
	 *	{
	 *		//Do something when operation successful
	 *	}
	 *	@endverbatim
	 */
	virtual int StartHomingChannelSearch( _IN_ const std::vector<TSHomingChannelLocator>& homingCandidates, _IN_ EProfile profileId = DEFAULT_PROFILE_TYPE, _IN_ unsigned short subId = DEFAULT_SCREEN_ID ) = 0;
	
	/**
	 * @brief Stop homing channel scanning.
	 * @param [in] force Defines kind of stop homing scanning.
	 * @param [in] profileId ID of a TV profile.
	 * @param [in] subId ID of a TV screen.
	 * @return Returns 1 if channel scanning has started, otherwise returns 0.
	 * @return When calling method failed returns -1.
	 *
	 *	@paragraph <Example>
	 *	This example will stop homing channel scanning.
	 *	
	 *	@verbatim
	 *	IScanControl* pScanControl = NULL;
	 *	TVServiceAPI::CreateScanControl(&pScanControl);
	 *	if(pScanControl->StopHomingChannelSearch() > 0)
	 *	{
	 *		//Do something when operation successful
	 *	}
	 *	@endverbatim
	 */
	virtual int StopHomingChannelSearch( _IN_ bool force, _IN_ EProfile profileId = DEFAULT_PROFILE_TYPE, _IN_ unsigned short subId = DEFAULT_SCREEN_ID ) = 0;
	
	/**
	 * @brief Pause homing channel scanning.
	 * @param [in] profileId ID of a TV profile.
	 * @param [in] subId ID of a TV screen.
	 * @return Returns 1 if channel scanning has started, otherwise returns 0.
	 * @return When calling method failed returns -1.
	 *
	 *	@paragraph <Example>
	 *	This example will pause homing channel scanning.
	 *	
	 *	@verbatim
	 *	IScanControl* pScanControl = NULL;
	 *	TVServiceAPI::CreateScanControl(&pScanControl);
	 *	if(pScanControl->PauseHomingChannelSearch() > 0)
	 *	{
	 *		//Do something when operation successful
	 *	}
	 *	@endverbatim
	 */
	virtual int PauseHomingChannelSearch( _IN_ EProfile profileId = DEFAULT_PROFILE_TYPE, _IN_ unsigned short subId = DEFAULT_SCREEN_ID ) = 0;
	
	/**
	 * @brief Resume homing channel scanning.
	 * @param [in] profileId ID of a TV profile.
	 * @param [in] subId ID of a TV screen.
	 * @return Returns 1 if channel scanning has paused, otherwise returns 0.
	 * @return When calling method failed returns -1.
	 *
	 *	@paragraph <Example>
	 *	This example will resume homing channel scanning.
	 *	
	 *	@verbatim
	 *	IScanControl* pScanControl = NULL;
	 *	TVServiceAPI::CreateScanControl(&pScanControl);
	 *	if(pScanControl->ResumeHomingChannelSearch() > 0)
	 *	{
	 *		//Do something when operation successful
	 *	}
	 *	@endverbatim
	 */
	virtual int ResumeHomingChannelSearch( _IN_ EProfile profileId = DEFAULT_PROFILE_TYPE, _IN_ unsigned short subId = DEFAULT_SCREEN_ID ) = 0;

	/**
	 * @brief Start clear scramble services.
	 * @param [in] channelType Defines channel type.
	 * @return Returns 1 if channel scanning has started, otherwise returns 0.
	 * @return When calling method failed returns -1.
	 *
	 *	@paragraph <Example>
	 *	This example will start procedure of search scrambled channels.
	 *	
	 *	@verbatim
	 *	IScanControl* pScanControl = NULL;
	 *	EChannelType = CHANNEL_TYPE_CDTV;
	 *	TVServiceAPI::CreateScanControl(&pScanControl);
 	 *	if(pScanControl->StartClearScramble(channelType) > 0)
	 *	{
	 *		//Do something when operation successful
	 *	}
	 *	@endverbatim
	 */
	virtual int StartClearScramble( _IN_  EChannelType channelType ) = 0;
	
	/**
	 * @brief Stop clear scramble services.
	 * @return Returns 1 if channel scanning has stopped, otherwise returns 0.
	 * @return When calling method failed returns -1.
	 *
	 *	@paragraph <Example>
	 *	This example will stop procedure of search scrambled channels.
	 *	
	 *	@verbatim
	 *	IScanControl* pScanControl = NULL;
	 *	TVServiceAPI::CreateScanControl(&pScanControl);
  	 *	if(pScanControl->StopClearScramble() > 0)
	 *	{
	 *		//Do something when operation successful
	 *	}
	 *	@endverbatim
	 */
	virtual int StopClearScramble( void ) = 0;
	
	/**
	 * @brief Pause clear scramble services.
	 * @return Returns 1 if channel scanning has stopped, otherwise returns 0.
	 * @return When calling method failed returns -1.
	 *
	 *	@paragraph <Example>
	 *	This example will pause procedure of search scrambled channels.
	 *	
	 *	@verbatim
	 *	IScanControl* pScanControl = NULL;
	 *	TVServiceAPI::CreateScanControl(&pScanControl);
   	 *	if(pScanControl->PauseClearScramble() > 0)
	 *	{
	 *		//Do something when operation successful
	 *	}
	 *	@endverbatim
	 */
	virtual int PauseClearScramble( void ) = 0;
	
	/**
	 * @brief Resume clear scramble services.
	 * @return value different from zero if successed, zero if not.
	 * @return When calling method failed returns -1.
	 *
	 *	@paragraph <Example>
	 *	This example will resume procedure of search scrambled channels.
	 *	
	 *	@verbatim
	 *	IScanControl* pScanControl = NULL;
	 *	TVServiceAPI::CreateScanControl(&pScanControl);
     *	if(pScanControl->ResumeClearScramble() > 0)
	 *	{
	 *		//Do something when operation successful
	 *	}
	 *	@endverbatim
	 */
	virtual int ResumeClearScramble( void ) = 0;

};

#endif // _ISCANCONTROL_H_