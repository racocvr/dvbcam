/** 
 * @file	UniConvGB13000.h
 * @brief	Unicode conversion helper classes for GB13000.
 *
 * Copyright 2013 by Samsung Electronics, Inc.,
 * 
 * This software is the confidential and proprietary information
 * of Samsung Electronics, Inc. ("Confidential Information").  You
 * shall not disclose such Confidential Information and shall use
 * it only in accordance with the terms of the license agreement
 * you entered into with Samsung.
 */

#ifndef _UNICONVGB13000_H_
#define _UNICONVGB13000_H_

#include "UniConv.h"

class TCUniConvGB13000 : public TCUniConv
{
private :
	/* GB13000 에서 Table 을 선택하기 위한 Second Byte */
	enum EGb13000Table
	{
		SECONDBYTE_UNICODE	= 0x01,
		SECONDBYTE_TIBET	= 0x02,
		SECONDBYTE_UIGUR	= 0x03,
		SECONDBYTE_KOREAN	= 0x04,
		SECONDBYTE_MONGOLIA	= 0x05,
	};

public:
	TCUniConvGB13000() {}
	virtual ~TCUniConvGB13000() {}
	
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

