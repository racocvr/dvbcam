/** 
 * @file IPCConnection.h
 * @brief Tool class for External API for communication with middleware
 *
 * Copyright 2013 by Samsung Electronics, Inc.,
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

#ifndef _IPCCONNECTION_H_
#define _IPCCONNECTION_H_

#include <string>
#include <dbus/dbus.h>
#include <pthread.h>

#include "MessageBuffer.h"
#include "IPCDataType.h"
#include "TVServiceDataType.h"


typedef void (*IPCCallbackFunction)(int, TCMessageBuffer&); // IPC Callback Function (parameters: messageId, messageData)

class TCIPCConnection
{
public:

	/**
	 * @brief Constructor
	 * @param [in] signalInterfaceName Name of DBus interface name that sends signals/data
	 * @param [in] signalObjectName Name of DBus object name that sends signals/data
	 * @param [in] setupWithMainLoop if true a new connection is setup with g_main_loop.
	 * g_main_loop is needed to use dbus signal (e.g. PES data, signals from tvs-tpms).
	 * It is a workaround since current implementation does not allow to remove a connection from g_main_loop correctly.
	 */
	TCIPCConnection( std::string signalInterfaceName, std::string signalObjectName, bool setupWithMainLoop = true );

	~TCIPCConnection(void);

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
	bool Call(const std::string& interfaceName,const short functionCode, TCMessageBuffer& inputData, TCMessageBuffer& outputData);

	/**
	 * @brief Calls method from External API. A method is called asynchronously. It does not wait for response.
	 * @param [in] interfaceName name of interface that handles method call
	 * @param [in] functionCode code of a method on interface
	 * @param [in] inputData input data buffer for method call
	 * @return return true if success
	 */
	bool CallAsync(const std::string& interfaceName,const short functionCode, TCMessageBuffer& inputData);

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

	/* Mutexes and callbacks are per message type.
	It enables to set different listeners for different message types (more than one interface) and ensures that they can be changed independently 
	(you can change in the same time callback for two different message types). 
	It also allows to set callback method for some message type while another callback (for another message type) is handled.
	This case is used when handling of SIGNAL message causes creation of another listener (like CAPTION data).
	*/
	pthread_mutex_t m_cbMutexes[IPC_MESSAGE_MAX];	// mutexes one per message type
	IPCCallbackFunction m_cbFunctions[IPC_MESSAGE_MAX];	// callback methods one per message type
	
	DBusConnection* m_pAPIConnection; // this connection is used only for API calls
	DBusConnection* m_pMainLoopConnection; // this connection is used to deliver DBUS signals. It is handled by g_main_loop.
	std::string m_signalInterfaceName; // name of DBus interface name that sends signals/data
	std::string m_signalObjectName; // name of DBus object name that sends signals/data
	std::string m_receiverId; // unique message bus ID

	bool m_sendHello; // if true additional information like app name and pid are added to each message
	bool m_connectedWithMainLoop; //if true current connection is connected to g_main_loop.

	/**
	 * @brief Connects to data bus to enable receiving data from middleware and calling methods.
	 * @param [in] setupWithMainLoop if true a new connection is setup with g_main_loop.
	 * g_main_loop is needed to use dbus signal (e.g. PES data, signals from tvs-tpms).
	 * It is a workaround since current implementation does not allow to remove a connection from g_main_loop correctly.
	 * @return Return if success.
	 */
	bool m_Connect(bool setupWithMainLoop);

	/**
	 * @return if success a new private DBUS connection. Otherwise NULL;
	 */
	DBusConnection* m_CreateConnection();

	/**
	 * @brief This method releases all DBUS connections
	 */
	void m_ReleaseAllConnections();

	/**
	 * @brief Wrapper static method for handling messages incoming
	 * @param [in] connection DBusConnection
	 * @param [in] message Message to be handled
	 * @param [in] object interface object
	 * @return result of handling message
	 */	
	static DBusHandlerResult m_MessageHandlerHelper(DBusConnection* connection, DBusMessage* message, void* object);

	/**
	 * @brief Proper method for handling messages incoming
	 * @param [in] message Message to be handled
	 * @return result of handling message
	 */	
	DBusHandlerResult m_MessageHandler(DBusMessage* message);

	/**
	 * @brief Creates text of a match rule
	 * @param [in] messageType type of message  
	 * @param [in] messageId ID of a message
	 * @return true if success
	 */
	void m_CreateMatchRule(EIPCMessageType messageType, int messageId, char* pMatchRule);

	/**
	 * @brief Creates text of a match rule
	 * @param [in] messageType type of message  
	 * @param [in] messageId ID of a message
	 * @param [in] handle TVSHandle to which assigned is the message.
	 * @return true if success
	 */
	void m_CreateMatchRule(EIPCMessageType messageType, int messageId, const TVSHandle& handle, char* pMatchRule);

	/**
	 * @brief Returns message type for given message
	 * @param [in] message message that should be checked
	 * @return message type
	 */
	EIPCMessageType m_GetMessageType(DBusMessage* message);

	/**
	 * @brief Converts message type to string
	 * @param [in] messageType message type
	 * @return text version of message type
	 */
	const char* m_ConvertMsgTypeToString(EIPCMessageType messageType);


	/**
	 * Prepare message to send by dbus. It converts functionCode and inputData to DBusMessage
	 * @param [out] message result is stored in this fiels
	 * @param [in] functionCode code of a method on interface
	 * @param [in] inputData input data buffer for method call
	 * @param [in] flag that are sent from proxy to native side.
	 * @return true if success. Otherwise false.
	 */
	bool m_PrepareMessage(DBusMessage* message, const short functionCode, TCMessageBuffer& inputData, unsigned short flags = IPC_FLAG_NONE);

};

#endif // _IPCCONNECTION_H_

