#include "player.h"
#include <iostream>
#include <cmath>

Player::Player(const char *textureSheet, SDL_Renderer *ren) : GameObject(textureSheet, ren)
{
    xVel = 0;
    yVel = 0;
}

void Player::update()
{
    movement();
    yPos += yVel;
    xPos += xVel;
    GameObject::update();
}

void Player::movement()
{
    const bool *keys = SDL_GetKeyboardState(nullptr);

    float moveX = 0;
    float moveY = 0;

    if (keys[SDL_SCANCODE_W])
    {
        std::cout << "W" << std::endl;
        moveY -= 1;
    }
    if (keys[SDL_SCANCODE_S])
    {
        std::cout << "S" << std::endl;
        moveY += 1;
    }
    if (keys[SDL_SCANCODE_A]){
        std::cout << "A" << std::endl;
        moveX -= 1;
    }
    if (keys[SDL_SCANCODE_D]){
        std::cout << "D" << std::endl;
        moveX += 1;
    }

    float length = sqrt(moveX * moveX + moveY * moveY);

    if (length > 0)
    {
        moveX /= length;
        moveY /= length;
    }

    xVel = moveX * speed;
    yVel = moveY * speed;
}