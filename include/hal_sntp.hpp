// components/idf_hals/include/hal_sntp.hpp
#pragma once

#include "interfaces/i_hal_sntp.hpp"

namespace idf_hals {

/**
 * @class HalSntp
 * @brief Concrete wrapper for ESP-IDF SNTP and esp_netif_sntp functions.
 */
class HalSntp : public IHalSntp
{
public:
    esp_err_t init(const HalSntpConfig& config) override;
    esp_err_t start() override;
    void deinit() override;
    esp_err_t sync_wait(uint32_t timeout_ms) override;
    void set_sync_interval(uint32_t interval_ms) override;
    HalSntpSyncStatus get_sync_status() override;
    bool restart() override;
};

} // namespace idf_hals
