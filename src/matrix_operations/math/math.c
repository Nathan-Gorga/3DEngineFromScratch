#include "../matrix_operations.h"

void multMatrixVector(vec3 *v,const float m[4][4])
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

void multMatrixConstant(float m[4][4], const float c){
    for(int i = 0; i < 4; ++i){
        for(int j = 0; j < 4; ++j){
            m[i][j] *= c;
        }
    }
}

void scaleMesh(const vec3 vec, mesh * mesh){

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




