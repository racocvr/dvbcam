#ifndef _SECTIONSUBSCRIBERPROXY_H_
#define _SECTIONSUBSCRIBERPROXY_H_

#include <pthread.h>
#include <string>
#include <map>
#include <set>
#include "TVServiceDataType.h"

#include "MarshallingHelperProxy.h"
#include "ISectionSubscriber.h"

class TCSectionSubscriberProxy : public ISectionSubscriber
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
	static ISectionSubscriber* Instance( TVSHandle tvsHandle );
	
	/**
	 * @brief Returns an interface object
	 * @param [in] callback callback method that should be called when section comes
	 */
	static void SetCallback( SectionCallback callback  );

	/**
	 * @brief Callback when section comes. This method should be called only by IPCS.
	 * @param [in] handle handle ID
	 * @param [in] messageBuffer raw data buffer
	 */
	static void OnSectionCallback(int handle, TCMessageBuffer& messageBuffer);

	/**
	 * @brief Destroys all interface instances.
	 */
	static void Destroy( void );

	int Subscribe( _IN_ int userParam, const _IN_ TCSectionCriteriaHelper& criteria, _OUT_ int& handle );

	int SubscribeByFilter( _IN_ int userParam, const _IN_ TCSectionFilterCriteriaHelper& filterCriteria, _OUT_ int& handle );

	int Unsubscribe( _IN_ int handle );

private:
	TCSectionSubscriberProxy( TVSHandle tvsHandle );
	TCSectionSubscriberProxy( const TCSectionSubscriberProxy& ){};
	TCSectionSubscriberProxy& operator= ( const TCSectionSubscriberProxy& ) { return *this; };

	/**
	 * @brief Adds profile related data to proxy method call.
	 * @param [in] helper Proxy marshalling helper.
	 */
	void m_AddInterfaceProfiling( TCMarshallingHelperProxy& helper );

	static std::map<TVSHandle, ISectionSubscriber*> m_instances;
	TVSHandle m_tvsHandle;

	static TVServiceAPIConnection* m_pTVSConnection;
	static std::string m_interfaceName;
	static pthread_rwlock_t m_rwlock; // lock for instance creation in multi-thread applications

	static SectionCallback m_callback;

	static pthread_mutex_t m_mutex;

	typedef std::map<int, TVSHandle> TTReceiverList; //<- maps subscribe handle to TVSHandle
	static TTReceiverList m_receivers;
};
#endif //_SECTIONSUBSCRIBERPROXY_H_
