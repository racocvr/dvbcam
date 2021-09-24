#ifndef _SATELLITEPROXY_H_
#define _SATELLITEPROXY_H_

#include <string>
#include <pthread.h>

#include "ISatellite.h"

class TCSatelliteProxy : public ISatellite
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
	static ISatellite* Instance( void );

	/**
	 * @brief Destroys all interface instances.
	 */
	static void Destroy( void );

	int FindSatelliteList( const _IN_ TCCriteriaHelper& criteria, _OUT_ std::vector< TSSatellite* >& satellites );

	int FindSatellite( const _IN_ TCCriteriaHelper& criteria, _OUT_ TSSatellite& satellite );

	int SetSatellitePosition( _IN_ ESatelliteId satelliteId, _IN_ ECardinalDirection direction, unsigned int position );

	int FindTransponderList( const _IN_ TCCriteriaHelper& criteria, _OUT_ std::vector< TSTransponder* >& transponders );

	int FindTransponder( const _IN_ TCCriteriaHelper& criteria, _OUT_ TSTransponder& transponder );

	int AddUserTransponder( const _IN_ TSTransponder& transponder, _OUT_ unsigned short& userTransponderId );

	int RemoveUserTransponder( _IN_ unsigned short userTransponderId );

	int Reset( _IN_ ESatDbResetType resetType );

	int CheckDbUpdated( _OUT_ bool& dbUpdated );

	int ConfirmDbUpdate( void );

private:
	TCSatelliteProxy( void );
	TCSatelliteProxy( const TCSatelliteProxy& ){};
	TCSatelliteProxy& operator= ( const TCSatelliteProxy& ) { return *this; };

	static ISatellite* m_pInstance;

	static TVServiceAPIConnection* m_pTVSConnection;
	static std::string m_interfaceName;
	static pthread_rwlock_t m_rwlock; // lock for instance creation in multi-thread applications
};
#endif //_SATELLITEPROXY_H_
