// external/idf_hals/mocks/mock_hal_gpio.hpp
#pragma once

#include "gmock/gmock.h"
#include "interfaces/i_hal_gpio.hpp"

namespace idf_hals {

class MockGpioHAL : public IGpioHAL
{
public:
    MOCK_METHOD(esp_err_t, reset_pin, (gpio_num_t pin), (override));
    MOCK_METHOD(esp_err_t, config, (const gpio_config_t* config), (override));
    MOCK_METHOD(esp_err_t, set_level, (gpio_num_t pin, const uint32_t level), (override));
    MOCK_METHOD(int, get_level, (gpio_num_t pin), (override));
    MOCK_METHOD(esp_err_t, set_direction, (gpio_num_t pin, gpio_mode_t mode), (override));
    MOCK_METHOD(esp_err_t, set_drive_capability, (gpio_num_t gpio_num, gpio_drive_cap_t strength), (override));
    MOCK_METHOD(esp_err_t, hold_en, (gpio_num_t gpio_num), (override));
    MOCK_METHOD(esp_err_t, hold_dis, (gpio_num_t gpio_num), (override));
    MOCK_METHOD(void, deep_sleep_hold_en, (), (override));
    MOCK_METHOD(esp_err_t, install_isr_service, (int intr_alloc_flags), (override));
    MOCK_METHOD(void, uninstall_isr_service, (), (override));
    MOCK_METHOD(esp_err_t, isr_handler_add, (gpio_num_t gpio_num, gpio_isr_t isr_handler, void* args), (override));
    MOCK_METHOD(esp_err_t, isr_handler_remove, (gpio_num_t gpio_num), (override));
};

} // namespace idf_hals
