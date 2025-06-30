#include "global.h"
#include "SDL_interface/SDL_interface.h"
#include "shapes/shapes.h"
#include "matrix_operations/matrix_operations.h"
#include "camera/camera.h"
#include "run/run.h"

int main(void){

    SDL_Renderer *renderer = initRenderer();
    if(renderer == NULL){
        return 1;
    }

    mesh * Cube = cube();

    mesh * DuplicateCube = cube();
    

    if(Cube == NULL || DuplicateCube == NULL){
        return 1;
    }

    camera * cam = initCamera();
    if(cam == NULL){
        printf("cam\n");
     
        return 1;
    }

    


    // createProjectionMatrix(cam, projectionMatrix);

    // multMeshMatrix(rotationMatrix, Cube, DuplicateCube);
    // memcpy(Cube, DuplicateCube->tris, Cube->size * sizeof(triangle));//FIXME : this is so ugly, pls fix
    // //offset into screen
    // translateMesh((vec3){0.0f, 0.0f, 1.0f}, Cube, DuplicateCube);
    // memcpy(Cube, DuplicateCube->tris, Cube->size * sizeof(triangle));//FIXME : this is so ugly, pls fix

    // //move mesh
    // translateMesh((vec3){-0.5f, -0.5f, 1.0f}, Cube, DuplicateCube);
    // memcpy(Cube, DuplicateCube->tris, Cube->size * sizeof(triangle));//FIXME : this is so ugly, pls fix


    // multMeshMatrix(projectionMatrix, Cube, DuplicateCube);
    // memcpy(Cube, DuplicateCube->tris, Cube->size * sizeof(triangle));//FIXME : this is so ugly, pls fix

    // multMatrixMatrix( rotationMatrix,projectionMatrix, matrix);

    // multMeshMatrix(matrix, Cube);    


    //scale into view
    // translateMesh((vec3){1.0f, 1.0f, 0.0f}, Cube, DuplicateCube);
    // memcpy(Cube, DuplicateCube->tris, Cube->size * sizeof(triangle));//FIXME : this is so ugly, pls fix

    // scaleMesh((vec3){500.0f, 500.0f, 500.0f}, Cube, DuplicateCube);
    // memcpy(Cube, DuplicateCube->tris, Cube->size * sizeof(triangle));//FIXME : this is so ugly, pls fix

    // // drawMesh(Cube, renderer);
    // // SDL_RenderPresent(renderer);
    // drawMesh(DuplicateCube, renderer);
    // SDL_RenderPresent(renderer);
    // SDL_Delay(1000);
    
    bool running = true;
    SDL_Event event;
    float time = 0.0f;

    while(running){

        while (SDL_PollEvent(&event)) {
            
            if (event.type == SDL_QUIT) {
                running = false;
            }
        }

        if(mainLoop(time, renderer, cam, Cube) == -1){
            return 1;
        }

        time += 0.5f;
        
        SDL_Delay(16); 

    }

    free(cam);

    
    //BUG : free(): invalid next size (fast) somewhere here
    free(DuplicateCube->tris);
    free(DuplicateCube);


    free(Cube->tris);
    free(Cube);

    return 0;
}



