#include "textureManager.h"

SDL_Texture* TextureManager::LoadTexture(const char* fileName, SDL_Renderer* ren){
    SDL_Surface* tempSurface = SDL_LoadPNG(fileName);
    if(!tempSurface) {
        std::cout << "Image not found!" << std::endl;
    }
    SDL_Texture* tex = SDL_CreateTextureFromSurface(ren, tempSurface);
    SDL_SetTextureScaleMode(tex, SDL_SCALEMODE_NEAREST);
    SDL_DestroySurface(tempSurface);
    return tex;
}