#ifndef _AIXI_LED_HPP_
#define _AIXI_LED_HPP_

#include "Arduino.h"//导入arduino核心头文件


class LED
{
private:
    byte pin;
public:
    LED(byte pin);//构造函数
    ~LED();//析构函数
    byte getPin();
    void on();
    void off();
    bool getState();
    void disattach();//释放引脚与LED的绑定
};
#endif
