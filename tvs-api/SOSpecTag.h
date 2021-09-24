/** 
 * @file SOSpecTag.h
 * @brief SOSpec data tags.
 *
 * Copyright 2014 by Samsung Electronics, Inc.,
 * 
 * This software is the confidential and proprietary information
 * of Samsung Electronics, Inc. ("Confidential Information"). You
 * shall not disclose such Confidential Information and shall use
 * it only in accordance with the terms of the license agreement
 * you entered into with Samsung.
 */

#ifndef _SOSPECTAG_H_
#define _SOSPECTAG_H_

typedef enum {
	SOSPEC_TAG_SPEC_CODE = 0, //ESpecCode, db: specId
	SOSPEC_TAG_COUNTRY = 1, //system_info_country_e, db: cntr
	SOSPEC_TAG_COUNTRY_CODE = 2, //ECountryCode, db: cntrC
	SOSPEC_TAG_DEFAULT_PREFERRED_LANGUAGE = 3, //ELanguageCode, db: defPrfLan
	SOSPEC_TAG_DEFAULT_SECONDARY_LANGUAGE = 4, //ELanguageCode, db: defSecLan
	SOSPEC_TAG_DELETE_CHANNEL_BEFORE_AUTO_STORE = 5, //bool, db: delChBefAuSt
	SOSPEC_TAG_DTV_DEFAULT_SCREEN_MODE = 6, //EMainSize, db: defScrM
	SOSPEC_TAG_DEFAULT_TIMEZONE_REGION = 7, //ETimeZone, db: defTZReg
	SOSPEC_TAG_DEFAULT_LATIN_TABLE_INDEX = 8, //ECharacterTable, db: defLatTblInd
	SOSPEC_TAG_DEFAULT_TRIPLE_OFFSET = 9, //ETripleOffset, db: defTrpOff
	SOSPEC_TAG_SUPPORT_HM = 10, //bool, db: sprtHM
	SOSPEC_TAG_ENABLE_AUTO_WIDE = 11, //bool, db: enblAuW
	SOSPEC_TAG_SUPPORT_DATA_SERVICE_APP_TYPE = 12, //EDataServiceSupportType, db: dataSrvAppT
	SOSPEC_TAG_SUPPORT_STANDBY_SCAN = 13, //bool, db: stndbScn
	SOSPEC_TAG_SUPPORT_TIMED_CHILD_LOCK = 14, //bool, db: tmdChldLck
	SOSPEC_TAG_PRIVATE_DATA_SPECIFICATION = 15, //EDVBPDSD, db:  pDS
	SOSPEC_TAG_AVAILABLE_PDSD_0 = 16, //EDVBPDSD, db: avai0
	SOSPEC_TAG_AVAILABLE_PDSD_1 = 17, //EDVBPDSD, db: avai1
	SOSPEC_TAG_AVAILABLE_PDSD_2 = 18, //EDVBPDSD, db: avai2
	SOSPEC_TAG_AVAILABLE_PDSD_3 = 19, //EDVBPDSD, db: avai3
	SOSPEC_TAG_RETUNE_ALTERNATIVE_FREQ_ON_SIGNAL_LOSS = 20, //bool, db: rtnAltFrqOnSigLoss
	SOSPEC_TAG_DISPLAY_ALT_FREQ = 21, //bool, db: dsplAltFrq
	SOSPEC_TAG_SCAN_SUPPORT_TYPE = 22, //EScanSupportType, db: scnSprtTp
	SOSPEC_TAG_TUNER_T2 = 23, //bool, db: tnrT2
	SOSPEC_TAG_DEFAULT_SATELLITE_ID = 24, //ESatelliteId, db: defSatId
	SOSPEC_TAG_UNICODE_CONVERSION_TYPE = 25, //EUnicodeConvType, db: uniConv
	SOSPEC_TAG_TIMEZONE_0 = 26, //int, db: tZ0
	SOSPEC_TAG_TIMEZONE_1 = 27, //int, db: tZ1
	SOSPEC_TAG_TIMEZONE_2 = 28, //int, db: tZ2
	SOSPEC_TAG_TIMEZONE_3 = 29, //int, db: tZ3
	SOSPEC_TAG_TIMEZONE_4 = 30, //int, db: tZ4
	SOSPEC_TAG_TIMEZONE_5 = 31, //int, db: tZ5
	SOSPEC_TAG_TIMEZONE_6 = 32, //int, db: tZ6
	SOSPEC_TAG_TIMEZONE_7 = 33, //int, db: tZ7
	SOSPEC_TAG_TIMEZONE_8 = 34, //int, db: tZ8
	SOSPEC_TAG_SUPPORT_FRANCE_HD_SIMULCAST_SWAP = 35, //ERCNHDSIMulticastPolicy, db: frHDSimSwp
	SOSPEC_TAG_RCN_ASSIGN_ALGORITHM = 36, //EAssignAlgorithm, db: assgnAlg
	SOSPEC_TAG_RCN_COUNTRY_DIFFER = 37, //ECountryDifferentiation, db: cntrDiff
	SOSPEC_TAG_RCN_MIXED_BASE_ON_COUNTRY = 38, //bool, db: mxdBsOnCntr
	SOSPEC_TAG_SERVICE_KEY_TYPE = 39, //EServicekeyType, db: srvKeyT
	SOSPEC_TAG_RCN_CONFLICT_LOCATOR_POLICY = 40, //EConflictLocatorPolicy, db: cnflctLocPol
	SOSPEC_TAG_RCN_CONFLICT_PRIORITY = 41, //ERCNPriority, db: cnflctRCNPr
	SOSPEC_TAG_LCN_ZERO_POLICY = 42, //ELCNZeroPolicy, db: lcnZPol
	SOSPEC_TAG_FOCUS_ON_ID = 43, //EOriginalNetworkId, db: fcsONId
	SOSPEC_TAG_FILTER_SERVICE_HD_LINKAGE_TYPE = 44, //bool, db: fltrSrvHDLnkT
	SOSPEC_TAG_DELETE_CHANNEL_WHEN_RCN_CONFLICT = 45, //bool, db: dltChnlRCNCnflct
	SOSPEC_TAG_IGNORE_OLD_SERVICES = 46, //bool, db: ignrOldSrvs
	SOSPEC_TAG_RCN_RANGE_LIMIT_END = 47, //int, db: rngLmtEnd
	SOSPEC_TAG_RCN_TEMP_START = 48, //int, db: tmpRCNStrt
	SOSPEC_TAG_RCN_CATEGORY_STEP = 49, //int, db: catStp
	SOSPEC_TAG_ENABLE_SDT_OTHER = 50, //bool, db: nblSDTOth
	SOSPEC_TAG_ENABLE_SDT_ACTUAL = 51, //bool, db: nblSDTAct
	SOSPEC_TAG_ENABLE_NIT_OTHER = 52, //bool, db: nblNITOth
	SOSPEC_TAG_ENABLE_BAT = 53, //bool, db: siEnableBAT
	SOSPEC_TAG_USE_COMPRESSED_SCHED_EIT = 54, //bool, db: useCmprSchEIT
	SOSPEC_TAG_DEFAULT_BOUQUET_ID = 55, //int, db: defBqtId
	SOSPEC_TAG_DEFAULT_REGION_ID = 56, //int, db: defRegId
	SOSPEC_TAG_SUPPORT_COUNTRY_AVAILABILITY = 57, //bool, db: cntrAvail
	SOSPEC_TAG_ENABLE_SERVICE_LIST_DESC = 58, //EServiceListOrLCNOnthefly, db: nblSrvLstDsc
	SOSPEC_TAG_COMPOSE_AUDIO_INFO_WITH_EIT = 59, //ERefEitAudioInfo, db: cmpsAdInfoWEIT
	SOSPEC_TAG_TRUST_ACTUAL_EIT_LOCATOR = 60, //bool, db: trstActEITLoc
	SOSPEC_TAG_FILTER_SERVICE_PRIVATE_TEMP_USE = 61, //bool, db: fltrSrvPrvTmpUse
	SOSPEC_TAG_FILTER_SERVICE_FREE_CA_MODE = 62, //EFilterCamMode, db: fltrSrvFrCAMod
	SOSPEC_TAG_FILTER_SERVICE_AVAILABLE_DESC = 63, //bool, db: fltrSrvAvailDsc
	SOSPEC_TAG_SUPPORT_REPLACEMENT_SERVICE = 64, //bool, db: replSrv
	SOSPEC_TAG_SUPPORT_SERVICE_MARK = 65, //bool, db: srvMrk
	SOSPEC_TAG_SUPPORT_NORDIG_LCN_DESC = 66, //bool, db: nrdgLCNDsc
	SOSPEC_TAG_SUPPORT_DYNAMIC_SI = 67, //bool, db: dynSI
	SOSPEC_TAG_SUPPORT_MULTIPLE_LCN = 68, //bool, db: multLCN
	SOSPEC_TAG_SUPPORT_LCN_ON_THE_FLY = 69, //EServiceListOrLCNOnthefly, db: lcnOTF
	SOSPEC_TAG_NIT_RESCAN_CONDITION = 70, //ERescanEventType, db: procNITRscnCond
	SOSPEC_TAG_NIT_SELECT_FAST_SCAN_DESC = 71, //EScanParamAddType, db: procNITSlctFScnDsc
	SOSPEC_TAG_SERVICELIST_SELECTION_TYPE = 72, //integer, db: svcListSelType
	SOSPEC_TAG_TRUST_NIT_TS_LOOP_OTHER = 73, //bool, db: trstNITTSLpOth
	SOSPEC_TAG_NIT_ENABLE_EIT_BARKER = 74, //bool, db: prcsNITEnabEITBrkr
	SOSPEC_TAG_UPDATE_AUDIO_METHOD = 75, //EUpdateAudioMethod, db: updAudMthd
	SOSPEC_TAG_SAVE_CHANNEL_WHEN_AUTO_STORE = 76, //bool, db: svChnlWAStr
	SOSPEC_TAG_SDT_OTHER_POLICY_TYPE = 77, //ESDTOtherPolicy, db: sdtOthPolT
	SOSPEC_TAG_INVISIBLE_SERVICE_TYPE = 78, //EInvisibleType, db: nvsblSrvT
	SOSPEC_TAG_DO_NOT_UPDATE_CH_MAP_IF_NO_SDT = 79, //EExceptPSIUpdateCondition, db: dNtUpdChMapIfNSDT
	SOSPEC_TAG_TOT_OPTION = 80, //ETOTOption, db: totOpt
	SOSPEC_TAG_CRID = 81, //bool, db: crd
	SOSPEC_TAG_MONITORING_EVENT = 82, //bool, db: monEv
	SOSPEC_TAG_IGNORE_PAT_TIMEOUT = 83, //bool, db: ignrPATTO
	SOSPEC_TAG_CRID_STANDARD_TYPE = 84, //ECRIDStandardType, db: crdStdT
	SOSPEC_TAG_USE_PRIMARY_CHANNEL_NAVIGATION = 85, //bool, db: usePrmChNav
	SOSPEC_TAG_SUPPORT_TTX = 86, //bool, db: ttx
	SOSPEC_TAG_SUPPORT_SBT = 87, //bool, db: sbt
	SOSPEC_TAG_DEFAULT_SUBTITLE_ON_OFF_WHEN_RESET = 88, //bool, db: defSubOOWRst
	SOSPEC_TAG_AUTO_SBT_NO_MATCH_NO_DISPLAY = 89, //bool, db: aSBTNMtchNDspl
	SOSPEC_TAG_SHOW_HOH_IF_SBT_MODE_NORMAL = 90, //bool, db: shHOHIfSBTMdNrm
	SOSPEC_TAG_SBT_PRIORITY = 91, //ESBTPriority, db: sbtPrio
	SOSPEC_TAG_AUDIO_HEAAC_HAVE_PRIORITY_ORDER = 92, //EAudioPrior, db: audHEAACHvPrioOrd
	SOSPEC_TAG_MHEG_EPG = 93, //bool, db: mhegEPG
	SOSPEC_TAG_SIGNAL_INFO_TUNE = 94, //bool, db: sgnInfTn
	SOSPEC_TAG_EPG_TUNE_AROUND = 95, //bool, db: epgTnArnd
	SOSPEC_TAG_PARENTAL_LOCK = 96, //EParentalLock, db: prntlLck
	SOSPEC_TAG_FULL_SEARCH_PARAM_ADD = 97, //bool, db: fSrchParA
	SOSPEC_TAG_IGNORE_CI = 98, //bool, db: ignrCI
	SOSPEC_TAG_DISPLAY_NETWORK_NAME = 99, //bool, db: dsplNetNm
	SOSPEC_TAG_EDIT_CHANNEL_NUMBER = 100, //EEditChannelNumberCondition, db: edtChnlNum
	SOSPEC_TAG_SUPPORT_EPG_TYPE = 101, //ESupportEPGType, db: sprtEPGT
	SOSPEC_TAG_PARENTAL_RATING_INIT_VAL = 102, //EParentalRatingInit, db: prntlRatInitV
	SOSPEC_TAG_PARENTAL_LOCK_WHEN_CHANNEL_CHANGE = 103, //bool, db: prntlLckWChnlCh
	SOSPEC_TAG_PARENTAL_LOCK_WITH_EIT = 104, //EParantalLeckWithEIT, db: prntlLckWEIT
	SOSPEC_TAG_HIDE_43_SCREEN_SIZE = 105, //bool, db: hid43ScrnSz
	SOSPEC_TAG_HIDE_EDIT_CHANNEL_NUMBER = 106, //bool, db: hidEdtChnlNum
	SOSPEC_TAG_COUNTRY_GROUP = 107, //ECountryGroup, db: cntrGrp
	SOSPEC_TAG_MHEG_SUPPORT = 108, //bool, db: mhegSprt
	SOSPEC_TAG_MHP_SUPPORT = 109, //bool, db: mhpSprt
	SOSPEC_TAG_USE_SIMPLE_CHINESE = 110, //bool, db: useSmplChnse
	SOSPEC_TAG_DEFAULT_DESC_LANGUAGE = 111, //ELanguageCode, db: defDescLan
	SOSPEC_TAG_EXTENDED_EVENT_INCLUDES_SHORT_EVENT = 112, //bool, db: extEvIncShrtEv
	SOSPEC_TAG_EIT_RUNNING_STATUS_TRUSTED = 113, //bool, db: eitRunStatTrst
	SOSPEC_TAG_CHARACTER_CODE_BYTE = 124, //unsigned int, db: charCB
	SOSPEC_TAG_ENCODING_SECOND_BYTE = 125, //unsigned int, db: encSecB
	SOSPEC_TAG_ENCODING_THIRD_BYTE = 126, //unsigned int, db: encThrdB
	SOSPEC_TAG_LCN_RANGE_LIMIT_END = 132, //unsigned int, db : lngLmtEnd	
	SOSPEC_TAG_DEFAULT_SERVICE_LIST_NAME_LANGUAGE = 133, //ELanguageCode, db: defSrvLstNmLng
    SOSPEC_TAG_KEEP_RCN_MODIFIED_BY_USER = 134, //bool, db : rcnKeepModByUsr
	SOSPEC_TAG_MAX,
} ESOSpecTag;

typedef enum
{
	SOSPEC_TAG_ANALOG_COUNTRY = 114, //system_info_country_e, db: aCntr
	SOSPEC_TAG_ANALOG_COUNTRY_CODE = 115, //ECountryCode, db: aCntrC
	SOSPEC_TAG_ANALOG_MIN_ATV_AIR_CH_NUMBER = 116, //int, db: minAChN
	SOSPEC_TAG_ANALOG_MAX_ATV_AIR_CH_NUMBER = 117, //int, db: maxAChN
	SOSPEC_TAG_ANALOG_MIN_ATV_CABLE_CH_NUMBER = 118, //int, db: minCCHN
	SOSPEC_TAG_ANALOG_MAX_ATV_CABLE_CH_NUMBER = 119, //int, db: maxCCHN
	SOSPEC_TAG_ANALOG_SECAM_MODE = 120, //bool, db: secam
	SOSPEC_TAG_ANALOG_DEFAULT_SOUND_SYSTEM = 121, //EChannelSound, db: defSndSys
	SOSPEC_TAG_ANALOG_DEFAULT_COLOR_SYSTEM = 122, //EChannelColor, db: defColSys
	SOSPEC_TAG_ANALOG_ATM = 123, //EATM, db: atm
	SOSPEC_TAG_ANALOG_ONE_MAP = 127, //bool, db: oneMap
}  ESOSpecAnalogTag;

#endif //_SOSPECTAG_H_