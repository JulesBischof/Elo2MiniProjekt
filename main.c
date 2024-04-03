#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "pico/time.h"
#include "measure.h"

#define LED_PIN 15
#define ECHO_PIN 2
#define TRIGGER_PIN 3
#define SUBSONIC_VELOCITY_CM_PER_US 0.0343

int main() {
    stdio_init_all() ;

    gpio_init(LED_PIN) ;
    gpio_init(ECHO_PIN) ;
    gpio_init(TRIGGER_PIN) ;

    gpio_pull_down (ECHO_PIN);

    gpio_set_dir(LED_PIN, GPIO_OUT) ;
    gpio_set_dir(TRIGGER_PIN, GPIO_OUT) ;
    gpio_set_dir(ECHO_PIN, GPIO_IN) ; //gpio_set_input_enabled (uint gpio, bool enabled); //Enable GPIO input.

   
    while(1) {

        set_trigger(TRIGGER_PIN);
        
        float distance;
        distance = SUBSONIC_VELOCITY_CM_PER_US*measure_time(ECHO_PIN) / 2.0; 
        push_measure(distance); 
            
        printf("Entfernung: %f cm\n", get_result());
        sleep_ms(500);
    }
    return 0;
}