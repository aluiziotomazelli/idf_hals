// external/idf_hals/src/hal_rtc_gpio.cpp
#if __has_include("driver/rtc_io.h")
#include "driver/rtc_io.h"
#endif

#include "hal_rtc_gpio.hpp"

namespace idf_hals {

esp_err_t RtcGpioHAL::gpio_init(gpio_num_t gpio_num)
{
    return rtc_gpio_init(gpio_num);
}
esp_err_t RtcGpioHAL::gpio_deinit(gpio_num_t gpio_num)
{
    return rtc_gpio_deinit(gpio_num);
}
uint32_t RtcGpioHAL::gpio_get_level(gpio_num_t gpio_num)
{
    return rtc_gpio_get_level(gpio_num);
}
esp_err_t RtcGpioHAL::gpio_set_level(gpio_num_t gpio_num, uint32_t level)
{
    return rtc_gpio_set_level(gpio_num, level);
}
esp_err_t RtcGpioHAL::gpio_set_direction(gpio_num_t gpio_num, rtc_gpio_mode_t mode)
{
    return rtc_gpio_set_direction(gpio_num, mode);
}
esp_err_t RtcGpioHAL::gpio_pullup_en(gpio_num_t gpio_num)
{
    return rtc_gpio_pullup_en(gpio_num);
}
esp_err_t RtcGpioHAL::gpio_pulldown_en(gpio_num_t gpio_num)
{
    return rtc_gpio_pulldown_en(gpio_num);
}
esp_err_t RtcGpioHAL::gpio_pullup_dis(gpio_num_t gpio_num)
{
    return rtc_gpio_pullup_dis(gpio_num);
}
esp_err_t RtcGpioHAL::gpio_pulldown_dis(gpio_num_t gpio_num)
{
    return rtc_gpio_pulldown_dis(gpio_num);
}
esp_err_t RtcGpioHAL::gpio_set_drive_capability(gpio_num_t gpio_num, gpio_drive_cap_t strength)
{
    return rtc_gpio_set_drive_capability(gpio_num, strength);
}
esp_err_t RtcGpioHAL::gpio_hold_dis(gpio_num_t gpio_num)
{
    return rtc_gpio_hold_dis(gpio_num);
}
esp_err_t RtcGpioHAL::gpio_hold_en(gpio_num_t gpio_num)
{
    return rtc_gpio_hold_en(gpio_num);
}
esp_err_t RtcGpioHAL::gpio_wakeup_enable(gpio_num_t gpio_num, gpio_int_type_t intr_type)
{
    return rtc_gpio_wakeup_enable(gpio_num, intr_type);
}
esp_err_t RtcGpioHAL::gpio_wakeup_disable(gpio_num_t gpio_num)
{
    return rtc_gpio_wakeup_disable(gpio_num);
}

} // namespace idf_hals