#include <stdio.h>
#include "tim.h"

gpio_num_t led_array[] = {gpio_num_t::GPIO_NUM_17, GPIO_NUM_18, GPIO_NUM_22,
                          GPIO_NUM_25};

void gpioSetup()
{
    for (int i = 0; i <= 4; i++)
    {
        gpio_reset_pin(*((gpio_num_t *)led_array + i));
        gpio_set_direction(*((gpio_num_t *)led_array + i), GPIO_MODE_OUTPUT);
    }
}
void *udp_timeout_cb(TimerHandle_t xTimer)
{
    s_udp_socket *user_data = (s_udp_socket *)pvTimerGetTimerID(xTimer);
    ++((*user_data).retries);
    // issue_retransmit(user_data->socket);
    return (void *)user_data;
}