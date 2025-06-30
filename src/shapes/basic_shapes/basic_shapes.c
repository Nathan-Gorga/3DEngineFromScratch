#include "../shapes.h"

mesh * cube(void){

    mesh * meshCube = initMesh(12);

    if(meshCube == NULL) return NULL;

    triangle temp[12] = {
        
        // SOUTH
        { (vec3){0.0f, 0.0f, 0.0f},    (vec3){0.0f, 1.0f, 0.0f},    (vec3){1.0f, 1.0f, 0.0f} },
        { (vec3){0.0f, 0.0f, 0.0f},    (vec3){1.0f, 1.0f, 0.0f},    (vec3){1.0f, 0.0f, 0.0f} },

        // EAST                                                      
        { (vec3){1.0f, 0.0f, 0.0f},    (vec3){1.0f, 1.0f, 0.0f},    (vec3){1.0f, 1.0f, 1.0f} },
        { (vec3){1.0f, 0.0f, 0.0f},    (vec3){1.0f, 1.0f, 1.0f},    (vec3){1.0f, 0.0f, 1.0f} },

        // NORTH                                                     
        { (vec3){1.0f, 0.0f, 1.0f},    (vec3){1.0f, 1.0f, 1.0f},    (vec3){0.0f, 1.0f, 1.0f} },
        { (vec3){1.0f, 0.0f, 1.0f},    (vec3){0.0f, 1.0f, 1.0f},    (vec3){0.0f, 0.0f, 1.0f} },

        // WEST                                                      
        { (vec3){0.0f, 0.0f, 1.0f},    (vec3){0.0f, 1.0f, 1.0f},    (vec3){0.0f, 1.0f, 0.0f} },
        { (vec3){0.0f, 0.0f, 1.0f},    (vec3){0.0f, 1.0f, 0.0f},    (vec3){0.0f, 0.0f, 0.0f} },

        // TOP                                                       
        { (vec3){0.0f, 1.0f, 0.0f},    (vec3){0.0f, 1.0f, 1.0f},    (vec3){1.0f, 1.0f, 1.0f} },
        { (vec3){0.0f, 1.0f, 0.0f},    (vec3){1.0f, 1.0f, 1.0f},    (vec3){1.0f, 1.0f, 0.0f} },

        // BOTTOM                                                    
        { (vec3){1.0f, 0.0f, 1.0f},    (vec3){0.0f, 0.0f, 1.0f},    (vec3){0.0f, 0.0f, 0.0f} },
        { (vec3){1.0f, 0.0f, 1.0f},    (vec3){0.0f, 0.0f, 0.0f},    (vec3){1.0f, 0.0f, 0.0f} },

    };

    memcpy(meshCube->tris, temp, sizeof(triangle) * 12);

    return meshCube;
}


mesh * tetrahedron(void){

    mesh * meshTetrahedron = initMesh(4);

    if(meshTetrahedron == NULL) return NULL;

    triangle temp[4] = {
        { (vec3){0.0f, 0.0f, 0.0f},    (vec3){1.0f, 0.0f, 0.0f},    (vec3){0.5f, 0.0f, 1.0f} },
        
        { (vec3){0.0f, 0.0f, 0.0f},    (vec3){0.5f, 1.0f, 0.5f},    (vec3){1.0f, 0.0f, 0.0f} },
        
        { (vec3){1.0f, 0.0f, 0.0f},    (vec3){0.5f, 1.0f, 0.5f},    (vec3){0.5f, 0.0f, 1.0f} },

        { (vec3){0.5f, 0.0f, 1.0f},    (vec3){0.5f, 1.0f, 0.5f},    (vec3){0.0f, 0.0f, 0.0f} },        
    };

    memcpy(meshTetrahedron->tris, temp, sizeof(triangle) * 4);

    return meshTetrahedron;
}

