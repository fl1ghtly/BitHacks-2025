#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H

class GameManager
{
    public:
        GameManager();
        void initializeGame();
        void handleInput(float x, float y, int sw, float delta);
        void gameLoop();

    private:
        // Player
        int lives;
        float playerX;
        float playerY;
        float speed;
        float angle;
        int size;
};

#endif