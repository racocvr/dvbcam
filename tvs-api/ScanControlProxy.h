#ifndef _SCANCONTROLPROXY_H_
#define _SCANCONTROLPROXY_H_

#include <string>
#include <pthread.h>

#include "IScanControl.h"

class TCScanControlProxy : public IScanControl
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
	static IScanControl* Instance( void );

	/**
	 * @brief Destroys all interface instances.
	 */
	static void Destroy( void );

	int StartAutoScan( void );

	int StopAutoScan( bool force = false );

	int PauseAutoScan( void );

	int ResumeAutoScan( void );

	int ActivateManualAnalogScan( void );

	int DeactivateManualAnalogScan( void );

	int StartManualScan( const _IN_ TSScanChannel& scanChannel );

	int StopManualScan( void );

	int PauseManualScan( void );

	int ResumeManualScan( void );

	int StoreServiceForManualAnalogScan( unsigned short major );

	int StartHomingChannelSearch( const _IN_ std::vector< TSHomingChannelLocator >& homingCandidates, _IN_ EProfile profileId, _IN_ unsigned short subId );

	int StopHomingChannelSearch( _IN_ bool force, _IN_ EProfile profileId, _IN_ unsigned short subId );

	int PauseHomingChannelSearch( _IN_ EProfile profileId, _IN_ unsigned short subId );

	int ResumeHomingChannelSearch( _IN_ EProfile profileId, _IN_ unsigned short subId );

	int StartClearScramble( _IN_ EChannelType channelType );

	int StopClearScramble( void );

	int PauseClearScramble( void );

	int ResumeClearScramble( void );

private:
	TCScanControlProxy( void );
	TCScanControlProxy( const TCScanControlProxy& ){};
	TCScanControlProxy& operator= ( const TCScanControlProxy& ) { return *this; };

	static IScanControl* m_pInstance;

	static TVServiceAPIConnection* m_pTVSConnection;
	static std::string m_interfaceName;
	static pthread_rwlock_t m_rwlock; // lock for instance creation in multi-thread applications
};
#endif //_SCANCONTROLPROXY_H_
