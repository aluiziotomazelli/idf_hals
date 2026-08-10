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

esp_err_t GpioHAL::hold_en(gpio_num_t gpio_num)
{
    return gpio_hold_en(gpio_num);
}

esp_err_t GpioHAL::hold_dis(gpio_num_t gpio_num)
{
    return gpio_hold_dis(gpio_num);
}

void GpioHAL::deep_sleep_hold_en()
{
#if SOC_GPIO_SUPPORT_HOLD_IO_IN_DSLP && !SOC_GPIO_SUPPORT_HOLD_SINGLE_IO_IN_DSLP
    gpio_deep_sleep_hold_en();
#endif
}

esp_err_t GpioHAL::install_isr_service(int intr_alloc_flags)
{
    return gpio_install_isr_service(intr_alloc_flags);
}

void GpioHAL::uninstall_isr_service(void)
{
    gpio_uninstall_isr_service();
}

esp_err_t GpioHAL::isr_handler_add(gpio_num_t gpio_num, gpio_isr_t isr_handler, void* args)
{
    return gpio_isr_handler_add(gpio_num, isr_handler, args);
}

esp_err_t GpioHAL::isr_handler_remove(gpio_num_t gpio_num)
{
    return gpio_isr_handler_remove(gpio_num);
}

} // namespace idf_hals
