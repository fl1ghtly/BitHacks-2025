#include "GameManager.h"
#include "Audio.h"
#include <chrono>
#include <thread>

GameManager::GameManager()
{
    // Setup all game variables
    this->lives = 3;    //3 lives
    this->speed = 1.0;  //default speed
    this->size = 10;    //size is 10? idk what that means

    this->enemyLife = 1;
    this->enemySize = 10;
}

void GameManager::initializeGame()
{
    // Initialize anything if necessary, if not then delete this function

    //keep extremely simple. Do 1 enemy first. figure out array later
    //add enemy variables
    
    enemyX = -0.8;
    enemyY = 0.8;

    

    //no blockades
    //player intializes in the middle 

    playerX = 0;   //start the player in the middle, ten bits up about
    playerY = -0.5;


}

void GameManager::gameLoop()
{
    /* Runs in the microcontroller's loop function.
    Handles any game logic that needs to update continuously such as player and enemy movement
    */ 

    //what loops?
    //the movement of the enemies needs to loop
    //every second (add timescale) enemies move to the right and reset

    while (enemyX < 0.8) {
        enemyX += 0.2;
        sleep(1);   //adds a delay of 1 sec before it continues moving again
    }

    if (enemyX >= 0.8) {
        enemyX = -0.8;
        enemyY -= 0.2;
    }

    if (enemyY < -0.4) {
        this->lives -= 1;
        enemyX = -0.8;
        enemyY = 0.8;
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


    //we also need the shooting mechanics
    if (sw = 1) {
        //idk how to do shooting
    }
    
    //player cannot go above -0.4 Y
    if (playerY > -0.4) {
        playerY = -0.4; //should always "reset" to -0.4
    }
}