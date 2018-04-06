#include "testoptions.h"

#ifndef FAKEDRIVE
#include "drive.h"
#else
#include "fakedrive.h"
#warning "fakedrive is on"
#endif

#include "switch.h"

void setup() 
{   
    pinMode(LED_BUILTIN, OUTPUT);
    motor_setup();
    switch_setup();
}

void loop()
{
    int emergency = 1;
    go_stop();
    delay(1000);
    go_south();
    if(test_switch_south(10000) == SUCCESS)
        go_stop();
    delay(15000);
}
