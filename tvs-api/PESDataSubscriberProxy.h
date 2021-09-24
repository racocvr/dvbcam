#ifndef _PESDATASUBSCRIBERPROXY_H_
#define _PESDATASUBSCRIBERPROXY_H_

#include <string>
#include <pthread.h>
#include <map>
#include <set>

#include "TVServiceDataType.h"
#include "MarshallingHelperProxy.h"
#include "IPESDataSubscriber.h"

class TCPESDataSubscriberProxy : public IPESDataSubscriber
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
	static IPESDataSubscriber* Instance( TVSHandle tvsHandle );

	/**
	 * @brief Callback when PES data comes. This method should be called only by IPCS.
	 * @param [in] messageId Message id (subscription handle).
	 * @param [in] messageBuffer Raw data buffer (serialized PES data).
	 */
	static void OnCallback(int messageId, TCMessageBuffer& messageBuffer);

	/**
	 * @brief Callback when extended PES data comes. This method should be called only by IPCS.
	 * @param [in] messageId Message id (subscription handle).
	 * @param [in] messageBuffer Raw data buffer (serialized PES data).
	 */
	static void OnExCallback(int messageId, TCMessageBuffer& messageBuffer);

	/**
	 * @brief Destroys all interface instances.
	 */
	static void Destroy( void );

	int Subscribe( _IN_ PESDataCallback pesDataCallback, _IN_ void* pUserData, _OUT_ int& handle );

	int Subscribe( _IN_ ExPESDataCallback exPesDataCallback, const _IN_ TCServiceId& serviceId, _IN_ int componentTag, _IN_ void* pUserData, _OUT_ int& handle );

	int Unsubscribe( _IN_ int handle );

private:
	TCPESDataSubscriberProxy( TVSHandle tvsHandle );
	TCPESDataSubscriberProxy( const TCPESDataSubscriberProxy& ){};
	TCPESDataSubscriberProxy& operator= ( const TCPESDataSubscriberProxy& ) { return *this; };

	/**
	 * @brief Adds profile related data to proxy method call.
	 * @param [in] helper Proxy marshalling helper.
	 */
	void m_AddInterfaceProfiling( TCMarshallingHelperProxy& helper );

	static std::map<TVSHandle, IPESDataSubscriber*> m_instances;
	TVSHandle m_tvsHandle;

	static TVServiceAPIConnection* m_pTVSConnection;
	static std::string m_interfaceName;
	static pthread_rwlock_t m_rwlock; // lock for instance creation in multi-thread applications
	static pthread_mutex_t m_mutex;

private:

	template<typename PESCallbackType>
	struct TSPESDataCallback
	{
		PESCallbackType callback;
		TVSHandle tvsHandle;
		void* pUserData;

		TSPESDataCallback(): callback(NULL), tvsHandle(), pUserData(NULL) {}
		TSPESDataCallback(PESCallbackType call, TVSHandle handle, void* pData): callback(call), tvsHandle(handle), pUserData(pData) {}
	};

	typedef std::map<int, TSPESDataCallback<PESDataCallback> > TTPESDataMap; //< first arg: handle (subscription Id), second arg: PES callback data
	static TTPESDataMap m_pesData;

	typedef std::map<int, TSPESDataCallback<ExPESDataCallback> > TTExPESDataMap; //< first arg: handle (subscription Id), second arg: Ex PES callback data
	static TTExPESDataMap m_exPesData;
};
#endif //_PESDATASUBSCRIBERPROXY_H_
