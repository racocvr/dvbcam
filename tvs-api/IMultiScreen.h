/** 
 * @file IMultiScreen.h
 * @brief Application interface for controlling Multi Screen.
 *
 * Copyright 2014 by Samsung Electronics, Inc.,
 * 
 * This software is the confidential and proprietary information
 * of Samsung Electronics, Inc. ("Confidential Information"). You
 * shall not disclose such Confidential Information and shall use
 * it only in accordance with the terms of the license agreement
 * you entered into with Samsung.
 */


#ifndef _IMULTISCREEN_H_
#define _IMULTISCREEN_H_


#include <string>

#include "MarshallingMarks.h"
#include "MultiScreenDataType.h"

class IMultiScreen
{
protected:
	virtual ~IMultiScreen(){};

public:

	/**
	 * @brief Gets id of slot's screen.
	 * @param [in] slot Slot identifier.
	 * @param [out] slot Screen identifier.
	 * @return Returns 1 if screen identifier was obtained.
	 * @return When calling method failed returns -1.
	 *
	 * @paragraph <Example>
	 * This code will get screen identifier for slot = 0.
	 *
	 *	@verbatim
	 *	IMultiScreen* pMultiScreen = NULL;
	 *	TVServiceAPI::GetMultiScreen(&pMultiScreen);
	 *
	 *	int screenId = 0;
	 *	if(1 == pMultiScreen->GetScreenId(0, screenId))
	 *	{
	 *		// Screen id obtained successfully.
	 *	}
	 *	@endverbatim
	 */
	virtual int GetScreenId(_IN_ int slot, _OUT_ int& screenId) = 0;

	/**
	 * @brief Sets id of slot's screen.
	 * @param [in] slot Slot identifier.
	 * @param [in] slot Screen identifier
	 * @return Returns 1 if screen identifier was set.
	 * @return When calling method failed returns -1.
	 *
	 * @paragraph <Example>
	 * This code will set screen identifier to 0 for slot = 0.
	 *
	 *	@verbatim
	 *	IMultiScreen* pMultiScreen = NULL;
	 *	TVServiceAPI::GetMultiScreen(&pMultiScreen);
	 *
	 *	int screenId = 0;
	 *	if(1 == pMultiScreen->SetScreenId(0, screenId))
	 *	{
	 *		// Screen id set successfully.
	 *	}
	 *	@endverbatim
	 */
	virtual int SetScreenId(_IN_ int slot, _IN_ int screenId) = 0;

	/**
	 * @brief Start multi-screen mode
	 * @param [in] mode Multi-screen start mode.
	 * @return Returns 1 if started successfully.
	 * @return When calling method failed returns -1.
	 *
	 * @paragraph <Example>
	 * This code will start multi-screen mode MULTI_SCREEN_MODE_LEFT_ONLY.
	 *
	 *	@verbatim
	 *	IMultiScreen* pMultiScreen = NULL;
	 *	TVServiceAPI::CreateMultiScreen(&pMultiScreen);
	 *
	 *	if( 1 == pMultiScreen->StartMultiScreenMode(MULTI_SCREEN_MODE_LEFT_ONLY) )
	 *	{
	 *		// Multi-screen mode started.
	 *	}
	 *	@endverbatim
	 */
	virtual int StartMultiScreenMode(_IN_ EMultiScreenMode mode) = 0;

	/**
	 * @brief Stop multi-screen mode
	 * @param [in] slot Slot number that is currently focused. Main source should be set with the source of focused slot.
	 * @return Returns 1 if stopped successfully.
	 * @return When calling method failed returns -1.
	 *
	 * @paragraph <Example>
	 * This code will stop multi-screen mode for slot = 0.
	 *
	 *	@verbatim
	 *	IMultiScreen* pMultiScreen = NULL;
	 *	TVServiceAPI::CreateMultiScreen(&pMultiScreen);
	 *
	 *	if( 1 == pMultiScreen->StopMultiScreenMode(0) )
	 *	{
	 *		// Multi-screen mode stopped.
	 *	}
	 *	@endverbatim
	 */
	virtual int StopMultiScreenMode(_IN_ int slot) = 0;
};

#endif // _IMULTISCREEN_H_
