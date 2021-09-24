// This file shall be removed on 09.15.2015.

#ifdef _WIN32
#pragma once
#endif

#ifndef _IIPCCONNECTION_H_
#define _IIPCCONNECTION_H_

#include <string>

#include "MessageBuffer.h"
#include "IPCDataType.h"

typedef void (*IPCCallbackFunction)(int, TCMessageBuffer&); // IPC Callback Function (parameters: messageId, messageData)

class TIIPCConnection
{
public:
	virtual ~TIIPCConnection(){};
	
	/**
	 * @brief Returns pointer to instance of an interface.
	 * @return Interface object pointer.
	 */
	static TIIPCConnection* GetInstance();
	
	/**
	 * @brief Destroys kept instance of interface.
	 */
	static void Destroy();
	
	/**
	 * @brief Connects to data bus to enable receiving data from middleware and calling methods.
	 * @return Returns true if successfully connected, otherwise returns false.
	 */
	virtual bool Connect(void) = 0;
	
	/**
	 * @brief Adds match rule which has to be fulfilled to receive message.
	 * @param [in] messageType Type of message. 
	 * @param [in] messageId ID of a message.
	 * @return Returns true if match rule was added, otherwise returns false.
	 */
	virtual bool AddMatchRule(const int messageId) = 0;

	/**
	 * @brief Deletes match rule which has to be fulfilled to receive message.
	 * @param [in] messageType Type of message.  
	 * @param [in] messageId ID of a message.
	 * @return Returns true if match rule was removed, otherwise returns false.
	 */
	virtual bool RemoveMatchRule(const int messageId) = 0;

	/**
	 * @brief Calls method from external API.
	 * @param [in] interfaceName Name of interface that handles method call.
	 * @param [in] functionCode Code of a method on interface.
	 * @param [in] inputData Input data buffer for method call.
	 * @param [out] outputData Output data buffer.
	 * @return Returns true if method called successfully, otherwise returns false.
	 */
	virtual bool Call(const std::string& interfaceName, const int functionCode, TCMessageBuffer& inputData, TCMessageBuffer& outputData) = 0;
	
	/**
	 * @brief Waits until there is listener of the interface.
	 * @param [in] interfaceName Name of interface that handles method call.
	 * @return Returns true if listener of the interface exists, otherwise returns false.
	 */
	virtual bool WaitForCreateInterface(const char* interfaceName) = 0;

	/**
	 * @brief Sets a function that will be called when IPC message arrives.
	 * @param [in] type Type of IPC message.
	 * @param [in] functionCB Pointer to callback function.
	 */
	virtual void SetCallbackFunction(EIPCMessageType type, IPCCallbackFunction functionCB) = 0;
	
	/**
	 * @brief Returns unique connection id for object.
	 * @return Returns unique connection id.
	 */
	virtual std::string* GetConnectionId() = 0;

private:
	static TIIPCConnection* m_pInstance; 
};

#endif // _IIPCCONNECTION_H_

