#include "game.h"

class GameObject{
    public:
        GameObject(const char* textureSheet, SDL_Renderer* ren);
        ~GameObject();

        void update();
        void render();

    private:
        int xPos;
        int yPos;

        SDL_Texture* objTexture;
        SDL_FRect srcR, destR;
        SDL_Renderer* renderer;

};