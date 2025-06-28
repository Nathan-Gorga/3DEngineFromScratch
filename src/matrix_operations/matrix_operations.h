#ifndef MATRIX_OPERATIONS_H
#define MATRIX_OPERATIONS_H

#include "../global.h"
#include "../camera/camera.h"

//MATH
void multMatrixMatrix(float m1[4][4], float m2[4][4], float o[4][4]);

void multMatrixVector(vec3 * vec, const float M[4][4]);

void multMatrixConstant(float m[4][4], const float c);

void scaleMesh(const vec3 vec, mesh * mesh);

float radiansToDegrees(float radians);

float degreesToRadians(float degrees);

void multMeshMatrix(const float M[4][4], mesh * mesh);

//PROJECTION
void createProjectionMatrix(const camera *cam, float M[4][4]);

//ROTATION
void createRotationMatrix(const vec3 rotationVector, float M[4][4]);

//TRANSLATION
void translateMesh(const vec3 vec, mesh * mesh);

#endif
