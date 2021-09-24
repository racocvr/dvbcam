#ifndef _DEBUGTVSAPI_H_
#define _DEBUGTVSAPI_H_

#include "TVServiceAssert.h"

#ifdef _WIN32
#define DEFAULT_LOG(...)
#define ERROR_API(...)
#define DEBUG_API(...)
#define INFO_API(...)
#else
#include <dlog.h>

#undef LOG_TAG
#define LOG_TAG "TVS_API"

#undef __MODULE__
#define __MODULE__ "TVS_API"

#define DEFAULT_LOG(...) SLOGW(__VA_ARGS__)
#define ERROR_API(...) LOGE(__VA_ARGS__)
#define DEBUG_API(...) LOGD(__VA_ARGS__)
#define INFO_API(...) LOGI(__VA_ARGS__)
#endif


#ifndef FORCED_LOG
#define FORCED_LOG(...) SLOGD(__VA_ARGS__)
#endif //FORCED_LOG

#ifndef FORCEE_LOG
#define FORCEE_LOG(...) SLOGE(__VA_ARGS__)
#endif //FORCEE_LOG

#endif //_DEBUGTVSAPI_H_
