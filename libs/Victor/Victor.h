#ifndef Victor_h
#define Victor_h

#include "Arduino.h"
#include <Servo.h>

class Victor : protected Servo
{
	int pin;
	
	public:
 		Victor(int pin);
		void enable();
		void disable();
		void set(int value);
};

#endif