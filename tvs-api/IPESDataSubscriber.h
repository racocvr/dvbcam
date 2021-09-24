/** 
 * @file IPESDataSubscriber.h
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

#ifndef _IPESDATASUBSCRIBER_H_
#define _IPESDATASUBSCRIBER_H_


#include "MarshallingMarks.h"
#include "PESDataSubscriberDataType.h"
#include "ServiceData.h"

/**
 * @brief Definition of PES data callback method, which shall be implemented by application.
 * @remark It is forbidden for callback function to call methods related to subscribing or unsubscribing.
 * @param [in] TSPESData PES data structure (please refer to DataSubscriberDataType.h fro more information).
 * @param [in] void* Application data passed during subscription.
 */
typedef void (*PESDataCallback)(TSPESData&, void*);

/**
 * @brief Definition of external PES data callback method, which shall be implemented by application.
 * @remark Passed serviceId and componentTag identify received PES data in the current MUX.
 * @remark It is forbidden for callback function to call methods related to subscribing or unsubscribing.
 * @param [in] TSPESData PES data structure (please refer to DataSubscriberDataType.h fro more information).
 * @param [in] TCServiceId ServiceId.
 * @param [in] int PES component Tag.
 * @param [in] void* Application data passed during subscription.
 */
typedef void (*ExPESDataCallback)(TSPESData&, const TCServiceId&, int, void*);


class IPESDataSubscriber
{
protected:
	virtual ~IPESDataSubscriber() {};

public:

	/**
	 * @brief Subscribes for PES data.
	 * @remarks Use this method only to subscribe for currently selected PES for current service.
	 * @remarks Application can subscribe only once per tvsHandle (second subscription with fail).
	 * @param [in] pesDataCallback Callback method which will be called when PES data comes.
	 * @param [in] pUserData User data which will be passed together with PES data.
	 * @param [out] handle Handle associated with callback (needed for unsubscription).
	 * @return Returns 1 if subscription succeeded, otherwise returns 0.
	 * @return When calling method failed returns -1.
	 *
	 *	@paragraph <Example>
	 *	This example will subscribe for PES data.
	 *	
	 *	void OnPESDataCallback(TSPESData& pesData, void* pUserData)
	 *	{
	 *		//Do something with PES data on callback.
	 *	}
	 *
	 *	@verbatim
	 *	EProfile profile = PROFILE_TYPE_MAIN;
	 *	int screenId = 0;
	 *	IPESDataSubscriber* pPESDataSubscriber;
	 *	TVServiceAPI::CreateDataSubscriber(PROFILE_TYPE_MAIN, screenId, &pPESDataSubscriber);
	 *
	 *	int handle;
	 *	if(pPESDataSubscriber->Subscribe(&OnPESDataCallback, this, handle) > 0)
	 *	{
	 *		//Do something.
	 *	}
	 *	@endverbatim
	 */
	virtual int Subscribe(_IN_ PESDataCallback pesDataCallback, _IN_ void* pUserData, _OUT_ int& handle) = 0;

	/**
	 * @brief Subscribes for PES data.
	 * @remarks Use this method to subscribe for any PES data in current MUX.
	 * @remarks Application can subscribe only once per specified component and tvsHandle (second subscription for the same component with fail).
	 * @param [in] exPesDataCallback Callback method which will be called when PES data comes.
	 * @param [in] serviceId Service Id.
	 * @param [in] componentTag Component tag, which specify PES data for given service.
	 * @param [in] pUserData User data which will be passed together with PES data.
	 * @param [out] handle Unique handle associated with callback (needed for unsubscription).
	 * @return Returns 1 if subscription succeeded, otherwise returns 0.
	 * @return When calling method failed returns -1.
	 *
	 *	@paragraph <Example>
	 *	This example will subscribe for PES data.
	 *	
	 *	void OnExPESDataCallback(TSPESData& pesData, void* pUserData)
	 *	{
	 *		//Do something with caption on callback.
	 *	}
	 *
	 *	@verbatim
	 *	IPESDataSubscriber* pPESDataSubscriber;
	 *	TVServiceAPI::CreateDataSubscriber(DEFAULT_PROFILE_TYPE, DEFAULT_SCREEN_ID, &pPESDataSubscriber);
	 *
	 *	TCServiceId serviceId = 1234567890;
	 *	int componentTag = 0x3;
	 *	int handle = INVALID;
	 *	if( pPESDataSubscriber->Subscribe( &OnExPESDataCallback, serviceId, componentTag, this, handle ) > 0 )
	 *	{
	 *		//Do something.
	 *	}
	 *	@endverbatim
	 */
	virtual int Subscribe(_IN_ ExPESDataCallback exPesDataCallback, const _IN_ TCServiceId& serviceId, _IN_ int componentTag, _IN_ void* pUserData, _OUT_ int& handle) = 0; 

	/**
	 * @brief Unsubscribes from any subscription specified by handle.
	 * @param [in] handle Handle associated with subscription.
	 * @return Returns 1 if unsubscription succeeded, otherwise returns 0.
	 * @return When calling method failed returns -1.
	 *
	 *	@paragraph <Example>
	 *	This example will subscribe for PES data.
	 *
	 *	@verbatim
	 *	EProfile profile = PROFILE_TYPE_MAIN;
	 *	int screenId = 0;
	 *	IPESDataSubscriber* pPESDataSubscriber;
	 *	TVServiceAPI::CreateDataSubscriber(PROFILE_TYPE_MAIN, screenId, &pPESDataSubscriber);
	 *
	 *	if(pPESDataSubscriber->Unsubscribe(handle) > 0)
	 *	{
	 *		//Do something.
	 *	}
	 *	@endverbatim
	 */
	virtual int Unsubscribe(_IN_ int handle) = 0;
};


#endif //_IPESDATASUBSCRIBER_H_