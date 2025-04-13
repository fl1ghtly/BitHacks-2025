#include "GameManager.h"
#include "GraphicsEngine.h"
#include "Audio.h"

GameManager::GameManager(Adafruit_SSD1327* display)
{
    // Setup all game variables
    this->lives = 3;    //3 lives
    this->speed = 1.0;  //default speed
    this->display = display;
}

void GameManager::initializeGame()
{
    // Initialize anything if necessary, if not then delete this function

    playerX = 0;   //start the player in the middle
    playerZ = 0;

    //adjust game volume here?? might not be needed
    player.volume(5);

    Enemy enemies[5] = {};
    for (int i = 0; i < 5; i++)
    {
        enemies[i] = {(float) random(-1, 1), (float) random(-1, 1), (float) random(0.5, 1), (float) random(0, 6.28), (float) random(-0.1, 0.1)};
    }
}

void GameManager::gameLoop()
{
    /* Runs in the microcontroller's loop function.
    Handles any game logic that needs to update continuously such as player and enemy movement
    */ 
   
    for (int i = 0; i < 5; i++)
    {
        Enemy e = enemies[i];
        e.Angle = atan2f(e.X, e.Z);
        e.X = e.Speed * sin(e.Angle);
        e.Z = e.Speed * cos(e.Angle);

        Graphics::drawEnemy(e.X, e.Y, e.Z, display);
        // Only do when enemy z < 0.05
        if (e.Z > 0.05) { continue; }
        // Check enemy x vs player x
        // Check enemy y vs player y
        if (abs(e.X - playerX) < 0.05 || abs(e.Y - playerY) < 0.05)
        {
            lives--;
        }

        Enemy newE = enemies[i] = {(float) random(-1, 1), (float) random(-1, 1), (float) random(0.5, 1), (float) random(0, 6.28), (float) random(-0.1, 0.1)};
        enemies[i] = newE;
    }

    if (lives <= 0)
    {
        // do something
    }

}

void GameManager::handleInput(float x, float y, int sw, float delta)
{
    /*
    Gets input from Analog Joystick. X and Y are bound between (-1, 1).
    SW is when the button is pressed.
    delta is the time between each frame
    */
    angle = atan2f(y, x);
    playerX += speed * x * delta;
    playerY += speed * y * delta;

}