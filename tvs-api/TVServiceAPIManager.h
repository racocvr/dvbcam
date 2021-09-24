/** 
 * @file TVServiceAPIManager.cpp
 * @brief Internal interface for sending data from TVService to applications and managing external API handling
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

#ifndef _TVSERVICEAPIMANAGER_H_
#define _TVSERVICEAPIMANAGER_H_

#include <map>
#include <string>
#include <memory>
#include <pthread.h>

#include "Marshalable.h"
#include "IPCDataType.h"
#include "TVServiceDataType.h"
#include "IIPCListener.h"
#include "ICallListener.h"

class TCIPCManager;

class TVServiceAPIManager
{
public:

	/**
	 * @brief Returns pointer to instance of an interface.
	 * @param [in] interfaceName Name of DBus interface name that sends signals/data.
	 * @param [in] objectName Name of DBus object name that sends signals/data.
	 * @return Interface object pointer.
	 */
	static TVServiceAPIManager* GetInstance(std::string interfaceName, std::string objectName);
	
	/**
	 * @brief Destroys kept instance of interface.
 	 * @param [in] interfaceName Name of DBus interface name that sends signals/data.
	 * @param [in] objectName Name of DBus object name that sends signals/data.
	 */
	static void Destroy(std::string interfaceName, std::string objectName);
	
	/**
	 * @brief Sends serializable object to selected recipient with set message ID.
	 * @param [in] type Type of message to be sent.
	 * @param [in] receiverId Unique connection name of message receiver.
	 * @param [in] messageId ID of a message.
	 * @param [in] pMessageData Serializable object that ought to be sent.
	 * @return Returns information if message was sent or any error occured.
	 */
	EIPCSendMessageReturn Send(EIPCMessageType type, const std::string& receiverId, const int messageId, TCMarshalable* pMessageData); 	

	/**
	 * @brief Sends data buffer in a broadcast scheme with set message Id and TVS handle.
	 * @param [in] type Type of message to be sent.
	 * @param [in] messageId Id of a message.
	 * @param [in] handle Defines TVS pipeline.
	 * @param [in] messageData Data buffer that ought to be sent.
	 * @return Returns information if message was sent or any error occured.
	 */
	EIPCSendMessageReturn Send(EIPCMessageType type, int messageId, const TVSHandle& handle, TCMessageBuffer& messageData);

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
	 * @brief Get id of current caller. ID of process from which request was sent.
	 * @param [in] id it is unique name of caller. To make it unique name assigned by dbus is used.
	 * @return Returns current caller properties.
	 */
	TSCallerProperties GetCallerProperties(void);
	
private:

	/**
	 * @brief Constructor.
	 * @param [in] interfaceName Name of DBus interface name that sends signals/data.
	 * @param [in] objectName Name of DBus object name that sends signals/data.
	 */
	TVServiceAPIManager(std::string interfaceName, std::string objectName);
	~TVServiceAPIManager();
	
	// 1'st string represents signal interface name and 2'nd string represents signal object name.
	typedef std::map< std::pair<std::string, std::string>, TVServiceAPIManager* > TTIPCManagerMap;
	static TTIPCManagerMap m_instances;
	static pthread_rwlock_t m_rwlock; // lock for instance creation
	
	TCIPCManager* m_pIPCManager;
};

#endif // _TVSERVICEAPIMANAGER_H_