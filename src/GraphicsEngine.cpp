#include <Adafruit_GFX.h>
#include <Adafruit_SSD1327.h>
#include <ArduinoEigen.h>

using Eigen::Matrix3f;

void drawPlayer(float x, float y, float angle, Adafruit_SSD1327* display)
{
    Matrix3f triangleVertices = 
    (Matrix3f() << 
        -0.5f, -0.5f, 0.0f,
        0.5f, -0.5f, 0.0f,
        0.0f,  0.5f, 0.0f
    ).finished();

    Eigen::Transform<float, 3, Eigen::Affine> t;
    t.translate(Eigen::Vector3f(x, y, 0));
    t.rotate(Eigen::AngleAxisf(angle, Eigen::Vector3f(0, 0, 1)));

    display->drawTriangle(0, 40, -40, -40, 40, -40, SSD1327_WHITE);
}

void drawEnemy()
{
    
}