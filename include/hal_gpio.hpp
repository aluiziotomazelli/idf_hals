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
    esp_err_t reset_pin(gpio_num_t pin) override;

    /** @copydoc IGpioHAL::config() */
    esp_err_t config(const gpio_config_t* config) override;

    /** @copydoc IGpioHAL::set_level() */
    esp_err_t set_level(gpio_num_t pin, uint32_t level) override;

    /** @copydoc IGpioHAL::get_level() */
    int get_level(gpio_num_t pin) override;

    /** @copydoc IGpioHAL::set_direction() */
    esp_err_t set_direction(gpio_num_t pin, gpio_mode_t mode) override;

    /** @copydoc IGpioHAL::set_drive_capability() */
    esp_err_t set_drive_capability(gpio_num_t gpio_num, gpio_drive_cap_t strength) override;

    /** @copydoc IGpioHAL::hold_en() */
    esp_err_t hold_en(gpio_num_t gpio_num) override;

    /** @copydoc IGpioHAL::hold_dis() */
    esp_err_t hold_dis(gpio_num_t gpio_num) override;

    /** @copydoc IGpioHAL::deep_sleep_hold_en() */
    void deep_sleep_hold_en() override;

    /** @copydoc IGpioHAL::install_isr_service() */
    esp_err_t install_isr_service(int intr_alloc_flags) override;

    /** @copydoc IGpioHAL::uninstall_isr_service() */
    virtual void uninstall_isr_service(void) override;

    /** @copydoc IGpioHAL::isr_handler_add() */
    esp_err_t isr_handler_add(gpio_num_t gpio_num, gpio_isr_t isr_handler, void* args) override;

    /** @copydoc IGpioHAL::isr_handler_remove() */
    esp_err_t isr_handler_remove(gpio_num_t gpio_num) override;
};

} // namespace idf_hals
