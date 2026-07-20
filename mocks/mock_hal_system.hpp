// components/idf_hals/mocks/mock_system_hal.hpp
#pragma once

#include "interfaces/i_hal_system.hpp"
#include <gmock/gmock.h>

namespace idf_hals {

/**
 * @class MockSystemHAL
 * @brief GMock implementation of ISystemHAL for unit testing.
 */
class MockSystemHAL : public ISystemHAL
{
public:
    MOCK_METHOD(void, restart, (), (override));
    MOCK_METHOD(esp_reset_reason_t, reset_reason, (), (override));
    MOCK_METHOD(uint32_t, get_free_heap_size, (), (override));
    MOCK_METHOD(uint32_t, get_free_internal_heap_size, (), (override));
    MOCK_METHOD(uint32_t, get_minimum_free_heap_size, (), (override));
};

} // namespace idf_hals
