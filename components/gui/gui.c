/**
* @file gui.c

* @brief This file is an example for how to use the LVGL library.
*
* COPYRIGHT NOTICE: (c) 2022 Byte Lab Grupa d.o.o.
* All rights reserved.
*/

//--------------------------------- INCLUDES ----------------------------------
#include "gui.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_freertos_hooks.h"
#include "freertos/semphr.h"
#include "esp_log.h"
#include "esp_timer.h"

/* Littlevgl specific */
#include "lvgl.h"
#include "lvgl_helpers.h"

#include "squareline/project/ui.h"

//---------------------------------- MACROS -----------------------------------
#define LV_TICK_PERIOD_MS (1U)

//-------------------------------- DATA TYPES ---------------------------------
gui_send_queue_data_t gui_send_data;          // Data that is sent over the queue to main task
gui_receive_queue_data_t gui_received_data;  // Data that is received over the queue from main task

static QueueHandle_t gui_send_to_main = NULL;  // Queue handle for the queue that sends to main task
static QueueHandle_t gui_receive_from_main = NULL;  // Queue handle for the queue that receives to hardware task
//---------------------- PRIVATE FUNCTION PROTOTYPES --------------------------
/**
 * @brief Initializes GUI application.
 */
static void _gui_application_init(void);

/**
 * @brief Lv's timer callback function.
 *
 * @param [in] p_arg The argument of the timer.
 */
static void _lv_tick_timer(void *p_arg);

/**
 * @brief Starts GUI task.
 *
 * @param [in] p_parameter Parameter that is passed to the task.
 */
static void _gui_task(void *p_parameter);

static void gui_queue_task(void *p_parameter);

//------------------------- STATIC DATA & CONSTANTS ---------------------------
static SemaphoreHandle_t p_gui_semaphore;

//------------------------------- GLOBAL DATA ---------------------------------

//------------------------------ PUBLIC FUNCTIONS -----------------------------
void gui_init()
{
    // 👇 Create queues first
    gui_send_to_main = xQueueCreate(5, sizeof(gui_send_data));
    gui_receive_from_main = xQueueCreate(5, sizeof(gui_received_data));

    gui_received_data.data.command1.button1 = 11;

    xTaskCreatePinnedToCore(_gui_task, "gui", 4096 * 2, NULL, 0, NULL, 1);
    xTaskCreate(&gui_queue_task, "GUI_Queue_Task", 2048, NULL, 5, NULL);
}

//---------------------------- PRIVATE FUNCTIONS ------------------------------
static void _gui_application_init(void)
{
    ui_init();
}

static void _lv_tick_timer(void *p_arg)
{
    (void)p_arg;

    lv_tick_inc(LV_TICK_PERIOD_MS);
}

static void _gui_task(void *p_parameter)
{

    (void)p_parameter;
    p_gui_semaphore = xSemaphoreCreateMutex();

    // Added for main communication
    gui_send_to_main = xQueueCreate(5, sizeof(gui_send_data));
    gui_receive_from_main = xQueueCreate(5, sizeof(gui_received_data));
    //

    lv_init();

    /* Initialize SPI or I2C bus used by the drivers */
    lvgl_driver_init();

    lv_color_t *p_buf1 = heap_caps_malloc(DISP_BUF_SIZE * sizeof(lv_color_t), MALLOC_CAP_DMA);
    assert(NULL != p_buf1);

    /* Use double buffered when not working with monochrome displays */
    lv_color_t *p_buf2 = heap_caps_malloc(DISP_BUF_SIZE * sizeof(lv_color_t), MALLOC_CAP_DMA);
    assert(NULL != p_buf2);
    static lv_disp_draw_buf_t disp_draw_buf;
    uint32_t                  size_in_px = DISP_BUF_SIZE;

    /* Initialize the working buffer */
    lv_disp_draw_buf_init(&disp_draw_buf, p_buf1, p_buf2, size_in_px);

    static lv_disp_drv_t disp_drv;
    disp_drv.hor_res = LV_HOR_RES_MAX;
    disp_drv.ver_res = LV_VER_RES_MAX;
    lv_disp_drv_init(&disp_drv);
    disp_drv.flush_cb = disp_driver_flush;

    disp_drv.draw_buf = &disp_draw_buf;
    lv_disp_drv_register(&disp_drv);

    /* Register an input device */
    static lv_indev_drv_t indev_drv;
    lv_indev_drv_init(&indev_drv);
    indev_drv.read_cb = touch_driver_read;
    indev_drv.type    = LV_INDEV_TYPE_POINTER;
    lv_indev_drv_register(&indev_drv);

    /* Create and start a periodic timer interrupt to call lv_tick_inc */
    const esp_timer_create_args_t periodic_timer_args = { .callback = &_lv_tick_timer, .name = "periodic_gui" };

    esp_timer_handle_t periodic_timer;
    ESP_ERROR_CHECK(esp_timer_create(&periodic_timer_args, &periodic_timer));
    ESP_ERROR_CHECK(esp_timer_start_periodic(periodic_timer, LV_TICK_PERIOD_MS * 1000));

    /* Create the demo application */
    _gui_application_init();

    for(;;)
    {
        /* Delay 1 tick (assumes FreeRTOS tick is 10ms */
        vTaskDelay(pdMS_TO_TICKS(10));

        /* Try to take the semaphore, call lvgl related function on success */
        if(pdTRUE == xSemaphoreTake(p_gui_semaphore, portMAX_DELAY))
        {
            lv_task_handler();
            xSemaphoreGive(p_gui_semaphore);
        }
    }

    /* A task should NEVER return */
    free(p_buf1);
    free(p_buf2);
    vTaskDelete(NULL);
}

static void gui_queue_task(void *p_parameter)
{

    (void)p_parameter;

    for(;;)
    {
        
        if (pdTRUE == xQueueReceive(gui_receive_from_main, &gui_received_data, pdMS_TO_TICKS(10)))
        {
            printf("(GUI) Received from main task: %d\n", gui_received_data.data.command1.button1);
        }
        vTaskDelay(1000 / portTICK_PERIOD_MS);

        if (pdTRUE == xQueueSend(gui_send_to_main, &gui_send_data, pdMS_TO_TICKS(10)))
        {
            //ESP_LOGI(TAG, "[Producer] Sent value: %lu", count);
            //count++;
            printf("GUI task send\n");
        }
    }


}


QueueHandle_t get_gui_send_queue(void){
    return gui_send_to_main;
}

QueueHandle_t get_gui_receive_queue(void){
    return gui_receive_from_main;
}



//---------------------------- INTERRUPT HANDLERS -----------------------------
