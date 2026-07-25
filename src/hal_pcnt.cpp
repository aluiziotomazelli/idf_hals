#include "hal_pcnt.hpp"

namespace idf_hals {

esp_err_t HalPcnt::new_unit(const pcnt_unit_config_t *config, pcnt_unit_handle_t *ret_unit) {
#if __has_include("driver/pulse_cnt.h")
    return pcnt_new_unit(config, ret_unit);
#else
    return ESP_ERR_NOT_SUPPORTED;
#endif
}

esp_err_t HalPcnt::del_unit(pcnt_unit_handle_t unit) {
#if __has_include("driver/pulse_cnt.h")
    return pcnt_del_unit(unit);
#else
    return ESP_ERR_NOT_SUPPORTED;
#endif
}

esp_err_t HalPcnt::unit_set_glitch_filter(pcnt_unit_handle_t unit, const pcnt_glitch_filter_config_t *config) {
#if __has_include("driver/pulse_cnt.h")
    return pcnt_unit_set_glitch_filter(unit, config);
#else
    return ESP_ERR_NOT_SUPPORTED;
#endif
}

esp_err_t HalPcnt::unit_enable(pcnt_unit_handle_t unit) {
#if __has_include("driver/pulse_cnt.h")
    return pcnt_unit_enable(unit);
#else
    return ESP_ERR_NOT_SUPPORTED;
#endif
}

esp_err_t HalPcnt::unit_disable(pcnt_unit_handle_t unit) {
#if __has_include("driver/pulse_cnt.h")
    return pcnt_unit_disable(unit);
#else
    return ESP_ERR_NOT_SUPPORTED;
#endif
}

esp_err_t HalPcnt::unit_start(pcnt_unit_handle_t unit) {
#if __has_include("driver/pulse_cnt.h")
    return pcnt_unit_start(unit);
#else
    return ESP_ERR_NOT_SUPPORTED;
#endif
}

esp_err_t HalPcnt::unit_stop(pcnt_unit_handle_t unit) {
#if __has_include("driver/pulse_cnt.h")
    return pcnt_unit_stop(unit);
#else
    return ESP_ERR_NOT_SUPPORTED;
#endif
}

esp_err_t HalPcnt::unit_clear_count(pcnt_unit_handle_t unit) {
#if __has_include("driver/pulse_cnt.h")
    return pcnt_unit_clear_count(unit);
#else
    return ESP_ERR_NOT_SUPPORTED;
#endif
}

esp_err_t HalPcnt::unit_get_count(pcnt_unit_handle_t unit, int *value) {
#if __has_include("driver/pulse_cnt.h")
    return pcnt_unit_get_count(unit, value);
#else
    return ESP_ERR_NOT_SUPPORTED;
#endif
}

esp_err_t HalPcnt::new_channel(pcnt_unit_handle_t unit, const pcnt_chan_config_t *config, pcnt_channel_handle_t *ret_chan) {
#if __has_include("driver/pulse_cnt.h")
    return pcnt_new_channel(unit, config, ret_chan);
#else
    return ESP_ERR_NOT_SUPPORTED;
#endif
}

esp_err_t HalPcnt::del_channel(pcnt_channel_handle_t chan) {
#if __has_include("driver/pulse_cnt.h")
    return pcnt_del_channel(chan);
#else
    return ESP_ERR_NOT_SUPPORTED;
#endif
}

esp_err_t HalPcnt::channel_set_edge_action(pcnt_channel_handle_t chan, pcnt_channel_edge_action_t pos_act, pcnt_channel_edge_action_t neg_act) {
#if __has_include("driver/pulse_cnt.h")
    return pcnt_channel_set_edge_action(chan, pos_act, neg_act);
#else
    return ESP_ERR_NOT_SUPPORTED;
#endif
}

esp_err_t HalPcnt::channel_set_level_action(pcnt_channel_handle_t chan, pcnt_channel_level_action_t high_act, pcnt_channel_level_action_t low_act) {
#if __has_include("driver/pulse_cnt.h")
    return pcnt_channel_set_level_action(chan, high_act, low_act);
#else
    return ESP_ERR_NOT_SUPPORTED;
#endif
}

} // namespace idf_hals
