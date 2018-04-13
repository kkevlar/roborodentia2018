#include "testoptions.h"

#ifndef FAKEDRIVE
#include "drive.h"
#include "shoot.h"
#else
#include "fakedrive.h"
#warning "fakedrive is on"
#endif

#include "switch.h"
#include "wiring.h"

void panic()
{
    digitalWrite(LED_BUILTIN, HIGH);
    go_stop();
//    for (int i = 0; i < 100; i++)
//    delay(1000);
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
    #ifndef FAKEDRIVE
      shoot_setup();
    #endif
    delay(1000);
    #ifndef MOTOR_TEST
    #ifdef SHOOT_TEST
        while(1)
        {
            // if (digitalRead(SWITCH_PIN_NORTH) == LOW)
                shoot_spin_up();
            // else
                // shoot_stop();
        }
    return;
    #endif
    go_stop();
    #warning "ass"
    delay(1000);
    go_east_first();
    if(test_switch_east(10000) != SUCCESS)
        panic();
    go_north_hug_east();
    if(test_switch_north(10000) != SUCCESS)
        panic();
    go_stop();
    #endif
    
    
}

#define PANIC_WAIT_TIME 30000

int firstdrive = 1;

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
    #ifdef SHOOT_TEST
    go_stop();
       #ifndef FAKEDRIVE
//          simple_shoot();
        #endif

   go_stop();
   return;
   #endif
        go_east();
        if(test_switch_east(PANIC_WAIT_TIME) != SUCCESS)
            panic();
        go_stop();
        go_south_east();
        
        if(test_switch_south(PANIC_WAIT_TIME) != SUCCESS)
            panic();
        go_stop();
        go_north_west();
        if(test_switch_north(PANIC_WAIT_TIME) != SUCCESS)
            panic();

        go_stop();
        shoot_prepare();
        
        go_west();
        if(test_switch_west(PANIC_WAIT_TIME) != SUCCESS)
            panic();

        shoot_begin();
//        go_stop();
//        delay(250);
//        shoot_begin();
//        go_north_east();
//        delay(250);
//        go_stop();        
        delay(6000);        
//        
//
//        go_north_west();
//        if(test_switch_west(PANIC_WAIT_TIME) != SUCCESS)
//            panic();

        shoot_stop();

        go_south_west();
        if(test_switch_south(PANIC_WAIT_TIME) != SUCCESS)
            panic();
        go_stop();
        go_north_east();
        if(test_switch_north(PANIC_WAIT_TIME) != SUCCESS)
            panic();
        go_stop();
        
//        delay(2000);
    #endif
}
