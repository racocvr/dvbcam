/** 
 * @file ResolutionUtility.h
 * @brief Utility methods related to service data.
 *
 * Copyright 2013 by Samsung Electronics, Inc.,
 * 
 * This software is the confidential and proprietary information
 * of Samsung Electronics, Inc. ("Confidential Information"). You
 * shall not disclose such Confidential Information and shall use
 * it only in accordance with the terms of the license agreement
 * you entered into with Samsung.
 */


#ifndef _RESOLUTIONUTILITY_H_
#define _RESOLUTIONUTILITY_H_

#include "AVControlDataType.h"

typedef enum
{
	DEFINITION_INFO_UNKNOWN = -1,
	DEFINITION_INFO_HD,
	DEFINITION_INFO_SD,
	DEFINITION_INFO_UHD,
} EDefinitionInfo;


class TCResolutionUtility
{
public:
	static EDefinitionInfo GetDefinitionInfo(EResolution inputResolutionEnum);
};



#endif // _RESOLUTIONUTILITY_H_
