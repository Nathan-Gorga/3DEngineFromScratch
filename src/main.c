#include "definitions.h"

typedef struct float3{
    float x; 
    float y; 
    float z;
} float3;

typedef struct float2{
    float x; 
    float y;
}float2;


SDL_Renderer * initRenderer(SDL_Window *window){
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    // Set draw color to black and clear the screen
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    // Set draw color to white
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    
    return renderer;
}

int main(void) {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        fprintf(stderr, "Error: %s\n", SDL_GetError());
        return 1;
    }

    SDL_Window *window = SDL_CreateWindow(
        "2D Line Example",
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        640, 480,
        SDL_WINDOW_SHOWN
    );

    SDL_Renderer *renderer = initRenderer(window);

    // Draw a simple 2D line
    SDL_RenderDrawLine(renderer, 100, 100, 500, 400);

    // Present to the screen
    SDL_RenderPresent(renderer);

    // Wait a bit so we can see the result
    SDL_Delay(3000); // 3 seconds

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
