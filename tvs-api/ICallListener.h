/** 
 * @file ICallListener.h
 * @brief Middleware internal interface inherited by all External API native objects for listening of incoming method calls
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

#ifndef _ICALLLISTENER_H_
#define _ICALLLISTENER_H_

#include "MessageBuffer.h"

class TICallListener
{
public:
	virtual ~TICallListener(){};

	/**
	 * @brief Used by listener if method is called from External API proxy.
	 * @param [in] functionCode Code of an interface method.
	 * @param [out] inputData Data buffer with input values.
	 * @param [out] outputData Data buffer with output values.
	 * @return Returns true if call was handled successfully, otherwise returns false.
	 */
	virtual bool OnCallReceived(const int functionCode, TCMessageBuffer& inputData, TCMessageBuffer& outputData) = 0;

	/**
	 * @brief Gets name of the interface.
	 * @return Interface name used on DBus.
	 */
	virtual std::string GetInterfaceName( void ) = 0;
};

#endif // _ICALLLISTENER_H_

