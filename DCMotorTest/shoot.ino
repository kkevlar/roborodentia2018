#include "testoptions.h"

#ifndef FAKEDRIVE
#include "drive.h"

// Adafruit_MotorShield AFMS_BOT(ADDR_BOT); // Rightmost jumper closed
Adafruit_MotorShield AFMS_TOP(ADDR_TOP); // Default address, no jumpers

Adafruit_DCMotor *motor_flywheel;
Adafruit_DCMotor *motor_indexer;

void drive_setup(void)
{
    // AFMS_BOT.begin();  // create with the default frequency 1.6KHz
    AFMS_TOP.begin();  // create with the default frequency 1.6KHz
    //AFMS.begin(1000);  // OR with a different frequency, say 1KHz
    // motors[1] = AFMS_TOP.getMotor(1);

    motor_indexer = AFMS_TOP.getMotor(TOP_PORT_INDEXER);
    motor_flywheel = AFMS_TOP.getMotor(TOP_PORT_FLYWHEEL);

    motor_indexer->run(RELEASE);
    motor_flywheel->run(RELEASE);
}

void simple_shoot(void)
{
	set_speed(motor_flywheel, 255, 0);
	set_speed(motor_indexer, 255, 0);
	delay(1000);
	set_speed(motor_flywheel, 0, 0);
	set_speed(motor_indexer, 0, 0);
}


#endif
