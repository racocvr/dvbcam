/** 
 * @file IEITRawData.h
 * @brief Application interface for receiving EIT data
 *
 * Copyright 2013 by Samsung Electronics, Inc.,
 * 
 * This software is the confidential and proprietary information
 * of Samsung Electronics, Inc. ("Confidential Information"). You
 * shall not disclose such Confidential Information and shall use
 * it only in accordance with the terms of the license agreement
 * you entered into with Samsung.
 */


#ifndef _IEITRAWDATA_H_
#define _IEITRAWDATA_H_

#include <vector>
#include <string>

#include "MarshallingMarks.h"
#include "EITRawDataDataType.h"
#include "ServiceData.h"

#include "RawEpgData.h"

class IEITRawData
{
protected:
	virtual ~IEITRawData(void){};

public:

	/*deprecated -will be deleted*/virtual int GetEITRawData(_IN_ const TCServiceId& serviceId, _IN_ const TCEITFilteringItem& item, _OUT_ TCRawEpgData& epgData){ return 0;}

	/** @brief Get raw Epg data.
 	* @remarks Retrieve the cached present and following event sections for the specified service. This invokes a user defined copy callback function which may be used to copy the data to a destination defined by the user (or to perform some other action).
 	* @param [in] tsid The transport stream identity, this may be specified as EPG_ANY if any transport stream identity is required.
 	* @param [in] onid The original network identity, this may be specified as EPG_ANY if any original network identity is required.
 	* @param [in] sid The service identity.
 	* @param [out] pParam Structure that contains pointer to copied buffer and size.
	* @return Returns true on success, otherwise false.
 	*/
	virtual int GetRawEpgDataUsingAlloc(_IN_ unsigned short in_tsid,_IN_  unsigned short in_onid,_IN_ unsigned short in_sid, _OUT_ TTRawEpgData& out_raw_epg_data) = 0;

	/** @brief Get raw Epg data.
	* @remarks Retrieve the cached event sections from the specified service based on a specified event ID. This invokes a user defined copy callback function which may be used to copy the data to a destination defined by the user (or to perform some other action).
 	* @param [in] tsid The transport stream identity, this may be specified as EPG_ANY if any transport stream identity is required.
 	* @param [in] onid The original network identity, this may be specified as EPG_ANY if any original network identity is required.
 	* @param [in] sid The service identity.
 	* @param [in] ucEventId Event ID.
 	* @param [out] pParam Structure that contains pointer to copied buffer and size.
	* @return Returns true on success, otherwise false.
 	*/
    virtual int GetRawEpgDataUsingAlloc(_IN_ unsigned short in_tsid, _IN_ unsigned short in_onid, _IN_ unsigned short in_sid, _IN_ unsigned short in_event_id, _OUT_ TTRawEpgData& out_raw_epg_data) = 0;

	/** @brief Get raw Epg data.
	* @remarks Retrieve the cached event sections from the specified service based on a specified event ID. This invokes a user defined copy callback function which may be used to copy the data to a destination defined by the user (or to perform some other action).
 	* @param [in] tsid The transport stream identity, this may be specified as EPG_ANY if any transport stream identity is required.
 	* @param [in] onid The original network identity, this may be specified as EPG_ANY if any original network identity is required.
 	* @param [in] sid The service identity.
	* @param [in] ulStartTime Start time of the section of interest.
	* @param [in] uDuration Duration of the section of interest.
 	* @param [out] pParam Structure that contains pointer to copied buffer and size.
	* @return Returns true on success, otherwise false.
 	*/
    virtual int GetRawEpgDataUsingAlloc(_IN_ unsigned short in_tsid, unsigned short in_onid,_IN_  unsigned short in_sid, _IN_ unsigned long in_start_time, _IN_ unsigned long in_duration, _OUT_ TTRawEpgData& out_raw_epg_data)= 0;

	/** @brief Get raw Epg data.
	* @remarks Retrieve the cached event sections from the specified service based on a specified event ID. This invokes a user defined copy callback function which may be used to copy the data to a destination defined by the user (or to perform some other action).
	* @param nHandle Handle to the subscription already registered - the subscription contains the starttime, endtime and the channel key required to get the eit datanote - there is no subscription function to get based on an event id.
 	* @param [out] pParam Structure that contains pointer to copied buffer and size.
	* @return Returns true on success, otherwise false.
 	*/
    virtual int GetRawEpgDataUsingAlloc(_IN_ int in_handle, _OUT_ TTRawEpgData& out_raw_epg_data)= 0;
};

#endif // _IEITRAWDATA_H_

