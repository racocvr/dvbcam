/** 
 * @file EITRawDataDataType.h
 * @brief EIT raw data related types.
 *
 * Copyright 2013 by Samsung Electronics, Inc.,
 * 
 * This software is the confidential and proprietary information
 * of Samsung Electronics, Inc. ("Confidential Information"). You
 * shall not disclose such Confidential Information and shall use
 * it only in accordance with the terms of the license agreement
 * you entered into with Samsung.
 */

#ifndef _EITRAWDATADATATYPE_H_
#define _EITRAWDATADATATYPE_H_

#include "Marshalable.h"


typedef enum
{
	TYPE_SERVICE_ONLY,
	TYPE_EVENT_ID,
	TYPE_TIME_RANGE,
} EEITFilteringType;


class TCEITFilteringItem : public TCMarshalable
{
private:
	enum 
	{
		TAG_TYPE,
		TAG_EVENTID,
		TAG_STARTTIME,
		TAG_ENDTIME,
	};

public : 
	TCEITFilteringItem(EEITFilteringType type = TYPE_SERVICE_ONLY) : m_filteringType(type) {};

	/**
	 * @brief Sets value for time range
	 * @param [in] startTime start time
	 * @param [in] endTime end time
	 * @return result of method call (0 == success)
	 */
	int SetValueForTimeRange(unsigned int startTime, unsigned int endTime);
	
	/**
	 * @brief Sets value for event id
	 * @param [in] eventId event id
	 * @return result of method call (0 == success)
	 */
	int SetValueForEventId(unsigned short eventId);
	
	/**
	 * @brief Returns value of event id
	 * @return event id
	 */
	EEITFilteringType GetFilteringType(){ return m_filteringType; }
	
	/**
	 * @brief Returns value of event id
	 * @return event id
	 */
	unsigned short GetEventId(){ return m_eventId; }
	
	/**
	 * @brief Returns value of start time
	 * @return start time
	 */
	unsigned short GetStartTime(){ return m_startTime; }
	
	/**
	 * @brief Returns value of end time
	 * @return end time
	 */
	unsigned short GetEndTime(){ return m_endTime; }
	
	/**
	 * @brief Extract Tree from Class
	 * @param [inout] treeParent branch to which object data should be added
	 * @return true if success
	 */
	bool ClassToTree(TCTreeBranch& treeParent);

	/**
	 * @brief Fill out Class from Tree
	 * @param [inout] treeMine branch from which object data should be fetched
	 * @return true if success
	 */
	bool TreeToClass(TCTreeBranch& treeMine);
private : 
	EEITFilteringType m_filteringType;
	unsigned short m_eventId;
	unsigned int m_startTime;
	unsigned int m_endTime;
};

#endif // _EITRAWDATADATATYPE_H_
