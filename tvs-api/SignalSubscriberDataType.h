/** 
 * @file SignalSubscriberDataType.h
 * @brief Definition of data types for signal subscription.
 *
 * Copyright 2013 by Samsung Electronics, Inc.,
 * 
 * This software is the confidential and proprietary information
 * of Samsung Electronics, Inc. ("Confidential Information"). You
 * shall not disclose such Confidential Information and shall use
 * it only in accordance with the terms of the license agreement
 * you entered into with Samsung.
 */


#ifndef _SIGNALSUBSCRIBERDATATYPE_H_
#define _SIGNALSUBSCRIBERDATATYPE_H_


#include "TVServiceDataType.h"


struct TSSignalData
{
	union TTDataType
	{
		unsigned long long ll;
		long  l[2];
		short s[4];
		char  c[8];
	}data;
};


/**
 * @brief Definition of all signals sent from TV Service to application.
 * @remark Signals are divided into two groups: general signals and pipeline signals.
 */
typedef enum
{
	SIGNAL_TYPE_BEGIN = 0x00010,


	/********************************************************************************************/
	/*	Enumaration of general signals.															*/
	/*	Signals which do not curry any information about tvsHandle,	unless specified otherwise	*/
	/*	For more information look into ISignalSubscriber interface.								*/
	/********************************************************************************************/


	// Sent whenever scanning some channel is started.
	// For DVB and DVBNT profile
	// param.s[0] = channel number (PTC)
	// param.s[1] = channel type
	// param.l[1] = frequency
	// For ATSC and ISDB profile
	// param.s[0] = channel number (PTC)
	// param.s[1] = channel type
	// param.s[2] = not tuned for searching a service
	SIGNAL_SEARCH_CHANNEL = SIGNAL_TYPE_BEGIN,

	// Sent whenever channel is found.
	// param.s[0]: channeltype
	// param.s[1]: number of Tv channels found
	// param.s[2]: number of Radio channels found
	// param.s[3]: number of Data channels found
	SIGNAL_CHANNEL_FOUND,

	// Sent when channel search is ended for some reason.
	// param.l[0]: COMMAND_PAUSE/ COMMAND_STOP - the reason that channel search ended.
	// param.s[2]: SCAN_STOP_USER/ SCAN_STOP_COMPLETE/ SCAN_STOP_FORCED - the request mode of channel search ended.
	SIGNAL_SEARCH_CHANNEL_DONE,

	// Sent when scan info options is change.
	// NIT in Cable Auto Store process , notify num of freq in NIT to APP.
	// param.l[0]: number of frequencies.
	SIGNAL_SEARCH_OPTION_CHANGE,

	// Sent when service list is full.
	SIGNAL_SEARCH_SERVICE_LIST_FULL,

	// Notification whether service list has changed.
	// param.s[0]: TVSHandle EProfile profile.
	// param.s[1]: TVSHandle subId.
	// param.s[2]: bShowNotificationBanner defines if to show notification banner.
	SIGNAL_SERVICE_LIST_CHANGED,

	// Notification about result of auto search for digi turk.
	// param.l[0]: Define whether tune to home transponder was successful.
	SIGNAL_DIGITURK_AUTO_TUNING_RESULT,

	// Sent when egp data fetch has completed for a given channel number.
	// param.l[0] = channel number;
	SIGNAL_EPG_COMPLETED,

	// Send whenever EPG information changes.
	// param.s[0]: TVSHandle EProfile profile.
	// param.s[1]: TVSHandle subId.
	SIGNAL_PROGRAM_CHANGED,

	// Sent when starting to change source.
	SIGNAL_EXT_SOURCE_CHANGE_START,

	// Sent when Signal is valid
	SIGNAL_EXT_SOURCE_SIGNAL_OK,

	// Sent when Resolution is not suppoted.
	SIGNAL_EXT_SOURCE_NOT_SUPPORT,

	// Sent when no signal state
	SIGNAL_EXT_SOURCE_NO_SIGNAL,

	// Sent when cable is unplugged
	// param.s[0]: source type
	// param.s[1]: state
	SIGNAL_EXT_SOURCE_UNPLUG,

	// Sent when cable is unplugged
	// param.s[0]: TVSHandle EProfile profile.
	// param.s[1]: TVSHandle subId.
	SIGNAL_EXT_SOURCE_STOP,

	// Sent by PVR whenever any event occur for tvs-system.
	// param.s[0]: PVR event type
	// param.s[1]: depend on the event
	// param.s[2]: depend on the event
	// param.s[3]: depend on the event
	SIGNAL_PVR_SYSTEM_EVENT,

	// Send when rating information changes.
	// param.s[0]: TVSHandle EProfile profile.
	// param.s[1]: TVSHandle subId.
	SIGNAL_RATING_CHANGED,

	// Sent when scrambled channel is found at  the Clear Scrambled Channels.
	// param.s[0]: major channel number
	// param.s[1]: minor channel number
	// param.s[2]: searched channel count
	// param.s[3]: total channel count
	SIGNAL_CHANNEL_SCRAMBLED_FOUND,

	// Sent when new channel tunning is started at the Clear Scrambled Channels.
	// param.s[0]: major channel number
	// param.s[1]: minor channel number
	// param.s[2]: searched channel count
	// param.s[3]: total channel count
	SIGNAL_SEARCH_SCRAMBLE,

	// Sent when Clear Scrambled Channels is done.
	// param.l[0] - COMMAND_STOP
	// param.l[1] - 0: user stop, 1: tvs stop
	SIGNAL_SEARCH_SCRAMBLE_DONE,

	// DEPRECATED will be removed on 07.01.2016. refer to ci-api for replacement
	SIGNAL_CI_MMI_SESSION_CLOSED,

	// DEPRECATED will be removed on 07.01.2016. refer to ci-api for replacement
	SIGNAL_CI_MMI_ENQUIRY_RECEIVED,

	// DEPRECATED will be removed on 07.01.2016. refer to ci-api for replacement
	SIGNAL_CI_MMI_TEXT_RECEIVED,

	// DEPRECATED will be removed on 07.01.2016. refer to ci-api for replacement
	SIGNAL_CI_MMI_MENU_RECEIVED,

	// DEPRECATED will be removed on 07.01.2016. refer to ci-api for replacement
	SIGNAL_CI_MMI_LIST_RECEIVED,

	// DEPRECATED will be removed on 07.01.2016. refer to ci-api for replacement
	SIGNAL_CI_MMI_STATUS_CHANGED,

	// DEPRECATED will be removed on 07.01.2016. refer to ci-api for replacement
	SIGNAL_CI_CAM_READY_STATUS_CHANGED,

	// DEPRECATED will be removed on 07.01.2016. refer to ci-api for replacement
	// TODO still used by /BROADCAST/Core-app_2016_Prj/INT/tv-control/tv-viewer-app/src/common/
	// TODO still used by /CONTENTSERVICE/NewMarket_2016_Prj/INT/mvpd-apps/nodejs_modules/node-native/tvsapi/
	// TODO still used by /WCS/GingaNCL_2016_Prj/INT/ginga-ncl/GingaNCL/Platform/Device/Tizen/Inc/events/
	// TODO still used by /BROADCAST/Java-mw_2016_Prj/INT/javamw-service/JM_PIImpl/TVS/
	// TODO still used by /INTERACTION/Contents-analysis_2016_Prj/INT/contents-analysis-service/src/MiscMgr/
	SIGNAL_CI_CHECK_PARENTAL_RATING_HANDLERS,

	// DEPRECATED will be removed on 07.01.2016. refer to ci-api for replacement
	SIGNAL_CI_PIN_REPLY_TO_PIN_MMI_REQ,

	// DEPRECATED will be removed on 07.01.2016. refer to ci-api for replacement
	SIGNAL_CI_PIN_REPLY_TO_PIN_CMD,

	// DEPRECATED will be removed on 07.01.2016. refer to ci-api for replacement
	SIGNAL_CI_PIN_REPLY_TO_PIN_PLAYBACK,

	// DEPRECATED will be removed on 07.01.2016. refer to ci-api for replacement
	SIGNAL_CI_PIN_REPLY_TO_PIN_EVENT,

	// Send if current service's program is changed with specific tvsHandle
	SIGNAL_RECV_CURRENT_EVENT,

	// DEPRECATED will be removed on 07.01.2016. refer to ci-api for replacement
	SIGNAL_CI_APP_MMI_START_APP,

	// DEPRECATED will be removed on 07.01.2016. refer to ci-api for replacement
	SIGNAL_CI_APP_MMI_FILE_ACK,

	// DEPRECATED will be removed on 07.01.2016. refer to ci-api for replacement
	SIGNAL_CI_APP_MMI_ABORT_REQ,

	// DEPRECATED will be removed on 07.01.2016. refer to ci-api for replacement
	SIGNAL_CI_APP_MMI_ABORT_ACK,

	// DEPRECATED will be removed on 07.01.2016. refer to ci-api for replacement
	SIGNAL_CI_CAM_UGRADE_STATUS_CHANGE,

	// DEPRECATED will be removed on 07.01.2016. refer to ci-api for replacement
	SIGNAL_CI_OPERATOR_PROFILE_STATUS_CHANGE,

	// DEPRECATED will be removed on 07.01.2016. refer to ci-api for replacement
	SIGNAL_CI_SAS_STATUS_CHANGE,

	// DEPRECATED will be removed on 07.01.2016. refer to ci-api for replacement
	SIGNAL_CI_CA_SYSTEMS_CHANGE,

	// DEPRECATED will be removed on 07.01.2016. refer to ci-api for replacement
	SIGNAL_CI_SLOT_TEST_RESULT,

	// DEPRECATED will be removed on 07.01.2016. refer to ci-api for replacement
	// TODO still used by /BROADCAST/Core-app_2016_Prj/INT/tv-control/tv-viewer-app/src/common/
	// and /CONTENTSERVICE/NewMarket_2016_Prj/INT/mvpd-apps uses it
	SIGNAL_CI_CAM_MONITOR_STATUS,


	/********************************************************************************************/
	/*	Enumaration of pipeline signals.														*/
	/*	Signals which are generated for specific tvsHandle (TVS pipeline).						*/
	/*	The information about tvsHandle is passed in the callback argument list.				*/
	/*	For more information look into IPipelineSignalSubscriber interface.						*/
	/********************************************************************************************/


	// Sent before starting tuning.
	SIGNAL_TUNE_START,

	// Sent when Signal is valid.
	SIGNAL_TUNE_SUCCESS,

	// Sent when tuner lock is failed.
	SIGNAL_TUNER_LOCK_FAIL,

	// Sent when current service is locked.
	SIGNAL_SERVICE_LOCKED,

	// Sent on stop tunning.
	SIGNAL_TUNE_STOP,

	SIGNAL_SIGNAL_STRENGTH,

	// Notification whether TV mode has changed.
	SIGNAL_CHANGE_TV_MODE,

	// Send when resolution was changed
	SIGNAL_RESOLUTION_CHANGED,

	// Send whenever caption descriptor is available.
	SIGNAL_CAPTION_DESCRIPTOR,

	// Sent when occured SI Timeout.
	SIGNAL_SI_TIME_OUT,

	// Sent when changed SI ( example - pmt update ... )
	SIGNAL_SI_CHANGED,
	// Send before service tune for working things 
	SIGNAL_TUNE_PREPARATION,

	// Notification whether service list has changed.
	SIGNAL_TUNE_ABANDONED,

	// Notification whether service list has changed.
	SIGNAL_TUNE_WEAK_SIGNAL,

	// param.ll - changed source state
	SIGNAL_SOURCE_STATE_CHANGED,

	// Analog Case
	// param.s[0]: TVSHandle EProfile profile.
	// param.s[1]: TVSHandle subId.
	// param.s[2]: changed mts mode
	// Digital Case
	// param.s[0]: TVSHandle EProfile profile.
	// param.s[1]: TVSHandle subId.
	// param.s[2]: audio index.
   	SIGNAL_MTS_CHANGED,

	// Notification when ref-count of TVS was added.
	SIGNAL_TVS_ACTIVATE,

	// Notification when ref-count of TVS was released.
	SIGNAL_TVS_DEACTIVATE,

	// Notification when ref-count was ignored because of playback pipeline
	SIGNAL_IGNORE_TVS_ACTIVE,
	// Notification from SIManager when NetworkInformations has changed. Pipeline signal
	SIGNAL_DELIVERY_SYSTEM_CHANGED,

	// Notification from SIManager when EIT has changed. Pipeline signal
	// param.s[0]: EProgramChanged
	SIGNAL_PRESENT_EIT_CHANGED,

	// Notification from SIManager when EIT has changed. Pipeline signal
	// param.s[0]: EProgramChanged
	SIGNAL_FOLLOWING_EIT_CHANGED,

	//Notification from SIManager that SI module is ready to work. 
	//After recieving this signal there is possibility to subscribe for sections.
	SIGNAL_SI_STARTED,

	// Notification when picture size ( crop / geometry ) was changed.
	SIGNAL_PICTURE_SIZE_CHANGE,

	// Notification when (digital) country or broadcaster ID is being changed: see ISOSpecControl::ChangeDigitalSOSpec
	SIGNAL_COUNTRY_CHANGED,

	// Sent when homing channel search is ended for some reason.
	// param.l[0]: define whether Is home TP was found
	SIGNAL_SEARCH_HOMING_CHANNEL_DONE,

	// Notification when infomation of PES data(TTX/SBT/JPCaption/Superimpose)  was changed.
	// param.s[0]: PES type.
	// handle: TVSHandle.
	SIGNAL_PES_CHANGED,

	// Notification when infomation of caption data mode  was changed.
	// handle: TVSHandle.
	SIGNAL_CAPTION_DATA_MODE_CHANGED,

	// Sent when tuner lock is received.
	// param.ll = Current ServiceId;
	// handle: TVSHandle.	
	SIGNAL_LOCK_SUCCESS,
	SIGNAL_BDWISE_CONNECTED_CHANGE,
	SIGNAL_BDWISE_PANEL_OFF_CHANGE,
	SIGNAL_VSI_3D_CHANGE,

	SIGNAL_UNMUTE_VIDEO,

	//Pipeline type signal sent when new transponder is detected
	// param.l = pBat->VersionNumber
	SIGNAL_NEW_TRANSPONDERS_DETECTED,

	//Sent when bat table is changed. . Pipeline signal
	//param.l = bat version number
	SIGNAL_BAT_CHANGED,

	//Sent when SI received 3D channel. Pipeline signal
	// param.ll = Current ServiceId;
	// handle: TVSHandle.		
	SIGNAL_RECEIVED_MATCHED_3DCHANNEL,

	// Sent when current service is data service
	SIGNAL_DATA_SERVICE,

	// Sent when current service is scramble service
	SIGNAL_SCRAMBLED_SERVICE,

	// Sent when current service is clear service
	SIGNAL_CLEAR_SERVICE,

	// Sent when current service is not-support service
	SIGNAL_NOT_AVAILABLE_SERVICE,

	// Sent when successfully tuned in during 
	// SI is supporting only section subscription functionality. Pipeline signal
	SIGNAL_TUNE_FOR_FEEDING_SI,

	// TODO_CI TVS does not send this signal at all. why?
	SIGNAL_CI_VIDEODEC_ERROR_DETECT,

	SIGNAL_RATING_CHANGED_FROM_GUIDE, 

	SIGNAL_MAJOR_TUNE,

	// Sent in the case of tuning to a virtual service
	SIGNAL_TUNE_VIRTUAL,

	// Sent when trying to tune to a virtual (IP) service while PIP or MLS function is on/active
	SIGNAL_TUNE_VIRTUAL_NOTSUPPORTED,

	SIGNAL_PROGRAM_CHANGE_EPG_DATA_DYNAMIC_UPDATED,//for epg dynamic update

	SIGNAL_EPG_LOAD_COMPLETED,// for epg loader

	// Sent when the receiver is tuned to the home transponder and SAS-based appication should start acquisition of bouquet ID using CAM
	// Used in Airtel operator profile
	SIGNAL_REQUEST_BOUQUET_ID,

	// Send when system time is changed.
	SIGNAL_SYSTEM_TIME_UPDATED,

	// Send when kr3d channel is disappeared.
	SIGNAL_KR3DSERVICE_DISAPPEAR,

	// Sent whenever here is an mft tune adjustment during manual analog scan
	// param.l[0] = frequency;
	SIGNAL_CHANNEL_FREQUENCY_ADJUSTMENT,

	// Sent when processing sections fed to TVS is completed
	// (e.g. after receiving this signal APP can acquire audio information related to fed section).
	SIGNAL_FED_SECTIONS_PROCESSED,

	// Send when ASM crash is occur, that pipeline is deactivated.
	// param.s[0]: TVSHandle EProfile profile.
	// param.s[1]: TVSHandle subId.
	SIGNAL_ASM_DEACTIVATE_PIPELINE,

	// Sent when source play is failed by resource restriction.
	// (e.g. 2-UD content are not available)
	SIGNAL_SOURCE_FAILED_BY_RESOURCE_RESTICTION,

	// Send when decoder resource conflict by DV9
	// (e.g MLS TV=UD(DV9) : MLS MM(DV9))
	SIGNAL_MLS_RESOURCE_CONFLICT,

	//Send When change to subid by subscribe app
	// param.s[0]: TVSHandle EProfile profile
	// param.s[1]: TVSHandle subId.
	// param.s[2]: change to TVSHandle subId.
	SIGNAL_SUBSCRIBE_CHANGE_SUBID,

	// Send before source change for working things 
	SIGNAL_SOURCECHANGE_PREPARATION,

	// Notification that source changing has been abandoned.
	SIGNAL_SOURCECHANGE_ABANDONED,

	// DEPRECATED will be removed on 07.01.2016. refer to ci-api for replacement
	SIGNAL_CI_CA_REPLY,

	// DEPRECATED will be removed on 07.01.2016. refer to ci-api for replacement
	SIGNAL_CI_TUNE_ACK_SERVICE_CHANGE_ALLOWED,

	// DEPRECATED will be removed on 07.01.2016. refer to ci-api for replacement
	SIGNAL_CI_TUNE_ACK_SERVICE_CHANGE_NOT_ALLOWED,

	// DEPRECATED will be removed on 07.01.2016. refer to ci-api for replacement
	SIGNAL_CI_TUNE_ACK_SOURCE_CHANGE_ALLOWED,

	// DEPRECATED will be removed on 07.01.2016. refer to ci-api for replacement
	SIGNAL_CI_TUNE_ACK_SOURCE_CHANGE_NOT_ALLOWED,

	// DEPRECATED will be removed on 07.01.2016. refer to ci-api for replacement
	SIGNAL_CI_REQUEST_TUNE_BLOCKING,

	SIGNAL_NORWAY_TIMELOCK_CHANGED,

	// Notification when Release ref-count was ignored because of playback pipeline
	// param.s[0] - m_tvsHandle.profileId;
	// param.s[1] - m_tvsHandle.subId;
	SIGNAL_IGNORE_TVS_DEACTIVE,

	// Notification when pipeline active fail
	// param.s[0] - m_tvsHandle.profileId;
	// param.s[1] - m_tvsHandle.subId;
	SIGNAL_PIPELINE_ACTIVATE_FAIL,

	// Notification when changed source info
	// param.s[0] - m_tvsHandle.profileId;
	// param.s[1] - m_tvsHandle.subId;
	SIGNAL_SOURCE_INFO_CHANGE,

	SIGNAL_DUALVIEW_STOP,

	// Notification when video mute changed
	// param.s[0] - 1 mute, 0 unmute;
	SIGNAL_MUTE_VIDEO,

	// Notification when audio mute changed
	// param.s[0] - 1 mute, 0 unmute;
	SIGNAL_MUTE_AUDIO,

	// Notification when SetService() was ignored because of no TV Pipeline. Just Update Service Id and return false.
	// param.s[0] - m_tvsHandle.profileId;
	// param.s[1] - m_tvsHandle.subId;
	SIGNAL_JUST_UPDATE_SERVICEID,

	// Notification when changed EWBS state
	// param.s[0] = m_tvsHandle.profileId;
	// param.s[1] = m_tvsHandle.subId;
	// param.s[2] = EWBS State
	//			- 0 - inactive
	//			   1 - active
	SIGNAL_EWBS_STATE_CHANGE,

	// DEPRECATED will be removed on 07.01.2016. refer to ci-api for replacement
	SIGNAL_CI_TUNER_RELEASE_REPLY_STATUS,

	// Sent before starting tuning sending serviceID
	// param.ll - tune serviceID
	SIGNAL_TUNE_TO_SERVICEID,

	// Sent when EWBS information has changed.
	// To retreived EWBS info please use IEWBS::GetEWBSData() method.
	SIGNAL_EWBS_CHANGED,

	// @brief  Notification about a pipeline having a tuner connected/changed/disconnected.
	// @param  EProfile               profileId  - part of the pipeline identifier
	// @param  unsigned short         screenId   - part of the pipeline identifier
	// @param  TSSignalData:
	// @param           long          param.l[0] - identifier of the used tuner. This tunerId is directly mappable to kernel CA_FRONTEND_SOURCE. INVALID means tuner is disconnected.
	SIGNAL_CAS_PIPELINE_TUNER_STATUS,

	// @brief  Notification about a DVB service change.
	// @remark This notification is sent:
	//         - before SI is started/restarted
	//         - after AV is muted
	// @param  EProfile               profileId  - part of the pipeline identifier
	// @param  unsigned short         screenId   - part of the pipeline identifier
	// @param  TSSignalData:
	// @param           TCServiceId   param.ll   - identifier for the service set on the pipeline
	SIGNAL_CAS_SERVICE_CHANGE,

	// @brief  Notification about ES pid setting/change/unsetting, which need to be descrambled on the given pipeline
	// @remark All pids are notified for descrambling before SIGNAL_CAS_PID_SET_DONE.
	//         Any change in ES pids made later may result in macroblocks and CAM malfunction.
	//         TVS will select just one pid of each type. Any next call with same pid type will result in pid change.
	// @param  EProfile                profileId  - part of the pipeline identifier
	// @param  unsigned short          screenId   - part of the pipeline identifier
	// @param  TSSignalData:
	// @param           ECasPidType    param.s[0] - pid type
	// @param           unsigned short param.s[1] - pid value. INVALID means pid is unset
	SIGNAL_CAS_PID_SET,

	// @brief  Notification about finishing pid selection. This will trigger pid selection for descrambling.
	// @param  EProfile                profileId  - part of the pipeline identifier
	// @param  unsigned short          screenId   - part of the pipeline identifier
	// @param  TSSignalData:           N/A
	SIGNAL_CAS_PID_SET_DONE,

	// @brief  Notification about tuner demodulator status change
	// @param  EProfile                profileId  - part of the pipeline identifier
	// @param  unsigned short          screenId   - part of the pipeline identifier
	// @param  TSSignalData:
	// @param           unsigned short param.s[0] - demodulator state
	//                                              1 - stable (locked and no error)
	//                                              0 - unstable
	SIGNAL_CAS_TUNER_DEMODULATOR_STATUS_CHANGED,

	// @brief  Notification about decoder error status change
	// @param  EProfile                profileId  - part of the pipeline identifier
	// @param  unsigned short          screenId   - part of the pipeline identifier
	// @param  TSSignalData:
	// @param           unsigned short param.s[0] - decoder error status
	//                                              1 - error
	//                                              0 - no error
	SIGNAL_CAS_DECODER_ERROR_STATUS_CHANGED,

	// @brief  Notification about BER (bit error rate) limit (2000) exceeded
	// @param  EProfile                profileId  - part of the pipeline identifier
	// @param  unsigned short          screenId   - part of the pipeline identifier
	// @param  TSSignalData:
	// @param           unsigned short param.s[0] - BER limit exceeded status
	//                                              1 - BER limit exceeded (BER >= 2000)
	//                                              0 - BER limit NOT exceeded (BER < 2000)
	SIGNAL_CAS_BER_LIMIT_EXCEEDED,

	// @brief Notification about finishing to make thumbnail file.
	// param.s[0] - state(fail : 0 / success : 1)
	SIGNAL_PVR_MAKETHUMBNAIL_DONE,

	SIGANL_ADD_REFERENCECNT_VC,

	SIGNAL_RELEASE_REFERENCECNT_VC,

	// @brief Control EWBS-APP whether launching or deactivating
	// @param  bool param.s[0] - (need to launch : true / need to deactivate : false)
	SIGNAL_EWBS_CONTROL,

	// @brief Notification about starting AutoAdjustment to EP-APP for LFD Product 
	// param.s[0] = m_tvsHandle.profileId;
	// param.s[1] = m_tvsHandle.subId;
	// param.s[2] = Autoadjustment state [EAutoAdjustmentState]
	//			- 0 - finishing (success to adjust)
	//			  1 - starting 
	//			  2 - terminating (fail to adjust) 
	SIGNAL_EXECUTE_AUTOADJUSTMENT,

	// @brief Notification about progress value while recording
	// param.l[0] = pos;
	SIGNAL_RECORD_PROGRESS_POSITION,

	// @brief Notification about progress value while playing record file
	// param.l[0] = pos; (LeftTime)
	// param.l[1] = duration; (RightTime)
	SIGNAL_PLAYBACK_PROGRESS_POSITION,

	// @brief signal to stop spinner of tv-viewer after tune tv-plus channel
	// param.l[0] = success reason
	SIGNAL_TVPLUS_TUNE_SUCCESS,
	
	// @brief signal to show error message on tv-viewer after tune tv-plus channel
	// param.l[0] = fail reason
	SIGNAL_TVPLUS_TUNE_FAIL,

	// Sent when real tune start (after update current service info).
	// param.ll = Tuning Start ServiceId;
	// handle: TVSHandle.	
	SIGNAL_TUNING_SERVICEID,

	// Sent when source is changed in ReleaseReferenceCount State.
	// param.s[0] - Pre Source Type [ESource];
	// param.s[1] - Changed Source Type [ESource];
	SIGNAL_SOURCE_CHANGE_IN_TVS_DEACTIVATED,

	// @brief signal to notify tv-viewer when tune tv-plus channel
	// param.l[0] = start reason
	SIGNAL_TVPLUS_TUNE_START,
	SIGNAL_TYPE_END = 0x0fff,

}ESignalType;

#endif // _SIGNALSUBSCRIBERDATATYPE_H_
