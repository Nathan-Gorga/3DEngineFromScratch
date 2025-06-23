#include "camera.h"

camera *createCamera(void){
    camera *temp = (camera*)malloc(sizeof(camera));
    temp->x = 0;
    temp->y = 0;
    temp->z = 0;
    return temp;
}






