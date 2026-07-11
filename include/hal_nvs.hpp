// include/hal_nvs.hpp
#pragma once

#include "i_hal_nvs.hpp"

namespace idf_hals {

/**
 * @class NvsHAL
 * @brief Hardware Abstraction Layer for NVS.
 */
class NvsHAL : public INvsHAL
{
public:
    /** @copydoc INvsHAL::flash_init() */
    esp_err_t flash_init() override;

    /** @copydoc INvsHAL::flash_erase() */
    esp_err_t flash_erase() override;

    /** @copydoc INvsHAL::open() */
    esp_err_t open(const char* name, nvs_open_mode_t open_mode, nvs_handle_t* out_handle) override;

    /** @copydoc INvsHAL::close() */
    void close(nvs_handle_t handle) override;

    /** @copydoc INvsHAL::erase_key() */
    esp_err_t erase_key(nvs_handle_t handle, const char* key) override;

    /** @copydoc INvsHAL::erase_all() */
    esp_err_t erase_all(nvs_handle_t handle) override;

    /** @copydoc INvsHAL::set_blob() */
    esp_err_t set_blob(nvs_handle_t handle, const char* key, const void* value, size_t length) override;

    /** @copydoc INvsHAL::get_blob() */
    esp_err_t get_blob(nvs_handle_t handle, const char* key, void* out_value, size_t* length) override;

    /** @copydoc INvsHAL::commit() */
    esp_err_t commit(nvs_handle_t handle) override;
};

} // namespace idf_hals
