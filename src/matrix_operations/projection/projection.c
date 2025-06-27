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





