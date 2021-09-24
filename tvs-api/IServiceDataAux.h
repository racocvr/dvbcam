/** 
 * @file IServiceDataAux.h
 * @brief Utility methods related to service data.
 *
 * Copyright 2013 by Samsung Electronics, Inc.,
 * 
 * This software is the confidential and proprietary information
 * of Samsung Electronics, Inc. ("Confidential Information"). You
 * shall not disclose such Confidential Information and shall use
 * it only in accordance with the terms of the license agreement
 * you entered into with Samsung.
 */


#ifndef _ISERVICEDATAAUX_H_
#define _ISERVICEDATAAUX_H_


#include <map>
#include <vector>

#include "MarshallingMarks.h"
#include "ServiceData.h"
#include "AVControlDataType.h"
#include "DataControlDataType.h"


class IServiceDataAux
{
protected:
	virtual ~IServiceDataAux(){};

public:

	/**
	 * @brief Gets number of audio informations for specified service.
	 * @param [in] serviceId Service id.
	 * @param [out] size Audio information size.
	 * @return Returns 1 if audio size was successfully obtained, otherwise returns 0.
	 * @return When calling method failed returns -1.
	 *
	 *	@paragraph <Example>
	 *	This example will get size of audio information for serviceId == 848824369157121 and tvsHandle(PROFILE_TYPE_MAIN, 0).
	 *	
	 *	@verbatim
	 *	TCServiceId serviceId = 848824369157121;
	 *	unsigned int audioSize;
	 *
	 *	if(TVServiceAPI::ServiceDataAux(PROFILE_TYPE_MAIN, 0)->SizeOfAudio(serviceId, audioSize) > 0)
	 *	{
	 *		//Do something
	 *	}
	 *	@endverbatim
	 */
	virtual int SizeOfAudio(_IN_ const TCServiceId& serviceId, _OUT_ unsigned int& size) = 0;

	/**
	 * @brief Gets audio information for specified service.
	 * @param [in] serviceId Service id.
	 * @param [in] index Index of requested audio.
	 * @param [out] audio Audio information.
	 * @return Returns 1 if audio info was successfully obtained, otherwise returns 0.
	 * @return When calling method failed returns -1.
	 *
	 *	@paragraph <Example>
	 *	This example will get first available audio information for serviceId == 848824369157121 and tvsHandle(PROFILE_TYPE_MAIN, 0).
	 *	
	 *	@verbatim
	 *	TCServiceId serviceId = 848824369157121;
	 *	TSAudio audio;
	 *	if(TVServiceAPI::ServiceDataAux(PROFILE_TYPE_MAIN, 0)->GetAudio(serviceId, 0, audio) > 0)
	 *	{
	 *		//Do something with return audio
	 *	}
	 *	@endverbatim
	 */
	virtual int GetAudio(_IN_ const TCServiceId& serviceId, _IN_ unsigned int index, _OUT_ TSAudio& audio) = 0;

	/**
	 * @brief Gets preferred audio information for specified service.
	 * @param [in] serviceId Service id.
	 * @param [out] audio Prefered audio information.
	 * @return Returns 1 if audio info was successfully obtained, otherwise returns 0.
	 * @return When calling method failed returns -1.
	 *
	 *	@paragraph <Example>
	 *	This example will get preferred audio information for serviceId == 848824369157121 and tvsHandle(PROFILE_TYPE_MAIN, 0).
	 *	
	 *	@verbatim
	 *	TCServiceId serviceId = 848824369157121;
	 *	TSAudio preferAudio;
	 *	if(TVServiceAPI::ServiceDataAux(PROFILE_TYPE_MAIN, 0)->GetAudio(serviceId, preferAudio) > 0)
	 *	{
	 *		//Do something with return preferAudio
	 *	}
	 *	@endverbatim
	 */
	virtual int GetPreferredAudio(_IN_ const TCServiceId& serviceId, _OUT_ TSAudio& audio) = 0;

	/**
	 * @brief Check if there is audio description information for specified service.
	 * @remark This method is not a equivalent of SizeOfAudioDescription method ( SizeOfAudioDescription() > 0 != exists ).
	 * @remark Meaning some of visual imparied audio could be listed in normal audio list.
	 * @param [in] serviceId Service id.
	 * @param [out] exists True if audio description for given service exists, false otherwise.
	 * @return Returns 1 if information was successfully obtained, otherwise returns 0.
	 * @return When calling method failed returns -1.
	 *
	 *	@paragraph <Example>
	 *	This example will check if there is audio description for serviceId == 848824369157121 and tvsHandle(PROFILE_TYPE_MAIN, 0).
	 *	
	 *	@verbatim
	 *	TCServiceId serviceId = 848824369157121;
	 *	bool exists;
	 *
	 *	if(TVServiceAPI::ServiceDataAux(PROFILE_TYPE_MAIN, 0)-> CheckAudioDescription(serviceId, exists) > 0)
	 *	{
	 *		//Do something
	 *	}
	 *	@endverbatim
	 */
	virtual int CheckAudioDescription(_IN_ const TCServiceId& serviceId, _OUT_ bool& exists) = 0;

	/**
	 * @brief Gets number of audio description information for specified service.
	 * @param [in] serviceId Service id.
	 * @param [out] size Audio description informations size.
	 * @return Returns 1 if audio description size was successfully obtained, otherwise returns 0.
	 * @return When calling method failed returns -1.
	 *
	 *	@paragraph <Example>
	 *	This example will get size of audio description information for serviceId == 848824369157121 and tvsHandle(PROFILE_TYPE_MAIN, 0).
	 *	
	 *	@verbatim
	 *	TCServiceId serviceId = 848824369157121;
	 *	unsigned int audioDescSize;
	 *
	 *	if(TVServiceAPI::ServiceDataAux(PROFILE_TYPE_MAIN, 0)->SizeOfAudioDescription(serviceId, audioDescSize) > 0)
	 *	{
	 *		//Do something
	 *	}
	 *	@endverbatim
	 */
	virtual int SizeOfAudioDescription(_IN_ const TCServiceId& serviceId, _OUT_ unsigned int& size) = 0;

	/**
	 * @brief Get audio description information for specified service.
	 * @param [in] serviceId Service id.
	 * @param [in] index Index of requested audio description.
	 * @param [out] audioDesc Audio description information.
	 * @return Returns 1 if audio description info was successfully obtained, otherwise returns 0.
	 * @return When calling method failed returns -1.
	 *
	 *	@paragraph <Example>
	 *	This example will get first available audio description information for serviceId == 848824369157121 and tvsHandle(PROFILE_TYPE_MAIN, 0).
	 *	
	 *	@verbatim
	 *	TCServiceId serviceId = 848824369157121;
	 *	TSAudio audio;
	 *	if(TVServiceAPI::ServiceDataAux(PROFILE_TYPE_MAIN, 0)->GetAudioDescription(serviceId, 0, audio) > 0)
	 *	{
	 *		//Do something with return audio description
	 *	}
	 *	@endverbatim
	 */
	virtual int GetAudioDescription(_IN_ const TCServiceId& serviceId, _IN_ unsigned int index, _OUT_ TSAudio& audioDesc) = 0;

	/**
	 * @brief Gets number of TTX for specified service.
	 * @param [in] serviceId Service id.
	 * @param [out] size TTX size.
	 * @return Returns 1 if TTX size was successfully obtained, otherwise returns 0.
	 * @return When calling method failed returns -1.
	 *
	 *	@paragraph <Example>
	 *	This example will get size of TTX for serviceId == 848824369157121 and tvsHandle(PROFILE_TYPE_MAIN, 0).
	 *	
	 *	@verbatim
	 *	TCServiceId serviceId = 848824369157121;
	 *	unsigned int size = 0;
	 *
	 *	if(TVServiceAPI::ServiceDataAux(PROFILE_TYPE_MAIN, 0)->SizeOfTTX(serviceId, size) > 0)
	 *	{
	 *		//Do something
	 *	}
	 *	@endverbatim
	 */
	virtual int SizeOfTTX(_IN_ const TCServiceId& serviceId, _OUT_ unsigned int& size) = 0;

	/**
	 * @brief Gets TTX information for specified service.
	 * @param [in] serviceId Service id.
	 * @param [in] index Index of requested TTX.
	 * @param [out] ttx TTX information.
	 * @return Returns 1 if TTX info was successfully obtained, otherwise returns 0.
	 * @return When calling method failed returns -1.
	 *
	 *	@paragraph <Example>
	 *	This example will get first available TTX information for serviceId == 848824369157121 and tvsHandle(PROFILE_TYPE_MAIN, 0).
	 *	
	 *	@verbatim
	 *	TCServiceId serviceId = 848824369157121;
	 *	TSTTX ttx;
	 *	if(TVServiceAPI::ServiceDataAux(PROFILE_TYPE_MAIN, 0)->GetTTX(serviceId, 0, ttx) > 0)
	 *	{
	 *		//Do something with return ttx
	 *	}
	 *	@endverbatim
	 */
	virtual int GetTTX(_IN_ const TCServiceId& serviceId, _IN_ unsigned int index, _OUT_ TSTTX& ttx) = 0;

	/**
	 * @brief Gets number of HybridSBT for specified service.
	 * @param [in] serviceId Service id.
	 * @param [out] size HybridSBT size.
	 * @return Returns 1 if HybridSBT size was successfully obtained, otherwise returns 0.
	 * @return When calling method failed returns -1.
	 *
	 *	@paragraph <Example>
	 *	This example will get size of HybridSBT for serviceId == 848824369157121 and tvsHandle(PROFILE_TYPE_MAIN, 0).
	 *	
	 *	@verbatim
	 *	TCServiceId serviceId = 848824369157121;
	 *	unsigned int size = 0;
	 *
	 *	if(TVServiceAPI::ServiceDataAux(PROFILE_TYPE_MAIN, 0)->SizeOfHybridSBT(serviceId, size) > 0)
	 *	{
	 *		//Do something
	 *	}
	 *	@endverbatim
	 */
	virtual int SizeOfHybridSBT(_IN_ const TCServiceId& serviceId, _OUT_ unsigned int& size) = 0;

	/**
	 * @brief Gets HybridSBT information for specified service.
	 * remark If passed index == 0, then preferred HybridSBT is returned.
	 * @param [in] serviceId Service id.
	 * @param [in] index Index of requested HybridSBT.
	 * @param [out] language HybridSBT language.
	 * @param [out] hybridSbt HybridSBT information.
	 * @return Returns 1 if HybridSBT info was successfully obtained, otherwise returns 0.
	 * @return When calling method failed returns -1.
	 *
	 *	@paragraph <Example>
	 *	This example will get first available HybridSBT information for serviceId == 848824369157121 and tvsHandle(PROFILE_TYPE_MAIN, 0).
	 *	
	 *	@verbatim
	 *	TCServiceId serviceId = 848824369157121;
	 *	ELanguageCode language = LANGUAGE_CODE_UNKNOWN;
	 *	TSHybridSBT hybridSbt;
	 *	if(TVServiceAPI::ServiceDataAux(PROFILE_TYPE_MAIN, 0)->GetHybridSBT(serviceId, 1, language, hybridSbt) > 0)
	 *	{
	 *		//Do something with return hybridSbt
	 *	}
	 *	@endverbatim
	 */
	virtual int GetHybridSBT(_IN_ const TCServiceId& serviceId, _IN_ unsigned int index, _OUT_ ELanguageCode& language, _OUT_ TSHybridSBT& hybridSbt) = 0;

	/**
	 * @brief Gets Component information for specified service and component pid.
	 * @param [in] serviceId Service id.
	 * @param [in] pid Pid of requested Component.
	 * @param [out] component Component information.
	 * @return Returns 1 if specified component existed, otherwise returns 0.
	 * @return When calling method failed returns -1.
	 *
	 *	@paragraph <Example>
	 *	This example will get component information, with pid == 31, for serviceId == 848824369157121 and tvsHandle(PROFILE_TYPE_MAIN, 0).
	 *	
	 *	@verbatim
	 *	TCServiceId serviceId = 848824369157121;
	 *	TSComponent component;
	 *	if(TVServiceAPI::ServiceDataAux(PROFILE_TYPE_MAIN, 0)->GetComponent(serviceId, 31, component) > 0)
	 *	{
	 *		//Do something with return component
	 *	}
	 *	@endverbatim
	 */
	virtual int GetComponentByPid(_IN_ const TCServiceId& serviceId, _IN_ unsigned short pid, _OUT_ TSComponent& component) = 0;

	/**
	 * @brief Gets Component information for specified service and component tag.
	 * @param [in] serviceId Service id.
	 * @param [in] tag Tag of requested Component.
	 * @param [out] component Component information.
	 * @return Returns 1 if specified component existed, otherwise returns 0.
	 * @return When calling method failed returns -1.
	 *
	 *	@paragraph <Example>
	 *	This example will get component information, with tag == 31, for serviceId == 848824369157121 and tvsHandle(PROFILE_TYPE_MAIN, 0).
	 *	
	 *	@verbatim
	 *	TCServiceId serviceId = 848824369157121;
	 *	TSComponent component;
	 *	if(TVServiceAPI::ServiceDataAux(PROFILE_TYPE_MAIN, 0)->GetComponent(serviceId, 31, component) > 0)
	 *	{
	 *		//Do something with return component
	 *	}
	 *	@endverbatim
	 */
	virtual int GetComponentByTag(_IN_ const TCServiceId& serviceId, _IN_ unsigned char tag, _OUT_ TSComponent& component) = 0;

	/**
	 * @brief Gets All Components information for specified service.
	 * @param [in] serviceId Service id.
	 * @param [out] components List of all components available for specified service.
	 * @return Returns 1 if specified component existed, otherwise returns 0.
	 * @return When calling method failed returns -1.
	 *
	 *	@paragraph <Example>
	 *	This example will get component information for serviceId == 848824369157121 and tvsHandle(PROFILE_TYPE_MAIN, 0).
	 *	
	 *	@verbatim
	 *	TCServiceId serviceId = 848824369157121;
	 *	std::vector<TSComponent> components;
	 *	if(TVServiceAPI::ServiceDataAux(PROFILE_TYPE_MAIN, 0)->GetAllComponents(serviceId, components) > 0)
	 *	{
	 *		//Do something with return components
	 *	}
	 *	@endverbatim
	 */
	virtual int GetAllComponents(_IN_ const TCServiceId& serviceId, _OUT_ std::vector<TSComponent>& components) = 0;

	/**
	 * @brief Checks if exists hybrid subtitles for hard of hearing for given service.
	 * @param [in] serviceId Service id.
	 * @param [out] exists Result of checking: TRUE if exists, FALSE otherwise
	 * @return Returns 1.
	 * @return When calling method failed returns -1.
	 *
	 *	@paragraph <Example>
	 *	This example will check HoH SBT for serviceId == 848824369157121 and tvsHandle(PROFILE_TYPE_MAIN, 0).
	 *	
	 *	@verbatim
	 *	TCServiceId serviceId = 848824369157121;
	 *	bool result;
	 *
	 *	if(TVServiceAPI::ServiceDataAux(PROFILE_TYPE_MAIN, 0)->CheckHardOfHearingSBT(serviceId, result) > 0)
	 *	{
	 *		//Do something with result value
	 *	}
	 *	@endverbatim
	 */
	virtual int CheckHardOfHearingSBT( _IN_ const TCServiceId& serviceId, _OUT_ bool& exists ) = 0;

	/**
	 * @brief Returns number of ISDB text for given service.
	 * @param [in] serviceId Service id.
	 * @param [in] mode ISDB text type.
	 * @param [in] size Number of ISDB text of specified type.
	 * @return Returns true if number of ISDB text was successfully get, otherwise returns false.
	 *
	 *	@paragraph <Example>
	 *	This example will get number of ISDB text for serviceId == 848824369157121, CAPTION mode and tvsHandle(PROFILE_TYPE_MAIN, 0).
	 *	
	 *	@verbatim
	 *	TCServiceId serviceId = 848824369157121;
	 *	EISDBTextType mode = ISDB_TEXT_MODE_CAPTION;
	 *	unsigned int size;
	 *	if(TVServiceAPI::ServiceDataAux(PROFILE_TYPE_MAIN, 0)->SizeOfISDBText(serviceId, mode, size) > 0)
	 *	{
	 *		//Do something with returned text
	 *	}
	 *	@endverbatim
	 */
	virtual int SizeOfISDBText(_IN_ const TCServiceId& serviceId, _IN_ EISDBTextType mode, _OUT_ unsigned int& size) = 0;


	/**
	 * @brief Returns ISDB text for given service.
	 * @param [in] serviceId Service id.
	 * @param [in] mode ISDB text type.
	 * @param [in] index Index of the ISDB text.
	 * @param [out] isdbText Found ISDB text.
	 * @return Returns true if ISDB text was found for given index, otherwise returns false.
	 *
	 *	@paragraph <Example>
	 *	This example will get ISDB text for serviceId == 848824369157121, CAPTION mode, index==5 and tvsHandle(PROFILE_TYPE_MAIN, 0).
	 *	
	 *	@verbatim
	 *	TCServiceId serviceId = 848824369157121;
	 *	EISDBTextType mode = ISDB_TEXT_MODE_CAPTION;
	 *	unsigned int index = 5;
	 *	TSISDBText isdbText;
	 *	if(TVServiceAPI::ServiceDataAux(PROFILE_TYPE_MAIN, 0)->GetISDBText(serviceId, mode, index, isdbText) > 0)
	 *	{
	 *		//Do something with returned text
	 *	}
	 *	@endverbatim
	 */
	virtual int GetISDBText(_IN_ const TCServiceId& serviceId, _IN_ EISDBTextType mode, _IN_ unsigned int index, _OUT_ TSISDBText& isdbText) = 0;

	/**
	 * @brief Gets preferred subtitle for specified service.
	 * @param [in] serviceId Service id for which information should be acquired.
	 * @param [out] language Subtitle language code.
	 * @param [out] hybridSbt Subtitle information.
	 * @return Returns 1 if subtitle info was successfully obtained, otherwise returns 0.
	 * @return When calling method failed returns -1.
	 *
	 *	@paragraph <Example>
	 *	This example will get preferred subtitle information for serviceId == 848824369157121 and tvsHandle(PROFILE_TYPE_MAIN, 0).
	 *	
	 *	@verbatim
	 *	TCServiceId serviceId = 848824369157121;
	 *	ELanguageCode language;
	 *	TSHybridSBT hybridSbt;
	 *	if(TVServiceAPI::ServiceDataAux(PROFILE_TYPE_MAIN, 0)->GetPreferredHybridSBT(serviceId, language, hybridSbt) > 0)
	 *	{
	 *		//Do something with return hybridSbt
	 *	}
	 *	@endverbatim
	 */
	virtual int GetPreferredHybridSBT(_IN_ const TCServiceId& serviceId, _OUT_ ELanguageCode& language, _OUT_ TSHybridSBT& hybridSbt) = 0;

	/**
	 * @brief Gets if return channel access is allowed for given service ID.
	 * @remarks MHEG and Freesat related method.
	 * @param [in] serviceId ID of a service to be checked.
	 * @param [out] result TRUE if return channel access is allowed, FALSE otherwise.
	 * @return Returns 1 if information was successfully obtained, otherwise returns 0.
	 * @return When calling method failed returns -1.
	 *
	 *	@paragraph <Example>
	 *	This example will check if there is allowed return channel access for serviceId == 848824369157121 and tvsHandle(PROFILE_TYPE_MAIN, 0).
	 *	
	 *	@verbatim
	 *	TCServiceId serviceId = 848824369157121;
	 *	bool result;
	 *	if(TVServiceAPI::ServiceDataAux(PROFILE_TYPE_MAIN, 0)->ReturnChannelAccessAllowed(serviceId, result) > 0)
	 *	{
	 *		//Do something with returned result value
	 *	}
	 *	@endverbatim
	 */
	virtual int ReturnChannelAccessAllowed(const _IN_ TCServiceId& serviceId, _OUT_ bool& result) = 0;

	/**
	 * @brief Gets information if it is allowed to start MHEG data service for given service ID.
	 * @remarks MHEG and Freesat related method.
	 * @param [in] serviceId ID of a service to be checked.
	 * @param [out] result TRUE if it is allowed, FALSE if MHEG data service should be blocked
	 * @return Returns 1 if information was successfully obtained, otherwise returns 0.
	 * @return When calling method failed returns -1.
	 *
	 *	@paragraph <Example>
	 *	This example will check if we should start MHEG data service for serviceId == 848824369157121 and tvsHandle(PROFILE_TYPE_MAIN, 0).
	 *	
	 *	@verbatim
	 *	TCServiceId serviceId = 848824369157121;
	 *	bool result;
	 *	if(TVServiceAPI::ServiceDataAux(PROFILE_TYPE_MAIN, 0)->InteractiveServiceAllowed(serviceId, result) > 0)
	 *	{
	 *		//Do something with returned result value
	 *	}
	 *	@endverbatim
	 */
	virtual int InteractiveServiceAllowed(const _IN_ TCServiceId& serviceId, _OUT_ bool& result) = 0;

};



#endif // _ISERVICEDATAAUX_H_

