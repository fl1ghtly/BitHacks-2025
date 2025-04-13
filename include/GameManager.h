#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H
#include <Adafruit_SSD1327.h>

struct Enemy
{
    float X;
    float Y;
    float Z;
    float Speed;
};

class GameManager
{
    public:
        GameManager(Adafruit_SSD1327* display);
        void initializeGame();
        Enemy gameLoop(float x, float y);
        void initializeEnemy();
        void resetEnemy();
        void loopEnemy();

    private:
        // Player
        int lives;
        float playerX;
        float playerY;
        float playerZ;
        float speed;

        Enemy e;
        // OLED
        Adafruit_SSD1327* display;
    

};



#endif