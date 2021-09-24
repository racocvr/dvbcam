/**
 * @file	UnicodeConverterSatellitePL.h
 * @brief	Unicode converter class for Polish satellite services.
 *
 * Copyright 2013 by Samsung Electronics, Inc.,
 * 
 * This software is the confidential and proprietary information
 * of Samsung Electronics, Inc. ("Confidential Information").  You
 * shall not disclose such Confidential Information and shall use
 * it only in accordance with the terms of the license agreement
 * you entered into with Samsung.
 */

#ifndef _UNICODECONVERTERSATELLITEPL_H_
#define _UNICODECONVERTERSATELLITEPL_H_

#include "UnicodeConverterDVB.h"

class TCUnicodeConverterSatellitePL :  public TCUnicodeConverterDVB
{
public :
	
	TCUnicodeConverterSatellitePL(const TVSHandle &tvsHandle) : TCUnicodeConverterDVB(tvsHandle) {}

	virtual ~TCUnicodeConverterSatellitePL(void) {}

	/*
	 * @brief Converts encoded string to unicode
	 * @param [in] source buffer (encoded string)
	 * @param [in] size of source buffer
	 * @param [out] output buffer (decoded to unicode string)
	 * @param [out] size of output buffer
	 * @param [in] language of current channel
	 * @returns True if conversion was successful
	 */
	virtual bool ConvertToUnicode(unsigned char* pSrcData, unsigned short &srcSize, unsigned char* pDstData, unsigned short &dstSize, bool shortName, ELanguageCode langCode = LANGUAGE_CODE_UNKNOWN);
};

#endif

