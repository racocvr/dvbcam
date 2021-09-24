#ifndef _SECTIONFEEDERPROXY_H_
#define _SECTIONFEEDERPROXY_H_

#include <string>
#include <pthread.h>
#include <map>
#include "TVServiceDataType.h"

#include "MarshallingHelperProxy.h"
#include "ISectionFeeder.h"

class TCSectionFeederProxy : public ISectionFeeder
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
	static ISectionFeeder* Instance( TVSHandle tvsHandle );

	/**
	 * @brief Destroys all interface instances.
	 */
	static void Destroy( void );

	int Start( _OUT_ TCServiceData& channel );

	int StartForCI( _INOUT_ TCServiceData& channel );

	int Stop( void );

	int FeedSection( const _IN_ TCSectionData& section );

private:
	TCSectionFeederProxy( TVSHandle tvsHandle );
	TCSectionFeederProxy( const TCSectionFeederProxy& ){};
	TCSectionFeederProxy& operator= ( const TCSectionFeederProxy& ) { return *this; };

	/**
	 * @brief Adds profile related data to proxy method call.
	 * @param [in] helper Proxy marshalling helper.
	 */
	void m_AddInterfaceProfiling( TCMarshallingHelperProxy& helper );

	static std::map<TVSHandle, ISectionFeeder*> m_instances;
	TVSHandle m_tvsHandle;

	static TVServiceAPIConnection* m_pTVSConnection;
	static std::string m_interfaceName;
	static pthread_rwlock_t m_rwlock; // lock for instance creation in multi-thread applications
};
#endif //_SECTIONFEEDERPROXY_H_
