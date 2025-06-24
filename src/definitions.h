#ifndef DEFINITIONS_H
#define DEFINITIONS_H

#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>


#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600
#define ASPECT_RATIO (float)WINDOW_HEIGHT/WINDOW_WIDTH

#define M_PI 3.14159265358979323846


typedef struct float3{
    float x; 
    float y; 
    float z;
} float3;

typedef struct triangle{
    float3 p[3];
}triangle;

typedef struct mesh{
    triangle *triangles;
    int size;
}mesh;



#endif
