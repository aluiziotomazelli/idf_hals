// external/idf_hals/mocks/mock_hal_gpio.hpp
#pragma once

#include "gmock/gmock.h"
#include "interfaces/i_hal_gpio.hpp"

namespace idf_hals {

class MockGpioHAL : public IGpioHAL
{
public:
    MOCK_METHOD(esp_err_t, reset_pin, (const gpio_num_t pin), (override));
    MOCK_METHOD(esp_err_t, config, (const gpio_config_t &config), (override));
    MOCK_METHOD(esp_err_t, set_level, (const gpio_num_t pin, const bool level), (override));
    MOCK_METHOD(esp_err_t, get_level, (const gpio_num_t pin, bool &level), (override));
    MOCK_METHOD(esp_err_t, set_direction, (const gpio_num_t pin, gpio_mode_t mode), (override));
    MOCK_METHOD(esp_err_t, set_drive_capability, (const gpio_num_t gpio_num, gpio_drive_cap_t strength), (override));
};

} // namespace idf_hals
