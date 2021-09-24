/** 
 * @file TVServiceDataType.h
 * @brief Common TV service types.
 *
 * Copyright 2013 by Samsung Electronics, Inc.,
 * 
 * This software is the confidential and proprietary information
 * of Samsung Electronics, Inc. ("Confidential Information"). You
 * shall not disclose such Confidential Information and shall use
 * it only in accordance with the terms of the license agreement
 * you entered into with Samsung.
 */


#ifndef _TVSERVICEDATATYPE_H_
#define _TVSERVICEDATATYPE_H_

#include <climits>
#include <string>

#ifndef _WIN32
#include <stdint.h>
#define t_wchar_t uint16_t
#else
#define t_wchar_t unsigned __int16
#endif

typedef std::basic_string<t_wchar_t> t_wstring;

typedef unsigned long long TCServiceId;

#define INVALID_SERVICE_ID ULLONG_MAX

enum EValue
{
	INVALID = -1,
};

enum EProfile
{
	PROFILE_TYPE_UNKNOWN	= 0,
		
	PROFILE_TYPE_MAIN	= 1,
	
	PROFILE_TYPE_PIP	= 101,
	
	PROFILE_TYPE_DUAL	= 201,

	PROFILE_TYPE_RECORD = 301,
	PROFILE_TYPE_ANALYSIS = 401,

	PROFILE_TYPE_MEDIA = 601,		// used for feeding SI sections into TVS

	PROFILE_TYPE_BACKGROUND = 701,

	PROFILE_TYPE_MAX = 65535,
};

#define DEFAULT_PROFILE_TYPE	PROFILE_TYPE_MAIN
#define DEFAULT_SCREEN_ID		0


struct TVSHandle
{
public:
	EProfile profileId; // profile
	unsigned short subId; // desktop

public:

	bool operator< (const TVSHandle& other) const
	{
		if (this->profileId < other.profileId)
		{
			return true;
		}
		else if (this->profileId == other.profileId &&  this->subId < other.subId)
		{
			return true;
		}
		return false;
	}

	bool operator== (const TVSHandle& other) const
	{
		if (this->profileId == other.profileId && this->subId == other.subId)
		{
			return true;
		}
		return false;
	}
	
	operator unsigned long () const
	{
		return GetId();
	}
	
	unsigned long GetId() const
	{
		unsigned long key = (unsigned short)profileId;
		key <<= 16;
		key += (unsigned short)subId;
		return key;
	}

	TVSHandle() : profileId( DEFAULT_PROFILE_TYPE ), subId( DEFAULT_SCREEN_ID ) {};
	TVSHandle(EProfile aProfile, unsigned short aSub) : profileId(aProfile), subId(aSub) {};
	
	TVSHandle(unsigned long handle)
	{
		profileId = (EProfile) ((handle & 0xFFFF0000) >> 16);
		subId = (unsigned short)(handle & 0x0000FFFF);
	}

};

#define TVS_INVALID_ID 0

#endif // _TVSERVICEDATATYPE_H_

