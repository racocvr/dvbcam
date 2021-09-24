/** 
 * @file ISOSpecAppAnalog.h
 * @brief Application interface for managing country specs for analog.
 *
 * Copyright 2013 by Samsung Electronics, Inc.,
 * 
 * This software is the confidential and proprietary information
 * of Samsung Electronics, Inc. ("Confidential Information"). You
 * shall not disclose such Confidential Information and shall use
 * it only in accordance with the terms of the license agreement
 * you entered into with Samsung.
 */


#ifndef _ISOSPECAPPANALOG_H_
#define _ISOSPECAPPANALOG_H_


#include "MarshallingMarks.h"
#include "SOSpecTag.h"

class ISOSpecAppAnalog
{
protected:
	virtual ~ISOSpecAppAnalog(){};

public:

	/**
	 * @brief Gets value of given tag.
	 * @param[in] tag Tag for which value should be obtained.
	 * @param[out] value Value obtained.
	*/ 
	template<typename T>
	bool Get(ESOSpecAnalogTag tag, T &value)
	{
		return t_Get(tag, (int&)value);
	}

protected:
	/**
	 * @brief Performs actual Get operation: gets value of given tag.
	 * @param[in] tag Tag for which value will be obtained.
	 * @param[out] value Obtained value.
	 */
	virtual bool t_Get(_IN_ ESOSpecAnalogTag tag, _OUT_ int &value) = 0;
};

/**
 * @brief Get template specialization for bool values. Gets bool value of given tag.
 * @remark This specialization was introduced to overcome the issue of stack corruption when casting from int to bool.
 * @param[in] tag Tag for which value should be obtained.
 * @param[out] value Value obtained.
 */
template<>
inline bool ISOSpecAppAnalog::Get(ESOSpecAnalogTag tag, bool &value)
{
	int result = 0;
	bool ret = false;
	ret = t_Get(tag, result);
	value = result == 1;
	return ret;
}

#endif // _ISOSPECAPPANALOG_H_

