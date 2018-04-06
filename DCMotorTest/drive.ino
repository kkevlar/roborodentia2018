#include "testoptions.h"

#ifndef FAKEDRIVE
#include "drive.h"

Adafruit_MotorShield AFMS_BOT(ADDR_BOT); // Rightmost jumper closed
Adafruit_MotorShield AFMS_TOP(ADDR_TOP); // Default address, no jumpers
Adafruit_DCMotor *motors[MOTOR_COUNT];

void motor_setup(void)
{
    AFMS_BOT.begin();  // create with the default frequency 1.6KHz
    AFMS_TOP.begin();  // create with the default frequency 1.6KHz
    //AFMS.begin(1000);  // OR with a different frequency, say 1KHz

    motors[0] = AFMS_BOT.getMotor(1);
    motors[1] = AFMS_TOP.getMotor(1);
    
    for (int i = 0; i < MOTOR_COUNT; i++)
        motors[i]->run(RELEASE);
}

//Assumed that if time = 0, then current speed is zero
void set_speed(Adafruit_DCMotor* motor, int speed, int time)
{
    if (speed < 0)
    {
        speed = -speed;
        motor->run(BACKWARD);
    }
    else if (speed > 0)
    {
        motor->run(FORWARD);
    }
    if(time == 0 || speed == 0) //no ramp down
    {
        motor->setSpeed(speed);
        if (speed == 0)
            motor->run(RELEASE);
        return;
    }
    for (int i=0; i<speed; i++) 
    {
        motor->setSpeed(i);  
        delay(time/speed);
    }
    if (speed == 0)
            motor->run(RELEASE);
}

void go_north() 
{
    int speed = 255;
    set_speed(motors[FL], speed, 0);
    set_speed(motors[FR], speed, 0);
    set_speed(motors[BL], -speed, 0);
    set_speed(motors[BR], speed, 0);
}

void go_south() 
{
    int speed = 255;
    set_speed(motors[FL], -speed, 0);
    set_speed(motors[FR], -speed, 0);
    set_speed(motors[BL], speed, 0);
    set_speed(motors[BR], -speed, 0);
}

void go_stop() 
{
    int speed = 0;
    set_speed(motors[FL], speed, 0);
    set_speed(motors[FR], speed, 0);
    set_speed(motors[BL], -speed, 0);
    set_speed(motors[BR], speed, 0);
}
#endif

