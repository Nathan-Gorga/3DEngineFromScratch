#include "3DEngine.h"

int main(void){

    SDL_Renderer *renderer = initRenderer();

    if(renderer == NULL) return 1;

    mesh * Cube = cube();    

    if(Cube == NULL) return 1;

    camera * cam = initCamera();

    if(cam == NULL) return 1;
    
    bool running = true;
    SDL_Event event;
    float time = 0.0f;

    while(running){

        while (SDL_PollEvent(&event)) {
            
            if (event.type == SDL_QUIT) {
                running = false;
            }
        }

        if(mainLoop(time++, renderer, cam, Cube) == -1){
            return 1;
        }
        
        SDL_Delay(16); 
    }

    free(cam);
    freeMesh(Cube);

    return 0;
}



