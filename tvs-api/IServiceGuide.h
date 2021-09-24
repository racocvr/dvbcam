/** 
* @file IServiceGuide.h
* @brief Application interface for service guide.
*
* Copyright 2013 by Samsung Electronics, Inc.,
* 
* This software is the confidential and proprietary information
* of Samsung Electronics, Inc. ("Confidential Information"). You
* shall not disclose such Confidential Information and shall use
* it only in accordance with the terms of the license agreement
* you entered into with Samsung.
*/
#ifndef _ISERVICEGUIDE_H_
#define _ISERVICEGUIDE_H_

#include <vector>
#include <map>
#include <list>

#include "MarshallingMarks.h"
#include "ServiceNavigationDataType.h"
#include "ServiceGuideDataType.h"
#include "ServiceData.h"
#include "ProgramData.h"
#include "TVServiceDataType.h"

class IServiceGuide
{
protected:
	virtual ~IServiceGuide(){};

public:


	/**
	 * @brief Method to query if an event is split and get a list of the schedule for all parts of the event.
	 * @remark The application requires this for managing conflicts and correctly updating the schedule list.
	 * @param [in] programId ID of the reference program.
	 * @param [out] programList Program data of the separated parts of the queried program. The Key of programList map is an startTime of the program event.
	 * @return Returns 1 if success
	 * @return When calling method failed returns -1.
	 *
	 *	 @paragraph <Example>
	 *	 This example will query if an event is split and obtain the programList(with every part) of split program event.
	 *	 
	 *	 @verbatim
	 *	 IServiceGuide* pGuide = NULL;
	 *	 TVServiceAPI::CreateServiceGuide(&pGuide); 			// IServiceGuide creation
	 *	 
	 *     TCProgramData programData; // this program data have to be get from other IServiceGuide's API liks GetProgramList()
	 *	 TCProgramId progId;
	 *	 programData.GetProgramId(progId);
	 *
	 *	 std::map<unsigned int, TCProgramData*> programList; 	// list of split parts of program event
	 *	 if(1 == pGuide->GetSplitProgramList(progId, programList))
	 *	 {
	 *		// event is split, list of parts successfully obtained
	 *	 }
	 */
	virtual int GetSplitProgramList(_IN_ const TCProgramId& programId, _OUT_ std::map<unsigned int, TCProgramData*>& out_program_map) = 0;

	/**
	 * @brief Get a list of program events that are underway in a given time period.
	 * @remark Program event that have starting time before startTime and ending time before/after startTime + duration is included.
	 * @remark Program event that have starting time after startTime and ending time before/after startTime + duration is included.
	 * @remark Program event that have starting time exactly on startTime + duration is excluded.
	 * @param [in] serviceId Key of service for which to return the program events list.
	 * @param [in] startTime Beginning of time period.
	 * @param [in] duration Duration of time period.
	 * @param [out] programList List of program events that are underway in a given time period. The Key of programList map is an startTime of the program event.
	 * @return  Returns 1 if success
	 * @return When calling method failed returns -1.
	 *
	 *	 @paragraph <Example>
	 *	 This example will get list of program events that are underway in a given time period defined as (startTime, startTime + duration).
	 *	 
	 *	 @verbatim
	 *	 IServiceGuide* pGuide = NULL;
	 *	 TVServiceAPI::CreateServiceGuide(&pGuide); 			// IServiceGuide creation
	 *	 
	 *	 TCServiceId id = service.ServiceId();					// specify key of service for which to return the program event list
	 *	 unsigned int startTime = getTime();					// specify beginning of time period
	 *	 unsigned int duration = 25000;							// specify duration of time period
	 *	 std::map<unsigned int, TCProgramData*> programList; 	// list of found program events
	 *	 
	 *	 if(1 == pGuide->GetProgramList(id, startTime, duration, programList))
	 *	 {
	 *		// list of size > 0 successfully obtained
	 *	 }
	 *	 @endverbatim
	 */
	virtual int GetProgramList(_IN_ const TCServiceId& serviceId, _IN_ unsigned int startTime, _IN_ unsigned int duration, _OUT_ std::map<unsigned int, TCProgramData*>& out_program_map) = 0;

	/**
	 * @brief Get a list of program events that are matched by a given crid and crid type.
	 * @param [in] crid Reference CRID.
	 * @param [in] cridType Type of crid.
	 * @param [out] programList List of program events that are matched by a given crid and crid type. The Key of programList map is an startTime of the program event.
	 * @return  Returns 1 if success
	 * @return When calling method failed returns -1.
	 *
	 *	 @paragraph <Example>
	 *	 This example will get list of program events that are matched by a given crid and crid type.
	 *	 
	 *	 @verbatim
	 *	 IServiceGuide* pGuide = NULL;
	 *	 TVServiceAPI::CreateServiceGuide(&pGuide); 			// IServiceGuide creation
	 *	 
	 *	 std::map<unsigned int, TCProgramData*> programList; 	// list of found program events
	 *	 if(1 == pGuide->GetProgramList("crid://tv.com/Friends", SERIES_CRID, programList))
	 *	 {
	 *		// list of size > 0 successfully obtained
	 *	 }
	 *	 @endverbatim
	 */
	virtual int GetProgramList(_IN_ const std::string crid, _IN_ ECRIDType cridType, _OUT_ std::map<unsigned int, TCProgramData*>& out_program_map) = 0;

	/**
	 * @brief Gets program for given program indicator and ID.
	 * @param [in] indicator Program indicator which determines search type.
	 * @param [in] referenceProgramId ID of a reference program upon which the search is done.
	 * @param [out] program Program event data found using specified criteria.
	 * @return Returns 1 if success
	 * @return When calling method failed returns -1.
	 *
	 *	 @paragraph <Example>
	 *	 This example will get the program event data that is specified by an indicator based on a given programId.
	 *	 
	 *	 @verbatim
	 *	 IServiceGuide* pGuide = NULL;
	 *	 TVServiceAPI::CreateServiceGuide(&pGuide); // IServiceGuide creation
	 *	 
	 *     TCProgramData programData; // this program data have to be get from other IServiceGuide's API liks GetProgramList()
	 *	 TCProgramId progId;
	 *	 programData.GetProgramId(progId);
	 *
	 *	 if(1 == pGuide->GetProgram(FIRST_PROGRAM, progId, program))
	 *	 {
	 *		// program was found
	 *	 }
	 *	 @endverbatim
	 */
	virtual int GetProgram(_IN_ EProgramIndicator indicator, _IN_ const TCProgramId& referenceProgramId, _OUT_ TCProgramData& program) = 0;

	/**
	 * @brief Gets program data by program ID.
	 * @param [in] referenceProgramId ID of a reference program upon which the search is done.
	 * @param [out] program Program event data found using specified criteria.
	 * @return  Returns 1 if success
	 * @return When calling method failed returns -1.
	 *
	 *	 @paragraph <Example>
	 *	 This example will get the program event data that is specified by a given programId.
	 *	 
	 *	 @verbatim
	 *	 IServiceGuide* pGuide = NULL;
	 *	 TVServiceAPI::CreateServiceGuide(&pGuide); // IServiceGuide creation
	 *	 
	 *	 TCProgramData program;						// output program event data
	 *	 TCProgramId progId;
	 *	 progId.m_serviceId = service.ServiceId();	// serviceId of service
	 *	 progId.m_eventId = someEventId;			// eventId of a program event
	 *
	 *	 if(1 == pGuide->GetProgram(progId, program))
	 *	 {
	 *		// program was found
	 *	 }
	 *	 @endverbatim
	 */
	virtual int GetProgram(_IN_ const TCProgramId& referenceProgramId, _OUT_ TCProgramData& program) = 0;

	/** 
	 * @brief Obtain a program data of a specified event genre.
	 * @remarks This method returns the first/next/previous/last program event data of the specified genre type on any service, using the supplied reference program id and the indicator parameter.
	 * @param [in] indicator Program indicator which determines search type.
	 * @param [in] genre Program event genre type.
	 * @param [in] referenceProgramId ID of a reference program upon which the search is done.
	 * @param [out] program Program event data found using specified criteria.
	 * @return Returns 1 if success
	 * @return When calling method failed returns -1.
	 *
	 *	 @paragraph <Example>
	 *	 This example will get the next program event of a given genre type.
	 *	 
	 *	 @verbatim
	 *	 IServiceGuide* pGuide = NULL;
	 *	 TVServiceAPI::CreateServiceGuide(&pGuide);		// IServiceGuide creation
	 *	 
	 *     TCProgramData programData; // this program data have to be get from other IServiceGuide's API liks GetProgramList()
	 *	 TCProgramId progId;
	 *	 programData.GetProgramId(progId);
	 *
	 *	 TCProgramData progDat; // program data object for the search result
	 *	 if(1 == pGuide->GetProgram(NEXT_PROGRAM, FSAT_MOVIE, progId, progDat))
	 *	 {
	 *		// search for the next program event of a given genre type successful
	 *		// data of progDat is valid
	 *	 }
	 *	 @endverbatim
	 */
	virtual int GetProgram(_IN_ EProgramIndicator in_indicator, _IN_ EFSatEventGenreType in_genre, _IN_ const TCProgramId& in_program_id, _OUT_ TCProgramData& out_program_data) = 0;

	/**
	 * @brief Gets present program for given service ID.
	 * @param [in] serviceId ID of a service.
	 * @param [out] program Program data for given criteria.
	 * @return Returns 1 if success
	 * @return When calling method failed returns -1.
	 *
	 *	 @paragraph <Example>
	 *	 This example will get the program event data of the present program event.
	 *	 
	 *	 @verbatim
	 *	 IServiceGuide* pGuide = NULL;
	 *	 TVServiceAPI::CreateServiceGuide(&pGuide);		// IServiceGuide creation
	 *	 
	 *	 TCProgramData program;							// output program event data
	 *	 TCServiceId serviceId = service.ServiceId();	// serviceId of service
	 *
	 * 	 if(1 == pGuide->GetPresentProgram(serviceId, program))
	 *	 {
	 *		// present program was found
	 *	 }
	 *	 @endverbatim
	 */
	virtual int GetPresentProgram(_IN_ const TCServiceId& serviceId, _OUT_ TCProgramData& program) = 0;

	/**
	 * @brief Gets map of currently available program genres.
	 * @remark It is up to the caller to free the memory allocated for the names in the map.
	 * @param [out] genres Map of program genres that will be populated with the available service genres.
	 * @return  Returns 1 if success
	 * @return When calling method failed returns -1.
	 *
	 *	 @paragraph <Example>
	 *	 This example will get get all the available service genres.
	 *	 
	 *	 @verbatim
	 *	 IServiceGuide* pGuide = NULL;
	 *	 TVServiceAPI::CreateServiceGuide(&pGuide);		// IServiceGuide creation
	 *	 
	 *	 std::map<unsigned short, t_wstring> genres;	// output available service genres
	 *
	 * 	 if(1 == pGuide->GetGenreList(genres) )
	 *	 {
	 *		// valid available genres
	 *	 }
	 *	 @endverbatim
	 */
	virtual int GetGenreList(_OUT_ std::map<unsigned short, t_wstring>& out_genre_map) = 0;

	/**
	 * @brief Swaps programs data between two given services.
	 * @param [in] destService Service ID of destination service.
	 * @param [in] srcService Service ID of source service.
	 * @return Returns 1 if success
	 * @return When calling method failed returns -1.
	 *
	 *	 @paragraph <Example>
	 *	 This example will swap services data between given services.
	 *
	 *	 @verbatim
	 *	 IServiceGuide* pGuide = NULL;
	 *	 TVServiceAPI::CreateServiceGuide(&pGuide); // IServiceGuide creation
	 *	 
	 * 	 if(1 == pGuide->SwapPrograms(destService, srcService) )
	 *	 {
	 *		// program data successfully swapped between services
	 *	 }
	 *	 @endverbatim
	 */
	virtual int SwapPrograms(_IN_ const TCServiceId& destService, _IN_ const TCServiceId& srcService) = 0;

	/**
	 * @brief Check if program with given service ID, duration and start time exists.
	 * @param [in] serviceId ID of service.
	 * @param [in] startTime Start time of program.
	 * @param [in] duration Duration of program.
	 * @param [out] exist True if program exists.
	 * @return Returns 1 if success
	 * @return When calling method failed returns -1.
	 *
	 *	 @paragraph <Example>
	 *	 This example will check existence of program with given parameters.
	 *	 
	 *	 @verbatim
	 *	 IServiceGuide* pGuide = NULL;
	 *	 TVServiceAPI::CreateServiceGuide(&pGuide);		// IServiceGuide creation
	 *	 
	 *	 TCProgramData program;							// output program event data
	 *	 TCServiceId serviceId = service.ServiceId();	// serviceId of service
	 *	 unsigned int startTime = getTime();			// specify time of event
	 *	 unsigned int duration = 25000;					// specify duration in seconds
	 *	 bool exist;									// output value
	 *
	 *	 if(1 == pGuide->CheckProgramExists(serviceId, startTime, duration, exist))
	 *	 {
	 *		// program exists
	 *	 }
	 *	 @endverbatim
	 */
	virtual int CheckProgramExists(_IN_ const TCServiceId& serviceId, _IN_ unsigned int startTime, _IN_ unsigned int duration, _OUT_ bool& exist) = 0;

	/**
	 * @brief Get barker channel.
	 * @param [in] tvMode Defines TV mode for which to return the barker channel.
	 * @param [out] barkerChannel the barker channel locator.
	 * @return Returns 1 if success
	 * @return When calling method failed returns -1.
	 *
	 *	@paragraph <Example>
	 *	This example will get barker channel for due TV mode.
	 *
	 *	@verbatim
	 *	IServiceGuide* pGuide = NULL;
	 *	TVServiceAPI::CreateServiceGuide(&pGuide);
	 *	if(1 == pGuide->GetBarkerChannel( tvMode, barkerChannel ) )
	 *	{
	 *		//Do something when operation successful
	 *	}
	 *	@endverbatim
	 */
	virtual int GetBarkerChannel(_IN_ const TSTvMode& tvMode, _OUT_ TSBarkerChannelLocator& barkerChannel) = 0;

	/** 
	 * @brief Obtain simulcast infomation of given program id.
	 * @remarks simulcast infomations can be empty
	 * @param [in] reference program id which want to get the simulcast infomation
	 * @param [out] simulcast information list
	 * @return Returns 1 if success
	 * @return When calling method failed returns -1.
	 *
	 *	 
	 *	 @verbatim
	 *	 IServiceGuide* pGuide = NULL;
	 *	 TVServiceAPI::CreateServiceGuide(&pGuide);		// IServiceGuide creation
	 *	 
	 *     TCProgramData programData; // this program data have to be get from other IServiceGuide's API liks GetProgramList()
	 *	 TCProgramId progId;
	 *	 programData.GetProgramId(progId);
	 *
	 *	 std::list<ESimulcastInfo> out_simulcastInfoList
	 *	 if(1 == pGuide->GetSimulcastInfo(progId, out_simulcastInfoList))
	 *	 {
	 *		//do something if success
	 *	 }
	 *	 @endverbatim
	 */
	virtual int GetSimulcastInfo( _IN_ const TCProgramId& in_programId, _OUT_ std::list<ESimulcastInfo>& out_simulcastInfoList ) = 0;

	/** 
	 * @brief get the Freesat programdata list by genre filtering
	 * @remarks it is only for Freesat
	 * @param [in] startTime Start time of program.
	 * @param [in] duration Duration of program.
	 * @param [in] in_event_genre_type: Freesat Genre type
	 * @param [out] out_program_map: program map which have given genre type
	 * @return Returns 1 if success
	 * @return When calling method failed returns -1.
	 *
	 *	 
	 *	 @verbatim
	 *	 IServiceGuide* pGuide = NULL;
	 *	 TVServiceAPI::CreateServiceGuide(&pGuide);		// IServiceGuide creation
	 *	 unsigned long startTime = getTime();			// specify time of event
	 *	 unsigned long duration = 25000;					// specify duration in seconds
	 *
	 *	 std::map<unsigned int, TCProgramData*> out_program_map;
	 *	 if(1 == pGuide->GetProgramListByGenre(startTime, duration, FSAT_MOVIE, out_program_map))
	 *	 {
	 *		//do something if success
	 *	 }
	 *	 @endverbatim
	 */
	virtual int GetProgramListByGenre(_IN_ unsigned long in_starttime, _IN_ unsigned long in_duration, _IN_ const EFSatEventGenreType in_event_genre_type, _OUT_ std::map<unsigned int, TCProgramData*>& out_program_map) = 0;

	/**
	 * @brief Query if a service belongs to a service group.
	 *
	 * @remarks Freesat can present a list of available service genres (specified by
	 * the group_id, as detailed in Freesat 2 section 9.2.1), and the text
	 * that must be displayed for this group_id. The free satellite servicegroup
	 * name descriptor contains a mapping of group_id to service group name,
	 * for a specified ISO 639 language code. Therefore the descriptor may
	 * contain multiple names for a given group_id, for different languages.
	 * This API returns the best match for the preferred display language.
	 *
	 * @param [in] freesatId The service ID of the service to query
	 * @param [in] groupId The group ID of the group to check.
	 * @param [out] exist The value is true when given freesatId belongs to given groupId.
	 * @return 1 if success.
	 * @return When calling method failed returns -1.
	 *
	 *
	 *	@verbatim
	 *	IServiceGuide* pGuide = NULL;
	 *	TVServiceAPI::CreateServiceGuide(&pGuide);     // IServiceGuide creation
	 *	unsigned short freesatId = pServiceData->Get<unsigned short>( FREESAT_ID ); // pServiceData is type of TCServiceData pointer
	 *	bool exist = false;
	 *	if (1 == pGuide->CheckServiceInGroup(freesatId, allocation_id, exist))
	 *	{
	 *		// do something if successful
	 *	}
	 *	@endverbatim
	 */
	virtual int CheckServiceInGroup(_IN_ unsigned short freesatId, _IN_ unsigned short groupId, _OUT_ bool & exist) = 0;

	/**
	 * @brief set range for receiving epg dynamic update event
	 *
	 * @remarks service id list and start/end time is needed
	 * @param [in] in_subscribe_id: identification Unique identifier.
	 * @param [in] in_service_ids: the list of service IDs which represent vertial range .
	 * @param [in] in_start_time: the time which represent start of horizontal range.
	 * @param [in] in_end_time:  the time which represent end of horizontal range.
	 * @return 1 if success.
	 * @return When calling method failed returns -1.
	 *
	 *
	 *	@verbatim
	 *	IServiceGuide* pGuide = NULL;
	 *	TVServiceAPI::CreateServiceGuide(&pGuide);     // IServiceGuide creation
	 *    std::vector<TCserviceId> service_ids;
	 *    service_ids.push_back(8078970135039591422);
	 *	unsigned long start_time =0;
	 *    unsigned long end_time = 3600;
	 *	if (1 == pGuide->SetEPGDynamicUpdateEventFocusRange(service_ids, start_time, end_time))
	 *	{
	 *		// do something if successful
	 *	}
	 *	@endverbatim
	 */
	virtual int SetEPGDynamicUpdateEventFocusRange( _IN_ int in_subscribe_id, _IN_ std::vector<TCServiceId>& in_service_ids, _IN_ unsigned long in_start_time, _IN_ unsigned long in_end_time) = 0;

	/**
	 * @brief Get a list of program events that are underway in a given time period with specified list of key service.
	 * @remark Program event that have starting time before startTime and ending time before/after startTime + duration is included.
	 * @remark Program event that have starting time after startTime and ending time before/after startTime + duration is included.
	 * @remark Program event that have starting time exactly on startTime + duration is excluded.
	 * @param [in] servicesId List of key service for which to return the program events list.
	 * @param [in] startTime Beginning of time period.
	 * @param [in] duration Duration of time period.
	 * @param [out] programMap List of program events that are underway in a given time period. The Key of programList map is an startTime of the program event.
	 * @return  Returns 1 if success, return 0 if program list is empty.
	 * @return When calling method failed returns -1.
	 *
	 *	 @paragraph <Example>
	 *	 This example will get list of program events that are underway in a given time period defined as (startTime, startTime + duration).
	 *	 
	 *	 @verbatim
	 *	 IServiceGuide* pGuide = NULL;
	 *	 TVServiceAPI::CreateServiceGuide(&pGuide); 			// IServiceGuide creation
	 *	 
	 *	 std::vector<TCServiceId> servicesId;					// specify list of key service for which to return the program event list
	 *	 unsigned int startTime = getTime();					// specify beginning of time period
	 *	 unsigned int duration = 25000;							// specify duration of time period
	 *	 std::map<unsigned int, TCProgramData*> programList; 	// list of found program events
	 *	 
	 *	 if(1 == pGuide->GetProgramList(servicesId, startTime, duration, programList))
	 *	 {
	 *		// list of size > 0 successfully obtained
	 *	 }
	 *	 @endverbatim
	 */
	virtual int GetProgramList(_IN_ std::vector<TCServiceId> servicesId, _IN_ unsigned int startTime, _IN_ unsigned int duration, _OUT_ std::map<TCServiceId,  std::map<unsigned int, TCProgramData*> >& programMap) = 0;

	/**
	 * @brief Save program data to flash memory.
	 * @return Returns 1 on success, return 0 otherwise.
	 * @return When calling this method failed returns -1.
	 *
	 *
	 *	@verbatim
	 *	IServiceGuide* pGuide = NULL;
	 *	TVServiceAPI::CreateServiceGuide(&pGuide);     // IServiceGuide creation
	 *
	 *	if( 0 < pGuide->SaveProgramData() )
	 *	{
	 *		// do something if success
	 *	}
	 *	@endverbatim
	 */
	virtual int SaveProgramData(void) = 0;
};

#endif // _ISERVICEGUIDE_H_

