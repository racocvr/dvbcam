/** 
 * @file	UniConvBRZ.h
 * @brief	Unicode conversion helper classes for Brazil.
 *
 * Copyright 2013 by Samsung Electronics, Inc.,
 * 
 * This software is the confidential and proprietary information
 * of Samsung Electronics, Inc. ("Confidential Information").  You
 * shall not disclose such Confidential Information and shall use
 * it only in accordance with the terms of the license agreement
 * you entered into with Samsung.
 */

#ifndef _UNICONVBRZ_H_
#define _UNICONVBRZ_H_

class TCUniConvBrazil
{
private :
	/* Brazil Character Table 영역 지정 */
	enum EBrazilCharTable
	{
		ASCII_START_INDEX			= 0x00,
		ASCII_END_INDEX				= 0x7F,

		LATIN_EXTENSION_START_INDEX	= 0x80,
		LATIN_EXTENSION_END_INDEX	= 0xFF,
	};

public :
	bool Convert(unsigned char* srcData, unsigned short* srcSize, unsigned char* dstData, unsigned short* dstSize, bool short_name = false, bool ignore_control_chars = false);
};

#endif
