// external/idf_hals/include/interfaces/hal_rtc_gpio.hpp
#pragma once

#include "interfaces/i_hal_rtc_gpio.hpp"

namespace idf_hals {

/**
 * @file hal_rtc_gpio.hpp
 *
 * @brief Wrapper for RTC GPIO hardware abstraction.
 */
class RtcGpioHAL : public IRtcGpioHAL
{
public:
    /** @copydoc rtc_gpio_init(gpio_num_t gpio_num) */
    esp_err_t gpio_init(gpio_num_t gpio_num) override;

    /** @copydoc rtc_gpio_deinit(gpio_num_t gpio_num) */
    esp_err_t gpio_deinit(gpio_num_t gpio_num) override;

    /** @copydoc rtc_gpio_get_level(gpio_num_t gpio_num) */
    uint32_t gpio_get_level(gpio_num_t gpio_num) override;

    /** @copydoc rtc_gpio_set_level(gpio_num_t gpio_num, uint32_t level) */
    esp_err_t gpio_set_level(gpio_num_t gpio_num, uint32_t level) override;

    /** @copydoc rtc_gpio_set_direction(gpio_num_t gpio_num, rtc_gpio_mode_t mode) */
    esp_err_t gpio_set_direction(gpio_num_t gpio_num, rtc_gpio_mode_t mode) override;

    /** @copydoc rtc_gpio_pullup_en(gpio_num_t gpio_num) */
    esp_err_t gpio_pullup_en(gpio_num_t gpio_num) override;

    /** @copydoc rtc_gpio_pulldown_en(gpio_num_t gpio_num) */
    esp_err_t gpio_pulldown_en(gpio_num_t gpio_num) override;

    /** @copydoc rtc_gpio_pullup_dis(gpio_num_t gpio_num) */
    esp_err_t gpio_pullup_dis(gpio_num_t gpio_num) override;

    /** @copydoc rtc_gpio_pulldown_dis(gpio_num_t gpio_num) */
    esp_err_t gpio_pulldown_dis(gpio_num_t gpio_num) override;

    /** @copydoc rtc_gpio_set_drive_capability(gpio_num_t gpio_num, gpio_drive_cap_t strength) */
    esp_err_t gpio_set_drive_capability(gpio_num_t gpio_num, gpio_drive_cap_t strength) override;

    /** @copydoc rtc_gpio_hold_dis(gpio_num_t gpio_num) */
    esp_err_t gpio_hold_dis(gpio_num_t gpio_num) override;

    /** @copydoc rtc_gpio_hold_en(gpio_num_t gpio_num) */
    esp_err_t gpio_hold_en(gpio_num_t gpio_num) override;

    /** @copydoc rtc_gpio_wakeup_enable(gpio_num_t gpio_num, gpio_int_type_t intr_type) */
    esp_err_t gpio_wakeup_enable(gpio_num_t gpio_num, gpio_int_type_t intr_type) override;

    /** @copydoc rtc_gpio_wakeup_disable(gpio_num_t gpio_num) */
    esp_err_t gpio_wakeup_disable(gpio_num_t gpio_num) override;
};

} // namespace idf_hals