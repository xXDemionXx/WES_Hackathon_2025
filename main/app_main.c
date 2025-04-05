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


#include "gui/gui.h"
#include "hardware/hardware.h"
#include "wifi/wifi.h"

//---------------------------------- MACROS -----------------------------------

//-------------------------------- DATA TYPES ---------------------------------

//---------------------- PRIVATE FUNCTION PROTOTYPES --------------------------
static void main_task(void *p_param);
//------------------------- STATIC DATA & CONSTANTS ---------------------------
QueueHandle_t queue_from_hardware;
hardware_send_queue_data_t hardware_data;

//------------------------------- GLOBAL DATA ---------------------------------

//------------------------------ PUBLIC FUNCTIONS -----------------------------
void app_main(void)
{
    //gui_init();
    hardware_init();
    //wifi_init();
    xTaskCreate(&main_task, "Main_Task", 2048, NULL, 5, NULL);
}

static void main_task(void *p_param)
{
    (void)p_param;

    queue_from_hardware = get_hardware_send_queue();


    for(;;)
    {
        if (xQueueReceive(queue_from_hardware, &hardware_data, portMAX_DELAY)) {
            //printf("Received from queue: %d\n", hardware_data);
            printf("Received from hardware task: %d\n", hardware_data.data.buttons_data.button1);
        }
        //printf("main task\n");
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}



//---------------------------- PRIVATE FUNCTIONS ------------------------------

//---------------------------- INTERRUPT HANDLERS -----------------------------
