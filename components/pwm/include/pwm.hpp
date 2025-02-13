#pragma once
#include "esp_err.h"
#include "driver/ledc.h"
#include "hal/ledc_types.h"
#include "soc/clk_tree_defs.h"

#include "freertos/FreeRTOS.h"
#include "driver/dac_types.h"
#include "xtensa_timer.h"


/*
 * LEDC Chan to Group/Channel/Timer Mapping
 ** ledc: 0  => Group: 0, Channel: 0, Timer: 0 //HW Timer
 ** ledc: 1  => Group: 0, Channel: 1, Timer: 0  //HW Timer
 ** ledc: 2  => Group: 0, Channel: 2, Timer: 1  //HW Timer
 ** ledc: 3  => Group: 0, Channel: 3, Timer: 1  //HW Timer
 ** ledc: 4  => Group: 0, Channel: 4, Timer: 2  //HW Timer
 ** ledc: 5  => Group: 0, Channel: 5, Timer: 2   //HW Timer
 ** ledc: 6  => Group: 0, Channel: 6, Timer: 3  //HW Timer
 ** ledc: 7  => Group: 0, Channel: 7, Timer: 3    //HW Timer
 ** ledc: 8  => Group: 1, Channel: 0, Timer: 0 // HW timer manged by   software API
 ** ledc: 9  => Group: 1, Channel: 1, Timer: 0 // HW timer manged by   software API
 ** ledc: 10 => Group: 1, Channel: 2, Timer: 1 // HW timer manged by   software API
 ** ledc: 11 => Group: 1, Channel: 3, Timer: 1 // HW timer manged by   software API
 ** ledc: 12 => Group: 1, Channel: 4, Timer: 2 // HW timer manged by   software API
 ** ledc: 13 => Group: 1, Channel: 5, Timer: 2 // HW timer manged by   software API
 ** ledc: 14 => Group: 1, Channel: 6, Timer: 3 // HW timer manged by   software API
 ** ledc: 15 => Group: 1, Channel: 7, Timer: 3 // HW timer manged by   software API
 */

extern ledc_timer_config_t ledc_timer;
extern ledc_channel_config_t ledc_channel;
extern "C"    void setupledc(void*);
extern "C" void startpwm(void*);