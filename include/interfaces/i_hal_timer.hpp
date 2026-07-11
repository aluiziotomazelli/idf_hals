// external/idf_hals/include/interfaces/i_hal_timer.hpp
#pragma once

#include <cstdint>

namespace idf_hals {

/**
 * @file i_hal_timer.hpp
 * @brief Interface for system timer services.
 */

/**
 * @interface ITimerHAL
 * @brief Interface for system timer services.
 */
class ITimerHAL
{
public:
    virtual ~ITimerHAL() = default;

    /** @copydoc esp_timer_get_time() */
    virtual int64_t get_time_us() const = 0;
};

} // namespace idf_hals
