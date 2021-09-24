/** 
 * @file EWBSDataType.h
 * @brief Early Warning Broadcast System related types.
 *
 * Copyright 2015 by Samsung Electronics, Inc.,
 * 
 * This software is the confidential and proprietary information
 * of Samsung Electronics, Inc. ("Confidential Information"). You
 * shall not disclose such Confidential Information and shall use
 * it only in accordance with the terms of the license agreement
 * you entered into with Samsung.
 */

#ifndef _EWBSDATATYPE_H_
#define _EWBSDATATYPE_H_


enum EDisasterStatus
{
	DISASTER_STATUS_CAUTION		= 0x01,
	DISASTER_STATUS_ALERT		= 0x02,
	DISASTER_STATUS_WARNING		= 0x03,
};

enum EDisasterCode
{
	DISASTER_CODE_EARTHQUAKE			= 0x01,	// Earthquake
	DISASTER_CODE_TSUNAMI				= 0x02,	// Tsunami
	DISASTER_CODE_VULCANIC_ERUPTION		= 0x03,	// Vulcanic Eruption
	DISASTER_CODE_SHAKING_GROUND		= 0x04,	// Shaking Ground
	DISASTER_CODE_FLOODING				= 0x05,	// Flooding
	DISASTER_CODE_DROUGHT				= 0x06,	// Drought
	DISASTER_CODE_FOREST_FIRE			= 0x07,	// Land and Forest Fire
	DISASTER_CODE_EROSION				= 0x08,	// Erosion
	DISASTER_CODE_BUILDING_FIRE			= 0x09,	// Building and Residential Fire
	DISASTER_CODE_EXTREME_WAVES			= 0x0A,	// Extreme Waves and Abrasion
	DISASTER_CODE_EXTREME_WEATHER		= 0x0B,	// Extreme Weather
	DISASTER_CODE_TECHNOLOGY_FAILURE	= 0x0C,	// Technology Failure
	DISASTER_CODE_EPIDEMIC				= 0x0D,	// Technology Failure
	DISASTER_CODE_SOCIAL_CONFLICT		= 0x0E,	// Social Conflict
	DISASTER_CODE_RESERVED				= 0xFF,	// Reserved
};

enum EDisasterAuthority
{
	DISASTER_AUTHORITY_BMKG	= 0x01,	// Meteorology, Climatology and Geophysics Bureau
	DISASTER_AUTHORITY_BNPB	= 0x02,	// National Disaster Management Agency
};


#endif //_EWBSDATATYPE_H_
