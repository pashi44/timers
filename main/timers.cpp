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
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <iostream>
#include "gpio.h"
#include "queues.h"
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
        // &taskFunction,
        // vTaskDelete(th1);
        qh = xQueueCreateStatic(
            QUEUE_DEPTH,
            sizeof(s_udp_socket),
            queueArray,
            &qobj);
        if (qh == nullptr)
        {
            ESP_LOGE("queue object", "couldnt have dempry to crete  one");
            return;
        }
        // checking the kernel  queue
        queuedata.name = (char *)heap_caps_malloc(sizeof(char) * 50, MALLOC_CAP_8BIT);
        strcpy(queuedata.name, "All my friends are heathens");
        xQueueSendToBack(
            qh,
            &queuedata, (TickType_t)2); //  return s  a bBasetype_t  object

        s_udp_socket *datapointer = (s_udp_socket *)(queueArray);

        if (datapointer != NULL)
            ESP_LOGI("from  queue", "%s\n", (*datapointer).name);

        heap_caps_free(queuedata.name);
    }
#ifdef __cplusplus
}
#endif
