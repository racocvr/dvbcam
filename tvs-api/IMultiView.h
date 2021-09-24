/** 
* @file IMultiView.h
* @brief Application interface for multi view.
*
* Copyright 2013 by Samsung Electronics, Inc.,
* 
* This software is the confidential and proprietary information
* of Samsung Electronics, Inc. ("Confidential Information"). You
* shall not disclose such Confidential Information and shall use
* it only in accordance with the terms of the license agreement
* you entered into with Samsung.
*/
#ifndef _IMULTIVIEW_H_
#define _IMULTIVIEW_H_


#include "MarshallingMarks.h"
#include "TVServiceDataType.h"
#include "SourceControlDataType.h"
#include "ServiceData.h"


class IMultiView
{
protected:
	virtual ~IMultiView(){};

public:

	/**
	 * @brief Starts SubView.
	 * @param [in] profile Profile type.
	 * @param [in] source Source type.
	 * @param [in] serviceData Data of a service.
	 * @return Returns 1 if SubView was started, otherwise returns 0.
	 * @return When calling method failed returns -1.
	 *
	 *	@paragraph <Example>
	 * 
	 *	@verbatim
	 *	IMultiView* pMultiView = NULL;
	 *	TVServiceAPI::CreateMultiView(&pMultiView);
	 *	TCServiceData service;
	 *	service.SetServiceId(845524458537987);
	 *	if(pMultiView->StartSubView(PROFILE_TYPE_MAIN, SOURCE_TYPE_TV, service) > 0)
	 *	{
	 *		//Do something when operation successful
	 *	}
	 *	@endverbatim
	 */
	virtual int StartSubView(_IN_ EProfile profile, _IN_ ESource source, _IN_ const TCServiceData& serviceData) = 0;

	/**
	 * @brief Stops SubView.
	 * @param [in] profile Profile type.
	 * @return Returns 1 if SubView was stopped, otherwise returns 0.
	 * @return When calling method failed returns -1.
	 *
	 *	@paragraph <Example>
	 *	
	 *	@verbatim
	 *	IMultiView* pMultiView = NULL;
	 *	TVServiceAPI::CreateMultiView(&pMultiView);
	 *	if(pMultiView->StopSubView(PROFILE_TYPE_MAIN) > 0)
	 *	{
	 *		//Do something when operation successful
	 *	}
	 *	@endverbatim
	 */
	virtual int StopSubView(_IN_ EProfile profile) = 0;
};

#endif // _IMULTIVIEW_H_
