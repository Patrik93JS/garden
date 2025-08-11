#include <Arduino.h>
#include <SimpleDHT.h>

#define DHT_PIN 3              // Pin pro DHT11
#define SOIL_MOISTURE_PIN A0   // Pin pro kapacitní senzor vlhkosti půdy
#define WATER_PUMP_RELAY_PIN 8 // Pin pro relé čerpadla
#define LED_PIN 2              // Pin pro relé LED pásku

SimpleDHT11 dht(DHT_PIN);

void setup() {
    Serial.begin(9600);
    pinMode(SOIL_MOISTURE_PIN, INPUT);
    pinMode(WATER_PUMP_RELAY_PIN, OUTPUT);
    pinMode(LED_PIN, OUTPUT);

    digitalWrite(WATER_PUMP_RELAY_PIN, LOW); // Čerpadlo vypnuto na startu
    digitalWrite(LED_PIN, LOW);              // LED pásek vypnutý na startu
}

void loop() {
    // Čtení teploty a vlhkosti z DHT11
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

    // Čtení vlhkosti půdy z kapacitního senzoru
    int moisture = analogRead(SOIL_MOISTURE_PIN);
    Serial.print("Soil Moisture (raw): ");
    Serial.println(moisture);

    // Ovládání čerpadla podle vlhkosti půdy
    if (moisture < 500) { // Kalibruj tuto hodnotu podle potřeb
        Serial.println("Soil too dry, starting pump...");
        digitalWrite(WATER_PUMP_RELAY_PIN, HIGH); // Zapne čerpadlo
        delay(5000);                              // Čerpadlo běží 5 sekund
        digitalWrite(WATER_PUMP_RELAY_PIN, LOW);  // Vypne čerpadlo
    }

    // Ovládání LED pásku
    digitalWrite(LED_PIN, HIGH);
    Serial.println("LED ON");
    delay(10000); // 10 sekund zapnutý
    digitalWrite(LED_PIN, LOW);
    Serial.println("LED OFF");
    delay(2000);  // 2 sekundy vypnutý

    delay(1000); // Pauza pro stabilní čtení DHT11
}