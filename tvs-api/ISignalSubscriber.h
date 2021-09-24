/** 
 * @file ISignalSubscriber.h
 * @brief TVS API interface for signal subscription.
 *
 * Copyright 2013 by Samsung Electronics, Inc.,
 * 
 * This software is the confidential and proprietary information
 * of Samsung Electronics, Inc. ("Confidential Information"). You
 * shall not disclose such Confidential Information and shall use
 * it only in accordance with the terms of the license agreement
 * you entered into with Samsung.
 */

#ifndef _ISIGNALSUBSCRIBER_H_
#define _ISIGNALSUBSCRIBER_H_


#include <stddef.h>
#include <string>

#include "SignalSubscriberDataType.h"
#include "TVServiceDataType.h"

/** This typedef shall be removed on 12.09.2014 */
typedef int (*SignalCallback)(ESignalType, TSSignalData, void*);

/**
 * @brief Definition of signal callback method. It is implemented by application.
 * @remark It is forbidden for callback function to call methods related to subscribing or unsubscribing.
 * @param [in] ESignalType Signal type.
 * @param [in] EProfile Profile Id.
 * @param [in] unsigned short Screen Id.
 * @param [in] TSSignalData Signal data.
 * @param [in] void* Application data passed during subscription.
 */
typedef int (*TTSignalCallback)(ESignalType, EProfile, unsigned short, TSSignalData, void*);


class ISignalSubscriber
{
protected:
	virtual ~ISignalSubscriber(){};

public:

	/**
	 * @brief Subscribes for receiving specific signal.
	 * @remark This method can be used to subscribe for signals from specific profileId and screenId.
	 * @remark It is forbidden for callback function to call methods related to subscribing or unsubscribing.
	 * @param [in] type Signal type.
	 * @param [in] pUserData User data that will be returned when callback method will be called.
	 * @param [in] profileId Profile Id.
	 * @param [in] screenId Screen Id.
	 * @return Returns 1 if subscription succeeded, otherwise returns 0.
	 *
	 *	@paragraph <Example>
	 *	This sample code will subscribe for receiving SIGNAL_SEARCH_CHANNEL signal.
	 *	It includes GMainLoop creation and start.
	 *	
	 *	@verbatim
	 *	static void signalReceived(ESignalType signal, TSSignalData data, void* pUserData)
	 *	{
	 *	 	// signal receive handling
	 *	}
	 *	GMainLoop* loop = g_main_loop_new(NULL, FALSE);
	 *	
	 *	ISignalSubscriber* pSubscriber = NULL;
	 *	TVServiceAPI::CreateSignalSubscriber(&signalReceived, &pSubscriber);
	 *	
	 *	if(pSubscriber->Subscribe(SIGNAL_SEARCH_CHANNEL, this) > 0)
	 *	{
	 *		// Subscription succeeded
	 *	}
	 *	
	 *	g_main_loop_run(loop);
	 *	@endverbatim
	 */	
	virtual int Subscribe( ESignalType type,
						   void* pUserData = NULL, 
						   EProfile profileId = DEFAULT_PROFILE_TYPE, 
						   unsigned short screenId = DEFAULT_SCREEN_ID ) = 0;

	/**
	 * @brief Unsubscribes from receiving specific signal.
	 * @remark It is forbidden for callback function to call methods related to subscribing or unsubscribing.
	 * @param [in] type Signal type.
	 * @param [in] profileId Profile Id.
	 * @param [in] screenId Screen Id.
	 * @return Returns 1 if unsubscription succeeded, otherwise returns 0.
	 *
	 *	@paragraph <Example>
	 *	This code will unsubscribe from receiving SIGNAL_SEARCH_CHANNEL signal.
	 *	It includes GMainLoop creation and start.
	 *	
	 *	@verbatim
 	 *	static void signalReceived(ESignalType signal, TSSignalData data)
	 *	{
	 *	 	// signal receive handling
	 *	}
	 *	GMainLoop* loop = g_main_loop_new(NULL, FALSE);
	 *	
	 *	ISignalSubscriber* pSubscriber = NULL;
	 *	TVServiceAPI::CreateSignalSubscriber(&signalReceived, &pSubscriber);
	 *	
	 *	if(pSubscriber->Unsubscribe(SIGNAL_SEARCH_CHANNEL) > 0)
	 *	{
	 *		// Unsubscription succeeded
	 *	}
	 *	
	 *	g_main_loop_run(loop);
	 *	@endverbatim
	 */	
	virtual int Unsubscribe( ESignalType type, 
							 EProfile profileId = DEFAULT_PROFILE_TYPE,
							 unsigned short screenId = DEFAULT_SCREEN_ID ) = 0;

};

#endif // _ISIGNALSUBSCRIBER_H_
