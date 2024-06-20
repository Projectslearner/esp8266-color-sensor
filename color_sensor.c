/*
    Project name : ESP8266 Color Sensor
    Modified Date: 20-06-2024
    Code by : Projectslearner
    Website : https://projectslearner.com/learn/esp8266-color-sensor
*/

#include <Wire.h>
#include "Adafruit_TCS34725.h"

// Create the TCS34725 object
Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_50MS, TCS34725_GAIN_1X);

void setup() {
    Serial.begin(115200);
    if (tcs.begin()) {
        Serial.println("Found color sensor");
    } else {
        Serial.println("No TCS34725 found ... check your connections");
        while (1); // Halt
    }
}

void loop() {
    uint16_t r, g, b, c;
    tcs.getRawData(&r, &g, &b, &c);

    // Calculate color temperature in Kelvin
    uint16_t colorTemp = tcs.calculateColorTemperature(r, g, b);
    // Calculate lux
    uint16_t lux = tcs.calculateLux(r, g, b);

    // Print the values
    Serial.print("R: "); Serial.print(r);
    Serial.print(" G: "); Serial.print(g);
    Serial.print(" B: "); Serial.print(b);
    Serial.print(" C: "); Serial.print(c);
    Serial.print(" Temp: "); Serial.print(colorTemp);
    Serial.print(" K Lux: "); Serial.print(lux);
    Serial.println(" lux");

    delay(1000);
}
