/** 
 * @file NativeConnection.h
 * @brief Native connection class for External API Native objects
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

#ifndef _NATIVECONNECTION_H_
#define _NATIVECONNECTION_H_

#include <memory>
#include "IIPCListener.h"
#include "ICallListener.h"
#include "IIPCProperties.h"

class TCNativeConnection : public TIIPCListener
{
public:
	TCNativeConnection( std::auto_ptr<TICallListener> nativeAPIObject, TIIPCProperties* pPropertiesListener);
	/**
	 * @see base class
	 */
	virtual std::string GetInterfaceName( void );

	/**
	 * @see base class
	 */
	virtual bool HandleMessage( DBusConnection* pConnection, DBusMessage* pMessage );

	/**
	 * @see base class
	 */
	virtual std::string GetIntrospectionInfo( void );
	
private: 
	std::auto_ptr<TICallListener> m_listener;
	TIIPCProperties* m_pPropertiesListener;
};

#endif // _NATIVECONNECTION_H_
