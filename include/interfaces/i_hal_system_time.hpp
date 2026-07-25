// components/idf_hals/include/interfaces/i_hal_system_time.hpp
#pragma once

#include <sys/time.h>
#include <time.h>

namespace idf_hals {

/**
 * @interface IHalSystemTime
 * @brief Interface for POSIX system time functionality.
 */
class IHalSystemTime
{
public:
    virtual ~IHalSystemTime() = default;

    /** @copydoc gettimeofday() */
    virtual int gettimeofday(struct timeval *tv, struct timezone *tz) = 0;

    /** @copydoc settimeofday() */
    virtual int settimeofday(const struct timeval *tv, const struct timezone *tz) = 0;

    /** @copydoc setenv() */
    virtual int setenv(const char *name, const char *value, int overwrite) = 0;

    /** @copydoc tzset() */
    virtual void tzset() = 0;

    /** @copydoc time() */
    virtual time_t time(time_t *tloc) = 0;

    /** @copydoc localtime_r() */
    virtual struct tm *localtime_r(const time_t *timep, struct tm *result) = 0;
};

} // namespace idf_hals
