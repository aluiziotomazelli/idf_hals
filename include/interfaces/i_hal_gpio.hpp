// external/idf_hals/include/interfaces/i_hal_gpio.hpp
#pragma once

#include "esp_err.h"
#include "driver/gpio.h"

namespace idf_hals {

/**
 * @file i_hal_gpio.hpp
 * @brief Interface for GPIO hardware abstraction.
 */

/**
 * @interface IGpioHAL
 * @brief Interface for GPIO hardware abstraction.
 */
class IGpioHAL
{
public:
    virtual ~IGpioHAL() = default;

    /** @copydoc gpio_reset_pin() */
    virtual esp_err_t reset_pin(gpio_num_t pin) = 0;

    /** @copydoc gpio_config() */
    virtual esp_err_t config(const gpio_config_t* config) = 0;

    /** @copydoc gpio_set_level() */
    virtual esp_err_t set_level(gpio_num_t pin, uint32_t level) = 0;

    /** @copydoc gpio_get_level() */
    virtual int get_level(gpio_num_t pin) = 0;

    /** @copydoc gpio_set_direction() */
    virtual esp_err_t set_direction(gpio_num_t pin, gpio_mode_t mode) = 0;

    /** @copydoc gpio_set_drive_capability() */
    virtual esp_err_t set_drive_capability(gpio_num_t gpio_num, gpio_drive_cap_t strength) = 0;
};

} // namespace idf_hals
