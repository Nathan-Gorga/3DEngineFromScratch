#include "fundamental_op.h"

mesh * initMesh(const int size){
    mesh * temp = (mesh*)malloc(sizeof(mesh));

    if(temp == NULL) return NULL;
    
    temp->size = size;
    
    temp->tris = (triangle*)malloc(sizeof(triangle) * size);
    
    if(temp->tris == NULL) {
        free(temp);
        return NULL;
    }
    return temp;
}

void freeMesh(mesh * temp){
    free(temp->tris);
    free(temp);
}
