
#include "tim.h"

#include "gpio.h"
void setupFunctions()
{

    if (xTaskCreate(&taskFunc,
                    "led task2", // 1990
                    2048, NULL,
                    1, &th1) != pdPASS)
        ESP_LOGE("", "failed in thread");

    if (xTaskCreate(&taskFunction,
                    "led task1",
                    2048, NULL,
                    1, &th2) != pdPASS)
        ESP_LOGE("", "failed");
    vTaskDelay(pdMS_TO_TICKS(2000));
    if (th1 != NULL)
    {
        th1 = NULL;
    }
    if (th2 != NULL)
    {
        vTaskDelete(th2);
        th2 = NULL;
    }
    ESP_LOGI("taskFunc ", "%d\t  %d", uxTaskGetStackHighWaterMark(th1), uxTaskGetStackHighWaterMark(th2));
}

void taskFunction(void *args)
{
    gpio_reset_pin(*(led_array));
    gpio_set_direction(*(led_array), GPIO_MODE_OUTPUT);
    gpio_reset_pin(*(led_array + 3));
    gpio_set_direction(*(led_array + 3), GPIO_MODE_OUTPUT);
    while (1)
    {
        gpio_set_level(*(led_array), 1);
        vTaskDelay(pdMS_TO_TICKS(500));
        gpio_set_level(*(led_array), 0);
        vTaskDelay(pdMS_TO_TICKS(500));
    }
}

void taskFunc(void *args)
{
    gpio_reset_pin(*(led_array + 1));
    gpio_set_direction(*(led_array + 1), GPIO_MODE_OUTPUT);
    gpio_reset_pin(*(led_array + 2));
    gpio_set_direction(*(led_array + 2), GPIO_MODE_OUTPUT);
    while (1)
    {
        gpio_set_level(*(led_array + 2), 1);
        gpio_set_level(*(led_array + 1), 1);
        // ESP_LOGI("from TaskFunc", "%s", "switching to  taskFunction \n");

        gpio_set_level(*(led_array + 1), 0);
        gpio_set_level(*(led_array + 2), 0);
        // ESP_LOGI("from TaskFunc", "%s", "switching to  taskFunction  again \n");
        vTaskDelay(pdMS_TO_TICKS(400));
    }
}