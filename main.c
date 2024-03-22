#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "pico/time.h"

#define LED_PIN 15
#define ECHO_PIN 2
#define TRIGGER_PIN 3

int main() {
    int start;
    int end;
    int duration;
    stdio_init_all() ;

    gpio_init(LED_PIN) ;
    gpio_init(ECHO_PIN) ;
    gpio_init(TRIGGER_PIN) ;

    gpio_pull_down (ECHO_PIN);

    gpio_set_dir(LED_PIN, GPIO_OUT) ;
    gpio_set_dir(TRIGGER_PIN, GPIO_OUT) ;
    gpio_set_dir(ECHO_PIN, GPIO_IN) ; //gpio_set_input_enabled (uint gpio, bool enabled); //Enable GPIO input.

    while(1) {
// set Trigger
        gpio_put(TRIGGER_PIN,0);
        sleep_us(2);
        gpio_put(TRIGGER_PIN,1); // set trigger pin to High for 10 us
        sleep_us(10);
        gpio_put(TRIGGER_PIN,0);
// measure time
        while(!gpio_get(ECHO_PIN)); //wait until echo pin is high
        start = time_us_32();
        while(gpio_get(ECHO_PIN)); //wait until echo pin is low
        end = time_us_32();
        duration = end - start;

// calculate distance
        





        if(gpio_get(ECHO_PIN)){
            puts("LED start");
            gpio_put(LED_PIN,1);
            sleep_ms(250);
        }else{
            puts("LED stop");
            gpio_put(LED_PIN,0);
            sleep_ms(250);
        }    
    }
}