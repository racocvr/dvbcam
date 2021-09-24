/** 
 * @file	UniConvUTF8.h
 * @brief	Unicode conversion helper classes for UTF8.
 *
 * Copyright 2013 by Samsung Electronics, Inc.,
 * 
 * This software is the confidential and proprietary information
 * of Samsung Electronics, Inc. ("Confidential Information").  You
 * shall not disclose such Confidential Information and shall use
 * it only in accordance with the terms of the license agreement
 * you entered into with Samsung.
 */

#ifndef _UNICONVUTF8_H_
#define _UNICONVUTF8_H_

#include "UniConv.h"

class TCUniConvUTF8 : public TCUniConv
{
public:
	TCUniConvUTF8() {}
	virtual ~TCUniConvUTF8() {}

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

private :
	bool m_UTF8Decode(unsigned char *pDest, unsigned short* pDestLen, const unsigned char *pSrc, unsigned short len);

	enum EUtf8
	{
		UTF8_1BYTE_HEADER_MASK = 0x80,
		UTF8_2BYTE_HEADER_MASK = 0xE0,
		UTF8_3BYTE_HEADER_MASK = 0xF0,
		UTF8_4BYTE_HEADER_MASK = 0xF8,
		UTF8_1BYTE_HEADER_CODE = 0x00,
		UTF8_2BYTE_HEADER_CODE = 0xC0,
		UTF8_3BYTE_HEADER_CODE = 0xE0,
		UTF8_4BYTE_HEADER_CODE = 0xF0,
		UTF8_NEXT_BYTE_MASK = 0xC0,
		UTF8_NEXT_BYTE_CODE = 0x80,
	};
};

#endif

