/** 
 * @file	UnicodeConverterPHI.h
 * @brief	Handles Philippines unicode conversion
 *
 * Copyright 2015 by Samsung Electronics, Inc.,
 * 
 * This software is the confidential and proprietary information
 * of Samsung Electronics, Inc. ("Confidential Information").  You
 * shall not disclose such Confidential Information and shall use
 * it only in accordance with the terms of the license agreement
 * you entered into with Samsung.
 */

#ifndef _IUNICODECONVERTERPHI_H_
#define _IUNICODECONVERTERPHI_H_

#include "SOSpecDataType.h"

#include "IUnicodeConverter.h"
#include "UniConvUTF8.h"

class TCUnicodeConverterPHI : public IUnicodeConverter
{
public:
	TCUnicodeConverterPHI(){}
	virtual ~TCUnicodeConverterPHI(){}

	virtual bool ConvertToUnicode(unsigned char* pSrcData, unsigned short &srcSize, unsigned char* pDstData, unsigned short &dstSize, bool shortName, ELanguageCode langCode = LANGUAGE_CODE_UNKNOWN);

	virtual bool ConvertToFullWidth(unsigned char* pSrcData, unsigned short &srcSize, unsigned char* pDstData, unsigned short &dstSize){ return false; }

	virtual bool ConvertToUnicodeWithoutControlCode(unsigned char* pSrc, unsigned short srcLen, unsigned short* pDest, unsigned short &destLen, int type){ return false; }
};

#endif
