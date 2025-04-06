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


static const beep_timing_t stage_1_time = {STAGE1_ON_TIME, STAGE1_OFF_TIME};
static const beep_timing_t stage_2_time = {STAGE2_ON_TIME, STAGE2_OFF_TIME};
static const beep_timing_t stage_3_time = {STAGE3_ON_TIME, STAGE3_OFF_TIME};


//---------------------------------- LOCAL VARIABLES -----------------------------------
hardware_send_queue_data_t hardware_send_data;          // Data that is sent over the queue to main task
hardware_receive_queue_data_t hardware_received_data;  // Data that is received over the queue from main task

//============================================================

static void hardware_task(void *p_param);


static void hardware_task(void *p_param)
{
    (void)p_param;

    hc_sr04_t sensor; // Create an instance of the hc_sr04_t structure
    hc_sr04_init(&sensor,US_TRIGGER_PIN,US_ECHO_PIN);       //Ultrasonic sensor initialization
    static int prev_distance = 0;


    for(;;)
    {
        if (pdTRUE == xQueueReceive(hardware_receive_from_main, &hardware_received_data, pdMS_TO_TICKS(HARDWARE_RECEIVE_QUEUE_WAIT)))
        {
            printf("(Hardware) Received from main task: %d\n", hardware_received_data.data.command1.button1);
        }
        //vTaskDelay(1000 / portTICK_PERIOD_MS);

        int distance = (int)hc_sr04_measure_distance(&sensor); // Measure distance using the ultrasonic sensor

        if (distance >= 0) {

            distance = distance / 20;
            //vTaskResume(stage4_handle);

            if(distance > 3) distance = 3;
            
                switch(distance){
                    case 0:
                        /*
                        vTaskSuspend(stage1_handle);
                        vTaskSuspend(stage2_handle);
                        vTaskResume(stage3_handle);
                        */
                       play_beep_non_blocking(stage_1_time.on_time, stage_1_time.off_time);
                    break;
                    case 1:
                        /*
                        vTaskSuspend(stage1_handle);
                        vTaskResume(stage2_handle);
                        vTaskSuspend(stage3_handle);
                        */
                       play_beep_non_blocking(stage_2_time.on_time, stage_2_time.off_time);
                    break;
                    case 2:
                        /*
                        vTaskResume(stage1_handle);
                        vTaskSuspend(stage2_handle);
                        vTaskSuspend(stage3_handle);
                        */
                       play_beep_non_blocking(stage_3_time.on_time, stage_3_time.off_time);
                    break;
                    case 3:
                        /*
                        vTaskSuspend(stage1_handle);
                        vTaskSuspend(stage2_handle);
                        vTaskSuspend(stage3_handle);
                        */

                    break;
            }

            prev_distance = distance;

            hardware_send_data.message_type = UL_SENSOR; // Set message type to ultrasonic sensor
            hardware_send_data.data.ultrasonic_data.distance = distance; // Send distance to main task

            if (pdTRUE == xQueueSend(hardware_send_to_main, &hardware_send_data, pdMS_TO_TICKS(HARDWARE_SEND_QUEUE_WAIT)))
            {
                printf("Hardware task send distance\n");
            }

        } else {
            printf("Error measuring distance\n");
        }


        //printf("hardware task\n");
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}

/*
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
    */


static void beep_task(void *pvParameters) {
    beep_timing_t timing = *((beep_timing_t *)pvParameters);
    
    int samples = (SAMPLE_RATE * timing.on_time) / 1000;  // Only for on_time
    dac_output_enable(DAC_CHANNEL_1);

    for (int i = 0; i < samples; i++) {
        int value = 128 + (int)(127 * sin(2 * PI * TONE_FREQ * i / SAMPLE_RATE));
        dac_output_voltage(DAC_CHANNEL_1, value);
        ets_delay_us(1000000 / SAMPLE_RATE);  // ~125us delay for 8kHz sample rate
    }
    
    dac_output_voltage(DAC_CHANNEL_1, 0);
    vTaskDelay(pdMS_TO_TICKS(timing.off_time));
    
    free(pvParameters);      // Clean up
    vTaskDelete(NULL);       // Done
}

void play_beep_non_blocking(int on_time_ms, int off_time_ms) {
    beep_timing_t *timing = malloc(sizeof(beep_timing_t));
    if (timing == NULL) return;

    timing->on_time = on_time_ms;
    timing->off_time = off_time_ms;

    xTaskCreate(beep_task, "beep_task", 4096, timing, 5, NULL);
}

// --- app_main for testing ---
void sound_generator() {
    dac_output_enable(DAC_CHANNEL_1); // GPIO25

    // Example: Call one at a time (can trigger from sensor input or state machine)
    //stage1_slow_beeps();

    // To test others one-by-one manually, just call:
    //stage2_medium_beeps();
    //stage3_fast_beeps();
    //stage4_constant_tone();
}
//============================================================

void init_speeker_tasks(void){

    dac_output_enable(DAC_CHANNEL_1); // GPIO25

    
}



void hardware_init(void){
    hardware_send_data.message_type = 1;
    hardware_send_data.data.buttons_data.button1 = 66;

    init_speeker_tasks();
    

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