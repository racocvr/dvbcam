/** 
 * @file IConfigApp.h
 * @brief Application interface for receiving base TV Service configuration information.
 *
 * Copyright 2015 by Samsung Electronics, Inc.,
 * 
 * This software is the confidential and proprietary information
 * of Samsung Electronics, Inc. ("Confidential Information"). You
 * shall not disclose such Confidential Information and shall use
 * it only in accordance with the terms of the license agreement
 * you entered into with Samsung.
 */

#ifndef _ICONFIGAPP_H_
#define _ICONFIGAPP_H_

#include "MarshallingMarks.h"
#include "ConfigAppTag.h"

class IConfigApp
{
protected:
	virtual ~IConfigApp(){};

public:

	/**
	 * @brief Gets value of given tag.
	 * @param[in] tag Tag for which value should be obtained.
	 * @param[out] value Value obtained.
	 * @return True if value was obtained successfully, false otherwise.
	*/ 
	template<typename T>
	bool Get(EConfigAppTag tag, T &value)
	{
		// temporal variable is created to prevent stack corruption with memory overwriting.
		// if there was no temporal variable call Get<unsigned short>(TAG, value) will result in overriding two additional bytes of memory we have no rights to.
		int temp = 0;
		bool res = t_Get(tag, temp);
		value = static_cast<T>(temp);
		return res;
	}

protected:
	/**
	 * @brief Performs actual Get operation: gets value of given tag.
	 * @param[in] tag Tag for which value will be obtained.
	 * @param[out] value Obtained value.
	 * @return True if value was obtained successfully, false otherwise.
	 */
	virtual bool t_Get(_IN_ EConfigAppTag tag, _OUT_ int &value) = 0;
};

#endif // _ICONFIGAPP_H_
