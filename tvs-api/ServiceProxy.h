#ifndef _SERVICEPROXY_H_
#define _SERVICEPROXY_H_

#include <string>
#include <pthread.h>

#include "IService.h"

class TCServiceProxy : public IService
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
	static IService* Instance( void );

	/**
	 * @brief Destroys all interface instances.
	 */
	static void Destroy( void );

	int FindServiceList( const _IN_ TCCriteriaHelper& criteria, _OUT_ std::list< TCServiceData* >& services );

	int FindService( const _IN_ TCCriteriaHelper& criteria, _OUT_ TCServiceData& service, const _IN_ bool onlyStored );

	int GetServiceCount( const _IN_ TCCriteriaHelper& criteria, _OUT_ int& count );

	int UpdateService( const _IN_ TCServiceData& service );

	int UpdateServiceList( const _IN_ std::list< TCServiceData* >& services );

	int InsertServiceList( _IN_ std::list< TCServiceData* >& services );

	int GetFavorites( const _IN_ TCServiceId& serviceId, _OUT_ std::map< unsigned char, bool >& favorites );

	int UpdateFavorites( const _IN_ std::vector< std::pair< TCServiceId, bool > >& services, _IN_ unsigned char fav );

	int MoveFavorites( const _IN_ std::vector< TCServiceId >& services, _IN_ unsigned short targetPos, _IN_ unsigned char fav );

	int CopyServiceList( _IN_ std::map< TCServiceId, unsigned short >& services );

	int ReorderServiceList( const _IN_ TSTvMode& tvMode );

	int DeleteServiceList( const _IN_ TCCriteriaHelper& criteria, _IN_ bool forceDelete );

	int GetProviderList( const _IN_ TCCriteriaHelper& criteria, _OUT_ std::vector< TSServiceProvider* >& providers );

	int GetBouquets( const _IN_ TSTvMode& tvmode, _OUT_ std::map< unsigned long long, t_wstring >& bouquets );

	int GetBouquetCount( const _IN_ TSTvMode& tvmode, _OUT_ unsigned int& count );

	int GetBouquetName( const _IN_ unsigned long long& bouquetId, _OUT_ t_wstring& bouquetName );

	int GetServiceBouquets( const _IN_ TCServiceId& serviceId, _OUT_ std::vector< unsigned long long >& bouquetsIds );

	int SetBank( const _IN_ TCServiceId& serviceId, _IN_ EHotelBank bank );

	int RemoveBank( const _IN_ TCServiceId& serviceId, _IN_ EHotelBank bank );

	int GetBanks( const _IN_ TSTvMode& tvMode, _OUT_ std::map< TCServiceId, std::vector< EHotelBank > >& serviceBanksIds );

	int SetCountries( const _IN_ TCServiceId& serviceId, const _IN_ std::vector< EHotelCountry >& countries );

	int GetCountries( const _IN_ TCServiceId& serviceId, _OUT_ std::vector< EHotelCountry >& countries );

	int SetHotelGenre( const _IN_ TCServiceId& serviceId, _IN_ EHotelGenre genre );

	int RemoveHotelGenre( const _IN_ TCServiceId& serviceId, _IN_ EHotelGenre genre );

	int GetHotelGenres( const _IN_ TSTvMode& tvMode, _OUT_ std::map< TCServiceId, std::vector< EHotelGenre > >& servicesWithGenres );

	int ReorderDigitalServices( const _IN_ TSTvMode& tvmode, const _IN_ unsigned short startMajor );

	int SaveMemoryDBToFile(){return 0;};

	int RestoreService( const _IN_ TCServiceId& serviceId );

	int RestoreServiceList( const _IN_ std::vector< TCServiceId >& serviceIds );

	int FetchFavorites( _INOUT_ TCServiceData& serviceData );

private:
	TCServiceProxy( void );
	TCServiceProxy( const TCServiceProxy& ){};
	TCServiceProxy& operator= ( const TCServiceProxy& ) { return *this; };

	static IService* m_pInstance;

	static TVServiceAPIConnection* m_pTVSConnection;
	static std::string m_interfaceName;
	static pthread_rwlock_t m_rwlock; // lock for instance creation in multi-thread applications
};
#endif //_SERVICEPROXY_H_
