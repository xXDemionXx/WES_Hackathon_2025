#include "ui_queue.h"
#include "esp_log.h"
#include "freertos/queue.h"
#include "ui.h"

/* Declare the external queue handle defined in app_main.c */
extern QueueHandle_t s_queue_handle;

#ifndef TASK_DELAY_MS
#define TASK_DELAY_MS (1000U)
#endif

int car_distance_level = 0;


void ui_queue_task(void *p_param)
{
    (void)p_param;
    for (;;)
    {
    
        // Receive data from GUI
        if (xQueueReceive(s_queue_handle, &car_distance_level, pdMS_TO_TICKS(10))) {
            printf("Received from gui task: %d\n", car_distance_level);
        }
    }
}