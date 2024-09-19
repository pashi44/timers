// #include "queues.h"
#include "AlertLed.h"
//  ******************************* mian  _sectio  ****************
TaskHandle_t th1 = nullptr;
TaskHandle_t th2 = nullptr;
#ifdef __cplusplus
extern "C"
{
#endif
    void app_main()
    {

        static AlertLed alert1(GPIO_NUM_17, 1000);
        AlertLed alert2(GPIO_NUM_18, 1000);

        AlertLed alert3(GPIO_NUM_19, 500);

        //  a bit  of  cheating to dig the object and its members  memory  address
        void (AlertLed::*funcptr)() = &AlertLed::alert;
    }

#ifdef __cplusplus
}
#endif
