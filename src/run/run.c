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
    createRotationMatrix((vec3){elapsed_time * 0.5f, 0.0f, elapsed_time}, rotationMatrix);

    mesh * rotatedMesh = (mesh*)malloc(sizeof(mesh));

    if(rotatedMesh == NULL) return -1; 
    
    rotatedMesh->size = input_mesh->size;
    rotatedMesh->tris = (triangle*)malloc(sizeof(triangle) * rotatedMesh->size);

    //MULT MESH WITH ROTATION MATRIX 
    multMeshMatrix(rotationMatrix,input_mesh, rotatedMesh);

    //OFFSET INTO SCREEN
    mesh * offsetMesh = (mesh*)malloc(sizeof(mesh));

    if(offsetMesh == NULL) return -1; 
    
    offsetMesh->size = input_mesh->size;
    offsetMesh->tris = (triangle*)malloc(sizeof(triangle) * offsetMesh->size);

    translateMesh((vec3){4.0f, 3.0f, 4.0f}, rotatedMesh, offsetMesh);
    
    free(rotatedMesh->tris);
    free(rotatedMesh);

    //PROJECT MESH

    createProjectionMatrix(cam, projectionMatrix);

    mesh * projectedMesh = (mesh*)malloc(sizeof(mesh));

    if(projectedMesh == NULL) return -1; 
    
    projectedMesh->size = input_mesh->size;
    projectedMesh->tris = (triangle*)malloc(sizeof(triangle) * projectedMesh->size);

    multMeshMatrix(projectionMatrix, offsetMesh, projectedMesh);

    free(offsetMesh->tris);//TODO : create a free mesh function
    free(offsetMesh);

    //SCALE INTO VIEW

    mesh * scaledMesh = (mesh*)malloc(sizeof(mesh));

    if(scaledMesh == NULL) return -1; 
    
    scaledMesh->size = input_mesh->size;
    scaledMesh->tris = (triangle*)malloc(sizeof(triangle) * scaledMesh->size);

    scaleMesh((vec3){500.0f, 500.0f, 500.0f}, projectedMesh, scaledMesh);

    free(projectedMesh->tris);
    free(projectedMesh);


    //DRAW TRIANGLES

    drawMesh(scaledMesh, renderer);
    SDL_RenderPresent(renderer);

    free(scaledMesh->tris);
    free(scaledMesh);

    return 0;
}



