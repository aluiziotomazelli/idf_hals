// external/idf_hals/mocks/mock_hal_sys_rom.hpp
#pragma once

#include "gmock/gmock.h"
#include "interfaces/i_hal_sys_rom.hpp"

namespace idf_hals {

class MockSysRomHAL : public ISysRomHAL
{
public:
    MOCK_METHOD(void, delay_us, (uint32_t us), (const, override));
};

} // namespace idf_hals
