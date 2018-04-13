#include "testoptions.h"
#ifndef FAKEDRIVE
#ifndef SHOOT_H
#define SHOOT_H

#include <Wire.h>
#include <Adafruit_MotorShield.h>

#include "wiring.h"
#include "drive.h"

void shoot_setup(void);

void shoot_prepare(void);
void shoot_begin(void);

void simple_shoot(void);
void shoot_spin_up(void);
void shoot_stop(void);

#endif
#endif
