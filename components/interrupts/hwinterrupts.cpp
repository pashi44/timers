#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "hwinterrupts.hpp"     
#include "esp_err.h"
#include"esp_log.h"
//core one one esp32 board other may  vary

gpio_config_t io_conf= {

    .pin_bit_mask = (1ULL << GPIO_pin),

    .mode = GPIO_MODE_INPUT,

    .pull_up_en = GPIO_PULLUP_ENABLE,

    .pull_down_en = GPIO_PULLDOWN_DISABLE,

    .intr_type = GPIO_INTR_POSEDGE // Falling edge interrupt

};

esp_intr_cpu_affinity_t  intr_cpucore =  ESP_INTR_CPU_AFFINITY_1 ;
intr_handle_t intr_handler = nullptr;  

esp_err_t  errgpio= gpio_config(&io_conf);

void __attribute__((section("iram1"))) gpio_isr_handler(void *arg)


{  gpio_reset_pin(GPIO_NUM_17);


    gpio_set_direction(GPIO_NUM_17,GPIO_MODE_OUTPUT);

while(1){

    gpio_set_level(GPIO_NUM_17, 1);

}
gpio_set_level(GPIO_NUM_17, 0);     

vTaskDelete(nullptr);
}





