#ifndef _VIDEOCONTROLPROXY_H_
#define _VIDEOCONTROLPROXY_H_

#include <string>
#include <pthread.h>
#include <map>
#include "TVServiceDataType.h"

#include "MarshallingHelperProxy.h"
#include "IVideoControl.h"

class TCVideoControlProxy : public IVideoControl
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
	static IVideoControl* Instance( TVSHandle tvsHandle );

	/**
	 * @brief Destroys all interface instances.
	 */
	static void Destroy( void );

	int SetSize( _IN_ int x, _IN_ int y, _IN_ int h, _IN_ int w );

	int GetSize( _OUT_ int& x, _OUT_ int& y, _OUT_ int& h, _OUT_ int& w );

	int SetCropVideo( _IN_ TSRectInfo srcRect, _IN_ TSRectInfo dstRect );

	int GetCropVideoInfo( _OUT_ TSRectInfo& srcRect, _OUT_ TSRectInfo& dstRect );

	int SetZOrder( _IN_ EZOrder order );

	int ExecuteCrossTalkNR( _IN_ bool flagNR );

	int ExecuteCrossTalkNRDemo( _IN_ bool flagNR );

	int GetCrossTalkNRDemo( _OUT_ bool& flagNR );

	int SetStill( _IN_ bool onOff );

	int GetStill( _OUT_ bool& onOff );

	int CheckStill( _OUT_ bool& check );

	int SetAspectRatio(_IN_ EASpectRatioType eASpectRatioType, _IN_ bool bSave = true);

	int SetZoomOffset( _IN_ int dx , _IN_ int dy);

	int GetAspectRatio( _OUT_ EASpectRatioType& eASpectRatioType );

	int SetZoomOffset( _IN_ int dx , _IN_ int dy, _IN_ int width=0, _IN_ int height=0);

	int GetZoomOffset( _OUT_ int& dx, _OUT_ int& dy );

	int SetDefaultSize( void );

	int GetDefaultSize( _OUT_ TSRectInfo& srcRect, _OUT_ TSRectInfo& dstRect );

	int CheckAspectRatio( _IN_ EASpectRatioType aspectRatio, _OUT_ bool& bCheck );

	int GetAFD( _OUT_ int& AFD );

	int SetAFD( _IN_ int AFD, _IN_ bool autoOn );

	int GetAFDGeometryRectSize( _OUT_ int& x, _OUT_ int& y, _OUT_ int& width, _OUT_ int& height );

	int GetXWindow( _OUT_ unsigned long& windowId );

	int SetXWindow( _IN_ unsigned long& windowId );

	int GetScreenMode( _OUT_ EScreenModeData& pictureSize );

	int SetScreenMode( _IN_ EScreenModeData pictureSize, _IN_ bool save );

	int GetDefaultAspectRatio( _OUT_ EASpectRatioType& aspectRatio );

	int SetPictureSize( _IN_ EASpectRatioType aspectRatio, _IN_ bool save );

	int SetPictureSize( _IN_ EPictureSizeType pictureSize, _IN_ bool save );

	int GetPictureSize( _OUT_ EASpectRatioType& aspectRatio );

	int GetPictureSize( _OUT_ EPictureSizeType& pictureSize );

	int ResetPictureSize( void );

	int SetZoomSize( _IN_ int width, _IN_ int height );

	int GetZoomSize( _OUT_ int& width, _OUT_ int& height );

	int SetZoomPosition( _IN_ int x, _IN_ int y );

	int GetZoomPosition( _OUT_ int& x, _OUT_ int& y );

	int SetScreenFitOption( _IN_ EScreenFitOptionType optionType, _IN_ bool save );

	int GetScreenFitOption( _OUT_ EScreenFitOptionType& optionType );

	int CheckPictureSize( _IN_ EPictureSizeType pictureSize, _OUT_ bool& result );

	int CheckScreenFitOption( _IN_ EScreenFitOptionType optionType, _OUT_ bool& bCheck);

	int SetScreenFitPosition( _IN_ int dx, _IN_ int dy );

	int GetScreenFitPosition( _OUT_ int& dx, _OUT_ int& dy );

	int CheckScreenFitPosition( _OUT_ bool& check );

	int CheckPictureSizeSubMenu( _IN_ EPictureSizeSubMenuType submenu, _OUT_ bool& onOff );

	int GetAutoWideOption( _OUT_ bool& onOff );

	int SetAutoWideOption( _IN_ bool onOff, _IN_ bool save );

	int CheckAutoWideSupported( _IN_ EPictureSizeType pictureSizeType, _OUT_ bool& supported );

	int GetPanoramaOption( _OUT_ bool& onOff );

	int SetPanoramaOption( _IN_ bool onOff, _IN_ bool save );

	int SetCoarse( _IN_ int value, _IN_ bool save );

	int GetCoarse( _OUT_ int& value );

	int SetFine( _IN_ int value, _IN_ bool save );

	int GetFine( _OUT_ int& value );

	int SetAutoAdjustment( _IN_ int value, _IN_ bool save );

	int GetAutoAdjustment( _OUT_ int& value );

	int SetPcPosition( _IN_ int horizontal, _IN_ int vertical, _IN_ bool save );

	int GetPcPosition( _OUT_ int& horizontal, _OUT_ int& vertical );

	int ResetPcPicture( void );

private:
	TCVideoControlProxy( TVSHandle tvsHandle );
	TCVideoControlProxy( const TCVideoControlProxy& ){};
	TCVideoControlProxy& operator= ( const TCVideoControlProxy& ) { return *this; };

	/**
	 * @brief Adds profile related data to proxy method call.
	 * @param [in] helper Proxy marshalling helper.
	 */
	void m_AddInterfaceProfiling( TCMarshallingHelperProxy& helper );

	static std::map<TVSHandle, IVideoControl*> m_instances;
	TVSHandle m_tvsHandle;

	static TVServiceAPIConnection* m_pTVSConnection;
	static std::string m_interfaceName;
	static pthread_rwlock_t m_rwlock; // lock for instance creation in multi-thread applications
};
#endif //_VIDEOCONTROLPROXY_H_
