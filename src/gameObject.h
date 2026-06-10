#pragma once
#include "game.h"

class GameObject{
    public:
        GameObject(const char* textureSheet, SDL_Renderer* ren);
        ~GameObject();

        virtual void update();
        virtual void render();

        void setObjName(std::string name);

    protected:
        std::string objName = "";

        SDL_Texture* objTexture;
        SDL_FRect srcR, destR;
        SDL_Renderer* renderer;

        float xPos;
        float yPos;
};