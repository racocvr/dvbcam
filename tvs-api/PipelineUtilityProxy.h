#ifndef _PIPELINEUTILITYPROXY_H_
#define _PIPELINEUTILITYPROXY_H_

#include <string>
#include <pthread.h>
#include <map>
#include "TVServiceDataType.h"

#include "MarshallingHelperProxy.h"
#include "IPipelineUtility.h"

class TCPipelineUtilityProxy : public IPipelineUtility
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
	static IPipelineUtility* Instance( TVSHandle tvsHandle );

	/**
	 * @brief Destroys all interface instances.
	 */
	static void Destroy( void );

	int GetStreamTime( _OUT_ unsigned long& streamTime );

	int FlagStreamDST( void );

	int GetTimeOffset( _OUT_ unsigned long& timeOfTimeChange, _OUT_ int& nextTimeOffset, _OUT_ int& currentTimeOffset );

	int CheckPipelineAvailable( _OUT_ bool& available );

	int NotifyReceiverState( _IN_ EStateChange state, const _IN_ std::string& receiverId, _IN_ bool ready, const _IN_ TCServiceId& serviceId );

	int RegisterForStateChange( _IN_ EStateChange state, const _IN_ std::string& receiverId, _IN_ bool useTimeout );

	int UnregisterFromStateChange( _IN_ EStateChange state, const _IN_ std::string& receiverId );

	int GetCurrentTPMSStatus( _OUT_ TCTPMSStatus& status );
	
	int GetPIDSetStatus( _OUT_ bool& done );

private:
	TCPipelineUtilityProxy( TVSHandle tvsHandle );
	TCPipelineUtilityProxy( const TCPipelineUtilityProxy& ){};
	TCPipelineUtilityProxy& operator= ( const TCPipelineUtilityProxy& ) { return *this; };

	/**
	 * @brief Adds profile related data to proxy method call.
	 * @param [in] helper Proxy marshalling helper.
	 */
	void m_AddInterfaceProfiling( TCMarshallingHelperProxy& helper );

	static std::map<TVSHandle, IPipelineUtility*> m_instances;
	TVSHandle m_tvsHandle;

	static TVServiceAPIConnection* m_pTVSConnection;
	static std::string m_interfaceName;
	static pthread_rwlock_t m_rwlock; // lock for instance creation in multi-thread applications
};
#endif //_PIPELINEUTILITYPROXY_H_
