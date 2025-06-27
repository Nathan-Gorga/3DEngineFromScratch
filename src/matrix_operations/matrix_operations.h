#ifndef MATRIX_OPERATIONS_H
#define MATRIX_OPERATIONS_H

#include "../global.h"
#include "../camera/camera.h"

//MATH
void multMatrixVector(vec3 * vec, const float M[4][4]);

void multMatrixConstant(float m[4][4], const float c);

void scaleMesh(const vec3 vec, mesh * mesh);


//PROJECTION
void createProjectionMatrix(const camera *cam, float M[4][4]);

void projectMesh(const float projectionMatrix[4][4], mesh * mesh);

//ROTATION

//TRANSLATION
void translateMesh(const vec3 vec, mesh * mesh);

#endif
