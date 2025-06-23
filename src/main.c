#include "definitions.h"
#include "renderer/renderer.h"
#include "draw/draw.h"
#include "shape/shape.h"
#include "geometry/geometry.h"

int main(void) {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        fprintf(stderr, "Error: %s\n", SDL_GetError());
        return 1;
    }

    SDL_Window *window = SDL_CreateWindow(
        "Screen",
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        WINDOW_WIDTH, WINDOW_HEIGHT,
        SDL_WINDOW_SHOWN
    );

    SDL_Renderer *renderer = initRenderer(window);

    
    const int scale = 50;
    float2 point1 = {(WINDOW_WIDTH/2) - scale, (WINDOW_HEIGHT/2) - scale};
    float2 point2 = {(WINDOW_WIDTH/2) + scale, (WINDOW_HEIGHT/2) + scale};

    shape2D * Square = square(point1, point2);

    
    float2 offset = {0, 0};
    
    float angle = 2*M_PI/6;
    // drawShape2D(Square, offset,renderer);

    float2 origin = {WINDOW_WIDTH/2, WINDOW_HEIGHT/2};
    // rotate2D(Square, origin, angle);
    // drawShape2D(Square, offset,renderer);

    // SDL_RenderPresent(renderer);
        
    bool running = true;
    SDL_Event event;
    
    const float twoPi = 2 * M_PI;
    int divisor = 1;
    while (running) {
        // Poll for events
        while (SDL_PollEvent(&event)) {
            
            if (event.type == SDL_QUIT) {
                running = false;
            }
        }    
        const float angle = twoPi / divisor;

        rotate2D(Square, origin, angle);
        drawShape2D(Square, offset,renderer);
        SDL_RenderPresent(renderer);
        divisor++;
        // Optionally add a small delay to limit CPU usage
        SDL_Delay(1000); // ~60 FPS
    }
    
    free(Square->shape);
    free(Square);

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
