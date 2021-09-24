#ifndef _MULTIVIEWPROXY_H_
#define _MULTIVIEWPROXY_H_

#include <string>
#include <pthread.h>

#include "IMultiView.h"

class TCMultiViewProxy : public IMultiView
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
	static IMultiView* Instance( void );

	/**
	 * @brief Destroys all interface instances.
	 */
	static void Destroy( void );

	int StartSubView( _IN_ EProfile profile, _IN_ ESource source, const _IN_ TCServiceData& serviceData );

	int StopSubView( _IN_ EProfile profile );

private:
	TCMultiViewProxy( void );
	TCMultiViewProxy( const TCMultiViewProxy& ){};
	TCMultiViewProxy& operator= ( const TCMultiViewProxy& ) { return *this; };

	static IMultiView* m_pInstance;

	static TVServiceAPIConnection* m_pTVSConnection;
	static std::string m_interfaceName;
	static pthread_rwlock_t m_rwlock; // lock for instance creation in multi-thread applications
};
#endif //_MULTIVIEWPROXY_H_
