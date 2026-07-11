// external/idf_hals/src/hal_sys_rom.cpp
#include "esp_rom_sys.h"

#include "hal_sys_rom.hpp"

namespace idf_hals {

void SysRomHAL::delay_us(uint32_t us) const
{
    esp_rom_delay_us(us);
}

} // namespace idf_hals
