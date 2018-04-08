#include "testoptions.h"

#ifndef FAKEDRIVE
#include "drive.h"
#else
#include "fakedrive.h"
#warning "fakedrive is on"
#endif

#include "switch.h"

void panic()
{
	digitalWrite(LED_BUILTIN, HIGH);
}

void setup() 
{   
    pinMode(LED_BUILTIN, OUTPUT);
    digitalWrite(LED_BUILTIN, LOW);
    motor_setup();
    switch_setup();
    delay(1000);
    go_stop();
    delay(1000);
    go_north();
    if(test_switch_north(10000) != SUCCESS)
    	panic();
    go_stop();
}

void loop()
{
	go_east();
    if(test_switch_east(10000) != SUCCESS)
    	panic();
    go_stop();
    go_south();
    if(test_switch_south(10000) != SUCCESS)
    	panic();
    go_stop();
    go_north_west();
    if(test_switch_north(10000) != SUCCESS)
    	panic();
    go_stop();
    go_west();
    if(test_switch_west(10000) != SUCCESS)
    	panic();
    go_stop();
    go_south();
    if(test_switch_south(10000) != SUCCESS)
    	panic();
    go_stop();
    go_north_east();
    if(test_switch_north(10000) != SUCCESS)
    	panic();
    stop();
    delay(2000);
}
