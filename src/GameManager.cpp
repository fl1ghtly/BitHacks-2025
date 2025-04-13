#include "GameManager.h"
#include "GraphicsEngine.h"
// #include "Audio.h"

GameManager::GameManager(Adafruit_SSD1327* display)
{
    // Setup all game variables
    this->lives = 3;    //3 lives
    this->speed = 0.05;  //default speed
    this->display = display;
}

void GameManager::initializeGame()
{
    // Initialize anything if necessary, if not then delete this function

    playerX = 0;   //start the player in the middle
    playerZ = 0;

    //adjust game volume here?? might not be needed
    // player.volume(5);

    this->e = {0.5, 0.5, 0.1, 0.05};
}

Enemy GameManager::gameLoop(float x, float y)
{
    /* Runs in the microcontroller's loop function.
    Handles any game logic that needs to update continuously such as player and enemy movement
    */ 
   
    for (int i = 0; i < 1; i++)
    {
        e.X += speed * x;
        e.Y -= speed * y;
        e.Z += e.Speed;

        if (e.Z > 2.5)
        {
            e.X = 0.5;
            e.Y = 0.5;
            e.Z = 0.1;
        }
    }

    if (lives <= 0)
    {
        // do something
    }

    return e;
}

void GameManager::handleInput(float x, float y, int sw, float delta)
{
    /*
    Gets input from Analog Joystick. X and Y are bound between (-1, 1).
    SW is when the button is pressed.
    delta is the time between each frame
    */
    angle = atan2f(y, x);
    playerX += speed * x;
    playerY += speed * y;

}