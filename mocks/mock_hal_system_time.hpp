// components/idf_hals/mocks/mock_hal_system_time.hpp
#pragma once

#include "interfaces/i_hal_system_time.hpp"
#include <gmock/gmock.h>

namespace idf_hals {

/**
 * @class MockHalSystemTime
 * @brief GMock implementation of IHalSystemTime for unit testing.
 */
class MockHalSystemTime : public IHalSystemTime
{
public:
    MOCK_METHOD(int, gettimeofday, (struct timeval *tv, struct timezone *tz), (override));
    MOCK_METHOD(int, settimeofday, (const struct timeval *tv, const struct timezone *tz), (override));
    MOCK_METHOD(int, setenv, (const char *name, const char *value, int overwrite), (override));
    MOCK_METHOD(void, tzset, (), (override));
    MOCK_METHOD(time_t, time, (time_t *tloc), (override));
    MOCK_METHOD(struct tm*, localtime_r, (const time_t *timep, struct tm *result), (override));
};

} // namespace idf_hals
