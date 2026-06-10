#include "gameObject.h"

class Player : public GameObject{
    public:
        Player(const char* textureSheet, SDL_Renderer* ren);
        void update() override;
    private: 
        float xVel;
        float yVel;
        float speed = 3;

        void movement();
};