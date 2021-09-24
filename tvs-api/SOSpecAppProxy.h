#ifndef _SOSPECAPPPROXY_H_
#define _SOSPECAPPPROXY_H_

#include <string>
#include <pthread.h>
#include <map>
#include "TVServiceDataType.h"

#include "MarshallingHelperProxy.h"
#include "ISOSpecApp.h"

class TCSOSpecAppProxy : public ISOSpecApp
{
public:

	/**
	 * @brief Sets Dbus connection for communication with TVS.
	 * @param [in] pTVSConnection TVService IPC connection.
	 */
	static void InitTVSConnection(TVServiceAPIConnection* pTVSConnection);

	/**
	 * @brief Returns an interface object.
	 * @param [in] tvsHandle Profile identifier.
	 * @return Pointer to interface implementation.
	 */
	static ISOSpecApp* Instance( TVSHandle tvsHandle );

	/**
	 * @brief Destroys all interface instances.
	 */
	static void Destroy( void );

	/**
	 * @see Base class
	 */
	bool t_Get( _IN_ ESOSpecTag tag, _OUT_ int& value );

	/**
	 * @see Base class
	 */
	bool t_Set( _IN_ ESOSpecTag tag, _IN_ int value );

	/**
	 * @see Base class
	 */
	int SetPrimarySpec( _IN_ ESpecCode specCode );

	/**
	 * @see Base class
	 */
	int UnsetPrimarySpec( void );

	/**
	 * @see Base class
	 */
	int GetCurrentDataServiceType( _OUT_ EDataServiceSupportType& dataType );

private:
	TCSOSpecAppProxy( TVSHandle tvsHandle );
	TCSOSpecAppProxy( const TCSOSpecAppProxy& ){};
	TCSOSpecAppProxy& operator= ( const TCSOSpecAppProxy& ) { return *this; };

	/**
	 * @brief Adds profile related data to proxy method call.
	 * @param [in] helper Proxy marshalling helper.
	 */
	void m_AddInterfaceProfiling( TCMarshallingHelperProxy& helper );

	static std::map<TVSHandle, ISOSpecApp*> m_instances;
	TVSHandle m_tvsHandle;

	static TVServiceAPIConnection* m_pTVSConnection;
	static std::string m_interfaceName;
	static pthread_rwlock_t m_rwlock; // lock for instance creation in multi-thread applications
};
#endif //_SOSPECAPPPROXY_H_
