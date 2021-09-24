#ifndef _AVCONTROLPROXY_H_
#define _AVCONTROLPROXY_H_

#include <string>
#include <pthread.h>
#include <map>
#include "TVServiceDataType.h"

#include "MarshallingHelperProxy.h"
#include "IAVControl.h"

class TCAVControlProxy : public IAVControl
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
	static IAVControl* Instance( TVSHandle tvsHandle );

	/**
	 * @brief Destroys all interface instances.
	 */
	static void Destroy( void );

	int GetCurrentAudioInfo( _OUT_ ELanguageCode& langCode, _OUT_ int& index );

	int SetCurrentAudioByIndex( _IN_ int index );

	int SetAudioFormat( _IN_ EAudioEncodeType encodeType, _IN_ bool isPreferred );

	int GetAudioFormat( _OUT_ EAudioEncodeType& encodeType );

	int GetPreferredAudio( _OUT_ unsigned int& index, _OUT_ TSAudio& audio );

	int GetAVStatus( _OUT_ EAVStatus& avStatus );

	int FlagAudioLock( _OUT_ bool& flag );

	int GetResolution( _OUT_ EResolution& resolution, _OUT_ TSResolution& resolutionInfo );

	int SetResolution( _IN_ EResolution resolution, const _IN_ TSResolution& resolutionInfo );

	int SetServiceLock( _IN_ ELockedMode mode, _IN_ unsigned short startTime, _IN_ unsigned short endTime );

	int GetColorSystem(_OUT_ EChannelColorSystem& Mode , _OUT_ EChannelColor& Val);
	
	int SetColorSystem(_IN_ EChannelColorSystem Mode , _IN_ EChannelColor Val);
	
	int GetSoundSystem(_OUT_ EChannelSoundSystem& Mode , _OUT_ EChannelSound& Val);
	
	int SetSoundSystem(_IN_ EChannelSoundSystem Mode , _IN_ EChannelSound Val);	

	int MuteVideo( _IN_ int onoff);
	
	int MuteAudio( _IN_ int onoff);
	
	int MuteVideo( _IN_ int onoff, _IN_ EMuteMode muteMode );

	int MuteAudio( _IN_ int onoff, _IN_ EMuteMode muteMode );

	int CheckAnalogMTS(_IN_ EMultiSoundMode mode , _OUT_ bool& bCheck);

	int SetAnalogMTS( _IN_ EMultiSoundMode userSetMod , bool isPreview);

	int GetAnalogMTS( _OUT_ EMultiSoundMode& userSetMod );	

	int GetAnalogMTSBySignal( _OUT_ EMultiSoundMode& mode );

	int ChangeAudio( const _IN_ TSAudio& audio, const _IN_ TCServiceId& serviceId );

	int ChangeVideo( const _IN_ TSVideo& video );

	int ReleaseComponent( _IN_ EComponentType compType );

	int ReserveComponent( _IN_ EComponentType compType );

	int SetAudioDescriptionOnOff( _IN_ bool onoff );

	int UnMuteByRatingPin( void );

	int SetAudioDescriptionVolume( _IN_ int volume );

	int GetRatingLockState( _OUT_ bool& lock );

	int GetDigitalDualSound( _OUT_ long& currentMode, _OUT_ long& nextMode );

	int GetDigitalDualSound( _OUT_ ELanguageCode& currLanguage, _OUT_ ELanguageCode& nextLanguage );

	int GetDigitalDualSound( _OUT_ EMultiSoundMode& currMode, _OUT_ EMultiSoundMode& nextMode );

	int SetDigitalDualSound( _IN_ ELanguageCode language );

	int SetDigitalDualSound( _IN_ EMultiSoundMode mode );

	int GetAnalogDualSound( _OUT_ EMultiSoundMode& mode );

	int SetAnalogDualSound( _IN_ EMultiSoundMode mode );

	int ControlDualView( const _IN_ std::vector< unsigned char >& inData, _OUT_ std::vector< unsigned char >& outData );

	int GetDualTvProperty( const _IN_ std::vector< unsigned char >& pluginName, const _IN_ std::vector< unsigned char >& propertyName, _OUT_ std::vector< unsigned char >& value );

	int SetDualTvProperty( const _IN_ std::vector< unsigned char >& pluginName, const _IN_ std::vector< unsigned char >& propertyName, const _IN_ std::vector< unsigned char >& value );

	int SetDualViewType( _IN_ EDualViewType type );

	int ReapplyResolution( void );

	int SetAnalogCleanView( _IN_ bool on );

	int GetDirect2TvProperty( const _IN_ std::vector< unsigned char >& pluginName, const _IN_ std::vector< unsigned char >& propertyName, _OUT_ std::vector< unsigned char >& value );

	int SetStandbyVideoMute( _IN_ bool onoff );

	int GetTVStreamProperty( _IN_ ETVStreamProperty tvstreamProperty, _OUT_ unsigned int& propertyValue );

	int IsPipelineTypeDtv( _OUT_ bool& isPipelineDtv );

	int IsPipelineInPlayingState( _OUT_ bool& isPipelinePlaying );

	int GetRecommendedResolution( _OUT_ EResolution& resolution );
	
	int MuteVideoForCI( _IN_ int onoff );

	int MuteAudioForCI( _IN_ int onoff );

	int CheckAudioLanguageChangeAvailable( _OUT_ bool& bCheck );

private:
	TCAVControlProxy( TVSHandle tvsHandle );
	TCAVControlProxy( const TCAVControlProxy& ){};
	TCAVControlProxy& operator= ( const TCAVControlProxy& ) { return *this; };

	/**
	 * @brief Adds profile related data to proxy method call.
	 * @param [in] helper Proxy marshalling helper.
	 */
	void m_AddInterfaceProfiling( TCMarshallingHelperProxy& helper );

	static std::map<TVSHandle, IAVControl*> m_instances;
	TVSHandle m_tvsHandle;

	static TVServiceAPIConnection* m_pTVSConnection;
	static std::string m_interfaceName;
	static pthread_rwlock_t m_rwlock; // lock for instance creation in multi-thread applications

	std::string m_pName;
	long m_pid;
};
#endif //_AVCONTROLPROXY_H_
