/** 
 * @file IPCManager.h
 * @brief Implementation of IIPCManager interface
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

#ifndef _IPCMANAGER_H_
#define _IPCMANAGER_H_

#include <dbus/dbus.h>
#include <map>
#include <memory>
#include <string>
#include <pthread.h>

#include "MessageBuffer.h"
#include "Marshalable.h"
#include "IPCDataType.h"
#include "IIPCListener.h"
#include "ICallListener.h"
#include "IIPCProperties.h"

class TCIPCManager: public TIIPCProperties
{
public:
	TCIPCManager( std::string signalInterfaceName, std::string signalObjectName );
	~TCIPCManager( void );
	
	/**
	 * @brief Sends serializable object to selected recipient with set message ID.
	 * @param [in] type Type of message to be sent.
	 * @param [in] receiverId Unique connection name of message receiver.
	 * @param [in] messageId ID of a message.
	 * @param [in] messageData Serializable object that ought to be sent.
	 * @return Returns information if message was sent or any error occured.
	 */
	EIPCSendMessageReturn Send(EIPCMessageType type, const std::string& receiverId, const int messageId, TCMarshalable* messageData); 	

	/**
	 * @brief Sends data buffer in a broadcast scheme with set message Id and TVS handle.
	 * @param [in] type Type of message to be sent.
	 * @param [in] messageId Id of a message.
	 * @param [in] pipelineId Id of a pipeline.
	 * @param [in] messageData Data buffer that ought to be sent.
	 * @return Returns information if message was sent or any error occured.
	 */
	EIPCSendMessageReturn Send(EIPCMessageType type, int messageId, unsigned long pipelineId, TCMessageBuffer& messageData);

	/**
	 * @brief Starts new native API listener.
	 * @remark After calling this method TCIPCManager is the owner of pointed object and will manage its lifetime.
	 * @param [in] nativeAPI Native API object that will handle method calls.
	 * @return Returns true if listener was attached, otherwise returns false.
	 */
	bool StartNativeAPI(std::auto_ptr<TICallListener> nativeAPI); 

	/**
	 * @brief Attaches new listener to DBus incoming messages.
	 * @remark After calling this method TCIPCManager is the owner of pointed object and will manage its lifetime.
	 * @param [in] listener Object that will handle DBus messages.
	 * @return Returns true if listener was attached, otherwise returns false.
	 */
	bool AttachListener(std::auto_ptr<TIIPCListener> listener);

	/**
	 * @see base class
	 */
	virtual TSCallerProperties GetCallerProperties();

	/**
	 * @see base class
	 */
	virtual bool AddCaller(const std::string& id, const TSCallerProperties& properties);

	/**
	 * @see base class
	 */
	virtual bool SetCurrentCaller(const std::string& id);

	/**
	 * @see base class
	 */
	virtual void ClearCurrentCaller();
	
protected:	
	/**
	 * @brief Proper method for handling incoming messages
	 * @param [in] pMessage Message to be handled
	 * @return result of handling message
	 */
	DBusHandlerResult t_MessageHandler(DBusMessage* pMessage);
	
private:
	DBusConnection* m_pConnection; // DBus connection
	std::string m_signalInterfaceName; // name of DBus interface name for sending signals/data
	std::string m_signalObjectName; // name of DBus object name for sending signals/data

	std::map<std::string, TIIPCListener*> m_IPCListeners; // all IPC listeners
	pthread_rwlock_t m_listenerListLock; // mutex to IPC listeners list

	std::map<std::string, TSCallerProperties> m_callers;	// keeps map of caller properties
	TSCallerProperties m_currentCaller;			// keeps properties of current caller from proxy side. It is not cleared when call is finished.
	pthread_rwlock_t m_callersLock;

	/**
	 * @brief Sends serializable object to selected recipient with set message ID
	 * @param [in] receiverId unique connection name of message receiver
	 * @param [in] messageType type of message
	 * @param [in] messageId ID of a message
	 * @param [in] messageData serializable object that ought to be sent
	 * @return Returns information if message was sent or any error occured.
	 */
	EIPCSendMessageReturn m_Send(const std::string& receiverId, EIPCMessageType messageType, int messageId, TCMessageBuffer& messageData);

	/**
	 * @brief Sends serializable object to selected recipient with set message ID
	 * @param [in] receiverId unique connection name of message receiver
	 * @param [in] messageType type of message
	 * @param [in] messageId ID of a message
	 * @param [in] pipelineId ID of pipeline
	 * @param [in] messageData serializable object that ought to be sent
	 * @return Returns information if message was sent or any error occured.
	 */
	EIPCSendMessageReturn m_Send(const std::string& receiverId, EIPCMessageType messageType, int messageId, unsigned long pipelineId, TCMessageBuffer& messageData);
	
	/**
	 * @brief Creates main connection
	 * @return true if success
	 */
	bool m_Connect( void );

	/**
	 * @brief Converts message type to string
	 * @param [in] messageType message type
	 * @return text version of message type
	 */
	const char* m_ConvertMsgTypeToString(EIPCMessageType messageType);

	/**
	 * @brief Releases interface name on DBus
	 * @param [in] pListener IPC message listener.
	 */
	void m_ReleaseDbusName(TIIPCListener* pListener);


	/**
	 * @brief Wrapper static method for handling messages incoming
	 * @param [in] pConnection DBusConnection
	 * @param [in] pMessage Message to be handled
	 * @param [in] pObject interface object
	 * @return result of handling message
	 */
	static DBusHandlerResult m_MessageHandlerHelper(DBusConnection* pConnection, DBusMessage* pMessage, void* pObject);

	/**
	 * @brief Proper method for handling XML introspection (returning information how interface looks like)
	 * @remarks XML Introspection is needed for SBB support
	 * @param [in] pMessage Message to be handled
	 * @return result of handling message
	 */
	DBusHandlerResult m_HandleIntrospection(DBusMessage* pMessage); 

	/**
	 * @brief Gets introspection information for all registered exportable interfaces.
	 * @remark Introspection is needed for SBB support.
	 * @return Instrospection information for all registered exportable interfaces.
	 */
	std::string m_GetIntrospectionInfo(void);

	/**
	 * @brief Attaches new listener to DBus incoming messages.
	 * @param [in] listener Pointer to object that will handle DBus messages.
	 * @return Returns true if listener was attached, otherwise returns false.
	 */
	bool m_AttachListener( std::auto_ptr<TIIPCListener> listener );

	/**
	 * @brief Starts watching D-BUS name owner changed
	 * @param [in] pConnection DBusConnection
	 * @return true if success. Otherwise false.
	 */
	bool m_StartWatchOwnerChanged(DBusConnection* pConnection);

	/**
	 * @brief Stops watching D-BUS name owner changed
	 * @param [in] pConnection DBusConnection
	 * @return true if success. Otherwise false.
	 */
	bool m_StopWatchOwnerChanged(DBusConnection* pConnection);

	/**
	 * @brief Proper method for handling incoming messages about owner changed.
	 * The method is involved when a name appear or disappear from D-BUS.
	 * @param [in] pMessage Message to be handled
	 * @return result of handling message
	 */
	DBusHandlerResult m_HandleOwnerChanged(DBusMessage* pMessage);
};

#endif // _IPCMANAGER_H_

