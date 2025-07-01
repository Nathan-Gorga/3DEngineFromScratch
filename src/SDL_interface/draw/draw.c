#include "../SDL_interface.h"

static inline void drawLine(const float x1, const float y1, const float x2, const float y2, SDL_Renderer *renderer){
    SDL_RenderDrawLine(renderer, x1, y1, x2, y2);
}


static void drawTriangle(const triangle * tri, SDL_Renderer *renderer){
    drawLine(tri->p[0].x, tri->p[0].y, tri->p[1].x, tri->p[1].y, renderer); 
    drawLine(tri->p[1].x, tri->p[1].y, tri->p[2].x, tri->p[2].y, renderer);
    drawLine(tri->p[2].x, tri->p[2].y, tri->p[0].x, tri->p[0].y, renderer);
}

void drawMesh(mesh * mesh, SDL_Renderer *renderer){

    vec3 normal, line1, line2;
    
    for (int i = 0; i < mesh->size; i++){
    
        triangle tri = mesh->tris[i];

        line1.x = tri.p[1].x - tri.p[0].x;
        line1.y = tri.p[1].y - tri.p[0].y;
        line1.z = tri.p[1].z - tri.p[0].z;
    
        line2.x = tri.p[2].x - tri.p[0].x;
        line2.y = tri.p[2].y - tri.p[0].y;
        line2.z = tri.p[2].z - tri.p[0].z;
    
        normal = normalize(line1, line2);
        
        if(normal.z < 0.0f)
            drawTriangle(&mesh->tris[i], renderer);
        
    }

}

