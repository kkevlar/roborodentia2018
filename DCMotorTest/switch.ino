#include "testoptions.h"
#ifndef FAKESWITCH

#include "switch.h"
#include "wiring.h"

int pins[TOTAL_SWITCH_COUNT];

void switch_setup(void)
{
    pinMode(SWITCH_PIN_SOUTH, INPUT_PULLUP);
    pinMode(SWITCH_PIN_NORTH, INPUT_PULLUP);
    pinMode(SWITCH_PIN_EAST_NORTH, INPUT_PULLUP);
    pinMode(SWITCH_PIN_EAST_SOUTH, INPUT_PULLUP);
    pinMode(SWITCH_PIN_WEST_NORTH, INPUT_PULLUP);
    pinMode(SWITCH_PIN_WEST_SOUTH, INPUT_PULLUP);
}

int test_switch_arbitrary(long breaktime, int pincount, int* pins)
{
    int test[TOTAL_SWITCH_COUNT];
    int result = 1;
    int i;

    for(i = 0; i < pincount; i++)
    {
        test[i] = 0;
    }

    long starttime = millis();

    while (millis() - starttime < breaktime)
    {
        result = 1;
        for(i = 0; i < pincount; i++)
        {
            test[i] = (digitalRead(pins[i]) == LOW || test[i]);
            result = (test[i] && result);
        }
        if(result)
            return SUCCESS;
    }
    return FAILURE;
}

int test_switch_south(long breaktime)
{
    pins[0] = SWITCH_PIN_SOUTH;
    return test_switch_arbitrary(breaktime, 1, pins);
}
int test_switch_north(long breaktime)
{
    pins[0] = SWITCH_PIN_NORTH;
    return test_switch_arbitrary(breaktime, 1, pins);
}
int test_switch_east(long breaktime)
{
    pins[0] = SWITCH_PIN_EAST_NORTH;
    pins[1] = SWITCH_PIN_EAST_SOUTH;
    return test_switch_arbitrary(breaktime, 2, pins);
}
int test_switch_west(long breaktime)
{
    pins[0] = SWITCH_PIN_WEST_NORTH;
    pins[1] = SWITCH_PIN_WEST_SOUTH;
    return test_switch_arbitrary(breaktime, 2, pins);
}

#endif
