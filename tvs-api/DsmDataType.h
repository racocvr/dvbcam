/** 
 * @file DsmDataType.h
 * @brief DSM related types.
 *
 * Copyright 2014 by Samsung Electronics, Inc.,
 * 
 * This software is the confidential and proprietary information
 * of Samsung Electronics, Inc. ("Confidential Information"). You
 * shall not disclose such Confidential Information and shall use
 * it only in accordance with the terms of the license agreement
 * you entered into with Samsung.
 */

#ifndef _DSMDATATYPE_H_
#define _DSMDATATYPE_H_

#include "Marshalable.h"
#include <string>
#include <vector>
#include <list>

typedef enum
{
	DSM_STATUS_UNKNOWN = -1,		//*< unknown (Initial)
	DSM_STATUS_OK,
	DSM_STATUS_NOT_FOUND,
	DSM_STATUS_NOT_AVAILABLE,
	DSM_STATUS_ABORT,
}EDsmStatus;

typedef enum
{
	DSM_OBJECT_TYPE_UNKNOWN,			//*< unknown (Initial)
	DSM_OBJECT_TYPE_FILE,				//*< type of File
	DSM_OBJECT_TYPE_SGW,				//*< type of Service Gate Way
	DSM_OBJECT_TYPE_DIRECTORY,			//*< type of Directory
	DSM_OBJECT_TYPE_STREAM,				//*< type of Stream
	DSM_OBJECT_TYPE_STREAM_EVENT,		//*< type of Stream Event
}EDsmObjectType;

typedef enum
{
	DSM_OBJLOAD_UNKNOWN = -1,			//*< unknown (Initial)
	DSM_OBJLOAD_ASYNC,
	DSM_OBJLOAD_DIR_ENTRIES,
	DSM_OBJLOAD_CP_ZERO,				//*< object is loaded only from stream
	DSM_CONTENT_TYPE_ASYNC,
}EDsmObjectLoadType;

typedef enum
{
	DSM_ATTACH_TYPE_BOUND,
	DSM_ATTACH_TYPE_SERVICE_UNBOUND,
	DSM_ATTACH_TYPE_MUX_UNBOUND,
}EDsmAttachType;

typedef enum
{
	DSM_DATASERVICE_TYPE_MHEG,
	DSM_DATASERVICE_TYPE_MHP,
	DSM_DATASERVICE_TYPE_GINGA,
	DSM_DATASERVICE_TYPE_DEFAULT,		//*< data service type defined in country spec is used
}EDsmDataServiceType;

typedef enum
{
	DSM_MSG_UNKNOWN,					//*< unknown (Initial)
	DSM_MSG_ATTACH,						//*< TSDsmAttach
	DSM_MSG_LOAD,						//*< TSDsmObject
	DSM_MSG_DIR_ENTRIES,				//*< TSDsmDirEntries
	DSM_MSG_STREAM_OPEN,				//*< TSDsmStream
	DSM_MSG_STREAM_INFO,				//*< TSDsmStreamInfo
	DSM_MSG_STREAM_TAP,					//*< TSDsmStreamTapList
	DSM_MSG_EVENT_LIST,					//*< TSDsmEventList
	DSM_MSG_EVENT_OCCURED,				//*< TSDsmEvent
	DSM_MSG_EVENT_SUBS_FAIL,			//*< TSDsmEvent
	DSM_MSG_DSI_VERSION_CHANGED,		//*< TSDsmMessage - no data
	DSM_MSG_OBJECT_NAME,				//*< TSDsmObjectName
	DSM_MSG_OBJECT_CHANGED,				//*< TSDsmObjectChanged
	DSM_MSG_MONITOR_DELETED,			//*< TSDsmMonitorDeleted
	DSM_MSG_CACHED_LIST,				//*< TSDsmCachedInfoList
}EDsmMessageType;

class TCTreeFormatter;

struct TSDsmMessage: public TCMarshalable
{
	enum
	{	
		TAG_HANDLE,
		TAG_STATUS,
		TAG_MESSAGETYPE,
		TAG_USERPARAM,
		TAG_MAX = 100,
	};

	unsigned int sessionHandle;
	EDsmStatus status;
	EDsmMessageType messageType;
	void* userParam;

	TSDsmMessage();

		/* Methods which implement marshaling */
	virtual bool ClassToTree(TCTreeBranch& treeParent);
	virtual bool TreeToClass(TCTreeBranch& treeMine);
};

struct TSDsmAttach: TSDsmMessage
{
	enum
	{	
		TAG_DOMAINPREFIX = TAG_MAX,
	};

	std::string domainPrefix;

	TSDsmAttach();

	/* Methods which implement marshaling */
	virtual bool ClassToTree(TCTreeBranch& treeParent);
	virtual bool TreeToClass(TCTreeBranch& treeMine);
};

struct TSDsmExceptionServiceXFR: public TCMarshalable
{
	enum
	{	
		TAG_NSAP,
		TAG_OBJTYPE,
		TAG_PATH,
	};

	std::vector<unsigned char> nsap;
	EDsmObjectType objectType;
	std::vector<unsigned char> path;

	TSDsmExceptionServiceXFR();

	/* Methods which implement marshaling */
	virtual bool ClassToTree(TCTreeBranch& treeParent);
	virtual bool TreeToClass(TCTreeBranch& treeMine);
};

struct TSDsmObject: TSDsmMessage
{
	enum
	{	
		TAG_PATH = TAG_MAX,
		TAG_OBJLOADTYPE,
		TAG_OBJECTTYPE,
		TAG_CREATIONTIME,
		TAG_SERVICEXFR,
		TAG_CONTENTTYPE,
		TAG_MODULEVERSION,
		TAG_FILECONTENT2,
	};

	std::string path;
	EDsmObjectLoadType objectLoadType;
	EDsmObjectType objectType;
	unsigned int creationTime;
	TSDsmExceptionServiceXFR serviceXFR;
	std::string contentType;
	unsigned char moduleVersion;
	std::vector<unsigned char> file;		//*< content of requested file

	TSDsmObject();
	
	/* Methods which implement marshaling */
	virtual bool ClassToTree(TCTreeBranch& treeParent);
	virtual bool TreeToClass(TCTreeBranch& treeMine);

protected:
	virtual void t_FillFormatter(TCTreeFormatter& treeFormatter);
};

struct TSDsmDirEntry: public TCMarshalable
{
	enum
	{	
		TAG_ENTRY_NAME,
		TAG_OBJTYPE,
	};

	std::string name;
	EDsmObjectType objectType;

	TSDsmDirEntry();

	/* Methods which implement marshaling */
	virtual bool ClassToTree(TCTreeBranch& treeParent);
	virtual bool TreeToClass(TCTreeBranch& treeMine);
};

struct TSDsmDirEntries: TSDsmMessage
{
	enum
	{	
		TAG_PATH = TAG_MAX,
		TAG_DIRENTRIES,
	};

	std::string path;
	std::list<TSDsmDirEntry> dirEntries;

	TSDsmDirEntries();

	/* Methods which implement marshaling */
	virtual bool ClassToTree(TCTreeBranch& treeParent);
	virtual bool TreeToClass(TCTreeBranch& treeMine);
};

struct TSDsmStream: TSDsmMessage
{
	enum
	{	
		TAG_STREAMHANDLE = TAG_MAX,
		TAG_SERVICEID,
	};

	unsigned int streamHandle;
	unsigned short serviceID;

	TSDsmStream();

	/* Methods which implement marshaling */
	virtual bool ClassToTree(TCTreeBranch& treeParent);
	virtual bool TreeToClass(TCTreeBranch& treeMine);
};

struct TSDsmNPT : public TCMarshalable
{
	enum
	{	
		TAG_SECONDS,
		TAG_USECONDS,
	};
	unsigned int seconds;				//*< seconds
	unsigned int useconds;				//*< microseconds

	TSDsmNPT() : seconds(0), useconds(0) {};
	
	/* Methods which implement marshaling */
	virtual bool ClassToTree(TCTreeBranch& treeParent);
	virtual bool TreeToClass(TCTreeBranch& treeMine);
};

struct TSDsmStreamInfoData: public TCMarshalable
{
	enum
	{	
		TAG_DESCRIPTION,
		TAG_DURATION,
		TAG_VIDEO,
		TAG_AUDIO,
		TAG_DATA
	};

	std::string description;			//*< stream description 
	TSDsmNPT duration;					//*< duration of stream
	unsigned char video;				//*< video component
	unsigned char audio;				//*< audio component
	unsigned char data;					//*< data component

	TSDsmStreamInfoData();

	/* Methods which implement marshaling */
	virtual bool ClassToTree(TCTreeBranch& treeParent);
	virtual bool TreeToClass(TCTreeBranch& treeMine);
};

struct TSDsmStreamInfo: TSDsmMessage
{
	enum
	{	
		TAG_STREAMHANDLE = TAG_MAX,
		TAG_SERVICEID,
		TAG_STREAMINFO,
	};

	unsigned int streamHandle;			//*< stream handle
	unsigned short serviceID;
	TSDsmStreamInfoData streamInfoData;			//*< stream info

	TSDsmStreamInfo();

	/**
	 * @see base class
	 */
	virtual bool ClassToTree(TCTreeBranch& treeParent);

	/**
	 * @see base class
	 */
	virtual bool TreeToClass(TCTreeBranch& treeMine);
};

struct TSDsmStreamTap: public TCMarshalable
{
	enum
	{	
		TAG_ID,
		TAG_USE,
		TAG_TAG,
	};

	unsigned short id;					//*< tap ID
	unsigned short use;					//*< to select program, stream OR ES
	unsigned short tag;					//*< association tag

	TSDsmStreamTap();

	/* Methods which implement marshaling */
	virtual bool ClassToTree(TCTreeBranch& treeParent);
	virtual bool TreeToClass(TCTreeBranch& treeMine);
};

struct TSDsmStreamTapList: TSDsmMessage
{
	enum
	{	
		TAG_STREAMHANDLE = TAG_MAX,
		TAG_SERVICEID,
		TAG_STREAMTAPS,
	};

	unsigned int streamHandle;					//*< stream handle
	unsigned short serviceID;
	std::list<TSDsmStreamTap> streamTaps;		//*< list of taps

	TSDsmStreamTapList();

	/* Methods which implement marshaling */
	virtual bool ClassToTree(TCTreeBranch& treeParent);
	virtual bool TreeToClass(TCTreeBranch& treeMine);
};

struct TSDsmEventItem: public TCMarshalable
{
	enum
	{	
		TAG_EVENTNAME,
		TAG_EVENTID,
	};

	std::string eventName;				//*< event name
	unsigned short eventID;				//*< event ID

	TSDsmEventItem();

	/* Methods which implement marshaling */
	virtual bool ClassToTree(TCTreeBranch& treeParent);
	virtual bool TreeToClass(TCTreeBranch& treeMine);
};

struct TSDsmEventList: TSDsmMessage
{
	enum
	{	
		TAG_STREAMHANDLE = TAG_MAX,
		TAG_SERVICEID,
		TAG_STREAMEVENTS,
	};

	unsigned int streamHandle;				//*< stream handle
	unsigned short serviceID;
	std::list<TSDsmEventItem> events;		//*< list of events

	TSDsmEventList();

	/* Methods which implement marshaling */
	virtual bool ClassToTree(TCTreeBranch& treeParent);
	virtual bool TreeToClass(TCTreeBranch& treeMine);
};

struct TSDsmEvent: TSDsmMessage
{
	enum
	{	
		TAG_STREAMHANDLE = TAG_MAX,
		TAG_EVENTID,
		TAG_NPTREF,
		TAG_PRIVATEDATA,
		TAG_VERSION
	};

	unsigned int streamHandle;			//*< stream handle
	unsigned short eventID;				//*< event ID
	long long NPTRef;					//*< NPT Ref. for Scheculed Event
	std::vector<unsigned char> privateData;
	unsigned int version;				//*< the version of section

	TSDsmEvent();

	/* Methods which implement marshaling */
	virtual bool ClassToTree(TCTreeBranch& treeParent);
	virtual bool TreeToClass(TCTreeBranch& treeMine);	
};

struct TSDsmObjectLocation: public TCMarshalable
{
	enum
	{	
		TAG_CAROUSELID,
		TAG_MODULEID,
		TAG_OBJECTKEY,
	};

	unsigned int carouselID;
	unsigned short moduleID;
	std::string objectKey;

	TSDsmObjectLocation();

		/* Methods which implement marshaling */
	virtual bool ClassToTree(TCTreeBranch& treeParent);
	virtual bool TreeToClass(TCTreeBranch& treeMine);
};

struct TSDsmObjectName: TSDsmMessage
{
	enum
	{	
		TAG_ENTRYLOCATION = TAG_MAX,
		TAG_PARENTDIRPATH,
		TAG_ENTRYNAME,
	};

	TSDsmObjectLocation entryLocation;
	std::string parentDirPath;
	std::string entryName;

	TSDsmObjectName();

	/* Methods which implement marshaling */
	virtual bool ClassToTree(TCTreeBranch& treeParent);
	virtual bool TreeToClass(TCTreeBranch& treeMine);	
};

struct TSDsmObjectChanged: TSDsmMessage
{
	enum
	{	
		TAG_PATH = TAG_MAX,
		TAG_OBJTYPE,
		TAG_VERSION
	};

	std::string path; /**< Full object path */
	EDsmObjectType objectType;
	unsigned int version;

	TSDsmObjectChanged();

	/* Methods which implement marshaling */
	virtual bool ClassToTree(TCTreeBranch& treeParent);
	virtual bool TreeToClass(TCTreeBranch& treeMine);	
};

struct TSDsmMonitorDeleted: TSDsmMessage
{
	enum
	{
		TAG_PATH = TAG_MAX,
		TAG_OBJTYPE
	};

	std::string path; /**< Full object path */
	EDsmObjectType objectType;

	TSDsmMonitorDeleted();

	/* Methods which implement marshaling */
	virtual bool ClassToTree(TCTreeBranch& treeParent);
	virtual bool TreeToClass(TCTreeBranch& treeMine);
};

struct TSApplicationProfile : public TCMarshalable
{
	enum
	{
		TAG_APPLICATION_PROFILE,
		TAG_VERSION_MAJOR,
		TAG_VERSION_MINOR,
		TAG_VERSION_MICRO,
	};

	unsigned short applicationProfile;
	unsigned char versionMajor;
	unsigned char versionMinor;
	unsigned char versionMicro;

	TSApplicationProfile();

	/* Methods which implement marshaling */
	virtual bool ClassToTree(TCTreeBranch& treeParent);
	virtual bool TreeToClass(TCTreeBranch& treeMine);

protected:
	virtual void t_FillFormatter(TCTreeFormatter& treeFormatter);
};

#endif //_DSMDATATYPE_H_
