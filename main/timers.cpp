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
        // void *start = (void *)heap_caps_malloc(sizeof(BaseType_t), (  MALLOC_CAP_DMA | MALLOC_CAP_32BIT));
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

        else
        {
            queuedata.name = (char *)heap_caps_malloc(sizeof(char) * 50, MALLOC_CAP_8BIT);
            strcpy(queuedata.name, "All my friends are heathens");
            rc = xQueueSendToBack(
                qh,
                &queuedata, (TickType_t)2); //  return s  a bBasetype_t  object

            // s_udp_socket *datapointer = (s_udp_socket *)(queueArray);
            //
            // if (datapointer != NULL)
            // ESP_LOGI("from  queue", "%s\n", (*datapointer).name);
            //
            if (rc == pdPASS)
            {
                ESP_LOGI("queue info", "added  to  queue\n");
            }
            else
            {
                //  (rc == pdFAIL || rc == errQUEUE_FULL)
                ESP_LOGE("Queue Info", "addig fialed to  queue or no space space at  all\
                                   try delay  timer to be large \n");
                return;
            }

            s_udp_socket rData;
            rc = xQueueReceive(
                qh,
                &rData,

                (TickType_t)3);
            if (rc == pdPASS)
            {

                s_udp_socket *pointertdata;
                pointertdata = &rData;

                ESP_LOGI("queue info ", "  address of rdata..name%p\n", (void *)&(rData));
                ESP_LOGI("queue info ", "  address of rdata..name%p\n", (void *)&((rData).name));

                ESP_LOGI("queue info ", "  address of rdata..name%c\n", *((rData).name));

                ESP_LOGI("queue info ", "  address of rdata..name%c\n", *(((rData).name) + 4));
                ESP_LOGI("queue info ", "  address of rdata..name%p\n", (void *)pointertdata->name);
                // ESP_LOGI("queue info ", "  address of rdata..name%s\n", pointertdata);

                ESP_LOGI("queue info ", "  address of rdata..name%p\n", (void *)(pointertdata->name + 3));

                ESP_LOGI("queue info ", "%s\n", rData.name);
            }
            else
            {
                if (rc == errQUEUE_EMPTY)
                {
                    ESP_LOGE("queue INFO", "an empty queue\n");
                    return;
                }
            }

            heap_caps_free(queuedata.name);
        }
        vQueueDelete(qh);
    }
#ifdef __cplusplus
}
#endif
