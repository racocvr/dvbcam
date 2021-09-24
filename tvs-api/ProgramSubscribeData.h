#ifndef _PROGRAMSUBSCRIBEDATA_H_
#define _PROGRAMSUBSCRIBEDATA_H_

#include "Marshalable.h"
#include "ProgramData.h"

class TCProgramSubscribeData : public TCMarshalable
{
private:
	enum 
	{
		TAG_USERPARAM,
		TAG_HANDLE,
		TAG_PROGRAMDATA,
	};

public:
	TCProgramSubscribeData() : m_userParam(0){}
	TCProgramSubscribeData(const int& userParam, const TCProgramData& programData) : m_userParam(userParam), m_programData(programData){}
	virtual ~TCProgramSubscribeData(void){}

	/**
	* @brief Set program data.
	* @param programData program data
	*/
	void SetProgramData(const TCProgramData& programData){ m_programData = programData; }

	/**
	* @brief Set user parameters.
	* @param userParam user parameters
	*/
	void SetUserParam(const int& userParam){ m_userParam = userParam; }

	/**
	* @brief Set ID of a handle of subscription.
	* @param handle ID of a handle of subscription.
	*/
	void SetHandle(const int& handle){ m_handle = handle; }

	/**
	* @brief Get program data.
	* @return program data
	*/
	TCProgramData* GetProgramData(void) { return &m_programData; }

	/**
	* @brief Get user parameters.
	* @return user parameters
	*/
	int GetUserParam(void) { return m_userParam; }

	/**
	* @brief Get ID of a handle of subscription.
	* @return ID of a handle of subscription.
	*/
	int GetHandle(void) { return m_handle; }

private:
	int m_userParam;
	int m_handle;
	TCProgramData m_programData;

public:
	virtual bool ClassToTree(TCTreeBranch& treeParent);
	virtual bool TreeToClass(TCTreeBranch& treeMine);
};

#endif // _PROGRAMSUBSCRIBEDATA_H_
