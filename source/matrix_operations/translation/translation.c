#include "../matrix_operations.h"

void translateMesh(const vec3 vec, mesh * mesh){
    const float x = vec.x;
    const float y = vec.y;
    const float z = vec.z;

    for(int i = 0; i < mesh->size; i++){
        for(int j = 0; j < 3; j++){
            mesh->tris[i].p[j].x += x;
            mesh->tris[i].p[j].y += y;
            mesh->tris[i].p[j].z += z;
        }
    }
}



