/** 
 * @file IDataSubscriber.h
 * @brief Interface for getting closed caption, teletex, subtitles.
 *
 * Copyright 2013 by Samsung Electronics, Inc.,
 * 
 * This software is the confidential and proprietary information
 * of Samsung Electronics, Inc. ("Confidential Information"). You
 * shall not disclose such Confidential Information and shall use
 * it only in accordance with the terms of the license agreement
 * you entered into with Samsung.
 */


#ifndef _IDATASUBSCRIBER_H_
#define _IDATASUBSCRIBER_H_


#include "MarshallingMarks.h"
#include "DataSubscriberDataType.h"


typedef void (*CaptionCallback)(TSCaption& caption, void* pUserData);


class IDataSubscriber
{
protected:
	virtual ~IDataSubscriber() {};

public:

	/**
	 * @brief Subscribes for closed caption.
	 * @remarks Given application can subscribe only once per TVSHandle.
	 * @param [in] captionCallback Callback method which will be called when caption comes.
	 * @param [in] pUserData User data which will be passed together with caption data.
	 * @param [out] handle Handle associated with callback (needed for unsubscription).
	 * @return Returns 1 if subscription succeeded, otherwise returns 0.
	 * @return When calling method failed returns -1.
	 *
	 *	@paragraph <Example>
	 *	This example will subscribe for closed caption.
	 *	
	 *	void OnCaptionCallback(TSCaption& caption, void* pUserData)
	 *	{
	 *		//Do something with caption on callback.
	 *	}
	 *
	 *	@verbatim
	 *	EProfile profile = PROFILE_TYPE_MAIN;
	 *	int screenId = 0;
	 *	IDataSubscriber* pDataSubscriber;
	 *	TVServiceAPI::CreateDataSubscriber(PROFILE_TYPE_MAIN, screenId, &pDataSubscriber);
	 *
	 *	int handle;
	 *	if(pDataSubscriber->SubscribeForCaption(&OnCaptionCallback, this, handle) > 0)
	 *	{
	 *		//Do something.
	 *	}
	 *	@endverbatim
	 */
	virtual int SubscribeForCaption(_IN_ CaptionCallback captionCallback, _IN_ void* pUserData, _OUT_ int& handle) = 0;

	/**
	 * @brief Unsubscribes from any subscription defined by handle.
	 * @param [in] handle Handle associated with callback.
	 * @return Returns 1 if unsubscription succeeded, otherwise returns 0.
	 * @return When calling method failed returns -1.
	 *
	 *	@paragraph <Example>
	 *	This example will subscribe for closed caption.
	 *
	 *	@verbatim
	 *	EProfile profile = PROFILE_TYPE_MAIN;
	 *	int screenId = 0;
	 *	IDataSubscriber* pDataSubscriber;
	 *	TVServiceAPI::CreateDataSubscriber(PROFILE_TYPE_MAIN, screenId, &pDataSubscriber);
	 *
	 *	if(pDataSubscriber->Unsubscribe(handle) > 0)
	 *	{
	 *		//Do something.
	 *	}
	 *	@endverbatim
	 */
	virtual int Unsubscribe(_IN_ int handle) = 0;
};


#endif //_IDATASUBSCRIBER_H_
