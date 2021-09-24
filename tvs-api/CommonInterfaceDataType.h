/** 
 * @file CommonInterfaceDataType.h
 * @brief Types and enums related with Common Interface.
 *
 * Copyright 2014 by Samsung Electronics, Inc.,
 * 
 * This software is the confidential and proprietary information
 * of Samsung Electronics, Inc. ("Confidential Information"). You
 * shall not disclose such Confidential Information and shall use
 * it only in accordance with the terms of the license agreement
 * you entered into with Samsung.
 */

#ifndef _COMMONINTERFACEDATATYPE_H_
#define _COMMONINTERFACEDATATYPE_H_

//*****************************************************************************
//*****************************************************************************
//
// Consts
//
//*****************************************************************************
//*****************************************************************************

///////////////////////////////////////////////////////////////////////////////

/**
 * @brief Enum for unknown answer length.
 */
enum
{
    MMI_ENQUIRY_EXPECTED_ANSWER_LENGTH_UNKNOWN = 0xFF,
};

/**
 * @brief Enum for ID length.
 */
enum
{
    CAM_ID_LENGTH = 8,
};

enum
{
    CAM_PIN_LENGTH_MAX = 8,
};

enum
{
    CAM_OPERATOR_PROFILE_NAME_LENGTH_MAX = 256,
};

///////////////////////////////////////////////////////////////////////////////


//*****************************************************************************
//*****************************************************************************
//
// Enums
//
//*****************************************************************************
//*****************************************************************************

///////////////////////////////////////////////////////////////////////////////

/**
 * @brief Conditional Acces State of a service
 */
enum ECaState
{
    CA_UNKNOWN,   // Default value for CA state, when the state is yet unknown
    CA_FTA,       // Free to air
    CA_SCRAMBLED, // Scrambled channel
};

/**
 * @brief Kind of application mode.
 */
typedef enum
{
    CI_APPLICATION_TYPE_CA       = 0x01,
    CI_APPLICATION_TYPE_EPG      = 0x02,
    CI_APPLICATION_TYPE_RESERVED = 0x03,
} ECIApplicationType;

///////////////////////////////////////////////////////////////////////////////

/**
 * @brief Enum for application answer.
 * @remark See ci-app.
 */
typedef enum
{
    MMI_ANSWER_ID_CANCEL   = 0x00,
    MMI_ANSWER_ID_ANSWER   = 0x01,
    MMI_ANSWER_ID_RESERVED = 0x02,
} EMmiAnswerId;

///////////////////////////////////////////////////////////////////////////////

/**
 * @brief       Indicates what response is required from the application to a CA PMT object
 * @remark      see ca_pmt_cmd_id table in En50221.V1
 */
typedef enum
{
    ECAPMTCMD_OKDESCR      = 0x01,
    ECAPMTCMD_OKMMI        = 0x02,
    ECAPMTCMD_QUERY        = 0x03,
    ECAPMTCMD_NOT_SELECTED = 0x04,
    ECAPMTCMD_RFU          // any other value
} ECaPmtCmd;

///////////////////////////////////////////////////////////////////////////////

/**
 * @brief       CAM upgrade mode. (see section 14.2.5.2 of CI+ 1.2)
 */
typedef enum
{
    CAM_UPGRADE_MODE_DELAYED   = 0x00,
    CAM_UPGRADE_MODE_IMMEDIATE = 0x01,
} ECamUpgradeMode;

///////////////////////////////////////////////////////////////////////////////

/**
 * @brief       CAM upgrade process answer. (see section 14.2.5.3 of CI+ 1.2)
 */
typedef enum
{
    CAM_UPGRADE_ANSWER_NO  = 0x00,
    CAM_UPGRADE_ANSWER_YES = 0x01,
    CAM_UPGRADE_ANSWER_ASK = 0x02,
} ECamUpgradeAnswer;

///////////////////////////////////////////////////////////////////////////////

/**
 * @brief       CAM upgrade status.
 */
typedef enum
{
    CAM_UPGRADE_STATUS_RESET,           // param.s[1]= N/A                               , param.s[2]= N/A
    CAM_UPGRADE_STATUS_PROGRESS,        // param.s[1]= download progress status 0 to 100 , param.s[2]= N/A
    CAM_UPGRADE_STATUS_REPLY_REQUESTED, // param.s[1]= sessionId with the CAM            , param.s[2]= upgrade type (see ECamUpgradeMode)
} ECamUpgradeStatus;

///////////////////////////////////////////////////////////////////////////////

/**
 * @brief       CAM Operator Profile status change type.
 */
typedef enum
{
    CAM_OP_BEFORE_UPDATE_ENQUIRY_DONT_ASK = 0x00,
    CAM_OP_BEFORE_UPDATE_ENQUIRY_ASK      = 0x01,
} ECamOperatorBeforeUpdateEnquiry;

///////////////////////////////////////////////////////////////////////////////

/**
 * @brief       CAM Operator Profile status change type.
 */
typedef enum
{
    CAM_OP_STATUS_NEW_OP_INSERTED,                        // param.s[2]= 0 if type 0, 1 if type 1            , param.s[3]= N/A
    CAM_OP_STATUS_INSTALLATION_SUCCESS,                   // param.s[2]=antennaMode                          , param.s[3]=serviceMode
    CAM_OP_STATUS_INSTALLATION_FAILED,                    // param.s[2]=antennaMode                          , param.s[3]=serviceMode
    CAM_OP_STATUS_UPDATE_READY_TO_START,                  // param.s[2]= N/A                                 , param.s[3]= N/A
    CAM_OP_STATUS_UPDATE_SUCCESS,                         // param.s[2]=antennaMode                          , param.s[3]=serviceMode
    CAM_OP_STATUS_UPDATE_FAILED,                          // param.s[2]=antennaMode                          , param.s[3]=serviceMode
    CAM_OP_STATUS_ENTITLEMENT_CHANGE,                     // param.s[2]= N/A                                 , param.s[3]= N/A
    CAM_OP_STATUS_REFRESH_REQUEST,                        // param.s[2]=(see ECamOperatorBeforeUpdateEnquiry), param.s[3]= N/A
    CAM_OP_STATUS_REFRESH_REQUEST_AND_ENTITLEMENT_CHANGE, // param.s[2]=(see ECamOperatorBeforeUpdateEnquiry), param.s[3]= N/A
    CAM_OP_STATUS_AUTHENTICATION_REMOVED                  // param.s[2]=antennaMode                          , param.s[3]=serviceMode
} ECamOperatorProfileStatus;

///////////////////////////////////////////////////////////////////////////////

/**
 * @brief See description of a field 'profile_type' (in 'operator_status_body' APDU).
 */
typedef enum
{
    OP_PROFILE_TYPE_NON_PROFILED = 0x00,
    OP_PROFILE_TYPE_PROFILED     = 0x01,
} EOpProfileType;

///////////////////////////////////////////////////////////////////////////////

/**
 * @brief       CAM PIN answer.
 */
typedef enum
{
    CAM_PIN_CODE_STATUS_BAD,
    CAM_PIN_CODE_STATUS_CAM_BUSY,
    CAM_PIN_CODE_STATUS_CORRECT,
    CAM_PIN_CODE_STATUS_UNCONFIRMED,
    CAM_PIN_CODE_STATUS_VIDEO_BLANKING_NOT_REQUIRED,
    CAM_PIN_CODE_STATUS_CONTENT_STILL_SCRAMBLED,
    CAM_PIN_CODE_STATUS_VBNR,
    CAM_PIN_CODE_SUPPORTED,         // Value never sent by CAM. This is sent after CAM declares support of CAM Pin capabilities
} ECamPinCodeStatus;

///////////////////////////////////////////////////////////////////////////////

/**
 * @brief  Enum for answer from CAM after write data.
 */
typedef enum
{
    WRITE_CIP_NA       = 0,
    WRITE_CIP_SUCCESS  = 1,
    WRITE_CIP_FAIL     = 2,
} EWriteCipKeyResult;

///////////////////////////////////////////////////////////////////////////////

/**
 * @brief MMI message type
 */
enum ECiMmiStatus
{
    CI_MMI_STATUS_SESSION_CLOSED,              // param.s[2]= delay    , param.s[3]= N/A
    CI_MMI_STATUS_ENQUIRY_RECEIVED,            // param.s[2]= objectId , param.s[3]= N/A
    CI_MMI_STATUS_TEXT_RECEIVED,               // param.s[2]= objectId , param.s[3]= N/A
    CI_MMI_STATUS_MENU_RECEIVED,               // param.s[2]= objectId , param.s[3]= N/A
    CI_MMI_STATUS_LIST_RECEIVED,               // param.s[2]= objectId , param.s[3]= N/A

    // other, not MMI related options
    CI_OTHER_STATUS_CAM_COMPATIBILITY_ISSUE,   // param.s[2]= N/A , param.s[3]= N/A
    CI_OTHER_STATUS_TTX_STATUS_CHANGE,         // param.s[2]= N/A , param.s[3]= N/A
};

///////////////////////////////////////////////////////////////////////////////

/**
 * @brief CAM state as in en50221
 */
typedef enum
{
    CAM_STATUS_NO_CAM = 0x00,       // No CAM in slot or CAM has not got Application Info ready yet
    CAM_STATUS_READY = 0x01,        // CAM in slot and Application Info is ready
} ECamStatus;

///////////////////////////////////////////////////////////////////////////////

/** TODO_CI deprecated
 * @brief Indicates who should mute AV.
 */
enum EParentalRatingMuteHandler
{
    PARENTAL_RATING_MUTE_HANDLER_UNSPECIFIED,                    // Can't decide yet. Host needs to mute Audio, Video, Subtitle. CIM module is still waiting for information about current service status.
    PARENTAL_RATING_MUTE_HANDLER_IS_HOST,                        // HOST mutes Audio, Video and Subtitle
    PARENTAL_RATING_MUTE_HANDLER_IS_CAM,                         // CAM mutes Audio, Video and Subtitle
    PARENTAL_RATING_MUTE_HANDLER_IS_HOST_REQUEST_NOT_NEEDED,     // HOST mutes Audio, Video and Subtitle. Host mutes by its own without request from tvs-ci
    PARENTAL_RATING_MUTE_HANDLER_IS_HOST_REQUEST_NEEDED,         // HOST mutes Audio, Video and Subtitle. Host mutes on request from tvs-ci (watch and buffer case)
};

///////////////////////////////////////////////////////////////////////////////

/**
 * @brief Indicates who should show PIN dialog window
 */
enum EPinWindowShowHandler
{
    PIN_WINDOW_SHOW_HANDLER_UNSPECIFIED,               // Can't decide yet. CIM module is still waiting for information about current service status. HOST PIN window is blocked.
    PIN_WINDOW_SHOW_HANDLER_IS_CAM,                    // CAM will show PIN dialog window. HOST PIN dialog window should be blocked.
    PIN_WINDOW_SHOW_HANDLER_IS_HOST,                   // CAM won't show PIN dialog window. HOST PIN dialog window should be used.
    PIN_WINDOW_SHOW_HANDLER_IS_CAM_REQUEST_NOT_NEEDED, // CAM will show PIN dialog window by its own. HOST PIN dialog window should be blocked.
    PIN_WINDOW_SHOW_HANDLER_IS_CAM_REQUEST_NEEDED,     // CAM will show PIN dialog window, but it should be requested by HOST. HOST PIN dialog window should be blocked. (exaple case: showing PIN window on FTA service)
};

///////////////////////////////////////////////////////////////////////////////

/**
 * @brief SAS connection status
 */
enum ESasConnectionStatus
{
    SAS_CONNECTION_STATUS_CONNECT_OK                  = 0x00,
    SAS_CONNECTION_STATUS_CONNECT_DENIED_NO_APP       = 0x01,
    SAS_CONNECTION_STATUS_CONNECT_DENIED_TOO_MANY_APP = 0x02
};

///////////////////////////////////////////////////////////////////////////////

/**
 * @brief SAS status
 */
enum ECamSasStatus
{
    CAM_SAS_STATUS_SESSION_OPEN,          // param.s[0]= N/A,              param.s[2]= N/A                                             , param.s[3]= N/A
    CAM_SAS_STATUS_SESSION_CLOSED,        // param.s[0]= connectionHandle, param.s[2]= N/A                                             , param.s[3]= N/A
    CAM_SAS_STATUS_CONNECT_RESULT,        // param.s[0]= connectionHandle, param.s[2]= connection result from ESasConnectionResult     , param.s[3]= N/A
    CAM_SAS_STATUS_DATA_RECEIVED,         // param.s[0]= connectionHandle, param.s[2]= dataId used for data retrieval using GetSasData , param.s[3]= N/A
};

///////////////////////////////////////////////////////////////////////////////

/**
 * @brief Operator Profile installation triggers
 */
enum EOperatorProfileInstallation
{
   OP_INSTALLATION_INACTIVE,            // Operator Profile installation is not active
   OP_INSTALLATION_ACTIVATED_PNP,       // Operator Profile installation was triggered by Setup Wizard
   OP_INSTALLATION_ACTIVATED_AUTO_TUNE  // Operator Profile installation was triggered by Auto Store
};

///////////////////////////////////////////////////////////////////////////////

/**
 *  @brief masks for db/commoninterface/ci_settings vconf value
 */
enum ECiSettingsMask
{
    CI_SETTINGS_MASK_BARKER_FLAG_ON  = 0x00000001,
    CI_SETTINGS_MASK_BARKER_FLAG_OFF = 0xfffffffe,
};

///////////////////////////////////////////////////////////////////////////////

/**
 *  @brief
 */
enum ETVSHandleProperty
{
    TVSHANDLE_PROPERTY_TUNER_LOCK_FAIL,
    TVSHANDLE_PROPERTY_TUNER_LOCK_SUCCESS,
    TVSHANDLE_PROPERTY_PID_SET_DONE,
};

///////////////////////////////////////////////////////////////////////////////

#endif  /* _COMMONINTERFACEDATATYPE_H_ */

