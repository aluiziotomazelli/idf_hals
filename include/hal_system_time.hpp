// components/idf_hals/include/hal_system_time.hpp
#pragma once

#include "interfaces/i_hal_system_time.hpp"

namespace idf_hals {

/**
 * @class HalSystemTime
 * @brief Concrete wrapper for POSIX system time functions.
 */
class HalSystemTime : public IHalSystemTime
{
public:
    int gettimeofday(struct timeval *tv, struct timezone *tz) override;
    int settimeofday(const struct timeval *tv, const struct timezone *tz) override;
    int setenv(const char *name, const char *value, int overwrite) override;
    void tzset() override;
    time_t time(time_t *tloc) override;
    struct tm *localtime_r(const time_t *timep, struct tm *result) override;
};

} // namespace idf_hals
