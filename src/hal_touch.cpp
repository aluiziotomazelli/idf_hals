#include "hal_touch.hpp"

namespace idf_hals {

esp_err_t HalTouch::new_controller(const touch_sensor_config_t *sens_cfg, touch_sensor_handle_t *ret_sens_handle) {
#if __has_include("driver/touch_sens.h")
    return touch_sensor_new_controller(sens_cfg, ret_sens_handle);
#else
    return ESP_ERR_NOT_SUPPORTED;
#endif
}

esp_err_t HalTouch::del_controller(touch_sensor_handle_t sens_handle) {
#if __has_include("driver/touch_sens.h")
    return touch_sensor_del_controller(sens_handle);
#else
    return ESP_ERR_NOT_SUPPORTED;
#endif
}

esp_err_t HalTouch::config_filter(touch_sensor_handle_t sens_handle, const touch_sensor_filter_config_t *filter_cfg) {
#if __has_include("driver/touch_sens.h")
    return touch_sensor_config_filter(sens_handle, filter_cfg);
#else
    return ESP_ERR_NOT_SUPPORTED;
#endif
}

esp_err_t HalTouch::new_channel(touch_sensor_handle_t sens_handle, int channel_id, const touch_channel_config_t *chan_cfg, touch_channel_handle_t *ret_chan_handle) {
#if __has_include("driver/touch_sens.h")
    return touch_sensor_new_channel(sens_handle, channel_id, chan_cfg, ret_chan_handle);
#else
    return ESP_ERR_NOT_SUPPORTED;
#endif
}

esp_err_t HalTouch::del_channel(touch_channel_handle_t chan_handle) {
#if __has_include("driver/touch_sens.h")
    return touch_sensor_del_channel(chan_handle);
#else
    return ESP_ERR_NOT_SUPPORTED;
#endif
}

esp_err_t HalTouch::enable(touch_sensor_handle_t sens_handle) {
#if __has_include("driver/touch_sens.h")
    return touch_sensor_enable(sens_handle);
#else
    return ESP_ERR_NOT_SUPPORTED;
#endif
}

esp_err_t HalTouch::disable(touch_sensor_handle_t sens_handle) {
#if __has_include("driver/touch_sens.h")
    return touch_sensor_disable(sens_handle);
#else
    return ESP_ERR_NOT_SUPPORTED;
#endif
}

esp_err_t HalTouch::start_continuous_scanning(touch_sensor_handle_t sens_handle) {
#if __has_include("driver/touch_sens.h")
    return touch_sensor_start_continuous_scanning(sens_handle);
#else
    return ESP_ERR_NOT_SUPPORTED;
#endif
}

esp_err_t HalTouch::stop_continuous_scanning(touch_sensor_handle_t sens_handle) {
#if __has_include("driver/touch_sens.h")
    return touch_sensor_stop_continuous_scanning(sens_handle);
#else
    return ESP_ERR_NOT_SUPPORTED;
#endif
}

esp_err_t HalTouch::trigger_oneshot_scanning(touch_sensor_handle_t sens_handle, uint32_t timeout_ms) {
#if __has_include("driver/touch_sens.h")
    return touch_sensor_trigger_oneshot_scanning(sens_handle, timeout_ms);
#else
    return ESP_ERR_NOT_SUPPORTED;
#endif
}

esp_err_t HalTouch::read_channel_data(touch_channel_handle_t chan_handle, touch_chan_data_type_t type, uint32_t *data) {
#if __has_include("driver/touch_sens.h")
    return touch_channel_read_data(chan_handle, type, data);
#else
    return ESP_ERR_NOT_SUPPORTED;
#endif
}

} // namespace idf_hals
