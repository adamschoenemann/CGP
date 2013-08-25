#ifdef _WIN32
#include <GL/glut.h>
#elif __APPLE__
#include <GLUT/glut.h>
#elif __linux__
#include <GL/glut.h>
#endif

GLfloat vertices[] = {-1,-1,-1, -1,1,-1, 1,1,-1, 1,-1,-1, // 8 of vertex coords
    -1,-1,1,  -1,1,1,  1,1,1,  1,-1,1};

GLubyte indices[] = {0,1,2, 2,3,0,   // 36 of indices
    0,3,4, 4,5,0,
    0,5,6, 6,1,0,
    1,6,7, 7,2,1,
    7,4,3, 3,2,7,
    4,7,6, 6,5,4};

void draw(){
    //Clear the screen black
    glClearColor(0, 0, 0, 0);
    glClear(GL_COLOR_BUFFER_BIT);
    
    // Save the current stack state
    glPushMatrix();
    
    // Translate the object forward, so it can be seen by the camera
    glTranslatef(0, 0, -10);
    
    // Draw the cube defined in the data structure
    glColor3f(1, 1, 1);
    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(3, GL_FLOAT, 0, vertices);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_BYTE, indices);
    glDisableClientState(GL_VERTEX_ARRAY);
    
    // Restore the previous stack
    glPopMatrix();

    // Draw the backbuffer on the screen
    glutSwapBuffers();


}

void reshape (int w, int h){
    glViewport(0,0,w ,h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45, (float)w/(float)h, 1.5, 20);
    glMatrixMode(GL_MODELVIEW);
}


int main(int argc, char * argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA );
    glutInitWindowPosition(100,100);
    glutInitWindowSize(800,450);
    glutCreateWindow("Lesson 2");
    
    glutDisplayFunc(draw);
    // glutReshapeFunc(reshape);
    glutMainLoop();
}
