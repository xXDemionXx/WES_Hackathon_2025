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
#include "main.h"

//---------------------------------- MACROS -----------------------------------

//-------------------------------- DATA TYPES ---------------------------------

//---------------------- PRIVATE FUNCTION PROTOTYPES --------------------------
static void main_task(void *p_param);
//------------------------- STATIC DATA & CONSTANTS ---------------------------

//Hardware
QueueHandle_t queue_from_hardware = NULL;   // Queue handle for the queue that receives from hardware task
QueueHandle_t queue_for_hardware = NULL;    // Queue handle for the queue that sends to hardware task
hardware_send_queue_data_t hardware_data;
hardware_receive_queue_data_t data_for_hardware;

//GUI
QueueHandle_t queue_from_gui = NULL;        // Queue handle for the queue that receives from gui task
QueueHandle_t queue_for_gui = NULL;         // Queue handle for the queue that sends to gui task
gui_send_queue_data_t gui_data;
gui_receive_queue_data_t data_for_gui;


static const char *TAG = "main task";
//------------------------------- GLOBAL DATA ---------------------------------

//------------------------------ PUBLIC FUNCTIONS -----------------------------
void app_main(void)
{
    gui_init();
    hardware_init();
    //wifi_init();

    data_for_hardware.message_type = 1;
    data_for_hardware.data.command1.button1 = 21;

    xTaskCreate(&main_task, "Main_Task", 2048, NULL, 5, NULL);
}

static void main_task(void *p_param)
{
    (void)p_param;

    queue_from_hardware = get_hardware_send_queue();
    queue_for_hardware = get_hardware_receive_queue();

    //queue_from_gui = get_gui_send_queue();
    //queue_for_gui = get_gui_receive_queue();

    for(;;)
    {
        // Receive data from hardware
        if (xQueueReceive(queue_from_hardware, &hardware_data, pdMS_TO_TICKS(WAIT_FOR_QUEUE))) {
            printf("Received from hardware task: %d\n", hardware_data.data.buttons_data.button1);
            //ESP_LOGI(TAG, "[Producer] Sent value: %lu", count);
        }
        // Receive data from GUI
        if (xQueueReceive(queue_from_gui, &gui_data, pdMS_TO_TICKS(WAIT_FOR_QUEUE))) {
            printf("Received from gui task: %d\n", gui_data.data.buttons_data.button1);
            //ESP_LOGI(TAG, "[Producer] Sent value: %lu", count);
        }


        // Send data to hardware
        if (xQueueSend(queue_for_hardware, &data_for_hardware, pdMS_TO_TICKS(WAIT_FOR_QUEUE))) {
            printf("Sending to hardware task\n");
        }
        // Send data to gui
        if (xQueueSend(queue_for_gui, &data_for_gui, pdMS_TO_TICKS(WAIT_FOR_QUEUE))) {
            printf("Sending to hardware task\n");
        }
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}



//---------------------------- PRIVATE FUNCTIONS ------------------------------

//---------------------------- INTERRUPT HANDLERS -----------------------------
