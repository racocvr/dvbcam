#ifndef _DATASUBSCRIBERPROXY_H_
#define _DATASUBSCRIBERPROXY_H_

#include <string>
#include <pthread.h>
#include <map>
#include <set>

#include "TVServiceDataType.h"
#include "MarshallingHelperProxy.h"
#include "IDataSubscriber.h"

class TCDataSubscriberProxy : public IDataSubscriber
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
	static IDataSubscriber* Instance( TVSHandle tvsHandle );

	/**
	 * @brief Callback when user data comes. This method should be called only by IPCS.
	 * @param [in] messageBuffer Raw data buffer.
	 */
	static void OnCallback(int messageId, TCMessageBuffer& messageBuffer);

	/**
	 * @brief Destroys all interface instances.
	 */
	static void Destroy( void );

	int SubscribeForCaption( _IN_ CaptionCallback captionCallback, _IN_ void* pUserData, _OUT_ int& handle );

	int Unsubscribe( _IN_ int handle );

private:
	TCDataSubscriberProxy( TVSHandle tvsHandle );
	TCDataSubscriberProxy( const TCDataSubscriberProxy& ){};
	TCDataSubscriberProxy& operator= ( const TCDataSubscriberProxy& ) { return *this; };

	/**
	 * @brief Adds profile related data to proxy method call.
	 * @param [in] helper Proxy marshalling helper.
	 */
	void m_AddInterfaceProfiling( TCMarshallingHelperProxy& helper );

	static std::map<TVSHandle, IDataSubscriber*> m_instances;
	TVSHandle m_tvsHandle;

	static TVServiceAPIConnection* m_pTVSConnection;
	static std::string m_interfaceName;
	static pthread_rwlock_t m_rwlock; // lock for instance creation in multi-thread applications
	static pthread_mutex_t m_mutex;

private:
	struct TSCaptionCallback
	{
		CaptionCallback callback;
		TVSHandle tvsHandle;
		void* pUserData;

		TSCaptionCallback(): callback(NULL), tvsHandle(), pUserData(NULL) {}
		TSCaptionCallback(CaptionCallback call, TVSHandle handle, void* pData): callback(call), tvsHandle(handle), pUserData(pData) {}
	};

	typedef std::map<int, TSCaptionCallback> TTCaptionUserDataMap;
	static TTCaptionUserDataMap m_captionUserData;
};
#endif //_DATASUBSCRIBERPROXY_H_
