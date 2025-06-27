#ifndef GLOBACL_H
#define GLOBACL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <SDL2/SDL.h>

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
