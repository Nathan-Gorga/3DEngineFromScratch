#include "global.h"
#include "SDL_interface/SDL_interface.h"
#include "shapes/shapes.h"
#include "matrix_operations/matrix_operations.h"
#include "camera/camera.h"

int main(void){

    SDL_Renderer *renderer = initRenderer();
    if(renderer == NULL){
        return 1;
    }

    mesh * Cube = cube();
    if(Cube == NULL){
        return 1;
    }

    camera * cam = initCamera();
    if(cam == NULL){
        printf("cam\n");
     
        return 1;
    }

    float projectionMatrix[4][4];
    float rotationMatrix[4][4];
    createProjectionMatrix(cam, projectionMatrix);

    //offset into screen
    translateMesh((vec3){0, 0.0f, 3.0f}, Cube);


    multMeshMatrix(projectionMatrix, Cube);

    //scale into view
    translateMesh((vec3){1.0f, 1.0f, 0.0f}, Cube);
    scaleMesh((vec3){500.0f, 500.0f, 500.0f}, Cube);

    drawMesh(Cube, renderer);
    SDL_RenderPresent(renderer);

    
    bool running = true;
    SDL_Event event;


    while(running){

        while (SDL_PollEvent(&event)) {
            
            if (event.type == SDL_QUIT) {
                running = false;
            }
        }

        // SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // black background
        // SDL_RenderClear(renderer);

        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); // white shapes

        drawMesh(Cube, renderer);
        SDL_RenderPresent(renderer);
        SDL_Delay(16); 

    }

    free(cam);
    free(Cube->tris);
    free(Cube);

    return 0;
}



