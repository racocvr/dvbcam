/** 
 * @file UtilDataType.h
 * @brief Enums for TCUtil class
 *
 * Copyright 2013 by Samsung Electronics, Inc.,
 * 
 * This software is the confidential and proprietary information
 * of Samsung Electronics, Inc. ("Confidential Information"). You
 * shall not disclose such Confidential Information and shall use
 * it only in accordance with the terms of the license agreement
 * you entered into with Samsung.
 */


#ifndef _UTILDATATYPE_H_
#define _UTILDATATYPE_H_


typedef enum
{
	DST_TYPE_OFF = 0,
	DST_TYPE_ON,
	DST_TYPE_AUTO,
}EDSTType;

typedef enum
{
	TIMEZONE_OFFSET_TYPE_AUTO,
	TIMEZONE_OFFSET_TYPE_MANUAL,
}ETimezoneOffsetType;

// The baseline is 'TIME_OFFSET_GMT_0' . all of the value except 'TIME_OFFSET_GMT_AUTO' is the relative value of 'TIME_OFFSET_GMT_0' 
typedef enum
{
	TIME_OFFSET_GMT_AUTO = 0xFF,
	TIME_OFFSET_GMT_MINUS_12 = -12,
	TIME_OFFSET_GMT_MINUS_11 = -11,
	TIME_OFFSET_GMT_MINUS_10 = -10,
	TIME_OFFSET_GMT_MINUS_9 = -9,
	TIME_OFFSET_GMT_MINUS_8 = -8,
	TIME_OFFSET_GMT_MINUS_7 = -7,
	TIME_OFFSET_GMT_MINUS_6 = -6,
	TIME_OFFSET_GMT_MINUS_5 = -5,
	TIME_OFFSET_GMT_MINUS_4 = -4,
	TIME_OFFSET_GMT_MINUS_3 = -3,
	TIME_OFFSET_GMT_MINUS_2 = -2,
	TIME_OFFSET_GMT_MINUS_1 = -1,
	TIME_OFFSET_GMT_0 = 0,
	TIME_OFFSET_GMT_1,	
	TIME_OFFSET_GMT_2,
	TIME_OFFSET_GMT_3,
	TIME_OFFSET_GMT_4,	
	TIME_OFFSET_GMT_5,	
	TIME_OFFSET_GMT_6,	
	TIME_OFFSET_GMT_7,	
	TIME_OFFSET_GMT_8,	
	TIME_OFFSET_GMT_9,	
	TIME_OFFSET_GMT_10,	
	TIME_OFFSET_GMT_11,	
	TIME_OFFSET_GMT_12,	
	TIME_OFFSET_GMT_13,	
}EManualTimeOffset;

typedef enum
{
	//DVB
	TIMEZONE_REGION_0 = 0,		//!< Time Zone Offset (Region 0) - Time Zone    .
	TIMEZONE_REGION_1 = 1,		//!< Time Zone Offset (Region 1) - ȣ : reserved ,  :
	TIMEZONE_REGION_2 = 2,		//!< Time Zone Offset (Region 2) - ȣ : New Southwales/ACT ,  :
	TIMEZONE_REGION_3 = 3,		//!< Time Zone Offset (Region 3) - ȣ : Victoria
	TIMEZONE_REGION_4 = 4,		//!< Time Zone Offset (Region 4) - ȣ : Queensland
	TIMEZONE_REGION_5 = 5,		//!< Time Zone Offset (Region 5) - ȣ : South Australia
	TIMEZONE_REGION_6 = 6,		//!< Time Zone Offset (Region 6) - ȣ : Western Australia
	TIMEZONE_REGION_7 = 7,		//!< Time Zone Offset (Region 7) - ȣ : Tasmania
	TIMEZONE_REGION_8 = 8,		//!< Time Zone Offset (Region 8) - ȣ : Northern Territory

			// ATSC USA
	TIMEZONE_NEWFOUNDLAND = TIMEZONE_REGION_0,
	TIMEZONE_ATLANTIC = TIMEZONE_REGION_1,
	TIMEZONE_EASTERN = TIMEZONE_REGION_2,
	TIMEZONE_CENTRAL = TIMEZONE_REGION_3,
	TIMEZONE_MOUNTAIN = TIMEZONE_REGION_4,
	TIMEZONE_PACIFIC = TIMEZONE_REGION_5,
	TIMEZONE_ALASKA = TIMEZONE_REGION_6,
	TIMEZONE_HAWAII = TIMEZONE_REGION_7,
	// ATSC KOR
	TIMEZONE_SEOUL = TIMEZONE_REGION_8,

	TIMEZONE_MAX,
}ETimeZone;


typedef enum
{
	AUTO_TYPE_BROADCAST_STREAM = 0,
	AUTO_TYPE_INTERNET,
	AUTO_TYPE_MAX,
} ETypeOfAutoClock;


typedef enum
{
	SYSTEM_TIME_REASON_INIT = 0,
	SYSTEM_TIME_REASON_MICOM,
	SYSTEM_TIME_REASON_NETWORK,
	SYSTEM_TIME_REASON_BROADCAST,
} ESystemTimeReason;

#endif // _UTILDATATYPE_H_

