#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_SSD1327.h>
#include "GameManager.h"
#include "Controller.h"
#include "Audio.h"

#include <GraphicsEngine.h>

#define OLED_RESET -1
#define DISPLAY_SDA 9
#define DISPLAY_SCL 10

Adafruit_SSD1327 display(128, 128, &Wire, OLED_RESET, 1000000);

unsigned long delta;
unsigned long start;
unsigned long end;

GameManager* gm;

Star stars[] = 
    {
        {0.8880, 0.4982}, {0.1466, 0.2135}, {0.6841, 0.0398}, {0.3109, 0.4634}, 
        {0.3457, 0.5412}, {0.8060, 0.9503}, {0.0293, 0.0683}, {0.9516, 0.1083}, 
        {0.6763, 0.3546}, {0.8652, 0.6534}, {0.5348, 0.8018}, {0.6302, 0.1139}, 
        {0.2241, 0.8848}, {0.6574, 0.7935}, {0.3153, 0.3270}, {0.0782, 0.4550}, 
        {0.3807, 0.5363}, {0.5471, 0.3389}, {0.3676, 0.8271}, {0.4419, 0.8068}
    };


void setup(void)
{

    Serial.begin(9600);
    Serial.println("Starting...");
    
    Wire.begin(DISPLAY_SDA, DISPLAY_SCL);

    ControllerInit(); //Initialize controller pins

    // Connect to OLED
   if (!display.begin(0x3D)) 
    {
        Serial.println("Unable to initialize OLED");
        while (1) yield();
    }
    display.clearDisplay();
    display.display();

    gm = new GameManager(&display);
    gm->initializeGame();
    
    start = millis();
}

void loop()
{
    delta = end - start; 
    Input input = ControllerLoop(); //Read controller values and print them to serial monitor
    
    Enemy enemy = gm->gameLoop(input.x, input.y);

    Graphics::drawEnemy(enemy.X, enemy.Y, enemy.Z, &display);
    Graphics::drawStars(stars, 0.01, atan2f(input.y, input.x), &display);
    display.display();
    delay(10);
    display.clearDisplay();

    start = millis();
}