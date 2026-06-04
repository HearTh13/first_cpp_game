#include "SDL3/SDL.h"
#include <iostream>

int main(int argc, char* argv[]) { 
    SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO);
	SDL_Window* window = SDL_CreateWindow("SDL3 Test", 1280, 720, SDL_WINDOW_RESIZABLE);
	SDL_Renderer* renderer = SDL_CreateRenderer(window, nullptr);
	SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
	SDL_RenderClear(renderer);
	SDL_RenderPresent(renderer);
	SDL_Delay(3000);
	return 0;
}