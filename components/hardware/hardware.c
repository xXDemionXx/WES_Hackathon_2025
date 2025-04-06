#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"
#include "esp_log.h"
#include "esp_mac.h"
#include "hardware.h"
#include "hcsr04.h"

#include <stdio.h>
#include <math.h>
#include "driver/dac.h"
#include "esp_system.h"
#include "esp32/rom/ets_sys.h"  // For ets_delay_us



int car_back_distance_level = 0;    // Tells GUI how many bars to display


static QueueHandle_t hardware_send_to_main = NULL;  // Queue handle for the queue that sends to main task
QueueHandle_t hardware_receive_from_main = NULL;  // Queue handle for the queue that receives to hardware task



//---------------------------------- LOCAL VARIABLES -----------------------------------
hardware_send_queue_data_t hardware_send_data;          // Data that is sent over the queue to main task
hardware_receive_queue_data_t hardware_received_data;  // Data that is received over the queue from main task

//============================================================


#define PI 3.14159265
#define SAMPLE_RATE 8000
#define TONE_FREQ 1000
#define BEEP_DURATION_MS 100

#define STAGE1_GAP 700
#define STAGE2_GAP 300
#define STAGE3_GAP 80
#define STAGE1_TIME 3333
#define STAGE2_TIME 3333
#define STAGE3_TIME 3333
#define STAGE4_TIME 2000

// --- Shared blocking tone generator ---
void play_beep_blocking(int duration_ms) {
    int samples = (SAMPLE_RATE * duration_ms) / 1000;
    for (int i = 0; i < samples; i++) {
        int value = 128 + (int)(127 * sin(2 * PI * TONE_FREQ * i / SAMPLE_RATE));
        dac_output_voltage(DAC_CHANNEL_1, value);
        ets_delay_us(1000000 / SAMPLE_RATE); // ~125us delay per sample
    }
}

// --- Stage 1: Slow Beeps Task ---
void stage1_task(void *pvParam) {
    int elapsed = 0;
    while (elapsed < STAGE1_TIME) {
        play_beep_blocking(BEEP_DURATION_MS);
        vTaskDelay(pdMS_TO_TICKS(STAGE1_GAP));
        elapsed += BEEP_DURATION_MS + STAGE1_GAP;
    }
    vTaskDelete(NULL);
}
void stage1_slow_beeps() {
    xTaskCreate(stage1_task, "stage1_task", 4096, NULL, 5, NULL);
}

// --- Stage 2: Medium Beeps Task ---
void stage2_task(void *pvParam) {
    int elapsed = 0;
    while (elapsed < STAGE2_TIME) {
        play_beep_blocking(BEEP_DURATION_MS);
        vTaskDelay(pdMS_TO_TICKS(STAGE2_GAP));
        elapsed += BEEP_DURATION_MS + STAGE2_GAP;
    }
    vTaskDelete(NULL);
}
void stage2_medium_beeps() {
    xTaskCreate(stage2_task, "stage2_task", 4096, NULL, 5, NULL);
}

// --- Stage 3: Fast Beeps Task ---
void stage3_task(void *pvParam) {
    int elapsed = 0;
    while (elapsed < STAGE3_TIME) {
        play_beep_blocking(BEEP_DURATION_MS);
        vTaskDelay(pdMS_TO_TICKS(STAGE3_GAP));
        elapsed += BEEP_DURATION_MS + STAGE3_GAP;
    }
    vTaskDelete(NULL);
}
void stage3_fast_beeps() {
    xTaskCreate(stage3_task, "stage3_task", 4096, NULL, 5, NULL);
}

// --- Stage 4: Constant Tone Task ---
void stage4_task(void *pvParam) {
    play_beep_blocking(STAGE4_TIME);
    vTaskDelete(NULL);
}
void stage4_constant_tone() {
    xTaskCreate(stage4_task, "stage4_task", 4096, NULL, 5, NULL);
}

// --- app_main for testing ---
void sound_generator() {
    dac_output_enable(DAC_CHANNEL_1); // GPIO25

    // Example: Call one at a time (can trigger from sensor input or state machine)
    stage1_slow_beeps();

    // To test others one-by-one manually, just call:
    //stage2_medium_beeps();
    //stage3_fast_beeps();
    //stage4_constant_tone();
}
//============================================================

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
            sound_generator();

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