#include "../matrix_operations.h"

void translateMesh(const vec3 vec, const mesh * I, mesh * O){
    const float x = vec.x;
    const float y = vec.y;
    const float z = vec.z;

    for(int i = 0; i < I->size; i++){
        for(int j = 0; j < 3; j++){
            O->tris[i].p[j].x = I->tris[i].p[j].x + x;
            O->tris[i].p[j].y = I->tris[i].p[j].y + y;
            O->tris[i].p[j].z = I->tris[i].p[j].z + z;
        }
    }
}



