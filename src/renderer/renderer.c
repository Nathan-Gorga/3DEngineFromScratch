#include "renderer.h"

SDL_Renderer * initRenderer(SDL_Window *window){
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    // Set draw color to black and clear the screen
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    // Set draw color to white
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    
    return renderer;
}
