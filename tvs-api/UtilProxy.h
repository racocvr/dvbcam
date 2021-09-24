#ifndef _UTILPROXY_H_
#define _UTILPROXY_H_

#include <string>
#include <pthread.h>

#include "IUtil.h"

class TCUtilProxy : public IUtil
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
	static IUtil* Instance( void );

	/**
	 * @brief Destroys all interface instances.
	 */
	static void Destroy( void );

	int SetDualTvAvOff( _IN_ bool onOff );

	int SelectMasterAudio( _IN_ EProfile profileId, _IN_ int screenId );

	int GetMasterAudio( _OUT_ EProfile& profileId, _OUT_ int& screenId );

	int SetTVSystemTime( _IN_ unsigned long UTC );

	int GetTimeZoneOffset( _IN_ ETimeZone timeZone, _OUT_ int& offset );

	int GetAutoClockType( _OUT_ ETypeOfAutoClock& autoClockType );

	int CheckRCNEditable( const _IN_ TSTvMode& tvMode, _OUT_ bool& editable ) const;

	int SetRCNEditable( const _IN_ TSTvMode& tvMode, _IN_ bool editable );
	
	int CheckServiceDeleteSupport( const _IN_ TSTvMode& tvMode, _OUT_ bool& deletable ) const;

	int GetPreferredLanguage( _IN_ EProfile profileId, _IN_ int screenId, _OUT_ unsigned int& language );

	int GetServiceDb( const _IN_ std::string& path );

	int ReplaceServiceDb( const _IN_ std::string& path, _OUT_ EServiceDbReplacementStatus& status );

	int Backup( const _IN_ std::string& path );

	int Restore( const _IN_ std::string& path );
	
	int SaveHistoryTrace();
	
	int ClearHistoryTrace();
	
private:
	TCUtilProxy( void );
	TCUtilProxy( const TCUtilProxy& ){};
	TCUtilProxy& operator= ( const TCUtilProxy& ) { return *this; };

	static IUtil* m_pInstance;

	static TVServiceAPIConnection* m_pTVSConnection;
	static std::string m_interfaceName;
	static pthread_rwlock_t m_rwlock; // lock for instance creation in multi-thread applications
};
#endif //_UTILPROXY_H_
