#include <stdio.h>
#include "AlertLed.h"
#include <iostream>

AlertLed::AlertLed(gpio_num_t gpio, TickType_t period_ms = 1000)
{

    (*this).gpio = gpio;

    (*this).period_ms = period_ms;
    gpio_reset_pin((*this).gpio);
    gpio_set_direction((*this).gpio, gpio_mode_t::GPIO_MODE_OUTPUT);
    gpio_set_level((*this).gpio, 1);
}

AlertLed AlertLed::getObject()
{
    return *this;
}
void AlertLed::alert()
{
    if (!timerHandle)
    {

        timerHandle = xTimerCreate(

            "alertTimer",
            pdMS_TO_TICKS(period_ms / 20),
            pdTRUE, // not a one short
            this,
            AlertLed::alertLed_cb

        );
        assert(timerHandle);

        AlertLed::reset(true);

        xTimerStart(timerHandle, portMAX_DELAY);
    }
}
void AlertLed::alertLed_cb(TimerHandle_t timerHandle)
{

    void (AlertLed::*funcptr)() = &AlertLed::alert;

    // uint32_t funcaddress;
    //
    // asm volatile(
    // "mov    a0,  %1 , 10\n"
    // : "=r"(funcaddress)
    // : "r"(funcptr)
    // : "a0");
    //
    // std::cout
    // << "function address is " << funcaddress << std::endl;

    AlertLed *obj = (AlertLed
                         *)pvTimerGetTimerID(timerHandle);

    assert(obj->timerHandle = timerHandle);
    (*obj).state ^= true;

    gpio_set_level((*obj).gpio, (*obj).state ? true : false);

    if (++((*obj).count) >= (5 * 2))
    {
        (*obj).state ^= true;

        xTimerChangePeriod(timerHandle, pdMS_TO_TICKS((*obj).period_ms / 20), portMAX_DELAY);
    }
    else if ((*obj).count == (5 * 2 - 1))
    {

        xTimerChangePeriod(timerHandle, pdMS_TO_TICKS((*obj).period_ms / 20 + ((*obj).period_ms / 2)), portMAX_DELAY);

        assert(!(*obj).state);
    }
}

void AlertLed::cancel()
{
    if (timerHandle)
    {
        xTimerStop(timerHandle, portMAX_DELAY);

        gpio_set_level((*this).gpio, 0);
    }
}

void AlertLed::reset(bool state)
{
    state = state;
    count = 0;

    gpio_set_level((*this).gpio, (state ? true : false));
}