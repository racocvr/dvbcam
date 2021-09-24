/** 
 * @file ISOSpecApp.h
 * @brief Application interface for managing country specs.
 *
 * Copyright 2013 by Samsung Electronics, Inc.,
 * 
 * This software is the confidential and proprietary information
 * of Samsung Electronics, Inc. ("Confidential Information"). You
 * shall not disclose such Confidential Information and shall use
 * it only in accordance with the terms of the license agreement
 * you entered into with Samsung.
 */


#ifndef _ISOSPECAPP_H_
#define _ISOSPECAPP_H_


#include "MarshallingMarks.h"
#include "SOSpecDataType.h"
#include "SOSpecTag.h"
#include "AVControlDataType.h"
#include "UtilDataType.h"
#include "ServiceDataType.h"
#include "DataControlDataType.h"

class ISOSpecApp
{
protected:
	virtual ~ISOSpecApp() {};

public:

	/**
	 * @brief Gets value of given tag.
	 * @param[in] tag Tag for which value should be obtained.
	 * @param[out] value Value obtained.
	*/ 
	template<typename T>
	bool Get(ESOSpecTag tag, T &value)
	{
		// temporal variable is created to prevent stack corruption with memory overwriting.
		// if there was no temporal variable call Get<unsigned short>(TAG, value) will result in overriding two additional bytes of memory we have no rights to.
		int temp = 0;
		bool res = t_Get(tag, temp);
		value = static_cast<T>(temp);
		return res;
	}

	/**
	 * @brief Sets value of given tag.
	 * @param[in] tag Tag for which value should be set.
	 * @param[in] value Value to be set.
	 */
	template<typename T>
	bool Set(ESOSpecTag tag, T value)
	{
		return t_Set(tag, (int)value);	
	}

	/**
	 * @brief Sets primary/override spec.
	 * @remark If primary spec is already set, it won't be overriden.
	 * @param[in] specCode Spec to be set as primary.
	 * @return When calling method fails due to dbus malfunction returns -1, otherwise returns 1.
	 **/
	virtual int SetPrimarySpec(_IN_ ESpecCode specCode) = 0;

	/**
	 * @brief Unsets primary/override spec.
	 * @remark If primary spec was not set, nothing will happen.
	 * @return When calling method fails due to dbus malfunction returns -1, otherwise returns 1.
	 */
	virtual int UnsetPrimarySpec(void) = 0;
	
	virtual int GetCurrentDataServiceType(_OUT_ EDataServiceSupportType& dataType) = 0;

protected:

	/**
	 * @brief Performs actual Get operation: gets value of given tag.
	 * @param[in] tag Tag for which value will be obtained.
	 * @param[out] value Obtained value.
	 */
	virtual bool t_Get(_IN_ ESOSpecTag tag, _OUT_ int &value) = 0;

	/**
	 * @brief Performs actual Set operation: sets value for given tag.
	 * @remark Sets value only for first spec.
	 * @param[in] tag Tag for which value should be set.
	 * @param[in] value Value to be set.
	 */
	virtual bool t_Set(_IN_ ESOSpecTag tag, _IN_ int value) = 0;

};
#endif // _ISOSPECAPP_H_
