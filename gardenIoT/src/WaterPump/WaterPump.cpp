#include "WaterPump.h"

WaterPump::WaterPump(int relayPin) : _relayPin(relayPin) {
    pinMode(_relayPin, OUTPUT);
    digitalWrite(_relayPin, LOW); 
}

void WaterPump::turnOn() {
    digitalWrite(_relayPin, HIGH);
}

void WaterPump::turnOff() {
    digitalWrite(_relayPin, LOW);
}
