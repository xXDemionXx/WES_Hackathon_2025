#include "TCRT5000.h"
#include "esp_log.h"
#include "driver/adc.h"
#include "esp_err.h"

#define ADC_ATTEN ADC_ATTEN_DB_11      // Sets the attenuation (adjust if needed)
#define ADC_WIDTH ADC_WIDTH_BIT_12     // 12-bit ADC resolution

static const char *TAG = "TCRT5000";

/* Calibration table for ADC readings versus distance (in millimeters).
   Replace these values with your own calibration data. */
typedef struct {
    int adc;
    float distance; // in millimeters
} calib_point_t;

#define CALIB_POINTS 6
static calib_point_t calib_table[CALIB_POINTS] = {
    {3500, 50.0f},  // Close object: high ADC -> high distance (mm)
    {3000, 40.0f},
    {2500, 30.0f},
    {2000, 20.0f},
    {1500, 10.0f},
    {1000, 5.0f}    // Far object: low ADC -> low distance (mm)
};

int tcrt5000_init(tcrt5000_t *sensor, adc1_channel_t channel)
{
    if (sensor == NULL) {
        ESP_LOGE(TAG, "Sensor pointer is NULL");
        return -1;
    }
    
    sensor->channel = channel;
    
    // Configure ADC1 width and attenuation.
    ESP_ERROR_CHECK(adc1_config_width(ADC_WIDTH));
    ESP_ERROR_CHECK(adc1_config_channel_atten(channel, ADC_ATTEN));
    
    return 0;
}

int tcrt5000_get_raw_measurement(tcrt5000_t *sensor)
{
    if (sensor == NULL) {
        ESP_LOGE(TAG, "Sensor pointer is NULL");
        return -1;
    }
    
    // Read the raw ADC value.
    return adc1_get_raw(sensor->channel);
}

float tcrt5000_map_to_distance(int adc_reading)
{
    // Clamp ADC reading to calibration range.
    if (adc_reading >= calib_table[0].adc)
        return calib_table[0].distance;
    if (adc_reading <= calib_table[CALIB_POINTS - 1].adc)
        return calib_table[CALIB_POINTS - 1].distance;

    // Find the two calibration points between which the adc_reading lies.
    for (int i = 0; i < CALIB_POINTS - 1; i++) {
        if (adc_reading <= calib_table[i].adc && adc_reading >= calib_table[i + 1].adc) {
            float slope = (calib_table[i + 1].distance - calib_table[i].distance) /
                          (calib_table[i + 1].adc - calib_table[i].adc);
            return calib_table[i].distance + slope * (adc_reading - calib_table[i].adc);
        }
    }
    
    // Should not reach here.
    return -1.0f;
}

float tcrt5000_get_distance(tcrt5000_t *sensor)
{
    int raw = tcrt5000_get_raw_measurement(sensor);
    if (raw < 0) {
        return -1.0f;
    }
    return tcrt5000_map_to_distance(raw);
}
