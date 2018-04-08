#include "testoptions.h"
#ifndef FAKEDRIVE
#ifndef SHOOT_H
#define SHOOT_H

#include <Wire.h>
#include <Adafruit_MotorShield.h>

#include "wiring.h"
#include "drive.h"

void shoot_setup(void);
void simple_shoot(void);

#endif
#endif
