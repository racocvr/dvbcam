/** 
 * @file ITunerControl.h
 * @brief Application interface for controlling tuner.
 *
 * Copyright 2013 by Samsung Electronics, Inc.,
 * 
 * This software is the confidential and proprietary information
 * of Samsung Electronics, Inc. ("Confidential Information"). You
 * shall not disclose such Confidential Information and shall use
 * it only in accordance with the terms of the license agreement
 * you entered into with Samsung.
 */


#ifndef _ITUNERCONTROL_H_
#define _ITUNERCONTROL_H_

#include "MarshallingMarks.h"
#include "TunerControlDataType.h"
#include "ServiceDataType.h"


class ITunerControl
{
protected:
	virtual ~ITunerControl(){};

public:

	/**
	 * @brief Gets signal strength.
	 * @param [in] selfFlag ???.
	 * @param [out] sigStrength Signal strength.
	 * @return Returns 1 if signal strength acquired successfully, otherwise returns 0.
	 * @return When calling method failed returns -1.
	 *
	 *	@paragraph <Example>
	 *	
	 *	@verbatim
	 *	ITunerControl* pTunerControl = NULL;
	 *	TVServiceAPI::CreateTunerControl(PROFILE_TYPE_MAIN, 0, &pTunerControl);
	 *	unsigned char sigStrength;
	 *	if(pTunerControl->GetSignalStrength(false, sigStrength) > 0)
	 *	{
	 *		//Do something when operation successful
	 *	}
	 *	@endverbatim
	 */
	virtual int GetSignalStrength(_IN_ bool selfFlag, _OUT_ unsigned char& sigStrength) = 0;

	/**
	 * @brief Gets signal quality.
	 * @param [out] quality Signal quality.
	 * @return Returns 1 if signal quality acquired successfully, otherwise returns 0.
	 * @return When calling method failed returns -1.
	 *
	 *	@paragraph <Example>
	 *	
	 *	@verbatim
	 *	ITunerControl* pTunerControl = NULL;
	 *	TVServiceAPI::CreateTunerControl(PROFILE_TYPE_MAIN, 0, &pTunerControl);
	 *	unsigned char quality;
	 *	if(pTunerControl->GetSignalQuality(quality) > 0)
	 *	{
	 *		//Do something when operation successful
	 *	}
	 *	@endverbatim
	 */
	virtual int GetSignalQuality(_OUT_ unsigned char& quality) = 0;
	
	/**
	 * @brief Gets current RF signal kind.
	 * @param [out] signalKind Signal kind.
	 * @return Returns 1 if signal kind acquired successfully, otherwise returns 0.
	 * @return When calling method failed returns -1.
	 *
	 *	@paragraph <Example>
	 *	
	 *	@verbatim
	 *	ITunerControl* pTunerControl = NULL;
	 *	TVServiceAPI::CreateTunerControl(PROFILE_TYPE_MAIN, 0, &pTunerControl);
	 *	ESignalKind signalKind;
	 *	if(pTunerControl->GetSignalKind(signalKind) > 0)
	 *	{
	 *		//Do something when operation successful
	 *	}
	 *	@endverbatim
	 */
	virtual int GetSignalKind(_OUT_ ESignalKind& signalKind) = 0;

	/**
	 * @brief Gets Bit Error Rate.
	 * @param [out] Bit Error Rate.
	 * @return Returns 1 if Bit Error Rate acquired successfully, otherwise returns 0.
	 * @return When calling method failed returns -1.
	 *
	 *	@paragraph <Example>
	 *	
	 *	@verbatim
	 *	ITunerControl* pTunerControl = NULL;
	 *	TVServiceAPI::CreateTunerControl(PROFILE_TYPE_MAIN, 0, &pTunerControl);
	 *	unsigned int quality;
	 *	if(pTunerControl->GetBER(ber) > 0)
	 *	{
	 *		//Do something when operation successful
	 *	}
	 *	@endverbatim
	 */
	virtual int GetBER(_OUT_ unsigned int& ber) = 0;

	/**
	 * @brief Gets Signal-to-Noise ratio.
	 * @param [out] snr Signal-to-Noise ratio.
	 * @return Returns 1 if SNR acquired successfully, otherwise returns 0.
	 * @return When calling method failed returns -1.
	 *
	 *	@paragraph <Example>
	 *	
	 *	@verbatim
	 *	ITunerControl* pTunerControl = NULL;
	 *	TVServiceAPI::CreateTunerControl(PROFILE_TYPE_MAIN, 0, &pTunerControl);
	 *	unsigned int snr;
	 *	if(pTunerControl->GetSNR(snr) > 0)
	 *	{
	 *		//Do something when operation successful
	 *	}
	 *	@endverbatim
	 */
	virtual int GetSNR(_OUT_ unsigned int& snr) = 0;

	/**
	 * @brief Resets Manual Fine Tuning.
	 * @return Returns 1 if MFT reset, otherwise returns 0.
	 * @return When calling method failed returns -1.
	 *
	 *	@paragraph <Example>
	 *	
	 *	@verbatim
	 *	ITunerControl* pTunerControl = NULL;
	 *	TVServiceAPI::CreateTunerControl(PROFILE_TYPE_MAIN, 0, &pTunerControl);
	 *	if(pTunerControl->ResetMFT(num) > 0)
	 *	{
	 *		//Do something when operation successful
	 *	}
	 *	@endverbatim
	 */
	virtual int ResetMFT(void) = 0;

	/**
	 * @brief Tunes for Manual Fine Tuning.
	 * @param [in] mftFreq MFT frequency.
	 * @return Returns 1 if tuned successfully, otherwise returns 0.
	 * @return When calling method failed returns -1.
	 *
	 *	@paragraph <Example>
	 *	
	 *	@verbatim
	 *	ITunerControl* pTunerControl = NULL;
	 *	TVServiceAPI::CreateTunerControl(PROFILE_TYPE_MAIN, 0, &pTunerControl);
	 *	if(pTunerControl->TuneForMFT(10) > 0)
	 *	{
	 *		//Do something when operation successful
	 *	}
	 *	@endverbatim
	 */
	virtual int TuneForMFT(_IN_ unsigned char mftFreq) = 0;

	/**
	 * @brief Save the frequency for Manual Fine Tuning.
	 * @return Returns 1 if tuned successfully, otherwise returns 0.
	 * @return When calling method failed returns -1.
	 *
	 *	@paragraph <Example>
	 *	
	 *	@verbatim
	 *	ITunerControl* pTunerControl = NULL;
	 *	TVServiceAPI::CreateTunerControl(PROFILE_TYPE_MAIN, 0, &pTunerControl);
	 *	if(pTunerControl->SaveForMFT() > 0)
	 *	{
	 *		//Do something when operation successful
	 *	}
	 *	@endverbatim
	 */
	virtual int SaveForMFT(void) = 0;

	/**
	 * @brief Get the current tuning frequency for Manual Fine Tuning.
	 * @return Returns 1 if tuned successfully, otherwise returns 0.
	 * @return When calling method failed returns -1.
	 *
	 *	@paragraph <Example>
	 *	
	 *	@verbatim
	 *	ITunerControl* pTunerControl = NULL;
	 *	TVServiceAPI::CreateTunerControl(PROFILE_TYPE_MAIN, 0, &pTunerControl);
	 *    unsigned char mftFreq;
	 *	if(pTunerControl->GetTunerOffsetForMFT(mftFreq) > 0)
	 *	{
	 *		//Do something when operation successful
	 *	}
	 *	@endverbatim
	 */
	virtual int GetTunerOffsetForMFT( unsigned char& mftFreq  ) = 0;

	/**
	 * @brief Get the index of tuner that is used by this pipeline
	 * @return Returns 1 if tuned successfully, otherwise returns 0.
	 * @return When calling method failed returns -1.
	 * @param [out] index tuner index
	 *
	 *	@paragraph <Example>
	 *	
	 *	@verbatim
	 *	ITunerControl* pTunerControl = NULL;
	 *	TVServiceAPI::CreateTunerControl(PROFILE_TYPE_MAIN, 0, &pTunerControl);
	 *  int index;
	 *	if(pTunerControl->GetTunerIndex(index) > 0)
	 *	{
	 *		//Do something when operation successful
	 *	}
	 *	@endverbatim
	 */
	virtual int GetTunerIndex(_OUT_ int& index) = 0;

	/**
	 * @brief Checks whether tuner being connected with antenna cable.
	 * @return Returns 1 if data were fetched, otherwise returns 0.
	 * @return When calling method failed returns -1.
	 * @param [out] state tuner signal state
	 *
	 *	@paragraph <Example>
	 *	
	 *	@verbatim
	 *	ITunerControl* pTunerControl = NULL;
	 *	TVServiceAPI::CreateTunerControl(PROFILE_TYPE_MAIN, 0, &pTunerControl);
	 *  ETunerSignalState state;
	 *	if(pTunerControl->GetTuneSignalState(state) > 0)
	 *	{
	 *		//Do something when operation successful
	 *	}
	 *	@endverbatim
	 */
	virtual int GetTuneSignalState(_OUT_ ETunerSignalState& state) = 0;

	
};

#endif // _ITUNERCONTROL_H_

