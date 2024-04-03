#include <stdio.h>
#include "pico/stdlib.h"
#include "pico/time.h"
#include "measure.h"


# define BUFFER_SIZE 10

// set trigger pin for 10 us
void set_trigger(int TriggerPin){
    gpio_put(TriggerPin,0);
    sleep_us(2);
    gpio_put(TriggerPin,1); // set trigger pin to High for 10 us
    sleep_us(10);
    gpio_put(TriggerPin,0);
}

// calculate the distance with the measure time
int measure_time(int EchoPin){
    int start;
    int end;
    int distance;
    while(!gpio_get(EchoPin)); //wait until echo pin is high
    start = time_us_32();
    while(gpio_get(EchoPin)); //wait until echo pin is low
    end = time_us_32();
    distance = end - start;
    return distance;
}

int position = 0;
float buffer[BUFFER_SIZE];
// save distance in ringbuffer
void push_measure(float distance){
    
    if(position == BUFFER_SIZE-1){
        buffer[position]=distance;
        position=0;
    }else{
        buffer[position]=distance;
        position++;
    }
}

// get the average value of the last 10 values
float get_result(){
    float sum = 0;
    int count = 0;
    for(;count<BUFFER_SIZE; count++){
        sum += buffer[count];
    }
    return sum/count;
}


