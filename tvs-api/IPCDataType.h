/** 
 * @file IPCDataType.h
 * @brief Data types of IPC part of tvs-api
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

#ifndef _IPCDATATYPE_H_
#define _IPCDATATYPE_H_

#include <string>

// TODO Duende - consider split into Signal and Data
typedef enum 
{
	IPC_MESSAGE_SIGNAL,			//!< for signals from TVS
	IPC_MESSAGE_PIPELINE_EVENT,	//!< for pipeline signals from TVS
	IPC_MESSAGE_DATA,
	IPC_MESSAGE_PROGRAM,
	IPC_MESSAGE_SECTION,
	IPC_MESSAGE_TEXTDATA,
	IPC_MESSAGE_DSM,
	IPC_MESSAGE_COPY_PROTECTION,
	IPC_MESSAGE_PESDATA,
	IPC_MESSAGE_EXPESDATA,
	IPC_MESSAGE_HT,
	IPC_MESSAGE_MAX,
} EIPCMessageType;

typedef enum
{
	MARSHALABLE_STORAGE_MAP, // default use, no multiple tags, fast find
	MARSHALABLE_STORAGE_LIST, // use only if you know how to use it, multiple tags allowed, slow find 
} EMarshalableStorageType;

typedef enum
{
	IPC_SEND_MESSAGE_OK,			// everthing is ok and message was sent
	IPC_SEND_MESSAGE_NO_RECEIVER,	// receiver is disconnected
	IPC_SEND_MESSAGE_TOO_BIG,		// message extends allowed size
	IPC_SEND_MESSAGE_ERROR,			// other errors
} EIPCSendMessageReturn;

//Flags that are sent from proxy side to native side. It can be 16 bits wide.
enum
{
	IPC_FLAG_NONE,
	IPC_FLAG_ASYNC = 0x01,					//proxy side does not wait for reply if this flag is set
	IPC_FLAG_HELLO = 0x02,					//proxy side sends app name and PID, this flag is use to send those data only once
};

//!< It stores caller properties that are sent from proxy side
struct TSCallerProperties
{
	TSCallerProperties() :
			pid(0)
	{
	}
	std::string name;			// name that is taken from __progname
	unsigned int pid;			// process ID that call given IP
};

#define TVSERVICE_INTERFACE_NAME "com.samsung.TVService.SignalIFace"
#define TVSERVICE_OBJECT_NAME "/com/samsung/TVService/SignalObject"

#endif // _IPCDATATYPE_H_
