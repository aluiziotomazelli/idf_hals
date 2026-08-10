// external/idf_hals/src/hal_i2c.cpp
#if __has_include("driver/i2c_master.h")
#include "driver/i2c_master.h"
#endif

#include "hal_i2c.hpp"

namespace idf_hals {

esp_err_t I2cHAL::new_master_bus(const i2c_master_bus_config_t* bus_config, i2c_master_bus_handle_t* ret_bus_handle)
{
#if __has_include("driver/i2c_master.h")
    return i2c_new_master_bus(bus_config, ret_bus_handle);
#else
    (void)bus_config;
    (void)ret_bus_handle;
    return ESP_ERR_NOT_SUPPORTED;
#endif
}

esp_err_t I2cHAL::del_master_bus(i2c_master_bus_handle_t bus_handle)
{
#if __has_include("driver/i2c_master.h")
    return i2c_del_master_bus(bus_handle);
#else
    (void)bus_handle;
    return ESP_ERR_NOT_SUPPORTED;
#endif
}

esp_err_t I2cHAL::master_bus_add_device(
    i2c_master_bus_handle_t bus_handle,
    const i2c_device_config_t* dev_config,
    i2c_master_dev_handle_t* ret_dev_handle)
{
#if __has_include("driver/i2c_master.h")
    return i2c_master_bus_add_device(bus_handle, dev_config, ret_dev_handle);
#else
    (void)bus_handle;
    (void)dev_config;
    (void)ret_dev_handle;
    return ESP_ERR_NOT_SUPPORTED;
#endif
}

esp_err_t I2cHAL::master_bus_rm_device(i2c_master_dev_handle_t dev_handle)
{
#if __has_include("driver/i2c_master.h")
    return i2c_master_bus_rm_device(dev_handle);
#else
    (void)dev_handle;
    return ESP_ERR_NOT_SUPPORTED;
#endif
}

esp_err_t I2cHAL::master_transmit(
    i2c_master_dev_handle_t i2c_dev,
    const uint8_t* write_buffer,
    size_t write_size,
    int xfer_timeout_ms)
{
#if __has_include("driver/i2c_master.h")
    return i2c_master_transmit(i2c_dev, write_buffer, write_size, xfer_timeout_ms);
#else
    (void)i2c_dev;
    (void)write_buffer;
    (void)write_size;
    (void)xfer_timeout_ms;
    return ESP_ERR_NOT_SUPPORTED;
#endif
}

esp_err_t I2cHAL::master_transmit_receive(
    i2c_master_dev_handle_t i2c_dev,
    const uint8_t* write_buffer,
    size_t write_size,
    uint8_t* read_buffer,
    size_t read_size,
    int xfer_timeout_ms)
{
#if __has_include("driver/i2c_master.h")
    return i2c_master_transmit_receive(i2c_dev, write_buffer, write_size, read_buffer, read_size, xfer_timeout_ms);
#else
    (void)i2c_dev;
    (void)write_buffer;
    (void)write_size;
    (void)read_buffer;
    (void)read_size;
    (void)xfer_timeout_ms;
    return ESP_ERR_NOT_SUPPORTED;
#endif
}

esp_err_t
I2cHAL::master_receive(i2c_master_dev_handle_t i2c_dev, uint8_t* read_buffer, size_t read_size, int xfer_timeout_ms)
{
#if __has_include("driver/i2c_master.h")
    return i2c_master_receive(i2c_dev, read_buffer, read_size, xfer_timeout_ms);
#else
    (void)i2c_dev;
    (void)read_buffer;
    (void)read_size;
    (void)xfer_timeout_ms;
    return ESP_ERR_NOT_SUPPORTED;
#endif
}

esp_err_t I2cHAL::master_probe(i2c_master_bus_handle_t bus_handle, uint16_t address, int xfer_timeout_ms)
{
#if __has_include("driver/i2c_master.h")
    return i2c_master_probe(bus_handle, address, xfer_timeout_ms);
#else
    (void)bus_handle;
    (void)address;
    (void)xfer_timeout_ms;
    return ESP_ERR_NOT_SUPPORTED;
#endif
}

esp_err_t I2cHAL::master_bus_reset(i2c_master_bus_handle_t bus_handle)
{
#if __has_include("driver/i2c_master.h")
    return i2c_master_bus_reset(bus_handle);
#else
    (void)bus_handle;
    return ESP_ERR_NOT_SUPPORTED;
#endif
}

} // namespace idf_hals
