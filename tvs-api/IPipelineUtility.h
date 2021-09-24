/** 
 * @file IPipelineUtility.h
 * @brief Application interface for informations related to pipeline.
 *
 * Copyright 2014 by Samsung Electronics, Inc.,
 * 
 * This software is the confidential and proprietary information
 * of Samsung Electronics, Inc. ("Confidential Information"). You
 * shall not disclose such Confidential Information and shall use
 * it only in accordance with the terms of the license agreement
 * you entered into with Samsung.
 */

#ifndef _IPIPELINEUTILITY_H_
#define _IPIPELINEUTILITY_H_


#include <string>

#include "MarshallingMarks.h"
#include "PipelineUtilityDataType.h"
#include "UtilDataType.h"
#include "ServiceData.h"

class IPipelineUtility
{
protected:
	virtual ~IPipelineUtility(){};

public:
	/**
	 * @brief Get stream time.
	 * @param [out] streamTime Stream time given in seconds.
	 * @return Returns 1 if fetched stream time is correct, otherwise returns 0.
	 * @return When calling method failed returns -1.
	 *
	 *	@paragraph <Example>
	 *	This code will get stream time for MAIN profile and screen=0.
	 *	
	 *	@verbatim
	 *	IPipelineUtility* pPipelineUtility;
	 *	TVServiceAPI::CreatePipelineUtility(PROFILE_TYPE_MAIN, 0, pPipelineUtility);
	 *	unsigned long streamTime = 0;
	 *	if(pPipelineUtility->GetStreamTime(streamTime) > 0)
	 *	{
	 *		//Time obtained successfully
	 *	}
	 *	@endverbatim
	 */
	virtual int GetStreamTime(_OUT_ unsigned long& streamTime) = 0;

	/**
	 * @brief Get DST flag.
	 * @return Returns 1 if DST flag is set, otherwise returns 0.
	 * @return When calling method failed returns -1.
	 *
	 *	@paragraph <Example>
	 *	This code will get DST flag for MAIN profile and screen=0.
	 *	
	 *	@verbatim
	 *	IPipelineUtility* pPipelineUtility;
	 *	TVServiceAPI::CreatePipelineUtility(PROFILE_TYPE_MAIN, 0, pPipelineUtility);
	 *	if(pPipelineUtility->FlagStreamDST())
	 *	{
	 *		//DST flag is set
	 *	}
	 *	@endverbatim
	 */
	virtual int FlagStreamDST(void) = 0;

	/**
	 * @brief Gets information about current time offset, when next change of time will happen and what will be next time offset.
	 * @remarks This information is only available for DVB from TOT tables in stream.
	 * @remarks For example time offset changes with summer/winter time change.
	 * @remarks Time offset is difference between local time and UTC-time.
	 * @param [out] timeOfTimeChange Next moment in time when time offset will change.
	 * @param [out] nextTimeOffset Time offset that is valid after timeOfTimeChange.
	 * @param [out] currentTimeOffset  Time offset that is valid before timeOfTimeChange.
	 * @return Returns 1 when information was obtained successfully, otherwise returns 0.
	 * @return When calling method failed returns -1.
	 *
	 *	@paragraph <Example>
	 *	This example shows how to obtain information about current time offset, when time offset will change and what next value will be.
	 *	 
	 *	@verbatim
	 *	IPipelineUtility* pPipelineUtility;
	 *	TVServiceAPI::CreatePipeline(DEFAULT_PROFILE_TYPE, DEFAULT_SCREEN_ID, &pPipelineUtility);
	 *
	 *	unsigned long timeOffsetChange;
	 *	int nextTimeOffset;
	 *	int currentTimeOffset;
	 *	if( pPipelineUtility->GetTimeOffset( timeOffsetChange, nextTimeOffset, currentTimeOffset ) > 0 )
	 *	{
	 *		// use obtained values
	 *	}
	 *	@endverbatim
	 */
	virtual int GetTimeOffset(_OUT_ unsigned long& timeOfTimeChange, _OUT_ int& nextTimeOffset, _OUT_ int& currentTimeOffset) = 0;
	
	/**
	 * @brief Checks whether this pipeline is available(can set source).
	 * @param [out] check Checking result.
	 * @return Returns 1 if information was acquired, otherwise returns 0.
	 * @return When calling method failed returns -1.
	 *
	 *	@paragraph <Example>
	 *	This code will check if pipeline for PROFILE_TYPE_MAIN and subId=0 is available.
	 *	
	 *	@verbatim
	 *	IPipelineUtility* pPipelineUtility;
	 *	TVServiceAPI::CreatePipeline(PROFILE_TYPE_MAIN, 0, &pPipelineUtility);
	 *	bool status;
	 *	if(pPipelineUtility->CheckPipelineAvailable(status) > 0)
	 *	{
	 *		//Success
	 *	}
	 *	@endverbatim
	 */
	virtual int CheckPipelineAvailable(_OUT_ bool& available) = 0;


	/**
	 * @brief Notify TVS about application/receiver readiness (or not) to something TVS state change. 
	 * @remarks Application must be registered to the specific state change in TVS
	 * @param [in] state Defines state change type.
	 * @param [in] receiverId Application Id.
	 * @param [in] ready Specify if application is ready on state change.
	 * @param [in] serviceId ServiceId as a token (for synchronisation).
	 * @return Returns 1 when notification was accepted, otherwise returns 0.
	 * @return When calling method failed returns -1.
	 *
	 *	@paragraph <Example>
	 *	This example shows how to notify TVS about readiness to source change.
	 *	 
	 *	@verbatim
	 *	IPipelineUtility* pPipelineUtility;
	 *	TVServiceAPI::CreatePipeline(DEFAULT_PROFILE_TYPE, DEFAULT_SCREEN_ID, &pPipelineUtility);
	 *
	 *	std::string receiverId("tv-viewer");
	 *	TCServiceId serviceId = 1234567890;
	 *	if( pPipelineUtility->NotifyReceiverState( STATE_CHANGE_SOURCE, receiverId, true, serviceId ) > 0 )
	 *	{
	 *		// notification was accepted
	 *	}
	 *	@endverbatim
	 */
	virtual int NotifyReceiverState( _IN_ EStateChange state,  const _IN_ std::string& receiverId, _IN_ bool ready, const _IN_ TCServiceId& serviceId = INVALID_SERVICE_ID ) = 0;

	/**
	 * @brief Register for TVS state change. 
	 * @param [in] state Defines state change type.
	 * @param [in] receiverId Application Id.
	 * @param [in] useTimeout Specify if TVS can ignore application when timeout occures.
	 * @return Returns 1 when application was registered, otherwise returns 0.
	 * @return When calling method failed returns -1.
	 *
	 *	@paragraph <Example>
	 *	This example shows how to register for service change.
	 *	 
	 *	@verbatim
	 *	IPipelineUtility* pPipelineUtility;
	 *	TVServiceAPI::CreatePipeline(DEFAULT_PROFILE_TYPE, DEFAULT_SCREEN_ID, &pPipelineUtility);
	 *
	 *	std::string receiverId("tv-viewer");
	 *	TCServiceId serviceId = 1234567890;
	 *	if( pPipelineUtility->RegisterForStateChange( STATE_CHANGE_SERVICE, receiverId, false ) > 0 )
	 *	{
	 *		// notification was accepted
	 *	}
	 *	@endverbatim
	 */
	virtual int RegisterForStateChange( _IN_ EStateChange state,  const _IN_ std::string& receiverId, _IN_ bool useTimeout = false ) = 0;

	/**
	 * @brief Unregister from TVS state change. 
	 * @param [in] state Defines state change type.
	 * @param [in] receiverId Application Id.
	 * @return Returns 1 when application was unregistered, otherwise returns 0.
	 * @return When calling method failed returns -1.
	 *
	 *	@paragraph <Example>
	 *	This example shows how to unregister from service change.
	 *	 
	 *	@verbatim
	 *	IPipelineUtility* pPipelineUtility;
	 *	TVServiceAPI::CreatePipeline(DEFAULT_PROFILE_TYPE, DEFAULT_SCREEN_ID, &pPipelineUtility);
	 *
	 *	std::string receiverId("tv-viewer");
	 *	TCServiceId serviceId = 1234567890;
	 *	if( pPipelineUtility->UnregisterFromStateChange( STATE_CHANGE_SERVICE, receiverId ) > 0 )
	 *	{
	 *		// notification was accepted
	 *	}
	 *	@endverbatim
	 */
	virtual int UnregisterFromStateChange( _IN_ EStateChange state,  const _IN_ std::string& receiverId ) = 0;

	virtual int GetCurrentTPMSStatus(_OUT_ TCTPMSStatus& status) = 0;

	/**
	 * @brief It checks if SIGNAL_CAS_PID_SET_DONE signal was sent already. The signal is sent when all A/V pids are set for a given service.
	 * @param [out] done true if AV pids are set. Otherwise false.
	 * @return Returns 1 if status is correct, otherwise returns 0.
	 * @return When calling method failed returns -1.
	 *
	 *	@paragraph <Example>
	 *	 
	 *	@verbatim
	 *	IPipelineUtility* pPipelineUtility;
	 *	TVServiceAPI::CreatePipeline(DEFAULT_PROFILE_TYPE, DEFAULT_SCREEN_ID, &pPipelineUtility);
	 *
	 *	bool done;
	 *	if( pPipelineUtility->GetPIDSetStatus( done ) > 0 )
	 *	{
	 *		// notification was accepted
	 *	}
	 *	@endverbatim
	 */
	virtual int GetPIDSetStatus(_OUT_ bool & done) = 0;
};

#endif // _IPIPELINEUTILITY_H_

