/** 
 * @file	UnicodeConverterBRZ.h
 * @brief	Handles Brazil unicode conversion
 *
 * Copyright 2013 by Samsung Electronics, Inc.,
 * 
 * This software is the confidential and proprietary information
 * of Samsung Electronics, Inc. ("Confidential Information").  You
 * shall not disclose such Confidential Information and shall use
 * it only in accordance with the terms of the license agreement
 * you entered into with Samsung.
 */

#ifndef _IUNICODECONVERTERBRZ_H_
#define _IUNICODECONVERTERBRZ_H_

#include "SOSpecDataType.h"

#include "IUnicodeConverter.h"
#include "UniConvBRZ.h"

class TCUnicodeConverterBRZ :  public IUnicodeConverter
{
public : 
	TCUnicodeConverterBRZ();
	virtual ~TCUnicodeConverterBRZ();

	virtual bool ConvertToUnicode(unsigned char* pSrcData, unsigned short &srcSize, unsigned char* pDstData, unsigned short &dstSize, bool shortName, ELanguageCode langCode = LANGUAGE_CODE_UNKNOWN);

	virtual bool ConvertToFullWidth(unsigned char* pSrcData, unsigned short &srcSize, unsigned char* pDstData, unsigned short &dstSize) {return false;}

	virtual bool ConvertToUnicodeWithoutControlCode(unsigned char* pSrc, unsigned short srcLen, unsigned short* pDest, unsigned short &destLen, int type) {return false;}
};

#endif


