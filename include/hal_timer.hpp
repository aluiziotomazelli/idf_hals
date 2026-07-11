// external/idf_hals/include/hal_timer.hpp
#pragma once

#include "interfaces/i_hal_timer.hpp"

namespace idf_hals {

/**
 * @file hal_timer.hpp
 * @brief Thin wrapper for ESP-IDF timer functions.
 */
class TimerHAL : public ITimerHAL
{
public:
    /** @copydoc ITimerHAL::get_time_us() */
    int64_t get_time_us() const override;
};

} // namespace idf_hals
