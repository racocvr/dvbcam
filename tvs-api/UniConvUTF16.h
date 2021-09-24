/** 
 * @file	UniConvUTF16.h
 * @brief	Unicode conversion helper classes for UTF16.
 *
 * Copyright 2013 by Samsung Electronics, Inc.,
 * 
 * This software is the confidential and proprietary information
 * of Samsung Electronics, Inc. ("Confidential Information").  You
 * shall not disclose such Confidential Information and shall use
 * it only in accordance with the terms of the license agreement
 * you entered into with Samsung.
 */

#ifndef _UNICONVUTF16_H_
#define _UNICONVUTF16_H_

#include "UniConv.h"

class TCUniConvUTF16 : public TCUniConv
{
public:
	TCUniConvUTF16() {}
	virtual ~TCUniConvUTF16() {}
	
protected:
	/* see base class */
	virtual bool t_Convert(
		const unsigned char* srcData, 
		const unsigned short& srcSize, 
		unsigned char* convertedData, 
		unsigned short& convertedLength, 
		const bool extendedType, 
		const bool short_name, 
		const bool ignore_control_chars);
};

#endif

