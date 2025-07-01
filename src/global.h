#ifndef GLOBAL_H
#define GLOBAL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>

#define WINDOW_WIDTH 1200
#define WINDOW_HEIGHT 1000

typedef struct vec3{
	float x, y, z;
}vec3;

typedef struct triangle{
	vec3 p[3];
}triangle ;

typedef struct mesh{
	int size;
	triangle * tris;
}mesh;


#endif
