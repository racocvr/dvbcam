#ifndef _SCANDATAPROXY_H_
#define _SCANDATAPROXY_H_

#include <string>
#include <pthread.h>

#include "IScanData.h"

class TCScanDataProxy : public IScanData
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
	static IScanData* Instance( void );

	/**
	 * @brief Destroys all interface instances.
	 */
	static void Destroy( void );

	int GetScanInfo( _IN_ EScanMode mode, _OUT_ TSScanInfo& info, _IN_ ECloudScan cloudScan );

	int GetScanOption( _INOUT_ TCScanOption& option, _IN_ TSScanOptionCriteria scanOptionCriteria );

	int SetScanOption( const _IN_ TCScanOption& option, _IN_ TSScanOptionCriteria scanOptionCriteria );

	int StoreScanOption( _IN_ EScanOption option, _IN_ EStoreMode mode, _IN_ TSScanOptionCriteria scanOptionCriteria );

	int SetHomingChannel( const _IN_ TSTvMode& tvMode, const _IN_ TSHomingChannelLocator& homingChannel );

	int GetHomingChannel( const _IN_ TSTvMode& tvMode, const _IN_ EBroadCaster& broadCasterId, _OUT_ TSHomingChannelLocator& homingChannel );

	int GetHomingChannelCandidates( const _IN_ TSTvMode& tvMode, _OUT_ std::vector< TSHomingChannelLocator >& homingChannelCandidates );

	int ResetHomingChannel( void );

	int SetPreferredTargetRegion( _IN_ unsigned int regionId );

	int GetPreferredTargetRegion( _IN_ unsigned char depth, _OUT_ unsigned int& regionId );

	int SetCamOperatorProfileScanActive( _IN_ bool active );

	int SetAppScanActive( _IN_ bool active );

	int CheckServiceListsRegistered( _OUT_ bool& flag );

	int GetNetworks( _OUT_ std::map< unsigned short, t_wstring >& networks );

	int SetPreferredNetwork( _IN_ unsigned short preferNetworkId, _IN_ TSTvMode tvMode);

	int DeleteNetworks( void );

	int GetServiceLists( _OUT_ std::map< unsigned short, t_wstring >& serviceLists, _OUT_ unsigned short& defaultServiceListId, _IN_ ELanguageCode menuLanguage, _IN_ int country );

	int GetRegionalServiceLists( _OUT_ std::map< unsigned short, t_wstring >& serviceLists );

	int SetServiceList( _IN_ unsigned short serviceListId );

	int SetRegionalServiceList( _IN_ unsigned short serviceListId );

	int GetServicesForReplacement( _OUT_ std::multimap< TCServiceId, std::list< TCServiceId > > &services );

	int CheckServicesForReplacement( _OUT_ bool& flag );

	int CheckScanActive( _OUT_ bool& flag );

	int CheckManualScanPerformed( _IN_ TSTvMode tvMode, _OUT_ bool& flag );

	int GetTargetSubRegions( _IN_ unsigned int parentRegion, _OUT_ std::map< unsigned int, t_wstring >& subRegions );

	int GetInteractiveStorageAllocations( _INOUT_ std::map< unsigned short, unsigned int >& groupAlloc, _INOUT_ std::map< unsigned short, unsigned int >& serviceAlloc );

	int SetPostCode( const _IN_ std::string& postCode );

	int GetPostCode( _OUT_ std::string& postCode );

	int VerifyPostCode( const _IN_ std::string& postCode );

	int CheckMissingTranspondersFound( _OUT_ bool& found );

	int GetColorSystem(_OUT_ EChannelColorSystem& mode, _OUT_ EChannelColor& value);

	int SetColorSystem(_IN_ EChannelColorSystem mode, _IN_ EChannelColor value);

	int GetSoundSystem(_OUT_ EChannelSoundSystem& mode, _OUT_ EChannelSound& value);

	int SetSoundSystem(_IN_ EChannelSoundSystem mode, _IN_ EChannelSound value);

private:
	TCScanDataProxy( void );
	TCScanDataProxy( const TCScanDataProxy& ){};
	TCScanDataProxy& operator= ( const TCScanDataProxy& ) { return *this; };

	static IScanData* m_pInstance;

	static TVServiceAPIConnection* m_pTVSConnection;
	static std::string m_interfaceName;
	static pthread_rwlock_t m_rwlock; // lock for instance creation in multi-thread applications
};
#endif //_SCANDATAPROXY_H_
