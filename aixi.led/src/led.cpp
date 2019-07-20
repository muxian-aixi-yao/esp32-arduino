#include "led.hpp"

LED::LED(byte pin)
{
    pinMode(pin,OUTPUT);
}

LED::~LED()
{
    disattach();
}


void LED::on()
{
    digitalWrite(pin,HIGH);
}

void LED::off()
{
    digitalWrite(pin,LOW);
}

bool LED::getState()
{
    return digitalRead(pin);
}

void LED::disattach()
{
    digitalWrite(pin,LOW);
    pinMode(pin,INPUT);
}

