/** 
 * @file BinderManager.h
 * @brief Manages and provides binder.
 *
 * Copyright 2014 by Samsung Electronics, Inc.,
 * 
 * This software is the confidential and proprietary information
 * of Samsung Electronics, Inc. ("Confidential Information"). You
 * shall not disclose such Confidential Information and shall use
 * it only in accordance with the terms of the license agreement
 * you entered into with Samsung.
 */

#ifndef _BINDERMANAGER_H_
#define _BINDERMANAGER_H_

#include "BinderExt.h"

class TCBinderManager
{
private:
	static IBinder* m_pBinder;
	static TCBinderExt m_binderDefault;

protected:
	TCBinderManager() { }

public:
	/**
	 * @brief Provides binder instance.
	 * @remark If binder was not set prior to calling of this method, a default one will be returned.
	 * @return Binder instance.
	 */
	static IBinder* Instance();

	/**
	 * @brief Sets binder instance.
	 * @param [in] config Configuration object to be used for obtaining data.
	 */
	static void SetBinder(IBinder* config);
};

#endif //_BINDERMANAGER_H_