#ifndef _REGIONRATING_H_
#define _REGIONRATING_H_

#include "Marshalable.h"

class TCRRSDimension;
class TCRRSRatingValue;

class TCRegionRating : public TCMarshalable
{
private:
	enum
	{
		TAG_REGION,
		TAG_VERSIONNUMBER,
		TAG_CRC32,
		TAG_RATINGREGIONNAME,
		TAG_RATINGREGIONNAMELENGTH,
		TAG_DIMENSIONDEFINED,
		TAG_DIMENSIONLIST,
	};

protected:
	unsigned char m_region;
	unsigned char m_versionNumber;
	unsigned long m_CRC32;

	unsigned char* m_pRatingRegionName;
	int m_ratingRegionNameLength;

	unsigned char m_dimensionDefined;

	std::vector<TCRRSDimension*> m_dimensionList ;

public:
	TCRegionRating();
	virtual ~TCRegionRating();

	unsigned char GetRegion(void){ return m_region; }

	unsigned char GetVersionNumber(void){ return m_versionNumber; }

	unsigned long GetCRC(void){ return m_CRC32;}

	unsigned char GetDimensionDefined(void){ return m_dimensionDefined; }

	bool GetRatingRegionName(unsigned char* name, int* size);

	TCRRSDimension* RRSDimension( unsigned int index );

	bool GetGraduatedScale(int dimension, unsigned char* flag);
	bool GetValueDefined(int dimension, unsigned char* valueDefined);
	bool GetDimensionName(int dimension, unsigned char* name, int* size);

	bool GetLockFlag(int dimension, int ratingValue, bool& lockFlag);

	bool GetAbbrevRatingValueName(int dimension, int ratingValue, unsigned char* name, int* size);
	bool GetRatingValueName(int dimension, int ratingValue, unsigned char* name, int* size);

	TCRegionRating& operator=(const TCRegionRating& regionRating);

	bool ClassToTree(TCTreeBranch& treeParent);
	bool TreeToClass(TCTreeBranch& treeMine);

protected:
	void m_DeleteAll(void);
};

class TCRRSDimension : public TCMarshalable
{
private:
	enum
	{
		TAG_GRADUATEDSCALE,
		TAG_VALUEDEFINED,
		TAG_DIMENSIONNAME,
		TAG_DIMENSIONNAMELENGTH,
		TAG_RATINGVALUELIST,
	};

protected:
	unsigned char m_graduatedScale;
	unsigned int m_valueDefined;

	unsigned char* m_pDimensionName;
	int m_dimensionNameLength;

	std::vector<TCRRSRatingValue*> m_ratingValueList;

public:
	TCRRSDimension();
	virtual ~TCRRSDimension();

	unsigned char GetGraduatedScale(void){ return m_graduatedScale; }

	unsigned char GetValueDefined(void){ return m_valueDefined; }

	bool GetDimensionName(unsigned char* name, int* size);

	TCRRSRatingValue* RRSRatingValue( unsigned int index );
	
	TCRRSDimension& operator=(const TCRRSDimension& dim);

	bool ClassToTree(TCTreeBranch& treeParent);
	bool TreeToClass(TCTreeBranch& treeMine);

protected:
	void m_DeleteAll(void);
};

class TCRRSRatingValue : public TCMarshalable
{
private:
	enum
	{
		TAG_LOCK,
		TAG_ABBREVRATINGVALUENAME,
		TAG_ABBREVRATINGVALUENAMELENGTH,
		TAG_RATINGVALUENAME,
		TAG_RATINGVALUENAMELENGTH,
	};

protected:
	unsigned char m_lock; // 0:off, 1: on

	unsigned char* m_abbrevRatingValueName;
	int m_abbrevRatingValueNameLength;

	unsigned char* m_ratingValueName;
	int m_ratingValueNameLength;

public:
	TCRRSRatingValue();
	virtual ~TCRRSRatingValue();
	
	unsigned char GetLockFlag(void){ return m_lock; }

	bool GetAbbrevRatingValueName(unsigned char* name, int* size);

	bool GetRatingValueName(unsigned char* name, int* size);

	TCRRSRatingValue& operator=(const TCRRSRatingValue& ratingValue);

	bool ClassToTree(TCTreeBranch& treeParent);
	bool TreeToClass(TCTreeBranch& treeMine);

protected:
	void m_DeleteAll(void);
};

#endif // _REGIONRATING_H_
