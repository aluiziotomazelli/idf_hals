// components/idf_hals/include/interfaces/i_system_hal.hpp
#pragma once

#include "esp_system.h"
#include <cstdint>

namespace idf_hals {

/**
 * @interface ISystemHAL
 * @brief Interface for ESP32 system functionality.
 */
class ISystemHAL
{
public:
    virtual ~ISystemHAL() = default;

    /** @copydoc esp_restart() */
    virtual void restart() = 0;

    /** @copydoc esp_reset_reason() */
    virtual esp_reset_reason_t reset_reason() = 0;

    /** @copydoc esp_get_free_heap_size() */
    virtual uint32_t get_free_heap_size() = 0;

    /** @copydoc esp_get_free_internal_heap_size() */
    virtual uint32_t get_free_internal_heap_size() = 0;

    /** @copydoc esp_get_minimum_free_heap_size() */
    virtual uint32_t get_minimum_free_heap_size() = 0;
};

} // namespace idf_hals
