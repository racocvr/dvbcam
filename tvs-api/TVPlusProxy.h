#ifndef _TVPLUSPROXY_H_
#define _TVPLUSPROXY_H_

#include <string>
#include <pthread.h>

#include "ITVPlus.h"

class TCTVPlusProxy : public ITVPlus
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
	static ITVPlus* Instance( void );

	/**
	 * @brief Destroys all interface instances.
	 */
	static void Destroy( void );

	int SendTVPlusTuneSuccess( _IN_ int success_reason );

	int SendTVPlusTuneFail( _IN_ int fail_reason );

	int SendTVPlusTuneStart( _IN_ int start_reason );

private:
	TCTVPlusProxy( void );
	TCTVPlusProxy( const TCTVPlusProxy& ){};
	TCTVPlusProxy& operator= ( const TCTVPlusProxy& ) { return *this; };

	static ITVPlus* m_pInstance;

	static TVServiceAPIConnection* m_pTVSConnection;
	static std::string m_interfaceName;
	static pthread_rwlock_t m_rwlock; // lock for instance creation in multi-thread applications
};
#endif //_TVPLUSPROXY_H_
