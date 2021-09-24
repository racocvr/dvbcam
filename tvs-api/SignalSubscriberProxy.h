/** 
 * @file SignalSubscriberProxy.h
 * @brief Implementation of signal subscription
 *
 * Copyright 2013 by Samsung Electronics, Inc.,
 * 
 * This software is the confidential and proprietary information
 * of Samsung Electronics, Inc. ("Confidential Information"). You
 * shall not disclose such Confidential Information and shall use
 * it only in accordance with the terms of the license agreement
 * you entered into with Samsung.
 */
 
#ifndef _SIGNALSUBSCRIBERPROXY_H_
#define _SIGNALSUBSCRIBERPROXY_H_


#include <map>
#include <set>
#include <string>
#include <pthread.h>

#include "ISignalSubscriber.h"
#include "MessageBuffer.h"

class TCSignalSubscriberProxy : public ISignalSubscriber
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
	static ISignalSubscriber* Instance( void );

	/**
	 * @brief Returns an interface object
	 * @param [in] callback callback method that should be called when section comes
	 */
	static void SetCallback( TTSignalCallback callback );

	/** This method shall be removed on 12.09.2014 */
	static void SetCallback( SignalCallback callback );

	/**
	 * @brief Callback when signal comes. This method should be called only by IPCS.
	 * @param [in] signalId event ID
	 * @param [in] messageBuffer raw data buffer
	 */ 
	static void OnSignalCallback( int signalId, TCMessageBuffer& data );

	/**
	 * @brief Destroys all interface instances
	 */
	static void Destroy( void );

	/**
	 * @see base class
	 */
	virtual int Subscribe( ESignalType type, void* pUserData, EProfile profileId, unsigned short screenId );

	/**
	 * @see base class
	 */
	virtual int Unsubscribe( ESignalType type, EProfile profileId, unsigned short screenId );

private:

	struct TSSignalKey
	{
		ESignalType type;
		EProfile profile;
		unsigned short screen;

		TSSignalKey(ESignalType t, EProfile p = DEFAULT_PROFILE_TYPE, unsigned short s = DEFAULT_SCREEN_ID): 
			type( t ), profile( p ), screen( s ) {}

		bool operator < (const TSSignalKey& ref) const
		{
			return	( type != ref.type ) ? ( type < ref.type ) :
					( ( profile != ref.profile ) ? ( profile < ref.profile ) : 
					( ( screen != ref.screen ) ? ( screen < ref.screen ) : false ) );
		}
	};

private:
	TCSignalSubscriberProxy( void );
	TCSignalSubscriberProxy( const TCSignalSubscriberProxy& ){};
	TCSignalSubscriberProxy& operator= ( const TCSignalSubscriberProxy& ) { return *this; };

	static TCSignalSubscriberProxy* m_pInstance;
	static TVServiceAPIConnection* m_pTVSConnection;
	static std::string m_interfaceName;
	static pthread_rwlock_t m_rwlock; // lock for instance creation in multi-thread applications

	static SignalCallback m_depricatedCallback; //<- This member will be removed on 12.09.2014.
	static TTSignalCallback m_callback;

	typedef std::map<TSSignalKey, void*> TTUserDataMap;
	static TTUserDataMap m_userDataMap;

	static pthread_mutex_t m_mutex;

};
#endif //_SIGNALSUBSCRIBERPROXY_H_
