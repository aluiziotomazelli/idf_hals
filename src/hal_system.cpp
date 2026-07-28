// components/idf_hals/src/system_hal.cpp
#include "hal_system.hpp"

namespace idf_hals {

void SystemHAL::restart()
{
    esp_restart();
}

esp_reset_reason_t SystemHAL::reset_reason()
{
    return esp_reset_reason();
}

uint32_t SystemHAL::get_free_heap_size()
{
    return esp_get_free_heap_size();
}

uint32_t SystemHAL::get_free_internal_heap_size()
{
    return esp_get_free_internal_heap_size();
}

uint32_t SystemHAL::get_minimum_free_heap_size()
{
    return esp_get_minimum_free_heap_size();
}

const esp_app_desc_t* SystemHAL::get_app_description()
{
    return esp_app_get_description();
}

} // namespace idf_hals
