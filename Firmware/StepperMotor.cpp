#include "StepperMotor.h"

StepperMotor::StepperMotor(int step, int dir, int microStep1, int microStep2, int microStep3, int enable) : 
	stepPin(step), dirPin(dir), microStep1Pin(microStep1), microStep2Pin(microStep2), microStep3Pin(microStep3), enablePin(enable)
{
	pinMode(stepPin, OUTPUT);
	pinMode(dirPin, OUTPUT);
	pinMode(microStep1Pin, OUTPUT);
	pinMode(microStep2Pin, OUTPUT);
	pinMode(microStep3Pin, OUTPUT);
	pinMode(enablePin, OUTPUT);
	
	enableMotor();
  digitalWrite(microStep1Pin,LOW);
      digitalWrite(microStep2Pin,LOW);
      digitalWrite(microStep3Pin,LOW);
	//setMicroSteps(fullStep);
}
void StepperMotor::write(byte dir, int numberOfSteps, int interval)
{
	if(!enableStatus) //if motor isn't enabled don't do anything
		return;
	digitalWrite(dirPin, dir); //define the direction
	//int stepInterval = max(interval,MinimumInterval); 
	for(int i=0;i<numberOfSteps;i++) //each loop is one step
	{
		digitalWrite(stepPin,HIGH);
		delay(10);
		digitalWrite(stepPin,LOW);
		delay(100);
		
		//delay(interval);
	}
}
void StepperMotor::setMicroSteps(MicroStepType type) //define micro step type
{
	switch(type)
	{
		case fullStep:
			digitalWrite(microStep1Pin,LOW);
			digitalWrite(microStep2Pin,LOW);
			digitalWrite(microStep3Pin,LOW);
			break;
		case halfStep:
			digitalWrite(microStep1Pin,HIGH);
			digitalWrite(microStep2Pin,LOW);
			digitalWrite(microStep3Pin,LOW);
			break;
		case quarterStep:
			digitalWrite(microStep1Pin,LOW);
			digitalWrite(microStep2Pin,HIGH);
			digitalWrite(microStep3Pin,LOW);
			break;
		case eigthStep:
			digitalWrite(microStep1Pin,HIGH);
			digitalWrite(microStep2Pin,HIGH);
			digitalWrite(microStep3Pin,LOW);
			break;
		case sixteenthStep:
			digitalWrite(microStep1Pin,HIGH);
			digitalWrite(microStep2Pin,HIGH);
			digitalWrite(microStep3Pin,HIGH);
			break;
	}
} 
void StepperMotor::enableMotor() //enable
{
	digitalWrite(enablePin, LOW);
	enableStatus = 1;
}
void StepperMotor::disableMotor() //disable
{
	digitalWrite(enablePin, HIGH);
	enableStatus = 0;
}

