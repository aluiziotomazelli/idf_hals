// components/idf_hals/src/hal_sntp.cpp
#include "hal_sntp.hpp"

#define LOG_LOCAL_LEVEL ESP_LOG_INFO
#include "esp_log.h"

#include "esp_netif_sntp.h"
#include "esp_sntp.h"

namespace idf_hals {

esp_err_t HalSntp::init(const HalSntpConfig& config)
{
    esp_sntp_config_t sntp_config = {};
    sntp_config.smooth_sync = config.smooth_sync;
    sntp_config.server_from_dhcp = config.server_from_dhcp;
    sntp_config.wait_for_sync = false;
    sntp_config.start = false;
    sntp_config.sync_cb = config.sync_cb;
    sntp_config.renew_servers_after_new_IP = config.server_from_dhcp;
    sntp_config.ip_event_to_renew = IP_EVENT_STA_GOT_IP;
    sntp_config.index_of_first_server = 0;
    
    // Safety check for CONFIG_LWIP_SNTP_MAX_SERVERS compile configuration
#if CONFIG_LWIP_SNTP_MAX_SERVERS > 0
    sntp_config.num_of_servers = 1;
    sntp_config.servers[0] = config.default_server;
#else
    sntp_config.num_of_servers = 0;
#endif

    return esp_netif_sntp_init(&sntp_config);
}

esp_err_t HalSntp::start()
{
    return esp_netif_sntp_start();
}

void HalSntp::deinit()
{
    esp_netif_sntp_deinit();
}

esp_err_t HalSntp::sync_wait(uint32_t timeout_ms)
{
    // Convert ms to FreeRTOS ticks
    TickType_t ticks = pdMS_TO_TICKS(timeout_ms);
    return esp_netif_sntp_sync_wait(ticks);
}

void HalSntp::set_sync_interval(uint32_t interval_ms)
{
    esp_sntp_set_sync_interval(interval_ms);
}

HalSntpSyncStatus HalSntp::get_sync_status()
{
    sntp_sync_status_t status = esp_sntp_get_sync_status();
    switch (status) {
        case SNTP_SYNC_STATUS_RESET:
            return HalSntpSyncStatus::RESET;
        case SNTP_SYNC_STATUS_COMPLETED:
            return HalSntpSyncStatus::COMPLETED;
        case SNTP_SYNC_STATUS_IN_PROGRESS:
            return HalSntpSyncStatus::IN_PROGRESS;
        default:
            return HalSntpSyncStatus::RESET;
    }
}

bool HalSntp::restart()
{
    return esp_sntp_restart();
}

} // namespace idf_hals
