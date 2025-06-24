#ifndef CAMERA_H
#define CAMERA_H

#include "../definitions.h"
#define Z_NEAR 1
#define Z_FAR 100


typedef struct camera{
    float3 position;
    int zfar;
    int znear;
    float theta;
}camera;

camera *createCamera(void);

void projectionMatrix(const camera *camera, double projectionMatrix[4][4]);

void multMatrixVector(float3 *vec, const double matrix[4][4]);

void multMeshAndMatrix(mesh * mesh, const double matrix[4][4]);


#endif
