#include "Arduino.h"
#include "LedClass.h"

LedClass::LedClass(int pin) {
    pinMode(pin, OUTPUT);
    _pin = pin;
}

void LedClass::controllLed(int blinkRate) {
    digitalWrite(_pin, HIGH);
    delay(blinkRate);
    digitalWrite(_pin, LOW);
    delay(blinkRate);
}