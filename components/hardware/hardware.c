#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"
#include "esp_log.h"
#include "esp_mac.h"
#include "hardware.h"


static void hardware_task(void *p_param);


void hardware_init(void){
    xTaskCreate(&hardware_task, "Hardware_Task", 2048, NULL, 5, NULL);
}

static void hardware_task(void *p_param)
{
    (void)p_param;

    for(;;)
    {
        printf("hardware task\n");
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}