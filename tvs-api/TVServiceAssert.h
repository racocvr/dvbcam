/** 
 * @file TVServiceAssert.h
 * @brief Assertion routines
 *
 * Copyright 2014 by Samsung Electronics, Inc.,
 * 
 * This software is the confidential and proprietary information
 * of Samsung Electronics, Inc. ("Confidential Information"). You
 * shall not disclose such Confidential Information and shall use
 * it only in accordance with the terms of the license agreement
 * you entered into with Samsung.
 */

#ifndef _TVSERVICEASSERT_H_
#define _TVSERVICEASSERT_H_

#include <assert.h> //TODO Duende: remove this.


void TCApiPrintMessage(const char * format, ...);


#if defined(_PDEBUG)
	#define PRINT_API_MESSAGE(...) TCApiPrintMessage(__VA_ARGS__)
#else
	#define PRINT_API_MESSAGE(...)
#endif //#if defined(_PDEBUG)


#if defined(_PDEBUG) || defined(_PASSERT)

	#include <cstddef>

	#ifdef WIN32
	#pragma	warning(disable:4002)
	#endif

	//! Abort the program if assertion is false and print diagnostic message.
	void _TCApiAssert(const char* expression, const char* file, unsigned long line, const char *message = NULL);

	//! Abort the program if assertion is false and print diagnostic message
	#define API_ASSERT(expression) if (!(expression)) _TCApiAssert(#expression, __FILE__, __LINE__);

	//! Abort the program if assertion is false and print diagnostic message
	#define API_ASSERT_MSG(expression, message) if (!(expression)) _TCApiAssert(#expression, __FILE__, __LINE__, message);

#else // not _PDEBUG

	#define API_ASSERT(expression);
	#define API_ASSERT_MSG(expression, message);

#endif


#define VOID_API_ASSERT(expression) \
	do \
	{ \
		if (!(expression)) \
		{ \
			API_ASSERT(expression); \
			PRINT_API_MESSAGE("ASSERT!!! - function %s, line %d", __FUNCTION__, __LINE__); \
			return; \
		} \
	} \
	while(0)


#endif //_TVSERVICEASSERT_H_

