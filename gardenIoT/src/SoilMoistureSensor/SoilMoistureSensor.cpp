#include "SoilMoistureSensor.h"

SoilMoistureSensor::SoilMoistureSensor(int pin) : _pin(pin) {
    pinMode(_pin, INPUT);
}

int SoilMoistureSensor::readMoisture() {
    return analogRead(_pin);
}
