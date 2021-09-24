#ifdef _WIN32
#pragma once
#endif

#ifndef MEASURETIME_H
#define MEASURETIME_H

typedef long long int64; 
typedef unsigned long long uint64;

/* Returns the amount of milliseconds elapsed since the UNIX epoch. Works on both
 * windows and linux. */
uint64 GetTimeMs64();

#endif //MEASURETIME_H
