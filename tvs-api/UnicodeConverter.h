/** 
 * @file UnicodeConverter.h
 * @brief Class intended for converting unicode text.
 *
 * Copyright 2013 by Samsung Electronics, Inc.,
 * 
 * This software is the confidential and proprietary information
 * of Samsung Electronics, Inc. ("Confidential Information"). You
 * shall not disclose such Confidential Information and shall use
 * it only in accordance with the terms of the license agreement
 * you entered into with Samsung.
 */

#include "TVServiceDataType.h"
#include "SOSpecDataType.h"

class IUnicodeConverter;

#ifndef _UNICODECONVERTER_H_
#define _UNICODECONVERTER_H_

#define LANGUAGE_CODE_MIN_TEXT 12

class TCUnicodeConverter
{
private:
	IUnicodeConverter* m_pImp;
public:
	TCUnicodeConverter(const TVSHandle &tvsHandle);
	~TCUnicodeConverter();

	/*
	 * @brief Converts encoded string to unicode.
	 * @remark pDstData has to be pre-allocated.
	 * @remark If there is not enough space in pDstData method will still return true and re-set the dstSize to smaller value.
	 * @param [in] pSrcData Buffer with the encoded string.
	 * @param [in] srcSize Size of source buffer.
	 * @param [out] pDstData Buffer with unicode string.
	 * @param [inout] dstSize Size of output buffer. After successfull conversion will carry 
	 * byte length of string put into pDstData (at most original dstSize)
	 * @param [in] shortName Defines if input string represent channel short name.
	 * @param [in] langCode Language of current channel.
	 * @return True Returns true when convertion succeeded.
	 */
	bool ConvertToUnicode(unsigned char* pSrcData, unsigned short &srcSize, unsigned char* pDstData, unsigned short &dstSize, bool shortName = false, ELanguageCode langCode = LANGUAGE_CODE_UNKNOWN);
	
	/*
	 * @brief Converts encoded string to unicode.
	 * @param [in] pSrcData Buffer with the encoded string.
	 * @param [in] srcSize Size of source buffer.
	 * @param [out] dstString t_wstring object were unicode string should be written to
	 * @param [in] shortName Defines if input string represent channel short name.
	 * @param [in] langCode Language of current channel.
	 * @return True Returns true when convertion succeeded.
	 */
	bool ConvertToUnicode(unsigned char* pSrcData, unsigned short &srcSize, t_wstring& dstString, bool shortName = false, ELanguageCode langCode = LANGUAGE_CODE_UNKNOWN);

	//JPN only - no idea what it does
	bool ConvertToFullWidth(unsigned char* pSrcData, unsigned short &srcSize, unsigned char* pDstData, unsigned short &dstSize);
	bool ConvertToFullWidth(unsigned char* pSrcData, unsigned short &srcSize, t_wstring& dstString);

	//JPN only (seems dead code - consider removing)
	bool ConvertToUnicodeWithoutControlCode(unsigned char* pSrc, unsigned short srcLen, unsigned short* pDest, unsigned short &destLen, int type);
	bool ConvertToUnicodeWithoutControlCode(unsigned char* pSrc, unsigned short srcLen, t_wstring& dstString, int type);
	
	/**
	 * @brief Converts language code identifier to ASCII representation.
	 * @remark pTextLanguageCode has to be pre-allocated with at least LANGUAGE_CODE_MIN_TEXT bytes.
	 * @remark The last char in pTextLanguageCode will be \0.
	 * @param [in] languageCode Language code identifier to be converted.
	 * @param [out] pTextLanguageCode Converted ASCII representation of Language code identifier.
	 * @param [in] textSize Size of preallocated array
	 */
	static void ConvertLanguageCodeToText(ELanguageCode languageCode, char* pTextLanguageCode, int textSize = LANGUAGE_CODE_MIN_TEXT);

	/**
	 * @brief Converts ASCII language code text to language code identifier.
	 * @remark The last char in pTextLanguageCode should be \0.
	 * @param [in] pTextLanguageCode ASCII Language code to be converted.
	 * @param [out] languageCode Converted language code identifier.
	 */
	static void ConvertTextToLanguageCode(char* pTextLanguageCode, ELanguageCode &languageCode);

};

#endif
