/** 
 * @file MutliScreenDataType.h
 * @brief Enums for IMultiScreen interface.
 *
 * Copyright 2013 by Samsung Electronics, Inc.,
 * 
 * This software is the confidential and proprietary information
 * of Samsung Electronics, Inc. ("Confidential Information"). You
 * shall not disclose such Confidential Information and shall use
 * it only in accordance with the terms of the license agreement
 * you entered into with Samsung.
 */

#ifndef _MULTISCREENDATATYPE_H_
#define _MULTISCREENDATATYPE_H_

typedef enum
{
	MULTI_SCREEN_MODE_LEFT_ONLY,		// Left screen only.
	MULTI_SCREEN_MODE_RIGHT_ONLY,		// Right screen only.
	MULTI_SCREEN_MODE_LEFT_RIGHT,		// Both left and right.
} EMultiScreenMode;

#endif // _MULTISCREENDATATYPE_H_