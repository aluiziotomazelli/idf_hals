// mocks/mock_hal_nvs.hpp
#pragma once

#include "gmock/gmock.h"
#include "interfaces/i_hal_nvs.hpp"

namespace idf_hals {

class MockNvsHAL : public INvsHAL
{
public:
    MOCK_METHOD(esp_err_t, flash_init, (), (override));
    MOCK_METHOD(esp_err_t, flash_erase, (), (override));
    MOCK_METHOD(esp_err_t, open, (const char* name, nvs_open_mode_t open_mode, nvs_handle_t* out_handle), (override));
    MOCK_METHOD(void, close, (nvs_handle_t handle), (override));
    MOCK_METHOD(esp_err_t, erase_key, (nvs_handle_t handle, const char* key), (override));
    MOCK_METHOD(esp_err_t, erase_all, (nvs_handle_t handle), (override));
    MOCK_METHOD(esp_err_t, set_blob, (nvs_handle_t handle, const char* key, const void* value, size_t length), (override));
    MOCK_METHOD(esp_err_t, get_blob, (nvs_handle_t handle, const char* key, void* out_value, size_t* length), (override));
    MOCK_METHOD(esp_err_t, commit, (nvs_handle_t handle), (override));
};

} // namespace idf_hals
