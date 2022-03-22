#include "libs.h"

Button::Button(const uint8_t& pin) : pin(pin)
{
	pinMode(pin, INPUT_PULLUP); 
}

uint8_t Button::getValue() const
{
	return digitalRead(pin);  
}