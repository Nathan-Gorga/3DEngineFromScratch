#ifndef CAMERA_H
#define CAMERA_H

#include "../global.h"

#define Z_NEAR 0.1f
#define Z_FAR 1000.0f


typedef struct camera{
    vec3 position;
    vec3 rotation;
    float zfar;
    float znear;
    float theta;
}camera;


camera * initCamera(void);


#endif
