#include "draw.h"


static inline void drawVector(const float3 p1, const float3 p2,SDL_Renderer *renderer){

    SDL_RenderDrawLine(renderer, p1.x + OFFSET_X, p1.y + OFFSET_Y, p2.x + OFFSET_X, p2.y + OFFSET_Y); 

}

static void drawTriangle(const triangle * triangle, SDL_Renderer *renderer){

    drawVector(triangle->p[0], triangle->p[1], renderer);
    drawVector(triangle->p[1], triangle->p[2], renderer);
    drawVector(triangle->p[2], triangle->p[0], renderer);
}

void drawMesh( const mesh *mesh, SDL_Renderer *renderer){
    for(int i = 0; i < mesh->size; i++){
        drawTriangle(&mesh->triangles[i], renderer);
    }
}
