/** 
 * @file IDataControl.h
 * @brief Application interface for managing user data information.
 *
 * Copyright 2013 by Samsung Electronics, Inc.,
 * 
 * This software is the confidential and proprietary information
 * of Samsung Electronics, Inc. ("Confidential Information"). You
 * shall not disclose such Confidential Information and shall use
 * it only in accordance with the terms of the license agreement
 * you entered into with Samsung.
 */


#ifndef _IDATACONTROL_H_
#define _IDATACONTROL_H_


#include "MarshallingMarks.h"
#include "DataControlDataType.h"
#include "SOSpecDataType.h"
#include "AVControlDataType.h"


class IDataControl
{
protected:
	virtual ~IDataControl(){};

public:

	/**
	 * @brief Gets current caption data mode.
	 * @param [out] mode Caption data mode.
	 * @return Returns 1 if retreived caption data mode is valid, otherwise returns 0.
 	 *
	 *	@paragraph <Example>
	 *	This example will get current caption mode.
	 *	
	 *	@verbatim
	 *	IDataControl* pDataControl;
	 *	TVServiceAPI::CreateDataControl(PROFILE_TYPE_MAIN, 0, &pDataControl);
	 *	ECaptionDataMode captionMode;
	 *	if(pDataControl->GetCaptionDataMode(captionMode) > 0)
	 *	{
	 *		//Do something with returned caption mode
	 *	}
	 *	@endverbatim
	 */
	virtual int GetCaptionDataMode(_OUT_ ECaptionDataMode& mode) = 0;

	/**
	 * @brief Gets current default caption service.
	 * @param [out] service Caption service.
	 * @return Returns 1 if retreived caption service is valid, otherwise returns 0.
  	 *
	 *	@paragraph <Example>
	 *	This example will get current caption mode.
	 *	
	 *	@verbatim
	 *	IDataControl* pDataControl;
	 *	TVServiceAPI::CreateDataControl(PROFILE_TYPE_MAIN, 0, &pDataControl);
	 *	ECaptionService captionService;
	 *	if(pDataControl->GetCaptionDataMode(captionService) > 0)
	 *	{
	 *		//Do something with returned caption service
	 *	}
	 *	@endverbatim
	 */
	virtual int GetDefaultCaptionService(_OUT_ ECaptionService& service) = 0;

	/**
	 * @brief Gets current caption language and Korean Code.
	 * @param [in] service Caption service.
	 * @param [out] language Caption language code.
	 * @param [out] koreanCode Is Korean code.
	 * @return Returns 1 if all retreived data are valid, otherwise returns 0.
   	 *
	 *	@paragraph <Example>
	 *	This example will get current caption mode.
	 *	
	 *	@verbatim
	 *	IDataControl* pDataControl;
	 *	TVServiceAPI::CreateDataControl(PROFILE_TYPE_MAIN, 0, &pDataControl);
	 *	ECaptionService captionService = CAPTION_SERVICE_CC1;
	 *	ELanguageCode language;
	 *	char koreanCode;
	 *	if(pDataControl->GetCaptionDataMode(captionService, language, koreanCode) > 0)
	 *	{
	 *		//Do something with returned language and koreanCode
	 *	}
	 *	@endverbatim
	 */
	virtual int GetCaptionLanguage(_IN_ ECaptionService service, _OUT_ ELanguageCode& language, _OUT_ char& koreanCode) = 0;

	// DVB interface

	/**
	 * @brief Sets current TTX.
	 * @param [in] index Index of TTX which should be set.
	 * @return Returns 1 if specified TTX was set, otherwise returns 0.
	 * @return When calling method failed returns -1.
   	 *
	 *	@paragraph <Example>
	 *	This example will set TTX under index == 1.
	 *	
	 *	@verbatim
	 *	IDataControl* pDataControl;
	 *	TVServiceAPI::CreateDataControl(PROFILE_TYPE_MAIN, 0, &pDataControl);
	 *	if(pDataControl->SetCurrentTTX(1) > 0)
	 *	{
	 *		//Do something when new TTX was set.
	 *	}
	 *	@endverbatim
	 */
	virtual int SetCurrentTTX(_IN_ unsigned int index) = 0;

	/**
	 * @brief Gets current TTX info.
	 * @param [out] language Language of current TTX.
	 * @param [out] index Index of current TTX.
	 * @return Returns 1 if current TTX ws retreived, otherwise returns 0.
	 * @return When calling method failed returns -1.
   	 *
	 *	@paragraph <Example>
	 *	This example will get current TTX info.
	 *	
	 *	@verbatim
	 *	IDataControl* pDataControl;
	 *	TVServiceAPI::CreateDataControl(PROFILE_TYPE_MAIN, 0, &pDataControl);
	 *  ELanguageCode language = LANGUAGE_CODE_UNKNOWN;
	 *  unsigned int index = 0;
	 *	if(pDataControl->GetCurrentTTX(language, index) > 0)
	 *	{
	 *		//Do something when current TTX was retrieved.
	 *	}
	 *	@endverbatim
	 */
	virtual int GetCurrentTTX(_OUT_ ELanguageCode& language, _OUT_ unsigned int& index) = 0;

	/**
	 * @brief Sets current HybridSBT.
	 * @remark When index == 0 is passed then the preferred HybridSBT is set.
	 * @param [in] index Index of HybridSBT which should be set.
	 * @return Returns 1 if specified HybridSBT was set, otherwise returns 0.
	 * @return When calling method failed returns -1.
   	 *
	 *	@paragraph <Example>
	 *	This example will set HybridSBT under index == 1.
	 *	
	 *	@verbatim
	 *	IDataControl* pDataControl;
	 *	TVServiceAPI::CreateDataControl(PROFILE_TYPE_MAIN, 0, &pDataControl);
	 *	if(pDataControl->SetCurrentHybridSBT(1) > 0)
	 *	{
	 *		//Do something when new HybridSBT was set.
	 *	}
	 *	@endverbatim
	 */
	virtual int SetCurrentHybridSBT(_IN_ unsigned int index) = 0;

	/**
	 * @brief Gets current HybridSBT info.
	 * @remark When index == 0 is retrieved that means the preferred HybridSBT is set.
	 * @param [out] language Language of current HybridSBT.
	 * @param [out] index Index of current HybridSBT.
	 * @return Returns 1 if current HybridSBT ws retreived, otherwise returns 0.
	 * @return When calling method failed returns -1.
   	 *
	 *	@paragraph <Example>
	 *	This example will get current HybridSBT info.
	 *	
	 *	@verbatim
	 *	IDataControl* pDataControl;
	 *	TVServiceAPI::CreateDataControl(PROFILE_TYPE_MAIN, 0, &pDataControl);
	 *  ELanguageCode language = LANGUAGE_CODE_UNKNOWN;
	 *  unsigned int index = 0;
	 *	if(pDataControl->GetCurrentHybridSBT(language, index) > 0)
	 *	{
	 *		//Do something when current HybridSBT was retrieved.
	 *	}
	 *	@endverbatim
	 */
	virtual int GetCurrentHybridSBT(_OUT_ ELanguageCode& language, _OUT_ unsigned int& index) = 0;

	/**
	 * @brief Gets preferred TTX info.
	 * @param [out] ttxSubtitle Preferred TTX info.
	 * @return Returns 1 if preferred TTX ws retreived, otherwise returns 0.
	 * @return When calling method failed returns -1.
   	 *
	 *	@paragraph <Example>
	 *	This example will get preferred TTX info.
	 *	
	 *	@verbatim
	 *	IDataControl* pDataControl;
	 *	TVServiceAPI::CreateDataControl(PROFILE_TYPE_MAIN, 0, &pDataControl);
	 *  TSTTX ttxSubtitle;
	 *	if(pDataControl->GetPreferredTTXSubtitle(ttxSubtitle) > 0)
	 *	{
	 *		//Do something when preferred TTX was retrieved.
	 *	}
	 *	@endverbatim
	 */
	virtual int GetPreferredTTXSubtitle(_OUT_ TSTTX& ttxSubtitle) = 0;

	/**
	 * @brief Gets preferred HybridSBT info.
	 * @param [out] language Preferred HybridSBT language.
	 * @param [out] hybridSbt Preferred HybridSBT info.
	 * @return Returns 1 if preferred TTX ws retreived, otherwise returns 0.
	 * @return When calling method failed returns -1.
   	 *
	 *	@paragraph <Example>
	 *	This example will get preferred HybridSBT info.
	 *	
	 *	@verbatim
	 *	IDataControl* pDataControl;
	 *	TVServiceAPI::CreateDataControl(PROFILE_TYPE_MAIN, 0, &pDataControl);
	 *  TSHybridSBT hybridSbt;
	 *	if(pDataControl->GetPreferredHybridSBT(hybridSbt) > 0)
	 *	{
	 *		//Do something when preferred HybridSBT was retrieved.
	 *	}
	 *	@endverbatim
	 */
	virtual int GetPreferredHybridSBT(_OUT_ ELanguageCode& language, _OUT_ TSHybridSBT& hybridSbt) = 0;

	/**
	 * @brief Gets current ISDB text index
	 * @param [in] mode ISDB Text Type.
	 * @param [out] language Language of current ISDBText.
	 * @param [out] index Language index of current ISDBText.
	 * @return Return true if the index was get successfully, false otherwise
	 *
	 *	@paragraph <Example>
	 *	This example will get current ISDB text language and index for CAPTION mode and tvsHandle(PROFILE_TYPE_MAIN, 0).
	 *	
	 *	@verbatim
	 *	IDataControl* pDataControl;
	 *	TVServiceAPI::CreateDataControl(PROFILE_TYPE_MAIN, 0, &pDataControl);
	 *	EISDBTextType mode = ISDB_TEXT_MODE_CAPTION;
	 *	ELanguageCode language;
	 *  	int index;
	 *	if(pDataControl->GetCurrentISDBText(mode, language, index) > 0)
	 *	{
	 *		//Do something with returned index.
	 *	}
	 *	@endverbatim
	 */
	virtual bool GetCurrentISDBText( _IN_ EISDBTextType mode, _OUT_ ELanguageCode& language, _OUT_ unsigned int& index) = 0;

	/**
	 * @brief Sets current ISDB text index and invoke setting new ISDB Text pid in tuner.
	 * @param [in] mode ISDB Text Type.
	 * @param [in] index Language index of ISDBText.
	 * @return Return true if the index was set successfully, false otherwise
	 *
	 *	@paragraph <Example>
	 *	This example will set current ISDB text index at 3 for CAPTION mode and tvsHandle(PROFILE_TYPE_MAIN, 0).
	 *	
	 *	@verbatim
	 *	IDataControl* pDataControl;
	 *	TVServiceAPI::CreateDataControl(PROFILE_TYPE_MAIN, 0, &pDataControl);
	 *	EISDBTextType mode = ISDB_TEXT_MODE_CAPTION;
	 *  	int index = 3;
	 *	if(pDataControl->SetCurrentISDBText(mode, index) > 0)
	 *	{
	 *		//success
	 *	}
	 *	@endverbatim
	 */
	virtual bool SetCurrentISDBText( _IN_ EISDBTextType mode, _IN_ int index) = 0;

	/**
	 * @brief Sets current ISDB text compTag and invoke setting new ISDB Text pid in tuner.
	 * @param [in] service, Service id.
	 * @param [in] mode, ISDB Text Type.
	 * @param [in] compTag, component Tag of ISDBText.
	 * @return Return true if the index was get successfully, false otherwise
	 */
	virtual bool SetCurrentISDBTextService( _IN_ EISDBTextType mode, _IN_  int compTag) = 0;

	virtual int GetSTCCount( _OUT_ unsigned long long& stc) = 0;

	// TODO Duende - to be removed after 1.10.2014
	virtual int GetSTCCount( _OUT_ unsigned long& stc)
	{
		unsigned long long temp;
		int ret = GetSTCCount(temp);
		stc = (unsigned long) temp;
		return ret;
	};

	//virtual int ControlTTXCommand(_IN_ ETTXCmd commad, _IN_ ETTXCmd param1, _IN_ ETTXCmd param2, _OUT_ ETTXCmd& colorkeys) = 0;

	//virtual int TTXShowMode(_OUT_ int& mode) = 0;

	//virtual int GetTTXTime(_OUT_ int& hour, _OUT_ int& minute, _OUT_ int& second) = 0;

	//virtual int CheckSubtitleSyncByFirstPTS(_OUT_ bool& flag) = 0;

	// ISDB interface.

	//virtual int GetISDBTextService(_OUT_ int& index, _IN_ EISDBTextType mode) = 0;

	//virtual int GetISDBTextLanguageByCompTag(_IN_ int compTag, _OUT_ ELanguageCode& langCode) = 0;

	//virtual int GetActiveCaptionIndexList(_OUT_ std::list<int>& list) = 0;

	//virtual int GetActiveSuperImposeIndexList(_OUT_ std::list<int>& list) = 0;

};

#endif // _IDATACONTROL_H_

