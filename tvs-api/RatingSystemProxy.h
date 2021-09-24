#ifndef _RATINGSYSTEMPROXY_H_
#define _RATINGSYSTEMPROXY_H_

#include <string>
#include <pthread.h>
#include <map>

#include "MarshallingHelperProxy.h"
#include "IRatingSystem.h"

class TCRatingSystemProxy : public IRatingSystem
{
public:

	/**
	 * @brief Sets Dbus connection for communication with TVS.
	 * @param [in] pTVSConnection TVService IPC connection.
	 */
	static void InitTVSConnection(TVServiceAPIConnection* pTVSConnection);

	/**
	 * @brief Returns an interface object.
	 * @param [in] regionIndex Index of region for Region Rating System.
	 * @return Pointer to interface implementation.
	 */
	static IRatingSystem* Instance( int regionIndex );

	/**
	 * @brief Destroys all interface instances.
	 */
	static void Destroy( void );

	int GetRRS( _OUT_ TCRegionRating& rrSystem );

	int GetRRSLock( _IN_ int dimension, _IN_ int ratingValue, _OUT_ bool& onOff );

	int SetRRSLock( _IN_ int dimension, _IN_ int ratingValue, _IN_ bool onOff );

private:
	TCRatingSystemProxy( int regionIndex );
	TCRatingSystemProxy( const TCRatingSystemProxy& ){};
	TCRatingSystemProxy& operator= ( const TCRatingSystemProxy& ) { return *this; };

	/**
	 * @brief Adds profile related data to proxy method call.
	 * @param [in] helper Proxy marshalling helper.
	 */
	void m_AddInterfaceProfiling( TCMarshallingHelperProxy& helper );

	static std::map<int, IRatingSystem*> m_instances;
	int m_regionIndex;

	static TVServiceAPIConnection* m_pTVSConnection;
	static std::string m_interfaceName;
	static pthread_rwlock_t m_rwlock; // lock for instance creation in multi-thread applications
};
#endif //_RATINGSYSTEMPROXY_H_
