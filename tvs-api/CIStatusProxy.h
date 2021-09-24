#ifndef _CISTATUSPROXY_H_
#define _CISTATUSPROXY_H_

#include <string>
#include <pthread.h>

#include "ICIStatus.h"

class TCCIStatusProxy : public ICIStatus
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
	static ICIStatus* Instance( void );

	/**
	 * @brief Destroys all interface instances.
	 */
	static void Destroy( void );

	int SetGeneralStatus( const _IN_ TSCIMStatusInfo& cimStatusInfo );

	int SetHostControlStatus( const _IN_ TSCIMStatusHostControl& cimHostControlStatus );

private:
	TCCIStatusProxy( void );
	TCCIStatusProxy( const TCCIStatusProxy& ){};
	TCCIStatusProxy& operator= ( const TCCIStatusProxy& ) { return *this; };

	static ICIStatus* m_pInstance;

	static TVServiceAPIConnection* m_pTVSConnection;
	static std::string m_interfaceName;
	static pthread_rwlock_t m_rwlock; // lock for instance creation in multi-thread applications
};
#endif //_CISTATUSPROXY_H_
