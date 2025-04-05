/**
* @file main.c

* @brief
*/

//--------------------------------- INCLUDES ----------------------------------
#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"
#include "esp_log.h"
#include "esp_mac.h"

#include <esp_event.h>
#include <esp_log.h>
#include <esp_netif.h>
#include <esp_wifi.h>


#include <nvs_flash.h>
#include <stdio.h>


#include "gui/gui.h"
#include "hardware/hardware.h"
#include "wifi/wifi.h"


#define EXAMPLE_ESP_WIFI_SSID ("koprive")
#define EXAMPLE_ESP_WIFI_PASS ("kopriva123")
#define DELAY_TIME_MS         (10000U)


//------------------------- STATIC DATA & CONSTANTS ---------------------------
static const char *TAG = "WIFI";
//---------------------------------- MACROS -----------------------------------

//-------------------------------- DATA TYPES ---------------------------------

//---------------------- PRIVATE FUNCTION PROTOTYPES --------------------------
// Forward declarations
static void _event_handler(void *p_arg, esp_event_base_t event_base, int32_t event_id, void *p_event_data);
static esp_err_t _wifi_init_sta(void);
static esp_err_t _nvs_init(void);   

void wifi_task(void *pvParameters)
{
    // Initialize NVS
    if (_nvs_init() != ESP_OK) {
        ESP_LOGE(TAG, "NVS initialization failed");
        vTaskDelete(NULL);
    }

    // Initialize TCP/IP network interface
    if (esp_netif_init() != ESP_OK) {
        ESP_LOGE(TAG, "esp_netif initialization failed");
        vTaskDelete(NULL);
    }

    // Create default event loop
    if (esp_event_loop_create_default() != ESP_OK) {
        ESP_LOGE(TAG, "Event loop creation failed");
        vTaskDelete(NULL);
    }

    // Register WiFi & IP event handlers
    ESP_ERROR_CHECK(esp_event_handler_register(WIFI_EVENT, ESP_EVENT_ANY_ID, &_event_handler, NULL));
    ESP_ERROR_CHECK(esp_event_handler_register(IP_EVENT, IP_EVENT_STA_GOT_IP, &_event_handler, NULL));

    // Initialize WiFi in station mode
    if (_wifi_init_sta() != ESP_OK) {
        ESP_LOGE(TAG, "WiFi initialization failed");
        vTaskDelete(NULL);
    }

    // Main loop for WiFi task (could also handle further WiFi related processing)
    int index = 0;
    while (true)
    {
        ESP_LOGI(TAG, "[%d] WiFi Task Running...", index++);
        vTaskDelay(DELAY_TIME_MS / portTICK_PERIOD_MS);
    }
}


//------------------------------- GLOBAL DATA ---------------------------------

//------------------------------ PUBLIC FUNCTIONS -----------------------------
void app_main(void)
{
    // Create the dedicated WiFi task
    xTaskCreate(wifi_task, "wifi_task", 4096, NULL, 5, NULL);
}



//---------------------------- PRIVATE FUNCTIONS ------------------------------
static esp_err_t _wifi_init_sta(void)
{
    esp_netif_create_default_wifi_sta();

    wifi_init_config_t cfg = WIFI_INIT_CONFIG_DEFAULT();
    ESP_ERROR_CHECK(esp_wifi_init(&cfg));

    ESP_LOGI(TAG, "Set Wi-Fi storage to RAM");
    ESP_ERROR_CHECK(esp_wifi_set_storage(WIFI_STORAGE_RAM));

    ESP_LOGI(TAG, "Set Wi-Fi mode to STA");
    ESP_ERROR_CHECK(esp_wifi_set_mode(WIFI_MODE_STA));

    wifi_config_t wifi_config = {
        .sta = {
            .ssid = EXAMPLE_ESP_WIFI_SSID,
            .password = EXAMPLE_ESP_WIFI_PASS,
            .threshold.authmode = WIFI_AUTH_OPEN,
            .sae_pwe_h2e = WPA3_SAE_PWE_BOTH,
        },
    };

    ESP_LOGI(TAG, "Set Wi-Fi configuration");
    ESP_ERROR_CHECK(esp_wifi_set_config(ESP_IF_WIFI_STA, &wifi_config));

    ESP_LOGI(TAG, "Starting Wi-Fi");
    ESP_ERROR_CHECK(esp_wifi_start());

    ESP_LOGI(TAG, "Connecting to AP: %s", EXAMPLE_ESP_WIFI_SSID);
    return ESP_OK;
}

static esp_err_t _nvs_init(void)
{
    esp_err_t ret = nvs_flash_init();
    if (ret == ESP_ERR_NVS_NO_FREE_PAGES || ret == ESP_ERR_NVS_NEW_VERSION_FOUND)
    {
        ESP_ERROR_CHECK(nvs_flash_erase());
        ret = nvs_flash_init();
    }
    return ret;
}

static void _event_handler(void *p_arg, esp_event_base_t event_base, int32_t event_id, void *p_event_data)
{
    if ((WIFI_EVENT == event_base) && (WIFI_EVENT_STA_START == event_id))
    {
        ESP_LOGI(TAG, "Wi-Fi STA started, connecting...");
        esp_wifi_connect();
    }
    else if ((WIFI_EVENT == event_base) && (WIFI_EVENT_STA_DISCONNECTED == event_id))
    {
        ESP_LOGW(TAG, "Wi-Fi disconnected, retrying...");
        esp_wifi_connect();
    }
    else if ((IP_EVENT == event_base) && (IP_EVENT_STA_GOT_IP == event_id))
    {
        ip_event_got_ip_t *event = (ip_event_got_ip_t *)p_event_data;
        ESP_LOGI(TAG, "Got IP: " IPSTR, IP2STR(&event->ip_info.ip));
    }
}
//---------------------------- INTERRUPT HANDLERS -----------------------------
