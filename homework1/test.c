#include <GL/glut.h>

void draw(void){
	glClear(GL_COLOR_BUFFER_BIT);

	glColor3f(0., 1., 0.);
	glBegin(GL_LINES);
		glVertex3f(0, 0, 0);
		glVertex3f(1, 1, 0);
	glEnd();

	glPushMatrix();
	glTranslated(0, 0, -5);
	glutWireCube(1);
	glPopMatrix();

	glutPostRedisplay();
	glFlush();
}

void keyboard(unsigned char key, int x, int y) {
	switch(key) {
		case 27:
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


void reshape(int w, int h){
	// on reshape and on startup, keep the viewport to be the entire size of the window
	// set the viewport to be 320 by 240, the initial size of the window
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	// keep our world coordinate system constant
	// Set the 2d clipping area
	// gluOrtho2D(0., 160., 0., 120.);
	gluPerspective(45, (float)w/(float)h,1.5,10);
	glMatrixMode(GL_MODELVIEW);
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
	glutKeyboardFunc(keyboard);
	glutMainLoop();
	return 0;
}