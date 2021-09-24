/** 
 * @file ISOSpecControl.h
 * @brief Application interface for setting country specs independent from pipeline.
 *
 * Copyright 2014 by Samsung Electronics, Inc.,
 * 
 * This software is the confidential and proprietary information
 * of Samsung Electronics, Inc. ("Confidential Information"). You
 * shall not disclose such Confidential Information and shall use
 * it only in accordance with the terms of the license agreement
 * you entered into with Samsung.
 */


#ifndef _ISOSPECCONTROL_H_
#define _ISOSPECCONTROL_H_


#include "MarshallingMarks.h"
#include "SOSpecDataType.h"
#include "ServiceNavigationDataType.h"
#include "ScanDataDataType.h"
#include "TVServiceDataType.h"


class ISOSpecControl
{
public:
	virtual ~ISOSpecControl() {};

	// TODO Duende - to be removed after 25.12.2014
	virtual int ChangeDigitalSOSpec(_IN_ ECountry country) = 0;

	/**
	 * @brief Sets service operator for given TV mode
	 * @param [in] tvMode TV mode
	 * @param [in] broadcaster Service Operator
	 * @return When calling method succeeds returns > 0.
	 *
	 *  @remark SIGNAL_COUNTRY_CHANGED is sent after changing SOSpecs
	 *  @remark This function is to be used for quick scan
	 *  @remark Current country will be used by this method
	 *
	 *	@paragraph <Example>
	 *	This example shows how to create ISOSpecControl interface and use it for setting broadcaster
	 *
	 *	@verbatim
	 *	ISOSpecControl * pSOSpecControl = NULL;
	 *	TVServiceAPI::CreateSOSpecControl(&pSOSpecControl);
	 *	if(pScanData->ChangeDigitalSOSpec(TSTvMode(ANTENNA_MODE_CABLE, SERVICE_MODE_DVB), BROADCASTER_ZIGGO) > 0)
	 *	{
	 *		//Do something when operation successful
	 *	}
	 *	@endverbatim
	 */
	virtual int ChangeDigitalSOSpec(_IN_ const TSTvMode & tvMode, _IN_ EBroadCaster broadcaster) = 0;

	/**
	 * @brief Sets country for digital television for all pipelines
	 * @remark Value of country identifier should be compatible with system_info_country_e.
	 * @param [in] country Country.
	 * @return When calling method succeeds returns > 0.
	 *
	 * @remark SIGNAL_COUNTRY_CHANGED is sent after changing SOSpecs
	 * @remark Broadcaster is set to BROADCASTER_UNKNOWN
	 * @remark TV mode for all pipelines shall be reset to default value
	 * @remark Service lists, ... current service, ... are reset
	 *
	 *	@paragraph <Example>
	 *	This example shows how to create ISOSpecControl interface and use it for setting new digital country
	 *
	 *	@verbatim
	 *	ISOSpecControl * pSOSpecControl = NULL;
	 *	TVServiceAPI::CreateSOSpecControl(&pSOSpecControl);
	 *	if(pScanData->ChangeDigitalSOSpec(COUNTRY_FRA) > 0)
	 *	{
	 *		//Do something when operation successful
	 *	}
	 *	@endverbatim
	 */
	virtual int ChangeDigitalSOSpec(_IN_ int country) = 0;

	/**
	 * @brief Sets country for analog television for all pipelines
	 * @param [in] country Country
	 * @return When calling method succeeds returns > 0.
	 *
	 *	@paragraph <Example>
	 *	This example shows how to create ISOSpecControl interface and use it for setting new analog country
	 *
	 *	@verbatim
	 *	ISOSpecControl * pSOSpecControl = NULL;
	 *	TVServiceAPI::CreateSOSpecControl(&pSOSpecControl);
	 *	if(pScanData->ChangeAnalogSOSpec(SYSTEM_INFO_COUNTRY_GERMANY) > 0)
	 *	{
	 *		//Do something when operation successful
	 *	}
	 *	@endverbatim
	 */
	virtual int ChangeAnalogSOSpec(_IN_ ECountry country) = 0;

	/**
	 * @brief Sets country for analog television for all pipelines
	 * @remark Value of country identifier should be compatible with system_info_country_e.
	 * @param [in] country Country
	 * @return When calling method succeeds returns > 0.
	 *
	 *	@paragraph <Example>
	 *	This example shows how to create ISOSpecControl interface and use it for setting new analog country
	 *
	 *	@verbatim
	 *	ISOSpecControl * pSOSpecControl = NULL;
	 *	TVServiceAPI::CreateSOSpecControl(&pSOSpecControl);
	 *	if(pScanData->ChangeAnalogSOSpec(COUNTRY_GERMANY) > 0)
	 *	{
	 *		//Do something when operation successful
	 *	}
	 *	@endverbatim
	 */
	virtual int ChangeAnalogSOSpec(_IN_ int country) = 0;

	/**
	 * @brief Gets service operator for specified TV mode
	 * @param [in] tvMode Tv mode
	 * @param[out] broadcaster Broadcaster ID(e.g. BROADCASTER_UPC)
	 * @return When calling method succeeds returns > 0.
	 *
	 *	@paragraph <Example>
	 *	This example shows how to create ISOSpecControl interface and use it for getting the current broadcaster for digital cable
	 *
	 *	@verbatim
	 *	ISOSpecControl * pSOSpecControl = NULL;
	 *	TVServiceAPI::CreateSOSpecControl(&pSOSpecControl);
	 *	EBroadCaster broadcaster = INVALID;
	 *	if(pScanData->GetBroadcaster(TSTvMode(ANTENNA_MODE_CABLE, SERVICE_MODE_DVB), broadcaster) > 0)
	 *	{
	 *		//Do something when operation successful
	 *	}
	 *	@endverbatim
	 */
	virtual int GetBroadcaster(_IN_ const TSTvMode & tvMode, _OUT_ EBroadCaster & broadcaster) const = 0;

	/**
	 * @brief Gets a default service operator corresponding to current country in specified TV mode.
	 * @param [in] tvMode Tv mode
	 * @param[out] broadcaster Broadcaster ID(e.g. BROADCASTER_UPC)
	 * @return When calling method succeeds returns > 0.
	 *
	 *	@paragraph <Example>
	 *	This example shows how to create ISOSpecControl interface and use it for getting the default broadcaster for digital cable in current country
	 *
	 *	@verbatim
	 *	ISOSpecControl * pSOSpecControl = NULL;
	 *	TVServiceAPI::CreateSOSpecControl(&pSOSpecControl);
	 *	EBroadCaster defaultBroadcaster = INVALID;
	 *	if(pScanData->GetDefaultBroadcaster(TSTvMode(ANTENNA_MODE_CABLE, SERVICE_MODE_DVB), defaultBroadcaster) > 0)
	 *	{
	 *		//Do something when operation successful
	 *	}
	 *	@endverbatim
	 */
	virtual int GetDefaultBroadcaster(_IN_ const TSTvMode & tvMode, _OUT_ EBroadCaster & broadcaster) const = 0;

	/**
	 * @brief Checks whether a broadcaster is supported
	 * @param [in] broadcaster Broadcaster ID
	 * @param[out] supported true if the broadcaster is supported in current country, false otherwise
	 * @param [in] country Country for which checking will be performed
	 * @remarks If country is not provided, currently set country will be used.
	 * @remarks Value of country identifier should be compatible with system_info_country_e.
	 * @return When calling method succeeds returns > 0.
	 *
	 *	@paragraph <Example>
	 *	This example shows how to create ISOSpecControl interface and use it for checking if BROADCASTER_ZIGGO is supported in current country
	 *
	 *	@verbatim
	 *	ISOSpecControl * pSOSpecControl = NULL;
	 *	TVServiceAPI::CreateSOSpecControl(&pSOSpecControl);
	 *	EBroadCaster broadcaster = BROADCASTER_ZIGGO;
	 *	bool supported = false;
	 *	if(pScanData->CheckBroadcasterSupported(BROADCASTER_ZIGGO, supported) > 0)
	 *	{
	 *		//Do something when operation successful
	 *	}
	 *	@endverbatim
	 */
	virtual int CheckBroadcasterSupported( _IN_ EBroadCaster broadcaster, _OUT_ bool & supported, int country = INVALID) const = 0;
};

#endif // _ISOSPECCONTROL_H_

