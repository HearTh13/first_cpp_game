#include "gameObject.h"
#include "textureManager.h"

GameObject::GameObject(const char* textureSheet, SDL_Renderer* ren){
    renderer = ren;
    objTexture = TextureManager::LoadTexture(textureSheet, ren);
}

GameObject::~GameObject(){

}

void GameObject::update(){
    xPos = 0;
    yPos = 0;

    srcR.h = 64;
    srcR.w = 64;
    srcR.x = 0;
    srcR.y = 0;

    destR.x = yPos;
    destR.y = xPos;
    destR.w = srcR.w * 2;
    destR.h = srcR.h * 2;
}

void GameObject::render(){
    SDL_RenderTexture(renderer, objTexture, &srcR, &destR);
}