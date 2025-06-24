#include "draw.h"


static inline void drawVector(float3 p1, float3 p2, SDL_Renderer *renderer){

    SDL_RenderDrawLine(renderer, p1.x, p1.y, p2.x, p2.y);

}

static void drawTriangle(triangle * triangle, SDL_Renderer *renderer){

    drawVector(triangle->p[0], triangle->p[1], renderer);
    drawVector(triangle->p[1], triangle->p[2], renderer);
    drawVector(triangle->p[2], triangle->p[0], renderer);
}

void drawMesh(mesh *mesh, SDL_Renderer *renderer){
    for(int i = 0; i < mesh->size; i++){
        drawTriangle(&mesh->triangles[i], renderer);
    }
}
