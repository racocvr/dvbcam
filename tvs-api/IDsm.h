/** 
 * @file IDsm.h
 * @brief DSM Interface for getting data from Object Carousel
 *
 * Copyright 2014 by Samsung Electronics, Inc.,
 * 
 * This software is the confidential and proprietary information
 * of Samsung Electronics, Inc. ("Confidential Information"). You
 * shall not disclose such Confidential Information and shall use
 * it only in accordance with the terms of the license agreement
 * you entered into with Samsung.
 */

#ifndef _IDSM_H_
#define _IDSM_H_

#include "MarshallingMarks.h"
#include "DsmDataType.h"

typedef void (*DsmCallback)(TSDsmMessage& dsmMessage);

class IDsm
{
protected:
	virtual ~IDsm(){}
public:

	/**
	 * @brief Requests attaching of object carousel based on NSAP.
	 * @remarks DsmCallback method will be called when the result is ready.
	 * TSDsmAttach will be passed to the callback with messageType equal to DSM_MSG_ATTACH.
	 * @param [out] sessionHandle Session handle associated with object carousel (needed for the other methods)
	 * @param [in] nsap Network Service Access Point address
	 * @param [in] dataServiceType Type of data service
	 * @param [in] attachType Type of attach
	 * @param [in] userParam User data which will be passed in the callback.
	 * @param [in] clearCache If true DSM cache will be cleared when attach succeeded
	 * @return 1 on success
	 * @return 0 on DSM error
	 * @return -1 on D-Bus communication error
	 *
	 * @par Example
	 * @code
	 *
	 * void OnDsmCallback(TSDsmMessage& dsmMessage)
	 * {
	 * 	if (dsmMessage.messageType == DSM_MSG_ATTACH)
	 * 	{
	 * 		TSDsmAttach& dsmAttach = static_cast<TSDsmAttach&>(dsmMessage);
	 * 		//do something with attach result
	 * 	}
	 * }
	 *
	 * unsigned int cid = 0x20;
	 * unsigned short tsid = 0x12;
	 * unsigned short onid = 0x15;
	 * unsigned short sid = 0x55;
	 * std::vector<unsigned char> nsap(20);
	 * nsap[0] = 0; // AFI
	 * nsap[1] = 0; // type
	 * nsap[2] = ((cid>>24) & 0xFF); // carousel
	 * nsap[3] = ((cid>>16) & 0xFF); // ...
	 * nsap[4] = ((cid>> 8) & 0xFF); // ...
	 * nsap[5] = ((cid)     & 0xFF);  // ID
	 * nsap[6] = 1;                         // specifier::specifierType IEEE (ETSI is 0, but see table B.26 in MHP1.0.3 B.2.3.7.2)
	 * nsap[7] = 0x00;                      // specifier::OUI: DVB
	 * nsap[8] = 0x01;                      // specifier::OUI: DVB
	 * nsap[9] = 0x5a;                      // specifier::OUI: DVB
	 * nsap[10]= ((tsid>>8) & 0xFF); // tsid
	 * nsap[11]= ((tsid)    & 0xFF);  // tsid
	 * nsap[12]= ((onid>>8) & 0xFF); // onid
	 * nsap[13]= ((onid)    & 0xFF);  // onid
	 * nsap[14]= (( sid>>8) & 0xFF); //  sid
	 * nsap[15]= (( sid)    & 0xFF);  //  sid
	 * nsap[16]= 0xff;               // reserved: 0xffffffff
	 * nsap[17]= 0xff;
	 * nsap[18]= 0xff;
	 * nsap[19]= 0xff;
	 *
	 * IDsm * pDsm = NULL;
	 * TVServiceAPI::CreateDsm(&OnDsmCallback, &pDsm);
	 * unsigned int sessionHandle;
	 *
	 * if (pDsm->RequestAttach(sessionHandle, nsap, DSM_DATASERVICE_TYPE_MHP, DSM_ATTACH_TYPE_BOUND, this) > 0)
	 * {
	 * 	//succeeded
	 * }
	 *
	 * @endcode
	 */
	virtual int RequestAttach(
			_OUT_ unsigned int& sessionHandle,
			_IN_ const std::vector<unsigned char>& nsap,
			_IN_ EDsmDataServiceType dataServiceType,
			_IN_ EDsmAttachType attachType,
			_IN_ void* userParam,
			_IN_ bool clearCache = false) = 0;

	/**
	 * @brief Detaches existing object carousel session.
	 * @remarks sessionHandle becomes invalid if this method is called
	 * @pre Object carousel needs to be attached.
	 * @param [in] sessionHandle Session handle associated with RequestAttach
	 * @return 1 on success
	 * @return 0 on DSM error
	 * @return -1 on D-Bus communication error
	 *
	 * @par Example
	 * @code
	 *
	 * void OnDsmCallback(TSDsmMessage& dsmMessage)
	 * {
	 * }
	 *
	 * IDsm * pDsm = NULL;
	 * TVServiceAPI::CreateDsm(&OnDsmCallback, &pDsm);
	 *
	 * //unsigned int sessionHandle = 0x20; //session handle associated with RequestAttach
	 *
	 * if (pDsm->Detach(sessionHandle) > 0)
	 * {
	 * 	//succeeded
	 * }
	 *
	 * @endcode
	 */
	virtual int Detach(_IN_ unsigned int sessionHandle) = 0;

	/**
	 * @brief Requests loading of an object or a directory contents from object carousel.
	 * @remarks DsmCallback method will be called when the result is ready.
	 * TSDsmObject (or TSDsmDirEntries if directory was requested) will be passed to the callback.
	 * To request directory contents RequestObjectLoad has to be called with DSM_OBJLOAD_DIR_ENTRIES.
	 * messageType is equal to DSM_MSG_LOAD (or DSM_MSG_DIR_ENTRIES if directory was requested).
	 * @remarks Object path needs to include the domain prefix.
	 * @pre Object carousel needs to be attached.
	 * @param [in] sessionHandle Session handle associated with RequestAttach
	 * @param [in] path Path to object that will be loaded
	 * @param [in] loadType type of load
	 * @param [in] userParam User data which will be passed in the callback.
	 * @return 1 on success
	 * @return 0 on DSM error
	 * @return -1 on D-Bus communication error
	 *
	 * @par Example
	 * @code
	 *
	 * void OnDsmCallback(TSDsmMessage& dsmMessage)
	 * {
	 * 	if (dsmMessage.messageType == DSM_MSG_LOAD)
	 * 	{
	 * 		TSDsmObject& dsmObject = static_cast<TSDsmObject&>(dsmMessage);
	 * 		//do something with DSM object
	 * 	}
	 * 	else if (dsmMessage.messageType == DSM_MSG_DIR_ENTRIES)
	 * 	{
	 * 		TSDsmDirEntries& dsmDirEntries = static_cast<TSDsmDirEntries&>(dsmMessage);
	 * 		//do something with DSM dir entries
	 * 	}
	 * }
	 *
	 * IDsm * pDsm = NULL;
	 * TVServiceAPI::CreateDsm(&OnDsmCallback, &pDsm);
	 *
	 * if (pDsm->RequestObjectLoad(sessionHandle, "/dsm/DTV000E0800/CRS00000001/test/suite/30", DSM_OBJLOAD_ASYNC, this) > 0)
	 * {
	 * 	//succeeded
	 * }
	 *
	 * @endcode
	 */
	virtual int RequestObjectLoad(
			_IN_ unsigned int sessionHandle,
			_IN_ const std::string& path,
			_IN_ EDsmObjectLoadType loadType,
			_IN_ void* userParam) = 0;

	/**
	 * @brief Aborts loading of an object from object carousel.
	 * @remarks This method aborts not finished request made by RequestObjectLoad.
	 * DsmCallback method will be called when the result is ready.
	 * TSDsmObject will be passed to the callback with messageType equal to DSM_MSG_LOAD.
	 * @remarks Object path needs to include the domain prefix.
	 * @pre Object carousel needs to be attached.
	 * @param [in] sessionHandle Session handle associated with RequestAttach
	 * @param [in] path Path to object
	 * @return 1 on success
	 * @return 0 on DSM error
	 * @return -1 on D-Bus communication error
	 *
	 * @par Example
	 * @code
	 *
	 * void OnDsmCallback(TSDsmMessage& dsmMessage)
	 * {
	 * 	if (dsmMessage.messageType == DSM_MSG_LOAD)
	 * 	{
	 * 		TSDsmObject& dsmObject = static_cast<TSDsmObject&>(dsmMessage);
	 * 		//do something
	 * 	}
	 * }
	 *
	 * IDsm * pDsm = NULL;
	 * TVServiceAPI::CreateDsm(&OnDsmCallback, &pDsm);
	 * //unsigned int sessionHandle = 0x20; //session handle associated with RequestAttach
	 *
	 * if (pDsm->AbortObjectLoad(sessionHandle, "/dsm/DTV000E0800/CRS00000001/test/suite/30") > 0)
	 * {
	 * 	//succeeded
	 * }
	 *
	 * @endcode
	 */
	virtual int AbortObjectLoad(_IN_ unsigned int sessionHandle, _IN_ const std::string& path) = 0;

	/**
	 * @brief Starts monitoring version changes of an object in object carousel.
	 * @remarks DsmCallback method will be called every time when version of the object is changed
	 * TSDsmObjectChanged will be passed to the callback with messageType equal
	 * to DSM_MSG_OBJECT_CHANGED.
	 * @remarks Object path needs to include the domain prefix.
	 * @pre Object carousel needs to be attached.
	 * @pre Object to be monitored needs to be loaded.
	 * @param [in] sessionHandle Session handle associated with RequestAttach
	 * @param [in] path Path to object
	 * @param [in] userParam User data which will be passed in the callback
	 * @return 1 on success
	 * @return 0 on DSM error
	 * @return -1 on D-Bus communication error
	 *
	 * @par Example
	 * @code
	 *
	 * void OnDsmCallback(TSDsmMessage& dsmMessage)
	 * {
	 * 	if (dsmMessage.messageType == DSM_MSG_OBJECT_CHANGED)
	 * 	{
	 * 		TSDsmObjectChanged& dsmObjectChanged = static_cast<TSDsmObjectChanged&>(dsmMessage);
	 * 		//do something
	 * 	}
	 * }
	 *
	 * IDsm * pDsm = NULL;
	 * TVServiceAPI::CreateDsm(&OnDsmCallback, &pDsm);
	 * //unsigned int sessionHandle = 0x20; //session handle associated with RequestAttach
	 *
	 * if (pDsm->AddMonitor(sessionHandle, "/dsm/DTV000E0800/CRS00000001/test/suite/30", this) > 0)
	 * {
	 * 	//succeeded
	 * }
	 *
	 * @endcode
	 */
	virtual int AddMonitor(_IN_ unsigned int sessionHandle, _IN_ const std::string& path, _IN_ void *userParam) = 0;

	/**
	 * @brief Stops monitoring of version changes for an object in object carousel.
	 * @remarks DsmCallback method will be called when the result is ready.
	 * TSDsmMonitorDeleted will be passed to the callback with messageType equal to
	 * DSM_MSG_MONITOR_DELETED.
	 * @remarks Object path needs to include the domain prefix.
	 * @pre Object carousel needs to be attached.
	 * @param [in] sessionHandle Session handle associated with RequestAttach
	 * @param [in] path Path to object
	 * @param [in] userParam User data which will be passed in the callback.
	 * @return 1 on success
	 * @return 0 on DSM error
	 * @return -1 on D-Bus communication error
	 *
	 * @par Example
	 * @code
	 *
	 * void OnDsmCallback(TSDsmMessage& dsmMessage)
	 * {
	 * 	if (dsmMessage.messageType == DSM_MSG_MONITOR_DELETED)
	 * 	{
	 * 		TSDsmMonitorDeleted& dsmMonitorDel = static_cast<TSDsmMonitorDeleted&>(dsmMessage);
	 * 		//do something
	 * 	}
	 * }
	 *
	 * IDsm * pDsm = NULL;
	 * TVServiceAPI::CreateDsm(&OnDsmCallback, &pDsm);
	 * //unsigned int sessionHandle = 0x20; //session handle associated with RequestAttach
	 *
	 * if (pDsm->DeleteMonitor(sessionHandle, "/dsm/DTV000E0800/CRS00000001/test/suite/30", this) > 0)
	 * {
	 * 	//succeeded
	 * }
	 *
	 * @endcode
	 */
	virtual int DeleteMonitor(_IN_ unsigned int sessionHandle, _IN_ const std::string& path, _IN_ void *userParam) = 0;

	/**
	 * @brief Requests asynchronous name resolution of an object based on parent
	 * directory path and object location (including object key from object's
	 * BIOP message).
	 * @remarks DsmCallback method will be called when the result is ready.
	 * TSDsmObjectName will be passed to the callback with messageType equal to DSM_MSG_OBJECT_NAME.
	 * @remarks TSDsmObjectLocation.object key needs to be a string containing
	 * hexadecimal representation of object key bytes (see example below).
	 * @pre Object carousel needs to be attached.
	 * @pre Object corresponding to parent directory needs to be loaded.
	 * @param [in] sessionHandle Session handle associated with RequestAttach
	 * @param [in] parentDirPath Path to parent directory
	 * @param [in] objectLocation Specifies location in object carousel
	 * @param [in] userParam User data which will be passed in the callback.
	 * @return 1 on success
	 * @return 0 on DSM error
	 * @return -1 on D-Bus communication error
	 *
	 * @par Example
	 * @code
	 *
	 * void OnDsmCallback(TSDsmMessage& dsmMessage)
	 * {
	 * 	if (dsmMessage.messageType == DSM_MSG_OBJECT_NAME)
	 * 	{
	 * 		TSDsmObjectName& dsmObjectName = static_cast<TSDsmObjectName&>(dsmMessage);
	 * 		//do something
	 * 	}
	 * }
	 *
	 * IDsm * pDsm = NULL;
	 * TVServiceAPI::CreateDsm(&OnDsmCallback, &pDsm);
	 * //unsigned int sessionHandle = 0x20; //session handle associated with RequestAttach
	 *
	 * TSDsmObjectLocation objectLocation.carouselID;
	 * objectLocation.carouselID = 0x1;
	 * objectLocation.moduleID = 0x8000;
	 * objectLocation.objectKey = "2A303178"; // BIOP's objectKey is "*01x" as ASCII
	 *
	 * if (pDsm->RequestObjectName(sessionHandle, "/dsm/DTV000E0800/CRS00000001/parent/dir", objectLocation.carouselID, this) > 0)
	 * {
	 * 	//succeeded
	 * }
	 *
	 * @endcode
	 */
	virtual int RequestObjectName(
			_IN_ unsigned int sessionHandle,
			_IN_ const std::string& parentDirPath,
			_IN_ const TSDsmObjectLocation& objectLocation,
			_IN_ void *userParam) = 0;

	/**
	 * @brief Acquires service context list bytes contained within the SGW message.
	 * @pre Object carousel needs to be attached.
	 * @pre SGW object needs to be loaded (use domain prefix as path).
	 * @param [in] sessionHandle Session handle associated with RequestAttach
	 * @param [out] SclCount Number of service contexts on the list
	 * @param [out] serviceContextData Raw service context list data bytes (all list
	 * entries).
	 * @return 1 on success
	 * @return 0 on DSM error
	 * @return -1 on D-Bus communication error
	 *
	 * @par Example
	 * @code
	 *
	 * void OnDsmCallback(TSDsmMessage& dsmMessage)
	 * {
	 * }
	 *
	 * IDsm * pDsm = NULL;
	 * TVServiceAPI::CreateDsm(&OnDsmCallback, &pDsm);
	 * //unsigned int sessionHandle = 0x20; //session handle associated with RequestAttach
	 * unsigned int sclCount;
	 * std::vector<unsigned char> serviceContextData;
	 *
	 * if (pDsm->GetServiceContextList(sessionHandle, sclCount, serviceContextData) > 0)
	 * {
	 * 	//succeeded
	 * }
	 *
	 * @endcode
	 */
	virtual int GetServiceContextList(
			_IN_ unsigned int sessionHandle,
			_OUT_ unsigned int& SclCount,
			_OUT_ std::vector<unsigned char>& serviceContextData) = 0;

	/**
	 * @brief Gets user user info bytes contained within the DSI message.
	 * @pre Object carousel needs to be attached.
	 * @pre SGW object needs to be loaded (use domain prefix as path).
	 * @param [in] sessionHandle Session handle associated with RequestAttach
	 * @param [out] userInfoBytes Raw user info data
	 * @return 1 on success
	 * @return 0 on DSM error
	 * @return -1 on D-Bus communication error
	 *
	 * @par Example
	 * @code
	 *
	 * void OnDsmCallback(TSDsmMessage& dsmMessage)
	 * {
	 * }
	 *
	 * IDsm * pDsm = NULL;
	 * TVServiceAPI::CreateDsm(&OnDsmCallback, &pDsm);
	 * //unsigned int sessionHandle = 0x20; //session handle associated with RequestAttach
	 * unsigned int sclCount;
	 * std::vector<unsigned char> userInfoBytes;
	 *
	 * if (pDsm->GetServiceContextList(sessionHandle, userInfoBytes) > 0)
	 * {
	 * 	//succeeded
	 * }
	 *
	 * @endcode
	 */
	virtual int GetUserInfoBytes(_IN_ unsigned int sessionHandle, _OUT_ std::vector<unsigned char>& userInfoBytes) = 0;

	/**
	 * @brief Opens stream associated with stream or stream event object.
	 * @remarks DsmCallback method will be called when the result is ready.
	 * TSDsmStream will be passed to the callback with messageType equal to DSM_MSG_STREAM_OPEN.
	 * @remarks Object path needs to include the domain prefix.
	 * @pre Object carousel needs to be attached.
	 * @pre Stream or stream event object corresponding to path needs to be loaed.
	 * @param [in] sessionHandle Session handle associated with RequestAttach
	 * @param [out] streamHandle Stream handle associated with opened stream.
	 * It is unique value in entire system. It is not possible that session
	 * handle and stream handle have the same value.
	 * @param [in] path Path to stream or stream event object
	 * @param [in] userParam User data which will be passed in the callback.
	 * @return 1 on success
	 * @return 0 on DSM error
	 * @return -1 on D-Bus communication error
	 *
	 * @par Example
	 * @code
	 *
	 * void OnDsmCallback(TSDsmMessage& dsmMessage)
	 * {
	 * 	if (dsmMessage.messageType == DSM_MSG_STREAM_OPEN)
	 * 	{
	 * 		TSDsmStream& dsmStream = static_cast<TSDsmStream&>(dsmMessage);
	 * 		//do something
	 * 	}
	 * }
	 *
	 * IDsm * pDsm = NULL;
	 * TVServiceAPI::CreateDsm(&OnDsmCallback, &pDsm);
	 * //unsigned int sessionHandle = 0x20; //session handle associated with RequestAttach
	 * unsigned int streamHandle;
	 *
	 * if (pDsm->RequestStreamOpen(sessionHandle, streamHandle, "/dsm/DTV000E0800/CRS00000001/test/stream", this) > 0)
	 * {
	 * 	//succeeded
	 * }
	 *
	 * @endcode
	 */
	virtual int RequestStreamOpen(
			_IN_ unsigned int sessionHandle,
			_OUT_ unsigned int& streamHandle,
			_IN_ const std::string& path,
			_IN_ void *userParam) = 0;

	/**
	 * @brief Closes previously opened stream.
	 * @remarks Stream handle becomes invalid if this method is called
	 * @pre Object carousel needs to be attached.
	 * @pre Stream needs to be opened.
	 * @param [in] streamHandle stream handle associated with RequestStreamOpen
	 * @return 1 on success
	 * @return 0 on DSM error
	 * @return -1 on D-Bus communication error
	 *
	 * @par Example
	 * @code
	 *
	 * void OnDsmCallback(TSDsmMessage& dsmMessage)
	 * {
	 * }
	 *
	 * IDsm * pDsm = NULL;
	 * TVServiceAPI::CreateDsm(&OnDsmCallback, &pDsm);
	 * //unsigned int streamHandle = 0x22; //stream handle associated with RequestStreamOpen
	 *
	 * if (pDsm->CloseStream(streamHandle) > 0)
	 * {
	 * 	//succeeded
	 * }
	 *
	 * @endcode
	 */
	virtual int CloseStream(_IN_ unsigned int streamHandle) = 0;

	/**
	 * @brief Asynchronously requests information related to stream object.
	 * @remarks DsmCallback method will be called when the result is ready.
	 * TSDsmStreamInfo will be passed to the callback with messageType equal to DSM_MSG_STREAM_INFO.
	 * @pre Object carousel needs to be attached.
	 * @pre Stream needs to be opened.
	 * @param [in] streamHandle stream handle associated with RequestStreamOpen
	 * @param [in] userParam User data which will be passed in the callback.
	 * @return 1 on success
	 * @return 0 on DSM error
	 * @return -1 on D-Bus communication error
	 *
	 * @par Example
	 * @code
	 *
	 * void OnDsmCallback(TSDsmMessage& dsmMessage)
	 * {
	 * 	if (dsmMessage.messageType == DSM_MSG_STREAM_INFO)
	 * 	{
	 * 		TSDsmStreamInfo& dsmStreamInfo = static_cast<TSDsmStreamInfo&>(dsmMessage);
	 * 		//do something
	 * 	}
	 * }
	 *
	 * IDsm * pDsm = NULL;
	 * TVServiceAPI::CreateDsm(&OnDsmCallback, &pDsm);
	 * //unsigned int streamHandle = 0x22; //stream handle associated with RequestStreamOpen
	 *
	 * if (pDsm->RequestStreamInfo(streamHandle, this) > 0)
	 * {
	 * 	//succeeded
	 * }
	 *
	 * @endcode
	 */
	virtual int RequestStreamInfo(_IN_ unsigned int streamHandle, _IN_ void *userParam) = 0;

	/**
	 * @brief Requests information on stream taps defined within stream or stream event
	 * object.
	 * @remarks DsmCallback method will be called when the result is ready.
	 * TSDsmStreamTapList will be passed to the callback with messageType equal to DSM_MSG_STREAM_TAP.
	 * @pre Object carousel needs to be attached.
	 * @pre Stream needs to be opened.
	 * @param [in] streamHandle stream handle associated with RequestStreamOpen
	 * @param [in] userParam User data which will be passed in the callback.
	 * @return 1 on success
	 * @return 0 on DSM error
	 * @return -1 on D-Bus communication error
	 *
	 * @par Example
	 * @code
	 *
	 * void OnDsmCallback(TSDsmMessage& dsmMessage)
	 * {
	 * 	if (dsmMessage.messageType == DSM_MSG_STREAM_TAP)
	 * 	{
	 * 		TSDsmStreamTapList& dsmStreamTapList = static_cast<TSDsmStreamTapList&>(dsmMessage);
	 * 		//do something
	 * 	}
	 * }
	 *
	 * IDsm * pDsm = NULL;
	 * TVServiceAPI::CreateDsm(&OnDsmCallback, &pDsm);
	 * //unsigned int streamHandle = 0x22; //stream handle associated with RequestStreamOpen
	 *
	 * if (pDsm->RequestStreamTap(streamHandle, this) > 0)
	 * {
	 * 	//succeeded
	 * }
	 *
	 * @endcode
	 */
	virtual int RequestStreamTap(_IN_ unsigned int streamHandle, _IN_ void *userParam) = 0;

	/**
	 * @brief Requests list of events defined within to stream event object.
	 * @remarks DsmCallback method will be called when the result is ready.
	 * TSDsmEventList will be passed to the callback with messageType equal to DSM_MSG_EVENT_LIST.
	 * @pre Object carousel needs to be attached.
	 * @pre Stream related to stream event object needs to be opened.
	 * @param [in] streamHandle stream handle associated with RequestStreamOpen
	 * @param [in] userParam User data which will be passed in the callback.
	 * @return 1 on success
	 * @return 0 on DSM error
	 * @return -1 on D-Bus communication error.
	 *
	 * @par Example
	 * @code
	 *
	 * void OnDsmCallback(TSDsmMessage& dsmMessage)
	 * {
	 * 	if (dsmMessage.messageType == DSM_MSG_EVENT_LIST)
	 * 	{
	 * 		TSDsmEventList& dsmStreamEventList = static_cast<TSDsmEventList&>(dsmMessage);
	 * 		//do something
	 * 	}
	 * }
	 *
	 * IDsm * pDsm = NULL;
	 * TVServiceAPI::CreateDsm(&OnDsmCallback, &pDsm);
	 * //unsigned int streamHandle = 0x22; //stream handle associated with RequestStreamOpen
	 *
	 * if (pDsm->RequestEventList(streamHandle, this) > 0)
	 * {
	 * 	//succeeded
	 * }
	 *
	 * @endcode
	 */
	virtual int RequestEventList(_IN_ unsigned int streamHandle, _IN_ void* userParam) = 0;

	/**
	 * @brief Subscribes for a stream event occurrences based on event identifier.
	 * @remarks DsmCallback method will be called every time when the event occurs.
	 * TSDsmEvent will be passed to the callback with messageType equal to DSM_MSG_EVENT_OCCURED.
	 * If subscription failed DsmCallback is called once with messageType DSM_MSG_EVENT_SUBS_FAIL.
	 * @pre Object carousel needs to be attached.
	 * @pre Stream needs to be opened.
	 * @param [in] streamHandle stream handle associated with RequestStreamOpen
	 * @param [in] eventID event ID associated with the result of RequestEventList
	 * @param [in] userParam User data which will be passed in the callback.
	 * @return 1 on success
	 * @return 0 on DSM error
	 * @return -1 on D-Bus communication error
	 *
	 * @par Example
	 * @code
	 *
	 * void OnDsmCallback(TSDsmMessage& dsmMessage)
	 * {
	 * 	if (dsmMessage.messageType == DSM_MSG_EVENT_OCCURED)
	 * 	{
	 * 		TSDsmEvent& dsmEvent = static_cast<TSDsmEvent&>(dsmMessage);
	 * 		//do something
	 * 	}
	 * 	else if (dsmMessage.messageType == DSM_MSG_EVENT_SUBS_FAIL)
	 * 	{
	 * 		TSDsmEvent& dsmEvent = static_cast<TSDsmEvent&>(dsmMessage);
	 * 		//do something - subscription failed
	 * 	}
	 * }
	 *
	 * IDsm * pDsm = NULL;
	 * TVServiceAPI::CreateDsm(&OnDsmCallback, &pDsm);
	 * //unsigned int streamHandle = 0x22; //stream handle associated with RequestStreamOpen
	 *
	 * if (pDsm->SubscribeEvent(streamHandle, 0x01 ,this) > 0)
	 * {
	 * 	//succeeded
	 * }
	 *
	 * @endcode
	 */
	virtual int SubscribeEvent(_IN_ unsigned int streamHandle, _IN_ unsigned short eventID, _IN_ void* userParam) = 0;

	/**
	 * @brief Subscribes for a stream event occurrences based on event name.
	 * @remarks DsmCallback method will be called every time when the event occurs.
	 * TSDsmEvent will be passed to the callback with messageType equal to DSM_MSG_EVENT_OCCURED.
	 * If subscription failed DsmCallback is called once with messageType DSM_MSG_EVENT_SUBS_FAIL.
	 * @pre Object carousel needs to be attached.
	 * @pre Stream needs to be opened.
	 * @param [in] streamHandle stream handle associated with RequestStreamOpen
	 * @param [in] eventName event name associated with the result of RequestEventList
	 * @param [in] userParam User data which will be passed in the callback.
	 * @return 1 on success
	 * @return 0 on DSM error
	 * @return -1 on D-Bus communication error
	 *
	 * @par Example
	 * @code
	 *
	 * void OnDsmCallback(TSDsmMessage& dsmMessage)
	 * {
	 * 	if (dsmMessage.messageType == DSM_MSG_EVENT_OCCURED)
	 * 	{
	 * 		TSDsmEvent& dsmEvent = static_cast<TSDsmEvent&>(dsmMessage);
	 * 		//do something
	 * 	}
	 * 	else if (dsmMessage.messageType == DSM_MSG_EVENT_SUBS_FAIL)
	 * 	{
	 * 		TSDsmEvent& dsmEvent = static_cast<TSDsmEvent&>(dsmMessage);
	 * 		//do something - subscription failed
	 * 	}
	 * }
	 *
	 * IDsm * pDsm = NULL;
	 * TVServiceAPI::CreateDsm(&OnDsmCallback, &pDsm);
	 * //unsigned int streamHandle = 0x22; //stream handle associated with RequestStreamOpen
	 *
	 * if (pDsm->SubscribeEvent(streamHandle, "someevent" ,this) > 0)
	 * {
	 * 	//succeeded
	 * }
	 *
	 * @endcode
	 */
	virtual int SubscribeEvent(_IN_ unsigned int streamHandle, _IN_ const std::string& eventName, _IN_ void* userParam) = 0;

	/**
	 * @brief Unsubscribes from a stream event notification based on event identifier.
	 * @remarks This method unsubscribes for the stream event that was made by SubscribeEvent method
	 * @pre Object carousel needs to be attached.
	 * @pre Stream needs to be opened.
	 * @param [in] streamHandle stream handle associated with RequestStreamOpen
	 * @param [in] eventID event ID associated with the result of RequestEventList
	 * @return 1 on success
	 * @return 0 on DSM error
	 * @return -1 on D-Bus communication error
	 *
	 * @par Example
	 * @code
	 *
	 * void OnDsmCallback(TSDsmMessage& dsmMessage)
	 * {
	 * }
	 *
	 * IDsm * pDsm = NULL;
	 * TVServiceAPI::CreateDsm(&OnDsmCallback, &pDsm);
	 * //unsigned int streamHandle = 0x22; //stream handle associated with RequestStreamOpen
	 *
	 * if (pDsm->UnsubscribeEvent(streamHandle, 0x01) > 0)
	 * {
	 * 	//succeeded
	 * }
	 *
	 * @endcode
	 */
	virtual int UnsubscribeEvent(_IN_ unsigned int streamHandle, _IN_ unsigned short eventID) = 0;

	/**
	 * @brief Unsubscribes from a stream event notification based on event name.
	 * @remarks This method unsubscribes for the stream event that was made by SubscribeEvent method
	 * @pre Object carousel needs to be attached.
	 * @pre Stream needs to be opened.
	 * @param [in] streamHandle stream handle associated with RequestStreamOpen
	 * @param [in] eventName event name associated with the result of RequestEventList
	 * @return 1 on success
	 * @return 0 on DSM error
	 * @return -1 on D-Bus communication error
	 *
	 * @par Example
	 * @code
	 *
	 * void OnDsmCallback(TSDsmMessage& dsmMessage)
	 * {
	 * }
	 *
	 * IDsm * pDsm = NULL;
	 * TVServiceAPI::CreateDsm(&OnDsmCallback, &pDsm);
	 * //unsigned int streamHandle = 0x22; //stream handle associated with RequestStreamOpen
	 *
	 * if (pDsm->UnsubscribeEvent(streamHandle, "someevent") > 0)
	 * {
	 * 	//succeeded
	 * }
	 *
	 * @endcode
	 */
	virtual int UnsubscribeEvent(_IN_ unsigned int streamHandle, _IN_ const std::string& eventName) = 0;

	/**
	 * @brief Inform DSM about which application profile is served by TV
	 * Used for FSA (File System Acceleration) feature purpose by HbbTV
	 * @remarks The client should call this method for the first time at the startup
	 * and each time the application profile has changed.
	 * Dsm will be able to use FSA caching only for those groups which belong to this profile
	 * @remarks The client does not have to be attached to any carousel to use this method
	 * @param [in] applicationProfile application profile
	 * @param [in] versionMajor application version major
	 * @param [in] versionMinor application version minor
	 * @param [in] versionMicro application version micro
	 * @return 1 on success
	 * @return 0 on DSM error
	 * @return -1 on D-Bus communication error
	 *
	 * @par Example
	 * @code
	 *
	 * void OnDsmCallback(TSDsmMessage& dsmMessage)
	 * {
	 * }
	 *
	 * IDsm * pDsm = NULL;
	 * TVServiceAPI::CreateDsm(&OnDsmCallback, &pDsm);
	 *
	 * unsigned short applicationProfile = 1;
	 * unsigned char versionMajor = 1;
	 * unsigned char versionMinor = 1;
	 * unsigned char versionMicro = 1;
	 *
	 * if (pDsm->SetServedApplicationProfile(applicationProfile, versionMajor, versionMinor, versionMicro) > 0)
	 * {
	 * 	//succeeded
	 * }
	 *
	 * @endcode
	 */
	virtual int SetServedApplicationProfile(
			_IN_ unsigned short applicationProfile,
			_IN_ unsigned char versionMajor,
			_IN_ unsigned char versionMinor,
			_IN_ unsigned char versionMicro) = 0;
};

#endif //_IDSM_H_
