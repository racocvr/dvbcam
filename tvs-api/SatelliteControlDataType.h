/** 
 * @file SatelliteControlDataType.h
 * @brief Definitions related to satellite control.
 *
 * Copyright 2013 by Samsung Electronics, Inc.,
 * 
 * This software is the confidential and proprietary information
 * of Samsung Electronics, Inc. ("Confidential Information"). You
 * shall not disclose such Confidential Information and shall use
 * it only in accordance with the terms of the license agreement
 * you entered into with Samsung.
 */

#ifndef _SATELLITECONTROLDATATYPE_H_
#define _SATELLITECONTROLDATATYPE_H_


typedef enum
{
	POSITIONER_HALT,		// [no param required] stop positioner
	POSITIONER_LIMITSOFF,	// [no param required] disable positioner west/east limits
	POSITIONER_LIMITE,		// [no param required] set positioner east limit - current positioner position will be set as the limit
	POSITIONER_LIMITW,		// [no param required] set positioner west limit - current positioner position will be set as the limit
	POSITIONER_DRIVEE,		// [param = number of steps or 0] move positioner east; if param = 0 - it will be continuous move
	POSITIONER_DRIVEW,		// [param = number of steps or 0] move positioner west; if param = 0 - it will be continuous move
	POSITIONER_STORENN,		// [param = slot id] store current position; position shall be stored in specified slot and that slot id should be assigned to currently adjusted satellite
	POSITIONER_GOTONN,		// [param = slot id] go to stored position; positioner will move to position specified by slot id, acquired from satellite settings
	POSITIONER_DIRECT,		// [param = position] move positioner to specified position (e.g. calculated by USALS)
}EPositionerCommand;

typedef enum
{
	POS_MOVE_CONTINUOUS,	// Continuous move mode.
	POS_MOVE_STEP,			// Step move mode - required specifying number of steps
}EPositionerMoveMode;


typedef enum
{
	SATCR_DETECT_SLOT_FREQUENCY,
	SATCR_VERIFY_SLOT_FREQUENCY,
	SATCR_STOP_SLOT_FREQUENCY_ACTION,
}ESatCRCommand;


typedef enum
{
	SATCR_MIN_SLOT_NUMBER = 1,
	SATCR_MAX_SLOT_NUMBER = 8,

	SATCR_MIN_SLOT_FREQUENCY = 950000, 	 // [kHz]
	SATCR_MAX_SLOT_FREQUENCY = 2150000,	 // [kHz]

	SATCR_PREDEFINED_SLOT_FREQ_1 = 1210000,  // [kHz]
	SATCR_PREDEFINED_SLOT_FREQ_2 = 1420000,  // [kHz]
	SATCR_PREDEFINED_SLOT_FREQ_3 = 1680000,  // [kHz]
	SATCR_PREDEFINED_SLOT_FREQ_4 = 2040000,  // [kHz]
}ESatCRConfiguration;


#endif // _SATELLITECONTROLDATATYPE_H_

