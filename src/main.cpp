#include "SDL3/SDL.h"
#include "game.h"

Game *game = nullptr;

int main(int argc, char* argv[]) { 
    game = new Game();
    game->init("SDL3 Test", 1280, 720, false);
    while (game->running()) {
        game->handleEvents();
        game->update();
        game->render();
    }
    game->clean();
    delete game;
    
	return 0;
}
