#ifndef TCRT5000_H
#define TCRT5000_H

#ifdef __cplusplus
extern "C" {
#endif

#include "driver/adc.h"

/**
 * @brief Structure representing a TCRT5000 sensor instance.
 */
typedef struct {
    adc1_channel_t channel;  ///< ADC channel used for sensor readings
} tcrt5000_t;

/**
 * @brief Initialize the TCRT5000 sensor.
 *
 * Configures the ADC channel that the sensor is connected to.
 *
 * @param sensor Pointer to a tcrt5000_t instance.
 * @param channel ADC channel (from adc1_channel_t) that the sensor uses.
 * @return int Returns 0 on success, or -1 on error.
 */
int tcrt5000_init(tcrt5000_t *sensor, adc1_channel_t channel);

/**
 * @brief Get a raw ADC measurement from the TCRT5000 sensor.
 *
 * Reads the raw ADC value from the sensor.
 *
 * @param sensor Pointer to an initialized tcrt5000_t instance.
 * @return int Raw ADC reading, or -1 on error.
 */
int tcrt5000_get_raw_measurement(tcrt5000_t *sensor);

/**
 * @brief Maps a raw ADC measurement to a distance in millimeters using calibration data.
 *
 * @param adc_reading The raw ADC value from the sensor.
 * @return float The estimated distance in millimeters.
 */
float tcrt5000_map_to_distance(int adc_reading);

/**
 * @brief Convenience function to get the distance measurement in millimeters.
 *
 * @param sensor Pointer to an initialized tcrt5000_t instance.
 * @return float The estimated distance in millimeters.
 */
float tcrt5000_get_distance(tcrt5000_t *sensor);

#ifdef __cplusplus
}
#endif

#endif /* TCRT5000_H */
