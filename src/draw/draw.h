#ifndef DRAW_H
#define DRAW_H

#include "../definitions.h"

#define OFFSET_X WINDOW_WIDTH/2
#define OFFSET_Y WINDOW_HEIGHT/2
#define Z_NEAR 1
#define Z_FAR 100

void drawMesh(const mesh *mesh, SDL_Renderer *renderer);


#endif



