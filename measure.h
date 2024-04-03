#include <stdio.h>
#include "pico/stdlib.h"

void set_trigger(int TriggerPin);
int measure_time(int EchoPin);
float calc_distance(int velocity, int duration);
void push_measure(float distance);
float get_result();