/*
  AsyncDelay.h - Library for non-blocking delay.
  Created by Lucas H. Dijon, January 17, 2020.
  Released into the public domain.
*/

#ifndef AsyncDelay_h
#define AsyncDelay_h

#include "Arduino.h"

class AsyncDelay
{
private:
    /* data */
    unsigned long _currentMillis;
    unsigned long _previousMillis;
    unsigned long _INTERVAL;
    void (*_ptr_func)();
public:
    AsyncDelay();
    AsyncDelay(unsigned long interval);
    AsyncDelay(void (*func)(), unsigned long interval);
    AsyncDelay(void (*func)());
    void setInterval(unsigned long interval);
    void attach(void (*func)());
    void set(void (*func)(),unsigned long interval);
    void run();
    /* ~AsyncDelay(); */
};

#endif