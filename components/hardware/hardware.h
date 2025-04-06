/**
* @file hardware.h
*
* @brief See the source file.
*/

#ifndef __HARDWARE_H__
#define __HARDWARE_H__

#ifdef __cplusplus
extern "C" {
#endif

//--------------------------------- INCLUDES ----------------------------------

//---------------------------------- MACROS -----------------------------------

#define HARDWARE_SEND_QUEUE_LENGTH              5
#define HARDWARE_SEND_QUEUE_WAIT                100

#define PI 3.14159265
#define SAMPLE_RATE 8000
#define TONE_FREQ 1000
#define BEEP_DURATION_MS 100

#define STAGE1_GAP 700
#define STAGE2_GAP 300
#define STAGE3_GAP 80
#define STAGE4_GAP 30
#define STAGE1_TIME 3333
#define STAGE2_TIME 3333
#define STAGE3_TIME 3333
#define STAGE4_TIME 2000

/**
 * @brief Structure that will be sent over the queue.
 * 
 */
typedef enum{
    UL_SENSOR,
    BUTTONS,
    JOYSTICK,
}hardware_send_message_t;

typedef struct{
    uint8_t button1;
    uint8_t button2;
}buttons_data_t;

typedef struct{
    uint8_t x_axis;
    uint8_t y_axis;
}joystick_data_t;

typedef struct{
    uint8_t distance;
}ultrasonic_data_t;

typedef union{  // Depending on the enum we want to send different data
    buttons_data_t buttons_data;
    joystick_data_t joystick_data;
    ultrasonic_data_t ultrasonic_data;
}hardware_send_message_data_t;

typedef struct{
    hardware_send_message_t message_type;
    hardware_send_message_data_t data;
}hardware_send_queue_data_t;



#define HARDWARE_RECEIVE_QUEUE_LENGTH           5
#define HARDWARE_RECEIVE_QUEUE_WAIT             10

/**
 * @brief Structure that will be received over the queue.
 * 
 */
typedef enum{
    COMMAND1,
    COMMAND2
}hardware_receive_message_t;

typedef struct{
    uint8_t button1;
    uint8_t button2;
}command1_data_t;

typedef struct{
    uint8_t x_axis;
    uint8_t y_axis;
}comman2_data_t;

typedef union{  // Depending on the enum we want to send different data
    command1_data_t command1;
    comman2_data_t command2;
}hardware_receive_message_data_t;

typedef struct{
    hardware_receive_message_t message_type;
    hardware_receive_message_data_t data;
}hardware_receive_queue_data_t;






/**
 * @brief Structure that will be received over the queue.
 * 
 */


//-------------------------------- DATA TYPES ---------------------------------

//---------------------- PUBLIC FUNCTION PROTOTYPES --------------------------

/**
 * @brief Initializes hardware.
 * 
 */
void hardware_init(void);
void play_beep_blocking(int duration_ms);
void stage1_task(void *pvParam);
void stage1_slow_beeps();
void stage2_task(void *pvParam);
void stage2_medium_beeps();
void stage3_task(void *pvParam);
void stage3_fast_beeps();
void stage4_task(void *pvParam);
void stage4_constant_tone();
void sound_generator();
void init_speeker_tasks(void);

QueueHandle_t get_hardware_send_queue(void);
QueueHandle_t get_hardware_receive_queue(void);

#ifdef __cplusplus
}
#endif

#endif // __HARDWARE_H__