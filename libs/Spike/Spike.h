#ifndef Spike_h
#define Spike_h

#include "Arduino.h"

#define OFF 0 // Both off
#define FORWARD 1 // Forward
#define REVERSE 2  // Reverse
#define ON 3 // Both terminals +12v

class Spike
{
	protected:
		void setPins(bool fw, bool rev);
		int fwPin, revPin;
	public:
		Spike(int fwPin, int revPin);
		void set(int state);
};

#endif