#ifndef _DSMPROXY_H_
#define _DSMPROXY_H_

#include <string>
#include <pthread.h>

#include "IDsm.h"

class TCDsmProxy : public IDsm
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
	static TCDsmProxy* Instance( void );

	/**
	 * @brief Destroys all interface instances.
	 */
	static void Destroy( void );

	int RequestAttach( _OUT_ unsigned int& sessionHandle, const _IN_ std::vector< unsigned char >& nsap, _IN_ EDsmDataServiceType dataServiceType, _IN_ EDsmAttachType attachType, _IN_ void* pUserParam, _IN_ bool clearCache );

	int Detach( _IN_ unsigned int sessionHandle );

	int RequestObjectLoad( _IN_ unsigned int sessionHandle, const _IN_ std::string& path, _IN_ EDsmObjectLoadType loadType, _IN_ void* pUserParam );

	int AbortObjectLoad( _IN_ unsigned int sessionHandle, const _IN_ std::string& path );

	int AddMonitor( _IN_ unsigned int sessionHandle, const _IN_ std::string& path, _IN_ void* pUserParam );

	int DeleteMonitor( _IN_ unsigned int sessionHandle, const _IN_ std::string& path, _IN_ void* pUserParam );

	int RequestObjectName( _IN_ unsigned int sessionHandle, const _IN_ std::string& parentDirPath, const _IN_ TSDsmObjectLocation& objectLocation, _IN_ void* pUserParam );

	int GetServiceContextList( _IN_ unsigned int sessionHandle, _OUT_ unsigned int& SclCount, _OUT_ std::vector< unsigned char >& serviceContextData );

	int GetUserInfoBytes( _IN_ unsigned int sessionHandle, _OUT_ std::vector< unsigned char >& userInfoBytes );

	int RequestStreamOpen( _IN_ unsigned int sessionHandle, _OUT_ unsigned int& streamHandle, const _IN_ std::string& path, _IN_ void* pUserParam );

	int CloseStream( _IN_ unsigned int streamHandle );

	int RequestStreamInfo( _IN_ unsigned int streamHandle, _IN_ void* pUserParam );

	int RequestStreamTap( _IN_ unsigned int streamHandle, _IN_ void* pUserParam );

	int RequestEventList( _IN_ unsigned int streamHandle, _IN_ void* pUserParam );

	int SubscribeEvent( _IN_ unsigned int streamHandle, _IN_ unsigned short eventID, _IN_ void* pUserParam );

	int SubscribeEvent( _IN_ unsigned int streamHandle, const _IN_ std::string& eventName, _IN_ void* pUserParam );

	int UnsubscribeEvent( _IN_ unsigned int streamHandle, _IN_ unsigned short eventID );

	int UnsubscribeEvent( _IN_ unsigned int streamHandle, const _IN_ std::string& eventName );

	int SetServedApplicationProfile(_IN_ unsigned short applicationProfile, _IN_ unsigned char versionMajor, _IN_ unsigned char versionMinor, _IN_ unsigned char versionMicro);

	void SetCallbackFunction(DsmCallback callback);
private:
	TCDsmProxy( void );
	TCDsmProxy( const TCDsmProxy& ){};
	TCDsmProxy& operator= ( const TCDsmProxy& ) { return *this; };
	~TCDsmProxy( void );

	static TCDsmProxy* m_pInstance;

	DsmCallback m_dsmCallback;
	static TVServiceAPIConnection* m_pTVSConnection;
	static std::string m_interfaceName;
	static pthread_rwlock_t m_rwlock; // lock for instance creation in multi-thread applications

	static void m_OnCallback(int messageType, TCMessageBuffer& messageBuffer);
	template<typename T> void m_SendMessage(TCMessageBuffer& messageBuffer);
};
#endif //_DSMPROXY_H_
