#include <Adafruit_GFX.h>
#include <Adafruit_SSD1327.h>
#include "GraphicsEngine.h"

using namespace Graphics;

void Graphics::drawEnemy(float x, float y, float z, Adafruit_SSD1327* display)
{
    display->drawCircle(x * display->width(), y * display->height(), z * drawDistance, SSD1327_WHITE);
}

void Graphics::drawEnemies(float x[], float y[], float z[], Adafruit_SSD1327* display)
{
    for (int i = 0; i < sizeof(x)/sizeof(x[0]); i++)
    {
        drawEnemies(&x[i], &y[i], &z[i], display);
    }
}