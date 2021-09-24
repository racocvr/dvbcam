/** 
 * @file	IUnicodeConverter.h
 * @brief	Interface which handles unicode conversion
 *
 * Copyright 2013 by Samsung Electronics, Inc.,
 * 
 * This software is the confidential and proprietary information
 * of Samsung Electronics, Inc. ("Confidential Information").  You
 * shall not disclose such Confidential Information and shall use
 * it only in accordance with the terms of the license agreement
 * you entered into with Samsung.
 */

#ifndef _IUNICODECONVERTER_H_
#define _IUNICODECONVERTER_H_

#include <vector>

#include "TVServiceDataType.h"
#include "SOSpecDataType.h"

class IUnicodeConverter
{
protected:
	IUnicodeConverter() {};

public:
	
	virtual ~IUnicodeConverter() {};
	
	/*
	 * @brief Converts encoded string to unicode.
	 * @param [in] pSrcData Buffer with the encoded string.
	 * @param [in] srcSize Size of source buffer.
	 * @param [out] pDstData Buffer with unicode string.
	 * @param [out] dstSize Size of output buffer.
	 * @param [in] shortName Defines if input string represent channel short name.
	 * @param [in] langCode Language of current channel.
	 * @return True Returns true when convertion succeeded.
	 */
	virtual bool ConvertToUnicode(unsigned char* pSrcData, unsigned short &srcSize, unsigned char* pDstData, unsigned short &dstSize, bool shortName = false, ELanguageCode langCode = LANGUAGE_CODE_UNKNOWN) = 0;

	virtual bool ConvertToFullWidth(unsigned char* pSrcData, unsigned short &srcSize, unsigned char* pDstData, unsigned short &dstSize) = 0;

	virtual bool ConvertToUnicodeWithoutControlCode(unsigned char* pSrc, unsigned short srcLen, unsigned short* pDest, unsigned short &destLen, int type) = 0;
};

#endif
