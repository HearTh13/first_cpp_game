#include "game.h"

class GameObject{
    public:
        GameObject(const char* textureSheet, SDL_Renderer* ren);
        ~GameObject();

        void update();
        void render();

        void setObjName(std::string name);
        void moveUp();
        void moveDown();
        void moveLeft();
        void moveRight();
        void stopVertical();
        void stopHorizontal();

    private:
        std::string objName = "";

        SDL_Texture* objTexture;
        SDL_FRect srcR, destR;
        SDL_Renderer* renderer;

        float xPos;
        float yPos;
        float xVel;
        float yVel;
};