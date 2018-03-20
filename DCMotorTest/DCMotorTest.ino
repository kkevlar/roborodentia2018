#include <Wire.h>
#include <Adafruit_MotorShield.h>

#define MOTOR_COUNT 4
#define FL 0
#define FR 1
#define BR 2
#define BL 3

Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 
Adafruit_DCMotor *motors[MOTOR_COUNT];

void setup() {

  AFMS.begin();  // create with the default frequency 1.6KHz
  //AFMS.begin(1000);  // OR with a different frequency, say 1KHz
  
  for (int i = 0; i < MOTOR_COUNT; i++)
  {
    motors[i] = AFMS.getMotor(i+1);
    motors[i]->run(RELEASE);
  }
  pinMode(2, INPUT_PULLUP);
 
  
}

void set_speed(Adafruit_DCMotor* motor, int speed, int time)
//Assumed that if time = 0, then current speed is zero
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

int cmi =0;

void loop() 
{
  cmi %= MOTOR_COUNT;
  int speed; 
  if(!digitalRead(2))
    speed = 255;
  else
    speed = -255;

  set_speed(motors[FL], -speed, 0);
  set_speed(motors[FR], speed, 0);
  set_speed(motors[BL], -speed, 0);
  set_speed(motors[BR], -speed, 0);

}
