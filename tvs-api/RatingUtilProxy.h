#ifndef _RATINGUTILPROXY_H_
#define _RATINGUTILPROXY_H_

#include <string>
#include <pthread.h>

#include "IRatingUtil.h"

class TCRatingUtilProxy : public IRatingUtil
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
	static IRatingUtil* Instance( void );

	/**
	 * @brief Destroys all interface instances.
	 */
	static void Destroy( void );

	int SetUnlockedInfo( const _IN_ TVSHandle& in_handle, _IN_ int in_rating_info );
	
	int GetTempRatingBlockedFlag( const _IN_ TVSHandle& in_handle, _INOUT_ bool& out_flag );

	int SetTempRatingBlockedFlag( const _IN_ TVSHandle& in_handle, _IN_ bool in_flag );

	int SetTempUnblockedLevel( const _IN_ TVSHandle& in_handle, _IN_ int in_rating );

	int GetTempUnblockedLevel( const _IN_ TVSHandle& in_handle, _INOUT_ int& out_rating );

	int SetUnBlockedFlag18( const _IN_ TVSHandle& in_handle, _IN_ bool in_flag );

	int SetRespondToCam( const _IN_ TVSHandle& in_handle, _IN_ bool in_flag );

	int FlagRespondToCam( const _IN_ TVSHandle& in_handle, _INOUT_ bool& out_flag );

	int SetServiceLocked( const _IN_ TVSHandle& in_handle, _IN_ bool in_serviceLocked );

	int FlagServiceLocked( const _IN_ TVSHandle& in_handle, _INOUT_ bool& out_serviceLocked );

	int SetTempUnblockedZiggoChildLock( const _IN_ TVSHandle& in_handle, _IN_ bool in_bChildLocked );

	int FlagTempUnblockedZiggoChildLock( const _IN_ TVSHandle& in_handle, _INOUT_ bool& out_bChildLocked );

	int SetTempRatingBlockedByCamFlag( const _IN_ TVSHandle& in_handle, _IN_ bool in_flag );

	int GetTempRatingBlockedByCamFlag( const _IN_ TVSHandle& in_handle, _INOUT_ bool& out_flag );

	int SendRatingChangedFromGuide(_IN_ const TVSHandle& in_handle);

	int SetUnlockedInfoWhenFactoryMode( const _IN_ TVSHandle& in_handle, _IN_ bool in_lock );
private:
	TCRatingUtilProxy( void );
	TCRatingUtilProxy( const TCRatingUtilProxy& ){};
	TCRatingUtilProxy& operator= ( const TCRatingUtilProxy& ) { return *this; };

	static IRatingUtil* m_pInstance;

	static TVServiceAPIConnection* m_pTVSConnection;
	static std::string m_interfaceName;
	static pthread_rwlock_t m_rwlock; // lock for instance creation in multi-thread applications
};
#endif //_RATINGUTILPROXY_H_
