
#ifndef FAKEDRIVE
#include "drive.h"
#else
#include "fakedrive.h"
#endif

#define SWITCH_BACK 2

int testForPress(int pin, int* docontinue)
{
    while (docontinue && *docontinue)
    {
        if(digitalRead(pin) == LOW)
            return 0;
    }
    return 1;
}

void setup() 
{   
    pinMode(2, INPUT_PULLUP);
    pinMode(LED_BUILTIN, OUTPUT);
    motor_setup();
}

void loop()
{
    int emergency = 1;
    stop();
    delay(1000);
    go_back();
    if (!testForPress(SWITCH_BACK,&emergency))
        stop();
    delay(15000);
}
