/** 
 * @file TVServiceAPIConnection.h
 * @brief Interface to tool class for External API for communication with TVService
 *
 * Copyright 2015 by Samsung Electronics, Inc.,
 * 
 * This software is the confidential and proprietary information
 * of Samsung Electronics, Inc. ("Confidential Information"). You
 * shall not disclose such Confidential Information and shall use
 * it only in accordance with the terms of the license agreement
 * you entered into with Samsung.
 */
 
#ifdef _WIN32
#pragma once
#endif

#ifndef _TVSERVICEAPICONNECTION_H_
#define _TVSERVICEAPICONNECTION_H_

#include <string>
#include "IPCConnection.h"

class TVServiceAPIConnection
{
public:

	/**
	 * @brief Constructor.
	 * @param [in] interfaceName Name of DBus interface name that sends signals/data.
	 * @param [in] objectName Name of DBus object name that sends signals/data.
	 * @param [in] setupWithMainLoop if true a new connection is setup with g_main_loop.
	 * g_main_loop is needed to use dbus signal (e.g. PES data, signals from tvs-tpms).
	 * It is a workaround since current implementation does not allow to remove a connection from g_main_loop correctly.
	 */
	TVServiceAPIConnection(std::string interfaceName, std::string objectName, bool setupWithMainLoop = true);

	/**
	 * @brief Destructor.
	 */
	~TVServiceAPIConnection();
	
	/**
	 * @brief Adds match rule which has to be fulfilled to receive message
	 * @param [in] type type of message to be sent
	 * @param [in] messageId ID of a message
	 * @param [in] handle TVSHandle to which assigned is the message.
	 * @return true if success
	 */
	bool AddMatchRule(EIPCMessageType type, int messageId, const TVSHandle& handle);

	/**
	 * @brief Deletes match rule which has to be fulfilled to receive message
	 * @param [in] type type of message to be sent
	 * @param [in] messageId ID of a message
	 * @param [in] handle TVSHandle to which assigned is the message.
	 * @return true if success
	 */
	bool RemoveMatchRule(EIPCMessageType type, int messageId, const TVSHandle& handle);

	/**
	 * @brief Calls method from External API
	 * @param [in] interfaceName name of interface that handles method call
	 * @param [in] functionCode code of a method on interface
	 * @param [in] inputData input data buffer for method call
	 * @param [out] outputData output data buffer
	 * @return return true if success
	 */
	bool Call(const std::string& interfaceName, const short functionCode, TCMessageBuffer& inputData, TCMessageBuffer& outputData);

	/**
	 * @brief Calls method from External API. A method is called asynchronously. It does not wait for response.
	 * @param [in] interfaceName name of interface that handles method call
	 * @param [in] functionCode code of a method on interface
	 * @param [in] inputData input data buffer for method call
	 * @return return true if success
	 */
	bool CallAsync(const std::string& interfaceName, const short functionCode, TCMessageBuffer& inputData);

	/**
	 * @brief Waits until there is listener of the interface
	 * @param [in] interfaceName name of interface that handles method call
	 * @return return true when exists
	 */
	bool WaitForCreateInterface(const char* interfaceName);
	
	/**
	 * @brief Sets a function that will be called when IPC message arrives
	 * @param [in] type type of IPC message
	 * @param [in] functionCB pointer to callback function
	 */
	void SetCallbackFunction(EIPCMessageType type, IPCCallbackFunction functionCB);

	/**
	 * @brief Unsets a function from specified IPC message
	 * @param [in] type type of IPC message
	 * @param [in] functionCB pointer to callback function
	 */
	void UnsetCallbackFunction(EIPCMessageType type, IPCCallbackFunction functionCB);

	/**
	 * @brief Gets unique dbus name
	 */
	const std::string GetReceiverId();

private:

	TCIPCConnection m_IPCConnection;

};

#endif // _TVSERVICEAPICONNECTION_H_
