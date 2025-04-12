#include <Arduino.h>
#include "GameManager.h"

GameManager::GameManager()
{
    // Setup all game variables
    this->lives = 3;
    this->speed = 1.0;
    this->size = 10;
}

void GameManager::initializeGame()
{
    // Initialize anything if necessary, if not then delete this function
}

void GameManager::gameLoop()
{
    /* Runs in the microcontroller's loop function.
    Handles any game logic that needs to update continuously such as player and enemy movement
    */ 

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