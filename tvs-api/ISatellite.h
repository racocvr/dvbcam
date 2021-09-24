/** 
 * @file ISatellite.h
 * @brief Application interface for acquiring satellite and transponder data.
 *
 * Copyright 2013 by Samsung Electronics, Inc.,
 * 
 * This software is the confidential and proprietary information
 * of Samsung Electronics, Inc. ("Confidential Information"). You
 * shall not disclose such Confidential Information and shall use
 * it only in accordance with the terms of the license agreement
 * you entered into with Samsung.
 */


#ifndef _ISATELLITE_H_
#define _ISATELLITE_H_

#include "MarshallingMarks.h"
#include "SatelliteDataType.h"
#include "CriteriaHelper.h"

class ISatellite
{
protected:
	virtual ~ISatellite(){};

public:


	/**
	 * @brief Find list of satellites matching given criteria.
	 * @remarks Complete satellite objects shall be returned, so DO NOT USE FETCH.
	 * @remarks MEMORY ALLOCATED FOR SATELLITE OBJECTS IN OUTPUT LIST MUST BE DEALLOCATED BY CALLER.
	 * @remarks Use EServiceDataTag and ESatelliteDataTag values to specify search conditions.
	 * @param [in] criteria Search criteria for satellites. FETCH shall NOT be used.
	 * @param [out] satellites List of found satellites.
	 * @return Returns 1 if at least one satellite was found, otherwise returns 0.
	 * @return When calling method failed returns -1.
	 *
	 *	@paragraph <Example>
	 *	This example will return list of satellites ordered by satellite id.
	 *	Only satellites with general satellite services assigned shall be returned.
	 *	
	 *	@verbatim
	 *	ISatellite* pSatelliteMgr;
	 *	TVServiceAPI::CreateSatellite(&pSatelliteMgr);
	 *	TCCriteriaHelper criteria;
	 *	//criteria.Where( SERVICE_DATA_TAG, VALUE ); //this should be set according to the needs
	 *	criteria.OrderBy( SATELLITE_ID );
	 *	std::list<TSSatellite*> satellites;
	 *	if(pSatelliteMgr->FindSatelliteList(searchCriteria, satellites) > 0)
	 *	{
	 *		//Do something with returned satellites
	 *	}
	 *	@endverbatim
	 */
	virtual int FindSatelliteList( _IN_ const TCCriteriaHelper& criteria, _OUT_ std::vector< TSSatellite* >& satellites ) = 0;


	/**
	 * @brief Find satellite matching given criteria.
	 * @remarks Complete satellite object shall be returned, so DO NOT USE FETCH.
	 * @remarks Use EServiceDataTag and ESatelliteDataTag values to specify search conditions.
	 * @param [in] criteria Search criteria for satellite. FETCH shall NOT be used.
	 * @param [out] satellite Found satellite.
	 * @return Returns 1 if requested satellite was found, otherwise returns 0.
	 * @return When calling method failed returns -1.
	 *
	 *	@paragraph <Example>
	 *	This example will return satellite with requested satellite id.
	 *	
	 *	@verbatim
	 *	ISatellite* pSatelliteMgr;
	 *	TVServiceAPI::CreateSatellite(&pSatelliteMgr);
	 *	TCCriteriaHelper criteria;
	 *	criteria.Where( SATELLITE_ID, 7 );
	 *	TSSatellite satellite;
	 *	if(pSatelliteMgr->FindSatellite(searchCriteria, satellite) > 0)
	 *	{
	 *		//Do something with returned satellite
	 *	}
	 *	@endverbatim
	 */
	virtual int FindSatellite( _IN_ const TCCriteriaHelper& criteria, _OUT_ TSSatellite& satellite ) = 0;


	/**
	 * @brief Set position of satellite.
	 * @see Check TSSatellite definition for detailed description of position related data.
	 * @remarks The method will not adjust positioner, just update satellite position in database.
	 * @param [in] satelliteId Id of satellite, which position shall be modified.
	 * @param [in] direction Cardinal direction of satellite (west/east).
	 * @param [in] position Satellite's position [in 1/10 of degree or 6 angular minutes].
	 * @return Returns 1 if requested satellite's position was modified, otherwise returns 0.
	 * @return When calling method failed returns -1.
	 *
	 *	@paragraph <Example>
	 *	This example will change position of Astra satellite in database.
	 *	
	 *	@verbatim
	 *	ISatellite* pSatelliteMgr;
	 *	TVServiceAPI::CreateSatellite(&pSatelliteMgr);
	 *	if(pSatelliteMgr->SetSatellitePosition(SATID_ASTRA_19_2E, DIR_WEST, 197) > 0)
	 *	{
	 *		//Do something
	 *	}
	 *	@endverbatim
	 */
	virtual int SetSatellitePosition( _IN_ ESatelliteId satelliteId, _IN_ ECardinalDirection direction, unsigned int position ) = 0;;


	/**
	 * @brief Find list of transponders matching given criteria.
	 * @remarks Complete transponder objects shall be returned, so DO NOT USE FETCH.
	 * @remarks MEMORY ALLOCATED FOR TRANSPONDER OBJECTS IN OUTPUT LIST MUST BE DEALLOCATED BY CALLER.
	 * @remarks Use EServiceDataTag and ESatelliteDataTag values to specify search conditions.
	 * @param [in] criteria Search criteria for transponders. FETCH shall NOT be used.
	 * @param [out] transponders List of found transponders.
	 * @return Returns 1 if at least one transponder was found, otherwise returns 0.
	 * @return When calling method failed returns -1.
	 *
	 *	@paragraph <Example>
	 *	This example will return list of transponders ordered by frequency.
	 *	Only transponders belonging to satellite with  id = 7 shall be returned.
	 *	
	 *	@verbatim
	 *	ISatellite* pSatelliteMgr;
	 *	TVServiceAPI::CreateSatellite(&pSatelliteMgr);
	 *	TCCriteriaHelper criteria;
	 *	criteria.Where( SATELLITE_ID, 7 );
	 *	criteria.OrderBy( TAG_TRANSPONDER_FREQUENCY );
	 *	std::list<TSTransponder*> transponders;
	 *	if(pSatelliteMgr->FindTransponderList(searchCriteria, transponders) > 0)
	 *	{
	 *		//Do something with returned transponders
	 *	}
	 *	@endverbatim
	 */
	virtual int FindTransponderList( _IN_ const TCCriteriaHelper& criteria, _OUT_ std::vector< TSTransponder* >& transponders ) = 0;


	/**
	 * @brief Find transponder matching given criteria.
	 * @remarks Complete transponder object shall be returned, so DO NOT USE FETCH.
	 * @remarks Use EServiceDataTag and ESatelliteDataTag values to specify search conditions.
	 * @param [in] criteria Search criteria for transponder. FETCH shall NOT be used.
	 * @param [out] transponder Found transponder.
	 * @return Returns 1 if requested transponder was found, otherwise returns 0.
	 * @return When calling method failed returns -1.
	 *
	 *	@paragraph <Example>
	 *	This example will return transponder matching input delivery parameters.
	 *	
	 *	@verbatim
	 *	ISatellite* pSatelliteMgr;
	 *	TVServiceAPI::CreateSatellite(&pSatelliteMgr);
	 *	TCCriteriaHelper criteria;
	 *	criteria.Where( TAG_TRANSPONDER_FREQUENCY, 12603000 );
	 *	criteria.Where( TAG_TRANSPONDER_POLARISATION, DVBS_POL_HL );
	 *	TSTransponder transponder;
	 *	if(pSatelliteMgr->FindTransponderList(searchCriteria, transponder) > 0)
	 *	{
	 *		//Do something with returned transponder
	 *	}
	 *	@endverbatim
	 */
	virtual int FindTransponder( _IN_ const TCCriteriaHelper& criteria, _OUT_ TSTransponder& transponder ) = 0;


	/**
	 * @brief Add user transponder to database.
	 * @remarks Transponder id shall be assigned by database.
	 * @param [int] transponder User transponder.
	 * @param [out] userTransponderId Id of newly added user transponder.
	 * @return Returns 1 if user transponder was added to database, otherwise returns 0.
	 * @return When calling method failed returns -1.
	 *
	 *	@paragraph <Example>
	 *	Add new transponder to database.
	 *	
	 *	@verbatim
	 *	ISatellite* pSatelliteMgr;
	 *	TVServiceAPI::CreateSatellite(&pSatelliteMgr);
	 *	TSTransponder tp;
	 *	tp.satelliteId = SATID_ASTRA_19_2E;
	 *	tp.frequency = 12603000;
	 *	tp.symbolRate = 22000000;
	 *	tp.polarisation = DVBS_POL_HL;
	 *	tp.fec = DVB_FEC_INNER_7_8;
	 *	unsigned short userTpId = INVALID;
	 *	if(pSatelliteMgr->AddUserTransponder(tp, userTpId) > 0)
	 *	{
	 *		//Do something
	 *	}
	 *	@endverbatim
	 */
	virtual int AddUserTransponder( _IN_ const TSTransponder& transponder, _OUT_ unsigned short& userTransponderId ) = 0;


	/**
	 * @brief Remove user transponder from database.
	 * @remarks If given id is not user transponder id, transponder shall not be removed.
	 * @param [int] userTransponderId Id of user transponder to be removed.
	 * @return Returns 1 if user transponder was removed from database, otherwise returns 0.
	 * @return When calling method failed returns -1.
	 *
	 *	@paragraph <Example>
	 *	Remove transponder from database.
	 *	
	 *	@verbatim
	 *	ISatellite* pSatelliteMgr;
	 *	TVServiceAPI::CreateSatellite(&pSatelliteMgr);
	 *	TSTransponder tp;
	 *	tp.satelliteId = SATID_ASTRA_19_2E;
	 *	tp.frequency = 12603000;
	 *	tp.symbolRate = 22000000;
	 *	tp.polarisation = DVBS_POL_HL;
	 *	unsigned short userTpId = INVALID;
	 *	if(pSatelliteMgr->AddUserTransponder(tp, userTpId) > 0)
	 *	{
	 *		pSatelliteMgr->RemoveUserTransponder(userTpId);
	 *	}
	 *	@endverbatim
	 */
	virtual int RemoveUserTransponder( _IN_ unsigned short userTransponderId ) = 0;


	/**
	 * @brief Reset satellite database.
	 * @remarks Depending on reset type, behaviour will be different: either whole db will be recreated from SEI file or just user data shall be reset.
	 * @param [in] resetType Type of reset.
	 * @return Returns 1 when db was reset.
	 * @return When calling method failed returns -1.
	*/
	virtual int Reset( _IN_ ESatDbResetType resetType ) = 0;

	/**
	 * @brief Check if satellite database was updated.
	 * @remarks Satellite database might be updated by software upgrade. If that happens, new database shall be used
	 * 	during bootup - information that it happened is returned by this method.
	 * @remarks When satellite database was updated, user could be notified to perform auto tuning again.
	 * @param [out] dbUpdated True if satellite database was updated during bootup.
	 * @return Returns 1 if data was acquired successfully, otherwise returns 0.
	 * @return When calling method failed returns -1.
	 *
	 *	@paragraph <Example>
	 *	Following code will check if database was updated
	 *	
	 *	@verbatim
	 *	ISatellite* pSatelliteMgr;
	 *	TVServiceAPI::CreateSatellite(&pSatelliteMgr);
	 *	bool dbUpdated = false;
	 *	if(pSatelliteMgr->CheckDbUpdated(dbUpdated) > 0)
	 *	{
	 *		// use dbUpdated value
	 *	}
	 *	@endverbatim
	 */
	virtual int CheckDbUpdated(_OUT_ bool& dbUpdated) = 0;

	/**
	 * @brief Confirm that satellite db update process can be completed.
	 * @remarks Satellite db is updated during bootup if new version of db exists.
	 *	Currently used db version is stored in non-volatile memory; it is not updated during bootup though,
	 * 	but only after this method is called - it is assumed that calling this method confirms, that user was notified about update successfully.
	 * @remarks When new satellite db is available, user will be notified about it after every bootup until this method is called.
	 * @return Returns 1 if update was confirmed successfully, otherwise returns 0.
	 * @return When calling method failed returns -1.
	 *
	 *	@paragraph <Example>
	 *	Following code will confirm that database update process can be finished.
	 *	
	 *	@verbatim
	 *	ISatellite* pSatelliteMgr;
	 *	TVServiceAPI::CreateSatellite(&pSatelliteMgr);
	 *	if(pSatelliteMgr->ConfirmDbUpdate() > 0)
	 *	{
	 *		// success
	 *	}
	 *	@endverbatim
	 */
	virtual int ConfirmDbUpdate(void) = 0;
};

#endif // _ISATELLITE_H_

