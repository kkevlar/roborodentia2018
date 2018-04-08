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
    #ifndef FAKEDRIVE
    Serial.begin(9600);
    #endif
    
    pinMode(LED_BUILTIN, OUTPUT);
    digitalWrite(LED_BUILTIN, LOW);
    drive_setup();
    switch_setup();
    delay(1000);
    #ifndef MOTOR_TEST
    go_stop();
    delay(1000);
    go_north();
    if(test_switch_north(10000) != SUCCESS)
        panic();
    go_stop();
    #endif
    
    
}

void loop()
{
    #ifdef MOTOR_TEST
        Serial.println("lmao");
//        delay(1000);
//        go_stop();
        delay(500);
        go_north();
        delay(500);
        go_east();
        delay(500);        
        go_south();        
        delay(500);
        go_west();

    #else
        go_east();
        if(test_switch_east(10000) != SUCCESS)
            panic();
        go_stop();
        go_south_east();
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
        go_south_west();
        if(test_switch_south(10000) != SUCCESS)
            panic();
        go_stop();
        go_north_east();
        if(test_switch_north(10000) != SUCCESS)
            panic();
        go_stop();
        delay(2000);
    #endif
}
