/** 
 * @file IAVControl.h
 * @brief Application interface for controlling audio.
 *
 * Copyright 2013 by Samsung Electronics, Inc.,
 * 
 * This software is the confidential and proprietary information
 * of Samsung Electronics, Inc. ("Confidential Information"). You
 * shall not disclose such Confidential Information and shall use
 * it only in accordance with the terms of the license agreement
 * you entered into with Samsung.
 */


#ifndef _IAVCONTROL_H_
#define _IAVCONTROL_H_

#include <vector>
#include <list>

#include "MarshallingMarks.h"
#include "AVControlDataType.h"
#include "SOSpecDataType.h"
#include "ServiceDataType.h"
#include "DataControlDataType.h"
#include "ServiceData.h"

class IAVControl
{
protected:
	virtual ~IAVControl(){};

public:

	/**
	 * @brief Gets current audio informations related to current service.
	 * @param [out] langCode Language of the current audio.
	 * @param [out] index Index of the current audio. Current service can have more than one audio.
	 * @return Returns 1 if specified audio information for current service is available, otherwise returns 0.
	 * @return When calling method failed returns -1.
	 *
	 *	@paragraph <Example>
	 *	This example will get current audio information.
	 *	
	 *	@verbatim
	 *	IAVControl* pAVControl;
	 *	TVServiceAPI::CreateAVControl(PROFILE_TYPE_MAIN, 0, &pAVControl);
	 *	ELanguageCode langCode;
	 *	int audioIndex;
	 *	if(pAVControl->GetCurrentAudioInfo(langCode, audioIndex) > 0)
	 *	{
	 *		//Do something with returned audio information
	 *	}
	 *	@endverbatim
	 */
	virtual int GetCurrentAudioInfo(_OUT_ ELanguageCode& langCode, _OUT_ int& index) = 0;

	/**
	 * @brief Sets audio for current service.
	 * @param [in] index Index of the current audio. Current service can have more than one audio.
	 * @return Returns 1 if specified audio information successfully set for current service, otherwise return 0.
	 * @Return When calling method failed returns -1.
	 *
	 *	@paragraph <Example>
	 *	This example will set audio information for current service.
	 *	
	 *	@verbatim
	 *	IAVControl* pAVControl;
	 *	TVServiceAPI::CreateAVControl(PROFILE_TYPE_MAIN, 0, &pAVControl);
	 *	if(pAVControl->SetCurrentAudioByIndex(0) > 0)
	 *	{
	 *		//Do something when operation successful
	 *	}
	 *	@endverbatim
	 */
	virtual int SetCurrentAudioByIndex(_IN_ int index) = 0;

	/**
	 * @brief Sets new audio encode type. This method can invoke change of current audio.
	 * @remark Only when isPreferred == true the preferred audio format is changed.
	 * @param [in] encodeType Audio encode type.
	 * @param [in] isPreferred Differenciate current and preferred audio format.
	 * @return Returns 1 if current audio is changed to preferred one, otherwise return 0.
	 * @Return When calling method failed returns -1.
	 *
	 *	@paragraph <Example>
	 *	This example will set current audio, which encode type == AUDIO_ENCODE_TYPE_AAC.
	 *	
	 *	@verbatim
	 *	IAVControl* pAVControl;
	 *	TVServiceAPI::CreateAVControl(PROFILE_TYPE_MAIN, 0, &pAVControl);
	 *  EAudioEncodeType encodeType = AUDIO_ENCODE_TYPE_AAC;
	 *	if(pAVControl->SetAudioFormat( encodeType ) > 0)
	 *	{
	 *		//Do something when current audio meets the criteria.
	 *	}
	 *	@endverbatim
	 */
	virtual int SetAudioFormat(_IN_ EAudioEncodeType encodeType, _IN_ bool isPreferred = true) = 0;

	/* This method shall be removed on 01.12.2014 */
	virtual int GetAudioFormat(_OUT_ EAudioEncodeType& encodeType, _IN_ bool /* not used */) { return GetAudioFormat( encodeType ); }

	/**
	 * @brief Gets current audio encode type.
	 * @param [out] encodeType Audio encode type.
	 * @return Returns 1 if audio format was obtained, otherwise return 0.
	 * @Return When calling method failed returns -1.
	 *
	 *	@paragraph <Example>
	 *	This example will get current audio format (EAudioEncodeType value).
	 *	
	 *	@verbatim
	 *	IAVControl* pAVControl;
	 *	TVServiceAPI::CreateAVControl(PROFILE_TYPE_MAIN, 0, &pAVControl);
	 *  EAudioEncodeType encodeType = AUDIO_ENCODE_UNKNOWN;
	 *	if(pAVControl->GetAudioFormat( encodeType ) > 0)
	 *	{
	 *		//Do something with return value.
	 *	}
	 *	@endverbatim
	 */
	virtual int GetAudioFormat(_OUT_ EAudioEncodeType& encodeType) = 0;
	
	/**
	 * @brief Gets preferred audio of the current service.
	 * @param [out] index Index of the preferred audio.
	 * @param [out] audio Audio of the preferred audio.
	 * @return Returns 1 if preferred audio information for current service was retrieved, otherwise returns 0.
	 * @return When calling method failed returns -1.
	 *
	 *	@paragraph <Example>
	 *	This example will get preferred audio information.
	 *	
	 *	@verbatim
	 *	IAVControl* pAVControl;
	 *	TVServiceAPI::CreateAVControl(PROFILE_TYPE_MAIN, 0, &pAVControl);
	 *	int index;
	 *	TSAudio audio
	 *	if(pAVControl->GetPreferredAudio(index, audio) > 0)
	 *	{
	 *		//Do something with returned audio information
	 *	}
	 *	@endverbatim
	 */
	virtual int GetPreferredAudio(_OUT_ unsigned int& index, _OUT_ TSAudio& audio) = 0;

	/**
	 * @brief Gets AV status.
	 * @param [out] avStatus AV status type.
	 * @return Returns 1 if AV status is available, otherwise return 0.
	 * @Return When calling method failed returns -1.
	 *
	 *	@paragraph <Example>
	 *	This example will get AV status.
	 *	
	 *	@verbatim
	 *	IAVControl* pAVControl;
	 *	TVServiceAPI::CreateAVControl(PROFILE_TYPE_MAIN, 0, &pAVControl);
	 *	EAVStatus avStatus;
	 *	if(pAVControl->GetAVStatus(avStatus) > 0)
	 *	{
	 *		//Do something when operation successful
	 *	}
	 *	@endverbatim
	 */
	virtual int GetAVStatus(_OUT_ EAVStatus& avStatus) = 0;

	/**
	 * @brief Gets Audio lock value.
	 * @param [out] flag Audio lock flag.
	 * @return Returns 1 if data were acquired, otherwise return 0.
	 * @Return When calling method failed returns -1.
	 *
	 *	@paragraph <Example>
	 *	This example will get Audio lock flag.
	 *	
	 *	@verbatim
	 *	IAVControl* pAVControl;
	 *	TVServiceAPI::CreateAVControl(PROFILE_TYPE_MAIN, 0, &pAVControl);
	 *	bool flag;
	 *	if(pAVControl->FlagAudioLock(flag) > 0)
	 *	{
	 *		//Do something when operation successful
	 *	}
	 *	@endverbatim
	 */
	virtual int FlagAudioLock(_OUT_ bool& flag) = 0;

	/**
	 * @brief Gets Resolution infomation
	 * @param [out] resolution Resolution.
	 * @param [out] resolutionInfo Resolution information.
	 * @return Returns 0 if acquired data, otherwise return -1.
	 *
	 *	@paragraph <Example>
	 *	
	 *	@verbatim
	 *	IAVControl* pAVControl;
	 *	TVServiceAPI::CreateAVControl(PROFILE_TYPE_MAIN, 0, &pAVControl);
	 *	EResolution resolutionEnum;
	 *	TSResolution resolutionInfo;
	 *	if(pAVControl->GetResolution(TVS_RESOLUTION_1080I,resolutionInfo) == 0)
	 *	{
	 *		//Do something when operation successful
	 *	}
	 *	@endverbatim
	 */

	virtual int GetResolution(_OUT_ EResolution& resolution, _OUT_ TSResolution& resolutionInfo) = 0;

	/**
	 * @brief Sets Resolution infomation
	 * @param [in] resolution Resolution.
	 * @param [in] resolutionInfo Resolution information.
	 * @return Returns 0 if resolution set with success, otherwise return -1.
	 *
	 *	@paragraph <Example>
	 *	
	 *	@verbatim
	 *	IAVControl* pAVControl;
	 *	TVServiceAPI::CreateAVControl(PROFILE_TYPE_MAIN, 0, &pAVControl);
	 *	EResolution resolutionEnum;
	 *	TSResolution resolutionInfo;
	 *	if(pAVControl->SetResolution(TVS_RESOLUTION_1080I,resolutionInfo) == 0)
	 *	{
	 *		//Do something when operation successful
	 *	}
	 *	@endverbatim
	 */
	virtual int SetResolution(_IN_ EResolution resolution, _IN_ const TSResolution& resolutionInfo) = 0;

	/**
	 * @brief Locks/unlocks current service.
	 * @param [in] mode Defines type of operation.
	 * @param [in] startTime Time when service is locked.
	 * @param [in] endTime Time when service is unlocked.
	 * @return Returns 1 if current service is locked/unlocked successfully, otherwise return 0.
	 * @return When calling method failed returns -1.
	 * @remark Start and stop time are set only when mode == LOCKED_MODE_TIME.
	 *
	 *	@paragraph <Example>
	 *	This example will lock current service.
	 *	
	 *	@verbatim
	 *	IAVControl* pAVControl;
	 *	TVServiceAPI::CreateAVControl(PROFILE_TYPE_MAIN, 0, &pAVControl);
	 *	unsigned short startTime = getTime();
	 *	unsigned short startTime = getTime()+3600;
	 *	if(pAVControl->SetServiceLock(LOCKED_MODE_NORMAL, startTime, endTime) > 0)
	 *	{
	 *		//Do something when operation successful
	 *	}
	 *	@endverbatim
	 */
	virtual int SetServiceLock(_IN_ ELockedMode mode, _IN_ unsigned short startTime, _IN_ unsigned short endTime) = 0;

	/**
	 * @brief Get color system of current window
	 * @param [out] Mode - mode of color system, please see enueration EChannelColorSystem.<br>
				typedef enum
				{
					SYSTEM_MIN,
					SYSTEM_MANUAL = SYSTEM_MIN,
					SYSTEM_AUTO,
					SYSTEM_MAX = SYSTEM_AUTO,
				}EChannelColorSystem; 
	* @param [out] Val  - enum of color system , please see enueration EChannelColor.<br>
				typedef enum
				{
					COLOR_MIN,
					COLOR_PAL = COLOR_MIN,//! color system PAL
					COLOR_SECAM,//! color system SECAM
					COLOR_NTSC4_43,//! color system NTSC4.43
					COLOR_NTSC3_58,//! color system NTSC3.58
					COLOR_PAL_M,//! for Brazil
					COLOR_PAL_N,//! for Brazil
					COLOR_AUTO,//! color system auto -manual store에서 auto 로 설정시 사용.
					COLOR_MAX = COLOR_AUTO, //! color system maximum value
				}EChannelColor; 
	 * @return true if color system get properly. false if not.
	 */
	virtual int GetColorSystem(_OUT_  EChannelColorSystem& Mode , _OUT_  EChannelColor& Val) = 0;

	/**
	 * @brief Set color system of current window
	 * @param [in] Mode - mode of color system, please see enueration EChannelColorSystem.<br>
				typedef enum
				{
					SYSTEM_MIN,
					SYSTEM_MANUAL = SYSTEM_MIN,
					SYSTEM_AUTO,
					SYSTEM_MAX = SYSTEM_AUTO,
				}EChannelColorSystem; 
	* @param [in] Val  - enum of color system , please see enueration EChannelColor.<br>
				typedef enum
				{
					COLOR_MIN,
					COLOR_PAL = COLOR_MIN,//! color system PAL
					COLOR_SECAM,//! color system SECAM
					COLOR_NTSC4_43,//! color system NTSC4.43
					COLOR_NTSC3_58,//! color system NTSC3.58
					COLOR_PAL_M,//! for Brazil
					COLOR_PAL_N,//! for Brazil
					COLOR_AUTO,//! color system auto -manual store에서 auto 로 설정시 사용.
					COLOR_MAX = COLOR_AUTO, //! color system maximum value
				}EChannelColor; 
	 * @return true if color system set properly. false if not.
	 */
	virtual int SetColorSystem(_IN_  EChannelColorSystem Mode , _IN_  EChannelColor Val) = 0;

	/**
	 * @brief Get color system of current window
	 * @param [out] Mode - mode of color system, please see enueration EChannelSoundSystem.<br>
				typedef enum
				{
					SOUND_SYSTEM_MIN,
					SOUND_SYSTEM_MANUAL = SOUND_SYSTEM_MIN,
					SOUND_SYSTEM_AUTO,
					SOUND_SYSTEM_MAX = SOUND_SYSTEM_AUTO,
				}EChannelSoundSystem; 
	* @param [out] Val  - enum of sound system , please see enueration EChannelColor.<br>
				typedef enum
				{
					SOUND_UNDEFINED = -1,
					SOUND_MIN,
					SOUND_AUTO = SOUND_MIN,//! sound system AUTO - auto store에서 사용.
					SOUND_B_G,//! sound system B/G
					SOUND_I,//! sound system I
					SOUND_D_K,//! sound system D/k
					SOUND_M,//! sound system M
					SOUND_L,//! sound system L
					SOUND_MAX = SOUND_L, //! sound system maximum value
				}EChannelSound; 
	 * @return true if color system get properly. false if not.
	 */
	virtual int GetSoundSystem(_OUT_  EChannelSoundSystem& Mode , _OUT_  EChannelSound& Val) = 0;

	/**
	 * @brief Set color system of current window
	 * @param [in] Mode - mode of color system, please see enueration EChannelSoundSystem.<br>
				typedef enum
				{
					SOUND_SYSTEM_MIN,
					SOUND_SYSTEM_MANUAL = SOUND_SYSTEM_MIN,
					SOUND_SYSTEM_AUTO,
					SOUND_SYSTEM_MAX = SOUND_SYSTEM_AUTO,
				}EChannelSoundSystem; 
	* @param [in] Val  - enum of sound system , please see enueration EChannelSound.<br>
				typedef enum
				{
					SOUND_UNDEFINED = -1,
					SOUND_MIN,
					SOUND_AUTO = SOUND_MIN,//! sound system AUTO - auto store에서 사용.
					SOUND_B_G,//! sound system B/G
					SOUND_I,//! sound system I
					SOUND_D_K,//! sound system D/k
					SOUND_M,//! sound system M
					SOUND_L,//! sound system L
					SOUND_MAX = SOUND_L, //! sound system maximum value
				}EChannelSound; 
	 * @return true if sound system set properly. false if not.
	 */
	virtual int SetSoundSystem(_IN_  EChannelSoundSystem Mode , _IN_  EChannelSound Val) = 0;
	

	/**
	 * @brief mute video of current service.
	 * @param [in] on/off of video.
	 * @return Returns 1 if current service is mute video successfully.
	 * @return When calling method failed returns false.
	 *
	 *	@paragraph <Example>
	 *	This example will be mute video about current service.
	 *	The video mute which is set up as this API in the same screen is maintained in the source change.
	 *	If any app wishes to show TVS screen, The call that "MuteVideo(false)" should be called when the app launching.
	 *	
	 *	@verbatim
	 *	IAVControl* pAVControl;
	 *	TVServiceAPI::CreateAVControl(PROFILE_TYPE_MAIN, 0, &pAVControl);
	 *	
	 *	if(pAVControl->MuteVideo(true or false) > 0)
	 *	{
	 *		//Do something when operation successful
	 *	}
	 *	@endverbatim
	 */
	virtual int MuteVideo(_IN_ int onoff) = 0;
	
	/**
	 * @brief mute audio of current service.
	 * @param [in] on/off of audio.
	 * @return Returns 1 if current service is mute audio successfully.
	 * @return When calling method failed returns false.
	 *
	 *	@paragraph <Example>
	 *	This example will be mute audio about current service.
	 *	The video mute which is set up as this API in the same screen is maintained in the source change.
	 *	If any app wishes to out TVS sound, The call that "MuteAudio(false)" should be called when the app launching.
	 *	
	 *	@verbatim
	 *	IAVControl* pAVControl;
	 *	TVServiceAPI::CreateAVControl(PROFILE_TYPE_MAIN, 0, &pAVControl);
	 *	
	 *	if(pAVControl->MuteAudio(true or false) > 0)
	 *	{
	 *		//Do something when operation successful
	 *	}
	 *	@endverbatim
	 */
	virtual int MuteAudio(_IN_ int onoff) = 0;


	/**
	 * @brief mute video of current service.
	 * @param [in] onoff on/off of video.
	 * @param [in] muteMode it is used to distinguish different types of mute
	 * @return Returns 1 if current service is mute video successfully.
	 * @return When calling method failed returns false.
	 *
	 *	@paragraph <Example>
	 *	This example will be mute video about current service.
	 *	The video mute which is set up as this API in the same screen is maintained in the source change.
	 *	If any app wishes to show TVS screen, The call that "MuteVideo(false)" should be called when the app launching.
	 *	
	 *	@verbatim
	 *	IAVControl* pAVControl;
	 *	TVServiceAPI::CreateAVControl(PROFILE_TYPE_MAIN, 0, &pAVControl);
	 *	
	 *	if(pAVControl->MuteVideo(true or false) > 0)
	 *	{
	 *		//Do something when operation successful
	 *	}
	 *	@endverbatim
	 */
	virtual int MuteVideo(_IN_ int onoff, _IN_ EMuteMode muteMode) = 0;
	
	/**
	 * @brief mute audio of current service.
	 * @param [in] onoff on/off of video.
	 * @param [in] muteMode it is used to distinguish different types of mute
	 * @return Returns 1 if current service is mute audio successfully.
	 * @return When calling method failed returns false.
	 *
	 *	@paragraph <Example>
	 *	This example will be mute audio about current service.
	 *	The video mute which is set up as this API in the same screen is maintained in the source change.
	 *	If any app wishes to out TVS sound, The call that "MuteAudio(false)" should be called when the app launching.
	 *	
	 *	@verbatim
	 *	IAVControl* pAVControl;
	 *	TVServiceAPI::CreateAVControl(PROFILE_TYPE_MAIN, 0, &pAVControl);
	 *	
	 *	if(pAVControl->MuteAudio(true or false) > 0)
	 *	{
	 *		//Do something when operation successful
	 *	}
	 *	@endverbatim
	 */
	virtual int MuteAudio(_IN_ int onoff, _IN_ EMuteMode muteMode) = 0;


	/**
	 * @brief check whether input mts can set
	 * @param [in] mode - analog mts mode
	 * @param [out] bCheck - true : possible , false : impossible
 	 * @return Returns 1 
	 * @return When calling method failed returns false.
	 *
	 *	@paragraph <Example>
	 *	This example will be check whether MULTI_SOUND_MONO can be set.
	 *	
	 *	@verbatim
	 *	IAVControl* pAVControl;
	 *    bool bCheck = false;
	 *	TVServiceAPI::CreateAVControl(PROFILE_TYPE_MAIN, 0, &pAVControl);
	 *	
	 *	if(pAVControl->CheckAnalogMTS(MULTI_SOUND_MONO , bCheck) > 0)
	 *	{
	 *		//Do something when operation successful
	 *	}
	 *	@endverbatim
	 */
	virtual int CheckAnalogMTS(_IN_ EMultiSoundMode mode , _OUT_ bool& bCheck) = 0;

	virtual int SetAnalogMTS(_IN_ EMultiSoundMode userSetMod, bool isPreview = false) = 0;

	virtual int GetAnalogMTS(_OUT_ EMultiSoundMode& userSetMod) = 0;
	
	/** 
	 * @brief Get AnalogMTS mode by current signal.
	 * @param [out] mode MTS mode by current signal
	 * @return Returns 1 if dual sound existed for current service, otherwise returns 0.
	 * @return When calling method failed returns -1.
	 * 
	 *	@paragraph <Example> 
	 *	This example will return Analog MTS sound mode.
	 *	
	 *	@verbatim 
	 *	IAVControl* pAVControl; 
	 *	   
	 *	TVServiceAPI::CreateAVControl(DEFAULT_PROFILE_TYPE, DEFAULT_SCREEN_ID, &pAVControl); 
	 *	EMultiSoundMode current_mode = MULTI_SOUND_UNKNOWN;
	 *	if(pAVControl->GetAnalogMTSBySignal( current_mode  ) > 0) 
	 *	{
	 *		// value returned
	 *	}
	 *	@endverbatim 
	 */
	virtual int GetAnalogMTSBySignal(_OUT_ EMultiSoundMode& mode) = 0;

	virtual int ChangeAudio(_IN_ const TSAudio& audio, _IN_ const TCServiceId& serviceId = INVALID) = 0;

	virtual int ChangeVideo(_IN_ const TSVideo& video) = 0;

	/**
	 * @brief Releases given component distinguished by type
	 * @param [in] compType Component type.
	 * @return Returns 1 if successfully released component type, otherwise returns 0.
	 * @return When calling method failed returns -1.
	 *
	 *	@paragraph <Example>
	 *	This example will release COMPONENT_TYPE_VIDEO for MAIN profile type and screenId = 0.
	 *	
	 *	@verbatim
	 *	IAVControl* pAVControl;
	 *	TVServiceAPI::CreateAVControl(PROFILE_TYPE_MAIN, 0, &pAVControl);
	 *	
	 *	if(pAVControl->ReleaseComponent(COMPONENT_TYPE_VIDEO) > 0)
	 *	{
	 *		//Do something when operation successful
	 *	}
	 *	@endverbatim
	 */
	virtual int ReleaseComponent(_IN_ EComponentType compType) = 0;

	/**
	 * @brief Reserves given component distinguished by type
	 * @param [in] compType Component type.
	 * @return Returns 1.
	 * @return When calling method failed returns -1.
	 *
	 *	@paragraph <Example>
	 *	This example will reserve COMPONENT_TYPE_VIDEO for MAIN profile type and screenId = 0.
	 *	
	 *	@verbatim
	 *	IAVControl* pAVControl;
	 *	TVServiceAPI::CreateAVControl(PROFILE_TYPE_MAIN, 0, &pAVControl);
	 *	
	 *	if(pAVControl->ReserveComponent(COMPONENT_TYPE_VIDEO) > 0)
	 *	{
	 *		//Do something when operation successful
	 *	}
	 *	@endverbatim
	 */
	virtual int ReserveComponent(_IN_ EComponentType compType) = 0;

	/**
	 * @brief Changes audio description mode on/off.
	 * @param [in] onoff On/Off for Audio Diescription
	 * @return Returns 1 if the mode is changed successfully.
	 * @return When calling method failed returns false.
	 *
	 * @paragraph <Example>
	 * This example will be turn on audio description.
	 * 
	 * @verbatim
	 * IAVControl* pAVControl;
	 * TVServiceAPI::CreateAVControl(PROFILE_TYPE_MAIN, 0, &pAVControl);
	 * 
	 * if(pAVControl->SetAudioDescriptionOnOff(true) > 0)
	 * {
	 *  //Do something when operation successful
	 * }
	 * @endverbatim
	 */
	virtual int SetAudioDescriptionOnOff(_IN_ bool onoff) = 0;

	/**
	 * @brief Changes audio description volume.
	 * @param [in] volume control for Audio Diescription
	 * @return Returns 1 if the mode is changed successfully.
	 * @return When calling method failed returns false.
	 *
	 * @paragraph <Example>
	 * This example will be turn on audio description.
	 * 
	 * @verbatim
	 * IAVControl* pAVControl;
	 * TVServiceAPI::CreateAVControl(PROFILE_TYPE_MAIN, 0, &pAVControl);
	 * 
	 * if(pAVControl->SetAudioDescriptionVolume(true) > 0)
	 * {
	 *  //Do something when operation successful
	 * }
	 * @endverbatim
	 */

	virtual int SetAudioDescriptionVolume(_IN_ int volume) = 0;

	/**	
	 * @brief Do unmute AV about rating locked channel
 	 * @return Returns 1
	 * @return When calling method failed returns false.
	 *	
	 *	@paragraph <Example>	
	 *	This example will be unmute av by correct pin code.	
	 *		
	 *	@verbatim	
	 *	IAVControl* pAVControl;	
	 *    	
	 *	TVServiceAPI::CreateAVControl(PROFILE_TYPE_MAIN, 0, &pAVControl);	
	 *		
	 *	if(pAVControl->UnMuteByRatingPin() > 0)	
	 *	{	
	 *		//Audio/Video is unmute state	
	 *	}	
	 *	@endverbatim	
	 */
	virtual int UnMuteByRatingPin(void) = 0;


	/** 
	* @brief Get lock state about rating locked channel
   	* @return Returns 1
	* @return When calling method failed returns false.
	* 
	* @paragraph <Example> 
	* This example will be unmute av by correct pin code. 
	*  
	* @verbatim 
	* IAVControl* pAVControl; 
	*     
	* TVServiceAPI::CreateAVControl(PROFILE_TYPE_MAIN, 0, &pAVControl); 
	*  bool lock;
	* if(pAVControl->GetRatingLockState(lock) > 0) 
	* { 
	* } 
	* @endverbatim 
	*/
	virtual int GetRatingLockState(bool& lock) =0;
	
	// TODO Duende - to be removed after 07.11.2014
	virtual int GetDigitalDualSound(_OUT_ long& currentMode, _OUT_ long& nextMode) = 0;

	/** 
	 * @brief Gets digital dual sound language code.
	 * @remark Those values represent language code. The data comes from SI.
	 * @param [out] currLanguage Current digital dual audio language code.
	 * @param [out] nextLanguage Next digital dual audio language code.
   	 * @return Returns 1 if dual sound existed for current service, otherwise returns 0.
	 * @return When calling method failed returns -1.
	 * 
	 * 	@paragraph <Example> 
	 * 	This example will return digital dual sound language code.
	 *  
	 * 	@verbatim 
	 * 	IAVControl* pAVControl; 
	 *     
	 * 	TVServiceAPI::CreateAVControl(DEFAULT_PROFILE_TYPE, DEFAULT_SCREEN_ID, &pAVControl); 
	 *  	ELanguageCode currLanguage = LANGUAGE_CODE_UNKNOWN;
	 *	ELanguageCode nextLanguage = LANGUAGE_CODE_UNKNOWN;
	 * 	if(pAVControl->GetDigitalDualSound( currLanguage, nextLanguage ) > 0) 
	 * 	{
	 *		// value returned
	 * 	}
	 * 	@endverbatim 
	 */
	virtual int GetDigitalDualSound(_OUT_ ELanguageCode& currLanguage, _OUT_ ELanguageCode & nextLanguage) = 0; 
	
	/** 
	 * @brief Gets digital dual sound mode.
	 * @remark Those values represent MTS mode. The data comes from TVPlayer settings.
	 * @param [out] currentMode Current digital dual audio mode.
	 * @param [out] nextMode Current digital dual audio mode.
   	 * @return Returns 1 if dual sound existed for current service, otherwise returns 0.
	 * @return When calling method failed returns -1.
	 * 
	 * 	@paragraph <Example> 
	 * 	This example will return digital dual sound mode as MTS mode.
	 *  
	 * 	@verbatim 
	 * 	IAVControl* pAVControl; 
	 *     
	 * 	TVServiceAPI::CreateAVControl(DEFAULT_PROFILE_TYPE, DEFAULT_SCREEN_ID, &pAVControl); 
	 *  	EMultiSoundMode currMode = MULTI_SOUND_UNKNOWN;
	 *	EMultiSoundMode nextMode = MULTI_SOUND_UNKNOWN;
	 * 	if(pAVControl->GetDigitalDualSound( currMode, nextMode ) > 0) 
	 * 	{
	 *		// value returned
	 * 	}
	 * 	@endverbatim 
	 */
	virtual int GetDigitalDualSound(_OUT_ EMultiSoundMode & currMode, _OUT_ EMultiSoundMode & nextMode) = 0;


	/** 
	 * @brief Sets digital dual sound language code.
	 * @remark This value represents language code.
	 * @remark On success both current audio and settings in TVPlayer are changed.
	 * @param [in] language Digital dual audio language code.
   	 * @return Returns 1 if digital dual sound language code was set successfully, otherwise returns 0.
	 * @return When calling method failed returns -1.
	 * 
	 * @paragraph <Example> 
	 * This example will set digital dual sound language code to LANGUAGE_CODE_KOR
	 *  
	 * 	@verbatim 
	 * 	IAVControl* pAVControl; 
	 *     
	 * 	TVServiceAPI::CreateAVControl(DEFAULT_PROFILE_TYPE, DEFAULT_SCREEN_ID, &pAVControl); 
	 * 	if(pAVControl->SetDigitalDualSound( LANGUAGE_CODE_KOR ) > 0) 
	 * 	{
	 *		// value set
	 * 	}
	 * 	@endverbatim 
	 */
	virtual int SetDigitalDualSound(_IN_ ELanguageCode language) = 0;

	/** 
	 * @brief Sets digital dual sound mode.
	 * @remark This value represents MTS mode.
	 * @remark On success settings in TVPlayer are changed.
	 * @param [in] mode Digital dual audio mode.
   	 * @return Returns 1 if digital dual sound mode was set successfully, otherwise returns 0.
	 * @return When calling method failed returns -1.
	 * 
	 * @paragraph <Example> 
	 * This example will set digital dual sound mode to MULTI_SOUND_STEREO.
	 *  
	 * 	@verbatim 
	 * 	IAVControl* pAVControl; 
	 *     
	 * 	TVServiceAPI::CreateAVControl(DEFAULT_PROFILE_TYPE, DEFAULT_SCREEN_ID, &pAVControl); 
	 * 	if(pAVControl->SetDigitalDualSound( MULTI_SOUND_STEREO ) > 0) 
	 * 	{
	 *		// value set
	 * 	}
	 * 	@endverbatim 
	 */
	virtual int SetDigitalDualSound(_IN_ EMultiSoundMode mode) = 0;

	/* This method shall be removed on 20.10.2014 */
	virtual int GetDigitalDualSound(_OUT_ ELanguageCode& mode) { long mode2; return GetDigitalDualSound( (long&)mode, mode2 ); }
	
	/** 
	 * @brief Gets analog Dual Sound mode.
   	 * @param [out] mode Analog dual audio mode. The data comes from TVPlayer settings.
   	 * @return Returns 1 if dual sound existed for current service, otherwise returns 0.
	 * @return When calling method failed returns -1.
	 * 
	 * @paragraph <Example> 
	 * This example will return analog dual sound mode.
	 *  
	 * 	@verbatim 
	 * 	IAVControl* pAVControl; 
	 *     
	 * 	TVServiceAPI::CreateAVControl(DEFAULT_PROFILE_TYPE, DEFAULT_SCREEN_ID, &pAVControl); 
	 *  EMultiSoundMode mode = MULTI_SOUND_UNKNOWN;
	 * 	if(pAVControl->GetAnalogDualSound( mode ) > 0) 
	 * 	{
	 *		// value returned
	 * 	}
	 * 	@endverbatim 
	 */
	virtual int GetAnalogDualSound(_OUT_ EMultiSoundMode& mode) = 0;

	/** 
	 * @brief Sets analog Dual Sound mode.
	 * @remark On success settings in TVPlayer are changed.
   	 * @param [in] mode Analog dual audio mode.
   	 * @return Returns 1 if analog dual sound mode was set successfully, otherwise returns 0.
	 * @return When calling method failed returns -1.
	 * 
	 * @paragraph <Example> 
	 * This example will set analog dual sound mode to MULTI_SOUND_MONO.
	 *  
	 * 	@verbatim 
	 * 	IAVControl* pAVControl; 
	 *     
	 * 	TVServiceAPI::CreateAVControl(DEFAULT_PROFILE_TYPE, DEFAULT_SCREEN_ID, &pAVControl); 
	 * 	if(pAVControl->SetAnalogDualSound( MULTI_SOUND_MONO ) > 0) 
	 * 	{
	 *		// value set
	 * 	}
	 * 	@endverbatim 
	 */
	virtual int SetAnalogDualSound(_IN_ EMultiSoundMode mode) = 0;

	/* This method shall be removed on 09.10.2014 */
	virtual int GetAnalogDualSound(_OUT_ ELanguageCode& mode) { return GetAnalogDualSound( (EMultiSoundMode&)mode ); }

	/**
	 * @brief Control Dual View.
	 * @param [in] inData
	 * @param [out] outData
	 */
	virtual int ControlDualView(_IN_ const std::vector<unsigned char>& inData, _OUT_ std::vector<unsigned char>& outData) = 0;

	/**
	 * @brief Gets selected property for DualTV
	 * @param [in] pluginName Plugin name.
	 * @param [in] propertyName Property name.
	 * @param [in] Value Property value.
   	 * @return Returns 1 if property obtained, otherwise returns 0.
	 * @return When calling method failed returns -1.
	 * 
	 * @paragraph <Example> 
	 * This example will get property for DualTv.
	 *  
	 * 	@verbatim 
	 * 	IAVControl* pAVControl; 
	 *     
	 * 	TVServiceAPI::CreateAVControl(PROFILE_TYPE_MAIN, 0, &pAVControl); 
	 * 	if(pAVControl->GetDualTvProperty( pluginName, propertyName, value ) > 0) 
	 * 	{
	 *		// value returned
	 * 	}
	 * 	@endverbatim 
	 */
	virtual int GetDualTvProperty(_IN_ const std::vector<unsigned char>& pluginName, _IN_ const std::vector<unsigned char>& propertyName, _OUT_ std::vector<unsigned char>& value) = 0;

	/**
	 * @brief Sets selected property for DualTV
	 * @param [in] pluginName Plugin name.
	 * @param [in] propertyName Property name.
	 * @param [in] value Property value.
	 * @return Returns 1 if property successfully set, otherwise returns 0.
	 * @return When calling method failed returns -1.
	 * 
	 * @paragraph <Example> 
	 * This example will set property for DualTv.
	 *  
	 * 	@verbatim 
	 * 	IAVControl* pAVControl; 
	 *
	 * 	TVServiceAPI::CreateAVControl(PROFILE_TYPE_MAIN, 0, &pAVControl); 
	 * 	if(pAVControl->SetDualTvProperty( pluginName, propertyName, value ) > 0) 
	 * 	{
	 *		// value set
	 * 	}
	 * 	@endverbatim 
	 */
	virtual int SetDualTvProperty(_IN_ const std::vector<unsigned char>& pluginName, _IN_ const std::vector<unsigned char>& propertyName, _IN_ const std::vector<unsigned char>& value) = 0;

	/**
	 * @brief Sets DualView type.
	 * @param [in] type DualView type.
	 * @return Returns 1 if type successfully set, otherwise returns 0.
	 * @return When calling method failed returns -1.
	 * 
	 * @paragraph <Example> 
	 * This example will set DualView type to DUALVIEW_TYPE_DUALTV.
	 *
	 * 	@verbatim 
	 * 	IAVControl* pAVControl; 
	 *
	 * 	TVServiceAPI::CreateAVControl(PROFILE_TYPE_MAIN, 0, &pAVControl); 
	 * 	if(pAVControl->SetDualViewType( DUALVIEW_TYPE_DUALTV ) > 0) 
	 * 	{
	 *		// value set
	 * 	}
	 * 	@endverbatim 
	 */
	virtual int SetDualViewType(_IN_ EDualViewType type) = 0;

	/**
	 * @brief Force settting again current resolution.
	 * @remark This API helps to set again previously detected resolution.
	 * @return Returns 1 if operation was successful, otherwise returns 0.
	 * @return When calling method failed returns -1.
	 * 
	 * @paragraph <Example> 
	 * This example will set again previously detected resolution.
	 *
	 * 	@verbatim 
	 * 	IAVControl* pAVControl; 
	 *
	 * 	TVServiceAPI::CreateAVControl(PROFILE_TYPE_MAIN, 0, &pAVControl); 
	 * 	if(pAVControl->ReapplyResolution() > 0) 
	 * 	{
	 *		// resolution reset
	 * 	}
	 * 	@endverbatim 
	 */
	virtual int ReapplyResolution(void) = 0;

	/**
	 * @brief Sets Analog Clean View (on/off).
	 * @param [in] on States, whether Analog Clean View should be turned on or off. True: On, False: Off
	 * @return Returns 1 if operation was successful, otherwise returns 0.
	 * @return When calling method failed returns -1.
	 * 
	 * @paragraph <Example> 
	 * This example will turn Analog Clean View ON.
	 *
	 * 	@verbatim 
	 * 	IAVControl* pAVControl; 
	 *
	 * 	TVServiceAPI::CreateAVControl(PROFILE_TYPE_MAIN, 0, &pAVControl); 
	 * 	if(pAVControl->SetAnalogCleanView(true) > 0) 
	 * 	{
	 *		// resolution reset
	 * 	}
	 * 	@endverbatim 
	 */
	virtual int SetAnalogCleanView(_IN_ bool on) = 0;

	
	/**
	 * @brief Gets Direct2Tv property
	 * @param [in] pluginName Plugin name.
	 * @param [in] propertyName Property name.
	 * @param [in] Value Property value.
   	 * @return Returns 1 if property obtained, otherwise returns 0.
	 * @return When calling method failed returns -1.
	 * 
	 * @paragraph <Example> 
	 * This example will get Direct2Tv property.
	 *  
	 * 	@verbatim 
	 * 	IAVControl* pAVControl; 
	 *     
	 * 	TVServiceAPI::CreateAVControl(PROFILE_TYPE_MAIN, 0, &pAVControl); 
	 * 	if(pAVControl->GetDirect2TvProperty( pluginName, propertyName, value ) > 0) 
	 * 	{
	 *		// value returned
	 * 	}
	 * 	@endverbatim 
	 */
	virtual int GetDirect2TvProperty(_IN_ const std::vector<unsigned char>& pluginName, _IN_ const std::vector<unsigned char>& propertyName, _OUT_ std::vector<unsigned char>& value) = 0;

	
	/**
	* @brief Mute video for standby.
	* @param [in] on/off of video.
	* @return Returns 1 if current service is mute video for standby successfully.
	* @return When calling method failed returns -1.
	*
	* @paragraph <Example>
	* This example will be mute video for standby.
	*
	*	@verbatim
	*	IAVControl* pAVControl;
	*
	*	TVServiceAPI::CreateAVControl(PROFILE_TYPE_MAIN, 0, &pAVControl);
	*	if(pAVControl->SetStandbyVideoMute(true) > 0)
	*	{ 
	*		// Do something when operation successful 
	*	}
	*	@endverbatim
	*/
	virtual int SetStandbyVideoMute(_IN_ bool onoff) = 0;

	/**
	 * @brief Gets TVStream property
	 * @param [in] tvstreamProperty
	 * @param [out] propertyValue
	 * @return Returns 1 if analog dual sound mode was set successfully, otherwise returns 0.
	 * @return When calling method failed returns -1.
	 * @paragraph <Example> 
	 * This example will get TVStream property.
	 *
	 * @verbatim
	 * IAVControl* pAVControl;
	 *
	 * TVServiceAPI::CreateAVControl(PROFILE_TYPE_MAIN, 0, &pAVControl);
	 * if(pAVControl->GetTVStreamProperty( tvstreamProperty, propertyValue ) > 0)
	 * {
	 *      // value returned
	 * }
	 * @endverbatim
	 */
	virtual int GetTVStreamProperty(_IN_ ETVStreamProperty tvstreamProperty, _OUT_ unsigned int& propertyValue) = 0;

	/**
	 * @brief Checks if pipeline is DTV type
	 * @param [out] isPipelineDtv
	 * @return Returns 1 if analog dual sound mode was set successfully, otherwise returns 0.
	 * @return When calling method failed returns -1.
	 * @paragraph <Example> 
	 * This example will check if pipeline type is DTV.
	 *
	 * @verbatim
	 * IAVControl* pAVControl;
	 *
	 * TVServiceAPI::CreateAVControl(PROFILE_TYPE_MAIN, 0, &pAVControl);
	 * if(pAVControl->IsPipelineTypeDtv( isPipelineDtv ) > 0)
	 * {
	 *      // value returned
	 * }
	 * @endverbatim
	 */
	virtual int IsPipelineTypeDtv(_OUT_ bool& isPipelineDtv) = 0;

	/**
	 * @brief Checks if pipeline is in playing state
	 * @param [out] isPipelinePlaying
	 * @return Returns 1 if analog dual sound mode was set successfully, otherwise returns 0.
	 * @return When calling method failed returns -1.
	 * @paragraph <Example> 
	 * This example will check if pipeline is in playing state.
	 *
	 * @verbatim
	 * IAVControl* pAVControl;
	 *
	 * TVServiceAPI::CreateAVControl(PROFILE_TYPE_MAIN, 0, &pAVControl);
	 * if(pAVControl->IsPipelineInPlayingState( isPipelinePlaying ) > 0)
	 * {
	 *      // value returned
	 * }
	 * @endverbatim
	 */
	virtual int IsPipelineInPlayingState(_OUT_ bool& isPipelinePlaying) = 0;

	/**
	 * @brief Get resolution that is recommended
	 * @param [out] resolution
	 * @return Returns 1 if get successfully, otherwise returns 0.
	 * @return When calling method failed returns -1.
	 * @paragraph <Example> 
	 *
	 * @verbatim
	 * IAVControl* pAVControl;
	 *
	 * TVServiceAPI::CreateAVControl(PROFILE_TYPE_MAIN, 0, &pAVControl);
	 *
	 * EResolution resolution;
	 * if(pAVControl->GetRecommendedResolution( resolution ) > 0)
	 * {
	 *      // value returned
	 * }
	 * @endverbatim
	 */
	virtual int GetRecommendedResolution(_OUT_ EResolution& resolution) = 0;


	/**
	 * @brief mutes video of current service.
	 * @remarks Only the common interface module should use this API. Otherwise assertion will happen.
	 * @param [in] on/off of video.
	 * @return Returns 1 if video for current service was muted/unmuted successfully. Otherwise 0.
	 * @return When calling method failed returns -1.
	 *
	 * @paragraph <Example>
	 * 
	 * @verbatim
	 * IAVControl* pAVControl;
	 * TVServiceAPI::CreateAVControl(PROFILE_TYPE_MAIN, 0, &pAVControl);
	 * 
	 * if(pAVControl->MuteVideoForCI(true or false) > 0)
	 * {
	 *	//Do something when operation successful
	 * }
	 * @endverbatim
	 */
	virtual int MuteVideoForCI(_IN_ int onoff) = 0;

	/**
	 * @brief mutes audio of current service.
	 * @remarks Only the common interface module should use this API. Otherwise assertion will happen.
	 * @param [in] on/off of audio.
	 * @return Returns 1 if audio for current service was muted/unmuted successfully. Otherwise 0.
	 * @return When calling method failed returns -1.
	 *
	 * @paragraph <Example>
	 * 
	 * @verbatim
	 * IAVControl* pAVControl;
	 * TVServiceAPI::CreateAVControl(PROFILE_TYPE_MAIN, 0, &pAVControl);
	 * 
	 * if(pAVControl->MuteAudioForCI(true or false) > 0)
	 * {
	 *	//Do something when operation successful
	 * }
	 * @endverbatim
	 */
	virtual int MuteAudioForCI(_IN_ int onoff) = 0;

	/**
	* @brief check whether audio language can change
	* @param [out] bCheck - true : possible , false : impossible
	* @return Returns 1
	* @return When calling method failed returns false.
	*
	* @paragraph <Example>
	* This example will be check whether audio language can change.
	*
	* @verbatim
	* IAVControl* pAVControl;
	* bool bCheck = false;
	* TVServiceAPI::CreateAVControl(PROFILE_TYPE_MAIN, 0, &pAVControl);
	*
	* if(pAVControl->CheckAudioLanguageChangeAvailable() > 0)
	* {
	*  //Do something when operation successful
	* }
	* @endverbatim
	*/
	virtual int CheckAudioLanguageChangeAvailable(_OUT_ bool& bCheck) = 0;

};

#endif // _IAVCONTROL_H_

