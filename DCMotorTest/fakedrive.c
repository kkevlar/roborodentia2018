
#include "fakedrive.h"

void motor_setup(void)
{
    Serial.begin(9600);
    pinMode(LED_BUILTIN,OUTPUT);
    delay(1000);
    Serial.println("Motor setup complete");
}

void go_north() 
{
    Serial.println("Going north");
}

void go_south() 
{
    Serial.println("Going south");
}

void stop() 
{
    Serial.println("STOP");    
}

