// external/idf_hals/include/interfaces/i_hal_sys_rom.hpp
#pragma once

#include <cstdint>

namespace idf_hals {

/**
 * @file i_hal_sys_rom.hpp
 * @brief Interface for system ROM services.
 */

/**
 * @interface ISysRomHAL
 * @brief Interface for system ROM services.
 */
class ISysRomHAL
{
public:
    virtual ~ISysRomHAL() = default;

    /** @copydoc esp_rom_delay_us() */
    virtual void delay_us(uint32_t us) const = 0;
};

} // namespace idf_hals
