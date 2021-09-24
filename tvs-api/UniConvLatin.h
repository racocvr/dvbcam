/** 
 * @file	UniConvLatin.h
 * @brief	Unicode conversion helper classes for Latin alphabet.
 *
 * Copyright 2013 by Samsung Electronics, Inc.,
 * 
 * This software is the confidential and proprietary information
 * of Samsung Electronics, Inc. ("Confidential Information").  You
 * shall not disclose such Confidential Information and shall use
 * it only in accordance with the terms of the license agreement
 * you entered into with Samsung.
 */

#ifndef _UNICONVLATIN_H_
#define _UNICONVLATIN_H_

#include "UniConv.h"

class TCUniConvLatin : public TCUniConv
{
public :
	TCUniConvLatin() {}
	virtual ~TCUniConvLatin() {}
	
	enum  ELatinMaxLength
	{
		MAX_LATIN_CHARACTER = 128
	};
	
	/* Accent Merge를 위한 상수 */
	enum EMergeTable
	{
		MERGE_TABLE_ROWS 	= 39,
		MERGE_TABLE_COLUMNS = 17,
	};
	
private:
	/* Table 을 선택하기 위한 First Byte */
	enum EFirstbyteLatin
	{
		FIRSTBYTE_LATIN_ALPHABET	= 0x00,
		FIRSTBYTE_LATIN_CYRILLIC	= 0x01,
		FIRSTBYTE_LATIN_ARABIC		= 0x02,
		FIRSTBYTE_LATIN_GREEK		= 0x03,
		FIRSTBYTE_LATIN_HEBREW		= 0x04,
		FIRSTBYTE_LATIN_NO5			= 0x05,
		FIRSTBYTE_LATIN_NO6			= 0x06,
		FIRSTBYTE_LATIN_THAI			= 0x07,
		FIRSTBYTE_LATIN_NO7			= 0x09,
		FIRSTBYTE_LATIN_NO8			= 0x0a,
		FIRSTBYTE_LATIN_NO9			= 0x0b,
	};
	// First Byte 가 0x10 인 경우
	enum EFirstbyteExtenedLatin
	{
		FIRSTBYTE_EXTENDED_ISO_8859_1	= 0x01,
		FIRSTBYTE_EXTENDED_ISO_8859_2	= 0x02,
		FIRSTBYTE_EXTENDED_ISO_8859_3	= 0x03,
		FIRSTBYTE_EXTENDED_ISO_8859_4	= 0x04,
		FIRSTBYTE_EXTENDED_LATIN_CYRILLIC	= 0x05,
		FIRSTBYTE_EXTENDED_LATIN_ARABIC	= 0x06,
		FIRSTBYTE_EXTENDED_LATIN_GREEK	= 0x07,
		FIRSTBYTE_EXTENDED_LATIN_HEBREW	= 0x08,
		FIRSTBYTE_EXTENDED_LATIN_NO5	= 0x09,
		FIRSTBYTE_EXTENDED_LATIN_NO6	= 0x0a,
		FIRSTBYTE_EXTENDED_LATIN_THAI	= 0x0b,
		FIRSTBYTE_EXTENDED_LATIN_NO7	= 0x0d,
		FIRSTBYTE_EXTENDED_LATIN_NO8	= 0x0e,
		FIRSTBYTE_EXTENDED_LATIN_NO9	= 0x0f,
	};
	
protected:
	/**
	 * @see Base class.
	 */
	virtual bool t_Convert(
		const unsigned char* srcData, 
		const unsigned short& srcSize, 
		unsigned char* convertedData, 
		unsigned short& convertedLength, 
		const bool extendedType, 
		const bool short_name, 
		const bool ignore_control_chars);

	/**
	 * @see Base class.
	 */
	virtual bool t_PostProcess(
		unsigned char* pDstData, 
		unsigned short* pDstSize, 
		const bool shortName = false, 
		const bool ignoreControlChars = false);
	
private:
	bool m_UniIsMergerApplicant(const unsigned char tester);
	unsigned short m_UniMergeCChars(const unsigned char c_character, const unsigned char merge_character);
	bool m_GetTableId(unsigned char tableCode, unsigned char *tableIndex, bool extendedType);
	bool m_GetDefaultCharacterTable(unsigned char* tableId);
};

#endif

