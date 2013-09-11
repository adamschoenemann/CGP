#ifdef _WIN32
#include <GL/glut.h>
#elif __APPLE__
#include <GLUT/glut.h>
#elif __linux__
#include <GL/glut.h>
#endif

#include <math.h>

#define PI 3.1415926535898

void drawCircle(float x, float y, float r, int steps);

void drawPerson(void){
	glClear(GL_COLOR_BUFFER_BIT);

	// glLoadIdentity();

	glColor3f(1., 0.8, 1.);
	glBegin(GL_POLYGON);
		drawCircle(80., 85., 10., 100);
	glEnd();

	// Black eyes
	glBegin(GL_POINTS);
		glColor3f(0., 0., 0.);
		glVertex2f(77., 88.);
		glVertex2f(83., 88.);
	glEnd();

	// polygonal body
	glColor3f(0.8, 0., 0.9);
	glBegin(GL_POLYGON);
		glVertex2f(75., 75.);
		glVertex2f(85., 75.);
		glVertex2f(100., 30.);
		glVertex2f(60., 30.);
	glEnd();

	// rectangular legs
	glColor3f(1., 0.8, 0.1);
	glRectf(70., 5., 75., 30.);
	glRectf(85., 5., 90., 30);

	// lines for hands
	glBegin(GL_LINES);
		glVertex2f(74., 70.);
		glVertex2f(50., 50.);
	glEnd();
	glBegin(GL_LINES);
		glVertex2f(86., 70.);
		glVertex2f(110., 50.);
	glEnd();

	glFlush();
}

void displayCircle(void){

	const float CX = 80.;
	const float CY = 60.;
	const float R = 30;

	// glLoadIdentity();
	// Clear all pixels with the specified clear color
	glClear(GL_COLOR_BUFFER_BIT);
	glTranslatef(10, 10, 0);
	// draw the four points in four colors
	glBegin(GL_LINE_STRIP);
		glColor3f(0., 1., 0.);
		drawCircle(CX, CY, R, 100);
	glEnd();

	// start flushing OpenGL calls to to display buffer
	glFlush();
}

void drawCircle(float x, float y, float r, int steps){
	float t;
	for(int i = 0; i <= steps; i++){
		t = ((2 * PI)/(float)steps) * i;
		glVertex2f(x + r * cos(t), y + r * sin(t));
	}
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
	glMatrixMode(GL_MODELVIEW);
}

void draw(void){
	glClear(GL_COLOR_BUFFER_BIT);

	glColor3f(0., 1., 0.);
	
	glutWireCube(50);

	glutPostRedisplay();
	glFlush();
}

void init(void){
	// Set the clear color to be read
	glClearColor(1., 0., 0., 1.);
	// set the point size to be 5.0 pixels
	glPointSize(5);
	// Anti-aliasing
	glEnable(GL_LINE_SMOOTH);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glHint(GL_LINE_SMOOTH_HINT | GL_POLYGON_SMOOTH_HINT, GL_DONT_CARE);
}

int main(int argc, char** argv){
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(320, 240);
	glutCreateWindow("My First OpenGL Window");
	init();
	glutDisplayFunc(draw);
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