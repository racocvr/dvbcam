/** 
 * @file IEWBS.h
 * @brief Application interface for Early Warning Broadcast System.
 *
 * Copyright 2015 by Samsung Electronics, Inc.,
 * 
 * This software is the confidential and proprietary information
 * of Samsung Electronics, Inc. ("Confidential Information"). You
 * shall not disclose such Confidential Information and shall use
 * it only in accordance with the terms of the license agreement
 * you entered into with Samsung.
 */

#ifndef _IEWBS_H_
#define _IEWBS_H_


#include <string>

#include "MarshallingMarks.h"
#include "EWBSDataType.h"


class IEWBS
{
protected:
	
	virtual ~IEWBS() {};

public:

	/**
	 * @brief Gets EWBS data extracted from TRDW table.(Table Region Of Disaster Warning).
	 * @remarks Information about EWBS availability is signalled by sending SIGNAL_EWBS_CHANGED.
	 * @param [out] packageId Current package ID of TRDW.
	 * @param [out] disasterStatus Disaster area status.
	 * @param [out] disasterCode Disaster type.
	 * @param [out] areaCode Zipcode of Disaster location.
	 * @param [out] areaDescription Name of Disaster location.
	 * @return Returns 1 if EWBS data was retrieved, otherwise returns 0.
	 * @return When calling method failed returns -1.
	 *
	 *	@paragraph <Example>
	 *	This example will get EWBS data.
	 *
	 *	@verbatim
	 *	IEWBS* pEwbs;
	 *	TVServiceAPI::CreateEWBS(&pEwbs);
	 *
	 *	unsigned char packageId = 0;
	 *	EDisasterStatus disasterStatus = DISASTER_STATUS_CAUTION;
	 *	EDisasterCode disasterCode = DISASTER_CODE_EARTHQUAKE;
	 *	unsigned int areaCode = 0;
	 *	std::string areaDescription;
	 *	if( pEwbs->GetEWBSData( packageId, disasterStatus, disasterCode, areaCode, areaDescription ) > 0 )
	 *	{
	 *		//Do something.
	 *	}
	 *	@endverbatim
	 */
	virtual int GetEWBSData( _OUT_ unsigned char& packageId, _OUT_ EDisasterStatus& disasterStatus, _OUT_ EDisasterCode& disasterCode, _OUT_ unsigned int& areaCode, _OUT_ std::string& areaDescription) = 0;

};


#endif //_IEWBS_H_
