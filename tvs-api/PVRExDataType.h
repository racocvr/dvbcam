
#ifndef _PVREXDATATYPE_H_
#define _PVREXDATATYPE_H_

#include <vector>
#include "TVServiceDataType.h"
#include "Marshalable.h"
#include "TreeFormatter.h"

class TCTunerInfo: public TCMarshalable
{
	enum
	{
		TAG_INDEX,
		TAG_LINKED_PROFILE,
	};
public:
	int index;
	std::vector<TVSHandle> linkedProfile;

	/* Methods which implement marshaling */
	virtual bool ClassToTree(TCTreeBranch& treeParent);
	virtual bool TreeToClass(TCTreeBranch& treeMine);
protected:
	virtual void t_CreateTree(TCTreeFormatter& treeFormatter);
};


#endif /* _PVREXDATATYPE_H_ */
