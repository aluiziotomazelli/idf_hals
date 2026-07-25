// components/idf_hals/include/interfaces/i_hal_sntp.hpp
#pragma once

#include "esp_err.h"
#include <sys/time.h>
#include <stdint.h>

namespace idf_hals {

/**
 * @brief Unified SNTP sync status enum matching ESP-IDF's sntp_sync_status_t.
 */
enum class HalSntpSyncStatus : uint8_t {
    RESET = 0,
    COMPLETED = 1,
    IN_PROGRESS = 2
};

/**
 * @brief Unified SNTP configuration struct abstracted from ESP-IDF structures.
 */
struct HalSntpConfig {
    bool smooth_sync;
    bool server_from_dhcp;
    const char* default_server;
    uint32_t sync_interval_ms;
    void (*sync_cb)(struct timeval *tv);
};

/**
 * @interface IHalSntp
 * @brief Interface for ESP-IDF SNTP and esp_netif_sntp functionality.
 */
class IHalSntp
{
public:
    virtual ~IHalSntp() = default;

    /** @copydoc esp_netif_sntp_init() */
    virtual esp_err_t init(const HalSntpConfig& config) = 0;

    /** @copydoc esp_netif_sntp_start() */
    virtual esp_err_t start() = 0;

    /** @copydoc esp_netif_sntp_deinit() */
    virtual void deinit() = 0;

    /** @copydoc esp_netif_sntp_sync_wait() */
    virtual esp_err_t sync_wait(uint32_t timeout_ms) = 0;

    /** @copydoc esp_sntp_set_sync_interval() */
    virtual void set_sync_interval(uint32_t interval_ms) = 0;

    /** @copydoc esp_sntp_get_sync_status() */
    virtual HalSntpSyncStatus get_sync_status() = 0;

    /** @copydoc esp_sntp_restart() */
    virtual bool restart() = 0;
};

} // namespace idf_hals
