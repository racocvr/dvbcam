#ifndef _SERVICENAVIGATIONPROXY_H_
#define _SERVICENAVIGATIONPROXY_H_

#include <string>
#include <pthread.h>
#include <map>
#include "TVServiceDataType.h"

#include "MarshallingHelperProxy.h"
#include "IServiceNavigation.h"

class TCServiceNavigationProxy : public IServiceNavigation
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
	static IServiceNavigation* Instance( TVSHandle tvsHandle );

	/**
	 * @brief Destroys all interface instances.
	 */
	static void Destroy( void );

	int SetService( _IN_ TCServiceId& serviceId, _IN_ EServiceChangeDirection changeDirection, _IN_ bool cacheOnly, const _IN_ std::string& appID );

	int GetQuietServiceInfo( const _IN_ TCCriteriaHelper& fetchCriteria, _OUT_ TCServiceData& service );

	int SetQuietService( const _IN_ TCServiceId& serviceId );

	int SetQuietServiceNonDestructive( const _IN_ TCServiceId& serviceId );

	int TuneAlone( const _IN_ TSScanChannel& tuneParams, const _IN_ std::string& appID );

	int TuneForFeedingSI( const _IN_ TSScanChannel& tuneParams, const _IN_ std::string& appID );

	int GetTvMode( _OUT_ TSTvMode& tvMode );

	int GetAvailableTvModes( _OUT_ std::vector< TSTvMode >& tvModes );

	int SetTvMode( _IN_ TSTvMode tvMode, const _IN_ std::string& appID );

	int SetTvModeInfo( _IN_ TSTvMode tvMode, _IN_ bool cacheOnly );

	int ResetCurrentTvModeInfo( void );

	int ResetCurrentServiceInfo( void );

	int ResetPreviousServiceInfo( void );

	int ResetServiceInfo( _IN_ TSTvMode tvMode );

	int SetCurrentServiceInfo( _IN_ TSTvMode tvMode, const _IN_ TCServiceId& service );

	int GetCurrentServiceInfo( _IN_ TSTvMode tvMode, const _IN_ TCCriteriaHelper& fetchCriteria, _OUT_ TCServiceData& service );

	int GetCurrentServiceInfo( const _IN_ TCCriteriaHelper& fetchCriteria, _OUT_ TCServiceData& service );

	int SetPreviousServiceInfo( _IN_ TSTvMode tvMode, const _IN_ TCServiceId& service );

	int GetPreviousServiceInfo( _IN_ TSTvMode tvMode, _OUT_ TCServiceId& service );

	int CheckService( const _IN_ TCServiceId& service );

	int SetServiceWithoutChangingServiceInfo( const _IN_ TCServiceId& service );

	int SetServiceWithoutChangingPreviousServiceInfo( const _IN_ TCServiceId& service );

	int GetNextService( const _IN_ TCCriteriaHelper& policy, const _IN_ TCServiceId& referenceServiceId, _OUT_ TCServiceData& service, _IN_ TSTvMode tvMode );

	int GetPreviousService( const _IN_ TCCriteriaHelper& policy, const _IN_ TCServiceId& referenceServiceId, _OUT_ TCServiceData& service, _IN_ TSTvMode tvMode );

	int GetOptimumService( const _IN_ TCCriteriaHelper& policy, _OUT_ TCServiceData& service, _IN_ TSTvMode tvMode );

	int SetNextService( const _IN_ TCCriteriaHelper& criteria );

	int SetNextService( const _IN_ TCCriteriaHelper& criteria, _OUT_ TCServiceData& outService );
	int SetPreviousService( const _IN_ TCCriteriaHelper& criteria );

	int SetPreviousService( const _IN_ TCCriteriaHelper& criteria, _OUT_ TCServiceData& outService );
	int SetOptimumService( const _IN_ TCCriteriaHelper& criteria );

	int SetOptimumService( const _IN_ TCCriteriaHelper& criteria, _OUT_ TCServiceData& outService );
	
	int GetServiceList( const _IN_ TCCriteriaHelper& criteria, _OUT_ std::list< TCServiceData* >& services, _IN_ TSTvMode tvMode, _IN_ EServiceListType serviceListType, _IN_ bool includeDefaultCurrent );

	int GetServiceCount( const _IN_ TCCriteriaHelper& criteria, _OUT_ int& count, _IN_ TSTvMode tvMode, _IN_ EServiceListType serviceListType );

	int GetStartService( _OUT_ TCServiceId& serviceId, _OUT_ ESource& source );

	int GetDefaultServiceInfo( _IN_ TSTvMode tvMode, _OUT_ TCServiceId& service );

	int SetServiceNonDestructive( const _IN_ TCServiceId& serviceId );

	int SetDTVMode(_IN_ EDTVModeType mode, _IN_ bool enable);
	
	int SetVideoPID( _IN_ unsigned short video_pid, _IN_ EVideoEncodeType vEncType, _IN_ unsigned short pcr_pid );
	
	int SetAudioPID( _IN_ unsigned short audio_pid, _IN_ EAudioEncodeType aEncType );

	int NonDestructiveTuneAllowed( const _IN_ TCServiceId& serviceId1, const _IN_ TCServiceId& serviceId2, _OUT_ bool& result );

	int StartSatelliteSetting( void );

	int StopSatelliteSetting( void );

	int GetDynamicSIState( _OUT_ bool& active );

	int SetDynamicSIState( _IN_ bool active );

	int TuneBarkerChannel( const _IN_ TCServiceId& serviceId );

	int GetLatestTvPlusService( const _IN_ TCCriteriaHelper& fetchCriteria, _OUT_ TCServiceData& service );

private:
	TCServiceNavigationProxy( TVSHandle tvsHandle );
	TCServiceNavigationProxy( const TCServiceNavigationProxy& ){};
	TCServiceNavigationProxy& operator= ( const TCServiceNavigationProxy& ) { return *this; };

	/**
	 * @brief Adds profile related data to proxy method call.
	 * @param [in] helper Proxy marshalling helper.
	 */
	void m_AddInterfaceProfiling( TCMarshallingHelperProxy& helper );

	static std::map<TVSHandle, IServiceNavigation*> m_instances;
	TVSHandle m_tvsHandle;

	static TVServiceAPIConnection* m_pTVSConnection;
	static std::string m_interfaceName;
	static pthread_rwlock_t m_rwlock; // lock for instance creation in multi-thread applications
};
#endif //_SERVICENAVIGATIONPROXY_H_
