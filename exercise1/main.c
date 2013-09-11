#ifdef _WIN32
#include <GL/glut.h>
#elif __APPLE__
#include <GLUT/glut.h>
#elif __linux__
#include <GL/glut.h>
#endif

#include <math.h>
#include <stdlib.h>
#include "disk.h"
#include <stdio.h>


const GLubyte A = 0,
							B = 1,
							C = 2,
							D = 3,
							E = 4,
							F = 5,
							G = 6,
							H = 7;

GLfloat cubeVerts[] = {-1,-1,-1, -1,1,-1, 1,1,-1, 1,-1,-1, // 8 of vertex coords
    -1,-1,1,  -1,1,1,  1,1,1,  1,-1,1};


GLubyte cubeIndices[36] = 
{
	A, B, C,
	C, D, A,
	D, H, G,
	G, D, C,
	G, B, C,
	B, G, F,
	B, F, A,
	F, A, E,
	E, A, D,
	E, H, D,
	E, F, G,
	E, G, H
};

GLfloat prismVerts[] = 
{
	1,1,0,
	-1,-1,0,
	1,-1,0,
	-1,1,0,
	0,0,2,
	0,0,-2
};

GLubyte prismIndices[24] = 
{
	A,E,D,
	D,E,B,
	B,E,C,
	C,E,A,
	A,D,F,
	D,B,F,
	B,C,F,
	B,A,F
};



const GLuint res = 20;
const GLuint nDiskVerts = res + 1;
GLfloat radius = 2.0f;
GLfloat diskVertsArr[nDiskVerts*3];
GLubyte diskIndicesArr[nDiskVerts*3];
GLfloat cylinderVertsArr[nDiskVerts*2];
GLubyte cylinderIndicesArr[nDiskVerts*3*2];

GLfloat r = 180.0f;
void draw(){
    //Clear the screen black
    glClearColor(0, 0, 0, 0);
    glClear(GL_COLOR_BUFFER_BIT);
    
    //Save the current stack state
    glPushMatrix();
    
    //Translate the object forward, so it can be seen by the camera
    glTranslatef(0, 0, -10);
    glRotatef(r, 1, 1, 1);
    r += 0.005;
    //Draw the cube defined in the data structure
    glColor3f(1, 0, 0);

    if(cylinderVertsArr != NULL){
        glBegin(GL_POINTS);
            // This shouldn't be like this, should just be cylinder_nVerts()
            for(int i = 0; i < cylinder_nVerts(res); i++){
                size_t index = i * 3;
                glVertex3f(cylinderVertsArr[index],
                  cylinderVertsArr[index+1],
                  cylinderVertsArr[index+2]);
            }
        // glColor3f(0, 1, 0.);
        
        glEnd();
    }

    // glEnableClientState(GL_VERTEX_ARRAY);
    // glVertexPointer(3, GL_FLOAT, 0, cylinderVertsArr);
    // glDrawElements(GL_TRIANGLES, cylinder_nIndices(res), GL_UNSIGNED_BYTE, cylinderIndicesArr);
    // glDisableClientState(GL_VERTEX_ARRAY);
    
    //Restore the previous stack
    glPopMatrix();
    
    //Draw the backbuffer on the screen
    glutSwapBuffers();
    glutPostRedisplay();
    // glFlush();
}

void reshape (int w, int h){
    glViewport(0,0,w ,h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45, (float)w/(float)h, 1.5, 20);
    glMatrixMode(GL_MODELVIEW);
}

void keyboard(unsigned char key, int x, int y) {
    switch(key) {
        case 27: // ESC
            exit(0);
            break;
        case 'b':
            // call a function
            break;

        default:
            break;
    }
    glutPostRedisplay(); /* this redraws the scene without 
    waiting for the display callback so that any changes appear 
    instantly */
}


void init(void){
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glPointSize(5.f);

    diskVerts(0, radius, res, diskVertsArr, 0);
    diskIndices(res, diskIndicesArr, 0);

    unsigned int n = cylinderVerts(res, radius, 2.0, cylinderVertsArr);
    printf("Actual cylinder verts: %d\n", n);
    // cylinderVertsArr = malloc(sizeof(GLfloat) * cylinder_nVerts(res) * 3);
    // cylinderIndices(res, cylinderIndicesArr);

    for(int i = 0; i < disk_nVerts(res)*3; i += 3){
        GLfloat x, y, z;
        x = diskVertsArr[i+0];
        y = diskVertsArr[i+1];
        z = diskVertsArr[i+2];
        printf("[%f, %f, %f]\n", x, y, z);
    }
}

int main(int argc, char * argv[])
{
    printf("disc_nVerts for res %i: %i\n", res, disk_nVerts(res));
    printf("cylinder_nVerts for res %i: %i\n", res, cylinder_nVerts(res));
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA );
    glutInitWindowPosition(100,100);
    glutInitWindowSize(800,450);
    glutCreateWindow("Lesson 2");
  	init();
    glutDisplayFunc(draw);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
}
