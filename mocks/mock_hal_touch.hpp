#pragma once

#include "gmock/gmock.h"
#include "interfaces/i_hal_touch.hpp"

namespace idf_hals {

class MockTouchHAL : public ITouchHAL {
public:
    MOCK_METHOD(esp_err_t, read_channel_data, (touch_channel_handle_t chan_handle, touch_chan_data_type_t type, uint32_t *data), (override));
};

} // namespace idf_hals
