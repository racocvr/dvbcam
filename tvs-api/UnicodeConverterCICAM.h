/** 
 * @file	UnicodeConverterCICAM.h
 * @brief	Handles unicode conversion concerning CI CAM
 *
 * Copyright 2013 by Samsung Electronics, Inc.,
 * 
 * This software is the confidential and proprietary information
 * of Samsung Electronics, Inc. ("Confidential Information").  You
 * shall not disclose such Confidential Information and shall use
 * it only in accordance with the terms of the license agreement
 * you entered into with Samsung.
 */

#ifndef _IUNICODECONVERTERCICAM_H_
#define _IUNICODECONVERTERCICAM_H_

#include "SOSpecDataType.h"

#include "UnicodeConverterDVB.h"

class TCUnicodeConverterCICAM :  public TCUnicodeConverterDVB
{
private:
	std::vector<unsigned char> m_encoding;

public :
	TCUnicodeConverterCICAM(const TVSHandle& tvsHandle);

	virtual ~TCUnicodeConverterCICAM();

	virtual bool ConvertToUnicode(unsigned char* pSrcData, unsigned short &srcSize, unsigned char* pDstData, unsigned short &dstSize, bool shortName, ELanguageCode langCode = LANGUAGE_CODE_UNKNOWN);

	virtual bool ConvertToFullWidth(unsigned char* pSrcData, unsigned short &srcSize, unsigned char* pDstData, unsigned short &dstSize) {return false;}

	virtual bool ConvertToUnicodeWithoutControlCode(unsigned char* pSrc, unsigned short srcLen, unsigned short* pDest, unsigned short &destLen, int type) {return false;}
};

#endif
