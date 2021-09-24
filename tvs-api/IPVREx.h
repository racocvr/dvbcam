/** 
 * @file IPVREx.h
 * @brief Application interface for Early Warning Broadcast System.
 *
 * Copyright 2015 by Samsung Electronics, Inc.,
 * 
 * This software is the confidential and proprietary information
 * of Samsung Electronics, Inc. ("Confidential Information"). You
 * shall not disclose such Confidential Information and shall use
 * it only in accordance with the terms of the license agreement
 * you entered into with Samsung.
 */

#ifndef _IPVREX_H_
#define _IPVREX_H_


#include <vector>
#include <string>

#include "MarshallingMarks.h"
#include "PVRExDataType.h"


class IPVREx
{
protected:

	virtual ~IPVREx() {};

public:
	/**
	 * @brief Starts making thumbnail's frame file. When file is ready SIGNAL_PVR_MAKETHUMBNAIL_DONE is sent.
	 * @param [in] fileName Thumbnail's frame file name.
	 * @return Returns 1 if data was retrieved, otherwise returns 0.
	 * @return When calling method failed returns -1.
	 *
	 *	@paragraph <Example>
	 *
	 *	@verbatim
	 *	IPVREx* pPvrEx;
	 *	TVServiceAPI::CreatePVREx(&pPvrEx);
	 *
	 *	std::string srfFileName;
	 *	if( pPvrEx->MakeThumbnailFrameFileStart( srfFileName) > 0 )
	 *	{
	 *		//Do something.
	 *	}
	 *	@endverbatim
	 */
	virtual int MakeThumbnailFrameFileStart(const _IN_ std::string & fileName) = 0;

	/**
	 * @brief Gets thumbnail's frame file info.
	 * @param [out] size vector of sizes.
	 * @param [out] codecType vector of codecs types.
	 * @return Returns 1 if data was retrieved, otherwise returns 0.
	 * @return When calling method failed returns -1.
	 *
	 *	@paragraph <Example>
	 *
	 *	@verbatim
	 *	IPVREx* pPvrEx;
	 *	TVServiceAPI::CreatePVREx(&pPvrEx);
	 *
	 *	int size = 0;
	 *	int codecType = 0;
	 *	if( pPvrEx->GetThumbnailFrameFileInfo( size, codecType ) > 0 )
	 *	{
	 *		//Do something.
	 *	}
	 *	@endverbatim
	 */
	virtual int GetThumbnailFrameFileInfo(_OUT_ std::vector<int> & size, _OUT_ std::vector<int> & codecType) = 0;

	/**
	 * @brief Checks available tuner for recording. If there is idle tuner it return true.
	 * If there is the same mux tuner it return true (CPLD case can be checked in this function).
	 * This function will check resource limitation with input service ID(If input service ID is ATV, only main tuner can be available).
	 * If this function return false, SetService() should be called for starting record.
	 * @param [in] serviceId service ID record want to be started on
	 * @param [out] result true if there is available tuner to record. Otherwise false.
	 * @return Returns 1 if data was retrieved, otherwise returns 0.
	 * @return When calling method failed returns -1.
	 *
	 *	@paragraph <Example>
	 *	This example will Extracts thumbnail's frame file.
	 *
	 *	@verbatim
	 *	IPVREx* pPvrEx;
	 *	TVServiceAPI::CreatePVREx(&pPvrEx);
	 *
	 *	TCServiceId serviceId;
	 *	int result;
	 *	if( pPvrEx->CheckAvailableTunerToRecord( serviceId, result) > 0 )
	 *	{
	 *		//Do something.
	 *	}
	 *	@endverbatim
	 */
	virtual int CheckAvailableTunerToRecord( _IN_ const TCServiceId& serviceId, _OUT_ int& result) = 0;

	/**
	 * @brief Find tuners that have no dependency with another pipeline( ex. analysis pipeline / record pipeline ).
	 * Returned tuners can be tuned for record:
	 * - linked screen ID can be got from linkedProfile value
	 * - before starting record, SetService() will be called using returned tuner info
	 * @param [in] serviceId service ID that record wants to be started on
	 * @param [out] tunerInfoList tuner information list can that be tuned for record on input service ID channel
	 * @return Returns 1 if data was retrieved, otherwise returns 0.
	 * @return When calling method failed returns -1.
	 *
	 *	@paragraph <Example>
	 *	This example will Extracts thumbnail's frame file.
	 *
	 *	@verbatim
	 *	IPVREx* pPvrEx;
	 *	TVServiceAPI::CreatePVREx(&pPvrEx);
	 *
	 *	TCServiceId serviceId;
	 *	std::vector<TCTunerInfo>& tunerInfoList;
	 *	if( pPvrEx->GetCandidateTunerList( serviceId, tunerInfoList) > 0 )
	 *	{
	 *		//Do something.
	 *	}
	 *	@endverbatim
	 */
	virtual int GetCandidateTunerList( _IN_ const TCServiceId& serviceId, _OUT_ std::vector<TCTunerInfo>& tunerInfoList) = 0;

	/**
	 * @brief Finds conflict recordings for changing channel.
	 * When receiving SIGNAL_TUNE_PREPARATION signal, recordings that should be stopped can be got.
	 * @param [in] screenId screen id of changing channel
	 * @param [in] serviceId service ID of next channel
	 * @param [out] conflictRecordList recorderâ€TVSHandle info should be stopped for changing channel
	 * @param [out] isAll all have to be stopped
	 * @return Returns 1 if data was retrieved, otherwise returns 0.
	 * @return When calling method failed returns -1.
	 *
	 *	@paragraph <Example>
	 *	This example will Extracts thumbnail's frame file.
	 *
	 *	@verbatim
	 *	IPVREx* pPvrEx;
	 *	TVServiceAPI::CreatePVREx(&pPvrEx);
	 *
	 *	int screenId;
	 *	TCServiceId serviceId;
	 *	std::vector<TVSHandle> conflictRecordList;
	 *	if( pPvrEx->GetConflictRecordListForChannelChange( screenId, serviceId, conflictRecordList) > 0 )
	 *	{
	 *		//Do something.
	 *	}
	 *	@endverbatim
	 */
	virtual int GetConflictRecordListForChannelChange( _IN_ const int screenId, _IN_ const TCServiceId& serviceId,
			_OUT_ std::vector<TVSHandle>& conflictRecordList, _OUT_ bool& isAll) = 0;

	/**
	 * @brief Finds conflict recordings for changing source.
	 * When receiving SIGNAL_SOURCECHANGE_PREPARATION signal, recordings that should be stopped can be got.
	 * @param [in] screenId screen id of changing source
	 * @param [in] sourceType next source type
	 * @param [out] conflictRecordList recorderâ€TVSHandle info that should be stopped for changing source
	 * @param [out] isAll all have to be stopped
	 * @return Returns 1 if data was retrieved, otherwise returns 0.
	 * @return When calling method failed returns -1.
	 *
	 *	@paragraph <Example>
	 *	This example will Extracts thumbnail's frame file.
	 *
	 *	@verbatim
	 *	IPVREx* pPvrEx;
	 *	TVServiceAPI::CreatePVREx(&pPvrEx);
	 *
	 *	int screenId;
	 *	int sourceType;
	 *	std::vector<TVSHandle>& conflictRecordList;
	 *	if( pPvrEx->GetConflictRecordListForSourceChange( screenId, sourceType, conflictRecordList) > 0 )
	 *	{
	 *		//Do something.
	 *	}
	 *	@endverbatim
	 */
	virtual int GetConflictRecordListForSourceChange( _IN_ const int screenId, _IN_ const int sourceType,
			_OUT_ std::vector<TVSHandle>& conflictRecordList, _OUT_ bool& isAll) = 0;

	/**
	 * @brief Checks if an given file was recorded on this tv set.
	 * If the file was recored on diffrent tv set it cannot be played.
	 * @param [in] fileName path to recorded file
	 * @param [out] result true if file was recorde on this tv set. Otherwise false.
	 * @return Returns 1 if data was retrieved, otherwise returns 0.
	 * @return When calling method failed returns -1.
	 *
	 *	@paragraph <Example>
	 *
	 *	@verbatim
	 *	IPVREx* pPvrEx;
	 *	TVServiceAPI::CreatePVREx(&pPvrEx);
	 *
	 *	std::string fileName;
	 *	bool result;
	 *	if( pPvrEx->IsFileRecordedLocal( fileName, result ) > 0 )
	 *	{
	 *		//Do something.
	 *	}
	 *	@endverbatim
	 */
	virtual int IsFileRecordedLocal( _IN_ const std::string & fileName, _OUT_ bool & result) = 0; 

};


#endif //_IPVREX_H_
