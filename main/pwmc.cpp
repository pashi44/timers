#include <stdio.h>
#include "driver/adc.h"
#include "esp_adc_cal.h"
#include "freertos/FreeRTOS.h"
#define DEFAULT_VREF 1100           // Default reference voltage (mV)
#define ADC1_CHANNEL ADC1_CHANNEL_6 // GPIO34

extern "C" void app_main()
{
    int adc_value;
    uint32_t voltage;
    esp_adc_cal_characteristics_t adc_chars;

    // Configure ADC1
    adc1_config_width(ADC_WIDTH_BIT_12);                      // 12-bit resolution
    adc1_config_channel_atten(ADC1_CHANNEL, ADC_ATTEN_DB_11); // 0-3.9V range

    // Characterize ADC
    esp_adc_cal_characterize(ADC_UNIT_1, ADC_ATTEN_DB_11, ADC_WIDTH_BIT_12, DEFAULT_VREF, &adc_chars);

    while (1)
    {
        adc_value = adc1_get_raw(ADC1_CHANNEL);
        voltage = esp_adc_cal_raw_to_voltage(adc_value, &adc_chars); // Convert to mV
        printf("ADC Raw: %d, Voltage: %ld mV\n", adc_value, voltage);

        vTaskDelay(pdMS_TO_TICKS(1000)); // Delay 1 second
    }
}
