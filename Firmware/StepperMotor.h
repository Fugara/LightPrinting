#ifndef StepperMotor_H
#define StepperMotor_H

#include "arduino.h"

#define MinimumInterval 1 //MS, ToDo - consider change to NS

//micro steps types
enum MicroStepType { fullStep, halfStep, quarterStep, eigthStep, sixteenthStep };

class StepperMotor
{
	public:
		StepperMotor(int step, int dir, int microStep1, int microStep2, int microStep3, int enable);
		void write(byte dir, int numberOfSteps, int interval);
		void setMicroSteps(MicroStepType type);
		void enableMotor();
		void disableMotor();
		
	private:
		const int stepPin,dirPin,microStep1Pin,microStep2Pin, microStep3Pin,enablePin;
		byte enableStatus = 0;
};
#endif //StepperMotor_H
