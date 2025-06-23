#include "geometry.h"


void rotateVector2D(vertex2D *vector,const float2 origin, const float angle){//angle in radians
    
    //step 1, translate the vector to the origin
    const float x1 = vector->p1.x - origin.x;
    const float y1 = vector->p1.y - origin.y;

    const float x2 = vector->p2.x - origin.x;
    const float y2 = vector->p2.y - origin.y;


    //step 2, rotate
    // x′ = xcos(θ)−ysin(θ)
    // y′= xsin(θ)+ycos(θ)
    float x1Temp = x1 * cos(angle) - y1 * sin(angle);
    float y1Temp = x1 * sin(angle) + y1 * cos(angle);

    float x2Temp = x2 * cos(angle) - y2 * sin(angle);
    float y2Temp = x2 * sin(angle) + y2 * cos(angle);

    //step 3, translate back to original position
    vector->p1.x = x1Temp + origin.x;
    vector->p1.y = y1Temp + origin.y;

    vector->p2.x = x2Temp + origin.x;
    vector->p2.y = y2Temp + origin.y;
}


void rotate2D(shape2D *shape, const float2 origin, const float angle){
    for(int i = 0; i < shape->size; i++){
        rotateVector2D(&shape->shape[i], origin, angle);
    }
}

