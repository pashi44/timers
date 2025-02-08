#include <stdio.h>
#include "hal/ledc_types.h"
#include "esp_log.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include "channe.hpp"
#include "freertos/idf_additions.h"

TaskHandle_t taskHnadlerone;
extern  "C" 
    void app_main()


{


xTaskCreatePinnedToCore(

set_timers,
"setting up  the manual timer",4096,NULL,2,&taskHnadlerone , 1);

xTaskCreatePinnedToCore( [](void*)->void{
    while (1)
    {
        if (timer_flag)
        {



            ESP_LOGI("", "%s\t  %ld", "Timer interrupt triggered!",xTaskGetTickCount());


            // Log the current timer count
            timer_flag = false; // Reset flag
        }
        vTaskDelay(pdMS_TO_TICKS(100)); // Sleep for 100 ms
    }},

"event trigger fucntion  based on  timerset",
2048,
NULL,2, NULL,0
);

}

