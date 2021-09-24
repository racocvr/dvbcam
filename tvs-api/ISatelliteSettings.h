/** 
 * @file ISatelliteSettings.h
 * @brief Application interface for managing satellite settings.
 *
 * Copyright 2013 by Samsung Electronics, Inc.,
 * 
 * This software is the confidential and proprietary information
 * of Samsung Electronics, Inc. ("Confidential Information"). You
 * shall not disclose such Confidential Information and shall use
 * it only in accordance with the terms of the license agreement
 * you entered into with Samsung.
 */


#ifndef _ISATELLITESETTINGS_H_
#define _ISATELLITESETTINGS_H_

#include <vector>
#include "MarshallingMarks.h"
#include "SatelliteDataType.h"
#include "SatelliteSettingsDataType.h"
#include "ServiceNavigationDataType.h"
#include "ScanDataDataType.h"
#include "TVServiceDataType.h"

class ISatelliteSettings
{
protected:
	virtual ~ISatelliteSettings(){};


public:

	/**
	 * @brief Gets satellite configuration.
	 * @remark If satellite settings are not present in database, default settings will be obtained.
	 * @param [in] satelliteId Satellite for which settings will be obtained.
	 * @param [out] settings Obtained satellite settings.
	 * @return When calling method failed returns -1, 1 otherwise.
	 *
	 *	@paragraph <Example>
	 *	This example will get satellite settings for SATID_ASTRA_19_2E.
	 *	
	 *	@verbatim
	 *	ISatelliteSettings* pSatelliteSettings = NULL;
	 *	TVServiceAPI::CreateSatelliteSettings(&pSatelliteSettings);
	 *	TSSatelliteSettings astraSettings;
	 *	if(pSatelliteSettings->GetSettings(SATID_ASTRA_19_2E, astraSettings) == 1)
	 *	{
	 *		//Do something with obtained settings.
	 *	}
	 *	@endverbatim
	 */
	virtual int GetSettings( _IN_ ESatelliteId satelliteId, _OUT_ TSSatelliteSettings& settings ) = 0;

	/**
	 * @brief Set satellite configuration.
	 * @param [in] settings Satellite settings to be set.
	 * @return When calling method failed returns -1, 1 otherwise.
	 *
	 *	@paragraph <Example>
	 *	This example will set/update satellite settings.
	 *	
	 *	@verbatim
	 *	ISatelliteSettings* pSatelliteSettings = NULL;
	 *	TVServiceAPI::CreateSatelliteSettings(&pSatelliteSettings);
	 *	TSSatelliteSettings satelliteSettings(SATID_ASTRA_19_2E, SCAN_SERVICE_MODE_NONE, 9750000, 10600000, 11300000, DISEQC_OFF, TONE_22_AUTO, 1, false, LNB_TYPE_SINGLE)'
	 *	if(pSatelliteSettings->SetSettings(satelliteSettings) == 1)
	 *	{
	 *		// Satellite settings have been stored/updated.
	 *	}
	 *	@endverbatim
	 */
	virtual int SetSettings( _IN_ const TSSatelliteSettings& settings ) = 0;

	/**
	 * @brief Set configuration of multiple satellites.
	 * @param [in] settings List of satellite settings.
	 * @return When calling method failed returns -1, 1 otherwise.
	 *
	 *	@paragraph <Example>
	 *	This example will set/update satellite settings using a list (SATID_ASTRA_19_2E & SATID_HOTBIRD_13E).
	 *	
	 *	@verbatim
	 *	ISatelliteSettings* pSatelliteSettings = NULL;
	 *	TVServiceAPI::CreateSatelliteSettings(&pSatelliteSettings);
	 *	std::vector<TSSatelliteSettings>& settings;
	 *	settings.push_back(TSSatelliteSettings(SATID_ASTRA_19_2E, SCAN_SERVICE_MODE_NONE, 9750000, 10600000, 11300000, DISEQC_OFF, TONE_22_AUTO, 1, false, LNB_TYPE_SINGLE));
	 *	settings.push_back(TSSatelliteSettings(SATID_HOTBIRD_13E, SCAN_SERVICE_MODE_NONE, 9750000, 10600000, 11300000, DISEQC_OFF, TONE_22_AUTO, 1, false, LNB_TYPE_SINGLE));
	 *	if(pSatelliteSettings->SetSettings(settings) == 1)
	 *	{
	 *		// Satellite settings have been stored/updated.
	 *	}
	 *	@endverbatim
	 */
	virtual int SetSettings( _IN_ const std::vector<TSSatelliteSettings>& settings ) = 0;

	/**
	 * @brief Sets enable positioner property.
	 * @param [in] enable State whether positioner should be enabled.
	 * @return When calling method failed returns -1, 1 otherwise.
	 *
	 *	@paragraph <Example>
	 *	This example will enable positioner.
	 *	
	 *	@verbatim
	 *	ISatelliteSettings* pSatelliteSettings = NULL;
	 *	TVServiceAPI::CreateSatelliteSettings(&pSatelliteSettings);
	 *	if(pSatelliteSettings->SetEnablePositioner(true) == 1)
	 *	{
	 *		// Positioner has been enabled.
	 *	}
	 *	@endverbatim
	 */
    virtual int SetEnablePositioner( _IN_ bool enable ) = 0;

	/**
	 * @brief Checks if positioner is enabled.
	 * @param [out] enable States whether positioner is enabled.
	 * @return When calling method failed returns -1, 1 otherwise.
	 *
	 *	@paragraph <Example>
	 *	This example will enable positioner.
	 *	
	 *	@verbatim
	 *	ISatelliteSettings* pSatelliteSettings = NULL;
	 *	TVServiceAPI::CreateSatelliteSettings(&pSatelliteSettings);
	 *	if(pSatelliteSettings->SetEnablePositioner(true) == 1)
	 *	{
	 *		// Positioner has been enabled.
	 *	}
	 *	@endverbatim
	 */
    virtual int CheckEnablePositioner( _OUT_ bool& enable ) = 0;

	/**
	 * @brief Sets DiSEqC version.
	 * @param [in] diseqc DiSEqC version.
	 * @return When calling method failed returns -1, 1 otherwise.
	 *
	 *	@paragraph <Example>
	 *	This example will enable positioner.
	 *	
	 *	@verbatim
	 *	ISatelliteSettings* pSatelliteSettings = NULL;
	 *	TVServiceAPI::CreateSatelliteSettings(&pSatelliteSettings);
	 *	if(pSatelliteSettings->SetDiSEqCVersion(DISEQC_1_2) == 1)
	 *	{
	 *		// DiSEqC version has been set.
	 *	}
	 *	@endverbatim
	 */
    virtual int SetDiSEqCVersion( _IN_ EDiSEqCVersion diseqc ) = 0;

	/**
	 * @brief Gets DiSEqC version.
	 * @param [out] diseqc DiSEqC version.
	 * @return When calling method failed returns -1, 1 otherwise.
	 *
	 *	@paragraph <Example>
	 *	This example will enable positioner.
	 *	
	 *	@verbatim
	 *	ISatelliteSettings* pSatelliteSettings = NULL;
	 *	TVServiceAPI::CreateSatelliteSettings(&pSatelliteSettings);
	 *	EDiSEqCVersion diseqc;
	 *	if(pSatelliteSettings->GetDiSEqCVersion(diseqc) == 1)
	 *	{
	 *		// DiSEqC version has been obtained.
	 *	}
	 *	@endverbatim
	 */
    virtual int GetDiSEqCVersion( _OUT_ EDiSEqCVersion& diseqc ) = 0;

	/**
	 * @brief Reset DiSEqC mode to default values.
	 * @remarks Some operators require that specific DiSEqC mode is assigned to appropriate satellites.
	 * @param [in] tvMode TV mode for which DiSEqC shall be reset. 
 	 * @param [in] network Network for which DiSEqC shall be reset.  
	 * @return Returns 1 if resetting DiSEqC mode succeeded.
	 * @return When calling method failed returns -1, 0 if tv mode & network does not correspond to appropriate satellites, 1 otherwise.
	 *
	 *	@paragraph <Example>
	 *	This example reset DiSEqCMode for SERVICE_MODE_CD_TVV_TELESAT & SCAN_NETWORK_CANALDIGITAL.
	 *	
	 *	@verbatim
	 *	ISatelliteSettings* pSatelliteSettings = NULL;
	 *	TVServiceAPI::CreateSatelliteSettings(&pSatelliteSettings);
	 *	TSTvMode tvMode(ANTENNA_MODE_SATELLITE, SERVICE_MODE_CD_TVV_TELESAT);
	 *	if(pSatelliteSettings->ResetDiSEqCMode(tvMode, SCAN_NETWORK_CANALDIGITAL) == 1)
	 *	{
	 *		// DiSEqCMode has been reset
	 *	}
	 *	@endverbatim
	 */
	virtual int ResetDiSEqCMode( _IN_ const TSTvMode& tvMode,  _IN_ EScanNetwork network ) = 0;

	/**
	 * @brief Set user's TV position.
	 * @remarks TV position is composed of latitude and longitude values.
	 * @param [in] latitude in range [-90.00 ~ 90.00] (the equator basis); value is valid down to two decimal places
	 * @param [in] longitude in range [-180.00 ~ 180.00] (the Greenwich Astronomical Observatory basis); value is valid down to two decimal places
	 * @return When calling method failed returns -1, 1 otherwise.
	 *
	 *	@paragraph <Example>
	 *	This example will set tv coordinates.
	 *	
	 *	@verbatim
	 *	ISatelliteSettings* pSatelliteSettings = NULL;
	 *	TVServiceAPI::CreateSatelliteSettings(&pSatelliteSettings);
	 *	if(pSatelliteSettings->SetTvCoordinates(45.0, 100.0) == 1)
	 *	{
	 *		// Coordinates have been set.
	 *	}
	 *	@endverbatim
	 */
	virtual int SetTvCoordinates( _IN_ double latitude, _IN_ double longitude ) = 0;

	/**
	 * @brief Get user's TV position.
	 * @remarks TV position is composed by latitude and longitude values.
	 * @param [out] latitude in range [-90.00 ~ 90.00] (the equator basis); value is valid down to two decimal places
	 * @param [out] longitude in range [-180.00 ~ 180.00] (the Greenwich Astronomical Observatory basis); value is valid down to two decimal places
	 * @return When calling method failed returns -1, 1 otherwise.
	 *
	 *	@paragraph <Example>
	 *	This example will get tv coordinates.
	 *	
	 *	@verbatim
	 *	ISatelliteSettings* pSatelliteSettings = NULL;
	 *	TVServiceAPI::CreateSatelliteSettings(&pSatelliteSettings);
	 *	double latitude = 0.0;
	 *	double longitude = 0.0;
	 *	if(pSatelliteSettings->GetTvCoordinates(latitude, longitude) == 1)
	 *	{
	 *		// Coordinates (latitude & longitude) have been obtained.
	 *	}
	 *	@endverbatim
	 */
	virtual int GetTvCoordinates( _OUT_ double& latitude, _OUT_ double& longitude ) = 0;

	/**
	 * @brief Calculate positioner position based on tv coordinates.
	 * @param [in] satelliteId Id of satellite, for which position shall be calculated.
	 * @param [out] usals Calculated positioner position.
	 * @return When calling method failed returns -1, 0 if satellite not present in transponder database, 1 otherwise.
	 *
	 *	@paragraph <Example>
	 *	This example will calculate USALS for SATID_ASTRA_19_2E satellite.
	 *	
	 *	@verbatim
	 *	ISatelliteSettings* pSatelliteSettings = NULL;
	 *	TVServiceAPI::CreateSatelliteSettings(&pSatelliteSettings);
	 *	int usals = 0;
	 *	if(pSatelliteSettings->CalculateUSALS(SATID_ASTRA_19_2E, usals) == 1)
	 *	{
	 *		// Coordinates (latitude & longitude) have been obtained.
	 *	}
	 *	@endverbatim
	 */
	virtual int CalculateUSALS( _IN_ ESatelliteId satelliteId, _OUT_ int& usals ) = 0;

	/**
	 * @brief Enable SatCR.
	 * @remarks SatCR (satellite channel routing) is single cable installation, combining multiple input satellite signals onto a single cable.
	 * @param [in] enable Enable/disable SatCR.
	 * @return When calling method failed returns -1, 1 otherwise.
	 *
	 *	@paragraph <Example>
	 *	This example will enable SatCR.
	 *	
	 *	@verbatim
	 *	ISatelliteSettings* pSatelliteSettings = NULL;
	 *	TVServiceAPI::CreateSatelliteSettings(&pSatelliteSettings);
	 *	int usals = 0;
	 *	if(pSatelliteSettings->SetEnableSatCR(true) == 1)
	 *	{
	 *		// SatCR has been enabled.
	 *	}
	 *	@endverbatim
	 */
	virtual int SetEnableSatCR( _IN_ bool enable ) = 0;

	/**
	 * @brief Check if SatCR is enabled.
	 * @remarks SatCR (satellite channel routing) is single cable installation, combining multiple input satellite signals onto a single cable.
	 * @param [out] enable Is SatCR enabled?
	 * @return When calling method failed returns -1, 1 otherwise.
	 *
	 *	@paragraph <Example>
	 *	This example will check SatCR is enabled.
	 *	
	 *	@verbatim
	 *	ISatelliteSettings* pSatelliteSettings = NULL;
	 *	TVServiceAPI::CreateSatelliteSettings(&pSatelliteSettings);
	 *	bool satCREnabled = false;
	 *	if(pSatelliteSettings->CheckEnableSatCR(satCREnabled) == 1)
	 *	{
	 *		// SatCR has been obtained.
	 *	}
	 *	@endverbatim
	 */
	virtual int CheckEnableSatCR( _OUT_ bool& enable ) = 0;

	/**
	 * @brief Set slot number assigned to the receiver by user.
	 * @param [in] tunerId Tuner to be controlled.
	 * @param [in] slotNumber Slot number assigned to the receiver.
	 * @return When calling method failed returns -1, 1 otherwise.
	 *
	 *	@paragraph <Example>
	 *	This example will set SatCR slot number.
	 *	
	 *	@verbatim
	 *	ISatelliteSettings* pSatelliteSettings = NULL;
	 *	TVServiceAPI::CreateSatelliteSettings(&pSatelliteSettings);
	 *	if(pSatelliteSettings->SetSatCRSlotNumber(0, 1) == 1)
	 *	{
	 *		// SatCR slot number has been set (for tunerId = 0)
	 *	}
	 *	@endverbatim
	 */
	virtual int SetSatCRSlotNumber( _IN_ unsigned short tunerId, _IN_ unsigned char slotNumber ) = 0;

	/**
	 * @brief Set slot frequency selected by the user.
	 * @param [in] tunerId Tuner to be controlled.
	 * @param [in] slotFrequency Frequency of slot assigned to the receiver in [kHz].
	 * @return Returns 1 if storing slot frequency succeeded.
	 * @return When calling method failed returns -1, 1 otherwise.
	 *
	 *	@paragraph <Example>
	 *	This example will set SatCR slot frequency.
	 *	
	 *	@verbatim
	 *	ISatelliteSettings* pSatelliteSettings = NULL;
	 *	TVServiceAPI::CreateSatelliteSettings(&pSatelliteSettings);
	 *	if(pSatelliteSettings->SetSatCRSlotFrequency(0, 1420) == 1)
	 *	{
	 *		// SatCR slot frequency has been set (for tunerId = 0)
	 *	}
	 *	@endverbatim
	 */
	virtual int SetSatCRSlotFrequency( _IN_ unsigned short tunerId, _IN_ int slotFrequency ) = 0;

	/**
	 * @brief Acquire current SatCR settings.
	 * @param [in] tunerId Tuner for which SatCR settings shall be acquired.
	 * @param [out] satCRsettings SatCR settings for requested tuner.
	 * @return When calling method failed returns -1, 1 otherwise.
	 *
	 *	@paragraph <Example>
	 *	This example will get SatCR settings for tunerId = 0.
	 *	
	 *	@verbatim
	 *	ISatelliteSettings* pSatelliteSettings = NULL;
	 *	TVServiceAPI::CreateSatelliteSettings(&pSatelliteSettings);
	 *	TSSatCRSettings satCRSettings;
	 *	if(pSatelliteSettings->GetSatCRSettings(0, satCRSettings) == 1)
	 *	{
	 *		// SatCR settings have been obtained (for tunerId = 0)
	 *	}
	 *	@endverbatim
	 */
	virtual int GetSatCRSettings( _IN_ unsigned short tunerId, _OUT_ TSSatCRSettings& satCRsettings ) = 0;


	/**
	 * @brief Reset satellite settings.
	 * @param[in] resetType What should be reset?
	 * @param[in] satelliteId Id of satellite which settings should be reset.
	 * @return When calling method failed returns -1, 1 otherwise.
	 *
	 *	@paragraph <Example>
	 *	This example will do a SATSET_RESET_SATELLITE reset of satellite settings for SATID_ASTRA_19_2E satellite.
	 *	
	 *	@verbatim
	 *	ISatelliteSettings* pSatelliteSettings = NULL;
	 *	TVServiceAPI::CreateSatelliteSettings(&pSatelliteSettings);
	 *	if(pSatelliteSettings->Reset(SATSET_RESET_SATELLITE, SATID_ASTRA_19_2E) == 1)
	 *	{
	 *		// Reset has been performed.
	 *	}
	 *	@endverbatim
	 */
	virtual int Reset( _IN_ ESatSettingsResetType resetType, _IN_ ESatelliteId satelliteId = SATID_UNKNOWN) = 0;

	/**
	 * @brief Sets satellites as selected.
	 * @param[in] satellites Satellites to be selected.
	 * @return When calling method failed returns -1, 0 if error occurred while storing selected satellites, 1 if succeeded.
	 *
	 *	@paragraph <Example>
	 *	This example will set SATID_ASTRA_19_2E & SATID_EUTELSAT_28_5E as selected satellites.
	 *	
	 *	@verbatim
	 *	ISatelliteSettings* pSatelliteSettings = NULL;
	 *	TVServiceAPI::CreateSatelliteSettings(&pSatelliteSettings);
	 *	std::vector<ESatelliteId> satellites;
	 *	satellites.push_back(SATID_ASTRA_19_2E);
	 *	satellites.push_back(SATID_EUTELSAT_28_5E);
	 *	if(pSatelliteSettings->SelectSatellites(satellites) == 1)
	 *	{
	 *		// selected satellites have been set
	 *	}
	 *	@endverbatim
	 */
	virtual int SelectSatellites( _IN_ std::vector<ESatelliteId> &satellites) = 0;

	/**
	 * @brief Checks if satellite is selected on given TVS Handle.
	 * @param[in] tvsHandle TVS Handle.
	 * @param[in] satelliteId Identifier of satellite to be checked for selection.
	 * @param[out] selected Describes if satellite is selected.
	 * @return When calling method failed return -1, 0 if obtaining tv mode failed, 1 otherwise.
	 *
	 *	@paragraph <Example>
	 *	This example will check if SATID_ASTRA_19_2E satellite is selected.
	 *	
	 *	@verbatim
	 *	ISatelliteSettings* pSatelliteSettings = NULL;
	 *	TVServiceAPI::CreateSatelliteSettings(&pSatelliteSettings);
	 *	TVSHandle tvsHandle; // this should be obtained/pre-filled
	 *	bool selected = false;
	 *	if(pSatelliteSettings->CheckSatelliteSelected(tvsHandle, SATID_ASTRA_19_2E, selected) == 1)
	 *	{
	 *		if(selected)
	 *		{
	 *			// satellite is selected, do something..
	 *		}
	 *	}
	 *	@endverbatim
	 */
	virtual int CheckSatelliteSelected( _IN_ const TVSHandle &tvsHandle, _IN_ ESatelliteId satelliteId, _OUT_ bool &selected) = 0;

	/**
	 * @brief Checks if satellite is selected on given TVS Handle.
	 * @param[in] tvsHandle TVS Handle.
	 * @param[in] tvMode TV mode.
	 * @param[in] satelliteId Identifier of satellite to be checked for selection.
	 * @param[out] selected Describes if satellite is selected.
	 * @return When calling method failed return -1, 1 otherwise. 
	 *
	 *	@paragraph <Example>
	 *	This example will check if SATID_ASTRA_19_2E satellite is selected.
	 *	
	 *	@verbatim
	 *	ISatelliteSettings* pSatelliteSettings = NULL;
	 *	TVServiceAPI::CreateSatelliteSettings(&pSatelliteSettings);
	 *	TSTvMode tvMode; // this should be obtained/pre-filled
	 *	TVSHandle tvsHandle; // this should be obtained/pre-filled
	 *	bool selected = false;
	 *	if(pSatelliteSettings->CheckSatelliteSelected(tvsHandle, tvMode, SATID_ASTRA_19_2E, selected) == 1)
	 *	{
	 *		if(selected)
	 *		{
	 *			// satellite is selected, do something..
	 *		}
	 *	}
	 *	@endverbatim
	 */
	virtual int CheckSatelliteSelected( _IN_ const TVSHandle &tvsHandle, _IN_ const TSTvMode &tvMode, _IN_ ESatelliteId satelliteId, _OUT_ bool &selected) = 0;

	/**
	 * @brief Gets SatCR auto detection status.
	 * @param[out] slotNumber Detected slot number.
	 * @param[out] slotFrequency Detected frequency [kHz].
	 * @param[out] progress Percentage of current progress.
	 * @return When calling method failed return -1, 1 otherwise. 
	 *
	 *	@paragraph <Example>
	 *	This example get SatCR detected status.
	 *	
	 *	@verbatim
	 *	ISatelliteSettings* pSatelliteSettings = NULL;
	 *	TVServiceAPI::CreateSatelliteSettings(&pSatelliteSettings);
	 *	unsigned char slotNumber;
	 *	int slotFrequency;
	 *	unsigned char progress;
	 *	if(pSatelliteSettings->GetSatCRDetectStatus(slotNumber, slotFrequency, progress) == 1)
	 *	{
	 *		// you can use received data
	 *	}
	 *	@endverbatim
	 */
	virtual int GetSatCRDetectStatus(_OUT_ unsigned char &slotNumber, _OUT_ int& slotFrequency, _OUT_ unsigned char& progress, _IN_ int tunerId = 0 ) = 0;
};


#endif //  _ISATELLITESETTINGS_H_

