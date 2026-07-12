// components/idf_hals/include/hal_sleep.hpp
#pragma once

#include "interfaces/i_hal_sleep.hpp"

namespace idf_hals {

/**
 * @class SleepHAL
 * @brief Thin wrapper for ESP-IDF sleep functions.
 */
class SleepHAL : public ISleepHAL
{
public:
    /** @copydoc ISleepHAL::disable_wakeup_source() */
    esp_err_t disable_wakeup_source(esp_sleep_source_t source) override;

    /** @copydoc ISleepHAL::enable_timer_wakeup() */
    esp_err_t enable_timer_wakeup(uint64_t time_in_us) override;

    /** @copydoc ISleepHAL::deep_sleep_enable_gpio_wakeup() */
    esp_err_t deep_sleep_enable_gpio_wakeup(uint64_t gpio_pin_mask, esp_deepsleep_gpio_wake_up_mode_t mode) override;

    /** @copydoc ISleepHAL::deep_sleep_start() */
    void deep_sleep_start() override;
};

} // namespace idf_hals
