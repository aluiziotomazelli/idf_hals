#pragma once

#include "gmock/gmock.h"
#include "interfaces/i_hal_pcnt.hpp"

namespace idf_hals {

class MockPcntHAL : public IPcntHAL {
public:
    MOCK_METHOD(esp_err_t, new_unit, (const pcnt_unit_config_t*, pcnt_unit_handle_t*), (override));
    MOCK_METHOD(esp_err_t, del_unit, (pcnt_unit_handle_t), (override));
    MOCK_METHOD(esp_err_t, unit_set_glitch_filter, (pcnt_unit_handle_t, const pcnt_glitch_filter_config_t*), (override));
    MOCK_METHOD(esp_err_t, unit_enable, (pcnt_unit_handle_t), (override));
    MOCK_METHOD(esp_err_t, unit_disable, (pcnt_unit_handle_t), (override));
    MOCK_METHOD(esp_err_t, unit_start, (pcnt_unit_handle_t), (override));
    MOCK_METHOD(esp_err_t, unit_stop, (pcnt_unit_handle_t), (override));
    MOCK_METHOD(esp_err_t, unit_clear_count, (pcnt_unit_handle_t), (override));
    MOCK_METHOD(esp_err_t, unit_get_count, (pcnt_unit_handle_t, int*), (override));
    MOCK_METHOD(esp_err_t, new_channel, (pcnt_unit_handle_t, const pcnt_chan_config_t*, pcnt_channel_handle_t*), (override));
    MOCK_METHOD(esp_err_t, del_channel, (pcnt_channel_handle_t), (override));
    MOCK_METHOD(esp_err_t, channel_set_edge_action, (pcnt_channel_handle_t, pcnt_channel_edge_action_t, pcnt_channel_edge_action_t), (override));
    MOCK_METHOD(esp_err_t, channel_set_level_action, (pcnt_channel_handle_t, pcnt_channel_level_action_t, pcnt_channel_level_action_t), (override));
};

} // namespace idf_hals
