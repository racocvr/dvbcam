#ifndef _SATELLITECONTROLPROXY_H_
#define _SATELLITECONTROLPROXY_H_

#include <string>
#include <pthread.h>

#include "ISatelliteControl.h"

class TCSatelliteControlProxy : public ISatelliteControl
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
	static ISatelliteControl* Instance( void );

	/**
	 * @brief Destroys all interface instances.
	 */
	static void Destroy( void );

	int SendPositionerCommand( _IN_ EPositionerCommand command, _IN_ int param );

	int SendSatCRCommand( _IN_ unsigned short tunerId, _IN_ ESatCRCommand satCRCmd, const _IN_ TSSatCRSettings& satCRSettings );

	int GetLnbPower( _OUT_ bool& enable );

	int SetLnbPower( _IN_ bool enable );

private:
	TCSatelliteControlProxy( void );
	TCSatelliteControlProxy( const TCSatelliteControlProxy& ){};
	TCSatelliteControlProxy& operator= ( const TCSatelliteControlProxy& ) { return *this; };

	static ISatelliteControl* m_pInstance;

	static TVServiceAPIConnection* m_pTVSConnection;
	static std::string m_interfaceName;
	static pthread_rwlock_t m_rwlock; // lock for instance creation in multi-thread applications
};
#endif //_SATELLITECONTROLPROXY_H_
