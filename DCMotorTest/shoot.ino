#include "testoptions.h"

#ifndef FAKEDRIVE

// Adafruit_MotorShield AFMS_BOT(ADDR_BOT); // Rightmost jumper closed
Adafruit_MotorShield AFMS_TOP(ADDR_TOP); // Default address, no jumpers

Adafruit_DCMotor *motor_flywheel;
Adafruit_DCMotor *motor_indexer;

void shoot_setup(void)
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
	set_speed(motor_flywheel,(int) (255.0 * OFFSET_FLYWHEEL), 2);
  for (int i = 0; i < 20; i++)
  {
  set_speed(motor_indexer, (int) (255.0 * -OFFSET_INDEXER), 2);
  delay(250);
  set_speed(motor_indexer, (int) (255.0 * OFFSET_INDEXER), 2);
  delay(500);
  
  }
	set_speed(motor_flywheel, 0, 0);
  set_speed(motor_indexer, 0, 0);
}

void shoot_prepare(void)
{
  set_speed(motor_flywheel,(int) (255.0 * OFFSET_FLYWHEEL), 0);
  set_speed(motor_indexer,(int) (255.0 * OFFSET_INDEXER * SHOOT_UNJAM_CONSTANT), 0);
}

void shoot_begin(void)
{
  set_speed(motor_flywheel,(int) (255.0 * OFFSET_FLYWHEEL), 0);
  set_speed(motor_indexer, (int) (255.0 * OFFSET_INDEXER), 0);
}


void shoot_spin_up(void)
{
  set_speed(motor_flywheel,(int) (255.0 * OFFSET_FLYWHEEL), 0);
  set_speed(motor_indexer, (int) (255.0 * OFFSET_INDEXER), 0);
}

void shoot_stop(void)
{
  set_speed(motor_flywheel,(int) (0 * OFFSET_FLYWHEEL), 0);
  set_speed(motor_indexer, (int) (0 * OFFSET_INDEXER), 0);
}

#endif
