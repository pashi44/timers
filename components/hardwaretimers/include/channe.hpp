#ifndef __CHANNE_HPP__
#define __CHANNE_HPP__
#include "driver/gptimer.h"
#include "freertos/FreeRTOS.h"  //free  rtos sdk
#include "freertos/portmacro.h"
#include "freertos/task.h"

#include "xtensa_timer.h"
extern     volatile bool timer_flag; // Declare the global variable
     extern gptimer_handle_t timer_handler;


     extern "C" gptimer_config_t timer_config;

     extern "C" gptimer_alarm_config_t alarm_config;
     extern "C" bool __attribute__((section(".iram1"))) timer_isr_callback(gptimer_handle_t, const gptimer_alarm_event_data_t *, void *);
     extern "C" void set_timers(void*);

#endif
    