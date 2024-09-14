#ifndef __TIMH__
#define __TIMH__

#include <FreeRTOSConfig.h>
#include <freertos/FreeRTOS.h>
#include <freertos/idf_additions.h>

#include "esp_log.h"
#include <driver/gpio.h>
#include <freertos/task.h>
#include <freertos/stack_macros.h>
#include <freertos/queue.h>

extern gpio_num_t led_array[4];

struct s_udp_socket
{
    int socket;
    int retries;
};

extern TimerHandle_t xTimer;

void gpioSetup();

void my_timer_cb(TimerHandle_t);

void *udp_timeout_cb(TimerHandle_t);

extern void setup17(void *args);
#endif
