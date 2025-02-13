#pragma  once
#include"freertos/FreeRTOS.h"
#include <cstdint>
#include "driver/gpio.h"

#include "soc/soc.h" //interrupts sources
#include "esp_intr_types.h" //interrupt types
#include "esp_intr_alloc.h" // allocates   type of interrupt  to a partcular  core
//  absed o n the intterupt  number (masked or non-masked)
/* ********************** duirng  SPI flash operations  ESP32 will disabpe cache, making spi flash 

inaccesacle for flash storade and SPIram inaccesacble for this reases    IRAM -SAFE Interrupt hab=nlders esist 


*/


extern esp_intr_cpu_affinity_t   intr_cpucore ; //interrupt cpu affinity

extern  intr_handle_t  intr_handler; 
extern esp_err_t intr_alloc_handler;
// 32 interrputs mashed on to each  core  //
// with priorty  based   from -0-7
extern esp_err_t esp_shared_intr(int interrupt_number,
int cpucore , bool isin_iram);

 //shared inerrupt

// ETS_GPIO_INTR_SOURCE → GPIO interrupt
// ETS_UART0_INTR_SOURCE → UART0 interrupt
// // ETS_TIMER1_INTR_SOURCE → Timer1 interrupt

// ESP_INTR_FLAG_SHARED	Allows the interrupt to be shared with other peripherals.
// ESP_INTR_FLAG_EDGE	Configures the interrupt as edge-triggered (instead of level-triggered).
// ESP_INTR_FLAG_IRAM	Places the handler in IRAM for fast execution.
// ESP_INTR_FLAG_INTRDISABLED	Allocates the interrupt but keeps it disabled until explicitly enabled.
// ESP_INTR_FLAG_LOWMED


//         extern esp_err_t
//         esp_intr_alloc(int intr_source,
//                        int flags, intr_handler_t intr_handler,
                    //    void *arg, intr_handle_t *ret_handle);

// Interrupt Service Routine (ISR)

#define GPIO_pin GPIO_NUM_25
extern "C"    gpio_config_t io_conf; 
    extern "C"  void __attribute__((section("iram1"))) gpio_isr_handler(void *arg)
    ;




// extern "C"  esp_err_t gpio_config(gpio_config*);