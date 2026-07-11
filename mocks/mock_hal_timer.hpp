// external/idf_hals/mocks/mock_hal_timer.hpp
#pragma once

#include "gmock/gmock.h"
#include "interfaces/i_hal_timer.hpp"

namespace idf_hals {

class MockTimerHAL : public ITimerHAL
{
public:
    MOCK_METHOD(int64_t, get_time_us, (), (const, override));
};

} // namespace idf_hals
