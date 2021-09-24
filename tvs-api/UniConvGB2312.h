/** 
 * @file	UniConvGB2312.h
 * @brief	Unicode conversion helper classes for GB2312.
 *
 * Copyright 2013 by Samsung Electronics, Inc.,
 * 
 * This software is the confidential and proprietary information
 * of Samsung Electronics, Inc. ("Confidential Information").  You
 * shall not disclose such Confidential Information and shall use
 * it only in accordance with the terms of the license agreement
 * you entered into with Samsung.
 */

#ifndef _UNICONVGB2312_H_
#define _UNICONVGB2312_H_

#include "UniConv.h"

class TCUniConvGB2312 : public TCUniConv
{
private :
	/* GB2312 Table 영역 지정 */
	enum EGb2312Table
	{
		ASCII_START_INDEX			= 0x00,
		ASCII_END_INDEX 			= 0x7F,

		GB2312_SYMBOLIC_START_INDEX = 0xA1A1,
		GB2312_SYMBOLIC_END_INDEX	= 0xA9FE,

		GB2312_HANCHAR_START_INDEX	= 0xB0A1,
		GB2312_HANCHAR_END_INDEX	= 0xF7FE,
	};

public:
	TCUniConvGB2312() {}
	virtual ~TCUniConvGB2312() {}
	
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

