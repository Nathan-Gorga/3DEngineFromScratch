#ifndef SDL_INTERFACE_H
#define SDL_INTERFACE_H

#include "../global.h"

//INIT
SDL_Renderer * initRenderer(void);

//DRAW
void drawMesh(mesh * mesh, SDL_Renderer *renderer);


#endif
