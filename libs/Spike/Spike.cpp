#include "Spike.h"

Spike::Spike(int fwPin, int revPin)
{
	pinMode(fwPin, OUTPUT);
	pinMode(revPin, OUTPUT);
	this->fwPin = fwPin;
	this->revPin = revPin;
	setPins(false, false);
}

void Spike::setPins(bool fw, bool rev)
{
	digitalWrite(fwPin, (fw?HIGH:LOW));
	digitalWrite(revPin, (rev?HIGH:LOW));
}

void Spike::set(int state)
{
	switch ( state )
	{
		case OFF:
			setPins(false, false);
			break;
		case FORWARD:
			setPins(true, false);
			break;
		case REVERSE:
			setPins(false, true);
			break;
		case ON:
			setPins(true, true);
			break;
	}
}