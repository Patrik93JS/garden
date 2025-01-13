#include <Arduino.h>
#include <SimpleDHT.h>

// Pin konfigurace
#define DHT_PIN 3
#define SOIL_MOISTURE_PIN A0
#define WATER_PUMP_RELAY_PIN 8
#define LED_PIN 2

SimpleDHT11 dht(DHT_PIN);

void setup() {
    Serial.begin(9600);
    pinMode(SOIL_MOISTURE_PIN, INPUT);
    pinMode(WATER_PUMP_RELAY_PIN, OUTPUT);
    pinMode(LED_PIN, OUTPUT);

    digitalWrite(WATER_PUMP_RELAY_PIN, LOW);
}

void loop() {
    byte temperature = 0;
    byte humidity = 0;
    int err = dht.read(&temperature, &humidity, NULL);
    if (err != SimpleDHTErrSuccess) {
        Serial.print("DHT11 read error: ");
        Serial.println(err);
        delay(2000); 
        return;
    }

    Serial.print("Temperature: ");
    Serial.print((int)temperature);
    Serial.println(" *C");

    Serial.print("Humidity: ");
    Serial.print((int)humidity);
    Serial.println(" %");

    int moisture = analogRead(SOIL_MOISTURE_PIN);
    Serial.print("Soil Moisture: ");
    Serial.println(moisture);

    if (moisture < 500) { 
        digitalWrite(WATER_PUMP_RELAY_PIN, HIGH); 
        delay(5000); 
        digitalWrite(WATER_PUMP_RELAY_PIN, LOW);  
    }

    digitalWrite(LED_PIN, HIGH);
    delay(10000); 
    digitalWrite(LED_PIN, LOW);
    delay(2000); 
}
