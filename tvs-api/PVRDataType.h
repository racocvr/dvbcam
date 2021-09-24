/** 
 * @file PVRDataType.h
 * @brief PVR related data types.
 *
 * Copyright 2013 by Samsung Electronics, Inc.,
 * 
 * This software is the confidential and proprietary information
 * of Samsung Electronics, Inc. ("Confidential Information"). You
 * shall not disclose such Confidential Information and shall use
 * it only in accordance with the terms of the license agreement
 * you entered into with Samsung.
 */


#ifndef _PVRDATATYPE_H_
#define _PVRDATATYPE_H_

enum ERecordType //Window.h
{
	RECORD_TYPE_UNKNOWN,	// Initial value
	RECORD_TYPE_DIRECT,	// Instant Record
	RECORD_TYPE_RESERVED,	// Reserved Record
	RECORD_TYPE_TIMESHIFT,	// TimeShift
	RECORD_TYPE_COMPOSITE,	// Composite Record	
};

enum EPlayType //Window.h
{
	PLAY_TYPE_UNKNOWN, 
	PLAY_TYPE_DTV, 
	PLAY_TYPE_ATV,
	PLAY_TYPE_COMPOSITE,
};

/**
 * \note
 * It is not marshallable type.
 * It has been requested to make it in that way in sake of 'easy adding a new field'.
 */
struct TSPlaybackData
{
  public:
    bool pastPlayback;
	EPlayType playType;

  public:
    TSPlaybackData() : pastPlayback(false), playType(PLAY_TYPE_UNKNOWN) {};
};


#endif // _PVRDATATYPE_H_

