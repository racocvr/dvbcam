/**
 * @file IIPCProperties.h
 * @brief It is used to manage IPC properties like pid and name of IPC caller from proxy side
 *
 * Copyright 2015 by Samsung Electronics, Inc.,
 *
 * This software is the confidential and proprietary information
 * of Samsung Electronics, Inc. ("Confidential Information"). You
 * shall not disclose such Confidential Information and shall use
 * it only in accordance with the terms of the license agreement
 * you entered into with Samsung.
 */

#ifndef _IIPCPROPERTIES_H_
#define _IIPCPROPERTIES_H_

#include "IPCDataType.h"
#include <string>

class TIIPCProperties
{
public:
	virtual ~TIIPCProperties(){};

	/**
	 * @brief Adds new caller properties to map
	 * @param [in] id it is unique name of caller. To make it unique name assigned by dbus is used.
	 * @param [in] properties contains caller properties like pid and process name
	 * @return true if success. Otherwise false.
	 */
	virtual bool AddCaller(const std::string& id, const TSCallerProperties& properties) = 0;

	/**
	 * @brief This method is invoked to set id of current caller. ID of process from which request was sent.
	 * @param [in] id it is unique name of caller. To make it unique name assigned by dbus is used.
	 * @return true if given id exists. Otherwise false.
	 */
	virtual bool SetCurrentCaller(const std::string& id) = 0;

	/**
	 * @brief This method is invoked to clear id of current caller. ID of process from which request was sent.
	 */
	virtual void ClearCurrentCaller() = 0;
};

class TCIPCPropertiesWrapper
{
public:
	TCIPCPropertiesWrapper(TIIPCProperties& ipcProperties) :
		m_ipcProperties(ipcProperties)
	{
	}

	~TCIPCPropertiesWrapper()
	{
		m_ipcProperties.ClearCurrentCaller();
	}
private:
	TIIPCProperties& m_ipcProperties;
};

#endif /* _IIPCPROPERTIES_H_ */
