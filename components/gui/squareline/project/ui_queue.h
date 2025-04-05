#ifndef UI_QUEUE_H
#define UI_QUEUE_H

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

/* Function prototype for the producer task */
void ui_queue_task(void *p_param);

typedef enum{
    NO_DANGER,
    DANGER_L1,
    DANGER_L2,
    DANGER_L3
}car_danger_level_t;

#endif /* UI_QUEUE_H */
