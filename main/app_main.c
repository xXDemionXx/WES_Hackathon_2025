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
#include "gui/squareline/project/ui_queue.h"
 
//---------------------------------- MACROS -----------------------------------
 
//-------------------------------- DATA TYPES ---------------------------------
 
//---------------------- PRIVATE FUNCTION PROTOTYPES --------------------------
static void main_task(void *p_param);
//------------------------- STATIC DATA & CONSTANTS ---------------------------
 
//Hardware
QueueHandle_t queue_from_hardware = NULL;   // Queue handle for the queue that receives from hardware task
QueueHandle_t queue_for_hardware = NULL;    // Queue handle for the queue that sends to hardware task
hardware_send_queue_data_t hardware_data;           // Data that is received from the hardware task
hardware_receive_queue_data_t data_for_hardware;    // Data that is sent to hardware task
 
QueueHandle_t gui_queue_handle = NULL;
 
//GUI
QueueHandle_t queue_from_gui = NULL;        // Queue handle for the queue that receives from gui task
QueueHandle_t queue_for_gui = NULL;         // Queue handle for the queue that sends to gui task
gui_send_queue_data_t gui_data;
gui_receive_queue_data_t data_for_gui;
 
int test_send_to_gui = 35;
static int danger_lv = 0;
 
static const char *TAG = "main task";
//------------------------------- GLOBAL DATA ---------------------------------
 
//------------------------------ PUBLIC FUNCTIONS -----------------------------
void app_main(void)
{   
    // Init all the peripheral tasks
    gui_init();
    hardware_init();
 
    // Create GUI queue
    gui_queue_handle = xQueueCreate(5, sizeof(uint32_t));
    if (NULL == gui_queue_handle)
     {
         ESP_LOGE(TAG, "Failed to create queue");
         return;
     }
     xTaskCreate(&ui_queue_task, "ui_queue_task", 2048, NULL, 5, NULL);
 
    data_for_hardware.message_type = 1;
    data_for_hardware.data.command1.button1 = 21;
 
    data_for_gui.message_type = 1;
    data_for_hardware.data.command1.button1= 55;
 
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

            if (hardware_data.message_type == UL_SENSOR) {
                danger_lv = hardware_data.data.ultrasonic_data.distance;
                printf("Received from hardware task: %d\n", danger_lv);
                 // Send data to GUI
                if (xQueueSend(gui_queue_handle, &danger_lv, pdMS_TO_TICKS(WAIT_FOR_QUEUE))) {
                    printf("Test send to GUI\n");
                }

            } else if (hardware_data.message_type == 2) {
                printf("Received from hardware task: %d\n", hardware_data.data.joystick_data.x_axis);
            }
        }
 
 
        // Send data to hardware
        if (xQueueSend(queue_for_hardware, &data_for_hardware, pdMS_TO_TICKS(WAIT_FOR_QUEUE))) {
            printf("Sending to hardware task\n");
        }
 
 
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}
 
 
 
//---------------------------- PRIVATE FUNCTIONS ------------------------------
 
//---------------------------- INTERRUPT HANDLERS -----------------------------