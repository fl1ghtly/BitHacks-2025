#ifndef GRAPHICS_ENGINE_H
#define GRAPHICS_ENGINE_H

namespace Graphics
{
    void drawEnemy(float x, float y, float z, Adafruit_SSD1327* display);
    void drawEnemies(float x[], float y[], float z[], Adafruit_SSD1327* display);
    const float drawDistance = 32.0f;
}

#endif