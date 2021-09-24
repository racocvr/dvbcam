/** 
 * @file ServiceGuideDataType.h
 * @brief Data types related to service guide.
 *
 * Copyright 2013 by Samsung Electronics, Inc.,
 * 
 * This software is the confidential and proprietary information
 * of Samsung Electronics, Inc. ("Confidential Information"). You
 * shall not disclose such Confidential Information and shall use
 * it only in accordance with the terms of the license agreement
 * you entered into with Samsung.
 */
#ifndef _SERVICEGUIDEDATATYPE_H_
#define _SERVICEGUIDEDATATYPE_H_

#include "Marshalable.h"
#include "TreeBranchMap.h"
#include "TreeBranchList.h"
#include "TreeLeafVar.h"
#include "TreeLeafFixed.h"
#include "ServiceData.h"


typedef enum
{
	TEXT_TYPE_TITLE = 0x00,
	TEXT_TYPE_EXTENDED_TEXT,
	TEXT_TYPE_DESCRIPTOR_RAW_DATA,
	TEXT_TYPE_SOURCE_NAME,
	TEXT_TYPE_GUIDANCE_DESC,
	MAX_TEXT_TYPE,
} ETextType;

typedef enum
{
	MONITORING_INVALID,
	MONITORING_START_STOP_CHANGE,	// in case of running status valid
	MONITORING_CHANGE_ONLY,			// in case of default
} EProgramMonitoringType;

typedef enum
{
	MPA_RATING              = 0,	//!<MPA Rating (Motion Picture Association) Rating
	US_RATING               = 1,	//!<US_RATING
	MPA3_RATING             = 2,	//!<MPA3_RATING
	CANADIAN_ENGLISH_RATING = 3,	//!<CANADIAN_ENGLISH_RATING
	CANADIAN_FRENCH_RATING  = 7,	//!<CANADIAN_FRENCH_RATING
	RESERVED_RATING0        = 11,	//!<RESERVED_RATING0
	RESERVED_RATING1        = 15,	//!<RESERVED_RATING1
	UNDEFINED_RATING        = 8,	//!<UNDEFINED_RATING,
	DOWNLOADABLE_RATING 	= 16,	//!<Downloadable RRT
	KR_RATING				= 18,	// KR Rating
} ERating;

typedef enum
{
	MPA_RATING_NA        = 0,	//!<Not Applicable
	MPA_RATING_G         = 1,	//!<General Audiences-All Ages Admitted
	MPA_RATING_PG        = 2,	//!< Parental Guidance Suggested
	MPA_RATING_PG_13     = 3,	//!<Parents Strongly Cautioned. Some Material May Be Inappropriate For Children Under 13
	MPA_RATING_R         = 4,	//!<Restricted, Under 17 Requires Accompanying Parent Or Adult Guardian
	MPA_RATING_NC_17     = 5,	//!< No One 17 And Under Admitted
	MPA_RATING_X         = 6,	//!<Adults only. No one under 17 admitted
	MPA_RATING_NOT_RATED = 7,	//!<Not Rated
} EMPARating;

typedef enum
{
	KR_PARENTAL_NA = 0,
	KR_PARENTAL_TV_ALL = 1,
	KR_PARENTAL_TV_7 = 2,
	KR_PARENTAL_TV_12 = 3,
	KR_PARENTAL_TV_15 = 4,
	KR_PARENTAL_TV_19 = 5,
} EKRRating;

typedef enum
{
	US_PARENTAL_RATING_NONE     = 0,	//!None1
	US_PARENTAL_US_RATING_TV_Y  = 1,	//!<All Children
	US_PARENTAL_US_RATING_TV_Y7 = 2,	//!<Directed to Older Children
	US_PARENTAL_US_RATING_TV_G  = 3,	//!General Audiences
	US_PARENTAL_US_RATING_TV_PG = 4,	//!Parental Guidance Suggested
	US_PARENTAL_US_RATING_TV_14 = 5,	//!Parents Strongly Cautioned
	US_PARENTAL_US_RATING_TV_MA = 6,	//!Mature Audiences Only
	US_PARENTAL_US_RATING_NONE2 = 7,	//!None2
} EUsParentRate;

typedef enum
{
	RRT_REGION_US			= 0x01, //!<RRT Region - US
	RRT_REGION_CANADIAN		= 0x02,	//!<RRT Region - Canadian
	RRT_REGION_KR			= 0x04,
	RRT_REGION_DOWNLOADABLE	= 0x05,	//!<RRT Region - DRRT
} ERRTRegion;

typedef enum
{
	ALL_CRID					= 0x00,

	/// DTG Program CRID value.
	TVA_PROGRAM_CRID			= 0x01,
	PROGRAM_CRID				= 0x31,

	/// DTG Series CRID value.
	TVA_SERIES_CRID				= 0x02,
	SERIES_CRID					= 0x32,
	
	/// DTG Recommendation CRID value.
	TVA_RECOMMENDATION_CRID	= 0x03,
	RECOMMENDATION_CRID			= 0x33,

	UNKNOWN_CRID
} ECRIDType;

typedef enum
{
	FSAT_ALL_PROGRAMS = 0,		///< All genres.
	FSAT_MOVIE, 				///< Movies.
	FSAT_NEWS_AND_FACTUAL,		///< News and factual programmes.
	FSAT_ENTERTAINMENT, 		///< Entertainment.
	FSAT_SPORT, 				///< Sport
	FSAT_CHILDRENS, 			///< Children's programmes.
	FSAT_EDUCATION, 			///< Education.
	FSAT_LIFESTYLE, 			///< Lifestyle.
	FSAT_DRAMA, 				///< Drama.
	FSAT_EVENT_GENRE_MAX		///< End-of-list limiter.
} EFSatEventGenreType;

typedef enum 
{
	FIRST_PROGRAM,
	PREVIOUS_PROGRAM,
	NEXT_PROGRAM,
	LAST_PROGRAM
} EProgramIndicator;


typedef enum
{
	CURRENT_PROGRAM_MODIFIED,
	CHANGED_TO_NEW_PROGRAM,
} EProgramChanged;

class TCProgramId : public TCMarshalable
{
private:
	enum 
	{
		TAG_SERVICEID,
		TAG_EVENTID,
		TAG_START_TIME,
		TAG_DURATION,
		TAG_EIT_TABLE_ID,
		TAG_EIT_NUMBER
	};

public:
	bool operator<(const TCProgramId& );//it is for comparator
	virtual bool ClassToTree(TCTreeBranch& treeParent);

	virtual bool TreeToClass(TCTreeBranch& treeMine);

	//common
	TCServiceId m_serviceId;
	unsigned short m_eventId;

	//dvb
	unsigned long m_utc_starttime;
	unsigned long m_utc_duration;
	int m_eit_table_id;

	//atsc
	unsigned char m_eit_number;
};


class TCProgramMonitorId : public TCMarshalable
{
private:
	enum 
	{
		TAG_SERVICEID,
		TAG_EVENTID,
		TAG_START_TIME,
		TAG_DURATION,
		TAG_CRID
	};

public:
	virtual bool ClassToTree(TCTreeBranch& treeParent);

	virtual bool TreeToClass(TCTreeBranch& treeMine);

	//common
	TCServiceId m_serviceId;
	unsigned short m_eventId;
	unsigned long m_starttime;
	unsigned long m_duration;
	std::string m_program_crid;
};

struct TSBarkerChannelLocator : public TCMarshalable
{
private:
	enum
	{
		TAG_ONID,
		TAG_TSID,
		TAG_TPID,
	};

	virtual bool ClassToTree(TCTreeBranch& treeParent);

	virtual bool TreeToClass(TCTreeBranch& treeMine);

public:
	struct Data
	{
		unsigned short onid;
		unsigned short tsid;
		unsigned short tpid;
		bool operator==( const Data & other ) const { return onid == other.onid && tsid == other.tsid && tpid == other.tpid; }
		bool operator!=( const Data & other ) const { return !(*this == other); }
	} data;

	TSBarkerChannelLocator(void)
	{
		data.onid = INVALID;
		data.tpid = INVALID;
		data.tsid = INVALID;
	}
};

#endif // _SERVICEGUIDEDATATYPE_H_
