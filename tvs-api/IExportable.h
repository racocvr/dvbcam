/** 
 * @file IExportable.h
 * @brief Middleware internal interface for TVS interfaces that want to be exportable to SBB side.
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

#ifndef _IEXPORTABLE_H_
#define _IEXPORTABLE_H_

#include <string>
#include "MessageBuffer.h"

class TIExportable
{
public:
	virtual ~TIExportable(){};

	/**
	 * @brief Gets information about interface structure for Dbus introspection.
	 * @return Retrospection info about interface.
	 */
	virtual std::string GetIntrospectionInfo( void ) = 0;
};

#endif // _IEXPORTABLE_H_

