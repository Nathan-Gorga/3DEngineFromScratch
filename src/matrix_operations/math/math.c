#include "../matrix_operations.h"


void multMatrixMatrix(const float m1[4][4], const float m2[4][4], float o[4][4]){
    
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            o[j][i] = 0;
            for(int k = 0; k < 4; k++){
                o[j][i] += m1[k][i] * m2[j][k];
            }
        }
    }
}

void multMatrixVector(const vec3 *i, vec3 *o,const float m[4][4])
{
    const float x = i->x;
    const float y = i->y;
    const float z = i->z;

    o->x = x * m[0][0] + y * m[1][0] + z * m[2][0] + m[3][0];
    o->y = x * m[0][1] + y * m[1][1] + z * m[2][1] + m[3][1];
    o->z = x * m[0][2] + y * m[1][2] + z * m[2][2] + m[3][2];

    const float w = x * m[0][3] + y * m[1][3] + z * m[2][3] + m[3][3];

    if (w != 0.0f)
    {
        o->x /= w; 
        o->y /= w; 
        o->z /= w;
    }
}

void multMatrixConstant(const float I[4][4], float O[4][4], const float c){

    for(int i = 0; i < 4; ++i){
        for(int j = 0; j < 4; ++j){
            O[i][j] = I[i][j] * c;
        }
    }
}

void scaleMesh(const vec3 vec, const mesh * I, mesh * O){

    const float x = vec.x;
    const float y = vec.y;
    const float z = vec.z;

    for(int i = 0; i < I->size; ++i){
        for(int j = 0; j < 3; ++j){
            O->tris[i].p[j].x = I->tris[i].p[j].x * x;
            O->tris[i].p[j].y = I->tris[i].p[j].y * y;
            O->tris[i].p[j].z = I->tris[i].p[j].z * z;
        }
    }
}

float degreesToRadians(float degrees){
    return degrees * 0.0174533f;
}

float radiansToDegrees(float radians){
    return radians * 57.2958f;
}


static inline void multTriangleMatrix(const triangle * I, triangle * O, const float M[4][4]){
    multMatrixVector(&I->p[0], &O->p[0], M);
    multMatrixVector(&I->p[1], &O->p[1], M);
    multMatrixVector(&I->p[2], &O->p[2], M);
}

void multMeshMatrix(const float M[4][4], const mesh * I, mesh * O){
    for(int i = 0; i < I->size; i++){
        multTriangleMatrix(&I->tris[i], &O->tris[i], M);
    }
}
