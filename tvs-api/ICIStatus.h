/**
 * @file ICIStatus.h
 * @brief Application interface for setting CI status (used by CI APP).
 *
 * Copyright 2015 by Samsung Electronics, Inc.,
 *
 * This software is the confidential and proprietary information
 * of Samsung Electronics, Inc. ("Confidential Information"). You
 * shall not disclose such Confidential Information and shall use
 * it only in accordance with the terms of the license agreement
 * you entered into with Samsung.
 */

#ifndef _ICISTATUS_H_
#define _ICISTATUS_H_


#include "MarshallingMarks.h"
#include "CIStatusDataType.h"


class ICIStatus
{
protected:
	virtual ~ICIStatus(){};

public:

	/**
	 * @brief Sets general data regaring CIM status.
	 * @param [in] cimStatusInfo CIM status info.
	 * @return Returns 1 if specified audio information for current service is available, otherwise returns 0.
	 * @return When calling method failed returns -1.
	 *
	 *	@paragraph <Example>
	 *	This example will set CIM status info.
	 *	
	 *	@verbatim
	 *	ICIStatus* pCIStatus;
	 *	TVServiceAPI::CreateCIStatus( &pCIStatus );
	 *
	 *	TSCIMStatusInfo cimStatusInfo
	 *	if( pCIStatus->SetGeneralStatus( cimStatusInfo ) > 0 )
	 *	{
	 *	}
	 *	@endverbatim
	 */
	virtual int SetGeneralStatus( _IN_ const TSCIMStatusInfo & cimStatusInfo ) = 0;

	/**
	 * @brief Sets host control status.
	 * @param [in] cimHostControlStatus Host control status info.
	 * @return Returns 1 if specified audio information for current service is available, otherwise returns 0.
	 * @return When calling method failed returns -1.
	 *
	 *	@paragraph <Example>
	 *	This example will set host control status info.
	 *	
	 *	@verbatim
	 *	ICIStatus* pCIStatus;
	 *	TVServiceAPI::CreateCIStatus( &pCIStatus );
	 *
	 *	TSCIMStatusHostControl cimHostControlStatus
	 *	if( pCIStatus->SetHostControlStatus( cimHostControlStatus ) > 0 )
	 *	{
	 *	}
	 *	@endverbatim
	 */
	virtual int SetHostControlStatus( _IN_ const TSCIMStatusHostControl & cimHostControlStatus ) = 0;

};


#endif //_ICISTATUS_H_
