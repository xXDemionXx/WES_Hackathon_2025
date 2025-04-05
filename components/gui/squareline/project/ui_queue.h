#ifndef UI_QUEUE_H
#define UI_QUEUE_H

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

/* Function prototype for the producer task */
void ui_queue_task(void *p_param);

#endif /* UI_QUEUE_H */
