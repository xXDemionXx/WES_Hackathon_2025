#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"
#include "esp_log.h"
#include "esp_mac.h"
#include "hardware.h"


static QueueHandle_t hardware_send_to_main = NULL;  // Queue handle for the queue that sends to main task
QueueHandle_t hardware_receive_from_main = NULL;    // Queue handle for the queue that sreceives from main task




//---------------------------------- LOCAL VARIABLES -----------------------------------
hardware_send_queue_data_t hardware_send_data;      // Data that is sent over the queue to main task


static void hardware_task(void *p_param);


void hardware_init(void){
    hardware_send_data.message_type = 1;
    hardware_send_data.data.buttons_data.button1 = 233;

    hardware_send_to_main = xQueueCreate(5, sizeof(hardware_send_data));
    xTaskCreate(&hardware_task, "Hardware_Task", 2048, NULL, 5, NULL);
}

QueueHandle_t get_hardware_send_queue(void) {
    return hardware_send_to_main;
}

static void hardware_task(void *p_param)
{
    (void)p_param;

    for(;;)
    {
        if (pdTRUE == xQueueSend(hardware_send_to_main, &hardware_send_data, portMAX_DELAY))
        {
            //ESP_LOGI(TAG, "[Producer] Sent value: %lu", count);
            //count++;
            printf("hardware task send\n");
        }

        //printf("hardware task\n");
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}