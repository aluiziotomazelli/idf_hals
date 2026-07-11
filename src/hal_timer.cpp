// external/idf_hals/src/hal_timer.cpp
#include "esp_timer.h"

#include "hal_timer.hpp"

namespace idf_hals {

int64_t TimerHAL::get_time_us() const
{
    return esp_timer_get_time();
}

} // namespace idf_hals
