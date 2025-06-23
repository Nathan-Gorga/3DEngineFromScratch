#include "draw.h"


void drawLine2D(line2D line, float2 offset, SDL_Renderer *renderer){
    // Draw a simple 2D line
    SDL_RenderDrawLine(renderer, line.p1.x + offset.x, line.p1.y + offset.y, line.p2.x + offset.x, line.p2.y + offset.y);
}

void drawShape2D(line2D *shape,const int size, SDL_Renderer *renderer){
    float2 offset = {WINDOW_WIDTH/2, WINDOW_HEIGHT/2};
    for(int i = 0; i < size; i++){
        drawLine2D(shape[i], offset,renderer);
    }
}


