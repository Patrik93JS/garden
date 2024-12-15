#include "DHTSensor.h"

DHTSensor::DHTSensor(int pin, int type) : _dht(pin, type), _pin(pin) {}

void DHTSensor::begin() {
    _dht.begin();
}

float DHTSensor::readTemperature() {
    return _dht.readTemperature();
}

float DHTSensor::readHumidity() {
    return _dht.readHumidity();
}
