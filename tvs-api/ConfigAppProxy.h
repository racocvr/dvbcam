#ifndef _CONFIGAPPPROXY_H_
#define _CONFIGAPPPROXY_H_

#include <string>
#include <pthread.h>

#include "IConfigApp.h"

class TCConfigAppProxy : public IConfigApp
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
	static IConfigApp* Instance( void );

	/**
	 * @brief Destroys all interface instances.
	 */
	static void Destroy( void );

	bool t_Get( _IN_ EConfigAppTag tag, _OUT_ int& value );

private:
	TCConfigAppProxy( void );
	TCConfigAppProxy( const TCConfigAppProxy& ){};
	TCConfigAppProxy& operator= ( const TCConfigAppProxy& ) { return *this; };

	static IConfigApp* m_pInstance;

	static TVServiceAPIConnection* m_pTVSConnection;
	static std::string m_interfaceName;
	static pthread_rwlock_t m_rwlock; // lock for instance creation in multi-thread applications
};
#endif //_CONFIGAPPPROXY_H_
