/** 
 * @file ISatelliteControl.h
 * @brief Application interface for controlling satellite equipment.
 *
 * Copyright 2013 by Samsung Electronics, Inc.,
 * 
 * This software is the confidential and proprietary information
 * of Samsung Electronics, Inc. ("Confidential Information"). You
 * shall not disclose such Confidential Information and shall use
 * it only in accordance with the terms of the license agreement
 * you entered into with Samsung.
 */


#ifndef _ISATELLITECONTROL_H_
#define _ISATELLITECONTROL_H_


#include "MarshallingMarks.h"
#include "TVServiceDataType.h"
#include "SatelliteControlDataType.h"
#include "SatelliteSettingsDataType.h"


class ISatelliteControl
{
protected:
	virtual ~ISatelliteControl(){};


public:

	/**
	 * @brief Control satellite positioner.
	 * @param [in] command Positioner command - for details, see EPositionerCommand description.
	 * @param [in] param Command's parameter - depends on requested command (some commands to not require parameters).
	 * @return Returns 1 if sending command to positioner succeeded, 0 otherwise.
	 * @return When calling method failed returns -1.
	 */
	virtual int SendPositionerCommand( _IN_ EPositionerCommand command, _IN_ int param = INVALID ) = 0;

	/**
	 * @brief Control SatCR.
	 * @remarks SatCR (satellite channel routing) is single cable installation, combining multiple input satellite signals onto a single cable.
	 * @param [in] tunerId Tuner to be controlled.
	 * @param [in] satCRCmd SatCR command.
	 * @param [in] satCRSettings Parameters for the command sent to SatCR controller.
	 * @return Returns 1 if the command was successfully sent.
	 * @return When calling method failed returns -1.
	 */
	virtual int SendSatCRCommand( _IN_ unsigned short tunerId, _IN_ ESatCRCommand satCRCmd, _IN_ const TSSatCRSettings& satCRSettings ) = 0;

	/**
	 * @brief Gets information if Lnb Power is disabled / enabled
	 * @param [out] enable Determines if Lnb Power is enabled (true) or disabled (false).
	 * @return Returns 1.
	 * @return When calling method failed returns -1.
	 *
	 *	@paragraph <Example>
	 *	This code will get information if Lnb Power is enabled
	 *	
	 *	@verbatim
	 *	ISatelliteControl* satelliteCtrl;
	 *	TVServiceAPI::CreateSatelliteControl(&satelliteCtrl);
	 *	
	 *	bool enabled;
	 *	if(satelliteCtrl->GetLnbPower(enabled) == 1)
	 *	{
	 *		//Value was retrieved
	 *		if(enabled)
	 *		{
	 *			// Lnb Power is enabled
	 *		}
	 *		else
	 *		{
	 *			// Lnb Power is disabled
	 *		}
	 *	}
	 *	@endverbatim
	 */
	virtual int GetLnbPower(_OUT_ bool& enable) = 0;

	/**
	 * @brief Enables/Disables Lnb Power
	 * @param [in] enable Determines if Lnb Power should be enabled (true) or disabled (false).
	 * @return Returns 1 if Lnb Power was successfully enabled/disabled, 0 otherwise.
	 * @return When calling method failed returns -1.
	 *
	 *	@paragraph <Example>
	 *	This code will get information if Lnb Power is enabled
	 *	
	 *	@verbatim
	 *	ISatelliteControl* satelliteCtrl;
	 *	TVServiceAPI::CreateSatelliteControl(&satelliteCtrl);
	 *	
	 *	if(satelliteCtrl->SetLnbPower(true) > 0)
	 *	{
	 *		//Lnb Power successfully set
	 *	}
	 *	@endverbatim
	 */
	virtual int SetLnbPower(_IN_ bool enable) = 0;

};


#endif //  _ISATELLITECONTROL_H_

