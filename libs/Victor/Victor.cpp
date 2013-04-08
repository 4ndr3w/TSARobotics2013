#include "Victor.h"

Victor::Victor(int pin) : Servo()
{
	this->pin = pin;
	enable();
}

void Victor::enable()
{
	attach(pin);
}

void Victor::disable()
{
	detach();
}

void Victor::set(int value)
{
	if ( !attached() )
		return;
	this->writeMicroseconds(value);
}
