#include "shape.h"


mesh *initMesh(const int size){
    mesh *temp = (mesh*)malloc(sizeof(mesh));
    temp->triangles = (triangle*)malloc(sizeof(triangle) * size);
    temp->size = size;
    return temp;
}


mesh* unitCube(void){
    const float scale = 100;

    mesh *temp = initMesh(12);

    //SOUTH FACE
    //triangle1
    temp->triangles[0].p[0].x = 0;
    temp->triangles[0].p[0].y = 0;
    temp->triangles[0].p[0].z = 0;

    temp->triangles[0].p[1].x = 0;
    temp->triangles[0].p[1].y = scale;
    temp->triangles[0].p[1].z = 0;

    temp->triangles[0].p[2].x = scale;
    temp->triangles[0].p[2].y = scale;
    temp->triangles[0].p[2].z = 0;


    //triangle2
    temp->triangles[1].p[0].x = 0;
    temp->triangles[1].p[0].y = 0;
    temp->triangles[1].p[0].z = 0;
    
    temp->triangles[1].p[1].x = scale;
    temp->triangles[1].p[1].y = scale;
    temp->triangles[1].p[1].z = 0;
    
    temp->triangles[1].p[2].x = scale;
    temp->triangles[1].p[2].y = 0;
    temp->triangles[1].p[2].z = 0;
    
    
    //EAST FACE

    //triangle 3
    temp->triangles[2].p[0].x = scale;
    temp->triangles[2].p[0].y = 0;
    temp->triangles[2].p[0].z = 0;

    temp->triangles[2].p[1].x = scale;
    temp->triangles[2].p[1].y = scale;
    temp->triangles[2].p[1].z = 0;

    temp->triangles[2].p[2].x = scale;
    temp->triangles[2].p[2].y = scale;
    temp->triangles[2].p[2].z = scale;


    //triangle 4
    temp->triangles[3].p[0].x = scale;
    temp->triangles[3].p[0].y = 0;
    temp->triangles[3].p[0].z = 0;

    temp->triangles[3].p[1].x = scale;
    temp->triangles[3].p[1].y = scale;
    temp->triangles[3].p[1].z = scale;

    temp->triangles[3].p[2].x = scale;
    temp->triangles[3].p[2].y = 0;
    temp->triangles[3].p[2].z = scale;
    
    //NORTH FACE
    //triangle 5
    temp->triangles[4].p[0].x = scale;
    temp->triangles[4].p[0].y = 0;
    temp->triangles[4].p[0].z = scale;
    
    temp->triangles[4].p[1].x = scale;
    temp->triangles[4].p[1].y = scale;
    temp->triangles[4].p[1].z = scale;

    temp->triangles[4].p[2].x = 0;
    temp->triangles[4].p[2].y = scale;
    temp->triangles[4].p[2].z = scale;


    //triangle 6
    temp->triangles[5].p[0].x = scale;
    temp->triangles[5].p[0].y = 0;
    temp->triangles[5].p[0].z = scale;
    
    temp->triangles[5].p[1].x = 0;
    temp->triangles[5].p[1].y = scale;
    temp->triangles[5].p[1].z = scale;
    
    temp->triangles[5].p[2].x = 0;
    temp->triangles[5].p[2].y = 0;
    temp->triangles[5].p[2].z = scale;
    
    
    
    //WEST FACE
    //triangle 7
    temp->triangles[6].p[0].x = 0;
    temp->triangles[6].p[0].y = 0;
    temp->triangles[6].p[0].z = scale;
    
    temp->triangles[6].p[1].x = 0;
    temp->triangles[6].p[1].y = scale;
    temp->triangles[6].p[1].z = scale;

    temp->triangles[6].p[2].z = 0;
    temp->triangles[6].p[2].x = scale;
    temp->triangles[6].p[2].y = 0;


    //triangle 8
    temp->triangles[7].p[0].x = 0;
    temp->triangles[7].p[0].y = 0;
    temp->triangles[7].p[0].z = scale;
    
    temp->triangles[7].p[1].z = 0;
    temp->triangles[7].p[1].x = scale;
    temp->triangles[7].p[1].y = 0;
    
    temp->triangles[7].p[2].x = 0;
    temp->triangles[7].p[2].y = 0;
    temp->triangles[7].p[2].z = 0;


    
    //BOTTOM FACE
    //triangle 9
    temp->triangles[8].p[0].x = 0;
    temp->triangles[8].p[0].y = 0;
    temp->triangles[8].p[0].z = scale;
    
    temp->triangles[8].p[1].z = 0;
    temp->triangles[8].p[1].x = 0;
    temp->triangles[8].p[1].y = 0;

    temp->triangles[8].p[2].x = scale;
    temp->triangles[8].p[2].y = 0;
    temp->triangles[8].p[2].z = 0;

    //triangle 10
    temp->triangles[9].p[0].x = 0;
    temp->triangles[9].p[0].y = 0;
    temp->triangles[9].p[0].z = scale;
    
    temp->triangles[9].p[1].x = scale;
    temp->triangles[9].p[1].y = 0;
    temp->triangles[9].p[1].z = 0;

    temp->triangles[9].p[2].z = scale;
    temp->triangles[9].p[2].x = 0;
    temp->triangles[9].p[2].y = scale;


    //TOP FACE
    //triangle 11
    temp->triangles[10].p[0].x = 0;
    temp->triangles[10].p[0].y = scale;
    temp->triangles[10].p[0].z = 0;
    
    temp->triangles[10].p[1].x = 0;
    temp->triangles[10].p[1].y = scale;
    temp->triangles[10].p[1].z = scale;

    temp->triangles[10].p[2].z = scale;
    temp->triangles[10].p[2].x = scale;
    temp->triangles[10].p[2].y = scale;

    //triangle 12
    temp->triangles[11].p[0].x = 0;
    temp->triangles[11].p[0].y = scale;
    temp->triangles[11].p[0].z = 0;
    
    temp->triangles[11].p[1].x = scale;
    temp->triangles[11].p[1].y = scale;
    temp->triangles[11].p[1].z = scale;

    temp->triangles[11].p[2].z = scale;
    temp->triangles[11].p[2].x = scale;
    temp->triangles[11].p[2].y = 0;

    return temp;
}


