#include "camera.h"

camera *createCamera(void){
    camera *temp = (camera*)malloc(sizeof(camera));

    temp->position.x = 0;
    temp->position.y = 0;
    temp->position.z = 0;
    
    temp->zfar = Z_FAR;
    temp->znear = Z_NEAR;

    temp->theta = 2 * M_PI / 3;
    return temp;
}


void multMatrixVector(float3 *vec, const double matrix[4][4]){

    const float3 *temp = vec;

    vec->x = matrix[0][0] * temp->x + matrix[1][0] * temp->y + matrix[2][0] * temp->z + matrix[3][0];
    vec->y = matrix[0][1] * temp->x + matrix[1][1] * temp->y + matrix[2][1] * temp->z + matrix[3][1];
    vec->z = matrix[0][2] * temp->x + matrix[1][2] * temp->y + matrix[2][2] * temp->z + matrix[3][2];

    float w = matrix[0][3] * temp->x + matrix[1][3] * temp->y + matrix[2][3] * temp->z + matrix[3][3];

    if(w != 0){
        vec->x /= w;
        vec->y /= w;
        vec->z /= w;
    }
}

void projectionMatrix(const camera *camera, double projectionMatrix[4][4]){
    
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            projectionMatrix[i][j] = 0;
        }
    }

    const double aspectRatio = ASPECT_RATIO;
    const double f = 1/(tan(camera->theta/2));// FIXME: change divide by 2to mutliply by 0.5

    projectionMatrix[0][0] = aspectRatio * f;
    projectionMatrix[1][1] = f;
    projectionMatrix[2][2] = (camera->zfar)/(camera->zfar - camera->znear);
    projectionMatrix[2][3] = (-camera->zfar * camera->znear)/(camera->zfar - camera->znear);
    projectionMatrix[3][2] = 1; 

}



void multTriangleAndMatrix(triangle * triangle, const double matrix[4][4]){
    for(int i = 0; i < 3; i++){
        multMatrixVector(&triangle->p[i], matrix);
    }
}


void multMeshAndMatrix(mesh * mesh, const double matrix[4][4]){
    for(int i = 0; i < mesh->size; i++){
        // mesh->triangles->p[0].z += Z_NEAR;
        // mesh->triangles->p[1].z += Z_NEAR;
        // mesh->triangles->p[2].z += Z_NEAR;

        multTriangleAndMatrix(&mesh->triangles[i], matrix);
    }
}





