#include "camera.h"

camera * initCamera(void){

    camera * temp = (camera*)malloc(sizeof(camera));

    if(temp == NULL) return NULL;

    temp->position = (vec3){0.0f, 0.0f, 0.0f};
    temp->rotation = (vec3){0.0f, 0.0f, 0.0f};
    temp->zfar = Z_FAR;
    temp->znear = Z_NEAR;
    temp->theta = 90.0f;

    return temp;
}


