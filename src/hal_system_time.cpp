// components/idf_hals/src/hal_system_time.cpp
#include "hal_system_time.hpp"

#define LOG_LOCAL_LEVEL ESP_LOG_INFO
#include "esp_log.h"

#include <sys/time.h>
#include <time.h>
#include <stdlib.h>

namespace idf_hals {

int HalSystemTime::gettimeofday(struct timeval *tv, struct timezone *tz)
{
    return ::gettimeofday(tv, tz);
}

int HalSystemTime::settimeofday(const struct timeval *tv, const struct timezone *tz)
{
    return ::settimeofday(tv, tz);
}

int HalSystemTime::setenv(const char *name, const char *value, int overwrite)
{
    return ::setenv(name, value, overwrite);
}

void HalSystemTime::tzset()
{
    ::tzset();
}

time_t HalSystemTime::time(time_t *tloc)
{
    return ::time(tloc);
}

struct tm *HalSystemTime::localtime_r(const time_t *timep, struct tm *result)
{
    return ::localtime_r(timep, result);
}

} // namespace idf_hals
