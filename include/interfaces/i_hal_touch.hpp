#pragma once

#include "esp_err.h"
#if __has_include("driver/touch_sens.h")
#include "driver/touch_sens.h"
#else
typedef struct touch_channel_s* touch_channel_handle_t;
typedef enum {
    TOUCH_CHAN_DATA_TYPE_RAW,
    TOUCH_CHAN_DATA_TYPE_SMOOTH,
    TOUCH_CHAN_DATA_TYPE_BENCHMARK,
    TOUCH_CHAN_DATA_TYPE_PROXIMITY
} touch_chan_data_type_t;
#endif

namespace idf_hals {

/**
 * @file i_hal_touch.hpp
 * @brief Interface for Touch Sensor hardware abstraction.
 */

/**
 * @interface ITouchHAL
 * @brief Interface for Touch Sensor hardware abstraction (ESP-IDF v5).
 */
class ITouchHAL {
public:
    virtual ~ITouchHAL() = default;

    /** @copydoc touch_channel_read_data() */
    virtual esp_err_t read_channel_data(touch_channel_handle_t chan_handle, touch_chan_data_type_t type, uint32_t *data) = 0;
};

} // namespace idf_hals
