// external/idf_hals/include/hal_gpio.hpp
#pragma once

#include "interfaces/i_hal_gpio.hpp"

namespace idf_hals {

/**
 * @file hal_gpio.hpp
 * @brief Thin wrapper for ESP-IDF GPIO functions.
 */
class GpioHAL : public IGpioHAL
{
public:
    /** @copydoc IGpioHAL::reset_pin() */
    esp_err_t reset_pin(const gpio_num_t pin) override;

    /** @copydoc IGpioHAL::config() */
    esp_err_t config(const gpio_config_t &config) override;

    /** @copydoc IGpioHAL::set_level() */
    esp_err_t set_level(const gpio_num_t pin, const bool level) override;

    /** @copydoc IGpioHAL::get_level() */
    esp_err_t get_level(const gpio_num_t pin, bool &level) override;

    /** @copydoc IGpioHAL::set_direction() */
    esp_err_t set_direction(const gpio_num_t pin, gpio_mode_t mode) override;

    /** @copydoc IGpioHAL::set_drive_capability() */
    esp_err_t set_drive_capability(const gpio_num_t gpio_num, gpio_drive_cap_t strength) override;
};

} // namespace idf_hals
