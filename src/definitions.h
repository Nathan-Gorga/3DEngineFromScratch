#ifndef DEFINITIONS_H
#define DEFINITIONS_H

#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>


#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600
#define ASPECT_RATION (float)WINDOW_HEIGHT/WINDOW_WIDTH

#define M_PI 3.14159265358979323846


typedef struct float3{
    float x; 
    float y; 
    float z;
} float3;

typedef struct float2{
    float x; 
    float y;
}float2;



typedef struct line2D{
    float2 p1;
    float2 p2;
}line2D;

typedef struct line3D{
    float3 p1;
    float3 p2;
}line3D;



typedef struct shape2D{
    line2D *shape;
    int size;
}shape2D;

typedef struct shape3D{
    line3D *shape;
    int size;
}shape3D;



#endif
