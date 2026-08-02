// external/idf_hals/include/interfaces/i_hal_i2c.hpp
#pragma once

#include "esp_err.h"

#if __has_include("driver/i2c_master.h")
#include "driver/i2c_master.h"
#else
typedef void* i2c_master_bus_handle_t;
typedef void* i2c_master_dev_handle_t;
typedef int i2c_port_num_t;

typedef struct {
    i2c_port_num_t i2c_port;
    int sda_io_num;
    int scl_io_num;
    int clk_source;
    uint8_t glitch_ignore_cnt;
    struct {
        uint32_t enable_internal_pullup: 1;
    } flags;
} i2c_master_bus_config_t;

typedef struct {
    uint16_t dev_addr_length;
    uint16_t device_address;
    uint32_t scl_speed_hz;
    uint32_t scl_wait_us;
    struct {
        uint32_t disable_ack_check: 1;
    } flags;
} i2c_device_config_t;
#endif

namespace idf_hals {

/**
 * @file i_hal_i2c.hpp
 * @brief Interface for I2C master driver abstraction.
 */

/**
 * @interface II2cHAL
 * @brief Interface for I2C master driver abstraction.
 */
class II2cHAL
{
public:
    virtual ~II2cHAL() = default;

    /** @copydoc i2c_new_master_bus() */
    virtual esp_err_t new_master_bus(const i2c_master_bus_config_t* bus_config, i2c_master_bus_handle_t* ret_bus_handle) = 0;

    /** @copydoc i2c_del_master_bus() */
    virtual esp_err_t del_master_bus(i2c_master_bus_handle_t bus_handle) = 0;

    /** @copydoc i2c_master_bus_add_device() */
    virtual esp_err_t master_bus_add_device(i2c_master_bus_handle_t bus_handle, const i2c_device_config_t* dev_config, i2c_master_dev_handle_t* ret_dev_handle) = 0;

    /** @copydoc i2c_master_bus_rm_device() */
    virtual esp_err_t master_bus_rm_device(i2c_master_dev_handle_t dev_handle) = 0;

    /** @copydoc i2c_master_transmit() */
    virtual esp_err_t master_transmit(i2c_master_dev_handle_t i2c_dev, const uint8_t* write_buffer, size_t write_size, int xfer_timeout_ms) = 0;

    /** @copydoc i2c_master_transmit_receive() */
    virtual esp_err_t master_transmit_receive(i2c_master_dev_handle_t i2c_dev, const uint8_t* write_buffer, size_t write_size, uint8_t* read_buffer, size_t read_size, int xfer_timeout_ms) = 0;

    /** @copydoc i2c_master_receive() */
    virtual esp_err_t master_receive(i2c_master_dev_handle_t i2c_dev, uint8_t* read_buffer, size_t read_size, int xfer_timeout_ms) = 0;

    /** @copydoc i2c_master_probe() */
    virtual esp_err_t master_probe(i2c_master_bus_handle_t bus_handle, uint16_t address, int xfer_timeout_ms) = 0;

    /** @copydoc i2c_master_bus_reset() */
    virtual esp_err_t master_bus_reset(i2c_master_bus_handle_t bus_handle) = 0;
};

} // namespace idf_hals
