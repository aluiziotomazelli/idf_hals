// components/idf_hals/mocks/mock_hal_sleep.hpp
#pragma once

#include "gmock/gmock.h"
#include "interfaces/i_hal_sleep.hpp"

namespace idf_hals {

class MockSleepHAL : public ISleepHAL
{
public:
    MOCK_METHOD(esp_err_t, disable_wakeup_source, (esp_sleep_source_t source), (override));
    MOCK_METHOD(esp_err_t, enable_timer_wakeup, (uint64_t time_in_us), (override));
    MOCK_METHOD(esp_err_t, deep_sleep_enable_gpio_wakeup, (uint64_t gpio_pin_mask, GpioWakeupMode mode), (override));
    MOCK_METHOD(void, deep_sleep_start, (), (override));
};

} // namespace idf_hals
