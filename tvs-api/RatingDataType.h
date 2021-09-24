/** 
 * @file RatingDataType.h
 * @brief Data types for TCRating class.
 *
 * Copyright 2013 by Samsung Electronics, Inc.,
 * 
 * This software is the confidential and proprietary information
 * of Samsung Electronics, Inc. ("Confidential Information"). You
 * shall not disclose such Confidential Information and shall use
 * it only in accordance with the terms of the license agreement
 * you entered into with Samsung.
 */
#ifndef _RATINGDATATYPE_H_
#define _RATINGDATATYPE_H_

#include "Marshalable.h"
#include "TreeToClassFormatter.h"
#include "ClassToTreeFormatter.h"

typedef enum
{
	RATING_LONG_TEXT = 1,
	RATING_SHORT_TEXT = 0,
}ERatingTextMode;

typedef enum
{
    // TV Parental Guide  data
    RATING_TV_Y_ALL,
    RATING_TV_Y7_ALL,
    RATING_TV_Y7_FV,
    RATING_TV_G_ALL,
    RATING_TV_PG_ALL,
    RATING_TV_PG_V,
    RATING_TV_PG_S,
    RATING_TV_PG_L,
    RATING_TV_PG_D,
    RATING_TV_14_ALL,
    RATING_TV_14_V,
    RATING_TV_14_S,
    RATING_TV_14_L,
    RATING_TV_14_D,
    RATING_TV_MA_ALL,
    RATING_TV_MA_V,
    RATING_TV_MA_S,
    RATING_TV_MA_L,

    // MPAA  data
    RATING_TV_MPAA,
    RATING_TV_MPAA_NR,
    // Canadian English  data
    RATING_TV_CAN_ENG,
    RATING_TV_CAN_ENG_E,
    // Canadian French  data
    RATING_TV_CAN_FRE,
    RATING_TV_CAN_FRE_E,

    // rating value for dvb
    RATING_TV_DVB
}ERatingData;


class TSRatingInfo : public TCMarshalable
{
private:
	enum
	{
		TAG_RATINGSYSTEM,
		TAG_RATING,
		TAG_VSLD,
	};

public:
	char ratingSystem;	// Rating region system which can contain several rating dimensions
	char rating;		// Rating value within a given rating dimension
	char vsld; 			// Rating dimension which contain several rating levels(values)

	TSRatingInfo() : ratingSystem(0), rating(0), vsld(0) {}

	bool ClassToTree(TCTreeBranch& treeParent)
	{
		TCClassToTreeFormatter helper(&treeParent);
		helper.PushValue(TAG_RATINGSYSTEM, sizeof(char), &ratingSystem);
		helper.PushValue(TAG_RATING, sizeof(char), &rating);
		helper.PushValue(TAG_VSLD, sizeof(char), &vsld);
		return helper.Extract();
	}

	bool TreeToClass(TCTreeBranch& treeMine)
	{
		TCTreeToClassFormatter helper(&treeMine);
		helper.PushValue(TAG_RATINGSYSTEM, sizeof(char), &ratingSystem);
		helper.PushValue(TAG_RATING, sizeof(char), &rating);
		helper.PushValue(TAG_VSLD, sizeof(char), &vsld);
		return helper.FillOut();

	}
};

#endif // _RATINGDATATYPE_H_

