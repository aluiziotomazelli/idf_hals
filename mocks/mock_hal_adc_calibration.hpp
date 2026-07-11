// external/idf_hals/mocks/mock_hal_adc_calibration.hpp
#pragma once

#include <gmock/gmock.h>
#include "interfaces/i_hal_adc_calibration.hpp"

namespace idf_hals {

class MockHalAdcCalibration : public IHalAdcCalibration {
public:
    MOCK_METHOD(esp_err_t, create_scheme_curve_fitting, (const adc_cali_curve_fitting_config_t *config, adc_cali_handle_t *ret_handle), (override));
    MOCK_METHOD(esp_err_t, delete_scheme_curve_fitting, (adc_cali_handle_t handle), (override));
    MOCK_METHOD(esp_err_t, raw_to_voltage, (adc_cali_handle_t handle, int raw, int *voltage), (override));
};

} // namespace idf_hals
