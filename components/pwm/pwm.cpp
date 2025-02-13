#include "pwm.hpp"
#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "driver/gpio.h"
#include "esp_log.h"
/* Warning:
 * For ESP32, ESP32S2, ESP32S3, ESP32C3, ESP32C2, ESP32C6, ESP32H2, ESP32P4 targets,
 * when LEDC_DUTY_RES selects the maximum duty resolution (i.e. value equal to SOC_LEDC_TIMER_BIT_WIDTH),
 * 100% duty cycle is not reachable (duty cannot be set to (2 ** SOC_LEDC_TIMER_BIT_WIDTH)).
 */
         ledc_timer_config_t ledc_timer = {
    .speed_mode = LEDC_LOW_SPEED_MODE,
    .duty_resolution   =  LEDC_TIMER_12_BIT,
    .timer_num = LEDC_TIMER_0,
    .freq_hz = 100, // Set output frequency at 4 kHz
    // .clk_cfg = 1
    
};
      ledc_channel_config_t ledc_channel = {
         .gpio_num = GPIO_NUM_17,
.speed_mode = LEDC_LOW_SPEED_MODE,
         .channel = LEDC_CHANNEL_0,
         .timer_sel = LEDC_TIMER_0,
         .duty = 0

     };


 void setupledc(void * ){

     ESP_ERROR_CHECK(ledc_timer_config(&ledc_timer));
     // Prepare and then apply the LEDC PWM channel configuration
     ESP_ERROR_CHECK(ledc_channel_config(&ledc_channel));

     vTaskDelete(nullptr);
}





 void startpwm(void *)
{
    int duty_percent = 30; // Start with 30%

    while (true)
    {
        uint32_t duty = (4096 * duty_percent) / 100;
        ledc_set_duty(ledc_channel.speed_mode, ledc_channel.channel, duty);
        ledc_update_duty(ledc_channel.speed_mode, ledc_channel.channel);
        ESP_LOGI("PWM", "Duty Cycle set to %ld", duty_percent);

        // Toggle duty cycle between 0 and 30%
        duty_percent = (duty_percent == 30) ? 0 : 30;
        vTaskDelay(pdMS_TO_TICKS(2000)); // Change every 2000 milliseconds (2 seconds)
    }



}