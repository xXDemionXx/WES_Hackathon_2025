#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"
#include "esp_log.h"
#include "esp_mac.h"
#include "wifi.h"


static void wifi_task(void *p_param);


void wifi_init(void){
    xTaskCreate(&wifi_task, "Hardware_Task", 2048, NULL, 5, NULL);
}

static void wifi_task(void *p_param)
{
    (void)p_param;

    for(;;)
    {
        //printf("wifi task\n");
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}