// external/idf_hals/include/hal_sys_rom.hpp
#pragma once

#include "interfaces/i_hal_sys_rom.hpp"

namespace idf_hals {

/**
 * @file hal_sys_rom.hpp
 * @brief Thin wrapper for ESP-IDF system ROM functions.
 */
class SysRomHAL : public ISysRomHAL
{
public:
    /** @copydoc ISysRomHAL::delay_us() */
    void delay_us(uint32_t us) const override;
};

} // namespace idf_hals
