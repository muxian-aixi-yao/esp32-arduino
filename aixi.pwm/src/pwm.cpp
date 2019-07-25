#include "pwm.hpp"

PWM::PWM(byte pin)
{
    PIN = pin;
    pinMode(PIN,OUTPUT);
}

PWM::~PWM()
{
    disattach();
}


void PWM::servoWrite(unsigned char val)
{
    int i;
    for(i = 0; i < 50; i++)
    {
        int pulsewidth = (val * 11) + 500;  //将角度转化为500-2480的脉宽值
        digitalWrite(PIN, HIGH);        //将舵机接口电平至高
        delayMicroseconds(pulsewidth);        //延时脉宽值的微秒数
        digitalWrite(PIN, LOW);         //将舵机接口电平至低
        delayMicroseconds(20000 - pulsewidth);
    }
    delay(100);
}

void PWM::disattach()
{
    digitalWrite(PIN,LOW);
    pinMode(PIN,INPUT);
}

