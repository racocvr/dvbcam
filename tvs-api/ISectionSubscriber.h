/** 
 * @file ISectionSubscriber.h
 * @brief Application interface for managing section subscription
 *
 * Copyright 2013 by Samsung Electronics, Inc.,
 * 
 * This software is the confidential and proprietary information
 * of Samsung Electronics, Inc. ("Confidential Information"). You
 * shall not disclose such Confidential Information and shall use
 * it only in accordance with the terms of the license agreement
 * you entered into with Samsung.
 */


#ifndef _ISECTIONSUBSCRIBER_H_
#define _ISECTIONSUBSCRIBER_H_

#include "MarshallingMarks.h"
#include "SectionSubscriberDataType.h"

typedef void (*SectionCallback)( bool isDone, unsigned short length, unsigned char* pData, int userParam );

class ISectionSubscriber
{
protected:
	virtual ~ISectionSubscriber(){};

public:
	/**
	 * @brief Subscribes for receiving sections.
	 * @remark It is forbidden for callback function to call methods related to subscribing or unsubscribing
	 * @remark Returned handle is unique even if application subscribe for the same section twice, so unsubscribe needs to be called separatly for every subscription.
	 * @remark To successfully subscribe both "tableId" and "pid" must be specified (optionally "tableId" and "programNumber").
	 * @remark You can subscribe for PMT by specifying "tableId" and "programNumber" values ("pid" value must be set to INVALID).
	 * @remark In case when "checkVersion" == true (default value) application will receive given section once per each version.
	 * @param [in] userParam User data which will be received with the specified section.
	 * @param [in] criteria Subscribing criteria.
	 * @param [out] handle ID of a handle of subscription.
	 * @return Returns 1 if subscription for section succeeded, otherwise returns 0.
	 * @return When calling method failed returns -1.
	 *
	 *	 @paragraph <Example>
	 *	 This example shows how to subscribe for PAT section.
	 *	 As an output it will generate a unique handle ID which should be later used for unsubscribe.
	 *	 
	 *	 @verbatim
	 *	 // callback for subscribed section
	 *	 static void onSection( bool isDone, unsigned short length, unsigned char* pData, int userParam )
	 *	 {
	 *	 	// some action taken on callback invocation
	 *	 }
	 *
	 *	 GMainLoop* loop = g_main_loop_new (NULL, FALSE); // gmainloop init
	 *
	 *	 // creating SectionSubscriber
	 *	 ISectionSubscriber* pSubscriber = NULL;
	 * 	 TVServiceAPI::CreateSectionSubscriber( &onSection, DEFAULT_PROFILE_TYPE, DEFAULT_SCREEN_ID, &pSubscriber );
	 *
	 *	 // example of preparation criteria helper
	 *	 int userParam = 432;
	 *	 int handle = INVALID;
	 *
	 *	 TCSectionCriteriaHelper sectionHelper;
	 *	 sectionHelper.pid = TCSectionParser::PAT_PID;
	 *	 sectionHelper.tableId = TCPATParser::TABLE_ID;	 
	 *	 sectionHelper.device = DEVICE_INBAND;
	 *	 sectionHelper.subscribeType = SECTION_SUBSCRIBE_CACHE_OR_STREAM;
	 *	 sectionHelper.version = true;
	 *	 
	 *	 //subscribing for sections
	 *	 if(pSubscriber->Subscribe( userParam, sectionHelper, handle ) > 0)
	 *	 {
	 *		//Do something when operation successful
	 *	 }
	 *
	 *	 //gmainloop take care of invoking onSection callback if it'll be triggered by tvs-si module
	 *	 g_main_loop_run (loop);
	 *	 @endverbatim
	 */
	virtual int Subscribe( _IN_ int userParam, _IN_ const TCSectionCriteriaHelper& criteria, _OUT_ int& handle ) = 0;
	
	/**
	 * @brief Subscribes for receiving sections using filter.
	 * @remark It is forbidden for callback function to call methods related to subscribing or unsubscribing
	 * @remark Returned handle is unique even if application subscribe for the same filtered section twice,
	 * @remark so unsubscribe needs to be called separatly for every subscription.
	 * @param [in] userParam User data which will be received with the specified section.
	 * @param [in] filterCriteria Subscribing criteria (Filter, Mask, Invert, filterLength, CheckCRC).
	 * @param [out] handle ID of a handle of subscription.
	 * @return Returns 1 if subscription for section succeeded, otherwise returns 0.
	 * @return When calling method failed returns -1.	 
	 *
	 *	 @paragraph <Example>
	 *	 This example shows how to subscribe for a section.
	 *	 As an output it will generate a unique handle ID which should be later used for unsubscribe.
	 *	 
	 *	 @verbatim
	 *	 // callback for subscribed section
	 *	 static void onSection( bool isDone, unsigned short length, unsigned char* pData, int userParam )
	 *	 {
	 *	 	// some action taken on callback invocation
	 *	 }
	 *
	 *	 GMainLoop* loop = g_main_loop_new (NULL, FALSE); // gmainloop init
	 *
	 *	 // creating SectionSubscriber
	 *	 ISectionSubscriber* pSubscriber = NULL;
	 * 	 TVServiceAPI::CreateSectionSubscriber( &onSection, DEFAULT_PROFILE_TYPE, DEFAULT_SCREEN_ID, &pSubscriber );
	 *
	 *	 // example of preparation criteria helper
	 *	 int userParam = 0;
 	 *	 int handle = -1;
	 *
	 *	 TCSectionFilterCriteriaHelper filterCriteria;
	 *	 filterCriteria.pid = 0x1ffb;
	 *	 filterCriteria.pFilter = filter; // prepared filter; filter is a vector 
	 *	 filterCriteria.pMask = mask; // mask for filter; mask is a vector
	 *	 filterCriteria.pInvert = invert; // filter invertion; invertion is a vector
	 *	 filterCriteria.checkCRC = true;
	 *	 
	 *	 //subscribing for sections
	 *	 if(pSubscriber->SubscribeByFilter( userParam, filterCriteria, handle ) > 0)
	 *	 {
	 *		//Do something when operation successful
	 *	 }
	 *
	 *	 //gmainloop take care of invoking onSection callback if it'll be triggered by tvs-si module
	 *	 g_main_loop_run (loop);
	 *	 @endverbatim
	 */
	virtual int SubscribeByFilter( _IN_ int userParam, const _IN_ TCSectionFilterCriteriaHelper& filterCriteria, _OUT_ int& handle ) = 0;

	/**
	 * @brief Unsubscribes from receiving sections.
	 * @remark It is forbidden for callback function to call methods related to subscribing or unsubscribing
	 * @param [in] handle ID of a handle of subscription.
	 * @return Returns 1 if section was unsubscribed successfully, otherwise returns 0.
	 * @return When calling method failed returns -1.	 
	 *
	 *	 @paragraph <Example>
	 *	 This example will subscribe how to unsubscribe from sections.
	 *	 
	 *	 ISectionSubscriber* pSubscriber = NULL;
	 *	 int handle = 458;
	 *	 TVServiceAPI::CreateSectionSubscriber( &onSection, DEFAULT_PROFILE_TYPE, DEFAULT_SCREEN_ID, &pSubscriber );
	 *
     *	 if(pSubscriber->Unsubscribe( handle ) > 0) // where handle is ID set by Subscribe method
	 *	 {
	 *		//Do something when operation successful
	 *	 }
	 *	 
	 */
	virtual int Unsubscribe( _IN_ int handle ) = 0;

};

#endif // _ISECTIONSUBSCRIBER_H_

