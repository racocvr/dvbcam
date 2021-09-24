#ifndef _PLAYBACKPROXY_H_
#define _PLAYBACKPROXY_H_

#include <string>
#include <pthread.h>
#include <map>

#include "MarshallingHelperProxy.h"
#include "IPlayback.h"

#include "ServiceData.h"

class TCPlaybackProxyNew : public IPlayback
{
public:

	/**
	 * @brief Sets Dbus connection for communication with TVS.
	 * @param [in] pTVSConnection TVService IPC connection.
	 */
	static void InitTVSConnection(TVServiceAPIConnection* pTVSConnection);

	/**
	 * @brief Returns an interface object.
	 * @param [in] uri URI address.
	 * @return Pointer to interface implementation.
	 */
	static IPlayback* Instance( TVSHandle& tvsHandle );

	/**
	 * @brief Destroys all interface instances.
	 */
	static void DestroyInstances( void );

	int Destroy( void );

	/**
	 * @brief Controls playback with given command.
	 * @param [in] inSize Playback control command size.
	 * @param [in] pInData Playback control command.
	 * @param [inout] outSize Size of output data.
	 * @param [inout] pOutData Result of the control command.
	 * @return Result >= 0 if successfully called TVService, result<0 if error occured.
	 */
	int ControlPlayback( _IN_ _ARRAY_SIZE_1_ unsigned int inSize, _IN_ _ARRAY_1_ unsigned char* pInData, _INOUT_ _ARRAY_SIZE_2_ unsigned int& outSize, _INOUT_ _ARRAY_2_ unsigned char* pOutData );

	int PipelineActivate( _IN_ std::string& uri, _IN_ TCServiceData& serviceData, const _IN_ TSPlaybackData& playbackData );


private:
	TCPlaybackProxyNew( TVSHandle& tvsHandle );
	TCPlaybackProxyNew( const TCPlaybackProxyNew& ){};
	TCPlaybackProxyNew& operator= ( const TCPlaybackProxyNew& ) { return *this; };
	void m_AddInterfaceProfiling( TCMarshallingHelperProxy& helper );

	static std::map<TVSHandle, IPlayback*> m_newInstances;
	static TVServiceAPIConnection* m_pTVSConnection;
	static std::string m_newInterfaceName;
	static pthread_rwlock_t m_rwlock; // lock for instance creation in multi-thread applications

	TVSHandle m_tvsHandle;
};




#endif //_PLAYBACKPROXY_H_
