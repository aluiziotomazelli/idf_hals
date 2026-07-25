#pragma once

#include "interfaces/i_hal_touch.hpp"

namespace idf_hals {

/**
 * @brief Concrete implementation of ITouchHAL wrapping ESP-IDF v5 driver.
 */
class HalTouch : public ITouchHAL {
public:
    esp_err_t new_controller(const touch_sensor_config_t *sens_cfg, touch_sensor_handle_t *ret_sens_handle) override;
    esp_err_t del_controller(touch_sensor_handle_t sens_handle) override;
    
    esp_err_t config_filter(touch_sensor_handle_t sens_handle, const touch_sensor_filter_config_t *filter_cfg) override;
    
    esp_err_t new_channel(touch_sensor_handle_t sens_handle, int channel_id, const touch_channel_config_t *chan_cfg, touch_channel_handle_t *ret_chan_handle) override;
    esp_err_t del_channel(touch_channel_handle_t chan_handle) override;
    
    esp_err_t enable(touch_sensor_handle_t sens_handle) override;
    esp_err_t disable(touch_sensor_handle_t sens_handle) override;
    
    esp_err_t start_continuous_scanning(touch_sensor_handle_t sens_handle) override;
    esp_err_t stop_continuous_scanning(touch_sensor_handle_t sens_handle) override;
    esp_err_t trigger_oneshot_scanning(touch_sensor_handle_t sens_handle, uint32_t timeout_ms) override;
    
    esp_err_t read_channel_data(touch_channel_handle_t chan_handle, touch_chan_data_type_t type, uint32_t *data) override;
};

} // namespace idf_hals
