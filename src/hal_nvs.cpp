// src/hal_nvs.cpp

#include "hal_nvs.hpp"

namespace idf_hals {

/** * @copydoc INvsHAL::flash_init() */
esp_err_t NvsHAL::flash_init()
{
    return nvs_flash_init();
}

/** * @copydoc INvsHAL::flash_erase() */
esp_err_t NvsHAL::flash_erase()
{
    return nvs_flash_erase();
}

/** * @copydoc INvsHAL::open() */
esp_err_t NvsHAL::open(const char* name, nvs_open_mode_t open_mode, nvs_handle_t* out_handle)
{
    return nvs_open(name, open_mode, out_handle);
}

/** * @copydoc INvsHAL::close() */
void NvsHAL::close(nvs_handle_t handle)
{
    nvs_close(handle);
}

/** * @copydoc INvsHAL::erase_key() */
esp_err_t NvsHAL::erase_key(nvs_handle_t handle, const char* key)
{
    return nvs_erase_key(handle, key);
}

/** * @copydoc INvsHAL::erase_all() */
esp_err_t NvsHAL::erase_all(nvs_handle_t handle)
{
    return nvs_erase_all(handle);
}

/** * @copydoc INvsHAL::set_blob() */
esp_err_t NvsHAL::set_blob(nvs_handle_t handle, const char* key, const void* value, size_t length)
{
    return nvs_set_blob(handle, key, value, length);
}

/** * @copydoc INvsHAL::get_blob() */
esp_err_t NvsHAL::get_blob(nvs_handle_t handle, const char* key, void* out_value, size_t* length)
{
    return nvs_get_blob(handle, key, out_value, length);
}

/** * @copydoc INvsHAL::commit() */
esp_err_t NvsHAL::commit(nvs_handle_t handle)
{
    return nvs_commit(handle);
}

} // namespace idf_hals