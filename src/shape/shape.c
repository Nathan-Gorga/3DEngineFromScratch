#include "shape.h"
#define M_PI 3.14159265358979323846


shape2D * square(const int scale){
    
    shape2D *temp = (shape2D*)malloc(sizeof(shape2D));

    temp->shape = (vertex2D*)malloc(4 * sizeof(vertex2D));

    temp->size = 4;

    // bottom vertex
    temp->shape[0].p1.x = -scale;
    temp->shape[0].p1.y = -scale;
    temp->shape[0].p2.x = scale;
    temp->shape[0].p2.y = -scale;

    // right vertex
    temp->shape[1].p1.x = scale;
    temp->shape[1].p1.y = -scale;
    temp->shape[1].p2.x = scale;
    temp->shape[1].p2.y = scale;

    // top vertex
    temp->shape[2].p1.x = scale;
    temp->shape[2].p1.y = scale;
    temp->shape[2].p2.x = -scale;
    temp->shape[2].p2.y = scale;

    // left vertex
    temp->shape[3].p1.x = -scale;
    temp->shape[3].p1.y = scale;
    temp->shape[3].p2.x = -scale;
    temp->shape[3].p2.y = -scale;

    return temp;

}


shape2D * circle(const int scale){
    
    shape2D *temp = (shape2D*)malloc(sizeof(shape2D));
    
    temp->size = 32;
    temp->shape = (vertex2D*)malloc(temp->size * sizeof(vertex2D));

    const float theta = 2 * M_PI / temp->size;
    for (int i = 0; i < temp->size; i++) {
        temp->shape[i].p1.x = scale * cos(theta * i);
        temp->shape[i].p1.y = scale * sin(theta * i);
        temp->shape[i].p2.x = scale * cos(theta * (i + 1));
        temp->shape[i].p2.y = scale * sin(theta * (i + 1));
    }

    return temp;

}


