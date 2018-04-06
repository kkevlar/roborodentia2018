#include <Wire.h>
#include <Adafruit_MotorShield.h>

#ifndef NOMOTORS
#define MOTOR_COUNT 2
#define FL 0
#define FR 1
#define BR 2
#define BL 3

Adafruit_MotorShield AFMSbot(0x61); // Rightmost jumper closed
Adafruit_MotorShield AFMStop(0x60); // Default address, no jumpers
Adafruit_DCMotor *motors[MOTOR_COUNT];

#endif 

int testForPress(int pin, int* docontinue)
{
	while (docontinue && *docontinue)
	{
		if(digitalRead(pin) == LOW)
			return 0;
	}
	return 1;
}

void setup() {
	#ifndef NOMOTORS
	AFMSbot.begin();  // create with the default frequency 1.6KHz
	AFMStop.begin();  // create with the default frequency 1.6KHz
	//AFMS.begin(1000);  // OR with a different frequency, say 1KHz


	motors[0] = AFMStop.getMotor(1);
	motors[1] = AFMSbot.getMotor(1);
	
	for (int i = 0; i < MOTOR_COUNT; i++)
	{
	 
		motors[i]->run(RELEASE);
	}
	#endif
	pinMode(2, INPUT_PULLUP);
	pinMode(LED_BUILTIN, OUTPUT);
	digitalWrite(LED_BUILTIN, LOW);
 
	
}

#ifndef NOMOTORS
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
#endif

void go_back()
{

}

void loop()
{
	int stop = 1;
  go_back();
	digitalWrite(LED_BUILTIN,LOW);
	delay(2000);
	digitalWrite(LED_BUILTIN, HIGH);
	digitalWrite(LED_BUILTIN,testForPress(2,&stop));
	delay(15000);
}
