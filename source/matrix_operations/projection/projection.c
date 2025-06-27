#include "../matrix_operations.h"


void createProjectionMatrix(const camera * cam, float M[4][4]){

    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            M[i][j] = 0;
        }
    }

    const float fNear = cam->znear;
    const float fFar = cam->zfar;
    const float fFov = cam->theta; //degrees
    const float fAspectRatio = (float)WINDOW_HEIGHT / (float)WINDOW_WIDTH;
    const float fFovRad = 1.0f / tanf(fFov * 0.5f / 180.0f * 3.14159f);

    M[0][0] = fAspectRatio * fFovRad;
    M[1][1] = fFovRad;
    M[2][2] = (float)(fFar / (fFar - fNear));
    M[3][2] = (float)((-fFar * fNear) / (fFar - fNear));
    M[2][3] = 1.0f;
}


static inline void projectVector(vec3 * vec, const float projectionMatrix[4][4]){
    multMatrixVector(vec, projectionMatrix);
}

static void projectTriangle(triangle * tri, const float projectionMatrix[4][4]){
    projectVector(&tri->p[0], projectionMatrix);
    projectVector(&tri->p[1], projectionMatrix);
    projectVector(&tri->p[2], projectionMatrix);
}

void projectMesh(const float projectionMatrix[4][4], mesh * mesh){
    for(int i = 0; i < mesh->size; i++){
        projectTriangle(&mesh->tris[i], projectionMatrix);
    }
}


