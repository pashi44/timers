#include <FreeRTOSConfig.h>
#include <freertos/FreeRTOS.h>
#include <freertos/idf_additions.h>
#include <driver/gpio.h>
#include <freertos/task.h>
#include <freertos/portmacro.h>
#include <freertos/stack_macros.h>
#include <freertos/queue.h>
#include <freertos/timers.h>
#include "esp_log.h"
#include <stdio.h>
#include <assert.h>

#include <stdlib.h>
#include <unistd.h>
#include <iostream>
#include "gpio.h"
//  ******************************* mian  _sectio  ****************

TaskHandle_t th1 = NULL;

TaskHandle_t th2 = NULL;

#ifdef __cplusplus
extern "C"
{
#endif
    void app_main()
    {

        // void *start = (void *)heap_caps_malloc(sizeof(BaseType_t), (2 || 1));
        // if (start != NULL)
        // start = th1;

        xTaskCreate(&taskFunc,
                    "led task2", // 1990
                    2048, NULL,
                    1, &th1);

        xTaskCreate(

            &taskFunction,
            "led task1", 2048, NULL,
            1, &th2);

        vTaskDelay(pdMS_TO_TICKS(2000));
        vTaskDelete(th1);
        th1 = NULL;
        vTaskDelete(th2);
        th2 = NULL;

        ESP_LOGI("taskFunc ", "%d\t  %d", uxTaskGetStackHighWaterMark(th1), uxTaskGetStackHighWaterMark(th2));
    }
#ifdef __cplusplus
}
#endif
