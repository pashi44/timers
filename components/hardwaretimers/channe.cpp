#include "channe.hpp"



#include "ledpwm.hpp"
#include "esp_log.h"
#include "esp_err.h"

volatile bool timer_flag = false;
gptimer_handle_t timer_handler = NULL;

// **ISR  hook fucntion
bool __attribute__((section(".iram1"))) timer_isr_callback(gptimer_handle_t timer,
                                                           const gptimer_alarm_event_data_t *edata, void *user_ctx)
{
    if (increasing)
    {
        duty_cycle += 1;
        if (duty_cycle >= BRIGHTNESS_STEPS)
            increasing = false; // Start dimming
    }
    else
    {
        duty_cycle -= 1;
        if (duty_cycle == 0)
            increasing = true; // Start brightening
    }

    // Adjust LED brightness
    uint32_t high_time_us = (duty_cycle * TIMER_RESOLUTION_HZ) / (BRIGHTNESS_STEPS * PWM_FREQUENCY_HZ);
    uint32_t low_time_us = (TIMER_RESOLUTION_HZ / PWM_FREQUENCY_HZ) - high_time_us;

    gpio_set_level(PWM_OUTPUT_PIN, duty_cycle > 0); // Turn ON/OFF based on duty cycle

    // Update timer for next cycle
    // gptimer_alarm_config_t next_alarm = {
        // .alarm_count = increasing ? high_time_us : low_time_us,
        // .reload_count = 0,
        // .flags = {.auto_reload_on_alarm = true}};
// 
    // gptimer_set_alarm_action(timer_handler, &next_alarm);

    timer_flag = true;
    return true; // Notify that the event has been handled
}
 gptimer_config_t timer_config = {
        .clk_src =  GPTIMER_CLK_SRC_APB, //closck source from 80mhz using pll on 40mhz xcl
        .direction = GPTIMER_COUNT_UP, //dirction to count up
        .resolution_hz =    1000000,  //1000khz
                .intr_priority = 0, //interruot pririty  relative
        .flags = {
            .intr_shared = true, //shared interrupt for alaram structure
            .allow_pd = 0,   //deprecated
            .backup_before_sleep = 0, //deprecated
        }};
//alaram set to  trigger interruot since we have shred the interrupt 
  gptimer_alarm_config_t alarm_config = {
        .alarm_count =   1000000,
        .reload_count = 0, //track   num of calling the isr callback
        .flags = {.auto_reload_on_alarm =   true  
        } //trigger  the alaram to  loop

    };
void  set_timers(void*){

    //event callback handler
    gptimer_event_callbacks_t cbs = {
        .on_alarm = timer_isr_callback
    };
    initPWM(nullptr);

    ESP_ERROR_CHECK(gptimer_new_timer(&timer_config, &timer_handler));            // init the timer object
    ESP_ERROR_CHECK(gptimer_set_alarm_action(timer_handler, &alarm_config));      // init the alarm object
    ESP_ERROR_CHECK(gptimer_register_event_callbacks(timer_handler, &cbs, NULL)); // register the callbcak
    ESP_ERROR_CHECK(gptimer_enable(timer_handler));                               // enable the timer
    ESP_ERROR_CHECK(gptimer_start(timer_handler));                                // start the the timer we manually config

// vTaskDelayUntil((TickType_t*)xTaskGetTickCount(), 1000);
vTaskDelete(nullptr);
}

   

