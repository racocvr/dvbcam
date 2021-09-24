/** 
 * @file SatelliteDataType.h
 * @brief Definitions related to satellite and transponder data.
 *
 * Copyright 2013 by Samsung Electronics, Inc.,
 * 
 * This software is the confidential and proprietary information
 * of Samsung Electronics, Inc. ("Confidential Information"). You
 * shall not disclose such Confidential Information and shall use
 * it only in accordance with the terms of the license agreement
 * you entered into with Samsung.
 */


#ifndef _SATELLITEDATATYPE_H_
#define _SATELLITEDATATYPE_H_

#include "Marshalable.h"
#include "TreeToClassFormatter.h"
#include "ClassToTreeFormatter.h"
#include "MarshallingHelper.h"

#include "TVServiceDataType.h"
#include "ServiceDataType.h"
#include <string>

// Satellite signal has wide bandwidth.
// If two transponders have close frequencies - they won't be distinguish by tuner.
// 10MHz difference was experimentally found as safe frequency distance between two close transponders.
enum 
{
	MIN_TP_FREQUENCY_DIFF = 10000 // [kHz]
};


typedef enum 
{
	TAG_SATELLITE_NAME = 72,				// [t_wchar_t*] satellite's name
	TAG_SATELLITE_DIRECTION = 73,			// [ECardinalDirection] satellite's cardinal direction - east/west
	TAG_SATELLITE_POSITION = 74,			// [unsigned int] satellite's position [in 1/10 of degree or 6 angular minutes]
	TAG_TRANSPONDER_FREQUENCY = 76,			// [int] transponder's frequency [kHz]
	TAG_TRANSPONDER_POLARISATION = 77,		// [EDVBSPolarisation] transponder's polarisation
	TAG_TRANSPONDER_FEC = 78,				// [EDVBFECInner] transponder's forward error correction
	TAG_TRANSPONDER_SYMBOL_RATE = 79,		// [unsigned short] transponder's symbol rate [kSym/s]
	TAG_HOME_TRANSPONDER_PACKAGE_ID = 81,	// [ESatellitePackageId] Id of package for which the transponder is home transponder (one package can have many home transponders)
	TAG_HOME_TRANSPONDER_PRIORITY = 82,		// [unsigned short] Priority of home transponder within given package (meaningfull if more than one home transponder is assigned to the package)
	TAG_HOME_SATELLITE_PACKAGE_ID = 84,		// [ESatellitePackageId] Id of package satellite belongs to (one package can have many satellites)
} ESatelliteDataTag;


typedef enum 
{
	DIR_UNKNOWN = -1,
	DIR_WEST = 0,
	DIR_EAST = 1,
} ECardinalDirection;


typedef enum
{
	SATDB_RESET_ALL,		// Recreate DB from SEI file
	SATDB_RESET_USER,		// Remove user transponders, reset user satellites
} ESatDbResetType;

typedef enum
{
	PKG_UNKNOWN = 0x0000,
	PKG_FREESAT = 0x0001,
	PKG_SKYUK = 0x0002,
	PKG_PREMIERE = 0x0003,
	PKG_NORDICCANALDIGITAL = 0x0004,
	PKG_TIVU = 0x0005,
	PKG_ASTRA_HD_PLUS = 0x0006,
	PKG_CANALDIGITAAL_NETHERLANDS = 0x0007,

	PKG_DIGITAL_PLUS = 0x0009,
	PKG_CYFRA_PLUS = 0x000a,
	PKG_DIGITURK = 0x00b,
	PKG_DSMART = 0x000c,
	PKG_FRANSAT = 0x000d,
	PKG_SKYD = 0x000e,
	PKG_NNK =0x000f,
	PKG_ORF =0x0010,
	PKG_ASTRA_INTERNATIONAL_LCN = 0x0011,
	PKG_SKYLINK = 0x0012,
	PKG_FREEVIEWNZ_SAT = 0x0013,
	PKG_AIRTEL = 0x0014,
	PKG_HD_AUSTRIA = 0x0015,
	PKG_OTAU = 0x0016,
	PKG_MAGYARORSZAG = 0x0017,
	PKG_POLSAT = 0x0018,
	PKG_TRICOLOR = 0x0019,
	PKG_TELEKARTA = 0x001a,
	PKG_NTV_PLUS = 0x001b,
	PKG_SUNDIRECT = 0x001c,

	PKG_MAX,
} ESatellitePackageId;

typedef enum
{
	SATID_UNKNOWN = -1,

	SATID_ASTRA_19_2E = 0x1,
	SATID_ASTRA_28_2E = 0x2,
	SATID_ASTRA_23_5E = 0x3,
	SATID_ASTRA_4_8E = 0x4,
	SATID_HOTBIRD_13E = 0x5,
	SATID_EUTELSAT_28_5E = 0x6, //Currently is not exist
	SATID_EUTELSAT_25_5E = 0x7,
	SATID_EUTELSAT_33E = 0x8,
	SATID_EUROBIRD_4E = 0x9,
	SATID_EUTELSAT_9E = 0xa,
	SATID_EUTELSAT_10E = 0xb,
	SATID_EUTELSAT_16E = 0xc,
	SATID_EUTELSAT_7E = 0xd,
	SATID_EUTELSAT_36E = 0xe,
	SATID_EUTELSAT_70_5E = 0xf,
	SATID_EUTELSAT_21_5E = 0x10,
	SATID_SESAT_53E = 0x12,
	SATID_TURKSAT_42E = 0x13,
	SATID_HISPASAT_30W = 0x15,
	SATID_BADR_26E = 0x17,
	SATID_ARABSAT_30_5E = 0x18,
	SATID_TURKSAT_31_3E = 0x19,
	SATID_ASTRA_31_5E = 0x1a,
	SATID_PAKSAT_38E = 0x1b,
	SATID_HELLAS_39E = 0x1c,
	SATID_EXPRESSAM1_40E = 0x1d,
	SATID_INTELSAT_45E = 0x1e,
	SATID_BONUM1_56E = 0x1f,
	SATID_THOR_INTELSAT_0_8W = 0x20,
	SATID_AMOS_4W = 0x21,
	SATID_EUTELSAT5_WESTA = 0x22,
	SATID_EUTELSAT7_WESTA = 0x23,
	SATID_EUTELSAT8_WESTA = 0x24,
	SATID_EUTELSAT12_WESTA = 0x25,
	SATID_EXPRESSA4_14W = 0x26,
	SATID_TELSTAR12_15W = 0x27,
	SATID_INTELSAT901_18W = 0x28,
	SATID_NSS7_22W = 0x29,
	SATID_INTELSAT905_24_5W = 0x2a,
	SATID_INTELSAT907_27_5W = 0x2b,
	SATID_INTELSAT801_31_5W = 0x2c,
	SATID_INTELSAT903_34_5W = 0x2d,
	SATID_TELSTAR_11N_37_5W = 0x2e,
	SATID_NSS806_40_5W = 0x2f,
	SATID_INTELSAT3R_43W = 0x30,
	SATID_INTELSAT1R_45W = 0x31,
	SATID_INTELSAT705_50W = 0x32,
	SATID_INTELSAT707_53W = 0x33,
	SATID_INTELSAT805_55_5W = 0x34,
	SATID_INTELSAT9_58W = 0x35,
	SATID_AMAZONAS_61W = 0x36,
	SATID_NSS12_57E = 0x37,
	SATID_INTELSAT7_10_68_5E = 0x38,
	SATID_YAMAL201_90E = 0x39,
	SATID_EUTELSAT_3E = 0x3a,
	SATID_EUTELSAT_70E = 0x3b,
	SATID_OPTUS_D1_160E = 0x3c,
	SATID_SES_7_108_2E = 0x3d,
	SATID_INSAT_4B_93_3E = 0x3e,
	SATID_INTELSAT_904_60E = 0x3f,
	SATID_NILESAT_102_7W = 0x40,
	SATID_NILESAT_201_7W = 0x41,
	SATID_ABS_2_75E = 0x42,
	SATID_INTELSAT15_85_2E = 0x43,
	SATID_EXPRESS_AM5_140E = 0x44,
	SATID_AZERSPACE_1_AFRICASAT_1A = 0x45,
	SATID_ARABSAT_5C_20E = 0x46,
	SATID_MEASAT_3B_91_5E = 0x47,	
	SATID_YAHSAT_1A = 0x48,
	SATID_EXPRESS_AM44 = 0x49,
	SATID_THAICOM = 0x4a,
	SATID_ST_2 = 0x4b,
	SATID_ASIASAT_7 = 0x4c,
	SATID_INTELSAT_902 = 0x4d,
	SATID_EUTELSAT_8_WEST_C = 0x4e,
	SATID_ASIASAT_5 = 0x4f,
	SATID_INTELSAT_10 = 0x50,
	SATID_APSTAR = 0x51,
	SATID_AFGHANSAT_1 = 0x52,
	SATID_YAMAL_202 = 0x53,
	SATID_ABS_7 = 0x54,
	SATID_SES_5 = 0x55,
	
	SATID_EUROBIRD_28_5E = SATID_EUTELSAT_28_5E,
	SATID_EUROBIRD_25_5E = SATID_EUTELSAT_25_5E,
	SATID_EUROBIRD_33E = SATID_EUTELSAT_33E,
	SATID_EUROBIRD_9E = SATID_EUTELSAT_9E ,
	SATID_EUTELSATW1_10E = SATID_EUTELSAT_10E,
	SATID_EUTELSATW2_16E = SATID_EUTELSAT_16E,
	SATID_EUTELSATW3A_7E = SATID_EUTELSAT_7E,
	SATID_EUTELSATW4_W7_36E = SATID_EUTELSAT_36E,
	SATID_EUTELSATW5_70_5E= SATID_EUTELSAT_70_5E,
	SATID_EUTELSATW6_21_5E= SATID_EUTELSAT_21_5E,
	SATID_ATLANTICBIRD_5W= SATID_EUTELSAT5_WESTA,
	SATID_NILESAT_7W = SATID_EUTELSAT7_WESTA, // todo: check if still needed while SATID_NILESAT_201_7W is added
	SATID_ATLANTICBIRD2_8W= SATID_EUTELSAT8_WESTA,
	SATID_ATLANTICBIRD1_12_5W = SATID_EUTELSAT12_WESTA,
	SATID_EXPRESS_AM22 = SATID_SESAT_53E,
	SATID_EXPRESS_AT1_56E = SATID_BONUM1_56E,

	// user defined satellites
	SATID_USER1 = 0xFFE1,
	SATID_USER2 = 0xFFE2,
	SATID_USER3 = 0xFFE3,
	SATID_USER4 = 0xFFE4,
}ESatelliteId;


struct TSSatellite : public TCMarshalable
{
	ESatelliteId satelliteId; // Id of satellite.
	t_wstring satelliteName; // Name of satellite.
	ECardinalDirection cardinalDir; // Satellite's cardinal direction (east/west).
	unsigned int position;  // Satellite's position [in 1/10 of degree or 6 angular minutes].

	TSSatellite( ESatelliteId satId = SATID_UNKNOWN, t_wstring satName = t_wstring(), ECardinalDirection cardDir = DIR_UNKNOWN, unsigned int pos = INVALID );

	TSSatellite( const TSSatellite& that);
	TSSatellite& operator=(const TSSatellite& rValue);

public:
	virtual bool ClassToTree(TCTreeBranch& treeParent);
	virtual bool TreeToClass(TCTreeBranch& treeMine);
	
private:
	enum 
	{
		TAG_ID,
		TAG_SATELLITE_NAME,
		TAG_CARDINAL_DIR,
		TAG_POSITION,
	};
} ;

struct TSTransponder : public TCMarshalable
{
	unsigned short transponderId; // Id of transponder.
	ESatelliteId satelliteId; // Id of parent satellite.
	int frequency; // Transponder's frequency [kHz].
	unsigned short symbolRate; // Transponder's symbol rate [kS/s]
	EDVBSPolarisation polarisation; // Transponder's polarisation (horizontal/vertical).
	EDVBFECInner fec; // Transponder's forward error correction.

	/* TODO Duende
	int hasOAD;		//  flag if transponder has OAD
	int PID;			// PID containing the upgrade
	ESigAlgId eSigAlgId;	// Upgrade signalling alghoritm Id
	EDataFormat eDataFormat;	// Id of carousel format
	*/

	TSTransponder( unsigned short tpId = INVALID, ESatelliteId satId = SATID_UNKNOWN,
		int freq = INVALID, unsigned short sr = INVALID, EDVBSPolarisation pol = DVBS_POL_UNKNOWN, EDVBFECInner fecInner = DVB_FEC_INNER_UNDEFINED );
	bool operator==( const TSTransponder& other ) const;
	bool operator!=( const TSTransponder& other ) const;
	bool operator<( const TSTransponder& other ) const;


public:
	virtual bool ClassToTree(TCTreeBranch& treeParent);
	virtual bool TreeToClass(TCTreeBranch& treeMine);

private:
	enum 
	{
		TAG_TP_ID,
		TAG_SAT_ID,
		TAG_FREQ,
		TAG_SR,
		TAG_POL,
		TAG_FEC,
	};
};

#endif // _SATELLITEDATATYPE_H_
