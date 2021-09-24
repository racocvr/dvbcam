#ifndef _EITRAWDATAPROXY_H_
#define _EITRAWDATAPROXY_H_

#include <string>
#include <pthread.h>

#include "IEITRawData.h"

class TCEITRawDataProxy : public IEITRawData
{
public:

	/**
	 * @brief Sets Dbus connection for communication with TVS.
	 * @param [in] pTVSConnection TVService IPC connection.
	 */
	static void InitTVSConnection(TVServiceAPIConnection* pTVSConnection);

	/**
	 * @brief Returns an interface object.
	 * @return Pointer to interface implementation.
	 */
	static IEITRawData* Instance( void );

	/**
	 * @brief Destroys all interface instances.
	 */
	static void Destroy( void );

	int GetRawEpgDataUsingAlloc( _IN_ unsigned short in_tsid, _IN_ unsigned short in_onid, _IN_ unsigned short in_sid, _OUT_ TTRawEpgData& out_raw_epg_data );

	int GetRawEpgDataUsingAlloc( _IN_ unsigned short in_tsid, _IN_ unsigned short in_onid, _IN_ unsigned short in_sid, _IN_ unsigned short in_event_id, _OUT_ TTRawEpgData& out_raw_epg_data );

	int GetRawEpgDataUsingAlloc( _IN_ unsigned short in_tsid, unsigned short in_onid, _IN_ unsigned short in_sid, _IN_ unsigned long in_start_time, _IN_ unsigned long in_duration, _OUT_ TTRawEpgData& out_raw_epg_data );

	int GetRawEpgDataUsingAlloc( _IN_ int in_handle, _OUT_ TTRawEpgData& out_raw_epg_data );

private:
	TCEITRawDataProxy( void );
	TCEITRawDataProxy( const TCEITRawDataProxy& ){};
	TCEITRawDataProxy& operator= ( const TCEITRawDataProxy& ) { return *this; };

	static IEITRawData* m_pInstance;

	static TVServiceAPIConnection* m_pTVSConnection;
	static std::string m_interfaceName;
	static pthread_rwlock_t m_rwlock; // lock for instance creation in multi-thread applications
};
#endif //_EITRAWDATAPROXY_H_
