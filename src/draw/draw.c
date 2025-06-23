#include "draw.h"


void drawLine2D(vertex2D line, float2 offset, SDL_Renderer *renderer){
    // Draw a simple 2D line
    SDL_RenderDrawLine(renderer, line.p1.x + offset.x, line.p1.y + offset.y, line.p2.x + offset.x, line.p2.y + offset.y);
}




void drawShape2D(shape2D *shape,float2 offset,  SDL_Renderer *renderer){
    
    for(int i = 0; i < shape->size; i++){
        drawLine2D(shape->shape[i], offset,renderer);
    }
}


