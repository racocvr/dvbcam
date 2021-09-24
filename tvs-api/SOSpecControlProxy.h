#ifndef _SOSPECCONTROLPROXY_H_
#define _SOSPECCONTROLPROXY_H_

#include <string>
#include <pthread.h>

#include "ISOSpecControl.h"

class TCSOSpecControlProxy : public ISOSpecControl
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
	static ISOSpecControl* Instance( void );

	/**
	 * @brief Destroys all interface instances.
	 */
	static void Destroy( void );

	int ChangeDigitalSOSpec( _IN_ ECountry country );

	int ChangeDigitalSOSpec( const _IN_ TSTvMode& tvMode, _IN_ EBroadCaster broadcaster );

	int ChangeDigitalSOSpec( _IN_ int country );

	int ChangeAnalogSOSpec( _IN_ ECountry country );

	int ChangeAnalogSOSpec( _IN_ int country );

	int GetBroadcaster( const _IN_ TSTvMode& tvMode, _OUT_ EBroadCaster& broadcaster ) const;

	int GetDefaultBroadcaster( const _IN_ TSTvMode& tvMode, _OUT_ EBroadCaster& broadcaster ) const;

	int CheckBroadcasterSupported( _IN_ EBroadCaster broadcaster, _OUT_ bool& supported, int country = INVALID ) const;

private:
	TCSOSpecControlProxy( void );
	TCSOSpecControlProxy( const TCSOSpecControlProxy& ){};
	TCSOSpecControlProxy& operator= ( const TCSOSpecControlProxy& ) { return *this; };

	static ISOSpecControl* m_pInstance;

	static TVServiceAPIConnection* m_pTVSConnection;
	static std::string m_interfaceName;
	static pthread_rwlock_t m_rwlock; // lock for instance creation in multi-thread applications
};
#endif //_SOSPECCONTROLPROXY_H_
