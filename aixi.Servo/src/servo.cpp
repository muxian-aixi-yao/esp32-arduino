#include "servo.hpp"

SERVO::SERVO(byte pin) :
  _timer(nullptr) {
      PIN = pin;
      pinMode(PIN,OUTPUT);
  }

SERVO::~SERVO() {
  detach();
}

void SERVO::_attach_us_(uint32_t microsecond, bool repeat, callback_with_arg_t callback, uint32_t arg) {
  esp_timer_create_args_t _timerConfig;
  _timerConfig.arg = reinterpret_cast<void*>(arg);
  _timerConfig.callback = callback;
  _timerConfig.dispatch_method = ESP_TIMER_TASK;
  _timerConfig.name = "SERVO";
  if (_timer) {
    esp_timer_stop(_timer);
    esp_timer_delete(_timer);
  }
  esp_timer_create(&_timerConfig, &_timer);
  if (repeat) {
    esp_timer_start_periodic(_timer, microsecond);
  } else {
    esp_timer_start_once(_timer, microsecond);
  }
}


void SERVO::detach() {
    if (_timer) {
        esp_timer_stop(_timer);
        esp_timer_delete(_timer);
        _timer = nullptr;
    }
    digitalWrite(PIN,LOW);
    pinMode(PIN,INPUT);
}
