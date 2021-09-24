#ifndef _SOSPECAPPANALOGPROXY_H_
#define _SOSPECAPPANALOGPROXY_H_

#include <string>
#include <pthread.h>

#include "ISOSpecAppAnalog.h"

class TCSOSpecAppAnalogProxy : public ISOSpecAppAnalog
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
	static ISOSpecAppAnalog* Instance( void );

	/**
	 * @brief Destroys all interface instances.
	 */
	static void Destroy( void );

	bool t_Get( _IN_ ESOSpecAnalogTag tag, _OUT_ int& value );

private:
	TCSOSpecAppAnalogProxy( void );
	TCSOSpecAppAnalogProxy( const TCSOSpecAppAnalogProxy& ){};
	TCSOSpecAppAnalogProxy& operator= ( const TCSOSpecAppAnalogProxy& ) { return *this; };

	static ISOSpecAppAnalog* m_pInstance;

	static TVServiceAPIConnection* m_pTVSConnection;
	static std::string m_interfaceName;
	static pthread_rwlock_t m_rwlock; // lock for instance creation in multi-thread applications
};
#endif //_SOSPECAPPANALOGPROXY_H_
