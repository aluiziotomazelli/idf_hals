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

#include "sdkconfig.h"
#include "soc/soc_caps.h"

esp_err_t SleepHAL::deep_sleep_enable_gpio_wakeup(uint64_t gpio_pin_mask, GpioWakeupMode mode)
{
#if SOC_GPIO_SUPPORT_DEEP_SLEEP_WAKEUP
    esp_deepsleep_gpio_wake_up_mode_t gpio_mode = (mode == GpioWakeupMode::HIGH_LEVEL) ? ESP_GPIO_WAKEUP_GPIO_HIGH : ESP_GPIO_WAKEUP_GPIO_LOW;
    return esp_deep_sleep_enable_gpio_wakeup(gpio_pin_mask, gpio_mode);
#elif SOC_PM_SUPPORT_EXT1_WAKEUP
    esp_sleep_ext1_wakeup_mode_t ext1_mode = (mode == GpioWakeupMode::HIGH_LEVEL) ? ESP_EXT1_WAKEUP_ANY_HIGH : ESP_EXT1_WAKEUP_ALL_LOW;
    return esp_sleep_enable_ext1_wakeup(gpio_pin_mask, ext1_mode);
#else
    return ESP_ERR_NOT_SUPPORTED;
#endif
}

void SleepHAL::deep_sleep_start()
{
    esp_deep_sleep_start();
}

} // namespace idf_hals
