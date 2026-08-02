// external/idf_hals/mocks/mock_hal_i2c.hpp
#pragma once

#include "gmock/gmock.h"
#include "interfaces/i_hal_i2c.hpp"

namespace idf_hals {

class MockI2cHAL : public II2cHAL
{
public:
    MOCK_METHOD(esp_err_t, new_master_bus, (const i2c_master_bus_config_t* bus_config, i2c_master_bus_handle_t* ret_bus_handle), (override));
    MOCK_METHOD(esp_err_t, del_master_bus, (i2c_master_bus_handle_t bus_handle), (override));
    MOCK_METHOD(esp_err_t, master_bus_add_device, (i2c_master_bus_handle_t bus_handle, const i2c_device_config_t* dev_config, i2c_master_dev_handle_t* ret_dev_handle), (override));
    MOCK_METHOD(esp_err_t, master_bus_rm_device, (i2c_master_dev_handle_t dev_handle), (override));
    MOCK_METHOD(esp_err_t, master_transmit, (i2c_master_dev_handle_t i2c_dev, const uint8_t* write_buffer, size_t write_size, int xfer_timeout_ms), (override));
    MOCK_METHOD(esp_err_t, master_transmit_receive, (i2c_master_dev_handle_t i2c_dev, const uint8_t* write_buffer, size_t write_size, uint8_t* read_buffer, size_t read_size, int xfer_timeout_ms), (override));
    MOCK_METHOD(esp_err_t, master_receive, (i2c_master_dev_handle_t i2c_dev, uint8_t* read_buffer, size_t read_size, int xfer_timeout_ms), (override));
    MOCK_METHOD(esp_err_t, master_probe, (i2c_master_bus_handle_t bus_handle, uint16_t address, int xfer_timeout_ms), (override));
    MOCK_METHOD(esp_err_t, master_bus_reset, (i2c_master_bus_handle_t bus_handle), (override));
};

} // namespace idf_hals
