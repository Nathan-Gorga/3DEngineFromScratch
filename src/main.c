#include "definitions.h"
#include "renderer/renderer.h"
#include "draw/draw.h"
#include "shape/shape.h"
#include "geometry/geometry.h"
#include "camera/camera.h"


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
  


    camera * cam = createCamera();

    double matrix[4][4];

    projectionMatrix(cam, matrix);
    mesh * cube = unitCube();


    // multMeshAndMatrix(cube, matrix);


    drawMesh(cube, renderer);
    
    SDL_RenderPresent(renderer);
    
    free(cube->triangles);
    free(cube);

    free(cam);

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
