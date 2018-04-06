#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "PinChangeInt.h"

#define MOTOR_COUNT 2
#define FL 0
#define FR 1
#define BR 2
#define BL 3

Adafruit_MotorShield AFMSbot(0x61); // Rightmost jumper closed
Adafruit_MotorShield AFMStop(0x60); // Default address, no jumpers
Adafruit_DCMotor *motors[MOTOR_COUNT];

int state = 0;
long last = 0;

void ass()
{
  last += 3000;
}

void setup() 
{
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(2, INPUT_PULLUP);
  PCintPort::attachInterrupt(2, &ass, FALLING);
  // AFMSbot.begin();  // create with the default frequency 1.6KHz
  //  AFMStop.begin();  // create with the default frequency 1.6KHz
  // //AFMS.begin(1000);  // OR with a different frequency, say 1KHz



  //  motors[0] = AFMStop.getMotor(1);
  //   motors[1] = AFMSbot.getMotor(1);
  
  // for (int i = 0; i < MOTOR_COUNT; i++)
  // {
   
  //   motors[i]->run(RELEASE);
  // }
  // pinMode(2, INPUT_PULLUP);
 
  
}

void loop()
{
  if (millis() - last > 50)
  {
    last = millis();
    state = (state+1) % 2;
    digitalWrite(LED_BUILTIN, state);
  }
//  if (digitalRead(2) == LOW && last - 1000 < millis())
//  {
//    last = millis() + 2000;
//  }
}

// void set_speed(Adafruit_DCMotor* motor, int speed, int time)
// //Assumed that if time = 0, then current speed is zero
// {
//   if (speed < 0)
//   {
//     speed = -speed;
//     motor->run(BACKWARD);
//   }
//   else if (speed > 0)
//   {
//     motor->run(FORWARD);
//   }
//   if(time == 0 || speed == 0) //no ramp down
//   {
//     motor->setSpeed(speed);
//     if (speed == 0)
//       motor->run(RELEASE);
//     return;
//   }
//   for (int i=0; i<speed; i++) 
//   {
//     motor->setSpeed(i);  
//     delay(time/speed);
//   }
//   if (speed == 0)
//       motor->run(RELEASE);
// }

// int cmi =0;

// void loop() 
// {
//  int speed; 
//   if(!digitalRead(2))
//     speed = 255;
//   else
//     speed = -255;

//   set_speed(motors[FL], -speed, 0);
//   set_speed(motors[FR], speed, 0);

// }

// void lr() 
// {
//   cmi %= MOTOR_COUNT;
//   int speed; 
//   if(!digitalRead(2))
//     speed = 255;
//   else
//     speed = -255;

//   set_speed(motors[FL], -speed, 0);
//   set_speed(motors[FR], speed, 0);
//   set_speed(motors[BL], -speed, 0);
//   set_speed(motors[BR], -speed, 0);

// }


// void fb() 
// {
//   cmi %= MOTOR_COUNT;
//   int speed; 
//   if(!digitalRead(2))
//     speed = 255;
//   else
//     speed = -255;

//   set_speed(motors[FL], speed, 0);
//   set_speed(motors[FR], speed, 0);
//   set_speed(motors[BL], -speed, 0);
//   set_speed(motors[BR], speed, 0);

// }
