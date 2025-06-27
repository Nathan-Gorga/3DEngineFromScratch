#include "../matrix_operations.h"


void multMatixMatrix(float m1[4][4], float m2[4][4], float o[4][4]){
    
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            o[i][j] = 0;
            for(int k = 0; k < 4; k++){
                o[i][j] += m1[i][k] * m2[k][j];
            }
        }
    }
}

void multMatrixVector(vec3 *v,const float m[4][4])//TODO : add output argument instead of changing input
{

    const float x = v->x;
    const float y = v->y;
    const float z = v->z;

    v->x = x * m[0][0] + y * m[1][0] + z * m[2][0] + m[3][0];
    v->y = x * m[0][1] + y * m[1][1] + z * m[2][1] + m[3][1];
    v->z = x * m[0][2] + y * m[1][2] + z * m[2][2] + m[3][2];

    const float w = x * m[0][3] + y * m[1][3] + z * m[2][3] + m[3][3];

    if (w != 0.0f)
    {
        v->x /= w; 
        v->y /= w; 
        v->z /= w;
    }
}

void multMatrixConstant(float m[4][4], const float c){//TODO : add output argument instead of changing input
    for(int i = 0; i < 4; ++i){
        for(int j = 0; j < 4; ++j){
            m[i][j] *= c;
        }
    }
}

void scaleMesh(const vec3 vec, mesh * mesh){//TODO : add output argument instead of changing input

    const float x = vec.x;
    const float y = vec.y;
    const float z = vec.z;

    for(int i = 0; i < mesh->size; ++i){
        for(int j = 0; j < 3; ++j){
            mesh->tris[i].p[j].x *= x;
            mesh->tris[i].p[j].y *= y;
            mesh->tris[i].p[j].z *= z;
        }
    }
}

float degreesToRadians(float degrees){//TODO : add output argument instead of changing input
    return degrees * 0.0174533f;
}

float radiansToDegrees(float radians){//TODO : add output argument instead of changing input
    return radians * 57.2958f;
}


static inline void multTriangleMatrix(triangle * tri, const float M[4][4]){
    multMatrixVector(&tri->p[0], M);
    multMatrixVector(&tri->p[1], M);
    multMatrixVector(&tri->p[2], M);
}

void multMeshMatrix(const float M[4][4], mesh * mesh){
    for(int i = 0; i < mesh->size; i++){
        multTriangleMatrix(&mesh->tris[i], M);
    }
}
