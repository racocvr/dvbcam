#ifndef _PVRPROXY_H_
#define _PVRPROXY_H_

#include <string>
#include <pthread.h>
#include <map>

#include "MarshallingHelperProxy.h"
#include "IPVR.h"
#include "TVServiceDataType.h"


class TCPVRProxy : public IPVR
{
public:

	/**
	 * @brief Sets Dbus connection for communication with TVS.
	 * @param [in] pTVSConnection TVService IPC connection.
	 */
	static void InitTVSConnection(TVServiceAPIConnection* pTVSConnection);

	/**
	 * @brief Returns an interface object.
	 * @param [in] serviceId ID of service.
	 * @param [in] recordType Type of a record.
	 * @return Pointer to interface implementation.
	 */
	static IPVR* Instance( TCServiceId& serviceId, ERecordType recordType );

	/**
	 * @brief Destroys all interface instances.
	 */
	static void DestroyInstances( void );

	int Destroy( void );

	/**
	 * @brief Controls recording with given command.
	 * @param [in] inSize Recording control command size.
	 * @param [in] pInData Recording control command.
	 * @param [inout] outSize Size of output data.
	 * @param [inout] pOutData Result of the control command.
	 * @return Result >= 0 if successfully called TVService, result<0 if error occured.
	 */
	int ControlRecording( _IN_ _ARRAY_SIZE_1_ unsigned int inSize, _IN_ _ARRAY_1_ unsigned char* pInData, _INOUT_ _ARRAY_SIZE_2_ unsigned int& outSize, _INOUT_ _ARRAY_2_ unsigned char* pOutData );

	/**
	 * @brief Get ProfileId & subId of this pvr control interface. ( This is for multi recording )
	 *		This interface need not dbus because proxy object has tvshandle.
	 * @param [out] profileId 
	 * @param [out] subId
	 * @return Result >= 0 if successfully called TVService, result<0 if error occured.
	*/
	int GetId(_OUT_ EProfile& profileId ,_OUT_ unsigned short& subId);

private:
	TCPVRProxy( TCServiceId& serviceId, ERecordType recordType );
	TCPVRProxy( const TCPVRProxy& ){};
	TCPVRProxy& operator= ( const TCPVRProxy& ) { return *this; };

	/**
	 * @brief Adds profile related data to proxy method call.
	 * @param [in] helper Proxy marshalling helper.
	 */
	void m_AddInterfaceProfiling( TCMarshallingHelperProxy& helper );
	
	void m_PipelineActivate(void);

	static std::map<std::pair<TCServiceId, ERecordType>, IPVR*> m_instances;
	TCServiceId m_serviceId;
	ERecordType m_recordType;
	int m_recordId;

	static TVServiceAPIConnection* m_pTVSConnection;
	static std::string m_interfaceName;
	static pthread_rwlock_t m_rwlock; // lock for instance creation in multi-thread applications
};
#endif //_PVRPROXY_H_
