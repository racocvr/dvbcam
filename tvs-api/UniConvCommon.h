/** 
 * @file	UniConvCommon.h
 * @brief	Common methods of unicode conversion helper classes.
 *
 * Copyright 2013 by Samsung Electronics, Inc.,
 * 
 * This software is the confidential and proprietary information
 * of Samsung Electronics, Inc. ("Confidential Information").  You
 * shall not disclose such Confidential Information and shall use
 * it only in accordance with the terms of the license agreement
 * you entered into with Samsung.
 */

#ifndef _UNICONVCOMMON_H_
#define _UNICONVCOMMON_H_

#define UNICODE_NOTHING ((unsigned short)0)
#define CHAR_1BYTE            1
#define CHAR_2BYTE            2
#define CHAR_MAPPING_UNIT    94

#define pfmGet8(a)     (*((unsigned char *)(a)))
#define pfmGet16(a)    ((unsigned short)(pfmGet8(a)<<8) + (unsigned short)(pfmGet8(((unsigned char *)(a))+1)))

class TCUniConvCommon
{
private :
	/* Unicode String Filtering 시에 사용할 Character Code */
	enum EUnicode
	{
		UNICODE_CTRLBYTE_START      = 0x0000,
		UNICODE_CTRLBYTE_END        = 0x001f,

		UNICODE_CTRLBYTE_LF         = 0x000a,

		UNICODE_SOFT_HYPHEN	        = 0x00ad,
        UNICODE_DEL                 = 0x007f,
		UNICODE_DVB_EMPHASIS_ON     = 0xe086,   /* DVB Spec 에서 Unicode Private 영역에 정의한 Character */
		UNICODE_DVB_EMPHASIS_OFF    = 0xe087,   /* DVB Spec 에서 Unicode Private 영역에 정의한 Character */
		UNICODE_DVB_CR_LF           = 0xe08a,   /* DVB Spec 에서 Unicode Private 영역에 정의한 Character */

		UNICODE_HK_SPECIAL_BIG 	    = 0x00CA,
		UNICODE_HK_SPECIAL_SMALL    = 0x00EA,
		UNICODE_HK_SPECIAL1 		= 0xF325,
		UNICODE_HK_SPECIAL2 		= 0xF327,
		UNICODE_HK_SPECIAL3 		= 0xF344,
		UNICODE_HK_SPECIAL4 		= 0xF346,
	};

public:
	/// Unicode로 Converting 된 String 에 대해 후처리 작업을 한다.
    /// @param [in,out] dstData A pointer to the string to process.  The processed
    ///                        data is written back to this data (therefore must
    ///                        contain less data!).
    /// @param [in,out] dstSize A pointer to the variable containing the length of
    ///                        dstData (in bytes).  On return the variable stores
    ///                        the length of the processed data (in bytes).
    /// @param [in] short_name Set this value to true to create a short name from
    ///                        the input name (only characters surrounded by
    ///                        emphasis chars are copied into the output string).
    ///                        Used by DVB SI data.
    /// @param [in] ignore_control_chars Set this value to true to ignore
    ///                        characters that are in the range of 0x00 - 0x1f
    ///                        which are illegal for DVB.
    ///                        Used by DVB SI data.
	bool ConvPostProcess(unsigned char* dstData, unsigned short* dstSize, bool short_name = false, bool ignore_control_chars = false);
};

#endif

