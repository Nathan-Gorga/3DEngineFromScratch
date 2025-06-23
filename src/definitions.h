#ifndef DEFINITIONS_H
#define DEFINITIONS_H

#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdbool.h>


#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

typedef struct float3{
    float x; 
    float y; 
    float z;
} float3;

typedef struct float2{
    float x; 
    float y;
}float2;

typedef struct vertex2D{
    float2 p1;
    float2 p2;
}vertex2D;

typedef struct vertex3D{
    float3 p1;
    float3 p2;
}vertex3D;

typedef struct shape2D{
    vertex2D *shape;
    int size;
}shape2D;

typedef struct shape3D{
    vertex3D *shape;
    int size;
}shape3D;


#endif
