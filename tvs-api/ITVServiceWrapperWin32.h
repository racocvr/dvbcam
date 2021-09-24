/** 
 * @file	TVServiceWrapperWin32.h
 * @brief	Class ONLY for win32 simulator - for TVS control
 *
 * Copyright 2016 by Samsung Electronics, Inc.,
 *
 * This software is the confidential and proprietary information
 * of Samsung Electronics, Inc. ("Confidential Information").  You
 * shall not disclose such Confidential Information and shall use
 * it only in accordance with the terms of the license agreement
 * you entered into with Samsung.
 */

#ifndef _ITVSERVICEWRAPPERWIN32_H_
#define _ITVSERVICEWRAPPERWIN32_H_

#include "MarshallingMarks.h"

class ITVServiceWrapperWin32
{

public:
	virtual int Init(void) = 0;
	virtual int Power(_IN_ int powerType , _IN_ int bootReason, _IN_ bool param) = 0;
	virtual int GetPowerState(_OUT_ int& powerState, _OUT_ int& bootReason) = 0;


	virtual int GetCountry( _IN_ bool digital, _OUT_ int& country ) = 0 ;
	virtual int SetCountry( _IN_ bool digital, _IN_ int country ) = 0;
	virtual int GetRegionKind( _OUT_ int& regionKind ) = 0;
	virtual int ConvertToTizenCountry( _IN_ int country ) = 0;

	virtual void SetAutoClock( _IN_ bool autoClock ) = 0;
	virtual bool FlagAutoClock(void) = 0;

	virtual void StoreRating(_IN_ unsigned int rating) = 0;

};

#endif /* _TVSERVICEWRAPPERWIN32_H_ */

