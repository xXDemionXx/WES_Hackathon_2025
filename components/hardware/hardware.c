#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"
#include "esp_log.h"
#include "esp_mac.h"
#include "hardware.h"
#include "hcsr04.h"



int car_back_distance_level = 0;    // Tells GUI how many bars to display


static QueueHandle_t hardware_send_to_main = NULL;  // Queue handle for the queue that sends to main task
QueueHandle_t hardware_receive_from_main = NULL;  // Queue handle for the queue that receives to hardware task



//---------------------------------- LOCAL VARIABLES -----------------------------------
hardware_send_queue_data_t hardware_send_data;          // Data that is sent over the queue to main task
hardware_receive_queue_data_t hardware_received_data;  // Data that is received over the queue from main task

static const char *TAG = "hardware task";


static void hardware_task(void *p_param);




void hardware_init(void){
    hardware_send_data.message_type = 1;
    hardware_send_data.data.buttons_data.button1 = 66;

    /*
    if (hardware_receive_from_main == NULL) {
        ESP_LOGE(TAG, "Queue 2 fail!");
        return; // Handle error
    }

    if (hardware_send_to_main == NULL) {
        ESP_LOGE(TAG, "Queue creation failed!");
        return; // Handle error
    }
    */

    hardware_send_to_main = xQueueCreate(5, sizeof(hardware_send_data));
    hardware_receive_from_main = xQueueCreate(5, sizeof(hardware_received_data));
    xTaskCreate(&hardware_task, "Hardware_Task", 2048*10, NULL, 5, NULL);
}

QueueHandle_t get_hardware_send_queue(void) {
    return hardware_send_to_main;
}

QueueHandle_t get_hardware_receive_queue(void) {
    return hardware_receive_from_main;
}

static void hardware_task(void *p_param)
{
    (void)p_param;

    hc_sr04_t sensor; // Create an instance of the hc_sr04_t structure
    hc_sr04_init(&sensor,US_TRIGGER_PIN,US_ECHO_PIN);       //Ultrasonic sensor initialization

    for(;;)
    {
        if (pdTRUE == xQueueReceive(hardware_receive_from_main, &hardware_received_data, pdMS_TO_TICKS(HARDWARE_RECEIVE_QUEUE_WAIT)))
        {
            printf("(Hardware) Received from main task: %d\n", hardware_received_data.data.command1.button1);
        }
        //vTaskDelay(1000 / portTICK_PERIOD_MS);

        float distance = hc_sr04_measure_distance(&sensor); // Measure distance using the ultrasonic sensor
        if (distance >= 0) {
            printf("Distance: %.2f cm\n", distance);

            hardware_send_data.message_type = UL_SENSOR; // Set message type to ultrasonic sensor
            hardware_send_data.data.ultrasonic_data.distance = (int)distance; // Send distance to main task
        } else {
            printf("Error measuring distance\n");
        }


        if (pdTRUE == xQueueSend(hardware_send_to_main, &hardware_send_data, pdMS_TO_TICKS(HARDWARE_SEND_QUEUE_WAIT)))
        {
            //printf("Hardware task send\n");
        }

        //printf("hardware task\n");
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}