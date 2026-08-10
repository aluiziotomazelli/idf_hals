// external/idf_hals/include/interfaces/i_hal_rtc_gpio.hpp
#pragma once

#include "esp_err.h"

#if __has_include("driver/rtc_io.h")
#include "driver/rtc_io.h"
#else
#include "driver/gpio.h"
typedef int rtc_gpio_mode_t;
#endif

namespace idf_hals {

/**
 * @file i_hal_rtc_gpio.hpp
 *
 * @brief Interface for RTC GPIO hardware abstraction.
 */
class IRtcGpioHAL
{
public:
    virtual ~IRtcGpioHAL() = default;

    /** @copydoc rtc_gpio_init(gpio_num_t gpio_num) */
    virtual esp_err_t gpio_init(gpio_num_t gpio_num) = 0;

    /** @copydoc rtc_gpio_deinit(gpio_num_t gpio_num) */
    virtual esp_err_t gpio_deinit(gpio_num_t gpio_num) = 0;

    /** @copydoc rtc_gpio_get_level(gpio_num_t gpio_num) */
    virtual uint32_t gpio_get_level(gpio_num_t gpio_num) = 0;

    /** @copydoc rtc_gpio_set_level(gpio_num_t gpio_num, uint32_t level) */
    virtual esp_err_t gpio_set_level(gpio_num_t gpio_num, uint32_t level) = 0;

    /** @copydoc rtc_gpio_set_direction(gpio_num_t gpio_num, rtc_gpio_mode_t mode) */
    virtual esp_err_t gpio_set_direction(gpio_num_t gpio_num, rtc_gpio_mode_t mode) = 0;

    /** @copydoc rtc_gpio_pullup_en(gpio_num_t gpio_num) */
    virtual esp_err_t gpio_pullup_en(gpio_num_t gpio_num) = 0;

    /** @copydoc rtc_gpio_pulldown_en(gpio_num_t gpio_num) */
    virtual esp_err_t gpio_pulldown_en(gpio_num_t gpio_num) = 0;

    /** @copydoc rtc_gpio_pullup_dis(gpio_num_t gpio_num) */
    virtual esp_err_t gpio_pullup_dis(gpio_num_t gpio_num) = 0;

    /** @copydoc rtc_gpio_pulldown_dis(gpio_num_t gpio_num) */
    virtual esp_err_t gpio_pulldown_dis(gpio_num_t gpio_num) = 0;

    /** @copydoc rtc_gpio_set_drive_capability(gpio_num_t gpio_num, gpio_drive_cap_t strength) */
    virtual esp_err_t gpio_set_drive_capability(gpio_num_t gpio_num, gpio_drive_cap_t strength) = 0;

    /** @copydoc rtc_gpio_hold_dis(gpio_num_t gpio_num) */
    virtual esp_err_t gpio_hold_dis(gpio_num_t gpio_num) = 0;

    /** @copydoc rtc_gpio_hold_en(gpio_num_t gpio_num) */
    virtual esp_err_t gpio_hold_en(gpio_num_t gpio_num) = 0;

    /** @copydoc rtc_gpio_wakeup_enable(gpio_num_t gpio_num, gpio_int_type_t intr_type) */
    virtual esp_err_t gpio_wakeup_enable(gpio_num_t gpio_num, gpio_int_type_t intr_type) = 0;

    /** @copydoc rtc_gpio_wakeup_disable(gpio_num_t gpio_num) */
    virtual esp_err_t gpio_wakeup_disable(gpio_num_t gpio_num) = 0;
};

} // namespace idf_hals