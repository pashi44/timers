#include "queues.h"

#include <string.h>
// void *start = (void *)heap_caps_malloc(sizeof(BaseType_t), (  MALLOC_CAP_DMA | MALLOC_CAP_32BIT));
// if (start != NULL)
// start = th1;
// &taskFunction,
// vTaskDelete(th1);

void queueHandler(void *argps)
{
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
            &queuedata, (TickType_t)portMAX_DELAY); //  return s  a bBasetype_t  object

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
    qh = nullptr;
}