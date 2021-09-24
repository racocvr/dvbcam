/** 
 * @file ServiceNavigationDataType.h
 * @brief Service navigation related data types.
 *
 * Copyright 2013 by Samsung Electronics, Inc.,
 * 
 * This software is the confidential and proprietary information
 * of Samsung Electronics, Inc. ("Confidential Information"). You
 * shall not disclose such Confidential Information and shall use
 * it only in accordance with the terms of the license agreement
 * you entered into with Samsung.
 */

#ifndef _SERVICENAVIGATIONDATATYPE_H_
#define _SERVICENAVIGATIONDATATYPE_H_

#include "Marshalable.h"

typedef enum
{
	ANTENNA_MODE_UNDEFINED = -1,
	
	ANTENNA_MODE_AIR,
	ANTENNA_MODE_CABLE,
	ANTENNA_MODE_SATELLITE,
	
	ANTENNA_MODE_MAX, // do not add new values after this
}EAntennaMode;

typedef enum
{
	SERVICE_MODE_UNKNOWN = -1,
	
	SERVICE_MODE_ATSC = 0,			// ATSC profile (includes both terrestrial and cable services)
	SERVICE_MODE_DVB,				// general DVB profile (includes terrestrial/cable/satellite services, use it when there is no service provider, like Freesat, specified)
	SERVICE_MODE_ISDB,				// ISDB profile
	SERVICE_MODE_FREESAT,			// Freesat (satellite profile, available in UK)
	SERVICE_MODE_CANALDIGITAL_SAT,	// CanalDigital (satellite profile, available in Sweden, Norway, Denmark and Finland)
	SERVICE_MODE_TIVUSAT,			// TivuSat (satellite profile, available in Italy)
	SERVICE_MODE_CD_TVV_TELESAT,	// CanalDigital TV Vlaanderen Telesat (satellite profile, available in Netherlands and Belgium)
	SERVICE_MODE_ASTRA_192E,		// Astra HD+ (satellite profile, available in Germany)
	SERVICE_MODE_DIGITAL_PLUS,		// Digital+ (satellite profile, operated by Sogecable, available in Spain)
	SERVICE_MODE_DSMART,			// DSmart (satellite profile, available in Turkey)
	SERVICE_MODE_DIGITURK,			// Digiturk (satellite profile, available in Turkey)
	SERVICE_MODE_FRANSAT,			// Fransat (satellite profile, available in France)
	SERVICE_MODE_FREEVIEWNZ_SAT,	// Freeview (satellite profile, available in New Zealand)
	SERVICE_MODE_NC_PLUS,			// nc+ (satellite profile, available in Poland)
	SERVICE_MODE_NNK,				// cyfra plus card
	SERVICE_MODE_SKYLINK,			// Skylink (satellite profile, available in Czech Republic and Slovakia)
	SERVICE_MODE_AIRTEL,			// airtel (satellite profile, available in India)
	SERVICE_MODE_HD_AUSTRIA,		// HD Austria (satellite profile, available in Austria)
	SERVICE_MODE_OTAU,				// OTAU TV (satellite profile, available in Kazakhstan)
	SERVICE_MODE_CIOP1,				// CI Operator Profile [1]
	SERVICE_MODE_CIOP2,				// CI Operator Profile [2]
	SERVICE_MODE_DVBNT,				// DVB NTSC profile
	SERVICE_MODE_MAGYARORSZAG,		// AustriaSat Magyarorszag (satellite profile, available in Hungary)
	SERVICE_MODE_POLSAT,			// Cyfrowy Polsat (satellite profile, available in Poland)
	SERVICE_MODE_NTV_PLUS,			// NTV +  (satellite profile, available in Russia)
	SERVICE_MODE_TELEKARTA,			// Telekarta (satellite profile, available in Russia)
	SERVICE_MODE_TRICOLOR,			// Tricolor TV (satellite profile, available in Russia)
	SERVICE_MODE_SUNDIRECT,			// SunDirect (satellite profile, available in India)	
	SERVICE_MODE_NAGSAM_OP1,		// NagSam Operator Profile [1]
	SERVICE_MODE_CIOP3 = SERVICE_MODE_NAGSAM_OP1, //ToDo Duende: Remove
	SERVICE_MODE_NAGSAM_OP2,		// NagSam Operator Profile [2]
	SERVICE_MODE_NAGSAM_OP3,		// NagSam Operator Profile [3]
	SERVICE_MODE_NAGSAM_OP4,		// NagSam Operator Profile [4]
	SERVICE_MODE_MAX, // do not add new values after this
}EServiceMode;

typedef enum
{
	SERVICE_CHANGE_DIRECTION_NONE,
	SERVICE_CHANGE_DIRECTION_DIRECT,
	SERVICE_CHANGE_DIRECTION_UP,
	SERVICE_CHANGE_DIRECTION_DOWN,
}EServiceChangeDirection;

typedef enum 
{	
	SERVICE_LIST_DISPLAYABLE,	//Specifies services that should be displayed to the user, in special case: it includes hidden ATSC services.
	SERVICE_LIST_NAVIGABLE,		//Specifies services through which user can navigate.
}EServiceListType;

struct TSTvMode: public TCMarshalable
{
	// Source of services: air, cable, satellite, ...
	EAntennaMode antennaMode;

	// Service mode information - used primarily for service operators.
	//
	// !!! WARNING !!!
	// If you want to set tvMode (IServiceNavigation::SetTvMode) in tvs you do not need to specify service mode. 
	// In any other case you need to specify antenna and service mode !!!
	//
	// Example 1: in ATSC - how to set cable tv mode? - TSTvMode( ANTENNA_MODE_CABLE )
	// Example 2: in DVB - how to set cable tv mode? - TSTvMode( ANTENNA_MODE_CABLE )
	// Example 3: in DVB - how to set general satellite tv mode?  - TSTvMode( ANTENNA_MODE_SATELLITE, SERVICE_MODE_DVB )
	// Example 4: in DVB - how to set Astra 19.2E satellite tv mode?  - TSTvMode( ANTENNA_MODE_SATELLITE, SERVICE_MODE_ASTRA_192E )
	// Example 5: passing TvMode to TCNavigationModeHelper methods - you need to specify full info.
	EServiceMode serviceMode;

public:
	TSTvMode(): antennaMode(ANTENNA_MODE_UNDEFINED), serviceMode(SERVICE_MODE_UNKNOWN) {}

	TSTvMode(EAntennaMode antMode, EServiceMode serMode = SERVICE_MODE_UNKNOWN);

	explicit TSTvMode(unsigned long long id);

	bool operator < (const TSTvMode& tvMode) const;
	bool operator == (const TSTvMode& tvMode) const;
	bool operator != (const TSTvMode& tvMode) const;

	/**
	 * @brief Extract Tree from Class
	 * @param [inout] treeParent branch to which object data should be added
	 * @return true if success
	 */
	virtual bool ClassToTree(TCTreeBranch& treeParent);
	
	/**
	 * @brief Fill out Class from Tree
	 * @param [inout] treeMine branch from which object data should be fetched
	 * @return true if success
	 */
	virtual bool TreeToClass(TCTreeBranch& treeMine);

	/**
	 * @brief Get id to identify all possible Tv Modes
	 * @return id
	 */
	unsigned long long GetId() const;

protected:

	enum
	{
		TAG_ANTENNAMODE,
		TAG_SERVICEMODE,
	};
};


#endif // _SERVICENAVIGATIONDATATYPE_H_
