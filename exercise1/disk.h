#ifndef _DISK_H_
#define _DISK_H_

#include <math.h>
#include <GL/glut.h>
#include <stdlib.h>

#define PI 3.14159265358979323846

GLuint cylinder_nVerts(GLuint resolution);
GLuint disk_nVerts(GLuint resolution);

typedef struct {

    GLfloat* verts;
    GLubyte* indices;
    GLfloat r;
    GLfloat y;
    GLuint res;    

} Disk;


// Disk newDisk(float y, float r, usigned int resolution){

    
// }

// Maybe increment i all the way to keep count
// and return it as the size
GLuint diskVerts(GLfloat y, GLfloat radius, GLuint resolution, GLfloat* verts, GLuint offset) { 
    GLuint i;
    GLdouble x, z, angle;
    // offset = 0;
    for(i = offset; i < resolution + offset; i++){
        x = z = angle = 0.0f;
        angle = ((2 * PI) / (GLdouble) resolution) * (i-offset);
        x = cos(angle) * radius;
        z = sin(angle) * radius;
        verts[(i*3)+0] = x;
        verts[(i*3)+1] = y;
        verts[(i*3)+2] = z;
    }
    GLuint centerVertIndex = i*3;
    verts[centerVertIndex + 0] = 0; // x
    verts[centerVertIndex + 1] = y; // y
    verts[centerVertIndex + 2] = 0; // z
    return ++i;
}

void diskIndices(GLuint resolution, GLubyte* indices, size_t offset){
    GLuint centerPoint = resolution + 1;
    // Connect a disk
    for(int i = 0; i < resolution; i++){
        GLuint index = i * 3;
        indices[index + 0] = i;
        indices[index + 1] = centerPoint;
        indices[index + 2] = i+1;
    }
}

int cylinderVerts(GLuint resolution, GLfloat radius, GLfloat height, GLfloat* verts){
    size_t size = cylinder_nVerts(resolution) * 3;
    int n = diskVerts(0, radius, resolution, verts, 0);
    n = diskVerts(height, radius, resolution, verts, n);
    return n;
}

// WRONG
GLuint disk_nVerts(const GLuint resolution){
    return resolution + 1;
}

GLuint disk_nIndices(GLuint resolution){
    return resolution * 3;
}

// WRONG
GLuint cylinder_nVerts(const GLuint resolution) {
    return disk_nVerts(resolution) * 2;
}

GLuint cylinder_nIndices(GLuint resolution){
    return disk_nIndices(resolution) * 2 + resolution * 3 * 2;
}

int cylinderIndices(GLuint resolution, GLubyte* indices){
    // size_t nIndices = disk_nIndices(resolution) * 2;
    // GLubyte* indices = (GLubyte*) malloc(sizeof(GLubyte) * nIndices);

    GLuint nDiskIndices = disk_nIndices(resolution);

    diskIndices(resolution, indices, 0);
    // diskIndices(resolution, indices, nDiskIndices);

    // for(int i = nDiskIndices*2; i < nIndices; i += 6){
    //     GLuint A = i - nDiskIndices*2;
    //     GLuint B = i - nDiskIndices;
    //     GLuint C = i - nDiskIndices + 1;
    //     GLuint D = i - nDiskIndices*2 + 1;

    //     indices[i+0] = A;
    //     indices[i+1] = B;
    //     indices[i+2] = C;

    //     indices[i+3] = A;
    //     indices[i+4] = C;
    //     indices[i+5] = D;

    // }
    return 0;
}

#endif