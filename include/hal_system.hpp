// components/idf_hals/include/system_hal.hpp
#pragma once

#include "interfaces/i_hal_system.hpp"

namespace idf_hals {

/**
 * @class SystemHAL
 * @brief Implementation of ISystemHAL using ESP-IDF functions.
 */
class SystemHAL : public ISystemHAL
{
public:
    void restart() override;
    esp_reset_reason_t reset_reason() override;
    uint32_t get_free_heap_size() override;
    uint32_t get_free_internal_heap_size() override;
    uint32_t get_minimum_free_heap_size() override;
};

} // namespace idf_hals
