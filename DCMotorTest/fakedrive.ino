#include "testoptions.h"

#ifdef FAKEDRIVE
#include "fakedrive.h"

void drive_setup(void)
{
    Serial.begin(9600);
    pinMode(LED_BUILTIN,OUTPUT);
    delay(1000);
    Serial.println("Motor setup complete");
}

void go_north(void)
{
    Serial.println("north");
}
void go_south(void)
{
    Serial.println("south");
}
void go_south_west(void)
{
    Serial.println("southwest");
}
void go_south_east(void)
{
    Serial.println("southeast");
}
void go_east(void)
{
    Serial.println("east");
}
void go_west(void)
{
    Serial.println("west");
}
void go_north_west(void)
{
    Serial.println("northwest");
}
void go_north_east(void)
{
    Serial.println("northeast");
}
void go_stop(void)
{
    Serial.println("STOP");
}
#endif

