#include "../SDL_interface.h"

static inline void drawLine(const float x1, const float y1, const float x2, const float y2, SDL_Renderer *renderer){
    SDL_RenderDrawLine(renderer, x1, y1, x2, y2);
}


static void drawTriangle(const triangle * tri, SDL_Renderer *renderer){
    drawLine(tri->p[0].x, tri->p[0].y, tri->p[1].x, tri->p[1].y, renderer); 
    drawLine(tri->p[1].x, tri->p[1].y, tri->p[2].x, tri->p[2].y, renderer);
    drawLine(tri->p[2].x, tri->p[2].y, tri->p[0].x, tri->p[0].y, renderer);
}

void drawMesh(mesh * mesh, SDL_Renderer *renderer){

    for (int i = 0; i < mesh->size; i++){
    
        drawTriangle(&mesh->tris[i], renderer);
        
    }

}

