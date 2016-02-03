#include "StepperMotor.h"

StepperMotor motor = StepperMotor(10,11,5,6,7,4);

void setup()
{
  pinMode(13,OUTPUT);
}

void loop()
{
	motor.write(HIGH,200,1);
	//delay(500);
 digitalWrite(13,HIGH);
 delay(500);
 digitalWrite(13,LOW);
 delay(500);
}
