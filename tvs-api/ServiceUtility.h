/** 
 * @file ServiceUtility.h
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


#ifndef _SERVICEUTILITY_H_
#define _SERVICEUTILITY_H_

#include "ServiceDataType.h"
#include "ServiceNavigationDataType.h"
#include "ScanDataDataType.h"
#include "SourceControlDataType.h"

#include <list>


class TCServiceUtility
{
public:

	static bool IsDigitalChannelType(EChannelType chType);

	static bool IsAnalogChannelType(EChannelType chType);

	static EServiceType ServiceTypeFromDVBService(EDVBServiceType dvbService);

	static EServiceType ServiceTypeFromISDBService(EISDBServiceType isdbService);

	/**
	 * @brief Convert channel type to antenna mode.
	 * @param [in] channelType Channel type.
	 * @return Antenna mode.
	 */
	static EAntennaMode ChannelTypeToAntennaMode( EChannelType channelType );

	/**
	 * @brief Convert scan mode to antenna mode.
	 * @param [in] scanMode Scan mode.
	 * @return Antenna mode.
	 */
	static EAntennaMode ScanModeToAntennaMode( EScanMode );

	/**
	 * @brief Convert service mode to service profile.
	 * @param [in] serviceMode Service mode to be converted.
	 * @return Service profile.
	 */
	static EServiceProfile ServiceModeToServiceProfile(EServiceMode serviceMode);
	
	/**
	 * @brief Convert service profile to service mode.
	 * @param [in] serviceProfile Service profile to be converted.
	 * @return Service mode.
	 */
	static EServiceMode ServiceProfileToServiceMode(EServiceProfile serviceProfile);

	/**
	 * @brief Convert antenna mode to matching digital channel type
	 * @param [in] antennaMode antenna mode 
	 * @return Channel type
	 */
	static EChannelType AntennaModeToDigitalChannelType(EAntennaMode antennaMode);

	/**
	 * @brief Convert antenna mode to matching analog channel type
	 * @param [in] antennaMode antenna mode 
	 * @return Channel type
	 */
	static EChannelType AntennaModeToAnalogChannelType(EAntennaMode antennaMode);


	static bool FlagSourceTypeUsingSI(ESource source);

	/**
	 * @brief Checks whether tv mode is a private satellite mode.
	 * @param[in] tvMode TV mode to be checked.
	 * @return True if tv mode is a private satellite mode, false otherwise.
	 */
	static bool IsPrivateSatelliteMode(const TSTvMode& tvMode);

	/**
	* @brief Convert service mod to satellite package id.
	* @param [in] serviceMode Defines service mode.
	* @return ESatellitePackageId.
	*/
	static ESatellitePackageId ServiceModeToSatellitePackageId(EServiceMode serviceMode);


	/**
	* @brief Get list of channel types related to input tv mode.
	* @param[in] tvMode TvMode for which you want to obtain list of channel types.
	* @param[out] channelTypes Buffer for channel types.
	*/
	static void GetChannelTypes( const TSTvMode& tvMode, std::list<int>& channelTypes );

	/**
	* @brief Get list of service profiles related to input tv mode.
	* @param[in] tvMode TvMode for which you want to obtain list of service profiles.
	* @param[out] serviceProfiles Buffer for service profiles.
	*/
	static void GetServiceProfiles( const TSTvMode& tvMode, std::list<int>& serviceProfiles );

	/**
	* @brief Get list of service types specific for given specification (like ATSC, DVB, etc) which define TV/Radio/Other service category.
	* @param[in] tvMode TvMode for which you want to obtain service types list.
	* @param[in] serviceCategory Service category for which you want to obtain list of service types.
	* @param[out] serviceTypes Buffer for service types.
	*/
	static void GetServiceTypes( const TSTvMode& tvMode, EServiceType serviceCategory, std::list<int>& serviceTypes );


};



#endif // _SERVICEUTILITY_H_

