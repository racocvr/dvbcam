// This file shall be removed on 09.15.2015.
 
#ifdef _WIN32
#pragma once
#endif

#ifndef _IIPCMANAGER_H_
#define _IIPCMANAGER_H_

#include <string>
#include <pthread.h>
#include <memory>

#include "MessageBuffer.h"
#include "Marshalable.h"
#include "IPCDataType.h"
#include "TVServiceDataType.h"
#include "IIPCListener.h"
#include "ICallListener.h"

class TIIPCManager
{
public:
	virtual ~TIIPCManager(){};
	
	/**
	 * @brief Sends serializable object to selected recipient with set message ID.
	 * @param [in] type Type of message to be sent.
	 * @param [in] receiverId Unique connection name of message receiver.
	 * @param [in] messageId ID of a message.
	 * @param [in] messageData Serializable object that ought to be sent.
	 * @return Returns information if message was sent or any error occured.
	 */
	virtual EIPCSendMessageReturn Send(EIPCMessageType type, const std::string& receiverId, const int messageId, TCMarshalable* messageData) = 0; 	

	/**
	 * @brief Sends data buffer in a broadcast scheme with set message Id and TVS handle.
	 * @param [in] type Type of message to be sent.
	 * @param [in] messageId Id of a message.
	 * @param [in] handle Defines TVS pipeline.
	 * @param [in] messageData Data buffer that ought to be sent.
	 * @return Returns information if message was sent or any error occured.
	 */
	virtual EIPCSendMessageReturn Send(EIPCMessageType type, int messageId, const TVSHandle& handle, TCMessageBuffer& messageData) = 0;

	/**
	 * @brief Starts new native API listener.
	 * @remark After calling this method TIIPCManager is the owner of pointed object and will manage its lifetime.
	 * @param [in] nativeAPI Native API object that will handle method calls.
	 * @return Returns true if listener was attached, otherwise returns false.
	 */
	virtual bool StartNativeAPI(std::auto_ptr<TICallListener> nativeAPI) = 0; 

	/**
	 * @brief Attaches new listener to DBus incoming messages.
	 * @remark After calling this method TIIPCManager is the owner of pointed object and will manage its lifetime.
	 * @param [in] listener Object that will handle DBus messages.
	 * @return Returns true if listener was attached, otherwise returns false.
	 */
	virtual bool AttachListener(std::auto_ptr<TIIPCListener> listener) = 0;
	
	/**
	 * @brief Returns properties of current caller that invokes tvs-api from proxy side.
	 * This method can be only use in thread of g_main_loop.
	 * There is no way to provide synchronization from the others threads.
	 * @return properties of caller from proxy side.
	 */
	virtual const TSCallerProperties& GetCallerProperties() const = 0;

	/**
	 * @brief Returns instance of an interface.
	 * @return Interface object.
	 */
	static TIIPCManager* GetInstance();

private:
	static TIIPCManager* m_pInstance; 
	static pthread_rwlock_t m_rwlock;
};

#endif // _IIPCMANAGER_H_
