/**
* @file gui.h

* @brief See the source file.
* 
* COPYRIGHT NOTICE: (c) 2022 Byte Lab Grupa d.o.o.
* All rights reserved.
*/

#ifndef __GUI_H__
#define __GUI_H__

#ifdef __cplusplus
extern "C" {
#endif

//--------------------------------- INCLUDES ----------------------------------
#include "freertos/queue.h"
//---------------------------------- MACROS -----------------------------------

#define GUI_SEND_QUEUE_LENGTH               5
#define GUI_SEND_QUEUE_WAIT                 100

/**
 * @brief Structure that will be sent over the queue.
 * 
 */
typedef enum{
    GUI_MAIN_MESSAGE,
    GUI_SIDE_MESSAGE
}gui_send_message_t;

typedef struct{
    int button1;
    int button2;
}gui_send_data_1_t;

typedef struct{
    int x_axis;
    int y_axis;
}gui_send_data_2_t;

typedef union{  // Depending on the enum we want to send different data
    gui_send_data_1_t buttons_data;
    gui_send_data_2_t joystick_data;
}gui_send_message_data_t;

typedef struct{
    gui_send_message_t message_type;
    gui_send_message_data_t data;
}gui_send_queue_data_t;


#define GUI_RECEIVE_QUEUE_LENGTH           5
#define GUI_RECEIVE_QUEUE_WAIT             10

/**
 * @brief Structure that will be received over the queue.
 * 
 */
typedef enum{
    GUI_COMMAND1,
    GUI_COMMAND2
}gui_receive_message_t;

typedef struct{
    int button1;
    int button2;
}gui_receive_data_1_t;

typedef struct{
    int x_axis;
    int y_axis;
}gui_receive_data_2_t;

typedef union{  // Depending on the enum we want to send different data
    gui_receive_data_1_t command1;
    gui_receive_data_2_t command2;
}gui_receive_message_data_t;

typedef struct{
    gui_receive_message_t message_type;
    gui_receive_message_data_t data;
}gui_receive_queue_data_t;
//-------------------------------- DATA TYPES ---------------------------------

//---------------------- PUBLIC FUNCTION PROTOTYPES --------------------------

/**
 * @brief Initializes LVGL, TFT drivers and input drivers and starts task needed for GUI operation.
 * 
 */
void gui_init(void);


//QueueHandle_t get_gui_send_queue(void);
//QueueHandle_t get_gui_receive_queue(void);


#ifdef __cplusplus
}
#endif

#endif // __GUI_H__
