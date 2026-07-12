// components/idf_hals/src/hal_sleep.cpp
#include "esp_sleep.h"

#include "hal_sleep.hpp"

namespace idf_hals {

esp_err_t SleepHAL::disable_wakeup_source(esp_sleep_source_t source)
{
    return esp_sleep_disable_wakeup_source(source);
}

esp_err_t SleepHAL::enable_timer_wakeup(uint64_t time_in_us)
{
    return esp_sleep_enable_timer_wakeup(time_in_us);
}

esp_err_t SleepHAL::deep_sleep_enable_gpio_wakeup(uint64_t gpio_pin_mask, esp_deepsleep_gpio_wake_up_mode_t mode)
{
    return esp_deep_sleep_enable_gpio_wakeup(gpio_pin_mask, mode);
}

void SleepHAL::deep_sleep_start()
{
    esp_deep_sleep_start();
}

} // namespace idf_hals
