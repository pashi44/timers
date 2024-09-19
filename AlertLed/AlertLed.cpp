#include <stdio.h>
#include "AlertLed.h"
#include <iostream>

AlertLed::AlertLed(gpio_num_t gpio, TickType_t period_ms = 1000)
{

    (*this).gpio = gpio;

    (*this).period_ms = period_ms;
    gpio_reset_pin((*this).gpio);
    gpio_set_direction((*this).gpio, gpio_mode_t::GPIO_MODE_OUTPUT);
}

AlertLed AlertLed::getObject()
{
    return *this;
}
void AlertLed::alert()
{

    gpio_set_level((*this).gpio, 1);
}
void AlertLed::alertLed_cb(TimerHandle_t timerHandle)
{

    void (AlertLed::*funcptr)() = &AlertLed::alert;

    uint32_t funcaddress;

    asm volatile(
        "mov    a0,  %1 , 10\n"
        : "=r"(funcaddress)
        : "r"(funcptr)
        : "a0");

    std::cout
        << "function address is " << funcaddress << std::endl;
}

void AlertLed::reset()
{
    gpio_set_level((*this).gpio, 0);
}