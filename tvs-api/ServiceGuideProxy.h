#ifndef _SERVICEGUIDEPROXY_H_
#define _SERVICEGUIDEPROXY_H_

#include <string>
#include <pthread.h>

#include "IServiceGuide.h"

class TCServiceGuideProxy : public IServiceGuide
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
	static IServiceGuide* Instance( void );

	/**
	 * @brief Destroys all interface instances.
	 */
	static void Destroy( void );

	int GetSplitProgramList( const _IN_ TCProgramId& programId, _OUT_ std::map< unsigned int, TCProgramData* >& out_program_map );

	int GetProgramList( const _IN_ TCServiceId& serviceId, _IN_ unsigned int startTime, _IN_ unsigned int duration, _OUT_ std::map< unsigned int, TCProgramData* >& out_program_map );

	int GetProgramList( const _IN_ std::string crid, _IN_ ECRIDType cridType, _OUT_ std::map< unsigned int, TCProgramData* >& out_program_map );

	int GetProgram( _IN_ EProgramIndicator indicator, const _IN_ TCProgramId& referenceProgramId, _OUT_ TCProgramData& program );

	int GetProgram( const _IN_ TCProgramId& referenceProgramId, _OUT_ TCProgramData& program );

	int GetProgram( _IN_ EProgramIndicator in_indicator, _IN_ EFSatEventGenreType in_genre, const _IN_ TCProgramId& in_program_id, _OUT_ TCProgramData& out_program_data );

	int GetPresentProgram( const _IN_ TCServiceId& serviceId, _OUT_ TCProgramData& program );

	int GetGenreList( _OUT_ std::map< unsigned short, t_wstring >& out_genre_map );

	int SwapPrograms( const _IN_ TCServiceId& destService, const _IN_ TCServiceId& srcService );

	int CheckProgramExists( const _IN_ TCServiceId& serviceId, _IN_ unsigned int startTime, _IN_ unsigned int duration, _OUT_ bool& exist );

	int GetBarkerChannel( const _IN_ TSTvMode& tvMode, _OUT_ TSBarkerChannelLocator& barkerChannel );

	int GetSimulcastInfo( const _IN_ TCProgramId& in_programId, _OUT_ std::list< ESimulcastInfo >& out_simulcastInfoList );

	int GetProgramListByGenre( _IN_ unsigned long in_starttime, _IN_ unsigned long in_duration, const _IN_ EFSatEventGenreType in_event_genre_type, _OUT_ std::map< unsigned int, TCProgramData* >& out_program_map );

	int CheckServiceInGroup( _IN_ unsigned short freesatId, _IN_ unsigned short groupId, _OUT_ bool& exist );

	int SetEPGDynamicUpdateEventFocusRange( _IN_ int in_subscribe_id, _IN_ std::vector< TCServiceId >& in_service_ids, _IN_ unsigned long in_start_time, _IN_ unsigned long in_end_time );

	int GetProgramList( _IN_ std::vector< TCServiceId > servicesId, _IN_ unsigned int startTime, _IN_ unsigned int duration, _OUT_ std::map< TCServiceId, std::map< unsigned int, TCProgramData* > >& programMap );

	int SaveProgramData( void );

private:
	TCServiceGuideProxy( void );
	TCServiceGuideProxy( const TCServiceGuideProxy& ){};
	TCServiceGuideProxy& operator= ( const TCServiceGuideProxy& ) { return *this; };

	static IServiceGuide* m_pInstance;

	static TVServiceAPIConnection* m_pTVSConnection;
	static std::string m_interfaceName;
	static pthread_rwlock_t m_rwlock; // lock for instance creation in multi-thread applications
};
#endif //_SERVICEGUIDEPROXY_H_
