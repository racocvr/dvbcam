/** 
 * @file IBinder.h
 * @brief Binder interface. Provides methods for obtaining data.
 *
 * Copyright 2014 by Samsung Electronics, Inc.,
 * 
 * This software is the confidential and proprietary information
 * of Samsung Electronics, Inc. ("Confidential Information"). You
 * shall not disclose such Confidential Information and shall use
 * it only in accordance with the terms of the license agreement
 * you entered into with Samsung.
 */

#ifndef _IBINDER_H_
#define _IBINDER_H_

#include "SOSpecDataType.h"

#include "TVServiceDataType.h"
#include "ServiceNavigationDataType.h"
#include "ScanDataDataType.h"
#include <vector>
#include <pthread.h>

class IBinder
{
public:
	/**
	 * @brief Provides IBinder instance.
	 * @return IBinder instance.
	 */
	static IBinder* Instance();

	virtual ~IBinder() { }

	/**
	 * @brief Checks whether given pdsd is allowed in the current country.
	 * @param [in] tvsHandle TVS Handle for which the pdsd has to be verified.
	 * @param [in] pdsd Value of PDSD to be checked for allowance.
	 * @return Returns true if pdsd is allowed.
	 */
	virtual bool CheckPDSD(const TVSHandle &tvsHandle, EDVBPDSD pdsd) = 0;

	/**
	 * @brief Gets current country identifier.
	 * @param [in] tvsHandle TVS Handle for which the country will be obtained.
	 * @return Returns id of country.
	 */
	virtual int Country(const TVSHandle &tvsHandle) = 0;

	/**
	 * @brief Gets current country code.
	 * @param [in] tvsHandle TVS Handle for which the country will be obtained.
	 * @return Returns value of country code.
	 */
	virtual ECountryCode CountryCode(const TVSHandle &tvsHandle) = 0;

	/**
	 * @brief Gets default preferred language of the current country.
	 * @param [in] tvsHandle TVS Handle for which the default preferred language will be obtained.
	 * @return Returns default preferred language identifier.
	 */
	virtual ELanguageCode DefaultPreferrredLanguage(const TVSHandle &tvsHandle) = 0;

	/**
	 * @brief Gets DVB spec code of the current country.
	 * @param [in] tvsHandle TVS Handle for which the DVB Spec code will be obtained.
	 * @return Returns DVB spec code.
	 */
	virtual int DVBSpecCode(const TVSHandle &tvsHandle) = 0;

	/**
	 * @brief Gets user preferred language.
	 * @param [in] tvsHandle TVS Handle for which the preferred language will be obtained.
	 * @return Returns preferred language.
	 */
	virtual unsigned int PreferredLanguage(const TVSHandle &tvsHandle) = 0;

	/**
	 * @brief Gets private data specification of current country.
	 * @param [in] tvsHandle TVS Handle for which the private data specification will be obtained.
	 * @return Returns private data specification.
	 */
	virtual EDVBPDSD PrivateDataSpecification(const TVSHandle &tvsHandle) = 0;

	/**
	 * @brief Gets default character table index.
	 * @param [in] tvsHandle TVS Handle for which the default character table index will be obtained.
	 * @return Returns default character table index.
	 */
	virtual int DefaultCharacterTableIndex(const TVSHandle &tvsHandle) = 0;

	/**
	 * @brief Gets unicode conversion type
	 * @param [in] tvsHandle TVS Handle for which unicode conversion type is obtained.
	 * @return Returns type of unicode conversion
	 */
	virtual EUnicodeConvType UnicodeConversionType(const TVSHandle &tvsHandle) = 0;

	/**
	 * @brief Gets three bytes defining the character set encoding.
	 * @param [out] encoding Character set encoding.
	 */
	virtual void CharacterSetEncoding(const TVSHandle &tvsHandle, std::vector<unsigned char>& encoding) = 0;

	virtual EParentalLock ParentalLock(const TVSHandle &tvsHandle) =0;

	/**
	 * @brief Check if analog one map is supported.
	 * @remarks Analog one map means that air and cable analog services are common for air and cable tv modes.
	 * @return True if analog one map is supported.
	 */
	virtual bool CheckAnalogOneMap(void) = 0;	

	/**
	 * @brief Gets parental rating init identifier.
	 * @param[in] tvsHandle TVS Handle for which parental rating init will be obtained.
	 * @return Parental rating init identifier.
	 */
	virtual EParentalRatingInit ParentalRatingInit(const TVSHandle &tvsHandle) = 0;
	

private:
	static IBinder* m_pInstance;
	static pthread_rwlock_t m_rwlock; // lock for instance creation
};

#endif //_IBINDER_H_
