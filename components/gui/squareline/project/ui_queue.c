#include "ui_queue.h"
#include "esp_log.h"
#include "freertos/queue.h"
#include "ui.h"

/* Declare the external queue handle defined in app_main.c */
extern QueueHandle_t s_queue_handle;

#ifndef TASK_DELAY_MS
#define TASK_DELAY_MS (1000U)
#endif

car_danger_level_t car_danger_level;



void ui_queue_task(void *p_param)
{
    (void)p_param;
    for (;;)
    {
    
        // Receive data from GUI
        if (xQueueReceive(s_queue_handle, &car_danger_level, pdMS_TO_TICKS(10))) {
            printf("Received from gui task: %d\n", car_danger_level);

            lv_obj_clear_flag(ui_smallarcr, LV_OBJ_FLAG_HIDDEN);
            lv_obj_clear_flag(ui_smallarcl, LV_OBJ_FLAG_HIDDEN);
            lv_obj_clear_flag(ui_midarcl, LV_OBJ_FLAG_HIDDEN);
            lv_obj_clear_flag(ui_midarcr, LV_OBJ_FLAG_HIDDEN);
            lv_obj_clear_flag(ui_bigarcl, LV_OBJ_FLAG_HIDDEN);
            lv_obj_clear_flag(ui_bigarcr, LV_OBJ_FLAG_HIDDEN);

            switch (car_danger_level){
 
                case NO_DANGER:
    
                break;
     
                case DANGER_L1:

                    lv_obj_add_flag(ui_bigarcl, LV_OBJ_FLAG_HIDDEN);
                    lv_obj_add_flag(ui_bigarcr, LV_OBJ_FLAG_HIDDEN);
    
                break;
     
                case DANGER_L2:

                    lv_obj_add_flag(ui_bigarcr, LV_OBJ_FLAG_HIDDEN);
                    lv_obj_add_flag(ui_bigarcl, LV_OBJ_FLAG_HIDDEN);
                    lv_obj_add_flag(ui_midarcl, LV_OBJ_FLAG_HIDDEN);
                    lv_obj_add_flag(ui_midarcr, LV_OBJ_FLAG_HIDDEN);

    
                break;
     
                case DANGER_L3:
                    lv_obj_add_flag(ui_smallarcr, LV_OBJ_FLAG_HIDDEN);
                    lv_obj_add_flag(ui_smallarcl, LV_OBJ_FLAG_HIDDEN);
                    lv_obj_add_flag(ui_midarcl, LV_OBJ_FLAG_HIDDEN);
                    lv_obj_add_flag(ui_midarcr, LV_OBJ_FLAG_HIDDEN);
                    lv_obj_add_flag(ui_bigarcl, LV_OBJ_FLAG_HIDDEN);
                    lv_obj_add_flag(ui_bigarcr, LV_OBJ_FLAG_HIDDEN);
                break;
    
                }
     
        }
    }
}