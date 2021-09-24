#ifndef _PVREXPROXY_H_
#define _PVREXPROXY_H_

#include <string>
#include <pthread.h>

#include "IPVREx.h"

class TCPVRExProxy : public IPVREx
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
	static IPVREx* Instance( void );

	/**
	 * @brief Destroys all interface instances.
	 */
	static void Destroy( void );

	int MakeThumbnailFrameFileStart( const _IN_ std::string& fileName );

	int GetThumbnailFrameFileInfo( _OUT_ std::vector< int >& size, _OUT_ std::vector< int >& codecType );

	int CheckAvailableTunerToRecord( const _IN_ TCServiceId& serviceId, _OUT_ int& result );

	int GetCandidateTunerList( const _IN_ TCServiceId& serviceId, _OUT_ std::vector< TCTunerInfo >& tunerInfoList );

	int GetConflictRecordListForChannelChange( const _IN_ int screenId, const _IN_ TCServiceId& serviceId, _OUT_ std::vector< TVSHandle >& conflictRecordList, _OUT_ bool& isAll );

	int GetConflictRecordListForSourceChange( const _IN_ int screenId, const _IN_ int sourceType, _OUT_ std::vector< TVSHandle >& conflictRecordList, _OUT_ bool& isAll );

	int IsFileRecordedLocal( const _IN_ std::string& fileName, _OUT_ bool& result );

private:
	TCPVRExProxy( void );
	TCPVRExProxy( const TCPVRExProxy& ){};
	TCPVRExProxy& operator= ( const TCPVRExProxy& ) { return *this; };

	static IPVREx* m_pInstance;

	static TVServiceAPIConnection* m_pTVSConnection;
	static std::string m_interfaceName;
	static pthread_rwlock_t m_rwlock; // lock for instance creation in multi-thread applications
};
#endif //_PVREXPROXY_H_
