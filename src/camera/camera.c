#include "camera.h"

camera *createCamera(void){
    camera *temp = (camera*)malloc(sizeof(camera));

    temp->position.x = 0;
    temp->position.y = 0;
    temp->position.z = 0;
    
    temp->zfar = 100;
    temp->znear = 1;

    temp->theta = 2 * M_PI / 3;
    return temp;
}


void multMatrixVector(const float3 *input, float3 *output, const double matrix[4][4]){
    output->x = matrix[0][0] * input->x + matrix[1][0] * input->y + matrix[2][0] * input->z + matrix[3][0];
    output->y = matrix[0][1] * input->x + matrix[1][1] * input->y + matrix[2][1] * input->z + matrix[3][1];
    output->z = matrix[0][2] * input->x + matrix[1][2] * input->y + matrix[2][2] * input->z + matrix[3][2];

    float w = matrix[0][3] * input->x + matrix[1][3] * input->y + matrix[2][3] * input->z + matrix[3][3];

    if(w != 0){
        output->x /= w;
        output->y /= w;
        output->z /= w;
    }
}

void projectionMatrix(camera *camera, double projectionMatrix[4][4]){
    
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            projectionMatrix[i][j] = 0;
        }
    }

    const double aspectRatio = ASPECT_RATIO;
    const double f = 1/(tan(camera->theta/2));

    projectionMatrix[0][0] = aspectRatio * f;
    projectionMatrix[1][1] = f;
    projectionMatrix[2][2] = (camera->zfar)/(camera->zfar - camera->znear);
    projectionMatrix[2][3] = (-camera->zfar * camera->znear)/(camera->zfar - camera->znear);
    projectionMatrix[3][2] = 1; 

}






