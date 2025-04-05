#ifndef HCSR04_H
#define HCSR04_H
#include "driver/gpio.h"

#ifdef __cplusplus
extern "C" {
#endif
#define US_TRIGGER_PIN GPIO_NUM_26
#define US_ECHO_PIN GPIO_NUM_27
/**
 * @brief Structure representing an HC-SR04 sensor instance.
 */
typedef struct {
    int trigger_pin;  ///< GPIO number for trigger
    int echo_pin;     ///< GPIO number for echo
} hc_sr04_t;

/**
 * @brief Initializes the HC-SR04 sensor.
 *
 * This function configures the trigger pin as output and the echo pin as input.
 *
 * @param sensor Pointer to an hc_sr04_t instance.
 * @param trigger_pin GPIO number to be used for the trigger.
 * @param echo_pin GPIO number to be used for the echo.
 * @return int Returns 0 on success.
 */
int hc_sr04_init(hc_sr04_t *sensor, int trigger_pin, int echo_pin);

/**
 * @brief Measures the distance using the HC-SR04 sensor.
 *
 * The function sends a 10 µs pulse to trigger the sensor, waits for the echo, and calculates
 * the distance in centimeters based on the duration of the echo pulse. A timeout is applied for both
 * waiting phases.
 *
 * @param sensor Pointer to an initialized hc_sr04_t instance.
 * @return float Distance in centimeters, or -1.0 in case of a timeout/error.
 */
float hc_sr04_measure_distance(hc_sr04_t *sensor);

/**
 * @brief Performs any necessary cleanup.
 *
 * For this implementation on ESP32, no explicit cleanup is required.
 */
void hc_sr04_cleanup(void);

#ifdef __cplusplus
}
#endif

#endif /* HC_SR04_H */