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

void projectionMatrix(){
    
}






