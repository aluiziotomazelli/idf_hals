// components/idf_hals/include/interfaces/i_hal_sleep.hpp
#pragma once

#include "esp_err.h"
#include "esp_sleep.h"

namespace idf_hals {

/**
 * @brief Unified GPIO Wakeup mode
 */
enum class GpioWakeupMode {
    LOW_LEVEL = 0,
    HIGH_LEVEL = 1
};

/**
 * @interface ISleepHAL
 * @brief Interface for ESP32 sleep functionality.
 */
class ISleepHAL
{
public:
    virtual ~ISleepHAL() = default;

    /** @copydoc esp_sleep_disable_wakeup_source() */
    virtual esp_err_t disable_wakeup_source(esp_sleep_source_t source) = 0;

    /** @copydoc esp_sleep_enable_timer_wakeup() */
    virtual esp_err_t enable_timer_wakeup(uint64_t time_in_us) = 0;

    /** @brief Enable GPIO deep sleep wakeup (abstracts ext1/gpio_wakeup differences) */
    virtual esp_err_t deep_sleep_enable_gpio_wakeup(uint64_t gpio_pin_mask, GpioWakeupMode mode) = 0;

    /** @copydoc esp_deep_sleep_start() */
    virtual void deep_sleep_start() = 0;
};

} // namespace idf_hals
