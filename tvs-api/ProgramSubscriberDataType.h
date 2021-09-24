/** 
 * @file ProgramSubscriberDataType.h
 * @brief Program subscription related data types.
 *
 * Copyright 2013 by Samsung Electronics, Inc.,
 * 
 * This software is the confidential and proprietary information
 * of Samsung Electronics, Inc. ("Confidential Information"). You
 * shall not disclose such Confidential Information and shall use
 * it only in accordance with the terms of the license agreement
 * you entered into with Samsung.
 */


#ifndef _PROGRAMSUBSCRIBERDATATYPE_H_
#define _PROGRAMSUBSCRIBERDATATYPE_H_

#include <string>
#include <vector>

#include "Marshalable.h"
#include "ServiceData.h"
#include "ServiceGuideDataType.h"
#include "ProgramData.h"


typedef enum
{
	SUBSCRIBE_CACHE,
	SUBSCRIBE_STREAM,
	SUBSCRIBE_CACHE_OR_STREAM,
	SUBSCRIBE_STREAM_MONITORING,
	SUBSCRIBE_INVALID,
}ESubscribeType;

typedef enum
{
	PROGRAM_CHANGE_STARTED,
	PROGRAM_CHANGE_STOPPED,
	PROGRAM_CHANGE_DATA_CHANGE,
	PROGRAM_CHANGE_NEW_FOUND,
	PROGRAM_CHANGE_NEW_SERIES_FOUND,
	PROGRAM_CHANGE_SUBSCRIBE_LIST,
	PROGRAM_CHANGE_EPG_RAW_DATA,
} EProgramChangeType;

typedef enum
{
	TYPE_SERIES,
	TYPE_PROGRAM,
} EProgramFilteringType;

// The raw data subscription return reason.
enum EEpgRawState
{
	// Initial state
	EPG_RAW_STATE_NEW = 0x00,
	// A timeout indicates that some or all of the sections required by the subscription were not found.
	EPG_RAW_STATE_TIMEOUT = 0x01,
	// A new or changed section has become available.
	EPG_RAW_STATE_AVAIL = 0x02,
	// All of the sections have been acquired, any timeout will be cancelled.
	EPG_RAW_STATE_COMPLETE = 0x04,
	// The call-back is made directly from the subscription. When this flag is clear then the call is made from the EPG task context.
	EPG_RAW_STATE_INLINE = 0x08,
	// stream monitoring (if set, then monitor for new versions) 
	EPG_RAW_STATE_MONITOR = 0x10,
};

class TCProgramFilteringItem : public TCMarshalable
{
private:
	enum 
	{
		TAG_TYPE,
		TAG_CRID,
		TAG_PROGRAM_MONITOR_ID,
		TAG_ALWAYS_NOTICE
	};

public :
	TCProgramFilteringItem(EProgramFilteringType type = TYPE_SERIES);

	/**
	 * @brief Sets value for series
	 * @param [in] crid CRID
	 * @return result of method call (0 == success)
	 */
	void SetSeries(const std::string& crid);
	
	/**
	 * @brief Sets value for program
	 * @param [in] programId program ID
	 * @return result of method call (0 == success)
	 */
	void SetProgramMonitorId(const TCProgramMonitorId& in_program_monitor_id);
	

	/**
	 * @brief Sets value for program
	 * @param [in] always notice flag
	 * @return result of method call (0 == success)
	 */
	void SetAlwaysNotice(bool in_always_notice);
	
	/**
	 * @brief Returns value of event id
	 * @return event id
	 */
	const EProgramFilteringType GetFilteringType(void) const { return m_filteringType; }
	
	/**
	 * @brief Returns value of CRID
	 * @return CRID
	 */
	const std::string& GetCRID(void) const { return m_crid; }
	
	/**
	 * @brief Returns value of program ID
	 * @return program ID
	 */
	const TCProgramMonitorId& GetProgramMonitorId(void) const { return m_program_monitor_id; }


	/**
	 * @brief Returns always notice flag
	 * @return always notice flag
	 */
	bool GetAlwaysNotice(void) const { return m_always_notice; }

	
	/**
	 * @brief Extract Tree from Class
	 * @param [inout] treeParent branch to which object data should be added
	 * @return true if success
	 */
	virtual bool ClassToTree(TCTreeBranch& treeParent);

	/**
	 * @brief Fill out Class from Tree
	 * @param [inout] treeMine branch from which object data should be fetched
	 * @return true if success
	 */
	virtual bool TreeToClass(TCTreeBranch& treeMine);
	
private: 
	EProgramFilteringType m_filteringType;
	std::string m_crid;
	TCProgramMonitorId m_program_monitor_id;
	bool m_always_notice;

};



#endif // _PROGRAMSUBSCRIBERDATATYPE_H_
