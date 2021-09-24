/** 
 * @file IReferenceCount.h
 * @brief Application interface for controlling source.
 *
 * Copyright 2013 by Samsung Electronics, Inc.,
 * 
 * This software is the confidential and proprietary information
 * of Samsung Electronics, Inc. ("Confidential Information"). You
 * shall not disclose such Confidential Information and shall use
 * it only in accordance with the terms of the license agreement
 * you entered into with Samsung.
 */


#ifndef _IREFERENCECOUNT_H_
#define _IREFERENCECOUNT_H_

#include "MarshallingMarks.h"

class IReferenceCount
{
protected:
	virtual ~IReferenceCount(){};

public:

	/**
	 * @brief Increases reference count.
	 * @remark After initialized by booting, the count is 1.
	 * @remarks THIS IS ASYNCHRONOUS METHOD, it does not wait for TVS reply
	 * @return Returns 1 if reference count was increased successfully, otherwise returns 0.
	 * @return When calling method failed returns -1.
	 *
	 *	@paragraph <Example>
	 *	
	 *	@verbatim
	 *	IReferenceCount* referenceCount;
	 *	referenceCount = TVServiceAPI::CreateReferenceCount();
	 *	if(referenceCount->IncreaseCount() > 0)
	 *	{
	 *		//Success
	 *	}
	 *	@endverbatim
	 */
	virtual int IncreaseCount(void) = 0;

	/**
	 * @brief Decreases reference count, if the count is zero and then the source is disconnected.
	 * @remarks THIS IS ASYNCHRONOUS METHOD, it does not wait for TVS reply
	 * @return Returns 1 if reference count was decreased successfully, otherwise returns 0.
	 * @return When calling method failed returns -1.
	 *
	 *	@paragraph <Example>
	 *	
	 *	@verbatim
	 *	IReferenceCount* referenceCount;
	 *	referenceCount = TVServiceAPI::CreateReferenceCount();
	 *	if(referenceCount->DecreaseCount() > 0)
	 *	{
	 *		//Success
	 *	}
	 *	@endverbatim
	 */
	virtual int DecreaseCount(void) = 0;

	/**
	 * @brief Decreases all reference counts that current process has, it is recomended to call when the process is destroyed.
	 * @remarks THIS IS ASYNCHRONOUS METHOD, it does not wait for TVS reply
	 * @return Returns 1 if reference count was cleared successfully, otherwise returns 0.
	 * @return When calling method failed returns -1.
	 *
	 *	@paragraph <Example>
	 *	
	 *	@verbatim
	 *	IReferenceCount* referenceCount;
	 *	referenceCount = TVServiceAPI::CreateReferenceCount();
	 *	if(referenceCount->ClearReferenceCount() > 0)
	 *	{
	 *		//Success
	 *	}
	 *	@endverbatim
	 */

	virtual int ClearReferenceCount(void) = 0;

	/**
	 * @remarks THIS IS ASYNCHRONOUS METHOD, it does not wait for TVS reply
	 */
	// do not use this API directly
	virtual int AddReferenceCount(void) = 0;

	/**
	 * @remarks THIS IS ASYNCHRONOUS METHOD, it does not wait for TVS reply
	 */
	// do not use this API directly
	virtual int ReleaseReferenceCount(void) = 0;

	/**
	 * @brief Gets value of reference count
	 * @param[out] value of reference count
	 * @return When calling method failed returns -1.
	 *
	 *	@paragraph <Example>
	 *
	 *	@verbatim
	 *	IReferenceCount* referenceCount;
	 *	referenceCount = TVServiceAPI::CreateReferenceCount();
	 *	int referenceCount = 0;
	 *	if(referenceCount->GetReferenceCount(referenceCount) > 0)
	 *	{
	 *		//Success
	 *	}
	 *	@endverbatim
	 */
	virtual int GetReferenceCount(_OUT_ int& value) = 0;

	/**
	 * @brief Adds reference count ready.
	 * @remarks THIS IS ASYNCHRONOUS METHOD, it does not wait for TVS reply
	 * @return Returns 1 if reference count added successfully, otherwise returns 0.
	 * @return When calling method failed returns -1.
	 *
	 *	@paragraph <Example>
	 *	
	 *	@verbatim
	 *	IReferenceCount* referenceCount;
	 *	referenceCount = TVServiceAPI::CreateReferenceCount();
	 *	if(referenceCount->AddReferenceCountReady() > 0)
	 *	{
	 *		//Success
	 *	}
	 *	@endverbatim
	 */
	virtual int AddReferenceCountReady(void) = 0;

	/**
	 * @brief Releases reference count ready.
	 * @remarks THIS IS ASYNCHRONOUS METHOD, it does not wait for TVS reply
	 * @return Returns 1 if reference count released successfully, otherwise returns 0.
	 * @return When calling method failed returns -1.
	 *
	 *	@paragraph <Example>
	 *	
	 *	@verbatim
	 *	IReferenceCount* referenceCount;
	 *	referenceCount = TVServiceAPI::CreateReferenceCount();
	 *	if(referenceCount->ReleaseReferenceCountReady() > 0)
	 *	{
	 *		//Success
	 *	}
	 *	@endverbatim
	 */
	virtual int ReleaseReferenceCountReady(void) = 0;

	/**
	 * @brief Gets value of reference count ready
	 * @param[out] value of reference count ready
	 * @return When calling method failed returns -1.
	 *
	 *	@paragraph <Example>
	 *
	 *	@verbatim
	 *	IReferenceCount* referenceCount;
	 *	referenceCount = TVServiceAPI::CreateReferenceCount();
	 *	int referenceCountReady = 0;
	 *	if(referenceCount->GetReferenceCountReady(referenceCountReady) > 0)
	 *	{
	 *		//Success
	 *	}
	 *	@endverbatim
	 */

	virtual int GetReferenceCountReady(_OUT_ int& value) = 0;

	/**
	 * @brief Gets value of reference count help
	 * @param[out] value of reference count help
	 * @return When calling method failed returns -1.
	 *
	 *	@paragraph <Example>
	 *
	 *	@verbatim
	 *	IReferenceCount* referenceCount;
	 *	referenceCount = TVServiceAPI::CreateReferenceCount();
	 *	int referenceCountHelp = 0;
	 *	if(referenceCount->GetReferenceCountHelp(referenceCountHelp) > 0)
	 *	{
	 *		//Success
	 *	}
	 *	@endverbatim
	 */
	virtual int GetReferenceCountHelp(_OUT_ int& value) = 0;
};

#endif // _IREFERENCECOUNT_H_

