#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H
#include <Adafruit_SSD1327.h>

struct Enemy
{
    float X;
    float Y;
    float Z;
    float Angle;
    float Speed;
};

class GameManager
{
    public:
        GameManager(Adafruit_SSD1327* display);
        void initializeGame();
        void handleInput(float x, float y, int sw, float delta);
        void gameLoop();
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
        float angle;
        int size;

        //enemy
        Enemy enemies[5];

        // OLED
        Adafruit_SSD1327* display;
    

};



#endif