#ifdef _WIN32
#include <GL/glut.h>
#elif __APPLE__
#include <GLUT/glut.h>
#elif __linux__
#include <GL/glut.h>
#endif

void display(void){
    // Clear all pixels with the specified clear color
    glClear(GL_COLOR_BUFFER_BIT);

    // draw the four points in four colors
    glBegin(GL_POINTS);
        glColor3f(0., 1., 0.); // green
        glVertex2f(10., 10.);
        glColor3f(1., 1., 0.); // yellow
        glVertex2f(10., 110.);
        glColor3f(0., 0., 1.); // blue
        glVertex2f(150., 110.);
        glColor3f(1., 1., 1.); // white
        glVertex2f(150., 10.);
    glEnd();

    // start flushing OpenGL calls to to display buffer
    glFlush();
}

void reshape(int w, int h){
    // on reshape and on startup, keep the viewport to be the entire size of the window
    // set the viewport to be 320 by 240, the initial size of the window
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    // keep our world coordinate system constant
    // Set the 2d clipping area
    gluOrtho2D(0., 160., 0., 120.);
}

void init(void){
    // Set the clear color to be read
    glClearColor(1., 0., 0., 1.);
    // set the point size to be 5.0 pixels
    glPointSize(5);
    
}

int main(int argc, char** argv){
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(320, 240);
    glutCreateWindow("My First OpenGL Window");
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMainLoop();
    return 0;
}

/*//Drawing funciton
void draw(void)
{
    //Background color
    glClearColor(1,0,0,1);
    glClear(GL_COLOR_BUFFER_BIT );

    //Draw order
    glutPostRedisplay();
    glFlush();
}

//Main program
int main(int argc, char **argv)
{


    glutInit(&argc, argv);
    
    //Simple buffer
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA );
    glutInitWindowPosition(100,100);
    glutInitWindowSize(800,400);
    glutCreateWindow("Red window");
    //Call to the drawing function
    glutDisplayFunc(draw);

    glutMainLoop();
    return 0;
}*/