#ifndef ___LEDPWMHPP__
#define ___LEDPWMHPP__

#include "freertos/FreeRTOS.h"
#include <stdio.h>
#include <iostream>
#include "driver/ledc.h"

 
#include "driver/dac_oneshot.h" // For one-time DAC output
#include "driver/dac_cosine.h" // For cosine waveform generation
#include "driver/dac_continuous.h" // For continuous DAC output

#define PWM_OUTPUT_PIN GPIO_NUM_17

#define TIMER_RESOLUTION_HZ (timer_config.resolution_hz) // 1MHz GPTimer resolution
#define PWM_FREQUENCY_HZ 1000       // 1kHz PWM frequency for smooth dimming
#define BRIGHTNESS_STEPS 100        // Number of brightness levels (0-100)
#define DIMMING_SPEED 10            // Speed of dimming (higher = slower change)

extern "C" volatile uint32_t duty_cycle;; // Current duty cycle (0-100%)
extern "C" volatile bool increasing ;
extern "C" uint32_t high_time_us;
extern "C" uint32_t low_time_us ;
extern "C" void initPWM(void *);

#endif //  ___LEDPWMHPP__
