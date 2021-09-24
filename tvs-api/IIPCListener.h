/** 
 * @file IIPCListener.h
 * @brief Middleware internal interface inherited by all classes that want to handle IPC messages.
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

#ifndef _IIPCLISTENER_H_
#define _IIPCLISTENER_H_

#include <string>

struct DBusConnection;
struct DBusMessage;

class TIIPCListener
{
public:
	virtual ~TIIPCListener(){};

	/**
	 * @brief Gets name of the interface.
	 * @return Interface name used on DBus.
	 */
	virtual std::string GetInterfaceName( void ) = 0;

	/**
	 * @brief Handles IPC (DBus) message
	 * @param [in] pConnection Connection to DBus.
	 * @param [in] pMessage DBus message to be handled.
	 * @return Returns true message was handled, false otherwise.
	 */
	virtual bool HandleMessage(DBusConnection* pConnection, DBusMessage* pMessage) = 0;

	/**
	 * @brief Gets information about interface structure for Dbus introspection.
	 * @return Retrospection info about interface.
	 */
	virtual std::string GetIntrospectionInfo( void ) = 0;
};

#endif // _IIPCLISTENER_H_
