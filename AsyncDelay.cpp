/*
  AsyncDelay.cpp - Library for non-blocking delay.
  Created by Lucas H. Dijon, January 17, 2020.
  Released into the public domain.
*/

#include "Arduino.h"
#include "AsyncDelay.h"

AsyncDelay::AsyncDelay() {
    _currentMillis = millis();
    _previousMillis = _currentMillis;
    _INTERVAL = 0;
    _ptr_func = NULL;
}

AsyncDelay::AsyncDelay(unsigned long interval) {
    _currentMillis = millis();
    _previousMillis = _currentMillis;
    _INTERVAL = interval;
    _ptr_func = NULL;
}

AsyncDelay::AsyncDelay(void (*func)(), unsigned long interval) {
    _currentMillis = millis();
    _previousMillis = _currentMillis;
    _INTERVAL = interval;
    _ptr_func = func;
}

AsyncDelay::AsyncDelay(void (*func)()) {
    _currentMillis = millis();
    _previousMillis = _currentMillis;
    _INTERVAL = 0;
    _ptr_func = func;
}

void AsyncDelay::setInterval(unsigned long interval) {
    _INTERVAL = interval;
}

void AsyncDelay::attach(void (*func)()) {
    _ptr_func = func;
}

void AsyncDelay::set(void (*func)(),unsigned long interval) {
    setInterval(interval);
    attach(func);
}

void AsyncDelay::run() {
    _currentMillis = millis();
    if(_currentMillis - _previousMillis >= _INTERVAL) {
        _previousMillis = _currentMillis;
        (*_ptr_func)();
    }
}
