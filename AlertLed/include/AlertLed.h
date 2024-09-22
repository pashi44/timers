
#ifndef _ALERTLEDH__
#define __ALERTLEDH__

#include "queues.h"
class AlertLed
{
    TimerHandle_t timerHandle;
    TickType_t period_ms;
    volatile bool state;
    volatile unsigned count;
    gpio_num_t gpio;

public:
    AlertLed(gpio_num_t gpio, TickType_t period_ms);
    AlertLed getObject();

    void alert();
    void cancel();
    void reset(bool state);

    static void alertLed_cb(TimerHandle_t timerHandle);
};
#endif
