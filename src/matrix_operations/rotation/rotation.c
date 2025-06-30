#include "../matrix_operations.h"


void createRotationMatrix(const vec3 rotationVector, float M[4][4]){
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            M[i][j] = 0;
        }
    }

    const float x = degreesToRadians(rotationVector.x);
    const float y = degreesToRadians(rotationVector.y);
    const float z = degreesToRadians(rotationVector.z);

    float X[4][4] = {0};
    float Y[4][4] = {0};
    float Z[4][4] = {0};

    if(x != 0.0f){
        
        const float cosX = cos(x);
        const float sinX = sin(x);
        X[0][0] = 1;
        X[1][1] = cosX;
        X[2][2] = cosX;
        X[3][3] = 1;
        X[1][2] = -sinX;//TODO : make a note to never mistake row and column
        X[2][1] = sinX;


    } else {
        for(int i = 0; i < 4; i++){
            X[i][i] = 1;
        }
    }



    if(y != 0.0f){
        
        const float cosY = cos(y);
        const float sinY = sin(y);

        Y[0][0] = cosY;
        Y[1][1] = 1;
        Y[2][2] = cosY;
        Y[3][3] = 1;
        Y[0][2] = sinY;
        Y[2][0] = -sinY;

    } else {
        for(int i = 0; i < 4; i++){
            Y[i][i] = 1;
        }  
    }


    if(z != 0.0f){

        const float cosZ = cos(z);
        const float sinZ = sin(z);
        Z[0][0] = cosZ;
        Z[1][1] = cosZ;
        Z[2][2] = 1;
        Z[3][3] = 1;
        Z[0][1] = -sinZ;
        Z[1][0] = sinZ;
        
    } else {
        for(int i = 0; i < 4; i++){
            Z[i][i] = 1;
        }
    }

    // the order of multiplication MUST be Z * Y * X

    float temp[4][4] = {0};

    multMatrixMatrix(Z, Y, temp);
    
    multMatrixMatrix(temp, X, M);
}


