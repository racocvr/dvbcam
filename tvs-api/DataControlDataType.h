/** 
 * @file DataControlDataType.h
 * @brief Data control related types.
 *
 * Copyright 2013 by Samsung Electronics, Inc.,
 * 
 * This software is the confidential and proprietary information
 * of Samsung Electronics, Inc. ("Confidential Information"). You
 * shall not disclose such Confidential Information and shall use
 * it only in accordance with the terms of the license agreement
 * you entered into with Samsung.
 */


#ifndef _DATACONTROLDATATYPE_H_
#define _DATACONTROLDATATYPE_H_


#include "SOSpecDataType.h"
#include "Marshalable.h"


#define MAX_USER_DATA_BUF_SIZE 1024
#define MAX_PES_USER_DATA_BUF_SIZE 0x10000


typedef enum
{
    CAPTION_DATA_MODE_INVALID = -1,//!< Invalid User Data.
	CAPTION_DATA_MODE_DIGITAL = 0,//!< Digital Caption Data(Closed Caption).
	CAPTION_DATA_MODE_ANALOG = 1,//!< Analog Caption Data(Closed Caption).
}ECaptionDataMode;

//!< PES data type
typedef enum
{
	PES_DATA_TYPE_UNKNOWN = -1,		//!< unknown type
	PES_DATA_TYPE_TTX,			    //!< TTX PES data
	PES_DATA_TYPE_SUBTITLE,	        //!< subtitle PES data
	PES_DATA_TYPE_ISDBCAPTION,	    //!< Japanese caption PES data
	PES_DATA_TYPE_SUPERIMPOSE,	    //!< Japanese superimpose PES data
	PES_DATA_TYPE_MAX,
}EPESDataType;

typedef enum
{
	CAPTION_SERVICE_DEFAULT,
	CAPTION_SERVICE_SERVICE1,
	CAPTION_SERVICE_SERVICE2,
	CAPTION_SERVICE_SERVICE3,
	CAPTION_SERVICE_SERVICE4,
	CAPTION_SERVICE_SERVICE5,
	CAPTION_SERVICE_SERVICE6,
	CAPTION_SERVICE_CC1,
	CAPTION_SERVICE_CC2,
	CAPTION_SERVICE_CC3,
	CAPTION_SERVICE_CC4,
	CAPTION_SERVICE_TEXT1,
	CAPTION_SERVICE_TEXT2,
	CAPTION_SERVICE_TEXT3,
	CAPTION_SERVICE_TEXT4,
	CAPTION_SERVICE_MAX,
}ECaptionService;

typedef enum
{
	INVALID_LINE = 0,
	TTX_LINE = -1,					//!< TTX Line (6~22, 318~335)
	VPS_LINE = 16,					//!< VPS line (16)
	CC_SIGNAL_LINE1 = 21,			//!< USER Data Monitoring Line
	CC_SIGNAL_LINE2 = 284,			//!< USER Data Monitoring Line
	CC_SIGNAL_LINE1_PAL_N = 18,		//!< USER Data Monitoring Line
	CC_SIGNAL_LINE2_PAL_N = 281,	//!< USER Data Monitoring Line
}EVBILine;

typedef enum
{
	ISDB_TEXT_MODE_CAPTION = 0,
	ISDB_TEXT_MODE_SUPERIMPOSE,
	ISDB_TEXT_MODE_MAX,
}EISDBTextType;

typedef enum
{
	PRIMARY_LANGUAGE,
	SECONDARY_LANGUAGE,
	MAX_PREFERRED_LANGUAGE,
}EPreferredLanguage;

typedef enum
{
	TTX_COMMAND_ON,
	TTX_COMMAND_OFF,
	TTX_COMMAND_CHANGE_LANGUAGE,
	TTX_COMMAND_REMOTE_KEY,
	TTX_COMMAND_IS_AVAILABLE,
	TTX_COMMAND_COLORKEY_INDEX,
	TTX_COMMAND_SET_TTXLIST_MODE,
	TTX_SUBTITLE_COMMAND_ON,
	TTX_SUBTITLE_COMMAND_OFF,
}ETTXCmd;


typedef enum
{
	TTX_TYPE_INVALID = 0x00,
	TTX_INITIAL_PAGE = 0x01,
	TTX_SUBTITLE_PAGE,
	TTX_ADDITIONAL_INFO_PAGE,
	TTX_PROGRAMME_SCHEDULE_PAGE,
	TTX_SUBTITLE_HARD_OF_HEARING,
}ETTXType;

typedef enum
{
	SBT_NORMAL = 0,
	SBT_NORMAL_4_3,
	SBT_NORMAL_16_9,
	SBT_NORMAL_224_1,
	SBT_NORMAL_HD,
	SBT_HARD_OF_HEARING,
	SBT_HARD_OF_HEARING_43,
	SBT_HARD_OF_HEARING_16_9,
	SBT_HARD_OF_HEARING_224_1,
	SBT_HARD_OF_HEARING_HD,
	SBT_TYPE_MAX,
}ESubtitle;

typedef enum
{
	SBT_TYPE_INVALID = 0x00,
	SBT_TYPE_NORMAL = 0x10,
	SBT_TYPE_NORMAL_4_3 = 0x11,
	SBT_TYPE_NORMAL_16_9 = 0x12,
	SBT_TYPE_NORMAL_224_1 = 0x13,
	SBT_TYPE_NORMAL_HD = 0x14,
	SBT_TYPE_HARD_OF_HEARING = 0x20,
	SBT_TYPE_HARD_OF_HEARING_43 = 0x21,
	SBT_TYPE_HARD_OF_HEARING_16_9 = 0x22,
	SBT_TYPE_HARD_OF_HEARING_224_1 = 0x23,
	SBT_TYPE_HARD_OF_HEARING_HD = 0x24,
	SBT_TYPE_MAXIMUM,
}ESubtitleType;

typedef enum
{
	HYBRID_SBT_TYPE_INVALID = -1,
	HYBRID_SBT_TYPE_DVB = 0,
	HYBRID_SBT_TYPE_TTX,
	HYBRID_SBT_TYPE_MAX,
}EHybridSBTType; 

typedef enum
{
	SUBTITLE_TYPE_NORMAL = 0,
	SUBTITLE_TYPE_HARD_OF_HEARING,
	SUBTITLE_TYPE_MAX,
}ESBTType;

typedef enum
{
	DATA_SERVICE_NOT_SUPPORTED = 0,	// No data service supported
	SUPPORT_MHEG = 1, 		// MHEG - no connection with Java application
	SUPPORT_MHP = 2,		// MHP - JAVA supported
	SUPPORT_GINGA = 3,		// GINGA - JAVA supported
	SUPPORT_BML = 4,		// BML - no connection with Java application
	SUPPORT_HBBTV = 5, 		// HBBTV - HBBTV supported
	SUPPORT_DTMB_I = 6,
}EDataServiceSupportType;

typedef struct
{
    short pid;                                      // PES pid
    unsigned long pts;                              // PES pts
	unsigned char data[MAX_PES_USER_DATA_BUF_SIZE]; //MAX_PACKET_BUF_SIZE
	int size;
}TSPESUserData;

typedef struct 
{
	bool	monitorOnOff;
	short	monitorPID;
	int		language;
	int		compTag;
}TSPESMonitorInfo;

class TCTTX
{
public:
	//! teletext language
	ELanguageCode language;
	//! TTX type
	unsigned char type;
	//! magazine number
	unsigned char magazine;
	//! page number
	unsigned char page;

	char dummy_char;
	//! PID
	unsigned short pid;
	unsigned char componentTag;
	char			dummyChar2;

	TCTTX( void );
	bool FlagEqual( TCTTX* pSrc );

	/*
	// For Serialize 
	virtual TISerializable::ESerializableType GetSerializedType(void);
	virtual bool ClassToTree(TCMarshalTreeBranch& treeParent);
	virtual bool TreeToClass(TCMarshalTreeBranch& treeMine);
	*/
};


class TCSBT
{
public: 
	//! subtitle language
	ELanguageCode language;

	//! subtitlling type
	unsigned char type[SBT_TYPE_MAX];

	short	dummyShort;
	//! composition page id
	unsigned short compPageId[SBT_TYPE_MAX];
	//ancillary page id
	unsigned short ancPageId[SBT_TYPE_MAX];
	//! PID
	short  pid[SBT_TYPE_MAX];
	unsigned char componentTag[SBT_TYPE_MAX];
	short		dummyShort2;

	TCSBT( void );
	bool FlagEqual( TCSBT* pSrc );

	/*
	// For Serialize 
	virtual TISerializable::ESerializableType GetSerializedType(void);
	virtual bool ClassToTree(TCMarshalTreeBranch& treeParent);
	virtual bool TreeToClass(TCMarshalTreeBranch& treeMine);
	*/
};


class TCHybridSBT
{
public:
	EHybridSBTType sbtType;		//! subtitle type( 0 : DVB sustitle(magazine & page is invalid..) , 1: TTX subtitle(compPageId & ancPageId is invalid.)  )
	char dummyChar;
	unsigned short pid;				//! elementary stream pid
	unsigned short compPageId;	//! composition page id (for DVB subtitle)
	unsigned short ancPageId;	//! ancillary page id (for DVB subtitle)
	unsigned char magazine;		//! magazine number (for TTX subtitle)
	unsigned char	 page;			//! page number(for TTX subtitle)
	unsigned char componentTag;
	char dummyChar2;

	TCHybridSBT( void );
	bool FlagEqual( TCHybridSBT* pSrc );

	/*
	// For Serialize 
	virtual TISerializable::ESerializableType GetSerializedType(void);
	virtual bool ClassToTree(TCMarshalTreeBranch& treeParent);
	virtual bool TreeToClass(TCMarshalTreeBranch& treeMine);
	*/
};


class TCISDBText
{
public :
	enum CONSTVALUE // Prevent enum parser error.
	{
		SIZE_OF_JPN_REGION = 7,
	};


	//! component_tag in stream identifier descriptor
	ELanguageCode language;
	// 4 byte
	
	unsigned char componentTag;
	//! Language Tag	: This is used for BML application for Japan model.
	unsigned char languageTag;
	//! PID
	unsigned short pid;
	// 4 byte

	unsigned char region[SIZE_OF_JPN_REGION];

	bool operator> (const TCISDBText& text) const { return componentTag > text.componentTag; }

	TCISDBText( void );
	bool FlagEqual( TCISDBText* pSrc );

	/*
	// For Serialize 
	virtual TISerializable::ESerializableType GetSerializedType(void);
	virtual bool ClassToTree(TCMarshalTreeBranch& treeParent);
	virtual bool TreeToClass(TCMarshalTreeBranch& treeMine);
	*/
};


struct TSTTX: public TCMarshalable
{
	ELanguageCode language;		//! teletext language
	ETTXType type;				//! TTX type
	unsigned short pid;			//! PID
	unsigned char magazine;		//! magazine number
	unsigned char page;			//! page number
	unsigned char componentTag;

	TSTTX(void);
	bool operator == (const TSTTX& ref) const;

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

private:
	enum
	{
		TAG_LANGUAGE,
		TAG_TYPE,
		TAG_PID,
		TAG_MAGAZINE,
		TAG_PAGE,
		TAG_COMPONENTTAG,
	};
};

struct TSHybridSBT: public TCMarshalable
{
	EHybridSBTType sbtType;		//! subtitle type( 0 : DVB sustitle(magazine & page is invalid..) , 1: TTX subtitle(compPageId & ancPageId is invalid.)  )
	unsigned short pid;			//! elementary stream pid
	unsigned short compPageId;	//! composition page id (for DVB subtitle)
	unsigned short ancPageId;	//! ancillary page id (for DVB subtitle)
	unsigned char magazine;		//! magazine number (for TTX subtitle)
	unsigned char page;			//! page number(for TTX subtitle)
	unsigned char componentTag;

	TSHybridSBT(void);
	bool operator == (const TSHybridSBT& ref) const;

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

private:
	enum
	{
		TAG_SBTTYPE,
		TAG_PID,
		TAG_COMPPAGEID,
		TAG_ANCPAGEID,
		TAG_MAGAZINE,
		TAG_PAGE,
		TAG_COMPONENTTAG,
	};
};

struct TSISDBText : public TCMarshalable
{
	static const unsigned int SIZE_OF_JPN_REGION = 7;

	//! component_tag in stream identifier descriptor
	ELanguageCode language;
	//! PID
	unsigned short pid;
	unsigned char componentTag;
	//! Language Tag: This is used for BML application for Japan model.
	unsigned char languageTag;
	unsigned char region[SIZE_OF_JPN_REGION];

	TSISDBText(void);
	bool operator == (const TSISDBText& ref) const;
	bool operator < (const TSISDBText& ref) const { return componentTag < ref.componentTag; }

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

private:
	enum
	{
		TAG_LANGUAGE,
		TAG_PID,
		TAG_COMPONENTTAG,
		TAG_LANGUAGETAG,
		TAG_REGION,
	};
};

struct TSComponent: public TCMarshalable
{
	unsigned short pid;					//! PID
	unsigned char componentTag;			//! component_tag in stream identifier descriptor
	unsigned char streamType;
	bool mhLevel;						// Hierarchical Transmission Level, true: HIGH, false: LOW
	unsigned short mhAlternativePid;

	TSComponent(void);
	bool operator == (const TSComponent& ref) const;

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

private:
	enum
	{
		TAG_PID,
		TAG_COMPONENTTAG,
		TAG_STREAMTYPE,
		TAG_MHLEVEL,
		TAG_MHALTERNATIVEPID,
	};
};


#endif // _DATACONTROLDATATYPE_H_

