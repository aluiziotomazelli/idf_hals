#pragma once

#include "gmock/gmock.h"
#include "interfaces/i_hal_touch.hpp"

namespace idf_hals {

class MockTouchHAL : public ITouchHAL {
public:
    MOCK_METHOD(esp_err_t, new_controller, (const touch_sensor_config_t*, touch_sensor_handle_t*), (override));
    MOCK_METHOD(esp_err_t, del_controller, (touch_sensor_handle_t), (override));
    MOCK_METHOD(esp_err_t, config_filter, (touch_sensor_handle_t, const touch_sensor_filter_config_t*), (override));
    MOCK_METHOD(esp_err_t, new_channel, (touch_sensor_handle_t, int, const touch_channel_config_t*, touch_channel_handle_t*), (override));
    MOCK_METHOD(esp_err_t, del_channel, (touch_channel_handle_t), (override));
    MOCK_METHOD(esp_err_t, enable, (touch_sensor_handle_t), (override));
    MOCK_METHOD(esp_err_t, disable, (touch_sensor_handle_t), (override));
    MOCK_METHOD(esp_err_t, read_channel_data, (touch_channel_handle_t, touch_chan_data_type_t, uint32_t*), (override));
};

} // namespace idf_hals
