#ifndef WaterPump_h
#define WaterPump_h

#include "Arduino.h"

class WaterPump {
public:
    WaterPump(int relayPin);
    void turnOn();
    void turnOff();

private:
    int _relayPin;
};

#endif
