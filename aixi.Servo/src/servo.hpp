#ifndef _AIXI_SERVO_HPP_
#define _AIXI_SERVO_HPP_

extern "C" {
  #include "esp_timer.h"
}
#include "Arduino.h"

class SERVO
{
private:
    byte PIN;
public:
  SERVO(byte pin);
  ~SERVO();
  typedef void (*callback_t)(void);
  typedef void (*callback_with_arg_t)(void*);

//   void attach(float seconds, callback_t callback)
//   {
//     _attach_ms(seconds * 1000, true, reinterpret_cast<callback_with_arg_t>(callback), 0);
//   }

//   void attach_ms(uint32_t milliseconds, callback_t callback)
//   {
//     _attach_ms(milliseconds, true, reinterpret_cast<callback_with_arg_t>(callback), 0);
//   }

  template<typename TArg>
  void attach(float milliseconds, void (*callback)(TArg), TArg arg)
  {
    static_assert(sizeof(TArg) <= sizeof(uint32_t), "attach() callback argument size must be <= 4 bytes");
    // C-cast serves two purposes:
    // static_cast for smaller integer types,
    // reinterpret_cast + const_cast for pointer types
    uint32_t arg32 = (uint32_t)arg;
    _attach_us_(milliseconds * 1000, true, reinterpret_cast<callback_with_arg_t>(callback), arg32);
  }

  template<typename TArg>
  void attach_ms(uint32_t microsecond, void (*callback)(TArg), TArg arg)
  {
    static_assert(sizeof(TArg) <= sizeof(uint32_t), "attach_ms() callback argument size must be <= 4 bytes");
    uint32_t arg32 = (uint32_t)arg;
    _attach_us_(microsecond, true, reinterpret_cast<callback_with_arg_t>(callback), arg32);
  }

//   void once(float seconds, callback_t callback)
//   {
//     _attach_ms(seconds * 1000, false, reinterpret_cast<callback_with_arg_t>(callback), 0);
//   }

//   void once_ms(uint32_t milliseconds, callback_t callback)
//   {
//     _attach_ms(milliseconds, false, reinterpret_cast<callback_with_arg_t>(callback), 0);	
//   }

//   template<typename TArg>
//   void once(float seconds, void (*callback)(TArg), TArg arg)
//   {
//     static_assert(sizeof(TArg) <= sizeof(uint32_t), "attach() callback argument size must be <= 4 bytes");
//     uint32_t arg32 = (uint32_t)(arg);
//     _attach_ms(seconds * 1000, false, reinterpret_cast<callback_with_arg_t>(callback), arg32);
//   }

//   template<typename TArg>
//   void once_ms(uint32_t milliseconds, void (*callback)(TArg), TArg arg)
//   {
//     static_assert(sizeof(TArg) <= sizeof(uint32_t), "attach_ms() callback argument size must be <= 4 bytes");
//     uint32_t arg32 = (uint32_t)(arg);
//     _attach_ms(milliseconds, false, reinterpret_cast<callback_with_arg_t>(callback), arg32);
//   }

  void detach();

protected:	
  void _attach_us_(uint32_t microsecond, bool repeat, callback_with_arg_t callback, uint32_t arg);

protected:
  esp_timer_handle_t _timer;
};


#endif  // TICKER_H
