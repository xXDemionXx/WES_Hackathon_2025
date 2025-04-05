#include "ui_queue.h"
#include "esp_log.h"
#include "freertos/queue.h"
#include "ui.h"

/* Declare the external queue handle defined in app_main.c */
extern QueueHandle_t s_queue_handle;

#ifndef TASK_DELAY_MS
#define TASK_DELAY_MS (1000U)
#endif

int test_var = 0;


static const char *TAG = "queue_example";

void ui_queue_task(void *p_param)
{
    (void)p_param;
    uint32_t count = 0;
    for (;;)
    {
        if (pdTRUE == xQueueSend(s_queue_handle, &count, pdMS_TO_TICKS(10)))
        {
            ESP_LOGI(TAG, "[Producer] Sent value: %lu", count);
            count++;
        }
        vTaskDelay(TASK_DELAY_MS / portTICK_PERIOD_MS);


        // Receive data from GUI
        if (xQueueReceive(s_queue_handle, &test_var, pdMS_TO_TICKS(10))) {
            printf("Received from gui task: %d\n", test_var);
            //ESP_LOGI(TAG, "[Producer] Sent value: %lu", count);
        }
    }
}