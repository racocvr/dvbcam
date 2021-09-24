/** 
 * @file DataControlProxy.h
 * @brief Implements DBus communication, between native and proxy side, for IDataControl use.
 *
 * Copyright 2013 by Samsung Electronics, Inc.,
 * 
 * This software is the confidential and proprietary information
 * of Samsung Electronics, Inc. ("Confidential Information"). You
 * shall not disclose such Confidential Information and shall use
 * it only in accordance with the terms of the license agreement
 * you entered into with Samsung.
 */

#ifndef _DATACONTROLPROXY_H_
#define _DATACONTROLPROXY_H_

#include <string>
#include <pthread.h>
#include <map>
#include "TVServiceDataType.h"

#include "MarshallingHelperProxy.h"
#include "IDataControl.h"

class TCDataControlProxy : public IDataControl
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
	static IDataControl* Instance( TVSHandle tvsHandle );

	/**
	 * @brief Destroys all interface instances.
	 */
	static void Destroy( void );

	int GetCaptionDataMode( _OUT_ ECaptionDataMode& mode );

	int GetDefaultCaptionService( _OUT_ ECaptionService& service );

	int GetCaptionLanguage( _IN_ ECaptionService service, _OUT_ ELanguageCode& language, _OUT_ char& koreanCode );

	int SetCurrentTTX( _IN_ unsigned int index );

	int GetCurrentTTX( _OUT_ ELanguageCode& language, _OUT_ unsigned int& index );

	int SetCurrentHybridSBT( _IN_ unsigned int index );

	int GetCurrentHybridSBT( _OUT_ ELanguageCode& language, _OUT_ unsigned int& index );

	int GetPreferredTTXSubtitle( _OUT_ TSTTX& ttxSubtitle );

	int GetPreferredHybridSBT( _OUT_ ELanguageCode& language, _OUT_ TSHybridSBT& hybridSbt );

	bool GetCurrentISDBText( _IN_ EISDBTextType mode, _OUT_ ELanguageCode& language, _OUT_ unsigned int& index );

	bool SetCurrentISDBText( _IN_ EISDBTextType mode, _IN_ int index );

	bool SetCurrentISDBTextService( _IN_ EISDBTextType mode, _IN_ int compTag );

	int GetSTCCount( _OUT_ unsigned long long& stc );

private:
	TCDataControlProxy( TVSHandle tvsHandle );
	TCDataControlProxy( const TCDataControlProxy& ){};
	TCDataControlProxy& operator= ( const TCDataControlProxy& ) { return *this; };

	/**
	 * @brief Adds profile related data to proxy method call.
	 * @param [in] helper Proxy marshalling helper.
	 */
	void m_AddInterfaceProfiling( TCMarshallingHelperProxy& helper );

	static std::map<TVSHandle, IDataControl*> m_instances;
	TVSHandle m_tvsHandle;

	static TVServiceAPIConnection* m_pTVSConnection;
	static std::string m_interfaceName;
	static pthread_rwlock_t m_rwlock; // lock for instance creation in multi-thread applications
};
#endif //_DATACONTROLPROXY_H_
