#ifndef SoilMoistureSensor_h
#define SoilMoistureSensor_h

#include "Arduino.h"

class SoilMoistureSensor {
public:
    SoilMoistureSensor(int pin);
    int readMoisture();

private:
    int _pin;
};

#endif
