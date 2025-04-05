#include "hcsr04.h"
#include "driver/gpio.h"
#include "esp_timer.h"
#include "esp_log.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_rom_sys.h"

#define TAG "HC_SR04"
#define TIMEOUT_US 30000  // Timeout in microseconds (30 ms)


/**
 * @brief Initializes the sensor by configuring the GPIO pins.
 */
int hc_sr04_init(hc_sr04_t *sensor, int trigger_pin, int echo_pin)
{
    sensor->trigger_pin = trigger_pin;
    sensor->echo_pin = echo_pin;

    // Configure trigger pin as output.
    gpio_config_t io_conf = {
        .pin_bit_mask = (1ULL << sensor->trigger_pin),
        .mode = GPIO_MODE_OUTPUT,
        .pull_up_en = GPIO_PULLUP_DISABLE,
        .pull_down_en = GPIO_PULLDOWN_DISABLE,
        .intr_type = GPIO_INTR_DISABLE,
    };
    gpio_config(&io_conf);

    // Configure echo pin as input.
    io_conf.pin_bit_mask = (1ULL << sensor->echo_pin);
    io_conf.mode = GPIO_MODE_INPUT;
    gpio_config(&io_conf);

    // Ensure trigger is low.
    gpio_set_level(sensor->trigger_pin, 0);

    // Allow sensor to settle.
    vTaskDelay(pdMS_TO_TICKS(50));
    return 0;
}

/**
 * @brief Measures the distance by sending a trigger pulse and reading the echo.
 */
float hc_sr04_measure_distance(hc_sr04_t *sensor)
{
    // Ensure a clean low state.
    gpio_set_level(sensor->trigger_pin, 0);
    esp_rom_delay_us(2);



    // Send a 10 µs high pulse.
    gpio_set_level(sensor->trigger_pin, 1);
    esp_rom_delay_us(10);
    gpio_set_level(sensor->trigger_pin, 0);

    int64_t start_time = esp_timer_get_time();
    int64_t timeout_time = start_time + TIMEOUT_US;

    // Wait for echo pin to go HIGH (start of pulse).
    while (gpio_get_level(sensor->echo_pin) == 0) {
        if (esp_timer_get_time() > timeout_time) {
            ESP_LOGE(TAG, "Timeout waiting for echo high");
            return -1.0;
        }
    }
    int64_t echo_start = esp_timer_get_time();

    // Wait for echo pin to go LOW (end of pulse).
    timeout_time = echo_start + TIMEOUT_US;
    while (gpio_get_level(sensor->echo_pin) == 1) {
        if (esp_timer_get_time() > timeout_time) {
            ESP_LOGE(TAG, "Timeout waiting for echo low");
            return -1.0;
        }
    }
    int64_t echo_end = esp_timer_get_time();

    // Compute the pulse duration in microseconds.
    int64_t pulse_duration = echo_end - echo_start;

    // Calculate distance in centimeters.
    // Speed of sound ~343 m/s equals ~0.0343 cm/µs.
    float distance_cm = (pulse_duration / 2.0f) * 0.0343f;
    return distance_cm;
}
