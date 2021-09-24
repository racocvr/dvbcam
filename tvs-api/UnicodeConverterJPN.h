/** 
 * @file	UnicodeConverterJPN.h
 * @brief	Handles Japan unicode conversion
 *
 * Copyright 2013 by Samsung Electronics, Inc.,
 * 
 * This software is the confidential and proprietary information
 * of Samsung Electronics, Inc. ("Confidential Information").  You
 * shall not disclose such Confidential Information and shall use
 * it only in accordance with the terms of the license agreement
 * you entered into with Samsung.
 */

#ifndef _IUNICODECONVERTERJPN_H_
#define _IUNICODECONVERTERJPN_H_

#include "SOSpecDataType.h"

#include "IUnicodeConverter.h"
#include "UniConvJPN.h"

class TCUnicodeConverterJPN :  public IUnicodeConverter
{
public :
	TCUnicodeConverterJPN();

	virtual ~TCUnicodeConverterJPN();

	virtual bool ConvertToUnicode(unsigned char* pSrcData, unsigned short &srcSize, unsigned char* pDstData, unsigned short &dstSize, bool shortName, ELanguageCode langCode = LANGUAGE_CODE_UNKNOWN);

	virtual bool ConvertToFullWidth(unsigned char* pSrcData, unsigned short &srcSize, unsigned char* pDstData, unsigned short &dstSize);

	virtual bool ConvertToUnicodeWithoutControlCode(unsigned char* pSrc, unsigned short srcLen, unsigned short* pDest, unsigned short &destLen, int type);
};


#endif
