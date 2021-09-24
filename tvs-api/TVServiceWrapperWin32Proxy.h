#ifndef _TVSERVICEWRAPPERWIN32PROXY_H_
#define _TVSERVICEWRAPPERWIN32PROXY_H_

#include <string>
#include <pthread.h>

#include "ITVServiceWrapperWin32.h"

class TCTVServiceWrapperWin32Proxy : public ITVServiceWrapperWin32
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
	static ITVServiceWrapperWin32* Instance( void );

	/**
	 * @brief Destroys all interface instances.
	 */
	static void Destroy( void );

	int Init( void );

	int Power( _IN_ int powerType, _IN_ int bootReason, _IN_ bool param );

	int GetPowerState( _OUT_ int& powerState, _OUT_ int& bootReason );

	int GetCountry( _IN_ bool digital, _OUT_ int& country );

	int SetCountry( _IN_ bool digital, _IN_ int country );

	int GetRegionKind( _OUT_ int& regionKind );

	int ConvertToTizenCountry( _IN_ int country );

	void SetAutoClock( _IN_ bool autoClock );

	bool FlagAutoClock( void );

	void StoreRating( _IN_ unsigned int rating );

private:
	TCTVServiceWrapperWin32Proxy( void );
	TCTVServiceWrapperWin32Proxy( const TCTVServiceWrapperWin32Proxy& ){};
	TCTVServiceWrapperWin32Proxy& operator= ( const TCTVServiceWrapperWin32Proxy& ) { return *this; };

	static ITVServiceWrapperWin32* m_pInstance;

	static TVServiceAPIConnection* m_pTVSConnection;
	static std::string m_interfaceName;
	static pthread_rwlock_t m_rwlock; // lock for instance creation in multi-thread applications
};
#endif //_TVSERVICEWRAPPERWIN32PROXY_H_
