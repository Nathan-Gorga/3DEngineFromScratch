#include "shape.h"


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
