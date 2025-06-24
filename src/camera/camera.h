#ifndef CAMERA_H
#define CAMERA_H

#include "../definitions.h"

typedef struct camera{
    float3 position;
    int zfar;
    int znear;
}camera;

camera *createCamera(void);

#endif
