#ifndef _EWBSPROXY_H_
#define _EWBSPROXY_H_

#include <string>
#include <pthread.h>

#include "IEWBS.h"

class TCEWBSProxy : public IEWBS
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
	static IEWBS* Instance( void );

	/**
	 * @brief Destroys all interface instances.
	 */
	static void Destroy( void );

	int GetEWBSData( _OUT_ unsigned char& packageId, _OUT_ EDisasterStatus& disasterStatus, _OUT_ EDisasterCode& disasterCode, _OUT_ unsigned int& areaCode, _OUT_ std::string& areaDescription );

private:
	TCEWBSProxy( void );
	TCEWBSProxy( const TCEWBSProxy& ){};
	TCEWBSProxy& operator= ( const TCEWBSProxy& ) { return *this; };

	static IEWBS* m_pInstance;

	static TVServiceAPIConnection* m_pTVSConnection;
	static std::string m_interfaceName;
	static pthread_rwlock_t m_rwlock; // lock for instance creation in multi-thread applications
};
#endif //_EWBSPROXY_H_
