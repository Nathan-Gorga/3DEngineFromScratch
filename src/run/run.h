#ifndef RUN_H
#define RUN_H

#include "../global.h"
#include "../matrix_operations/matrix_operations.h"
#include "../SDL_interface/SDL_interface.h"
#include "../FUNDAMENTAL_OP/fundamental_op.h"


int mainLoop(const float elapsed_time,  SDL_Renderer * renderer, const camera * cam, const mesh * input_mesh);

#endif
