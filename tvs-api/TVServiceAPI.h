/** 
 * @file TVServiceAPI.h
 * @brief Manager of all proxy objects for External API interface
 *
 * Copyright 2013 by Samsung Electronics, Inc.,
 * 
 * This software is the confidential and proprietary information
 * of Samsung Electronics, Inc. ("Confidential Information"). You
 * shall not disclose such Confidential Information and shall use
 * it only in accordance with the terms of the license agreement
 * you entered into with Samsung.
 */
 

#ifndef _SERVICEAPI_H_
#define _SERVICEAPI_H_


#include <string>
#include <pthread.h>

#include "TVServiceDataType.h"

#include "IService.h"
#include "IServiceNavigation.h"
#include "ISourceControl.h"
#include "IPVR.h"
#include "IPVREx.h"
#include "IPlayback.h"
#include "IVideoControl.h"
#include "ISignalSubscriber.h"
#include "IRating.h"
#include "IRatingSystem.h"
#include "IRatingUtil.h"
#include "IPipelineUtility.h"
#include "IEITRawData.h"
#include "IEWBS.h"
#include "IProgramSubscriber.h"
#include "IScanData.h"
#include "IScanControl.h"
#include "IServiceGuide.h"
#include "ISectionSubscriber.h"
#include "ISectionFeeder.h"
#include "IMultiView.h"
#include "IAVControl.h"
#include "IDataControl.h"
#include "IDataSubscriber.h"
#include "IPESDataSubscriber.h"
#include "ISOSpecApp.h"
#include "ISOSpecAppAnalog.h"
#include "ISOSpecControl.h"
#include "IUtil.h"
#include "ITunerControl.h"
#include "IServiceDataAux.h"
#include "IReferenceCount.h"
#include "ICIStatus.h"
#include "IDsm.h"
#include "ISatellite.h"
#include "ISatelliteSettings.h"
#include "ISatelliteControl.h"
#include "IChannelData.h"
#include "IMultiScreen.h"
#include "IConfigApp.h"
#include "ITVPlus.h"
#include "CommonInterfaceDataType.h"

#ifdef _WIN32
#include "ITVServiceWrapperWin32.h"
#endif


class TVServiceAPIConnection;


class TVServiceAPI
{
public:
	/**
	 * @brief Returns interface object for IService
	 * @param [in] profileId profile type
	 * @param [in] screenId ID of a screen
	 * @param [inout] pService interface object
	 * @return int 0 if processed.
	 */
	static int CreateService(IService** pService);
	
	/**
	 * @brief Returns interface object for IServiceNavigation
	 * @param [in] profileId profile type
	 * @param [in] screenId ID of a screen
	 * @param [inout] pSrvNavi interface object
	 * @return int 0 if processed.
	 */
	static int CreateServiceNavigation(EProfile profileId, int screenId, IServiceNavigation** pSrvNavi);

	/**
	 * @brief Returns interface object for ISourceControl
	 * @param [in] profileId profile type
	 * @param [in] screenId ID of a screen
	 * @param [inout] pSrcCtrl interface object
	 * @return int 0 if processed.
	 */
	static int CreateSourceControl(EProfile profileId, int screenId, ISourceControl** pSrcCtrl);

	/**
	 * @brief Returns interface object for IPVR.
	 * @param [in] serviceId ID of the service to be recorded.
	 * @param [in] recordType PVR type.
	 * @param [inout] pPVR Interface object.
	 * @return Returns 0 if object created.
	 */
	static int CreatePVRInstance(TCServiceId& serviceId, ERecordType recordType, IPVR** pPVR);

	/**
	 * @brief Returns interface object for IPVREx.
	 * @param [inout] pPVREx Interface object.
	 * @return Returns 0 if object created.
	 */
	static int CreatePVREx(IPVREx** pPVREx);
	
	/**
	 * @brief Returns interface object for IPlayback.
	 * @param [in] uri Localization of the file which will be played.
	 * @param [inout] pPlayback Interface object.
	 * @return Returns 0 if object created.
	 */
	static int CreatePlaybackInstance(std::string& uri, IPlayback** pPlayback);

	static int CreatePlaybackInstance(TVSHandle tvsHandle, IPlayback** pPlayback);
	
	/**
	 * @brief Returns interface object for IVideoControl
	 * @param [in] profileId profile type
	 * @param [in] screenId ID of a screen
	 * @param [inout] pVideoCtrl interface object
	 * @return int 0 if processed.
	 */
	static int CreateVideoControl(EProfile profileId, int screenId, IVideoControl** pVideoCtrl);

	/**
	 * @brief Returns interface object for ISignalSubscriber.
	 * @param [in] callback Client callback method.
	 * @param [inout] pSignalSubscriber Interface object.
	 * @return Always returns 0.
	 */
	static int CreateSignalSubscriber(TTSignalCallback callback, ISignalSubscriber** pSignalSubscriber);

	/** This method shall be removed on 12.09.2014 */
	static int CreateSignalSubscriber(SignalCallback callback, ISignalSubscriber** pSignalSubscriber);
	
	/** This method shall be removed on 12.09.2014 */
	static int CreateSignalSubscriber(SignalCallback callback, const std::string& applicationName, ISignalSubscriber** pSignalSubscriber);

	/**
	 * @brief Returns interface object for IRating
	 * @param [in] profileId profile type
	 * @param [in] screenId ID of a screen
	 * @param [inout] pRating interface object
	 * @return int 0 if processed.
	 */
	static int CreateRating(EProfile profileId, int screenId, IRating** pRating);

	/**
	 * @brief Returns interface object for IRatingSystem
	 * @param [in] regionIndex index of a Region for Region Rating System
	 * @param [inout] pRatingSystem interface object
	 * @return int 0 if processed.
	 */
	static int CreateRatingSystem(ERRTRegion regionIndex, IRatingSystem** pRatingSystem);

	/**
	 * @brief Returns interface object for IRatingUtil
	 * @param [inout] IRatingUtil interface object
	 * @return int 0 if processed.
	 */
	static int CreateRatingUtil(IRatingUtil** pRatingUtil);

	/**
	 * @brief Returns interface object for IPipelineUtility
	 * @param [in] profileId profile type
	 * @param [in] screenId ID of a screen
	 * @param [inout] pPipelineUtility interface object
	 * @return int 0 if processed.
	 */
	static int CreatePipelineUtility(EProfile profileId, int screenId, IPipelineUtility** pPipelineUtility);

	/**
	 * @brief Returns interface object for IEITRawData
	 * @param [inout] pEITRawData interface object
	 * @return int 0 if processed.
	 */
	static int CreateEITRawDataInstance(IEITRawData** pEITRawData);

	/**
	 * @brief Returns interface object for IEWBS
	 * @param [inout] pEWBS interface object
	 * @return int 0 if processed.
	 */
	static int CreateEWBS(IEWBS** pEWBS);

	/**
	 * @brief Returns interface object for IProgramSubscriber
	 * @param [in] callback program callback method
	 * @param [inout] pProgramSubsciber interface object
	 * @return int 0 if processed.
	 */
	static int CreateProgramSubscriber(ProgramCallback callback, IProgramSubscriber** pProgramSubscriber);
	/**
	 * @brief Returns interface object for IScanData
	 * @param [inout] pScanData interface object
	 * @return int 0 if processed.
	 */
	static int CreateScanData(IScanData** pScanData);

	/**
	 * @brief Returns interface object for IChannelData
	 * @param [in] profileId profile type
	 * @param [in] screenId ID of a screen
	 * @param [inout] pChannelData interface object
	 * @return int 0 if processed.
	 */
	static int CreateChannelData(EProfile profileId, int screenId, IChannelData** pChannelData);

	/**
	 * @brief Returns interface object for IScanControl
	 * @param [inout] pScanControl interface object
	 * @return int 0 if processed.
	 */
	static int CreateScanControl(IScanControl** pScanControl);

	/**
	 * @brief Returns interface object for ISectionSubscriber
	 * @param [in] callback section callback method
	 * @param [in] profileId profile type
	 * @param [in] screenId ID of a screen
	 * @param [inout] pSectionSubsciber interface object
	 * @return int 0 if processed.
	 */
	static int CreateSectionSubscriber(SectionCallback callback, EProfile profileId, int screenId, ISectionSubscriber** pProgramSubscriber);


	/**
	 * @brief Returns interface object for ISectionFeeder
	 * @param [in] profileId Profile type
	 * @param [in] screenId ID of a screen
	 * @param [inout] pSectionFeeder Interface object
	 * @return 0 if processed.
	 */
	static int CreateSectionFeeder(EProfile profileId, int screenId, ISectionFeeder** pSectionFeeder);


	/**
	 * @brief Returns interface object for IServiceGuide
	 * @param [inout] pServiceGuide interface object
	 * @return int 0 if processed.
	 */
	static int CreateServiceGuide(IServiceGuide** pServiceGuide);



	// TODO Duende - to be removed 22.09.2014 
	static IReferenceCount* CreateReferenceCount(void);

	/**
	 * @brief Returns interface object for IReferenceCount
	 * @param [in] profileId profile type
	 * @param [in] screenId ID of a screen
	 * @param [inout] pReferenceCount interface object
	 * @return int 0 if processed.
	 */
	static int CreateReferenceCount(EProfile profileId, int screenId, IReferenceCount** pReferenceCount);
	
	/**
	 * @brief Returns interface object for IMultiView
	 * @param [inout] pMultiView interface object
	 * @return int 0 if processed.
	 */
	static int CreateMultiView(IMultiView** pMultiView);

	static int CreateAVControl(EProfile profileId, int screenId, IAVControl** pAVControl);

	static int CreateDataControl(EProfile profileId, int screenId, IDataControl** pDataControl);

	static int CreateDataSubscriber(EProfile profileId, int screenId, IDataSubscriber** pDataSubscriber);

	static int CreatePESDataSubscriber(EProfile profileId, int screenId, IPESDataSubscriber** pPESDataSubscriber);

	/**
	 * @brief Gets interface object of ISOSpecControl.
	 * @param [out] pSOSpecControl pointer to ISOSpecControl interface pointer, must be not NULL, *pSOSpecControl original value is ignored!
	 * @return 0 if succeeded
	 */
	static int CreateSOSpecControl(ISOSpecControl** pSOSpecControl);

	/**
	 * @brief Gets interface object of ISOSpecApp.
	 * @param [in] profileId profile type
	 * @param [in] screenId ID of a screen
	 * @param[inout] pSOSpecApp interface object.
	 * @return int 0 if processed.
	 */
	static int CreateSOSpecApp(EProfile profileId, int screenId, ISOSpecApp** pSOSpecApp);
	
	static int CreateSOSpecAppAnalog(ISOSpecAppAnalog** pSOSpecAppAnalog);

	static int CreateTunerControl(EProfile profileId, int screenId, ITunerControl** pTunerControl);

	static int CreateUtil(IUtil** pUtil);

	static IServiceDataAux* ServiceDataAux(EProfile profileId, int screenId);

	/**
	 * @brief Returns interface object for ICIStatus
	 * @param [inout] pCIStatus interface object
	 * @return int 0 if processed.
	 */
	static int CreateCIStatus(ICIStatus** pCIStatus);

	/**
	* @brief Returns interface object for IDsm.
	* Only one callback method can be registered.
	* @param callback DSM callback method
	* @param [inout] pDsm IDsm interface object
	* @return 0 if processed.
	*/
	static int CreateDsm(DsmCallback callback, IDsm ** pDsm);

	
	/**
	* @brief Returns interface object for ISatellite.
	* @param [inout] pSat ISatellite interface object
	* @return 0 if processed.
	*/
	static int CreateSatellite(ISatellite** pSat);

	/**
	 * @brief Returns an instance of ISatelliteSettings
	 * @param [inout] pSatSet ISatelliteSettings interface object
	 * @return 0 if processed.
	 */
	static int CreateSatelliteSettings(ISatelliteSettings** pSatSet);

	/**
	 * @brief Returns an instance of ISatelliteControl
	 * @param [inout] pSatCtrl ISatelliteControl interface object
	 * @return 0 if processed.
	 */
	static int CreateSatelliteControl(ISatelliteControl** pSatCtrl);

	/**
	 * @brief Returns an instance of IMultiScreen.
	 * @param [inout] pMultiScreen IMultiScreen interface object
	 * @return 0 if processed.
	 */
	static int CreateMultiScreen(IMultiScreen** pMultiScreen);

	/**
	 * @brief Returns an instance of IConfigApp.
	 * @param [inout] pConfigApp IConfigApp interface object
	 * @return 0 if processed.
	 */
	static int CreateConfigApp(IConfigApp** pConfigApp);

	/**
	 * @brief Returns an instance of ITVPlus.
	 * @param [inout] pTVPlus ITVPlus interface object
	 * @return 0 if processed.
	 */
	static int CreateTVPlus(ITVPlus** pTVPlus);

	/**
	 * @brief Destroys all proxy objects
	 */
	static void Destroy();

	static int DestroyService(void);
	static int DestroyServiceNavigation(void);
	static int DestroySourceControl(void);
	static int DestroyPVRInstance(void);
	static int DestroyPVREx(void);
	static int DestroyPlaybackInstance(void);
	static int DestroyVideoControl(void);
	static int DestroySignalSubscriber(void);
	static int DestroyRating(void);
	static int DestroyRatingSystem(void);
	static int DestroyRatingUtil(void);
	static int DestroyPipelineUtility(void);
	static int DestroyEITRawDataInstance(void);
	static int DestroyEWBS(void);
	static int DestroyProgramSubscriber(void);
	static int DestroyScanData(void);
	static int DestroyScanControl(void);
	static int DestroySectionSubscriber(void);
	static int DestroySectionFeeder(void);
	static int DestroyServiceGuide(void);
	static int DestroyMultiView(void);
	static int DestroyAVControl(void);
	static int DestroyDataControl(void);
	static int DestroyDataSubscriber(void);
	static int DestroyPESDataSubscriber(void);
	static int DestroySOSpecControl(void);
	static int DestroySOSpecApp(void);
	static int DestroySOSpecAppAnalog(void);
	static int DestroyTunerControl(void);
	static int DestroyUtil(void);
	static int DestroyServiceDataAux(void);
	static int DestroyReferenceCount(void);
	static int DestroyCIStatus(void);
	static int DestroyDsm(void);
	static int DestroySatellite(void);
	static int DestroySatelliteSettings(void);
	static int DestroySatelliteControl(void);
	static int DestroyChannelData(void);
	static int DestroyMultiScreen(void);
	static int DestroyConfigApp(void);
	static int DestroyTVPlus(void);
	
protected:

	static TVServiceAPIConnection* m_GetInstance(void);

private:

	static TVServiceAPIConnection* m_pTVSConnection;
	static pthread_rwlock_t m_rwlock; // lock for instance creation

#ifdef _WIN32
public:
	static ITVServiceWrapperWin32* TVServiceWrapperWin32(void);

#endif	

};

#endif // _SERVICEAPI_H_
