#include "shape.h"


shape2D * square(const float2 point1, const float2 point2){
    
    shape2D *temp = (shape2D*)malloc(sizeof(shape2D));

    temp->shape = (vertex2D*)malloc(4 * sizeof(vertex2D));

    temp->size = 4;

    
    // bottom vertex
    temp->shape[0].p1.x = point1.x;
    temp->shape[0].p1.y = point1.y;
    temp->shape[0].p2.x = point1.x;
    temp->shape[0].p2.y = point2.y;

    // right vertex
    temp->shape[1].p1.x = point1.x;
    temp->shape[1].p1.y = point2.y;
    temp->shape[1].p2.x = point2.x;
    temp->shape[1].p2.y = point2.y;

    // top vertex
    temp->shape[2].p1.x = point2.x;
    temp->shape[2].p1.y = point2.y;
    temp->shape[2].p2.x = point2.x;
    temp->shape[2].p2.y = point1.y;

    // left vertex
    temp->shape[3].p1.x = point2.x;
    temp->shape[3].p1.y = point1.y;
    temp->shape[3].p2.x = point1.x;
    temp->shape[3].p2.y = point1.y;

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


