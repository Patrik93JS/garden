#ifndef DHTSensor_h
#define DHTSensor_h

#include "Arduino.h"
#include <DHT.h>  

class DHTSensor {
public:
    DHTSensor(int pin, int type);
    void begin();
    float readTemperature();
    float readHumidity();

private:
    int _pin;
    DHT _dht;
};

#endif
