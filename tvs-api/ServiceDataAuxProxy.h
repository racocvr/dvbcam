#ifndef _SERVICEDATAAUXPROXY_H_
#define _SERVICEDATAAUXPROXY_H_

#include <string>
#include <pthread.h>
#include <map>
#include "TVServiceDataType.h"

#include "MarshallingHelperProxy.h"
#include "IServiceDataAux.h"

class TCServiceDataAuxProxy : public IServiceDataAux
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
	static IServiceDataAux* Instance( TVSHandle tvsHandle );

	/**
	 * @brief Destroys all interface instances.
	 */
	static void Destroy( void );

	int SizeOfAudio( const _IN_ TCServiceId& serviceId, _OUT_ unsigned int& size );

	int GetAudio( const _IN_ TCServiceId& serviceId, _IN_ unsigned int index, _OUT_ TSAudio& audio );

	int GetPreferredAudio( const _IN_ TCServiceId& serviceId, _OUT_ TSAudio& audio );

	int CheckAudioDescription( const _IN_ TCServiceId& serviceId, _OUT_ bool& exists );

	int SizeOfAudioDescription( const _IN_ TCServiceId& serviceId, _OUT_ unsigned int& size );

	int GetAudioDescription( const _IN_ TCServiceId& serviceId, _IN_ unsigned int index, _OUT_ TSAudio& audioDesc );

	int SizeOfTTX( const _IN_ TCServiceId& serviceId, _OUT_ unsigned int& size );

	int GetTTX( const _IN_ TCServiceId& serviceId, _IN_ unsigned int index, _OUT_ TSTTX& ttx );

	int SizeOfHybridSBT( const _IN_ TCServiceId& serviceId, _OUT_ unsigned int& size );

	int GetHybridSBT( const _IN_ TCServiceId& serviceId, _IN_ unsigned int index, _OUT_ ELanguageCode& language, _OUT_ TSHybridSBT& hybridSbt );

	int GetComponentByPid( const _IN_ TCServiceId& serviceId, _IN_ unsigned short pid, _OUT_ TSComponent& component );

	int GetComponentByTag( const _IN_ TCServiceId& serviceId, _IN_ unsigned char tag, _OUT_ TSComponent& component );

	int GetAllComponents( const _IN_ TCServiceId& serviceId, _OUT_ std::vector< TSComponent >& components );

	int CheckHardOfHearingSBT( const _IN_ TCServiceId& serviceId, _OUT_ bool& exists );

	int SizeOfISDBText( const _IN_ TCServiceId& serviceId, _IN_ EISDBTextType mode, _OUT_ unsigned int& size );

	int GetISDBText( const _IN_ TCServiceId& serviceId, _IN_ EISDBTextType mode, _IN_ unsigned int index, _OUT_ TSISDBText& isdbText );

	int GetPreferredHybridSBT( const _IN_ TCServiceId& serviceId, _OUT_ ELanguageCode& language, _OUT_ TSHybridSBT& hybridSbt );

	int ReturnChannelAccessAllowed( const _IN_ TCServiceId& serviceId, _OUT_ bool& result );

	int InteractiveServiceAllowed( const _IN_ TCServiceId& serviceId, _OUT_ bool& result );

private:
	TCServiceDataAuxProxy( TVSHandle tvsHandle );
	TCServiceDataAuxProxy( const TCServiceDataAuxProxy& ){};
	TCServiceDataAuxProxy& operator= ( const TCServiceDataAuxProxy& ) { return *this; };

	/**
	 * @brief Adds profile related data to proxy method call.
	 * @param [in] helper Proxy marshalling helper.
	 */
	void m_AddInterfaceProfiling( TCMarshallingHelperProxy& helper );

	static std::map<TVSHandle, IServiceDataAux*> m_instances;
	TVSHandle m_tvsHandle;

	static TVServiceAPIConnection* m_pTVSConnection;
	static std::string m_interfaceName;
	static pthread_rwlock_t m_rwlock; // lock for instance creation in multi-thread applications
};
#endif //_SERVICEDATAAUXPROXY_H_
