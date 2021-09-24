/** 
 * @file SatelliteSettingsDataType.h
 * @brief Definitions related to satellite settings.
 *
 * Copyright 2013 by Samsung Electronics, Inc.,
 * 
 * This software is the confidential and proprietary information
 * of Samsung Electronics, Inc. ("Confidential Information"). You
 * shall not disclose such Confidential Information and shall use
 * it only in accordance with the terms of the license agreement
 * you entered into with Samsung.
 */

#ifndef _SATELLITESETTINGSDATATYPE_H_
#define _SATELLITESETTINGSDATATYPE_H_

#include "ScanDataDataType.h"
#include "SatelliteDataType.h"
#include "Marshalable.h"


typedef enum
{
	DISEQC_1_2,
	DISEQC_USALS,
}EDiSEqCVersion;

typedef enum
{
	DISEQC_UNKNOWN = -1,

	// support for DiSEqC ver. > 1.1 ( 16 channels)
	DISEQC_1,
	DISEQC_2,
	DISEQC_3,
	DISEQC_4,
	DISEQC_5,
	DISEQC_6,
	DISEQC_7,
	DISEQC_8,
	DISEQC_9,
	DISEQC_10,
	DISEQC_11,
	DISEQC_12,
	DISEQC_13,
	DISEQC_14,
	DISEQC_15,
	DISEQC_16,
	TONE_BURST_A,
	TONE_BURST_B,
	DISEQC_OFF,

	// compatibility with DiSEqC 1.0 ( 4 channels)
	DISEQC_A = DISEQC_1,
	DISEQC_B = DISEQC_2,
	DISEQC_C = DISEQC_3,
	DISEQC_D = DISEQC_4,

}EDiSEqCMode; 

typedef enum
{
	TONE_22_UNKNOWN = -1,
	TONE_22_OFF,
	TONE_22_ON,
	TONE_22_AUTO,
}ETone22KHz; 

typedef enum
{
	LNB_TYPE_SINGLE,	// LNB with single oscillator
	LNB_TYPE_DUAL,		// LNB with two oscillators
}ELnbType;

typedef enum
{
	SATSET_RESET_ALL,
	SATSET_RESET_SATELLITE,
	SATSET_RESET_SATCR,
}ESatSettingsResetType;

typedef enum
{
	LNB_PREDEFINED_FREQ_1 = 5150000,	// [kHz]
	LNB_PREDEFINED_FREQ_2 = 9750000,	// [kHz]
	LNB_PREDEFINED_FREQ_3 = 10000000,	// [kHz]
	LNB_PREDEFINED_FREQ_4 = 10600000,	// [kHz]
	LNB_PREDEFINED_FREQ_5 = 10750000,	// [kHz]
	LNB_PREDEFINED_FREQ_6 = 11300000,	// [kHz]
	LNB_PREDEFINED_FREQ_7 = 11475000,	// [kHz]
}ELnbConfiguration;


struct TSSatCRSettings : public TCMarshalable
{
	enum
	{
		DATA_SIZE = (sizeof(unsigned char) + sizeof(int)), // size of all elements in struct
	};

	enum
	{
		TAG_SLOT_NUMBER,
		TAG_SLOT_FREQUENCY,
	};

	unsigned char slotNumber;		// 1-8 slot numbers are allowed
	int slotFrequency;				// [kHz]

	TSSatCRSettings(unsigned char slotNum = INVALID, int slotFreq = INVALID) : slotNumber(slotNum), slotFrequency(slotFreq) { }

	/**
	 * @see base class
	 */
	virtual bool ClassToTree(TCTreeBranch& treeParent);

	/**
	 * @see base class
	 */
	virtual bool TreeToClass(TCTreeBranch& treeMine);
};


struct TSSatelliteSettings : public TCMarshalable
{
	enum
	{
		DATA_SIZE = (sizeof(ESatelliteId) + sizeof(int) + sizeof(EScanServiceMode) + sizeof(int) + sizeof(int) \
					+ sizeof(int) + sizeof(EDiSEqCMode) + sizeof(ETone22KHz) + sizeof(bool) + sizeof(ELnbType)), // size of all elements in struct
	};

	enum
	{	
		TAG_SATELLITE_ID,
		TAG_SLOT_ID,
		TAG_SCAN_MODE,
		TAG_LOWER_OSC,
		TAG_UPPER_OSC,
		TAG_SINGLE_OSC,
		TAG_DISEQC_MODE,
		TAG_TONE_22KHZ,
		TAG_LINE_COMPENSATION,
		TAG_LNB_TYPE,
	};


	ESatelliteId satelliteId; // satellite id
	int slotId; // slot id for positioner
	EScanServiceMode scanMode; // disable scanning or scan all/free services
	int lowerOsc; // lower LNB oscillator frequency [kHz]
	int upperOsc; // upper LNB oscillator frequency [kHz]
	int singleOsc; // oscillator frequency in case of single LNB [kHz]
	EDiSEqCMode diSEqCMode; // DiSEqC mode
	ETone22KHz tone22kHz; // 22 kHz tone setting - specifies whether to send a 22 kHz pulse tone to the LNB
	bool lineCompensation; // line compensation
	ELnbType lnbType; // dual or single LNB

	TSSatelliteSettings( ESatelliteId satId = SATID_ASTRA_19_2E, EScanServiceMode scanServMode = SCAN_SERVICE_MODE_NONE,
		int lowOsc = 9750000, int upOsc = 10600000, int sngOsc = 11300000, EDiSEqCMode diSEqC = DISEQC_OFF,
		ETone22KHz tone = TONE_22_AUTO, int slot = 1, bool lineComp = false, ELnbType lnb = LNB_TYPE_DUAL)
		: satelliteId(satId), slotId(slot), scanMode(scanServMode), lowerOsc(lowOsc), upperOsc(upOsc), singleOsc(sngOsc),
		diSEqCMode(diSEqC), tone22kHz(tone), lineCompensation(lineComp), lnbType(lnb)
	{
	}

	/**
	 * @see base class
	 */
	virtual bool ClassToTree(TCTreeBranch& treeParent);

	/**
	 * @see base class
	 */
	virtual bool TreeToClass(TCTreeBranch& treeMine);

	bool operator == (TSSatelliteSettings const &compare) const;
	bool operator > (TSSatelliteSettings const &compare) const;
	bool operator < (TSSatelliteSettings const &compare) const;
};

#endif //_SATELLITESETTINGSDATATYPE_H_

