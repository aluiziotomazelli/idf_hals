#pragma once

#include "esp_err.h"
#if __has_include("driver/touch_sens.h")
#include "driver/touch_sens.h"
#else
// Fallback for mocking/host tests if driver is missing
typedef struct touch_sensor_s* touch_sensor_handle_t;
typedef struct touch_channel_s* touch_channel_handle_t;
typedef struct {} touch_sensor_config_t;
typedef struct {} touch_sensor_filter_config_t;
typedef struct {} touch_channel_config_t;
typedef enum {
    TOUCH_CHAN_DATA_TYPE_RAW,
    TOUCH_CHAN_DATA_TYPE_SMOOTH,
    TOUCH_CHAN_DATA_TYPE_BENCHMARK,
    TOUCH_CHAN_DATA_TYPE_PROXIMITY
} touch_chan_data_type_t;
#endif

namespace idf_hals {

/**
 * @interface ITouchHAL
 * @brief Interface for Touch Sensor hardware abstraction (ESP-IDF v5+).
 */
class ITouchHAL {
public:
    virtual ~ITouchHAL() = default;

    /** @copydoc touch_sensor_new_controller() */
    virtual esp_err_t new_controller(const touch_sensor_config_t *sens_cfg, touch_sensor_handle_t *ret_sens_handle) = 0;

    /** @copydoc touch_sensor_del_controller() */
    virtual esp_err_t del_controller(touch_sensor_handle_t sens_handle) = 0;

    /** @copydoc touch_sensor_config_filter() */
    virtual esp_err_t config_filter(touch_sensor_handle_t sens_handle, const touch_sensor_filter_config_t *filter_cfg) = 0;

    /** @copydoc touch_sensor_new_channel() */
    virtual esp_err_t new_channel(touch_sensor_handle_t sens_handle, int channel_id, const touch_channel_config_t *chan_cfg, touch_channel_handle_t *ret_chan_handle) = 0;

    /** @copydoc touch_sensor_del_channel() */
    virtual esp_err_t del_channel(touch_channel_handle_t chan_handle) = 0;

    /** @copydoc touch_sensor_enable() */
    virtual esp_err_t enable(touch_sensor_handle_t sens_handle) = 0;

    /** @copydoc touch_sensor_disable() */
    virtual esp_err_t disable(touch_sensor_handle_t sens_handle) = 0;

    /** @copydoc touch_sensor_start_continuous_scanning() */
    virtual esp_err_t start_continuous_scanning(touch_sensor_handle_t sens_handle) = 0;

    /** @copydoc touch_sensor_stop_continuous_scanning() */
    virtual esp_err_t stop_continuous_scanning(touch_sensor_handle_t sens_handle) = 0;

    /** @copydoc touch_sensor_trigger_oneshot_scanning() */
    virtual esp_err_t trigger_oneshot_scanning(touch_sensor_handle_t sens_handle, uint32_t timeout_ms) = 0;

    /** @copydoc touch_channel_read_data() */
    virtual esp_err_t read_channel_data(touch_channel_handle_t chan_handle, touch_chan_data_type_t type, uint32_t *data) = 0;
};

} // namespace idf_hals
