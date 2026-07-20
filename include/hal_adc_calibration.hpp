// external/idf_hals/include/hal_adc_calibration.hpp
#pragma once

#include "interfaces/i_hal_adc_calibration.hpp"

namespace idf_hals {

/**
 * @brief Concrete implementation of IHalAdcCalibration wrapping ESP-IDF ADC Calibration APIs.
 */
class HalAdcCalibration : public IHalAdcCalibration {
public:
    HalAdcCalibration() = default;
    ~HalAdcCalibration() override = default;

    /** @copydoc IHalAdcCalibration::create_scheme */
    esp_err_t create_scheme(adc_unit_t unit_id, adc_channel_t chan, adc_atten_t atten, adc_bitwidth_t bitwidth, adc_cali_handle_t *ret_handle) override;

    /** @copydoc IHalAdcCalibration::delete_scheme */
    esp_err_t delete_scheme(adc_cali_handle_t handle) override;

    /** @copydoc IHalAdcCalibration::raw_to_voltage */
    esp_err_t raw_to_voltage(adc_cali_handle_t handle, int raw, int *voltage) override;
};

} // namespace idf_hals
