#include <Arduino.h>
#include <Wire.h>
#include <SPI.h>
#include <SdFat.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ILI9341.h>
#include "TouchScreen.h"
#include "Controller.h"
#include "Audio.h"


void setup(void)
{
    Serial.begin(115200); //Initialize with baud rate of 115200
    Serial.println("Starting...");
    ControllerInit(); //Initialize controller pins
}

void loop()
{
    ControllerLoop(); //Read controller values and print them to serial monitor
    delay(1000); //Delay to prevent overload serial monitor
}