/** 
 * @file IVideoControl.h
 * @brief Application interface for controlling video.
 *
 * Copyright 2013 by Samsung Electronics, Inc.,
 * 
 * This software is the confidential and proprietary information
 * of Samsung Electronics, Inc. ("Confidential Information"). You
 * shall not disclose such Confidential Information and shall use
 * it only in accordance with the terms of the license agreement
 * you entered into with Samsung.
 */


#ifndef _IVIDEOCONTROL_H_
#define _IVIDEOCONTROL_H_


#include <string>

#include "MarshallingMarks.h"
#include "VideoControlDataType.h"

class IVideoControl
{
protected:
	virtual ~IVideoControl(){};

public:

	/**
	 * @brief Sets size of video image (TV stream property).
	 * @param [in] x Position on X axis.
	 * @param [in] y Position on Y axis.
	 * @param [in] h Height of video image.
	 * @param [in] w Width of video image.
	 * @return Returns 1 if setting image position and size succeeded, otherwise returns 0.
	 * @return When calling method failed returns -1.
	 *
	 *	@paragraph <Example>
	 *	This code will set 1024x768 picture attached to (0,0) coordinates for MAIN profile type and screenId = 0.
	 *	
	 *	@verbatim
	 *	IVideoControl* videoCtrl;
	 *	TVServiceAPI::GetVideoControl(PROFILE_TYPE_MAIN, 0, &videoCtrl);
	 *	if(videoCtrl->SetSize(0,0,768,1024) > 0)
	 *	{
	 *		// Picture size and position was successfully set
	 *	}
	 *	@endverbatim
	 */
	virtual int SetSize(_IN_ int x , _IN_ int y , _IN_ int h , _IN_ int w) = 0;


	/**
	 * @brief Gets size of video image (TV stream property).
	 * @param [out] x Position on X axis.
	 * @param [out] y Position on Y axis.
	 * @param [out] h Height of video image.
	 * @param [out] w Width of video image.
	 * @return Returns 1 if setting image position and size succeeded, otherwise returns 0.
	 * @return When calling method failed returns -1.
	 *
	 *	@paragraph <Example>
	 *	This code will set 1024x768 picture attached to (0,0) coordinates for MAIN profile type and screenId = 0.
	 *	
	 *	@verbatim
	 *	IVideoControl* videoCtrl;
	 *	TVServiceAPI::GetVideoControl(PROFILE_TYPE_MAIN, 0, &videoCtrl);
	 * 	 int x , y , h , w;
	 *	if(videoCtrl->GetSize(x,y,h,w) > 0)
	 *	{
	 *		// Picture size and position was successfully set
	 *	}
	 *	@endverbatim
	 */
	virtual int GetSize(_OUT_ int& x , _OUT_ int& y , _OUT_ int& h , _OUT_ int& w) = 0;


	/**
	 * @brief Sets cropping of video image (TV stream property).
	 * @param [in] source rectangle info.
	 * @param [in] destination rectangle info.
	 * @return Returns 1 if setting image position and size succeeded, otherwise returns 0.
	 * @return When calling method failed returns -1.
	 *
	 *	@paragraph <Example>
	 *	This code will set 1024x768 picture attached to (0,0) coordinates for MAIN profile type and screenId = 0.
	 *	
	 *	@verbatim
	 *	IVideoControl* videoCtrl;
	 *	TSRectInfo srcRect;
	 *	TSRectInfo dstRect;
	 *	TVServiceAPI::GetVideoControl(PROFILE_TYPE_MAIN, 0, &videoCtrl);
	 *	if(videoCtrl->SetCropVideo(srcRect, dstRect) > 0)
	 *	{
	 *		// Picture size and position was successfully set
	 *	}
	 *	@endverbatim
	 */
	virtual int SetCropVideo(_IN_ TSRectInfo srcRect , _IN_ TSRectInfo dstRect) = 0;
	

	/**
	 * @brief Gets cropping of video image (TV stream property).
	 * @param [out] source rectangle info.
	 * @param [out] destination rectangle info.
	 * @return Returns 1 if setting image position and size succeeded, otherwise returns 0.
	 * @return When calling method failed returns -1.
	 *
	 *	@paragraph <Example>
	 *	This code will set 1024x768 picture attached to (0,0) coordinates for MAIN profile type and screenId = 0.
	 *	
	 *	@verbatim
	 *	IVideoControl* videoCtrl;
	 *	TSRectInfo srcRect;
	 *	TSRectInfo dstRect;
	 *	TVServiceAPI::GetVideoControl(PROFILE_TYPE_MAIN, 0, &videoCtrl);
	 *	if(videoCtrl->GetCropVideoInfo(srcRect, dstRect) > 0)
	 *	{
	 *		// Picture size and position was successfully set
	 *	}
	 *	@endverbatim
	 */
	virtual int GetCropVideoInfo(_OUT_ TSRectInfo& srcRect , _OUT_ TSRectInfo& dstRect) = 0;


	/**
	 * @brief Sets Z axis order.
	 * @param [in] order Z-axis order.
	 * @return Returns 1 if setting image z-order succeeded, otherwise returns 0.
	 * @return When calling method failed returns -1.
	 */
	virtual int SetZOrder(_IN_ EZOrder order) = 0;

	virtual int ExecuteCrossTalkNR(_IN_ bool flagNR) = 0;

	virtual int ExecuteCrossTalkNRDemo(_IN_ bool flagNR) = 0;

	virtual int GetCrossTalkNRDemo(_OUT_ bool& flagNR) = 0;

	virtual int SetStill(_IN_ bool onOff) = 0;

	virtual int GetStill(_OUT_ bool& onOff) = 0;

	virtual int CheckStill(_OUT_ bool& check) = 0;

	virtual int SetAspectRatio(_IN_ EASpectRatioType eASpectRatioType, _IN_ bool bSave = true) = 0;
	virtual int GetAspectRatio(_OUT_ EASpectRatioType& eASpectRatioType) = 0;

	virtual int SetZoomOffset(_IN_ int dx , _IN_ int dy, _IN_ int width=0, _IN_ int height=0) = 0;
	virtual int GetZoomOffset(_OUT_ int& dx , _OUT_ int& dy) = 0;

	virtual int SetDefaultSize()=0;
	virtual int GetDefaultSize(_OUT_ TSRectInfo& srcRect , _OUT_ TSRectInfo& dstRect)=0;

	/**
	 * @brief Check if aspect ratio type is valid in current signal (TV stream property).
	 * @param [in] aspectRatio Aspect ratio type for checking.
	 * @param [out] bCheck - true : possible, false : impossible.
	 * @return Returns 1.
	 * @return When calling method failed returns -1.
	 *
	 *	@paragraph <Example>
	 *	This code will be check whether ASPECTRATIOTYPE_16_9 can be set for PROFILE_TYPE_MAIN and subId=0.
	 *	 
	 *	@verbatim
	 *	IVideoControl* videoCtrl;
	 *	TVServiceAPI::GetVideoControl(PROFILE_TYPE_MAIN, 0, &videoCtrl);
	 *
	 *	bool bCheck
	 *	if(videoCtrl->CheckAspectRatio(ASPECTRATIOTYPE_16_9, bCheck) > 0)
	 *	{
	 *		if(bCheck)
	 *		{
	 *			// possible aspect ratio type
	 *		}
	 *		else
	 *		{
	 *			// impossible aspect ratio type
	 *		}
	 *	}
	 *	@endverbatim
	 */
	virtual int CheckAspectRatio(_IN_ EASpectRatioType aspectRatio , _OUT_ bool& bCheck) = 0;

	virtual int GetAFD(_OUT_ int& AFD) = 0;

	virtual int SetAFD(_IN_ int AFD, _IN_ bool autoOn) = 0;

	/**
	 * @brief Gets the Geometry rectangle position and size with applied AFD signal 
	 * @param [out] x Position of geometry rectangle on X axis.
	 * @param [out] y Position of geometry rectangle on Y axis.
	 * @param [out] width Width of geometry rectangle.
	 * @param [out] height Height of geometry rectangle.
	 * @return Returns 1 if AFD scaling was calculated successfully, 0 otherwise.
	 * @return When calling method failed returns -1.
	 *
	 *	@paragraph <Example>
	 *	This code will get screen mode.
	 *
	 *	@verbatim
	 *	IVideoControl* pVideoControl;
	 *	TVServiceAPI::CreateVideoControl(PROFILE_TYPE_MAIN, 0, &pVideoControl);
	 *	int x, y, width, height;
	 *
	 *	if(pVideoControl->GetAFDGeometryRectSize(x ,y, width, height) > 0)
	 *	{
	 *		//Video size calculation with AFD rectangle was successful
	 *	}
	 *	@endverbatim
	 */
	virtual int GetAFDGeometryRectSize( _OUT_ int& x, _OUT_ int& y, _OUT_ int& width, _OUT_ int& height ) = 0;

	/**
	 * @brief Get XWindow ID.
	 * @param[out] windowId ID of XWindow
	 * @return Returns 1 if calling method was successful.
	 * @return When calling method failed returns -1.
	 *
	 *	@paragraph <Example>
	 *	This code will get XWindow ID for MAIN profile and screen=0.
	 *	
	 *	@verbatim
	 *	IPipelineUtility* pPipelineUtility;
	 *	TVServiceAPI::CreatePipelineUtility(PROFILE_TYPE_MAIN, 0, pPipelineUtility);
	 *
	 *	unsigned long windowId;
	 *	if(pPipelineUtility->GetXWindow(windowId) > 0)
	 *	{
	 *		//use windiowId value
	 *	}
	 *	@endverbatim
	 */
	virtual int GetXWindow(_OUT_ unsigned long& windowId) = 0;

	/**
	 * @brief Set XWindow ID.
	 * @param[in] windowId ID of XWindow
	 * @return Returns 1 if calling method was successful.
	 * @return When calling method failed returns -1.
	 */
	virtual int SetXWindow(_IN_ unsigned long& windowId) = 0;

	/**
	 * @brief Gets screen mode.
	 * @param [out] pictureSize Picture size.
	 * @return Returns 1 if information was acquired, otherwise returns 0.
	 * @return When calling method failed returns -1.
	 *
	 *	@paragraph <Example>
	 *	This code will get screen mode.
	 *	
	 *	@verbatim
	 *	IVideoControl* videoControl;
	 *	TVServiceAPI::CreateVideoControl(PROFILE_TYPE_MAIN, 0, &videoControl);
	 *	EScreenModeData pictureSize = SCREENMODE_16_9;
	 *	if(videoControl->GetScreenMode(pictureSize) > 0)
	 *	{
	 *		//Obtained pictureSize
	 *	}
	 *	@endverbatim
	 */
	virtual int GetScreenMode(_OUT_ EScreenModeData& pictureSize) = 0;

	/**
	 * @brief Sets screen mode.
	 * @param [in] pictureSize Picture size.
	 * @param [in] save Specify if new screen mode should be save in DB.
	 * @return Returns 1 if picture size was successfully set, otherwise returns 0.
	 * @return When calling method failed returns -1.
	 *
	 *	@paragraph <Example>
	 *	This code will set screen mode (also save new value into DB).
	 *	
	 *	@verbatim
	 *	IVideoControl* videoControl;
	 *	TVServiceAPI::CreateVideoControl(PROFILE_TYPE_MAIN, 0, &videoControl);
	 *	EScreenModeData pictureSize = SCREENMODE_16_9;
	 *	if(videoControl->SetScreenMode(pictureSize) > 0)
	 *	{
	 *		//Successfully set screen mode.
	 *	}
	 *	@endverbatim
	 */
	virtual int SetScreenMode(_IN_ EScreenModeData pictureSize, _IN_ bool save = true) = 0;

	/**
	 * @brief Gets default aspect ratio.
	 * @param [out] aspectRatio Aspect ratio.
	 * @return Returns 1 if information was acquired.
	 * @return When calling method failed returns -1.
	 *
	 *	@paragraph <Example>
	 *	This code will get default aspect ratio.
	 *	
	 *	@verbatim
	 *	IVideoControl* videoControl;
	 *	TVServiceAPI::CreateVideoControl(PROFILE_TYPE_MAIN, 0, &videoControl);
	 *	EASpectRatioType aspectRatio;
	 *	if(videoControl->GetDefaultAspectRatio(aspectRatio) > 0)
	 *	{
	 *		//Obtained default aspect ratio
	 *	}
	 *	@endverbatim
	 */
	virtual int GetDefaultAspectRatio(_OUT_ EASpectRatioType& aspectRatio) = 0;

	/** DEPRECATED */
	// TODO Duende - to be removed after 07.11.2014
	virtual int SetPictureSize(_IN_ EASpectRatioType aspectRatio, _IN_ bool save = true) = 0;

	/**
	 * @brief Sets video picture size.
	 * @param [in] pictureSize Picture size type (16:9 / 4:3 / Zoom / Custom).
	 * @param [in] save True(selected picture size) or false(just preview picture size).
	 * @return Returns 1 if successfully set, otherwise returns 0.
	 * @return When calling method failed returns -1.
	 *
	 *	@paragraph <Example>
	 *	This code will set picture size to PICTURESIZETYPE_16_9.
	 *	
	 *	@verbatim
	 *	IVideoControl* videoControl;
	 *	TVServiceAPI::CreateVideoControl(PROFILE_TYPE_MAIN, 0, &videoControl);
	 *	if(videoControl->SetPictureSize(PICTURESIZETYPE_16_9) > 0)
	 *	{
	 *		//Successfully set picture size
	 *	}
	 *	@endverbatim
	 */
	virtual int SetPictureSize(_IN_ EPictureSizeType pictureSize, _IN_ bool save = true) = 0;

	/** DEPRECATED */
	// TODO Duende - to be removed after 07.11.2014
	virtual int GetPictureSize(_OUT_ EASpectRatioType& aspectRatio) = 0;

	/** 
	 * @brief Gets selected video picture size.
	 * @param [out] pictureSize Selected picture size.
	 * @return Returns 1 if successfully get, otherwise returns 0.
	 * @return When calling method failed returns -1.
	 *
	 *	@paragraph <Example>
	 *	This code will get picture size.
	 *	
	 *	@verbatim
	 *	IVideoControl* videoControl;
	 *	TVServiceAPI::CreateVideoControl(PROFILE_TYPE_MAIN, 0, &videoControl);
	 *	EASpectRatioType pictureSize;
	 *	if(videoControl->GetPictureSize(pictureSize) > 0)
	 *	{
	 *		//Obtained picture size
	 *	}
	 *	@endverbatim
	*/
	virtual int GetPictureSize(_OUT_ EPictureSizeType& pictureSize) = 0;

	/**
	 * @brief Resets video picture size (sets initial value).
	 * @return Returns 1 if successfully reset, otherwise returns 0.
	 * @return When calling method failed returns -1.
	 *
	 *	@paragraph <Example>
	 *	This code will set picture size to initial value.
	 *	
	 *	@verbatim
	 *	IVideoControl* videoControl;
	 *	TVServiceAPI::CreateVideoControl(PROFILE_TYPE_MAIN, 0, &videoControl);
	 *	if(videoControl->ResetPictureSize() > 0)
	 *	{
	 *		//Successfully reset picture size
	 *	}
	 *	@endverbatim
	 */
	virtual int ResetPictureSize( void ) = 0;

 	/**
	 * @brief Changes zoom size.
	 * @param [in] width Zoom size width.
	 * @param [in] height Zoom size height.
	 * @return Returns 1 if successfully set, otherwise returns 0.
	 * @return When calling method failed returns -1.
	 *
	 *	@paragraph <Example>
	 *	This code will set zoom size.
	 *	
	 *	@verbatim
	 *	IVideoControl* videoControl;
	 *	TVServiceAPI::CreateVideoControl(PROFILE_TYPE_MAIN, 0, &videoControl);
	 *	if(videoControl->SetZoomSize(1024,768) > 0)
	 *	{
	 *		//Successfully set zoom size
	 *	}
	 *	@endverbatim
	*/
	virtual int SetZoomSize(_IN_ int width, _IN_ int height) = 0;

	/**
	 * @brief Gets zoom size.
	 * @param [out] width Zoom size width.
	 * @param [out] height Zoom size height.
	 * @return Returns 1 if successfully get, otherwise returns 0.
	 * @return When calling method failed returns -1.
	 *
	 *	@paragraph <Example>
	 *	This code will get zoom size.
	 *	
	 *	@verbatim
	 *	IVideoControl* videoControl;
	 *	TVServiceAPI::CreateVideoControl(PROFILE_TYPE_MAIN, 0, &videoControl);
	 *	int width;
	 *	int height;
	 *	if(videoControl->GetZoomSize(width, height) > 0)
	 *	{
	 *		//Obtained zoom size
	 *	}
	 *	@endverbatim
	 */
	virtual int GetZoomSize(_OUT_ int& width, _OUT_ int& height) = 0;

	/**
	 * @brief Changes zoom position.
	 * @param [in] x X-axis zoom position.
	 * @param [in] y Y-axis zoom position.
	 * @return Returns 1 if successfully set, otherwise returns 0.
	 * @return When calling method failed returns -1.
	 *
	 *	@paragraph <Example>
	 *	This code will set zoom position.
	 *	
	 *	@verbatim
	 *	IVideoControl* videoControl;
	 *	TVServiceAPI::CreateVideoControl(PROFILE_TYPE_MAIN, 0, &videoControl);
	 *	if(videoControl->SetZoomPosition(100,200) > 0)
	 *	{
	 *		//Successfully set zoom position
	 *	}
	 *	@endverbatim
	 */
	virtual int SetZoomPosition(_IN_ int x, _IN_ int y) = 0;

	/**
	 * @brief Gets zoom position.
	 * @param [in] x X-axis zoom position.
	 * @param [in] y Y-axis zoom position.
	 * @return Returns 1 if successfully get, otherwise returns 0.
	 * @return When calling method failed returns -1.
	 *
	 *	@paragraph <Example>
	 *	This code will get zoom position.
	 *	
	 *	@verbatim
	 *	IVideoControl* videoControl;
	 *	TVServiceAPI::CreateVideoControl(PROFILE_TYPE_MAIN, 0, &videoControl);
	 *	int x;
	 *	int y;
	 *	if(videoControl->GetZoomPosition(x, y) > 0)
	 *	{
	 *		//Obtained zoom position
	 *	}
	 *	@endverbatim
	 */
	virtual int GetZoomPosition(_OUT_ int& x, _OUT_ int& y) = 0;

	/**
	 * @brief Sets ScreenFit option.
	 * @param [in] onOff true - on / false - off.
	 * @param [in] save Specify if new screen fit option should be save in DB.
	 * @return Returns 1 if successfully set, otherwise returns 0.
	 * @return When calling method failed returns -1.
	 *
	 *	@paragraph <Example>
	 *	This code will set ScreenFit option to "ON" (also save new value into DB).
	 *	
	 *	@verbatim
	 *	IVideoControl* videoControl;
	 *	TVServiceAPI::CreateVideoControl(PROFILE_TYPE_MAIN, 0, &videoControl);
	 *	if(videoControl->SetScreenFitOption(true) > 0)
	 *	{
	 *		//Successfully set ScreenFit option
	 *	}
	 *	@endverbatim
	 */
	virtual int SetScreenFitOption(_IN_ EScreenFitOptionType optionType, _IN_ bool save = true) = 0;

	/**
	 * @brief Gets ScreenFit option.
	 * @param [out] onOff True - on / false - off.
	 * @return Returns 1 if successfully get, otherwise returns 0.
	 * @return When calling method failed returns -1.
	 *
	 *	@paragraph <Example>
	 *	This code will get ScreenFit option.
	 *	
	 *	@verbatim
	 *	IVideoControl* videoControl;
	 *	TVServiceAPI::CreateVideoControl(PROFILE_TYPE_MAIN, 0, &videoControl);
	 *	bool onOff;
	 *	if(videoControl->GetScreenFitOption(onOff) > 0)
	 *	{
	 *		//Obtained ScreenFit option
	 *	}
	 *	@endverbatim
	 */
	virtual int GetScreenFitOption(_OUT_ EScreenFitOptionType& optionType) = 0;

	// TODO Duende - to be removed after 6.09.2014
	int CheckSize(_IN_ EASpectRatioType eAspectRatioType , _OUT_ bool& bCheck)
	{
		return 0;
	}

	/** 
	 * @brief  Check if picture size can be set.
	 * @param [in] pictureSize Picture size to be checked.
	 * @param [out] result Result of check.
	 * @return Returns 1 if picture size was checked, 0 otherwise.
	 * @return When calling method failed returns -1.
	 *
	 * @paragraph <Example>
	 * This code will check whether PICTURESIZETYPE_16_9 can be set for PROFILE_TYPE_MAIN and subId=0.
	 *
	 *	@verbatim
	 *	IVideoControl* videoCtrl;
	 *	TVServiceAPI::GetVideoControl(PROFILE_TYPE_MAIN, 0, &videoCtrl);
	 *
	 *	bool bCheck = false;
	 *	if(videoCtrl->CheckPictureSize(PICTURESIZETYPE_16_9, bCheck) > 0)
	 *	{
	 *		if(bCheck)
	 *		{
	 *			// possible aspect ratio type
	 *		}
	 *		else
	 *		{
	 *			// impossible aspect ratio type
	 *		}
	 *	}
	 *	@endverbatim
	 */
	virtual int CheckPictureSize(_IN_ EPictureSizeType pictureSize, _OUT_ bool &result) = 0;

	/**
	 * @brief Checks if screen fit option can be set.
	 * @param [in] pictureSize Picture size.
	 * @param [out] result States whether screen fit option is valid.
	 * @return Returns 1 if picture size was checked, 0 otherwise.
	 * @return When calling method failed returns -1.
	 *
	 * @paragraph <Example>
	 * This code will check whether SCREENFITOPTION_ON can be set for PROFILE_TYPE_MAIN and subId=0.
	 *
	 *	@verbatim
	 *	IVideoControl* videoCtrl;
	 *	TVServiceAPI::GetVideoControl(PROFILE_TYPE_MAIN, 0, &videoCtrl);
	 *
	 *	bool bCheck = false;
	 *	if(videoCtrl->CheckScreenFitOption(SCREENFITOPTION_ON, bCheck) > 0)
	 *	{
	 *		if(bCheck)
	 *		{
	 *			// possible aspect ratio type
	 *		}
	 *		else
	 *		{
	 *			// impossible aspect ratio type
	 *		}
	 *	}
	 *	@endverbatim
	 */
	virtual int CheckScreenFitOption(_IN_  EScreenFitOptionType optionType, _OUT_ bool& bCheck) = 0;

	// TODO Duende - to be removed after 07.11.2014
	virtual int SetScreenFitPosition(_IN_ int dx, _IN_ int dy) = 0;

	// TODO Duende - to be removed after 07.11.2014
	virtual int GetScreenFitPosition(_OUT_ int& dx , _OUT_ int& dy) = 0;

	/**
	 * @brief Checks if ScreenFit position is movable.
	 * @param [out] check States whether ScreenFit position is valid.
	 * @return Returns 1 if screen fit position was obtained, 0 otherwise.
	 * @return When calling method failed returns -1.
	 *
	 * @paragraph <Example>
	 * This code will check ScreenFit position.
	 *
	 *	@verbatim
	 *	IVideoControl* videoCtrl;
	 *	TVServiceAPI::GetVideoControl(PROFILE_TYPE_MAIN, 0, &videoCtrl);
	 *
	 *	bool check = false;
	 *	if(1 == videoCtrl->CheckScreenFitPosition(check))
	 *	{
	 *		// ScreenFit position is movable.
	 *	}
	 *	@endverbatim
	 */
	virtual int CheckScreenFitPosition(_OUT_ bool& check) = 0;
	
	/**
	 * @brief Checks if Picture Size sub menu is enabled.
	 * @param [in] submenu Type of Picture Size sub menu.
	 * @param [out] onOff Determines if sub menu is enabled.
	 * @return Returns 1 if value was obtained, 0 otherwise.
	 * @return When calling method failed returns -1.
	 *
	 * @paragraph <Example>
	 * This code will check if Picture Size sub menu for P_SIZESUB_AUTOWIDE is enabled.
	 *
	 *	@verbatim
	 *	IVideoControl* videoCtrl;
	 *	TVServiceAPI::GetVideoControl(PROFILE_TYPE_MAIN, 0, &videoCtrl);
	 *
	 *	bool check = false;
	 *	if(1 == videoCtrl->CheckPictureSizeSubMenu(P_SIZESUB_AUTOWIDE, check))
	 *	{
	 *		if(check)
	 *		{
	 *			// sub menu is enabled
	 *		}
	 *	}
	 *	@endverbatim
	 */
	virtual int CheckPictureSizeSubMenu(_IN_ EPictureSizeSubMenuType submenu, _OUT_ bool& onOff) = 0;

	/**
	 * @brief Checks if Auto Wide option is turned on/off.
	 * @param [out] onOff Determines if Auto Wide is turned on/off.
	 * @return Returns 1 if value was obtained, 0 otherwise.
	 * @return When calling method failed returns -1.
	 *
	 * @paragraph <Example>
	 * This code will check if Auto Wide is turned on.
	 *
	 *	@verbatim
	 *	IVideoControl* videoCtrl;
	 *	TVServiceAPI::GetVideoControl(PROFILE_TYPE_MAIN, 0, &videoCtrl);
	 *
	 *	bool check = false;
	 *	if(1 == videoCtrl->GetAutoWideOption(check))
	 *	{
	 *		if(check)
	 *		{
	 *			// Auto Wide is enabled.
	 *		}
	 *	}
	 *	@endverbatim
	 */
	virtual int GetAutoWideOption(_OUT_ bool& onOff) = 0;

	/**
	 * @brief Enables/Disables Auto Wide option.
	 * @param [in] onOff Determines if Auto Wide is turned on/off.
	 * @param [in] save Specify if auto wide option  should be save in DB.
	 * @return Returns 1 if value was set successfully, 0 otherwise.
	 * @return When calling method failed returns -1.
	 *
	 * @paragraph <Example>
	 * This code will set Auto Wide to enabled (also save new value into DB).
	 *
	 *	@verbatim
	 *	IVideoControl* videoCtrl;
	 *	TVServiceAPI::GetVideoControl(PROFILE_TYPE_MAIN, 0, &videoCtrl);
	 *
	 *	if(1 == videoCtrl->SetAutoWideOption(true))
	 *	{
	 *		// value set successfully
	 *	}
	 *	@endverbatim
	 */
	virtual int SetAutoWideOption(_IN_ bool onOff, _IN_ bool save = true) = 0;

	/**
	 * @brief Checks whether Auto Wide menu item is supported.
	 * @param [in] pictureSize Picture size.
	 * @param [out] result States whether Auto Wide menu item is supported.
	 * @return Returns 1 if picture size was checked, 0 otherwise.
	 * @return When calling method failed returns -1.
	 *
	 * @paragraph <Example>
	 * This code will check whether Auto Wide menu is supported for PROFILE_TYPE_MAIN and subId=0.
	 *
	 *	@verbatim
	 *	IVideoControl* videoCtrl;
	 *	TVServiceAPI::CreateVideoControl(PROFILE_TYPE_MAIN, 0, &videoCtrl);
	 *
	 *	bool bCheck = false;
	 *	if(videoCtrl->CheckAutoWideSupported(SCREENFITOPTION_ON, bCheck) > 0)
	 *	{
	 *		if(bCheck)
	 *		{
	 *			// auto wide menu item is supported
	 *		}
	 *		else
	 *		{
	 *			// auto wide menu item is not supported
	 *		}
	 *	}
	 *	@endverbatim
	 */
	virtual int CheckAutoWideSupported(_IN_ EPictureSizeType pictureSizeType, _OUT_ bool& supported) = 0;

	/**
	 * @brief Checks if Panorama option is turned on/off.
	 * @param [out] onOff Determines if Panorama is turned on/off.
	 * @return Returns 1 if value was obtained, 0 otherwise.
	 * @return When calling method failed returns -1.
	 *
	 * @paragraph <Example>
	 * This code will check if Panorama is turned on.
	 *
	 *	@verbatim
	 *	IVideoControl* videoCtrl;
	 *	TVServiceAPI::GetVideoControl(PROFILE_TYPE_MAIN, 0, &videoCtrl);
	 *
	 *	bool check = false;
	 *	if(1 == videoCtrl->GetPanoramaOption(check))
	 *	{
	 *		if(check)
	 *		{
	 *			// Panorama is enabled.
	 *		}
	 *	}
	 *	@endverbatim
	 */
	virtual int GetPanoramaOption(_OUT_ bool& onOff) = 0;

	/**
	 * @brief Enables/Disables Panorama option.
	 * @param [in] onOff Determines if Panorama is turned on/off.
	 * @param [in] save Specify if Panorama option should be saved in DB.
	 * @return Returns 1 if value was set successfully, 0 otherwise.
	 * @return When calling method failed returns -1.
	 *
	 * @paragraph <Example>
	 * This code will set Panorama to enabled (also save new value into DB).
	 *
	 *	@verbatim
	 *	IVideoControl* videoCtrl;
	 *	TVServiceAPI::GetVideoControl(PROFILE_TYPE_MAIN, 0, &videoCtrl);
	 *
	 *	if(1 == videoCtrl->SetPanoramaOption(true))
	 *	{
	 *		// value set successfully
	 *	}
	 *	@endverbatim
	 */
	virtual int SetPanoramaOption(_IN_ bool onOff, _IN_ bool save = true) = 0;

	/**
	 * @brief Set coarse option for PC Source
	 * @param [in] value coarse value to set
	 * @param [in] save Specify if coarse value should be saved in DB.
	 * @return Returns 1 if value was set successfully, 0 otherwise.
	 * @return When calling method failed returns -1.
	 *
	 * @paragraph <Example>
	 *
	 *	@verbatim
	 *	IVideoControl* videoCtrl;
	 *	TVServiceAPI::GetVideoControl(PROFILE_TYPE_MAIN, 0, &videoCtrl);
	 *
	 *	if(1 == videoCtrl->SetCoarse(1))
	 *	{
	 *		// value set successfully
	 *	}
	 *	@endverbatim
	 */
	virtual int SetCoarse(_IN_ int value, _IN_ bool save = true) = 0;

	/**
	 * @brief Get coarse option for PC Source
	 * @param [out] value current coarse value
	 * @return Returns 1 if value was set successfully, 0 otherwise.
	 * @return When calling method failed returns -1.
	 *
	 * @paragraph <Example>
	 *
	 *	@verbatim
	 *	IVideoControl* videoCtrl;
	 *	TVServiceAPI::GetVideoControl(PROFILE_TYPE_MAIN, 0, &videoCtrl);
	 *
	 *	int value = 0;
	 *	if(1 == videoCtrl->GetCoarse(value))
	 *	{
	 *		// value set successfully
	 *	}
	 *	@endverbatim
	 */
	virtual int GetCoarse(_OUT_ int& value) = 0;

	/**
	 * @brief Set fine option for PC Source
	 * @param [in] value fine value to set
	 * @param [in] save Specify if fine value should be saved in DB.
	 * @return Returns 1 if value was set successfully, 0 otherwise.
	 * @return When calling method failed returns -1.
	 *
	 * @paragraph <Example>
	 *
	 *	@verbatim
	 *	IVideoControl* videoCtrl;
	 *	TVServiceAPI::GetVideoControl(PROFILE_TYPE_MAIN, 0, &videoCtrl);
	 *
	 *	if(1 == videoCtrl->SetFine(1))
	 *	{
	 *		// value set successfully
	 *	}
	 *	@endverbatim
	 */
	virtual int SetFine(_IN_ int value, _IN_ bool save = true) = 0;

	/**
	 * @brief Get find for PC Source
	 * @param [out] value current fine value
	 * @return Returns 1 if value was set successfully, 0 otherwise.
	 * @return When calling method failed returns -1.
	 *
	 * @paragraph <Example>
	 *
	 *	@verbatim
	 *	IVideoControl* videoCtrl;
	 *	TVServiceAPI::GetVideoControl(PROFILE_TYPE_MAIN, 0, &videoCtrl);
	 *
	 *	int value = 0;
	 *	if(1 == videoCtrl->GetFine(value))
	 *	{
	 *		// value set successfully
	 *	}
	 *	@endverbatim
	 */
	virtual int GetFine(_OUT_ int& value) = 0;

	/**
	 * @brief Set auto adjustment for PC Source
	 * @param [in] value auto adjustment value to set
	 * @param [in] save Specify if auto adjustment value should be saved in DB.
	 * @return Returns 1 if value was set successfully, 0 otherwise.
	 * @return When calling method failed returns -1.
	 *
	 * @paragraph <Example>
	 *
	 *	@verbatim
	 *	IVideoControl* videoCtrl;
	 *	TVServiceAPI::GetVideoControl(PROFILE_TYPE_MAIN, 0, &videoCtrl);
	 *
	 *	if(1 == videoCtrl->SetAutoAdjustment(1))
	 *	{
	 *		// value set successfully
	 *	}
	 *	@endverbatim
	 */
	virtual int SetAutoAdjustment(_IN_ int value, _IN_ bool save = true) = 0;

	/**
	 * @brief Get auto adjustment for PC Source
	 * @param [out] value current auto adjustment value
	 * @return Returns 1 if value was set successfully, 0 otherwise.
	 * @return When calling method failed returns -1.
	 *
	 * @paragraph <Example>
	 *
	 *	@verbatim
	 *	IVideoControl* videoCtrl;
	 *	TVServiceAPI::GetVideoControl(PROFILE_TYPE_MAIN, 0, &videoCtrl);
	 *
	 *	int value = 0;
	 *	if(1 == videoCtrl->GetAutoAdjustment(value))
	 *	{
	 *		// value set successfully
	 *	}
	 *	@endverbatim
	 */
	virtual int GetAutoAdjustment(_OUT_ int& value) = 0;

	/**
	 * @brief Set position for PC Source
	 * @param [in] horizontal Value of horizontal position to set
	 * @param [in] vertical Value of vertical position to set
	 * @param [in] save Specify if auto adjustment value should be saved in DB.
	 * @return Returns 1 if value was set successfully, 0 otherwise.
	 * @return When calling method failed returns -1.
	 *
	 * @paragraph <Example>
	 *
	 *	@verbatim
	 *	IVideoControl* videoCtrl;
	 *	TVServiceAPI::GetVideoControl(PROFILE_TYPE_MAIN, 0, &videoCtrl);
	 *
	 *	if(1 == videoCtrl->SetPcPosition(10, 15))
	 *	{
	 *		// value set successfully
	 *	}
	 *	@endverbatim
	 */
	virtual int SetPcPosition(_IN_ int horizontal, _IN_ int vertical, _IN_ bool save = true) = 0;

	/**
	 * @brief Get current position for PC Source
	 * @param [out] horizontal current value of horizontal position
	 * @param [out] vertical current value of vertical position
	 * @return Returns 1 if value was set successfully, 0 otherwise.
	 * @return When calling method failed returns -1.
	 *
	 * @paragraph <Example>
	 *
	 *	@verbatim
	 *	IVideoControl* videoCtrl;
	 *	TVServiceAPI::GetVideoControl(PROFILE_TYPE_MAIN, 0, &videoCtrl);
	 *
	 *	int horizontal = 0;
	 *  int vertical = 0;
	 *	if(1 == videoCtrl->GetPcPosition(horizontal, vertical))
	 *	{
	 *		// value set successfully
	 *	}
	 *	@endverbatim
	 */
	virtual int GetPcPosition(_OUT_ int& horizontal, _OUT_ int& vertical) = 0;

	/**
	 * @brief Resets picture parameters related to PC source (sets initial value).
	 * @return Returns 1 if successfully reset, otherwise returns 0.
	 * @return When calling method failed returns -1.
	 *
	 *	@paragraph <Example>
	 *	This code will set PC picture parameters to initial value.
	 *	
	 *	@verbatim
	 *	IVideoControl* videoControl;
	 *	TVServiceAPI::CreateVideoControl(PROFILE_TYPE_MAIN, 0, &videoControl);
	 *	if(videoControl->ResetPcPicture() > 0)
	 *	{
	 *		//Successfully reset
	 *	}
	 *	@endverbatim
	 */
	virtual int ResetPcPicture() = 0;
	
};
#endif // _IVIDEOCONTROL_H_

