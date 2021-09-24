/** 
 * @file	UniConv.h
 * @brief	Unicode conversion helper classes for Brazil.
 *
 * Copyright 2013 by Samsung Electronics, Inc.,
 * 
 * This software is the confidential and proprietary information
 * of Samsung Electronics, Inc. ("Confidential Information").  You
 * shall not disclose such Confidential Information and shall use
 * it only in accordance with the terms of the license agreement
 * you entered into with Samsung.
 */

#ifndef _UNICONV_H_
#define _UNICONV_H_

#include "TVServiceDataType.h"

class TCUniConv
{
public :
	/*
	 * @brief Converts encoded string to unicode.
	 * @remark pDstData has to be pre-allocated
	 * @param [in] srcData Buffer with the encoded string.
	 * @param [in] srcSize Size of source buffer.
	 * @param [out] dstData Buffer with unicode string.
	 * @param [inout] dstSize Size of output buffer. After successfull conversion will carry 
	 * byte length of string put into dstData (at most original dstSize)
	 * @param [in] extendedType (?)
	 * @param [in] shortName Defines if input string represent channel short name.
	 * @param [in] langCode Language of current channel.
	 * @return True Returns true when convertion succeeded.
	 */
	bool Convert(
		const unsigned char* srcData, 
		const unsigned short& srcSize,
		unsigned char* dstData, 
		unsigned short& dstSize, 
		const bool extendedType = false, 
		const bool short_name = false, 
		const bool ignore_control_chars = false);

protected:
	/*
	 * @brief Main converting method, implemented by each of the conversion type differently.
	 * @remark pDstData has to be pre-allocated
	 * @remark input parameter checking for NULL and 0 size is done already, do not do it again
	 * @param [in] srcData Buffer with the encoded string.
	 * @param [in] srcSize Size of source buffer.
	 * @param [out] dstData Buffer with unicode string.
	 * @param [inout] dstSize Size of output buffer. After successfull conversion will carry 
	 * byte length of string put into dstData (at most original dstSize)
	 * @param [in] extendedType (?)
	 * @param [in] shortName Defines if input string represent channel short name.
	 * @param [in] langCode Language of current channel.
	 * @return True Returns true when convertion succeeded.
	 */
	virtual bool t_Convert(
		const unsigned char* srcData, 
		const unsigned short& srcSize, 
		unsigned char* convertedData, 
		unsigned short& convertedLength, 
		const bool extendedType, 
		const bool short_name, 
		const bool ignore_control_chars) = 0;

	/**
	 * @brief Post process converted data.
	 * @param[inout] pDstData Buffer with string.
	 * @param[inout] pDstSize Size of buffer.
	 * @param[in] shortName Defines if input string represents channel short name.
	 * @param[in] ignoreControlChars Specifies if control chars should be ignored.
	 * @return True when post processing succeeded, false otherwise.
	 */
	virtual bool t_PostProcess(
		unsigned char* pDstData, 
		unsigned short* pDstSize, 
		const bool shortName = false, 
		const bool ignoreControlChars = false);

	TCUniConv() {}
	virtual ~TCUniConv() {}
};

#endif

