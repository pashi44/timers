#ifndef __GPIOH__
#define __GPIOH__

#include <FreeRTOSConfig.h>
#include <freertos/FreeRTOS.h>
#include <freertos/idf_additions.h>
#include <driver/gpio.h>
#include <freertos/task.h>
#include <freertos/stack_macros.h>
#include <freertos/queue.h>
#include <freertos/timers.h>
#include "esp_log.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <iostream>
#include "tim.h"
typedef struct
{

    gpio_num_t gpio;

    uint_fast8_t state;
    // byte(state);
    unsigned int delaySeconds;
    TaskHandle_t taskh;

} ledStruct;

extern ledStruct led[2];
extern void taskFunction(void *);

// static TaskHandle_t th1 = NULL;
// static TaskHandle_t th2 = NULL;
static StackType_t staticstack[2048 / sizeof(StackType_t)];
static StackType_t staticstack1[2048 / sizeof(StackType_t)];

static StaticTask_t tcb;
static StaticTask_t tcb1;
extern TaskHandle_t th1;
extern TaskHandle_t th2;

extern void
taskFunc(void *);

#endif