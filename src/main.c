#include "definitions.h"
#include "renderer/renderer.h"
#include "draw/draw.h"



void drawSquare(const int scale, SDL_Renderer *renderer){
    const int p = scale/2;
    line2D square[4] = {
        {{-p,-p},{-p,p}},
        {{-p,p},{p,p}},
        {{p,p},{p,-p}},
        {{p,-p},{-p,-p}},
    };

    drawShape2D(square, 4, renderer);
}




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

  
    drawSquare(50, renderer);
    
    // Present to the screen
    SDL_RenderPresent(renderer);


    bool running = true;
    SDL_Event event;
    while (running) {
        // Poll for events
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
            }
        }


        // Optionally add a small delay to limit CPU usage
        SDL_Delay(16); // ~60 FPS
    }


    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
