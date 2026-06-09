#include "game.h"
#include "textureManager.h"
#include "gameObject.h"

GameObject* player;

Game::Game() {
    isRunning = false;
}
Game::~Game() {

}

void Game::init(const char* title, int width, int height, bool fullscreen) {
    int flags = 0;
    if(fullscreen) {
        flags = SDL_WINDOW_FULLSCREEN;
    }

    std::cout << "Status: " << (SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO) == 1) << std::endl;
    if(SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO) == 1) {
        std::cout << "Subsystems Initialized!..." << std::endl;

        window = SDL_CreateWindow(title, width, height, flags);
        if (window) {
            std::cout << "Window created!..." << std::endl;
        }
        renderer = SDL_CreateRenderer(window, nullptr);
        if (renderer) {
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            std::cout << "Renderer created!..." << std::endl;
        }
        isRunning = true;
    } else {
        isRunning = false;
    }

    player = new GameObject((textureLocation + "/characters/player.png").c_str(), renderer);


}

void Game::handleEvents() {
    SDL_Event event;
    SDL_PollEvent(&event);
    switch (event.type) {
        case SDL_EVENT_QUIT:
            isRunning = false;
            break;
        default:
            break;
    }
}

void Game::update(){
    player->update();
}

void Game::render() {
    SDL_RenderClear(renderer);
    player->render();
    SDL_RenderPresent(renderer);
}

void Game::clean() {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    std::cout << "Game Cleaned!..." << std::endl;
}
