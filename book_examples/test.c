#include <GL/glut.h>

void display (void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f (1.0, 1.0, 1.0);
    glLoadIdentity ();             /* clear the matrix */
    glTranslatef (0.0, 0.0, -3.0); /* viewing transformation */
    glScalef (1.0, 2.0, 1.0);      /* modeling transformation */
    glutWireCube(1.0);    /*  draw the cube */
    glFlush();
}

void myinit (void) 
{
    glShadeModel (GL_FLAT);
    glClearColor(0., 0., 0., 1.);
}

void myReshape(GLsizei w, GLsizei h)
{
    glMatrixMode (GL_PROJECTION);    /* prepare for and then */ 
    glLoadIdentity();               /* define the projection */
    glFrustum(-1.0, 1.0, -1.0, 1.0, /* transformation */
                   1.5, 20.0); 
    glMatrixMode(GL_MODELVIEW);  /* back to modelview matrix */
    glViewport(0, 0, w, h);      /* define the viewport */
}


int main(int argc, char** argv)
{
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutInitWindowSize(320, 240);
    glutCreateWindow("My First OpenGL Window");
    myinit();
    glutReshapeFunc(myReshape);
    glutDisplayFunc(display);
    glutMainLoop();
}