#include "pwm.hpp"

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include  "esp_log.h"
#include "esp_err.h"



extern "C"  void app_main(){

    xTaskCreatePinnedToCore(
        &setupledc
        ,
        "example_ledc_init", 2048, NULL, 5, NULL, 0);





xTaskCreatePinnedToCore(
    &startpwm,
    "startpwm",
    2048,
    NULL,
    5,
    NULL, 0);





}