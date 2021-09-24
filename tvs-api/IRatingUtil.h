#ifndef _IRATINGUTIL_H_
#define _IRATINGUTIL_H_

#include "TVServiceDataType.h"
#include "IRating.h"
#include "RatingDataType.h"



enum RATING_SYSTEM_INFO
{
	// MPA or MPA3 RATING
	MPA_NA		= 0,
	MPA_G		= 1,
	MPA_PG		= 2,
	MPA_PG13	= 3,
	MPA_R		= 4,
	MPA_NC17	= 5,
	MPA_X		= 6,
	MPA_NR		= 7,

	// US RATING
	US_NONE		= 0,
	US_TV_Y		= 1,
	US_TV_Y7	= 2,
	US_TV_G		= 3,
	US_TV_PG	= 4,
	US_TV_14	= 5,
	US_TV_MA	= 6,

	// CANADIAN ENGLISH
	CAN_ENG_E	= 0,
	CAN_ENG_C	= 1,
	CAN_ENG_C8	= 2,
	CAN_ENG_G	= 3,
	CAN_ENG_PG	= 4,
	CAN_ENG_14	= 5,
	CAN_ENG_18	= 6,

	// CANADIAN FRENCH
	CAN_FRE_E	= 0,
	CAN_FRE_G	= 1,
	CAN_FRE_8	= 2,
	CAN_FRE_13	= 3,
	CAN_FRE_16	= 4,
	CAN_FRE_18	= 5,

	// AUSTRILIA
	AUSTRILIA_G	= 0x06,
	AUSTRILIA_PG = 0x08,
	AUSTRILIA_M	= 0x0a,
	AUSTRILIA_MA = 0x0c,
	AUSTRILIA_AV = 0x0e,
	AUSTRILIA_R	= 0x0f,
	AUSTRILIA_ALLOW_ALL= 0xff,

	// BRAZIL
	BRAZIL_10	= 0x02,
	BRAZIL_12	= 0x03,
	BRAZIL_14	= 0x04,
	BRAZIL_16	= 0x05,
	BRAZIL_18	= 0x06,
	BRAZIL_BLOCK_ALL	= 0x00,	// not defined in Brazil Spec. just used in Menu Setting.
	BRAZIL_ALLOW_ALL 	= 0xff,	// not defined in Brazil Spec. just used in Menu Setting.
	BRAZIL_RATING_MIN	= BRAZIL_10,
	BRAZIL_RATING_MAX	= BRAZIL_18,

	EUR_RATING_NO_BLOCK  = 0xff,
	EUR_RATING_BLOCK_ALL  = 0xfe,
	EUR_RATING_3  = 0x00,
	EUR_RATING_4  = 0x01,
	EUR_RATING_5  = 0x02,
	EUR_RATING_6  = 0x03,
	EUR_RATING_7  = 0x04,
	EUR_RATING_8  = 0x05,
	EUR_RATING_9  = 0x06,
	EUR_RATING_10 = 0x07,
	EUR_RATING_11 = 0x08,
	EUR_RATING_12 = 0x09,
	EUR_RATING_13 = 0x0a,
	EUR_RATING_14 = 0x0b,
	EUR_RATING_15 = 0x0c,
	EUR_RATING_16 = 0x0d,
	EUR_RATING_17 = 0x0e,
	EUR_RATING_18 = 0x0f,
	EUR_RATING_MIN = EUR_RATING_3,
	EUR_RATING_MAX = EUR_RATING_18,

	// Two more ratings than Europe standard in France
	FRA_RATING_GP  = 0x10, // General Public
	FRA_RATING_PAA = 0x11,// Parental Agreement Advisable
	FRA_RATING_MIN = EUR_RATING_3,
	FRA_RATING_MAX = FRA_RATING_PAA,// Max rating value in French Program Stream

	// Default rating for Fransat (for blocking AV by default if EIT is unavailable)
	FRANSAT_RATING_BLOCK_AV = 0xfd,

	// Only three category ratings in Sweden
	SWE_RATING_CHILDREN = EUR_RATING_4,
	SWE_RATING_YOUTH = EUR_RATING_8,
	SWE_RATING_ADULT = EUR_RATING_12,
	SWE_RATING_MIN = SWE_RATING_CHILDREN,
	SWE_RATING_MAX = SWE_RATING_ADULT,

	//New zealand
	NZE_RATING_ALLOW_ALL = 0xff,
	NZE_RATING_G = 0x06,
	NZE_RATING_PGR = 0x08,
	NZE_RATING_AO = 0x0c,

	//! Norway ratings
	NOR_RATING_7 = EUR_RATING_7,
	NOR_RATING_11 = EUR_RATING_11,
	NOR_RATING_15 = EUR_RATING_15,
	NOR_RATING_18 = EUR_RATING_18,
	NOR_RATING_MIN = EUR_RATING_7,
	NOR_RATING_MAX = EUR_RATING_18,

	//! Spain ratings
	SPA_RATING_UNCLASSIFIED = EUR_RATING_3,
	SPA_RATING_7 = EUR_RATING_7,
	SPA_RATING_13 = EUR_RATING_13,
	SPA_RATING_18 = EUR_RATING_18,
	SPA_RATING_ALLPUBLIC = 0x1d,
	SPA_RATING_CHILDREN = 0x1e,
	SPA_RATING_XRATED = 0x1F,

	//! Japan ratings
	JPN_RATING_ALLOW_ALL = 0xff,
	JPN_RATING_4  = 0x01,
	JPN_RATING_5  = 0x02,
	JPN_RATING_6  = 0x03,
	JPN_RATING_7  = 0x04,
	JPN_RATING_8  = 0x05,
	JPN_RATING_9  = 0x06,
	JPN_RATING_10 = 0x07,
	JPN_RATING_11 = 0x08,
	JPN_RATING_12 = 0x09,
	JPN_RATING_13 = 0x0a,
	JPN_RATING_14 = 0x0b,
	JPN_RATING_15 = 0x0c,
	JPN_RATING_16 = 0x0d,
	JPN_RATING_17 = 0x0e,
	JPN_RATING_18 = 0x0f,
	JPN_RATING_19 = 0x10,
	JPN_RATING_20 = 0x11,	
	JPN_RATING_MIN = JPN_RATING_4,
	JPN_RATING_MAX = JPN_RATING_20,

	//! SINGAPORE ratings
	SG_ALLOW_ALL = 0xff,
	SG_RATING_G = 0x01,
	SG_RATING_PG = 0x04,
	SG_RATING_PG13 = 0x0a,
	SG_RATING_NC16 = 0x0d,
	SG_RATING_M18 = 0x0f,
	SG_RATING_R21 = 0x12,
	SG_RATING_MIN = SG_RATING_G,
	SG_RATING_MAX = SG_RATING_R21,

	// ARGENTINA ratings
	ARGENTINA_13	= 0x02,
	ARGENTINA_16	= 0x03,
	ARGENTINA_18	= 0x04,
	ARGENTINA_C	= 0x05,
	ARGENTINA_BLOCK_ALL	= 0x00,	// not defined in Argentina Spec. just used in Menu Setting.
	ARGENTINA_ALLOW_ALL 	= 0xff,	// not defined in Argentina Spec. just used in Menu Setting.
	ARGENTINA_RATING_MIN	= ARGENTINA_13,
	ARGENTINA_RATING_MAX	= ARGENTINA_C,
	
};


class IRatingUtil
{
protected:
	virtual ~IRatingUtil(void){};
public:
	virtual int SetUnlockedInfo(_IN_ const TVSHandle& in_handle, _IN_ int in_rating_info) =0;
	virtual int GetTempRatingBlockedFlag(_IN_ const TVSHandle& in_handle, _INOUT_ bool& out_flag) = 0;
	virtual int SetTempRatingBlockedFlag(_IN_ const TVSHandle& in_handle, _IN_ bool in_flag) = 0;
	virtual int SetTempUnblockedLevel(_IN_ const TVSHandle& in_handle, _IN_ int in_rating) = 0;
	virtual int GetTempUnblockedLevel(_IN_ const TVSHandle& in_handle, _INOUT_ int& out_rating) = 0;
	virtual int SetUnBlockedFlag18(_IN_ const TVSHandle& in_handle, _IN_ bool in_flag) = 0;
	virtual int SetRespondToCam(_IN_ const TVSHandle& in_handle, _IN_ bool in_flag) = 0;
	virtual int FlagRespondToCam(_IN_ const TVSHandle& in_handle, _INOUT_ bool& out_flag) = 0;
	virtual int SetServiceLocked(_IN_ const TVSHandle& in_handle, _IN_ bool in_serviceLocked ) = 0;
	virtual int FlagServiceLocked(_IN_ const TVSHandle& in_handle, _INOUT_ bool& out_serviceLocked ) = 0;
	virtual int SetTempUnblockedZiggoChildLock( _IN_ const TVSHandle& in_handle, _IN_ bool in_bChildLocked ) = 0;
	virtual int FlagTempUnblockedZiggoChildLock(_IN_ const TVSHandle& in_handle, _INOUT_ bool& out_bChildLocked ) = 0;
	virtual int SetTempRatingBlockedByCamFlag( _IN_ const TVSHandle& in_handle, _IN_ bool in_flag) = 0;
	virtual int GetTempRatingBlockedByCamFlag(_IN_ const TVSHandle& in_handle, _INOUT_ bool& out_flag) = 0;
	virtual int SendRatingChangedFromGuide(_IN_ const TVSHandle& in_handle) = 0;
	virtual int SetUnlockedInfoWhenFactoryMode(_IN_ const TVSHandle& in_handle,_IN_ bool in_lock) =0;


};

#endif

