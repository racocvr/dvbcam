/** 
 * @file ProgramData.h
 * @brief Data of single program (event).
 *
 * Copyright 2013 by Samsung Electronics, Inc.,
 * 
 * This software is the confidential and proprietary information
 * of Samsung Electronics, Inc. ("Confidential Information"). You
 * shall not disclose such Confidential Information and shall use
 * it only in accordance with the terms of the license agreement
 * you entered into with Samsung.
 */


#ifndef _PROGRAMDATA_H_
#define _PROGRAMDATA_H_


#include "Marshalable.h"
#include "TVServiceDataType.h"
#include "ServiceData.h"
#include "ServiceGuideDataType.h"
#include "ProgramSubscriberDataType.h"
#include <string>
#include <list>

class TCProgramData : public TCMarshalable
{
private:
	enum 
	{
		TAG_SERVICEID,
		TAG_EVENTID,
		TAG_STARTTIME,
		TAG_DURATION,
		TAG_UTC_STARTTIME,
		TAG_UTC_DURATION,
		TAG_TEXT,	
		TAG_EIT_TABLE_ID,
		TAG_EIT_NUMBER,
		TAG_FREE_CA_MODE,
		TAG_LANGUAGE,
		TAG_RUNNING_STATE,
		TAG_PROGRAM_CRID,
		TAG_SERIES_CRID,
		TAG_RECOMMENDATION_CRID,
		TAG_DESCRIPTOR_RAW_DATA_LENGTH,
		TAG_DESCRIPTOR_RAW_DATA_BUFFER,
		TAG_DESCRIPTOR_RAW_DATA_TABLE_ID,
		TAG_TRANSPORT_STREAM_ID,
		TAG_ORIGINAL_NETWORK_ID,
		TAG_PROG_COMP_DATA,
		TAG_GUIDANCE_TYPE, 
		TAG_CONTENT_INFO,
		TAG_USER_INFO,
		TAG_PDSD,
		TAG_SERVICE_PROFILE,
		TAG_EXTENDED_EVENT_ITEM_VECTOR,
		TAG_EPG_RAW_STATE,
		TAG_SHORT_EVENT_TEXT_LEN
	};

public:
	enum EUndefinedTimeValue
	{
		EIT_UNDEFINED_DURATION_VALUE = 0xFFFFFF,		// time could be 0xFFFFFF to indicate undefined duration in EIT pf of Japan
		EIT_UNDEFINED_START_TIME_VALUE = 0xFFFFFFFF,	// time could be 0xFFFFFFFF to indicate undefined start or end time in EIT pf of Japan
	};

	enum EExtendChannelTextLength
	{
		MAX_EVENT_ITEM_LENGTH = 512,
		EXTEND_CHANNEL_TEXT_LENGTH = 4096,
	};

	enum EComponentType
	{
		COMP_TYPE_INVALID = -1,
		COMP_TYPE_VIDEO = 0, 
		COMP_TYPE_AUDIO,
		COMP_TYPE_CAPTION,
		COMP_TYPE_SUPERIMPOSE,
		COMP_TYPE_MAX
	};

	//! Relayed Event Infomation
	class TTEventInfo : public TCMarshalable
	{
	private:
		enum
		{
			TAG_TSID,
			TAG_ONID,
			TAG_SERVICEID,
			TAG_EVENTID,	
		};

	public:
		unsigned short tsid;
		unsigned short onid;
		unsigned short serviceId;
		unsigned short eventId;

		virtual bool ClassToTree(TCTreeBranch& treeParent);
		virtual bool TreeToClass(TCTreeBranch& treeMine);
	};

	class TTComp : public TCMarshalable
	{
	private:
		enum
		{
			TAG_COMPONENTTAG,
			TAG_COMPONENTTYPE,
			TAG_MULTISOUND,
			TAG_QUALITY,
			TAG_COMPONENTTEXT,
			TAG_COMPONENTTEXTLENGTH,
		};

	public:
		unsigned char componentTag;	
		unsigned char componentType;
		int multiSound;
		int quality;
		unsigned char* componentText;
		unsigned int componentTextLen;
		TTComp();
		TTComp(const TTComp& comp);
		~TTComp();
		TTComp& operator=(const TTComp& comp);

		virtual bool ClassToTree(TCTreeBranch& treeParent);
		virtual bool TreeToClass(TCTreeBranch& treeMine);
	};

	// "COPY_TEN_TIMES" is not supported currently. OCT-2011
	// : TV needs to check 'copy_restriction_mode' field of 'content availability descriptor' in PMT.
	//   If this has 0 then dubbing 10 is not allowed. So it is same as exactly 'COPY ONCE'.
	//   But if it has 1 then dubbing 10 is allowed. So this case is 'Dubbing 10'.
	// Condition of Others, refer to "8-TR-B15v4_1-2p4-E1"
	enum ECopyMode
	{
	   COPY_FREE,
	   COPY_TEN_TIMES,
	   COPY_ONCE,
   	   COPY_NEVER,
	};

	class TTSeriesItem : public TCMarshalable
	{
	private:
		enum
		{
			TAG_SERIESID,
			TAG_REPEATLABEL,
			TAG_EXPIREDDATE,
			TAG_PROGRAMPATTERN,
			TAG_EPISODENUMBER,
			TAG_LASTEPISODENUMBER,
			TAG_SERIESNAME,
			TAG_SERIESNAMELENGTH,
		};

	public:
		unsigned short  seriesId;
		char repeatLabel;
		unsigned short expiredDate;
		char programPattern;
		short episodeNumber;
		short lastEpisodeNumber;
		unsigned char seriesName[EXTEND_CHANNEL_TEXT_LENGTH];
		unsigned short seriesNameLength;

		virtual bool ClassToTree(TCTreeBranch& treeParent);
		virtual bool TreeToClass(TCTreeBranch& treeMine);
	};

	class TTEventItem : public TCMarshalable
	{
	private:
		enum 
		{
			TAG_ITEM,
			TAG_ITEMLENGTH,
			TAG_ITEMDESC,
			TAG_ITEMDESCLENGTH,
		};

	public:
		unsigned char item[MAX_EVENT_ITEM_LENGTH];
		unsigned short itemLength;
		unsigned char itemDesc[MAX_EVENT_ITEM_LENGTH];
		unsigned short itemDescLength;
		TTEventItem(void);
		TTEventItem(const TTEventItem& that);
		TTEventItem& operator= (const TTEventItem& lValue);
		

		virtual bool ClassToTree(TCTreeBranch& treeParent);
		virtual bool TreeToClass(TCTreeBranch& treeMine);
	};	
	
	class TCProgCompData : public TCMarshalable
	{
	private:
		enum
		{
			TAG_STL_ITEM,
			TAG_COMP,
		};

		std::vector<TCProgramData::TTComp> m_comp[TCProgramData::COMP_TYPE_MAX];
		
	public: 
		TCProgCompData(void) {}
		~TCProgCompData(void);
		int NumOfComponent(TCProgramData::EComponentType type);
		bool GetComponent(TCProgramData::EComponentType type, int index, TCProgramData::TTComp& comp);
		bool GetComponentList(TCProgramData::EComponentType type,std::vector<TCProgramData::TTComp>& compList);
		bool AddComponent(TCProgramData::EComponentType type,const TCProgramData::TTComp& comp);
		TCProgCompData& operator = (const TCProgCompData& compData);

		// Serializable implementation
		virtual bool ClassToTree(TCTreeBranch& treeParent);
		virtual bool TreeToClass(TCTreeBranch& treeMine);
	};

	TCProgramData( void );
	virtual ~TCProgramData( void );
	TCProgramData( const TCProgramData& );
	TCProgramData& operator=(const TCProgramData& );
	bool GetProgramMonitorId(TCProgramMonitorId& out_program_monitor_id) const;
	bool GetProgramId(TCProgramId& out_program_id) const;
	TCServiceId ServiceId() const;
	unsigned short EventId(void) const;
	unsigned int StartTime(void) const;
	unsigned int EndTime(void) const;
	unsigned int Duration(void) const;

	unsigned long UtcStartTime(void) const;
	unsigned long UtcEndTime(void) const;
	unsigned long UtcDuration(void) const;

	bool Title(t_wchar_t* pTitle, unsigned int* pSize);
	unsigned int TitleLength(void) const;

	bool ExtendedText(t_wchar_t* pText, unsigned int* pSize);
	unsigned int ExtendedTextLength(void) const;

	bool ShortText(t_wchar_t* pText, unsigned int* pSize);
	unsigned int ShortTextLength(void) const;
	
	bool GetGuidance(t_wchar_t* pGuidance, unsigned int* pSize);
	unsigned int GuidanceLength(void) const;
	unsigned int GetGuidanceType(void) const;
	
	bool  FreeCAMode(void)	const;
	unsigned long Language(void) const;
	ERunningStatus GetRunningStatus(void) const;
	/// Get the program CRID for this event.
	/// @param [out] crid stores the program CRID if found.
	/// @return true if a program CRID was set.
	bool GetProgramCRID(std::string& out_crid) const;
	/// Get the CRIDs of the specified type for this event.
	/// @param [out] crids A reference to a list where the crids are copied.
	/// @param [in] type Specifies the type of CRIDs to return.
	/// @return true if one or more CRIDs were copied to the provided list.
	bool GetCRIDs(std::list<std::string>& crids, ECRIDType type) const;

	bool SetDescriptorRawDataBuffer(unsigned char* pBuffer, unsigned short buffer_length, int table_id_for_parsing);	
	bool GetDescriptorRawDataBuffer(unsigned char*& out_buffer, unsigned short& out_buffer_length, int& out_table_id_for_parsing);

	unsigned short OriginalNetworkId(void) const;
	unsigned short TransportStreamId(void) const;

	static EComponentType ISDBCompType(unsigned char compType);

	bool SetProgCompData(TCProgCompData& in_prog_comp_data);
	bool GetProgCompData(TCProgCompData& out_prog_comp_data);

	/**
	 * @brief Get user nibbles fields for specified index of loop contained in EIT content descriptor.
	 * @param [in]  loopIndex index of iteration in nibble loop.
	 * @param [out] userNibble1 value of the first user nibble value.
	 * @param [out] userNibble2 value of the second user nibble value.
	 */
	void GetUserInfo( int loopIndex, unsigned char &userNibble1, unsigned char &userNibble2 ) const;				
	bool GetContentInfo( unsigned char* pContentNibble1, int loopIndex, unsigned char* pContentNibble2 = NULL ) const;
	int NumOfUserInfo(void) const;
	int NumOfContents(void) const;
	/// \brief Acquire PDSD for Freesat/UK_DTT .
	/// \remark Currently only Freesat/UK_DTT specifies a PDSD must be present if the descriptor
	unsigned long GetPDSD(void) const {return t_pdsd;}
	EServiceProfile GetServiceProfile(void) const {return t_service_profile;}

	bool GetItemList(std::vector<TTEventItem>& out_extended_event_item_vector);

	/**
	 * @brief Sets EPG raw state.
	 * @remark Used during program list subscription (MHP).
	 * @remark Passed value represent bit sum of EEpgRawState enum.
	 * @param [in] state EPG raw state.
	 */
	void SetEpgRawState(unsigned char state);

	/**
	 * @brief Gets EPG raw state.
	 * @remark Used during program list subscription (MHP).
	 * @remark Returned value represent bit sum of EEpgRawState enum.
	 * @return Return EPG raw state.
	 */
	unsigned char GetEpgRawState(void);

protected:
	TCServiceId t_serviceId;
	unsigned short t_eventId;

	// ATSC
	unsigned int t_starttime;
	unsigned int t_duration;

	/// DVB
	unsigned long t_utc_starttime;
	unsigned long t_utc_duration;


	/// Flag indicating the event if the program can be viewed without
	/// descrambling
	bool t_free_ca_mode;

	/// The language code (ISO639) for this object.
	unsigned long t_language;

	/// Flag indication the event if
	ERunningStatus t_running_state;

	/// The program CRID for this event.
	std::string t_programCRID;

	/// A list of series CRID this event belongs to.
	std::list<std::string> t_seriesCRID;

	/// A list of recommendation CRIDs for this event.
	std::list<std::string> t_recdCRID;

	
	int t_eit_table_id;
	unsigned char t_eit_number;
	std::string t_text[MAX_TEXT_TYPE];
	unsigned int t_shortTextLen;//added to support hbbtv -DF151015-00033

	unsigned short	t_descriptor_raw_data_length;	// descriptor raw data length
	unsigned char*	t_descriptor_raw_data_buffer;	// descriptor raw data buffer
	int t_descriptor_raw_data_table_id;//table id of descriptor raw data parsing

	
	unsigned short t_transportStreamId;//! transport stream id
	unsigned short t_originalNetworkId;//! original network id

	TCProgCompData* t_pProgComp;//component for isdb/jpn

	//Program Guidance type
	unsigned int t_guidanceType;

	//content descriptor
	std::vector< unsigned short > t_content;	// (content nibble1 << 8) + contentNibble2
	std::vector< unsigned short > t_user;		// (user nibble1 << 8) + userNibble2
	unsigned long t_pdsd;//Program PDSD
	EServiceProfile t_service_profile; //to distinguish the freesat program.

	std::vector<TTEventItem> t_extended_event_item_vector;

	// This value represent program subscription state (MHP).
	// It's combined from EEpgRawState enum.
	unsigned char t_epgRawState;

	
	bool t_GetText(t_wchar_t* pText, unsigned int* pLength, ETextType type);
	unsigned int t_TextLength(int type) const;
	virtual void t_Initialize( void );

public:
	virtual bool ClassToTree(TCTreeBranch& treeParent);
	virtual bool TreeToClass(TCTreeBranch& treeMine);
};


/// HD simulcast information.
struct ESimulcastInfo : public TCMarshalable
{
private:
	enum 
	{
		TAG_SERVICEID,
		TAG_PROGRAM,
		TAG_IS_PROGRAM_EXISTED,
		TAG_IS_SERVICE_EXISTED,
		TAG_IS_PROGRAM_RUNNING_NOW,
		TAG_IS_SIMULCAST
	};
public:
	TCServiceId simChan;  ///< Channel with simultanouslty transmitted HD program.
	TCProgramData simProg;  ///< Simultanouslty transmitted HD program.
	bool bProgPresent;                    ///< Indicates if program name has been set.
	bool bChanPresent;                    ///< Indicateds if channel name has been set
	bool bNow;                            ///< Indicates that currently selected program is running now.
	bool bSimulcast;                      ///< Indicates that both programs starts at the same time.

	ESimulcastInfo(void);
	virtual ~ESimulcastInfo(void);
	ESimulcastInfo( const ESimulcastInfo& );
	ESimulcastInfo& operator=(const ESimulcastInfo& );
	virtual bool ClassToTree(TCTreeBranch& treeParent);
	virtual bool TreeToClass(TCTreeBranch& treeMine);	
};


#endif // _PROGRAMDATA_H_
