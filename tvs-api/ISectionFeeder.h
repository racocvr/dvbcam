/** 
 * @file ISectionFeeder.h
 * @brief Application interface for feeding sections to TVS.
 * @remarks Feeder instance should be created per profile id/sub id.
 * @remarks For feeding sections from multiple channels, multiple feeder instances should be created.
 *
 * Copyright 2014 by Samsung Electronics, Inc.,
 * 
 * This software is the confidential and proprietary information
 * of Samsung Electronics, Inc. ("Confidential Information"). You
 * shall not disclose such Confidential Information and shall use
 * it only in accordance with the terms of the license agreement
 * you entered into with Samsung.
 */


#ifndef _ISECTIONFEEDER_H_
#define _ISECTIONFEEDER_H_

#include "MarshallingMarks.h"
#include "SectionFeederDataType.h"
#include "ServiceData.h"

class ISectionFeeder
{
protected:
	virtual ~ISectionFeeder() {}

public:


	/**
	 * @brief Prepare for sections feeding - initialize functionalities responsible for processing sections that will be fed in next step.
	 * @remarks Profile id should be PROFILE_TYPE_MEDIA, sub id represents channel number.
	 * @remarks Call this method before feeding sections is started. Otherwise fed sections will not be processed.
	 * @remarks Calling Start() will failed if ISectionFeeder for specified tvsHandle was already started (please use another subId is such case).
	 * @param [out] channel Services defined by fed sections will be temporarily added to service DB in scope of this channel;
	 *	after calling start method, following data will be added to 'channel': CHANNEL_TYPE, SERVICE_PROFILE and CHANNEL_NUMBER;
	 *	that data should be then used to find services defined by fed sections and added to service DB. 
	 * @return Returns 1 if preparing for sections feeding succeeded, otherwise returns 0.
	 * @return When calling method failed returns -1.
	 *
	 *	 @paragraph <Example>
	 *	 This example shows how to initialize sections feeder and how to use output 'channel'.
	 *	 
	 *	 @verbatim
	 *	 ISectionFeeder* pFeeder = NULL;
	 *	 // Feeder instances should be created for PROFILE_TYPE_MEDIA.
	 * 	 TVServiceAPI::CreateSectionFeeder(PROFILE_TYPE_MEDIA, 0, &pFeeder);
	 *
	 *	 TCServiceData feedChannel;
	 *	 if( pFeeder->Start( feedChannel ) > 0 )
	 *	 {
	 *		// starting successfull
	 *	 }
	 *	 ...
	 *	 feed sections
	 *	 ...
	 *	 wait for SIGNAL_FED_SECTIONS_PROCESSED
	 *	 ...
	 *	 // Get size of audio for one of services created for fed sections.
	 *	 TCCriteriaHelper criteria;
	 *	 criteria.Where(CHANNEL_TYPE, feedChannel.Get<EChannelType>(CHANNEL_TYPE));
	 *	 criteria.Where(SERVICE_PROFILE, feedChannel.Get<unsigned short>(SERVICE_PROFILE));
	 *	 criteria.Where(CHANNEL_NUMBER, feedChannel.Get<unsigned short>(CHANNEL_NUMBER));
	 *	 criteria.Fetch(SERVICE_ID);
	 *	 std::list<TCServiceData*> services;
	 *	 IService::FindServices(criteria, services);
	 *	 // here 'services' list contains all services added to service db for sections fed in step above
	 *	 if( services.empty() == false )
	 *	 {
	 *	 	TCServiceData* pService = *services.begin();
	 *		TCServiceId serviceId = pService->Get<TCServiceId>(SERVICE_ID);
	 *		unsigned int sizeOfAudio = 0;
	 *		IServiceDataAux::SizeOfAudio( serviceId, sizeOfAudio );
	 *	 }
	 *	 // Stop feeder
	 *	 pFeeder->Stop();
	 *	 // At this point services found above are no longer valid - all temporary data related to fed sections is removed.
	 *	 @endverbatim
	 */
	virtual int Start( _OUT_ TCServiceData& channel ) = 0;

	/**
	 * @brief Prepare for sections feeding - initialize functionalities responsible for processing sections that will be fed in next step (only for CI usage).
	 * @remarks Call this method before feeding sections is started. Otherwise fed sections will not be processed.
	 * @remarks Calling Start() will failed if ISectionFeeder for specified tvsHandle was already started (please use another subId is such case).
 	 * @remarks If SERVICE_ID is provided all service data will be aquired from service DB.
	 * @remarks If SERVICE_ID is not provided new service will be created according to tvsHandle (SERVICE_PROFILE == profileId and CHANNEL_NUMBER == subId).
	 * @param [inout] channel Service provided by application or (if SERVICE_ID is not specified) service created by TVS and returned to application. 
	 * @return Returns 1 if preparing for sections feeding succeeded, otherwise returns 0.
	 * @return When calling method failed returns -1.
	 *
	 *	 @paragraph <Example>
	 *	 This example shows how to initialize sections feeder and how to use output 'channel'.
	 *	 
	 *	 @verbatim
	 *	 ISectionFeeder* pFeeder = NULL;
	 * 	 TVServiceAPI::CreateSectionFeeder(PROFILE_TYPE_MAIN, 0, &pFeeder);
	 *
	 *	 TCServiceId serviceId = 123456789;
	 *	 TCServiceData feedChannel;
	 *	 feedChannel.Set<TCServiceId>( SERVICE_ID, 123456789 );
	 *	 if( pFeeder->StartForCI( feedChannel ) > 0 )
	 *	 {
	 *		// starting successfull
	 *	 }
	 *	 ...
	 *	 feed sections
	 *	 ...
	 *	 wait for SIGNAL_FED_SECTIONS_PROCESSED
	 *	 ...
	 *	 // Get size of audio for one of services created for fed sections.
	 *	 unsigned int sizeOfAudio = 0;
	 *	 IServiceDataAux::SizeOfAudio( serviceId, sizeOfAudio );
	 *	 
	 *	 // Stop feeder
	 *	 pFeeder->Stop();
	 *	 // All data provided by sections still exists in the TVS (agents and DB) after stopping feeder.
	 *	 @endverbatim
	 */
	virtual int StartForCI( _INOUT_ TCServiceData& channel ) = 0;


	/**
	 * @brief Stop section feeding.
	 * @remarks Call this method when feeding sections is completed.
	 * @remarks Temporary service created by calling Start() method will be destroyed together with all volitile data (audio, es data).
	 * @return Returns 1 if stopping sections feeding succeeded, otherwise returns 0.
	 * @return When calling method failed returns -1.
	 *
	 *	 @paragraph <Example>
	 *	 This example shows how to stop sections feeder.
	 *	 
	 *	 @verbatim
	 *	 ISectionFeeder* pFeeder = NULL;
	 *	 // Feeder instances should be created for PROFILE_TYPE_MEDIA.
	 * 	 TVServiceAPI::CreateSectionFeeder(PROFILE_TYPE_MEDIA, 0, &pFeeder);
	 *
	 *	 TCServiceData feedChannel;
	 *	 if( pFeeder->Start( feedChannel ) > 0 )
	 *	 {
	 *		// starting successfull
	 *	 }
	 *	 ...
	 *	 feed sections
	 *	 ...
	 *	 // Stop feeder
	 *	 pFeeder->Stop();
	 *	 @endverbatim
	 */
	virtual int Stop( void ) = 0;


	/**
	 * @brief Feed section to TVS.
	 * @remarks SI sections might be acquired from various sources, not only from tuner.
	 * 	To reuse TVS functionality for processing such sections, feeder interface is provided.
	 * @remarks APP will be notified after fed section is processed - SIGNAL_FED_SECTIONS_PROCESSED will be sent.
	 * @param [in] section Section to be fed to TVS.
	 * @return Returns 1 if section feeding succeeded, otherwise returns 0.
	 * @return When calling method failed returns -1.
	 *
	 *	 @paragraph <Example>
	 *	 This example shows how to feed single section to TVS.
	 *	 
	 *	 @verbatim
	 *	 ISectionFeeder* pFeeder = NULL;
	 *	 // Feeder instances should be created for PROFILE_TYPE_MEDIA.
	 * 	 TVServiceAPI::CreateSectionFeeder(PROFILE_TYPE_MEDIA, 0, &pFeeder);
	 *
	 *	 unsigned char temp[] = {0x02, 0xB0, 0x0D, 0x00, 0xAA, 0xC1, 0x00, 0x00, 0xFF, 0xFF, 0xF0, 0x00, 0x02, 0xD6, 0x68, 0x4D};
	 *	 TCSectionData section;
	 *	 section.SetPid(1700);
	 *	 section.SetData(temp, 16);
	 *	 
	 *	 //subscribing for sections
	 *	 if(pFeeder->FeedSection(section) > 0)
	 *	 {
	 *		// feeding successfull
	 *	 }
	 *	 @endverbatim
	 */
	virtual int FeedSection( _IN_ const TCSectionData& section ) = 0;

};

#endif // _ISECTIONFEEDER_H_

