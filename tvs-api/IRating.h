/** 
 * @file IRating.h
 * @brief Application interface for managing rating information.
 *
 * Copyright 2013 by Samsung Electronics, Inc.,
 * 
 * This software is the confidential and proprietary information
 * of Samsung Electronics, Inc. ("Confidential Information"). You
 * shall not disclose such Confidential Information and shall use
 * it only in accordance with the terms of the license agreement
 * you entered into with Samsung.
 */


#ifndef _IRATING_H_
#define _IRATING_H_

#include <vector>
#include <string>

#include "MarshallingMarks.h"
#include "RatingDataType.h"

class IRating
{
protected:
	virtual ~IRating(){};

public:

	/**
	 * @brief Get collected rating info data list.
	 * @param [out] ratingInfo Collected rating info data list.
	 * @return Returns 1 if rating informations are available, otherwise returns 0.
	 * @return When calling method failed returns -1.
	 *
	 *	@paragraph <Example>
	 *	This code will collect rating info for MAIN profile and screen=0.
	 *	
	 *	@verbatim
	 *	IRating* pRating;
	 *	TVServiceAPI::CreateRating(PROFILE_TYPE_MAIN, 0, pRating);
	 *	std::vector<TSRatingInfo> ratingInfo;
	 *	if(pRating->GetRatingInfo(ratingInfo) > 0)
	 *	{
	 *		//Data obtained successfully
	 *	}
	 *	@endverbatim
	 */
	virtual int GetRatingInfo(_OUT_ std::vector<TSRatingInfo>& ratingInfo) = 0;

	virtual int SetRatingData(_IN_ ERatingData ratingData, _IN_ unsigned int value) = 0;

	virtual int GetRatingData(_IN_ ERatingData ratingData, _OUT_ unsigned int& value) = 0;

};

#endif // _IRATING_H_

