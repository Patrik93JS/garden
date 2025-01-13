#ifndef LedClass_h
#define LedClass_h

#include "Arduino.h"


class LedClass {
    public:
        LedClass(int pin);
        void controllLed(int blinkRate);
    private:
        int _pin;
};

#endif