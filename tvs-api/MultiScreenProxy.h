#ifndef _MULTISCREENPROXY_H_
#define _MULTISCREENPROXY_H_

#include <string>
#include <pthread.h>

#include "IMultiScreen.h"

class TCMultiScreenProxy : public IMultiScreen
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
	static IMultiScreen* Instance( void );

	/**
	 * @brief Destroys all interface instances.
	 */
	static void Destroy( void );

	int GetScreenId( _IN_ int slot, _OUT_ int& screenId );

	int SetScreenId( _IN_ int slot, _IN_ int screenId );

	int StartMultiScreenMode( _IN_ EMultiScreenMode mode );

	int StopMultiScreenMode( _IN_ int slot );

private:
	TCMultiScreenProxy( void );
	TCMultiScreenProxy( const TCMultiScreenProxy& ){};
	TCMultiScreenProxy& operator= ( const TCMultiScreenProxy& ) { return *this; };

	static IMultiScreen* m_pInstance;

	static TVServiceAPIConnection* m_pTVSConnection;
	static std::string m_interfaceName;
	static pthread_rwlock_t m_rwlock; // lock for instance creation in multi-thread applications
};
#endif //_MULTISCREENPROXY_H_
