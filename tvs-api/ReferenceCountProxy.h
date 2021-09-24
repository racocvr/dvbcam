#ifndef _REFERENCECOUNTPROXY_H_
#define _REFERENCECOUNTPROXY_H_

#include <string>
#include <pthread.h>
#include <map>
#include "TVServiceDataType.h"

#include "MarshallingHelperProxy.h"
#include "IReferenceCount.h"

class TCReferenceCountProxy : public IReferenceCount
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
	static IReferenceCount* Instance( TVSHandle tvsHandle );

	/**
	 * @brief Destroys all interface instances.
	 */
	static void Destroy( void );

	int IncreaseCount( void );

	int DecreaseCount( void );

	int ClearReferenceCount( void );

	// do not use this API directly
	int AddReferenceCount( void );
	// do not use this API directly
	int ReleaseReferenceCount( void );

	int GetReferenceCount( _OUT_ int& value );

	int AddReferenceCountReady( void );

	int ReleaseReferenceCountReady( void );

	int GetReferenceCountReady( _OUT_ int& value );

	int GetReferenceCountHelp( _OUT_ int& value );

private:
	TCReferenceCountProxy( TVSHandle tvsHandle );
	TCReferenceCountProxy( const TCReferenceCountProxy& ){};
	TCReferenceCountProxy& operator= ( const TCReferenceCountProxy& ) { return *this; };

	/**
	 * @brief Adds profile related data to proxy method call.
	 * @param [in] helper Proxy marshalling helper.
	 */
	void m_AddInterfaceProfiling( TCMarshallingHelperProxy& helper );

	static std::map<TVSHandle, IReferenceCount*> m_instances;
	TVSHandle m_tvsHandle;

	static TVServiceAPIConnection* m_pTVSConnection;
	static std::string m_interfaceName;
	static pthread_rwlock_t m_rwlock; // lock for instance creation in multi-thread applications

	std::string m_pName;
	long m_pid;
};
#endif //_REFERENCECOUNTPROXY_H_
