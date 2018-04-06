#include "testoptions.h"
#ifndef DRIVE_H
#define DRIVE_H

#include <Wire.h>
#include <Adafruit_MotorShield.h>

#include "wiring.h"

#define ADDR_BOT 0x61
#define ADDR_TOP 0x60

#include "drivefuncs.h"
void set_speed(Adafruit_DCMotor* motor, int speed, int time);

#endif
