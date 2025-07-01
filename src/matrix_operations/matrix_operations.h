#ifndef MATRIX_OPERATIONS_H
#define MATRIX_OPERATIONS_H

#include "../global.h"
#include "../camera/camera.h"


//TODO : make a function that takes in all motion vectors and combines them in always the correct order


//MATH
void multMatrixMatrix(const float m1[4][4],const float m2[4][4], float o[4][4]);

void multMatrixVector(const vec3 *i, vec3 *o,const float m[4][4]);

void multMatrixConstant(const float I[4][4], float O[4][4], const float c);

void scaleMesh(const vec3 vec, const mesh * I, mesh * O);

float radiansToDegrees(float radians);

float degreesToRadians(float degrees);

void multMeshMatrix(const float M[4][4], const mesh * I, mesh * O);

//PROJECTION
void createProjectionMatrix(const camera *cam, float M[4][4]);

//ROTATION
void createRotationMatrix(const vec3 rotationVector, float M[4][4]);

//TRANSLATION
void translateMesh(const vec3 vec, const mesh * I, mesh * O);

vec3 normalize(const vec3 vec1, const vec3 vec2);

#endif
