#pragma once

#include "interfaces/i_hal_pcnt.hpp"

namespace idf_hals {

/**
 * @brief Concrete implementation of IPcntHAL wrapping ESP-IDF driver/pulse_cnt.h
 */
class HalPcnt : public IPcntHAL {
public:
    /** @copydoc IPcntHAL::new_unit */
    esp_err_t new_unit(const pcnt_unit_config_t *config, pcnt_unit_handle_t *ret_unit) override;

    /** @copydoc IPcntHAL::del_unit */
    esp_err_t del_unit(pcnt_unit_handle_t unit) override;

    /** @copydoc IPcntHAL::unit_set_glitch_filter */
    esp_err_t unit_set_glitch_filter(pcnt_unit_handle_t unit, const pcnt_glitch_filter_config_t *config) override;

    /** @copydoc IPcntHAL::unit_enable */
    esp_err_t unit_enable(pcnt_unit_handle_t unit) override;

    /** @copydoc IPcntHAL::unit_disable */
    esp_err_t unit_disable(pcnt_unit_handle_t unit) override;

    /** @copydoc IPcntHAL::unit_start */
    esp_err_t unit_start(pcnt_unit_handle_t unit) override;

    /** @copydoc IPcntHAL::unit_stop */
    esp_err_t unit_stop(pcnt_unit_handle_t unit) override;

    /** @copydoc IPcntHAL::unit_clear_count */
    esp_err_t unit_clear_count(pcnt_unit_handle_t unit) override;

    /** @copydoc IPcntHAL::unit_get_count */
    esp_err_t unit_get_count(pcnt_unit_handle_t unit, int *value) override;

    /** @copydoc IPcntHAL::new_channel */
    esp_err_t new_channel(pcnt_unit_handle_t unit, const pcnt_chan_config_t *config, pcnt_channel_handle_t *ret_chan) override;

    /** @copydoc IPcntHAL::del_channel */
    esp_err_t del_channel(pcnt_channel_handle_t chan) override;

    /** @copydoc IPcntHAL::channel_set_edge_action */
    esp_err_t channel_set_edge_action(pcnt_channel_handle_t chan, pcnt_channel_edge_action_t pos_act, pcnt_channel_edge_action_t neg_act) override;

    /** @copydoc IPcntHAL::channel_set_level_action */
    esp_err_t channel_set_level_action(pcnt_channel_handle_t chan, pcnt_channel_level_action_t high_act, pcnt_channel_level_action_t low_act) override;
};

} // namespace idf_hals
