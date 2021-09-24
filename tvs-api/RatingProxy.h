#ifndef _RATINGPROXY_H_
#define _RATINGPROXY_H_

#include <string>
#include <pthread.h>
#include <map>
#include "TVServiceDataType.h"

#include "MarshallingHelperProxy.h"
#include "IRating.h"

class TCRatingProxy : public IRating
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
	static IRating* Instance( TVSHandle tvsHandle );

	/**
	 * @brief Destroys all interface instances.
	 */
	static void Destroy( void );

	int GetRatingInfo( _OUT_ std::vector< TSRatingInfo >& ratingInfo );

	int SetRatingData( _IN_ ERatingData ratingData, _IN_ unsigned int value );

	int GetRatingData( _IN_ ERatingData ratingData, _OUT_ unsigned int& value );

private:
	TCRatingProxy( TVSHandle tvsHandle );
	TCRatingProxy( const TCRatingProxy& ){};
	TCRatingProxy& operator= ( const TCRatingProxy& ) { return *this; };

	/**
	 * @brief Adds profile related data to proxy method call.
	 * @param [in] helper Proxy marshalling helper.
	 */
	void m_AddInterfaceProfiling( TCMarshallingHelperProxy& helper );

	static std::map<TVSHandle, IRating*> m_instances;
	TVSHandle m_tvsHandle;

	static TVServiceAPIConnection* m_pTVSConnection;
	static std::string m_interfaceName;
	static pthread_rwlock_t m_rwlock; // lock for instance creation in multi-thread applications
};
#endif //_RATINGPROXY_H_
