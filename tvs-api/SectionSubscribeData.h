#ifndef _SECTIONSUBSCRIBEDATA_H_
#define _SECTIONSUBSCRIBEDATA_H_

#include "Marshalable.h"
#include <cstdio>


class TCSectionSubscribeData : public TCMarshalable
{
private:
	enum
	{
		TAG_SECTION,
		TAG_LENGTH,
		TAG_USERPARAM,
		TAG_HANDLE,
	};

public:
	TCSectionSubscribeData() : m_pSection(NULL), m_length(0) {}

	void SetSectionData(unsigned char* pSection){ m_pSection = pSection; }
	void SetLength(int length){ m_length = length; }
	void SetUserParam(int userParam){ m_userParam = userParam; }
	void SetHandle(int handle){ m_handle = handle; }

	unsigned char* GetSectionData(void){ return m_pSection; }
	int GetLength(void){ return m_length; }
	int GetUserParam(void){ return m_userParam; }
	int GetHandle(void){ return m_handle; }

	//TODO Duende using destructor causes core dump
	// this method removes only object on proxy side
	void Destroy() { delete [] m_pSection; }

private:
	unsigned char* m_pSection;
	int m_length;
	int m_userParam;
	int m_handle;

public:
	virtual bool ClassToTree(TCTreeBranch& treeParent);
	virtual bool TreeToClass(TCTreeBranch& treeMine);
};

#endif // _SECTIONSUBSCRIBEDATA_H_

