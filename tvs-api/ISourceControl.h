/** 
 * @file ISourceControl.h
 * @brief Application interface for controlling source.
 *
 * Copyright 2013 by Samsung Electronics, Inc.,
 * 
 * This software is the confidential and proprietary information
 * of Samsung Electronics, Inc. ("Confidential Information"). You
 * shall not disclose such Confidential Information and shall use
 * it only in accordance with the terms of the license agreement
 * you entered into with Samsung.
 */


#ifndef _ISOURCECONTROL_H_
#define _ISOURCECONTROL_H_

#include <list>
#include <map>
#include <string>
#include "MarshallingMarks.h"
#include "SourceControlDataType.h"
#include "ServiceData.h"

class ISourceControl
{
protected:
	virtual ~ISourceControl(){};

public:

	/**
	 * @brief Sets current source to selected one.
	 * @param [in] sourceType Type of source.
	 * @param [in] appID application ID that calls this API
	 * @return Returns 1 if source type was successfully set, otherwise returns 0.
	 * @return When calling method failed returns -1.
	 *
	 *	@paragraph <Example>
	 *	This code will set source to DTV for MAIN profile type and screenId = 0.
	 *	
	 *	@verbatim
	 *	ISourceControl* sourceCtrl;
	 *	TVServiceAPI::CreateSourceControl(PROFILE_TYPE_MAIN, 0, &sourceCtrl);
	 *	ESource source = SOURCE_TYPE_DTV;
	 *	if(sourceCtrl->SetSource(source) > 0)
	 *	{
	 *		//Source was successfully set
	 *	}
	 *	@endverbatim
	 */
	virtual int SetSource(_IN_ ESource sourceType, _IN_ const std::string& appID = std::string()) = 0;
	
	/**
	 * @brief Sets current source to selected one and sets current service.
	 * @param [in] sourceType Type of source.
	 * @param [in] serviceId ID of a service.
	 * @param [in] appID application ID that calls this API
	 * @return Returns 1 if source type and current service were successfully set, otherwise returns 0.
	 * @return When calling method failed returns -1.
	 *
	 *	@paragraph <Example>
	 *	This code will set source to DTV for MAIN profile type and screenId = 0. It will also set service to service with ID = 845524458537987.
	 *	
	 *	@verbatim
	 *	ISourceControl* sourceCtrl;
	 *	TCServiceId serviceId = 845524458537987;
	 *	TVServiceAPI::CreateSourceControl(PROFILE_TYPE_MAIN, 0, &sourceCtrl);
	 *	ESource source = SOURCE_TYPE_DTV;
	 *	if(sourceCtrl->SetSource(source, serviceId) > 0)
	 *	{
	 *		//Source and current service were successfully set
	 *	}
	 *	@endverbatim
	 */
	virtual int SetSource(_IN_ ESource sourceType, _IN_ TCServiceId serviceId, _IN_ const std::string& appID = std::string()) = 0;


	/**
	 * @brief Sets SHMSink attribute (related to multi view feature).
	 * @param [in] attribute SHMSink attribute to be set.
	 * @return Returns 1 if source type and current service were successfully set, otherwise returns 0.
	 * @return When calling method failed returns -1.
	 *
	 *	@paragraph <Example>
	 *	This code will set source to DTV for MAIN profile type and screenId = 0. It will also set service to service with ID = 845524458537987.
	 *	
	 *	@verbatim
	 *	ISourceControl* sourceCtrl;
	 *	TVSHMSinkAttr attribute;
	 *	if(sourceCtrl->SetSHMSinkAttribute(attribute) > 0)
	 *	{
	 *		//Source and current service were successfully set
	 *	}
	 *	@endverbatim
	 */
	virtual int SetSHMSinkAttribute(const _IN_ TVSHMSinkAttr& attribute) = 0;


	/**
	 * @brief Deactivate source to selected handle.
	 * @param None
	 * @return Returns 1 if source type was successfully deactivated, otherwise returns 0.
	 * @return When calling method failed returns -1.
	 *
	 *	@paragraph <Example>
	 *	This code will deactivate source to DTV for MAIN profile type and screenId = 0.
	 *	
	 *	@verbatim
	 *	ISourceControl* sourceCtrl;
	 *	TVServiceAPI::CreateSourceControl(PROFILE_TYPE_MAIN, 0, &sourceCtrl);
	 *	
	 *	if(sourceCtrl->DeactivateSource() > 0)
	 *	{
	 *		//Source was successfully deactivated
	 *	}
	 *	@endverbatim
	 */
	virtual int DeactivateSource(void) = 0;

	/**
	 * @brief Gets current source.
	 * @param [out] source Current source.
	 * @return Returns 1 if source type was successfully obtained, otherwise returns 0.
	 * @return When calling method failed returns -1.
	 *
	 *	@paragraph <Example>
	 *	This code will get current source for MAIN profile type and screenId = 0.
	 *	
	 *	@verbatim
	 *	ISourceControl* sourceCtrl;
	 *	TVServiceAPI::CreateSourceControl(PROFILE_TYPE_MAIN, 0, &sourceCtrl);
	 *	ESource source;
	 *	if(sourceCtrl->GetCurrentSourceInfo(source) > 0)
	 *	{
	 *		//Success
	 *	}
	 *	@endverbatim
	 */
	virtual int GetCurrentSourceInfo(_OUT_ ESource& source) = 0;

	/**
	 * @brief Gets current source.
	 * @param [out] curSource Current source.
	 * @return Returns 1 if source type was successfully obtained, otherwise returns 0.
	 * @return When calling method failed returns -1.
	 */
	 // TODO Duende - to be removed after 23.12.2013
	virtual int GetSource(_OUT_ ESource& curSource)
	{
		return GetCurrentSourceInfo(curSource);
	}

	/**
	 * @brief Gets previous source.
	 * @param [out] source Previous source.
	 * @return Returns 1 if source type was successfully obtained, otherwise returns 0.
	 * @return When calling method failed returns -1.
	 *
	 *	@paragraph <Example>
	 *	This code will get previous source for MAIN profile type and screenId = 0.
	 *	
	 *	@verbatim
	 *	ISourceControl* sourceCtrl;
	 *	TVServiceAPI::CreateSourceControl(PROFILE_TYPE_MAIN, 0, &sourceCtrl);
	 *	ESource source;
	 *	if(sourceCtrl->GetPreviousSourceInfo(source) > 0)
	 *	{
	 *		//Success
	 *	}
	 *	@endverbatim
	 */
	virtual int GetPreviousSourceInfo(_OUT_ ESource& source) = 0;
	
	/**
	 * @brief Stops TV service.
	 * @return Returns 1 if TV service was stopped, otherwise returns 0.
	 * @return When calling method failed returns -1.
	 *
	 *	@paragraph <Example>
	 *	This code will stop TV Service for MAIN profile type and screenId = 0.
	 *	
	 *	@verbatim
	 *	ISourceControl* sourceCtrl;
	 *	TVServiceAPI::CreateSourceControl(PROFILE_TYPE_MAIN, 0, &sourceCtrl);
	 *	ESource source = SOURCE_TYPE_DTV;
	 *	if(sourceCtrl->TVServiceStop() > 0)
	 *	{
	 *		//TV service was successfully stopped
	 *	}
	 *	@endverbatim
	 */
	virtual int TVServiceStop(void) = 0;

	//virtual int GetSourceName(_IN_ ESource source, _OUT_ ESourceName& nameId) = 0;

	//virtual int SetSourceName(_IN_ ESource source, _IN_ ESourceName nameId) = 0;

	//virtual int GetSourceTypeForMHL(_IN_ ESource source, _OUT_ ESource& sourceType) = 0;

	/**
	 * @brief Checks source statE.
	 * @param [out] sourceState Source state.
	 * @return Returns 1 if information was acquired, otherwise returns 0.
	 * @return When calling method failed returns -1.
	 *
	 *	@paragraph <Example>
	 *	This code will get source state for MAIN profile type and screenId = 0.
	 *	
	 *	@verbatim
	 *	ISourceControl* sourceCtrl;
	 *	TVServiceAPI::CreateSourceControl(PROFILE_TYPE_MAIN, 0, &sourceCtrl);
	 *	ESourceState sourceState;
	 *	if(sourceCtrl->GetSourceState(sourceState) > 0)
	 *	{
	 *		//Success
	 *	}
	 *	@endverbatim
	 */
	virtual int GetSourceState(_OUT_ ESourceState& sourceState) = 0;

	//virtual int GetDefaultSource(_IN_ TVStreamHandle streamHandle, _INOUT_ ESource sourceType) = 0;

	/**
	 * @brief Checks given source.
	 * @param [in] sourceType Source type.
	 * @param [out] check Checking result.
	 * @return Returns 1 if information was acquired, otherwise returns 0.
	 * @return When calling method failed returns -1.
	 *
	 *	@paragraph <Example>
	 *	This code will check SOURCE_TYPE_TV for MAIN profile type and screenId = 0.
	 *	
	 *	@verbatim
	 *	ISourceControl* sourceCtrl;
	 *	TVServiceAPI::CreateSourceControl(PROFILE_TYPE_MAIN, 0, &sourceCtrl);
	 *	bool status;
	 *	if(sourceCtrl->CheckExtSourcePlugged(SOURCE_TYPE_TV, status) > 0)
	 *	{
	 *		//Success
	 *	}
	 *	@endverbatim
	 */
	virtual int CheckExtSourcePlugged(_IN_ ESource sourceType, _OUT_ bool& check) = 0;
	
	/**
	 * @brief Gets source lock status.
	 * @param [out] lockStatus Lock status.
	 * @return Returns 1 if information was acquired, otherwise returns 0.
	 * @return When calling method failed returns -1.
	 *
	 *	@paragraph <Example>
	 *	This code will acquire lock status for MAIN profile type and screenId = 0.
	 *	
	 *	@verbatim
	 *	ISourceControl* sourceCtrl;
	 *	TVServiceAPI::CreateSourceControl(PROFILE_TYPE_MAIN, 0, &sourceCtrl);
	 *	bool status;
	 *	if(sourceCtrl->SourceLockStatus(status) > 0)
	 *	{
	 *		//Success
	 *	}
	 *	@endverbatim
	 */
	virtual int SourceLockStatus( _OUT_ bool& lockStatus) = 0;

	virtual int ResetCurrentSourceInfo(void) = 0;

	virtual int LiveTvShowReady(void) = 0;

	virtual int LiveTvShowClose(void) = 0;

	virtual int IsActive(_OUT_ bool& result) = 0;
	
	// TODO Duende - to be removed after 26.12.2014
	virtual int GetAvailableSources( _OUT_ std::vector< ESource >& availableSources) = 0;

	/**
	 * @brief Gets status for each source from given list.
	 * @param [in] sources List of sources for which status should be returned.
	 * @param [out] status Information about status of sources.
	 * @return Returns 1 if information was acquired, otherwise returns 0.
	 * @return When calling method failed returns -1.
	 *
	 *	@paragraph <Example>
	 *	This code will get status of TV and HDMI1 sources for MAIN profile type and screenId = 0.
	 *	
	 *	@verbatim
	 *	ISourceControl* sourceCtrl;
	 *	TVServiceAPI::CreateSourceControl(PROFILE_TYPE_MAIN, 0, &sourceCtrl);
	 *
	 *	std::list< ESource > sources;
	 *	source.push_back(SOURCE_TYPE_TV);
	 *	source.push_back(SOURCE_TYPE_HDMI1);
	 *
	 *	std::map<ESource,ESourceStatus> status;
	 *	if(sourceCtrl->CheckSourceStatus(sources, status) > 0)
	 *	{
	 *		//Read status[SOURCE_TYPE_TV] and status[SOURCE_TYPE_HDMI1] values
	 *	}
	 *	@endverbatim
	 */
	virtual int CheckSourceStatus( _IN_ const std::list<ESource>& sources, _OUT_ std::map<ESource,ESourceStatus>& status) = 0;

	/**
	 * @brief Starts source monitoring (It related to LFD product).
	 * @param [in] source source type to be monitored
	 * @return Returns 1 if successful, otherwise returns 0.
	 * @return When calling method failed returns -1.
	 *
	 *	@paragraph <Example>
	 *	
	 *	@verbatim
	 *	ISourceControl* sourceCtrl;
	 *	TVServiceAPI::CreateSourceControl(PROFILE_TYPE_MAIN, 0, &sourceCtrl);
	 *
	 *	ESource source = SOURCE_TYPE_DTV;
	 *
	 *	if(sourceCtrl->StartSourceMonitoring(source) > 0)
	 *	{
	 *		//Success
	 *	}
	 *	@endverbatim
	 */
	virtual int StartSourceMonitoring( _IN_ ESource source) = 0;

	/**
	 * @brief Stops source monitoring (It related to LFD product).
	 * @param [in] source source type that is monitored
	 * @return Returns 1 if successful, otherwise returns 0.
	 * @return When calling method failed returns -1.
	 *
	 *	@paragraph <Example>
	 *	
	 *	@verbatim
	 *	ISourceControl* sourceCtrl;
	 *	TVServiceAPI::CreateSourceControl(PROFILE_TYPE_MAIN, 0, &sourceCtrl);
	 *
	 *	ESource source = SOURCE_TYPE_DTV;
	 *
	 *	if(sourceCtrl->StopSourceMonitoring(source) > 0)
	 *	{
	 *		//Success
	 *	}
	 *	@endverbatim
	 */
	virtual int StopSourceMonitoring( _IN_ ESource source) = 0;

	 /**
	 * @brief Start HDMI analysis and capture. 
	 * @param [in] source source type to be captured (HDMI1 ~ HDMI4).
	 * @return Returns 1 if successful, otherwise returns 0.
	 * @return When calling method failed returns -1.
	 *
	 * @paragraph <Example>
	 * 
	 * @verbatim
	 * ISourceControl* sourceCtrl;
	 * TVServiceAPI::CreateSourceControl(PROFILE_TYPE_MAIN, 0, &sourceCtrl);
	 *
	 * ESource source = SOURCE_TYPE_HDMI1;
	 *
	 * if(sourceCtrl->StartHDMIAnalysis(source) > 0)
	 * {
	 *	//Success
	 * }
	 * @endverbatim
	 */
	virtual int StartHDMIAnalysis( _IN_ ESource source) = 0;

	 /**
	 * @brief stop HDMI analysis and capture. 
	 * @param [in] source source type to be captured (HDMI1 ~ HDMI4).
	 * @return Returns 1 if successful, otherwise returns 0.
	 * @return When calling method failed returns -1.
	 *
	 * @paragraph <Example>
	 * 
	 * @verbatim
	 * ISourceControl* sourceCtrl;
	 * TVServiceAPI::CreateSourceControl(PROFILE_TYPE_MAIN, 0, &sourceCtrl);
	 *
	 * ESource source = SOURCE_TYPE_HDMI1;
	 *
	 * if(sourceCtrl->StopHDMIAnalysis(source) > 0)
	 * {
	 *	//Success
	 * }
	 * @endverbatim
	 */
	virtual int StopHDMIAnalysis( _IN_ ESource source) = 0;

	/**
	* FIXME It should be removed for MAIN2017.
	* The magic method was added to provide communication between AVOC and TVPlayer.
	* They don't know about each other so it has been decided to do it in that way.
	*/
	virtual int PrepareLFDSoundOnVideoCall(_IN_ bool enable) = 0;
	
};

#endif // _ISOURCECONTROL_H_

