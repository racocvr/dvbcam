/** 
 * @file	UniConv.h
 * @brief	Unicode conversion helper classes for Japan
 *
 * Copyright 2013 by Samsung Electronics, Inc.,
 * 
 * This software is the confidential and proprietary information
 * of Samsung Electronics, Inc. ("Confidential Information").  You
 * shall not disclose such Confidential Information and shall use
 * it only in accordance with the terms of the license agreement
 * you entered into with Samsung.
 */

#ifndef _UNICONVJPN_H_
#define _UNICONVJPN_H_

#include "SOSpecDataType.h"

class TCUniConvJapan
{

private :
	/* Japan Table 영역 지정 */
	enum EJapanTable
	{
		GRAPHIC_AREA_LEFT_START_INDEX =0xA0,
		GRAPHIC_AREA_LEFT_END_INDEX	=0xFE,

		GRAPHIC_AREA_RIGHT_START_INDEX = 0x21,
		GRAPHIC_AREA_RIGHT_END_INDEX = 0x7E,

		CJK_FIRST_INDEX = 0x30,		
		CJK_LAST_INDEX = 0x76,

		KANJI_FIRST_INDEX = 0x21,		
		KANJI_LAST_INDEX = 0x28,

		ADDED_SYMBOL_FIRST_INDEX = 0x7A,		
		ADDED_SYMBOL_RANGE_LAST_INDEX = 0x7E,	

		HIRAGANA_START_INDEX = 0x40,
		HIRAGANA_END_INDEX = 0x9F,

		HALF_KATAKANA_ST_INDEX = 0x61,	

		SINGLE_SHIFTED_INDEX = 0x80,
	};

	enum EControlCode
	{
		CONTROL_LEFT_AREA = 0x20, //CL Area
		LS0	 = 0x0F,//G0 - Kanji
		LS1 = 0x0E,//G1 - alphanumeric
		LS2 = 0x6E,//G2 - Hiragana
		LS3 = 0x6F,//G3 - Katakana		
		SS2 = 0x19,//G2 - Hiragana
		SS3 = 0x1D,//G3 - Katakana
		SP = 0x20,//Space	
		ESC = 0x1B,//Extended Sequence
		LS1R = 0x7E,//G1 - alphanumeric
		LS2R = 0x7D,//G2 - Hiragana
		LS3R = 0x7C, //G3 - katakana	
		CR = 0x0d,//Carriage return : 커서의 위치를 현재 줄의 맨 처음으로 보내는 기능 
		LF = 0x0A,//Line Feed : 커서를 다음줄로 옮기는 기능 : 유닉스는 LF만으로 개행을 표현, 윈도우즈는 CR/LF의 조합으로 개행을 표현한다.
		DEL = 0x7F,//Delete Character
		TAB = 0x09,//Tab
		

		//termination codes
		ADDITIONAL_SIGNS = 0x3b,
		JISX0201_KATAKANA = 0x49,
		KANJI_SIDE_1 = 0x39,		
		KANJI_SIDE_2 = 0x3a,
		HIRAGANA = 0x30,
		KATAKANA = 0x31,
		ALPHANUMERIC = 0x4a,


		//Font size
		//이 control code 는 Caption data 에서 처리하는 control code로 M/W에서는 이를 처리해줄 필요없다. 무시해야함.
		MIDDLE_SIZE = 0x89, 
		NORMAL_SIZE = 0x8a, 
	};

	enum EGraphicSet
	{
		//Designation of graphic sets		
		GRAPHIC_SETS_2_BYTE = 0x24, // ESC 02/4 - 2Byte G Set	
		G0 = 0x2f,
		G1 = 0x29,
		G2 = 0x2a,
		G3 = 0x2b
	};

	enum EHalfWidth
	{
		HALF_KATAKANA_START_INDEX = 0xFF61,		
		HALF_kATAKANA_END_INDEX=0xFF9F,
	};

	bool m_CheckControlCode(const unsigned char src1Byte, const unsigned char src2Byte, bool* Is1ByteControl, ECharacterTable* SelectedTable, bool *IsThisShifted,bool *IsLockingShifted);
	bool m_Select2ByteCharacterSet(const unsigned char src1Byte, const unsigned char src2Byte, unsigned int* uniChar);


public:
	bool Convert(unsigned char* srcData, unsigned short* srcSize, unsigned char* dstData, unsigned short* dstSize, bool short_name = false, bool ignore_control_chars = false);

	bool ConvertToFullWidth(unsigned char* srcData, unsigned short* srcSize, unsigned char* dstData, unsigned short* dstSize); 

	bool ConvertToUnicodeWithoutControlCode(unsigned char* src, unsigned short srcLen, unsigned short* dest, unsigned short* destLen, ECharacterTable type);

};

#endif
