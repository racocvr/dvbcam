/** 
 * @file ServiceDataUtility.h
 * @brief Utility methods related to service data.
 *
 * Copyright 2015 by Samsung Electronics, Inc.,
 * 
 * This software is the confidential and proprietary information
 * of Samsung Electronics, Inc. ("Confidential Information"). You
 * shall not disclose such Confidential Information and shall use
 * it only in accordance with the terms of the license agreement
 * you entered into with Samsung.
 */


#ifndef _SERVICEDATAUTILITY_H_
#define _SERVICEDATAUTILITY_H_

#include "ServiceDataType.h"
#include "SOSpecDataType.h"

class TCServiceData;

class TCServiceDataUtility
{
public:

  /**
	* @brief Method to get service name/multilanguage service name for given service id based on language settings.
	* @remarks If multilingual service name matching user preferred language exists, it shall be acquired instead of regular name.
	* @param[in] serviceId Id of service.
	* @param[out] serviceName Returned service name.	
	* @param[in] option about remembered service.	
	* @return True if obtaining service name was successfull. When method returns false, serviceName has not been set and that means that it is incorrect.
	*/
	static bool GetServiceName( const TCServiceId serviceId, t_wstring& serviceName, bool remembered = true);

private:
	/**
	* @brief Gets preferred language from runtime, if language can't be get from runtime, method tries to get it from TCBinder.
	* @return Obtained language code.
	*/
	static ELanguageCode m_GetPreferredLanguage();

	/**
	* @brief Gets serviceData with service name, multilinguage service name and its language code.
	* @param[in] serviceId Id of service.
	* @param[out] service Returned service.	
	* @param[in] option about remembered service.	
	* @return True if obtaining service was successfull, false otherwise.
	*/
	static bool m_GetServiceById( const TCServiceId serviceId, TCServiceData& service, bool remembered );
};



#endif // _SERVICEDATAUTILITY_H_

