#ifndef _SOURCECONTROLPROXY_H_
#define _SOURCECONTROLPROXY_H_

#include <string>
#include <pthread.h>
#include <map>
#include "TVServiceDataType.h"

#include "MarshallingHelperProxy.h"
#include "ISourceControl.h"

class TCSourceControlProxy : public ISourceControl
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
	static ISourceControl* Instance( TVSHandle tvsHandle );

	/**
	 * @brief Destroys all interface instances.
	 */
	static void Destroy( void );

	int SetSource( _IN_ ESource sourceType, const _IN_ std::string& appID );

	int SetSource( _IN_ ESource sourceType, _IN_ TCServiceId serviceId, const _IN_ std::string& appID );

	int SetSHMSinkAttribute( const _IN_ TVSHMSinkAttr& attribute );

	int DeactivateSource( void );

	int GetCurrentSourceInfo( _OUT_ ESource& source );

	int GetPreviousSourceInfo( _OUT_ ESource& source );

	int TVServiceStop( void );

	int GetSourceState( _OUT_ ESourceState& sourceState );

	int CheckExtSourcePlugged( _IN_ ESource sourceType, _OUT_ bool& check );

	int SourceLockStatus( _OUT_ bool& lockStatus );

	int ResetCurrentSourceInfo( void );

	int LiveTvShowReady( void );

	int LiveTvShowClose( void );

	int IsActive( _OUT_ bool& result );

	int GetAvailableSources( _OUT_ std::vector< ESource >& availableSources );

	int CheckSourceStatus( const _IN_ std::list< ESource >& sources, _OUT_ std::map< ESource, ESourceStatus >& status );

	int StartSourceMonitoring( _IN_ ESource source );

	int StopSourceMonitoring( _IN_ ESource source );

	int StartHDMIAnalysis( _IN_ ESource source );

	int StopHDMIAnalysis( _IN_ ESource source );
	
	int PrepareLFDSoundOnVideoCall( _IN_ bool enable );

private:
	TCSourceControlProxy( TVSHandle tvsHandle );
	TCSourceControlProxy( const TCSourceControlProxy& ){};
	TCSourceControlProxy& operator= ( const TCSourceControlProxy& ) { return *this; };

	/**
	 * @brief Adds profile related data to proxy method call.
	 * @param [in] helper Proxy marshalling helper.
	 */
	void m_AddInterfaceProfiling( TCMarshallingHelperProxy& helper );

	static std::map<TVSHandle, ISourceControl*> m_instances;
	TVSHandle m_tvsHandle;

	static TVServiceAPIConnection* m_pTVSConnection;
	static std::string m_interfaceName;
	static pthread_rwlock_t m_rwlock; // lock for instance creation in multi-thread applications
};
#endif //_SOURCECONTROLPROXY_H_
