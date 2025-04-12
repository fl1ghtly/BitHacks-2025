#include <Arduino.h>
#include <Wire.h>
#include <SdFat.h>
#include <Adafruit_SSD1327.h>
#include "GameManager.h"
#include "Controller.h"
#include "Audio.h"
#include "GetMACAddress.h"

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
    Serial.println("Starting...");
    Wire.begin(DISPLAY_SDA, DISPLAY_SCL);

    ControllerInit(); //Initialize controller pins
    macInit(); //Initialize MAC Address

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
    delta = end - start; 
    ControllerLoop(); //Read controller values and print them to serial monitor
    macLoop(); //Read MAC Address and print it to serial monitor
    delay(1000); //Delay to prevent overload serial monitor    end = millis();
    
    gm->gameLoop();

    start = millis();
}