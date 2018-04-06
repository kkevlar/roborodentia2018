#include "testoptions.h"
#ifndef FAKESWITCH

#include "switch.h"
#include "wiring.h"

void switch_setup(void)
{
    pinMode(SWITCH_PIN_SOUTH, INPUT_PULLUP);
    pinMode(SWITCH_PIN_NORTH, INPUT_PULLUP);
    pinMode(SWITCH_PIN_EAST, INPUT_PULLUP);
    pinMode(SWITCH_PIN_WEST, INPUT_PULLUP);
}

int test_switch_arbitrary(long breaktime, int pin)
{
	long starttime = millis();
	while (millis() - starttime < breaktime)
    {
        if(digitalRead(pin) == LOW)
            return SUCCESS;
    }
    return FAILURE;
}

int test_switch_south(long breaktime)
{
	return test_switch_arbitrary(breaktime, SWITCH_PIN_SOUTH);
}
int test_switch_north(long breaktime)
{
	return test_switch_arbitrary(breaktime, SWITCH_PIN_NORTH);
}
int test_switch_east(long breaktime)
{
	return test_switch_arbitrary(breaktime, SWITCH_PIN_EAST);
}
int test_switch_west(long breaktime)
{
	return test_switch_arbitrary(breaktime, SWITCH_PIN_WEST);
}

#endif
