#ifndef _TUNERCONTROLPROXY_H_
#define _TUNERCONTROLPROXY_H_

#include <string>
#include <pthread.h>
#include <map>
#include "TVServiceDataType.h"

#include "MarshallingHelperProxy.h"
#include "ITunerControl.h"

class TCTunerControlProxy : public ITunerControl
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
	static ITunerControl* Instance( TVSHandle tvsHandle );

	/**
	 * @brief Destroys all interface instances.
	 */
	static void Destroy( void );

	int GetSignalStrength( _IN_ bool selfFlag, _OUT_ unsigned char& sigStrength );

	int GetSignalQuality( _OUT_ unsigned char& quality );

	int GetSignalKind( _OUT_ ESignalKind& signalKind );

	int GetBER( _OUT_ unsigned int& ber );

	int GetSNR( _OUT_ unsigned int& snr );

	int ResetMFT( void );

	int TuneForMFT( _IN_ unsigned char mftFreq );
	
	int SaveForMFT( void );
	
	int GetTunerOffsetForMFT(_OUT_ unsigned char& mftFreq);
	
	int GetTunerIndex( _OUT_ int& index );

	int GetTuneSignalState( _OUT_ ETunerSignalState& state );

private:
	TCTunerControlProxy( TVSHandle tvsHandle );
	TCTunerControlProxy( const TCTunerControlProxy& ){};
	TCTunerControlProxy& operator= ( const TCTunerControlProxy& ) { return *this; };

	/**
	 * @brief Adds profile related data to proxy method call.
	 * @param [in] helper Proxy marshalling helper.
	 */
	void m_AddInterfaceProfiling( TCMarshallingHelperProxy& helper );

	static std::map<TVSHandle, ITunerControl*> m_instances;
	TVSHandle m_tvsHandle;

	static TVServiceAPIConnection* m_pTVSConnection;
	static std::string m_interfaceName;
	static pthread_rwlock_t m_rwlock; // lock for instance creation in multi-thread applications
};
#endif //_TUNERCONTROLPROXY_H_
