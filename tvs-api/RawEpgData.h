#ifndef _RAWEPGDATA_H_
#define _RAWEPGDATA_H_

#include <cstddef>
#include "Marshalable.h"

/*!
\struct	TTRawEpgData
\brief	Structure used to hold the data from the MHP GetRawEpg Data.
\remarks NB: Memory for the buffer is allocated by the middleware but must be freed by the Java App.
*/
class TTRawEpgData : public TCMarshalable
{
private:
	enum
	{
		TAG_PUCBUFFER,
		TAG_DATASIZE,
	};

public:
	unsigned char* pucBuffer;
	int nDataSize;
	TTRawEpgData()
	{
		pucBuffer = NULL;
		nDataSize = 0;
	}

	~TTRawEpgData(void){ delete [] pucBuffer; pucBuffer = NULL; } // for debugging

	virtual bool ClassToTree(TCTreeBranch& treeParent);
	virtual bool TreeToClass(TCTreeBranch& treeMine);
};

typedef TTRawEpgData TCRawEpgData;

#endif // _RAWEPGDATA_H_
