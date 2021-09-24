#ifndef _PROGRAMSUBSCRIBERPROXY_H_
#define _PROGRAMSUBSCRIBERPROXY_H_

#include <pthread.h>
#include <string>
#include <set>

#include "IProgramSubscriber.h"

class TCProgramSubscriberProxy : public IProgramSubscriber
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
	static IProgramSubscriber* Instance( void );

	/**
	 * @brief Destroys all interface instances.
	 */
	static void Destroy( void );

	/**
	 * @brief Returns an interface object
	 * @param [in] callback callback method that should be called when section comes
	 */
	static void SetCallback( ProgramCallback callback  );

	/**
	 * @brief Callback when program comes. This method should be called only by IPCS.
	 * @param [in] handle handle ID
	 * @param [in] messageBuffer raw data buffer
	 */
	static void OnProgramCallback(int handle, TCMessageBuffer& messageBuffer);
	
	int SubscribeProgram( const _IN_ TCProgramFilteringItem& progItem, _OUT_ int& handle );

	int UnSubscribeProgram( _IN_ int handle );

	int SubscribeProgramListPF( _IN_ int userParam, const _IN_ TCServiceId& serviceId, _IN_ ESubscribeType type, _OUT_ int& handle );

	int SubscribeProgramList( _IN_ int userParam, const _IN_ TCServiceId& serviceId, _IN_ unsigned int startTime, _IN_ unsigned int duration, _IN_ ESubscribeType type, _OUT_ int& handle );

	int UnSubscribeProgramList( _IN_ int handle );

	int MonitoringType( _INOUT_ EProgramMonitoringType& out_monitoring_type );

private:
	TCProgramSubscriberProxy( void );
	TCProgramSubscriberProxy( const TCProgramSubscriberProxy& ){};
	TCProgramSubscriberProxy& operator= ( const TCProgramSubscriberProxy& ) { return *this; };

	static IProgramSubscriber* m_pInstance;
	static ProgramCallback m_callback;

	static TVServiceAPIConnection* m_pTVSConnection;
	static std::string m_interfaceName;
	static pthread_rwlock_t m_rwlock; // lock for instance creation in multi-thread applications

	static pthread_mutex_t m_mutex;
	static std::set<int> m_handles; 
};
#endif //_PROGRAMSUBSCRIBERPROXY_H_
