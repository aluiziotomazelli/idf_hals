// external/idf_hals/mocks/mock_hal_adc_calibration.hpp
#pragma once

#include <gmock/gmock.h>
#include "interfaces/i_hal_adc_calibration.hpp"

namespace idf_hals {

class MockHalAdcCalibration : public IHalAdcCalibration {
public:
    MOCK_METHOD(esp_err_t, create_scheme, (adc_unit_t unit_id, adc_channel_t chan, adc_atten_t atten, adc_bitwidth_t bitwidth, adc_cali_handle_t *ret_handle), (override));
    MOCK_METHOD(esp_err_t, delete_scheme, (adc_cali_handle_t handle), (override));
    MOCK_METHOD(esp_err_t, raw_to_voltage, (adc_cali_handle_t handle, int raw, int *voltage), (override));
};

} // namespace idf_hals
