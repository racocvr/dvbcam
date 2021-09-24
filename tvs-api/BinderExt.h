/** 
 * @file BinderExt.h
 * @brief Binder for external usage (outside of TVService).
 *
 * Copyright 2014 by Samsung Electronics, Inc.,
 * 
 * This software is the confidential and proprietary information
 * of Samsung Electronics, Inc. ("Confidential Information"). You
 * shall not disclose such Confidential Information and shall use
 * it only in accordance with the terms of the license agreement
 * you entered into with Samsung.
 */

#ifndef _BINDEREXT_H_
#define _BINDEREXT_H_

#include "IBinder.h"

class TCBinderExt : public IBinder
{
public:
	/**
	 * @see Base class.
	 */
	bool			CheckPDSD(const TVSHandle &tvsHandle, EDVBPDSD pdsd);

	/**
	 * @see Base class.
	 */
	int Country(const TVSHandle &tvsHandle);

	/**
	 * @see Base class.
	 */
	ECountryCode	CountryCode(const TVSHandle &tvsHandle);

	/**
	 * @see Base class.
	 */
	ELanguageCode	DefaultPreferrredLanguage(const TVSHandle &tvsHandle);

	/**
	 * @see Base class.
	 */
	int				DVBSpecCode(const TVSHandle &tvsHandle);

	/**
	 * @see Base class.
	 */
	unsigned int	PreferredLanguage(const TVSHandle &tvsHandle);

	/**
	 * @see Base class.
	 */
	EDVBPDSD		PrivateDataSpecification(const TVSHandle &tvsHandle);

	/**
	 * @see Base class.
	 */
	int DefaultCharacterTableIndex(const TVSHandle &tvsHandle);

	/**
	 * @see Base class.
	 */
	EUnicodeConvType UnicodeConversionType(const TVSHandle &tvsHandle);

	/**
	 * @see Base class.
	 */
	void CharacterSetEncoding(const TVSHandle &tvsHandle, std::vector<unsigned char>& encoding);

	/**
	 * @see Base class.
	 */
	EParentalLock ParentalLock(const TVSHandle &tvsHandle);

	/**
	 * @see Base class.
	 */
	virtual bool CheckAnalogOneMap(void);

	/**
	 * @see Base class.
	 */
	virtual EParentalRatingInit ParentalRatingInit(const TVSHandle &tvsHandle);
	 
};

#endif //_BINDEREXT_H_
