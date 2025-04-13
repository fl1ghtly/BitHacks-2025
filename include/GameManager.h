#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H

class GameManager
{
    public:
        GameManager();
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
        int enemyLife;
        float enemyX;
        float enemyY;
        float enemyZ;
        int enemySize;
        float enemyAngle;
    

};



#endif