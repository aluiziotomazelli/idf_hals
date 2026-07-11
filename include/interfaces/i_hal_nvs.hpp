// include/interfaces/i_hal_nvs.hpp
#pragma once

#include <cstddef>

#include "esp_err.h"
#include "nvs.h"
#include "nvs_flash.h"

namespace idf_hals {

/**
 * @interface INvsHAL
 * @brief Hardware Abstraction Layer for NVS.
 */
class INvsHAL
{
public:
    virtual ~INvsHAL() = default;

    /** @copydoc nvs_flash_init() */
    virtual esp_err_t flash_init() = 0;

    /** @copydoc nvs_flash_erase() */
    virtual esp_err_t flash_erase() = 0;

    /** @copydoc nvs_open() */
    virtual esp_err_t open(const char* name, nvs_open_mode_t open_mode, nvs_handle_t* out_handle) = 0;

    /** @copydoc nvs_close() */
    virtual void close(nvs_handle_t handle) = 0;

    /** @copydoc nvs_erase_key() */
    virtual esp_err_t erase_key(nvs_handle_t handle, const char* key) = 0;

    /** @copydoc nvs_erase_all() */
    virtual esp_err_t erase_all(nvs_handle_t handle) = 0;

    /** @copydoc nvs_set_blob() */
    virtual esp_err_t set_blob(nvs_handle_t handle, const char* key, const void* value, size_t length) = 0;

    /** @copydoc nvs_get_blob() */
    virtual esp_err_t get_blob(nvs_handle_t handle, const char* key, void* out_value, size_t* length) = 0;

    /** @copydoc nvs_commit() */
    virtual esp_err_t commit(nvs_handle_t handle) = 0;
};

} // namespace idf_hals
