// external/idf_hals/src/hal_gpio.cpp
#include "driver/gpio.h"

#include "hal_gpio.hpp"

namespace idf_hals {

esp_err_t GpioHAL::reset_pin(gpio_num_t pin)
{
    return gpio_reset_pin(pin);
}

esp_err_t GpioHAL::config(const gpio_config_t* config)
{
    return gpio_config(config);
}

esp_err_t GpioHAL::set_level(gpio_num_t pin, uint32_t level)
{
    return gpio_set_level(pin, level);
}

int GpioHAL::get_level(gpio_num_t pin)
{
    return gpio_get_level(pin);
}

esp_err_t GpioHAL::set_direction(gpio_num_t pin, gpio_mode_t mode)
{
    return gpio_set_direction(pin, mode);
}

esp_err_t GpioHAL::set_drive_capability(gpio_num_t gpio_num, gpio_drive_cap_t strength)
{
    return gpio_set_drive_capability(gpio_num, strength);
}

} // namespace idf_hals
