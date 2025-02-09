#include "ledpwm.hpp"
#include "driver/adc.h"
#include "driver/ledc.h"
#include "esp_adc_cal.h"
#include <stdio.h>

volatile uint32_t duty_cycle = 0; // Current duty cycle (0-100%)
volatile bool increasing = true;  // Direction of brightness change
void initPWM(void *)


{

    gpio_reset_pin(PWM_OUTPUT_PIN);
    gpio_set_direction(PWM_OUTPUT_PIN, GPIO_MODE_OUTPUT);

}
