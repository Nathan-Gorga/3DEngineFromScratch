#include "run.h"


int mainLoop(const float elapsed_time, SDL_Renderer * renderer, const camera * cam, const mesh * input_mesh){
    
    //CLEAR SCREEN
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); 
    
    SDL_RenderClear(renderer);
    
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); 


    //INIT MATRICES
    float rotationMatrix[4][4];
    float projectionMatrix[4][4];

    //CREATE ROTATION MATRIX ZX
    createRotationMatrix((vec3){elapsed_time * 0.5f, elapsed_time * 1.5f, elapsed_time}, rotationMatrix);

    mesh * rotatedMesh = initMesh(input_mesh->size);

    //MULT MESH WITH ROTATION MATRIX 
    multMeshMatrix(rotationMatrix,input_mesh, rotatedMesh);

    //OFFSET INTO SCREEN
    mesh * offsetMesh = initMesh(input_mesh->size);

    translateMesh((vec3){4.0f, 3.0f, 5.0f}, rotatedMesh, offsetMesh);
    
    freeMesh(rotatedMesh);

    //NORMALIZE TRIANGLES

            
        //PROJECT MESH
        createProjectionMatrix(cam, projectionMatrix);

        mesh * projectedMesh = initMesh(input_mesh->size);

        multMeshMatrix(projectionMatrix, offsetMesh, projectedMesh);
        
        freeMesh(offsetMesh);
        
        //SCALE INTO VIEW
        
        mesh * scaledMesh = initMesh(input_mesh->size);
        
        scaleMesh((vec3){300.0f, 300.0f, 300.0f}, projectedMesh, scaledMesh);
        
        freeMesh(projectedMesh);
        
        
        //DRAW TRIANGLES
        
        drawFilledMesh(scaledMesh, renderer);
        SDL_RenderPresent(renderer);
        
        freeMesh(scaledMesh);
    
    return 0;
}



