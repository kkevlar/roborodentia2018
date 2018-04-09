#include "testoptions.h"
#ifndef DRIVE_H
#define DRIVE_H

#include <Wire.h>
#include <Adafruit_MotorShield.h>

#include "wiring.h"

#define HUG_CONSTANT .85

//#include "drivefuncs.h"
void drive_setup(void);
void go_north(void);
void go_south(void);
void go_south_west(void);
void go_south_east(void);
void go_east(void);
void go_west(void);
void go_north_west(void);
void go_north_east(void);
void go_stop(void);
void set_speed(Adafruit_DCMotor* motor, int speed, int time);

#endif
