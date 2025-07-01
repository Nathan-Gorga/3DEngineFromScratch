#ifndef SDL_INTERFACE_H
#define SDL_INTERFACE_H

#include "../global.h"
#include "../matrix_operations/matrix_operations.h"
//INIT
SDL_Renderer * initRenderer(void);

//DRAW
void drawWireMesh(mesh * mesh, SDL_Renderer *renderer);

void drawFilledMesh(mesh * mesh, SDL_Renderer * renderer);


#endif
