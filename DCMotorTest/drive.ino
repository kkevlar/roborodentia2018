#include "testoptions.h"

#ifndef FAKEDRIVE
#include "drive.h"

Adafruit_MotorShield AFMS_BOT(ADDR_BOT); // Rightmost jumper closed
// Adafruit_MotorShield AFMS_TOP(ADDR_TOP); // Default address, no jumpers

Adafruit_DCMotor *nw;
Adafruit_DCMotor *ne;
Adafruit_DCMotor *sw;
Adafruit_DCMotor *se;

void drive_setup(void)
{
    AFMS_BOT.begin();  // create with the default frequency 1.6KHz
    // AFMS_TOP.begin();  // create with the default frequency 1.6KHz
    //AFMS.begin(1000);  // OR with a different frequency, say 1KHz
    // motors[1] = AFMS_TOP.getMotor(1);

    nw = AFMS_BOT.getMotor(BOT_PORT_NW);
    ne = AFMS_BOT.getMotor(BOT_PORT_NE);
    sw = AFMS_BOT.getMotor(BOT_PORT_SW);
    se = AFMS_BOT.getMotor(BOT_PORT_SE);
    
    nw->run(RELEASE);
    ne->run(RELEASE);
    sw->run(RELEASE);
    se->run(RELEASE);
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
    int speed = (int) (255.0 * SPEED_CONSTANT);
    set_speed(nw, OFFSET_NW * speed, 0);
    set_speed(ne, OFFSET_NE * speed, 0);
    set_speed(sw, OFFSET_SW * -speed, 0);
    set_speed(se, OFFSET_SE * -speed, 0);
}

void go_stop() 
{
    int speed = 0;
    set_speed(nw, OFFSET_NW * speed, 0);
    set_speed(ne, OFFSET_NE * speed, 0);
    set_speed(sw, OFFSET_SW * speed, 0);
    set_speed(se, OFFSET_SE * speed, 0);
}

void go_south(void)
{
    int speed = (int) (255.0 * SPEED_CONSTANT);
    set_speed(nw, OFFSET_NW * -speed, 0);
    set_speed(ne, OFFSET_NE * -speed, 0);
    set_speed(sw, OFFSET_SW * speed, 0);
    set_speed(se, OFFSET_SE * speed, 0);
}
void go_south_west(void)
{
    int speed = (int) (255.0 * SPEED_CONSTANT * COLLECT_CONSTANT);
    set_speed(nw, OFFSET_NW * -speed, 0);
    set_speed(ne, OFFSET_NE * -speed * COLLECT_HUG_CONSTANT, 0);
    set_speed(sw, OFFSET_SW * speed * COLLECT_HUG_CONSTANT, 0);
    set_speed(se, OFFSET_SE * speed, 0);
}
void go_north_hug_east(void)
{
    int speed = (int) (255.0 * SPEED_CONSTANT * COLLECT_CONSTANT);
    set_speed(nw, OFFSET_NW * speed, 0);
    set_speed(ne, OFFSET_NE * speed * COLLECT_HUG_CONSTANT, 0);
    set_speed(sw, OFFSET_SW * -speed * COLLECT_HUG_CONSTANT, 0);
    set_speed(se, OFFSET_SE * -speed, 0);
}
void go_south_east(void)
{
    int speed = (int) (255.0 * SPEED_CONSTANT * COLLECT_CONSTANT);
    set_speed(nw, OFFSET_NW * -speed *HUG_CONSTANT, 0);
    set_speed(ne, OFFSET_NE * -speed, 0);
    set_speed(sw, OFFSET_SW * speed, 0);
    set_speed(se, OFFSET_SE * speed * HUG_CONSTANT, 0);
}
void go_east(void)
{
    int speed = (int) (255.0 * SPEED_CONSTANT);
    set_speed(nw, OFFSET_NW * speed, 0);
    set_speed(ne, OFFSET_NE * HUG_CONSTANT* -speed, 0);
    set_speed(sw, OFFSET_SW * HUG_CONSTANT* speed, 0);
    set_speed(se, OFFSET_SE * -speed, 0);  
}

void go_east_first(void)
{
    int speed = (int) (140.0 * SPEED_CONSTANT);
    set_speed(nw, OFFSET_NW * speed, 0);
    set_speed(ne, OFFSET_NE *  -speed, 0);
    set_speed(sw, OFFSET_SW *  speed, 0);
    set_speed(se, OFFSET_SE * -speed, 0);  
}

void go_west(void)
{
  int speed = (int) (255.0 * SPEED_CONSTANT);
  set_speed(nw, OFFSET_NW * HUG_CONSTANT * -speed, 0);
  set_speed(ne, OFFSET_NE * speed, 0);
  set_speed(sw, OFFSET_SW * -speed, 0);
  set_speed(se, OFFSET_SE * HUG_CONSTANT* speed, 0);
}
void go_north_west(void)
{
  int speed = (int) (255.0 * SPEED_CONSTANT);
  set_speed(nw, OFFSET_NW * speed*DIAG_CONSTANT*1.2, 0); //front left
  set_speed(ne, OFFSET_NE * speed, 0); //front right
  set_speed(sw, OFFSET_SW * -speed, 0); //back left
  set_speed(se, OFFSET_SE * -speed*DIAG_CONSTANT*1.2, 0); //bk eifht
}
void go_north_east(void)
{
  int speed = (int) (255.0 * SPEED_CONSTANT);
  set_speed(nw, OFFSET_NW * speed, 0);
  set_speed(ne, OFFSET_NE * speed*DIAG_CONSTANT, 0);
  set_speed(sw, OFFSET_SW * -speed*DIAG_CONSTANT, 0);
  set_speed(se, OFFSET_SE * -speed, 0);
}


#endif

