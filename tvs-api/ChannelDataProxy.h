#ifndef _CHANNELDATAPROXY_H_
#define _CHANNELDATAPROXY_H_

#include <string>
#include <pthread.h>
#include <map>
#include "TVServiceDataType.h"

#include "MarshallingHelperProxy.h"
#include "IChannelData.h"

class TCChannelDataProxy : public IChannelData
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
	static IChannelData* Instance( TVSHandle tvsHandle );

	/**
	 * @brief Destroys all interface instances.
	 */
	static void Destroy( void );

	int GetDigitalFrequency( const _IN_ TSTvMode& tvMode, _IN_ unsigned short channelNumber, _IN_ EFrequencyType freqType, _OUT_ int& freq );

	int GetDigitalChannelNumber( const _IN_ TSTvMode& tvMode, _IN_ int freq, _IN_ EFrequencyType freqType, _OUT_ unsigned short& channelNumber );

	int GetDigitalChannels( const _IN_ TSTvMode& tvMode, _OUT_ std::list< TSChannelData* >& channels );

	int GetAnalogFrequency( const _IN_ TSTvMode& tvMode, _IN_ unsigned short channelNumber, _OUT_ int& freq );

	int GetAnalogChannelNumber( const _IN_ TSTvMode& tvMode, _IN_ int freq, _OUT_ unsigned short& channelNumber );

	int GetAnalogChannels( const _IN_ TSTvMode& tvMode, _OUT_ std::list< TSChannelData* >& channels );

	int GetAlternativeChannels( const _IN_ TSTvMode& tvMode, unsigned short channelNumber, _OUT_ std::vector< unsigned short >& alternativeChannelNumbers );

	int GetNetworkName( const _IN_ TSTvMode& tvMode, _IN_ unsigned short netId, _OUT_ t_wstring& networkName );

private:
	TCChannelDataProxy( TVSHandle tvsHandle );
	TCChannelDataProxy( const TCChannelDataProxy& ){};
	TCChannelDataProxy& operator= ( const TCChannelDataProxy& ) { return *this; };

	/**
	 * @brief Adds profile related data to proxy method call.
	 * @param [in] helper Proxy marshalling helper.
	 */
	void m_AddInterfaceProfiling( TCMarshallingHelperProxy& helper );

	static std::map<TVSHandle, IChannelData*> m_instances;
	TVSHandle m_tvsHandle;

	static TVServiceAPIConnection* m_pTVSConnection;
	static std::string m_interfaceName;
	static pthread_rwlock_t m_rwlock; // lock for instance creation in multi-thread applications
};
#endif //_CHANNELDATAPROXY_H_
