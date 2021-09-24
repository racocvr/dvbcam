/** 
 * @file IRatingSystem.h
 * @brief Application interface for managing region rating system.
 *
 * Copyright 2013 by Samsung Electronics, Inc.,
 * 
 * This software is the confidential and proprietary information
 * of Samsung Electronics, Inc. ("Confidential Information"). You
 * shall not disclose such Confidential Information and shall use
 * it only in accordance with the terms of the license agreement
 * you entered into with Samsung.
 */
#ifndef _IRATINGSYSTEM_H_
#define _IRATINGSYSTEM_H_

#include <vector>
#include <string>

#include "MarshallingMarks.h"
#include "RatingDataType.h"

#include "RegionRating.h"

class IRatingSystem
{
protected:
	virtual ~IRatingSystem(){};

public:
	/**
	 * @brief Acquires the region rating system information.
	 * @remarks Region rating system is a rating system for a given region, where the rating system is
	 * characterized by a number of rating dimensions, each of which is composed of two or more rating
	 * values. An example of a typical rating dimension used on cable is the Motion Picture Association
	 * of America (MPAA) system. The levels within the MPAA dimension include "G", "PG", "PG-13", and so on.
 	 * For identifing certain dimensions and values(levels) of rating please refere to ERRTRegion, ERating,
	 * EMPARating, EKRRating and EUsParentRate enums.
	 * @param [out] rrSystem Region rating system.
	 * @return Returns 1 if the information is available, otherwise returns 0.
	 * @return When calling method failed returns -1.
	 *
	 *	@paragraph <Example>
	 *	This code will acquire RRS information for RRT_REGION_DOWNLOADABLE.
	 *	
	 *	@verbatim
	 *	IRating* pRatingSystem;
	 *	TVServiceAPI::CreateRatingSystem(RRT_REGION_DOWNLOADABLE, pRatingSystem);
	 *	TCRegionRating rrSystem;
	 *	if(pRatingSystem->GetRRS(rrSystem) > 0)
	 *	{
	 *		//Data obtained successfully
	 *	}
	 *	@endverbatim
	 */
	virtual int GetRRS(_OUT_ TCRegionRating& rrSystem) = 0;

	/**
	 * @brief Gets the lock flag of a certain rating value in a given dimension for the region rating system.
	 * @remarks Lock flag is for a given value of a given dimension.
	 * @param [in] dimension Dimension of the acquired lock information. 
	 * @param [in] ratingValue Rating value(level) of the acquired lock information.
	 * @param [out] onOff Value of the lock.
	 * @return Returns 1 if lock value is available, otherwise returns 0.
	 * @return When calling method failed returns -1.
	 *
	 *	@paragraph <Example>
	 *	This code will get lock value for RRT_REGION_DOWNLOADABLE.
	 *	
	 *	@verbatim
	 *	IRating* pRatingSystem;
	 *	TVServiceAPI::CreateRatingSystem(RRT_REGION_DOWNLOADABLE, pRatingSystem);
	 *	bool onOff;
	 *	if(pRatingSystem->GetRRSLock(4,8,onOff) > 0)
	 *	{
	 *		//Lock get successfully
	 *	}
	 *	@endverbatim
	 */
	virtual int GetRRSLock(_IN_ int dimension, _IN_ int ratingValue, _OUT_ bool& onOff) = 0;

	/**
	 * @brief Sets the lock flag of a certain rating value in a given dimension for the region rating system.
	 * @remarks Lock flag is for a given value of a given dimension.
	 * @param [in] dimension Dimension of the acquired lock information. 
	 * @param [in] ratingValue RatingValue of the acquired lock information.
	 * @param [in] onOff Value of the lock.
	 * @return Returns 1 if lock value was set successfully, otherwise returns 0.
	 * @return When calling method failed returns -1.
	 *
	 *	@paragraph <Example>
	 *	This code will set lock value for RRT_REGION_DOWNLOADABLE.
	 *	
	 *	@verbatim
	 *	IRating* pRatingSystem;
	 *	TVServiceAPI::CreateRatingSystem(RRT_REGION_DOWNLOADABLE, pRatingSystem);
	 *	if(pRatingSystem->SetRRSLock(4,8,true) > 0)
	 *	{
	 *		//Lock set successfully
	 *	}
	 *	@endverbatim
	 */
	virtual int SetRRSLock(_IN_ int dimension, _IN_ int ratingValue, _IN_  bool onOff) = 0;
};

#endif // _IRATINGSYSTEM_H_
