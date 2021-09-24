/** 
 * @file IPCWrapper.h
 * @brief Tool classes to ensure no memory leaks in IPC. 
 * @brief Whenever you create one of IPC wrappers as local variable and pass pointer to DBus structure, wrapper will ensure proper unreferencing / cleaning of this structure at the end of code block.
 *
 * Copyright 2014 by Samsung Electronics, Inc.,
 * 
 * This software is the confidential and proprietary information
 * of Samsung Electronics, Inc. ("Confidential Information"). You
 * shall not disclose such Confidential Information and shall use
 * it only in accordance with the terms of the license agreement
 * you entered into with Samsung.
 */

#ifdef _WIN32
#include "glib.h" //fake for external api test under Windows
#include <windows.h>
#else
#include <unistd.h>
#include <dbus/dbus-glib.h>
#include <dbus/dbus-glib-lowlevel.h>
#endif

class TCDBusMessageWrapper
{
public: 
	TCDBusMessageWrapper(DBusMessage* pMsg) : m_pMessage(pMsg) {};

	~TCDBusMessageWrapper()
	{
		dbus_message_unref(m_pMessage); // free message
	}
private:
	TCDBusMessageWrapper & operator= (const TCDBusMessageWrapper & base) { return *this; }; // using assign operator is not allowed
	TCDBusMessageWrapper(const TCDBusMessageWrapper & base){}; // using copy constructor is not allowed
	
	DBusMessage* m_pMessage;
};

class TCDBusPendingCallWrapper
{
public: 
	TCDBusPendingCallWrapper(DBusPendingCall* pCall) : m_pPendingCall(pCall) {};

	~TCDBusPendingCallWrapper()
	{
		dbus_pending_call_unref (m_pPendingCall); // free pending call
	}
private:
	TCDBusPendingCallWrapper & operator= (const TCDBusPendingCallWrapper & base) { return *this; }; // using assign operator is not allowed
	TCDBusPendingCallWrapper(const TCDBusPendingCallWrapper & base){}; // using copy constructor is not allowed
	
	DBusPendingCall* m_pPendingCall;
};
