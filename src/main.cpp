#include <Arduino.h>
#include <Wire.h>
#include <SdFat.h>
#include <Adafruit_SSD1327.h>
#include "GameManager.h"

#define OLED_RESET -1
#define DISPLAY_SDA 9
#define DISPLAY_SCL 10

Adafruit_SSD1327 display(128, 128, &Wire, OLED_RESET, 1000000);

unsigned long delta;
unsigned long start;
unsigned long end;

GameManager* gm;

void setup(void)
{
    Serial.begin(9600);
    Wire.begin(DISPLAY_SDA, DISPLAY_SCL);

    // Connect to OLED
    if (!display.begin(0x3D)) 
    {
        Serial.println("Unable to initialize OLED");
        while (1) yield();
    }
    display.clearDisplay();
    display.display();

    gm = new GameManager();
    gm->initializeGame();
    
    start = millis();
}

void loop()
{
    end = millis();
    delta = end - start; 
    
    gm->gameLoop();

    start = millis();
}