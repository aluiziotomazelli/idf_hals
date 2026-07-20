// external/idf_hals/src/hal_adc_calibration.cpp
#include "hal_adc_calibration.hpp"
#include "sdkconfig.h"

namespace idf_hals {

esp_err_t HalAdcCalibration::create_scheme(adc_unit_t unit_id, adc_channel_t chan, adc_atten_t atten, adc_bitwidth_t bitwidth, adc_cali_handle_t *ret_handle) {
#if CONFIG_IDF_TARGET_ESP32
    adc_cali_line_fitting_config_t config = {
        .unit_id = unit_id,
        .atten = atten,
        .bitwidth = bitwidth,
        .default_vref = 0
    };
    return ::adc_cali_create_scheme_line_fitting(&config, ret_handle);
#else
    adc_cali_curve_fitting_config_t config = {
        .unit_id = unit_id,
        .chan = chan,
        .atten = atten,
        .bitwidth = bitwidth
    };
    return ::adc_cali_create_scheme_curve_fitting(&config, ret_handle);
#endif
}

esp_err_t HalAdcCalibration::delete_scheme(adc_cali_handle_t handle) {
#if CONFIG_IDF_TARGET_ESP32
    return ::adc_cali_delete_scheme_line_fitting(handle);
#else
    return ::adc_cali_delete_scheme_curve_fitting(handle);
#endif
}

esp_err_t HalAdcCalibration::raw_to_voltage(adc_cali_handle_t handle, int raw, int *voltage) {
    return ::adc_cali_raw_to_voltage(handle, raw, voltage);
}

} // namespace idf_hals
