#ifndef GRAPHICS_ENGINE_H
#define GRAPHICS_ENGINE_H

struct Star
{
    float x;
    float y;
};

namespace Graphics
{
    const float drawDistance = 32.0f;
    
    void drawEnemy(float x, float y, float z, Adafruit_SSD1327* display);
    void drawEnemies(float x[], float y[], float z[], Adafruit_SSD1327* display);
    void drawStars(Star stars[], float speed, float moveDirection, Adafruit_SSD1327* display);
}

#endif