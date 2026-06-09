#include "SDL3/SDL.h"
#include "game.h"

Game *game = nullptr;
int FPS = 60;
int frameDelay = 1000 / FPS;
Uint32 frameStart;
int frameTime;

int main(int argc, char* argv[]) { 
    game = new Game();
    game->init("SDL3 Test", 1280, 720, false);
    while (game->running()) {
        frameStart = SDL_GetTicks();
        game->handleEvents();
        game->update();
        game->render();
        frameTime = SDL_GetTicks() - frameStart;
        if (frameDelay > frameTime) {
            SDL_Delay(frameDelay - frameTime);
        }
    }
    game->clean();
    delete game;
    
	return 0;
}
