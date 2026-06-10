#include "gameObject.h"
#include "textureManager.h"

GameObject::GameObject(const char* textureSheet, SDL_Renderer* ren){
    renderer = ren;
    objTexture = TextureManager::LoadTexture(textureSheet, ren);
    xPos = 0;
    yPos = 0;
    xVel = 0;
    yVel = 0;
}

GameObject::~GameObject(){

}

void GameObject::update(){
    xPos += xVel;
    yPos += yVel;

    srcR.x = 0;
    srcR.y = 0;
    srcR.h = 48;
    srcR.w = 48;

    destR.x = xPos;
    destR.y = yPos;
    destR.w = 48;
    destR.h = 48;
}

void GameObject::render(){
    SDL_RenderTexture(renderer, objTexture, &srcR, &destR);
}

void GameObject::setObjName(std::string name){
    objName = name;
}

void GameObject::moveUp(){
    yVel = -3;
}

void GameObject::moveDown(){
    yVel = 3;
}

void GameObject::moveLeft(){
    xVel = -3;
}

void GameObject::moveRight(){
    xVel = 3;
}

void GameObject::stopVertical(){
    yVel = 0;
}

void GameObject::stopHorizontal(){
    xVel = 0;
}