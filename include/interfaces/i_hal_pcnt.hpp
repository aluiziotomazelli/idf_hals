#pragma once

#include <cstdint>
#include "esp_err.h"
#include "interfaces/i_hal_gpio.hpp"

#if __has_include("driver/pulse_cnt.h")
#include "driver/pulse_cnt.h"
#else
// Fallback for mocking/host tests if driver is missing
typedef struct pcnt_unit_t* pcnt_unit_handle_t;
typedef struct pcnt_chan_t* pcnt_channel_handle_t;

typedef struct {
    int low_limit;
    int high_limit;
    int intr_priority;
} pcnt_unit_config_t;

typedef struct {
    int edge_gpio_num;
    int level_gpio_num;
} pcnt_chan_config_t;

typedef struct {
    uint32_t max_glitch_ns;
} pcnt_glitch_filter_config_t;

typedef enum {
    PCNT_CHANNEL_EDGE_ACTION_HOLD,
    PCNT_CHANNEL_EDGE_ACTION_INCREASE,
    PCNT_CHANNEL_EDGE_ACTION_DECREASE,
} pcnt_channel_edge_action_t;

typedef enum {
    PCNT_CHANNEL_LEVEL_ACTION_KEEP,
    PCNT_CHANNEL_LEVEL_ACTION_INVERSE,
    PCNT_CHANNEL_LEVEL_ACTION_HOLD,
} pcnt_channel_level_action_t;
#endif

namespace idf_hals {

/**
 * @interface IPcntHAL
 * @brief Interface for ESP32 Pulse Counter (PCNT) hardware abstraction (ESP-IDF v5+).
 */
class IPcntHAL {
public:
    virtual ~IPcntHAL() = default;

    /** @copydoc pcnt_new_unit() */
    virtual esp_err_t new_unit(const pcnt_unit_config_t *config, pcnt_unit_handle_t *ret_unit) = 0;

    /** @copydoc pcnt_del_unit() */
    virtual esp_err_t del_unit(pcnt_unit_handle_t unit) = 0;

    /** @copydoc pcnt_unit_set_glitch_filter() */
    virtual esp_err_t unit_set_glitch_filter(pcnt_unit_handle_t unit, const pcnt_glitch_filter_config_t *config) = 0;

    /** @copydoc pcnt_unit_enable() */
    virtual esp_err_t unit_enable(pcnt_unit_handle_t unit) = 0;

    /** @copydoc pcnt_unit_disable() */
    virtual esp_err_t unit_disable(pcnt_unit_handle_t unit) = 0;

    /** @copydoc pcnt_unit_start() */
    virtual esp_err_t unit_start(pcnt_unit_handle_t unit) = 0;

    /** @copydoc pcnt_unit_stop() */
    virtual esp_err_t unit_stop(pcnt_unit_handle_t unit) = 0;

    /** @copydoc pcnt_unit_clear_count() */
    virtual esp_err_t unit_clear_count(pcnt_unit_handle_t unit) = 0;

    /** @copydoc pcnt_unit_get_count() */
    virtual esp_err_t unit_get_count(pcnt_unit_handle_t unit, int32_t *value) = 0;

    /** @copydoc pcnt_new_channel() */
    virtual esp_err_t new_channel(pcnt_unit_handle_t unit, const pcnt_chan_config_t *config, pcnt_channel_handle_t *ret_chan) = 0;

    /** @copydoc pcnt_del_channel() */
    virtual esp_err_t del_channel(pcnt_channel_handle_t chan) = 0;

    /** @copydoc pcnt_channel_set_edge_action() */
    virtual esp_err_t channel_set_edge_action(pcnt_channel_handle_t chan, pcnt_channel_edge_action_t pos_act, pcnt_channel_edge_action_t neg_act) = 0;

    /** @copydoc pcnt_channel_set_level_action() */
    virtual esp_err_t channel_set_level_action(pcnt_channel_handle_t chan, pcnt_channel_level_action_t high_act, pcnt_channel_level_action_t low_act) = 0;
};

} // namespace idf_hals
