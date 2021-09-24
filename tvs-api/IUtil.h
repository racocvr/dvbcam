/** 
 * @file IUtil.h
 * @brief Application interface for managing timer.
 *
 * Copyright 2013 by Samsung Electronics, Inc.,
 * 
 * This software is the confidential and proprietary information
 * of Samsung Electronics, Inc. ("Confidential Information"). You
 * shall not disclose such Confidential Information and shall use
 * it only in accordance with the terms of the license agreement
 * you entered into with Samsung.
 */


#ifndef _IUTIL_H_
#define _IUTIL_H_

#include "MarshallingMarks.h"
#include "UtilDataType.h"
#include "TVServiceDataType.h"
#include "ServiceNavigationDataType.h"
#include "ServiceDataType.h"

class IUtil
{
protected:
	virtual ~IUtil(){};

public:

	virtual int SetDualTvAvOff(_IN_ bool onOff) = 0;
	
	/**
	 * @brief Select Master audio pipeline
	 * @param [in] pipeline type and screen id  
	 * @return Returns 1 if search option was available, otherwise returns 0.
	 * @return When calling method failed returns -1.
	 *
	 *	@paragraph <Example>
	 *	
	 *	@verbatim
	 *	IUtil* pUtil = NULL;
	 *	TVServiceAPI::CreateUtil(&pUtil);
	 *	if(pUtil->SelectMasterAudio( PROFILE_TYPE_MAIN, 0 ) > 0)
	 *	{
	 *		//Do something when operation successful
	 *	}
	 *	@endverbatim
	 */
	virtual int SelectMasterAudio(_IN_ EProfile profileId, _IN_ int screenId) = 0;

	/**
	 * @brief Select Master audio pipeline
	 * @param [in] pipeline type and screen id  
	 * @return Returns 1 if search option was available, otherwise returns 0.
	 * @return When calling method failed returns -1.
	 *
	 *	@paragraph <Example>
	 *	
	 *	@verbatim
	 *	IUtil* pUtil = NULL;
	 *	TVServiceAPI::CreateUtil(&pUtil);
	 *	EProfile profileId;
	 *	int screenId;
	 *	if(pUtil->GetMasterAudio( profileId, screenId ) > 0)
	 *	{
	 *		//Do something when operation successful
	 *	}
	 *	@endverbatim
	 */
	virtual int GetMasterAudio(_OUT_ EProfile& profileId, _OUT_ int& screenId) = 0;

	/**
	 * @brief Set system time of TV
	 * @param [in] UTC time that   
	 * @return Returns 1 if success to set, otherwise returns 0.
	 * @return When calling method failed returns -1.
	 *
	 *	@paragraph <Example>
	 *	
	 *	@verbatim
	 *	IUtil* pUtil = NULL;
	 *	TVServiceAPI::CreateUtil(&pUtil);
	 *	unsigned long UTC = 946686246;
	 *	if(pUtil->SetTVSystemTime( UTC ) > 0)
	 *	{
	 *		//Do something when operation successful
	 *	}
	 *	@endverbatim
	 */
	virtual int SetTVSystemTime(_IN_ unsigned long UTC) = 0;

	/**
	 * @brief Get offset by timeZone
	 * @param [in] timeZone identifier value
	 * @param [out] offset value 
	 * @return Returns 1 if success to set, otherwise returns 0.
	 * @return When calling method failed returns -1.
	 *
	 *	@paragraph <Example>
	 *	
	 *	@verbatim
	 *	IUtil* pUtil = NULL;
	 *	TVServiceAPI::CreateUtil(&pUtil);
	 *	ETimeZone timeZone = TIMEZONE_REGION_0;
	 *	int offset = 0;
	 *	if(pUtil->GetTimeZoneOffset( timeZone, offset ) > 0)
	 *	{
	 *		//Do something when operation successful
	 *	}
	 *	@endverbatim
	 */
	virtual int GetTimeZoneOffset(_IN_ ETimeZone timeZone, _OUT_ int& offset) = 0;

	/** DEPRECATED DO NOT USE. WILL BE REMOVED AFTER 2014.11.07. TODO Duende */
	int GetTimeZoneOffset(_IN_ int regionId, _OUT_ int& offset)
	{
		return GetTimeZoneOffset((ETimeZone)regionId, offset);
	}

	/**
	 * @brief Get information how auto clock was set.
	 * @return Returns 1.
	 * @return When calling method failed returns -1.
	 * @remarks Auto clock check is independent of profile and screen.
	 *
	 *	@paragraph <Example>
	 *	This code will get auto clock type.
	 *	
	 *	@verbatim
	 *	IUtil* pUtil = NULL;
	 *	TVServiceAPI::CreateUtil(&pUtil);
	 *	ETypeOfAutoClock autoClockType;
	 *	if(pUtil->GetAutoClockType(autoClockType) > 0)
	 *	{
	 *		// autoClockType information valid
	 *	}
	 *	@endverbatim
	 */
	virtual int GetAutoClockType(_OUT_ ETypeOfAutoClock& autoClockType) = 0;

	/**
	 * @brief Checks if user is able to change RCN (receiver channel number) in specified TV mode
	 * @param [in] tvMode TV mode
	 * @param [out] editable true if the RCN is editable by user, false otherwise
	 * @return When calling method succeeds returns 1.
	 * @remark default value is false
	 *
	 *	@paragraph <Example>
	 *	This code will check user RCN editability.
	 *
	 *	@verbatim
	 *	IUtil* pUtil = NULL;
	 *	TVServiceAPI::CreateUtil(&pUtil);
	 *	bool editable = false;
	 *	if(pUtil->CheckRCNEditable(tvMode, editable) > 0)
	 *	{
	 *		// editable information valid
	 *	}
	 *	@endverbatim
	 */
	virtual int CheckRCNEditable(_IN_ const TSTvMode & tvMode, _OUT_ bool & editable) const = 0;

	/**
	 * @brief Defines whether user is able to change RCN (receiver channel number) in specified TV mode
	 * @param [in] tvMode TV mode
	 * @param [in] editable true if the RCN is editable by user, false otherwise
	 * @return When calling method succeeds returns 1.
	 *
	 *	@paragraph <Example>
	 *	This code will add user RCN editability.
	 *
	 *	@verbatim
	 *	IUtil* pUtil = NULL;
	 *	TVServiceAPI::CreateUtil(&pUtil);
	 *	bool editable = true;
	 *	if(pUtil->SetRCNEditable(tvMode, editable) > 0)
	 *	{
	 *		// editability successfully set
	 *	}
	 *	@endverbatim
	 */
	virtual int SetRCNEditable(_IN_ const TSTvMode & tvMode, _IN_ bool editable) = 0;

	/**
	 * @brief Checks if user can delete service from service list in channel editor in specified TV mode
	 * @param [in] tvMode TV mode
	 * @param [out] deletable true if user can delete service, false otherwise
	 * @return When calling method failed returns -1.
	 * @remark default value is true
	 *
	 *	@paragraph <Example>
	 *	This code will check user delete support.
	 *
	 *	@verbatim
	 *	IUtil* pUtil = NULL;
	 *	TVServiceAPI::CreateUtil(&pUtil);
	 *	bool deletable = true;
	 *	if(pUtil->CheckServiceDeleteSupport(tvMode, deletable) > 0)
	 *	{
	 *		// deletable information valid
	 *	}
	 *	@endverbatim
	 */
	virtual int CheckServiceDeleteSupport(_IN_ const TSTvMode & tvMode, _OUT_ bool & deletable) const = 0;

	/**
	 * @brief Gets user preferred language.
	 * @param [in] profileId profile type
	 * @param [in] screenId ID of a screen
	 * @param [out] language User preferred language.
	 * @return Returns 1.
	 * @return When calling method failed returns -1.
	 *
	 *	@paragraph <Example>
	 *	This code will add user RCN editability.
	 *
	 *	@verbatim
	 *	IUtil* pUtil = NULL;
	 *	TVServiceAPI::CreateUtil(&pUtil);
	 *
	 *	unsigned int language;
	 *	if(pUtil->GetPreferredLanguage(language) > 0)
	 *	{
	 *		// use given language value
	 *	}
	 *	@endverbatim
	 */
	virtual int GetPreferredLanguage(_IN_ EProfile profileId, _IN_ int screenId, _OUT_ unsigned int& language) = 0;

	/**
	 * @brief Stores service database in a ZIP file.
	 * @remark TVS must have access (defined in SMACK) to dbPath, otherwise the method will fail
	 * @param [out] path Path where the ZIP file is stored
	 * @return 1 on success, -1 on failure
	 *
	 * @paragraph <Example>
	 * This code will store service DB in a ZIP file
	 *
	 * @verbatim
	 * IUtil* pUtil = NULL;
	 * TVServiceAPI::CreateUtil(&pUtil);
	 *
	 * std::string dbPath = "/tmp/ServiceDB.zip";
	 * if(pUtil->GetServiceDb( dbPath ) > 0)
	 * {
	 *		//do something with the stored database
	 * }
	 * @endverbatim
	 */
	virtual int GetServiceDb( _IN_ const std::string& path ) = 0;

	/**
	 * @brief Loads service database from a ZIP file.
	 * @param [in] path Path where the ZIP file is stored
	 * @param [out] status Set to REPLACEMENT_SUCCESS when operation was successful, other values denote reason of failure
	 * @return 1 on success, 0 on failure, -1 on DBus error during communication with the TV Service
	 *
	 * @paragraph <Example>
	 * This code will restore service DB from a ZIP file
	 *
	 * @verbatim
	 * IUtil* pUtil = NULL;
	 * TVServiceAPI::CreateUtil(&pUtil);
	 *
	 * if(pUtil->ReplaceServiceDb( dbPath, status ) > 0)
	 * {
	 *		//the database has been successfully restored
	 * }
	 * @endverbatim
	 */
	virtual int ReplaceServiceDb( _IN_ const std::string& path, _OUT_ EServiceDbReplacementStatus& status ) = 0;

	/**
	 * @brief Creates TVS data back-up. 
	 * @param [in] path Path where the databases files are stored.
	 * @remarks This method creates ZIP file with data from TVS modules.
	 * @return 1 on success, 0 on failure, -1 on DBus error during communication with the TV Service
	 *
	 * @paragraph <Example>
	 * This code will create a back-up for TVS data.
	 *
	 * @verbatim
	 * IUtil* pUtil = NULL;
	 * TVServiceAPI::CreateUtil(&pUtil);
	 * std::string path = "\\files_path";
	 *
	 * if(pUtil->Backup( path ) > 0)
	 * {
	 *		//backup successfully created
	 * }
	 * @endverbatim
	 */
	virtual int Backup( _IN_ const std::string& path ) = 0;

	/**
	 * @brief Restores TVS data from back-up. 
	 * @param [in] path Path where the databases files are stored.
	 * @remarks Backup() method has to be called beforehand, otherwise there will be no data to restore.
	 * @return 1 on success, 0 on failure, -1 on DBus error during communication with the TV Service
	 *
	 * @paragraph <Example>
	 * This code will restore TVS data from previously created backup.
	 *
	 * @verbatim
	 * IUtil* pUtil = NULL;
	 * TVServiceAPI::CreateUtil(&pUtil);
	 * std::string path = "\\files_path";
	 *
	 * if(pUtil->Restore( path ) > 0)
	 * {
	 *		//data successfully restored.
	 * }
	 * @endverbatim
	 */
	virtual int Restore( _IN_ const std::string& path ) = 0;

	/** DEPRECATED DO NOT USE. WILL BE REMOVED AFTER 2014.12.19. TODO Duende */
	int ReplaceServiceDb( _IN_ const std::string& path )
	{
		 EServiceDbReplacementStatus status; 
		 return ReplaceServiceDb(path, status);
	}

	/**
	 * @brief Stores history trace log to flash
	 * @return 1 on success, 0 on failure, -1 on DBus error during communication with the TV Service
	 */
	virtual int SaveHistoryTrace() = 0;

	/**
	 * @brief Clears history trace log
	 * @return 1 on success, 0 on failure, -1 on DBus error during communication with the TV Service
	 */
	virtual int ClearHistoryTrace() = 0;
};

#endif // _IUTIL_H_

