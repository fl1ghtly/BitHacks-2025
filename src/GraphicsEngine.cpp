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

void Graphics::drawStars(Star stars[], float speed, float moveDirection, Adafruit_SSD1327* display)
{
    /*
    moveDirection: Direction that the player moves given in radians
    */
    for (int i = 0; i < 20; i++)
    {
        stars[i].x += speed * cos(moveDirection);
        stars[i].y += speed * sin(moveDirection);

        if (stars[i].x > 1.0)
        {
            stars[i].x = 0.0;
        } else if (stars[i].x < 0)
        {
            stars[i].x = 1.0;
        }

        if (stars[i].y > 1.0)
        {
            stars[i].y = 0.0;
        } else if (stars[i].y < 0.0)
        {
            stars[i].y = 1.0;
        }

        display->drawPixel(((int) (stars[i].x * display->width())) % display->width(), ((int) (stars[i].y * display->height())) % display->height(), SSD1327_WHITE);
    }
}