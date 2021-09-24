/** 
 * @file IChannelData.h
 * @brief Application interface for manage channel data.
 *
 * Copyright 2014 by Samsung Electronics, Inc.,
 *
 * This software is the confidential and proprietary information
 * of Samsung Electronics, Inc. ("Confidential Information"). You
 * shall not disclose such Confidential Information and shall use
 * it only in accordance with the terms of the license agreement
 * you entered into with Samsung.
 */


#ifndef _ICHANNELDATA_H_
#define _ICHANNELDATA_H_

#include "MarshallingMarks.h"
#include "ServiceNavigationDataType.h"
#include "ScanChannelDataDataType.h"
#include <list>

class IChannelData
{
protected:
	virtual ~IChannelData(){};

public:

	/**
	* @brief Get frequency for specified channel number.
	* @remarks Frequency is returned in [kHz].
	* @param [in] tvMode TV mode.
	* @param [in] channelNumber Channel number.
	* @param [in] freqType Type of frequency (channel number might depend on frequency type).
	* @param [out] freq Frequency matching specified channel number.
	* @return When calling method failed returns -1.
	*/
	virtual int GetDigitalFrequency( _IN_ const TSTvMode& tvMode, _IN_ unsigned short channelNumber, _IN_ EFrequencyType freqType, _OUT_  int& freq) = 0;
	
	/**
	* @brief Get channel number for specified frequency.
	* @param [in] tvMode TV mode.
	* @param [in] freq Frequency in [kHz].
	* @param [in] freqType Type of frequency (channel number might depend on frequency type).
	* @param [out] channelNumber TChannel number matching specified frequency.
	* @return When calling method failed returns -1.
	*/
	virtual int GetDigitalChannelNumber( _IN_ const TSTvMode& tvMode, _IN_ int freq, _IN_ EFrequencyType freqType, _OUT_ unsigned short& channelNumber ) = 0;
	
	/**
	* @brief Get list of channels to be scanned during auto store.
	* @param [in] tvMode TV mode.
	* @param [out] channels List of channels.
	* @return When calling method failed returns -1.
	*/
	virtual int GetDigitalChannels( _IN_ const TSTvMode& tvMode, _OUT_ std::list<TSChannelData*>& channels ) = 0;


	/**
	* @brief Get frequency for specified channel number.
	* @remarks Frequency is returned in [kHz].
	* @param [in] tvMode TV mode.
	* @param [in] channelNumber Channel number.
	* @param [in] freqType Type of frequency (channel number might depend on frequency type).
	* @param [out] freq Frequency matching specified channel number.
	* @return When calling method failed returns -1.
	*/
	virtual int GetAnalogFrequency( _IN_ const TSTvMode& tvMode, _IN_ unsigned short channelNumber, _OUT_  int& freq) = 0;
	
	/**
	* @brief Get channel number for specified frequency.
	* @param [in] tvMode TV mode.
	* @param [in] freq Frequency in [kHz].
	* @param [in] freqType Type of frequency (channel number might depend on frequency type).
	* @param [out] channelNumber TChannel number matching specified frequency.
	* @return When calling method failed returns -1.
	*/
	virtual int GetAnalogChannelNumber( _IN_ const TSTvMode& tvMode, _IN_ int freq, _OUT_ unsigned short& channelNumber ) = 0;
	
	/**
	* @brief Get list of channels to be scanned during auto store.
	* @param [in] tvMode TV mode.
	* @param [out] channels List of channels.
	* @return When calling method failed returns -1.
	*/
	virtual int GetAnalogChannels( _IN_ const TSTvMode& tvMode, _OUT_ std::list<TSChannelData*>& channels ) = 0;

	/**
	 * @briefs Gets lists of alternative channels for given tv mode & channel number.
	 * @param[in] tvMode TV mode.
	 * @param[in] channelNumber Channel number for which alternative channels will be obtained.
	 * @param[out] alternativeChannelNumbers Obtained alternative channel numbers.
	 * @return When calling method failed returns -1.
	 */
	virtual int GetAlternativeChannels( _IN_ const TSTvMode& tvMode, unsigned short channelNumber, _OUT_ std::vector<unsigned short>& alternativeChannelNumbers) = 0;
	
	/**
	 * @briefs Gets network name of given network.
	 * @param[in] tvMode TV mode.
	 * @param[in] netId Network identifier.
	 * @param[out] networkName Network name.
	 * @return When calling method failed returns -1.
	 */
	virtual int GetNetworkName( _IN_ const TSTvMode& tvMode, _IN_ unsigned short netId, _OUT_ t_wstring& networkName) = 0;
};

#endif
