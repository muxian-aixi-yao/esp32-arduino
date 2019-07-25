#include "pwm.hpp"

PWM::PWM(byte pin)
{
    pinMode(pin,OUTPUT);
}

PWM::~PWM()
{
    disattach();
}


void PWM::servoWrite(unsigned char val)
{
    int pulsewidth = (val * 11) + 500;  //将角度转化为500-2480的脉宽值
    digitalWrite(pin, HIGH);        //将舵机接口电平至高
    delayMicroseconds(pulsewidth);        //延时脉宽值的微秒数
    digitalWrite(pin, LOW);         //将舵机接口电平至低
    delayMicroseconds(20000 - pulsewidth);
}

void PWM::disattach()
{
    digitalWrite(pin,LOW);
    pinMode(pin,INPUT);
}

