/** 
 * @file ConfigAppTag.h
 * @brief ConfigApp data tags.
 *
 * Copyright 2015 by Samsung Electronics, Inc.,
 * 
 * This software is the confidential and proprietary information
 * of Samsung Electronics, Inc. ("Confidential Information"). You
 * shall not disclose such Confidential Information and shall use
 * it only in accordance with the terms of the license agreement
 * you entered into with Samsung.
 */

#ifndef _CONFIGAPPTAG_H_
#define _CONFIGAPPTAG_H_

typedef enum {
	CONF_TAG_MIN_AIR_CH_NUMBER,		// [unsigned short] Minimum channel number for AIR analog services
	CONF_TAG_MAX_AIR_CH_NUMBER,		// [unsigned short] Maximum channel number for AIR analog services
	CONF_TAG_MIN_CABLE_CH_NUMBER,	// [unsigned short] Minimum channel number for CABLE analog services
	CONF_TAG_MAX_CABLE_CH_NUMBER,	// [unsigned short] Maximum channel number for CABLE analog services
} EConfigAppTag;

#endif //_CONFIGAPPTAG_H_