// components/idf_hals/mocks/mock_hal_sntp.hpp
#pragma once

#include "interfaces/i_hal_sntp.hpp"
#include <gmock/gmock.h>

namespace idf_hals {

/**
 * @class MockHalSntp
 * @brief GMock implementation of IHalSntp for unit testing.
 */
class MockHalSntp : public IHalSntp
{
public:
    MOCK_METHOD(esp_err_t, init, (const HalSntpConfig& config), (override));
    MOCK_METHOD(esp_err_t, start, (), (override));
    MOCK_METHOD(void, deinit, (), (override));
    MOCK_METHOD(esp_err_t, sync_wait, (uint32_t timeout_ms), (override));
    MOCK_METHOD(void, set_sync_interval, (uint32_t interval_ms), (override));
    MOCK_METHOD(HalSntpSyncStatus, get_sync_status, (), (override));
    MOCK_METHOD(bool, restart, (), (override));
};

} // namespace idf_hals
