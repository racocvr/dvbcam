#ifndef _SATELLITESETTINGSPROXY_H_
#define _SATELLITESETTINGSPROXY_H_

#include <string>
#include <pthread.h>

#include "ISatelliteSettings.h"

class TCSatelliteSettingsProxy : public ISatelliteSettings
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
	static ISatelliteSettings* Instance( void );

	/**
	 * @brief Destroys all interface instances.
	 */
	static void Destroy( void );

	int GetSettings( _IN_ ESatelliteId satelliteId, _OUT_ TSSatelliteSettings& settings );

	int SetSettings( const _IN_ TSSatelliteSettings& settings );

	int SetSettings( const _IN_ std::vector< TSSatelliteSettings >& settings );

	int SetEnablePositioner( _IN_ bool enable );

	int CheckEnablePositioner( _OUT_ bool& enable );

	int SetDiSEqCVersion( _IN_ EDiSEqCVersion diseqc );

	int GetDiSEqCVersion( _OUT_ EDiSEqCVersion& diseqc );

	int ResetDiSEqCMode( const _IN_ TSTvMode& tvMode, _IN_ EScanNetwork network );

	int SetTvCoordinates( _IN_ double latitude, _IN_ double longitude );

	int GetTvCoordinates( _OUT_ double& latitude, _OUT_ double& longitude );

	int CalculateUSALS( _IN_ ESatelliteId satelliteId, _OUT_ int& usals );

	int SetEnableSatCR( _IN_ bool enable );

	int CheckEnableSatCR( _OUT_ bool& enable );

	int SetSatCRSlotNumber( _IN_ unsigned short tunerId, _IN_ unsigned char slotNumber );

	int SetSatCRSlotFrequency( _IN_ unsigned short tunerId, _IN_ int slotFrequency );

	int GetSatCRSettings( _IN_ unsigned short tunerId, _OUT_ TSSatCRSettings& satCRsettings );

	int Reset( _IN_ ESatSettingsResetType resetType, _IN_ ESatelliteId satelliteId );

	int SelectSatellites( _IN_ std::vector< ESatelliteId >& satellites );

	int CheckSatelliteSelected( const _IN_ TVSHandle& tvsHandle, _IN_ ESatelliteId satelliteId, _OUT_ bool& selected );

	int CheckSatelliteSelected( const _IN_ TVSHandle& tvsHandle, const _IN_ TSTvMode& tvMode, _IN_ ESatelliteId satelliteId, _OUT_ bool& selected );

	int GetSatCRDetectStatus( _OUT_ unsigned char& slotNumber, _OUT_ int& slotFrequency, _OUT_ unsigned char& progress , _IN_ int tunerId = 0);

private:
	TCSatelliteSettingsProxy( void );
	TCSatelliteSettingsProxy( const TCSatelliteSettingsProxy& ){};
	TCSatelliteSettingsProxy& operator= ( const TCSatelliteSettingsProxy& ) { return *this; };

	static ISatelliteSettings* m_pInstance;

	static TVServiceAPIConnection* m_pTVSConnection;
	static std::string m_interfaceName;
	static pthread_rwlock_t m_rwlock; // lock for instance creation in multi-thread applications
};
#endif //_SATELLITESETTINGSPROXY_H_
