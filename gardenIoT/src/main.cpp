#include <Arduino.h>
#include "./DHTSensor/DHTSensor.h"
#include <SoilMoistureSensor.h>
#include <WaterPump.h>
#include <LedClass.h>

#define DHT_PIN 2
#define DHT_TYPE DHT11
#define SOIL_MOISTURE_PIN A0
#define WATER_PUMP_RELAY_PIN 8

DHTSensor dht(DHT_PIN, DHT_TYPE);
SoilMoistureSensor soilMoisture(SOIL_MOISTURE_PIN);
WaterPump pump(WATER_PUMP_RELAY_PIN);
LedClass LED(10);

void setup() {
    Serial.begin(9600);
    dht.begin();
    pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
    float temperature = dht.readTemperature();
    float humidity = dht.readHumidity();
    int moisture = soilMoisture.readMoisture();

    Serial.print("Temperature: ");
    Serial.print(temperature);
    Serial.println(" C");

    Serial.print("Humidity: ");
    Serial.print(humidity);
    Serial.println(" %");

    Serial.print("Soil Moisture: ");
    Serial.println(moisture);

    if (moisture < 500) { 
        pump.turnOn();
        delay(5000); 
        pump.turnOff();
    }

    LED.controllLed(1000);
    delay(2000); 
}