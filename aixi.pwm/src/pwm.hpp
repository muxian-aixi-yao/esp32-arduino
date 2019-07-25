#ifndef _AIXI_PWM_HPP_
#define _AIXI_PWM_HPP_

#include "Arduino.h"//导入arduino核心头文件


class PWM
{
private:
    byte PIN;
public:
    PWM(byte pin);//构造函数
    ~PWM();//析构函数
    void servoWrite(unsigned char val);
    void disattach();
};
#endif
