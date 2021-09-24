/** 
 * @file IPCUtility.h
 * @brief Utility tools for IPC (part of tvs-api)
 *
 * Copyright 2013 by Samsung Electronics, Inc.,
 * 
 * This software is the confidential and proprietary information
 * of Samsung Electronics, Inc. ("Confidential Information"). You
 * shall not disclose such Confidential Information and shall use
 * it only in accordance with the terms of the license agreement
 * you entered into with Samsung.
 */

#ifndef _IPCUTILITY_H_
#define _IPCUTILITY_H_

#include "TVServiceDataType.h"
#include "IPCDataType.h"

#define MAX_DBUS_MESSAGE_SIZE 16*1024*1024 	// max size of message should not extend 16 MB
#define MAX_FILTER_LENGTH 256				// max length of text that represents filter for signals sent in broadcast style from TVService
#define MAX_DBUS_CONNECTION_ATTEMPTS 60		// max number of failed connection attempts to Dbus

class TCIPCUtility
{
public:
	
	/**
	 * @brief Creates text of a filter for signals.
	 * @param [in] messageType Type of message.
	 * @param [in] messageId ID of a message.
	 * @param [in] handle TVSHandle to which signal is assigned.
	 * @param [out] pFilter Filter text.
	 */
	static void GenerateSignalFilter(EIPCMessageType messageType, int messageId, const TVSHandle& handle, char* pFilter);


	/**
	 * @brief Creates name for sub DBUS connection based on name of main connection.
	 * The same name can be generated on proxy and native side.
	 * @param [in] nameOfMainConnection name of main connection
	 * @result generated name for subconnection
	 */
	static std::string GenerateSubConnectionName(const std::string& nameOfMainConnection);
};

#endif // _IPCUTILITY_H_
