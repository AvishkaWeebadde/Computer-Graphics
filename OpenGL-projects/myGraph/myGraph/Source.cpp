// f(x) = sin(2PI * x) graph with OpenGL.

#include <windows.h> // use proper includes for your system
#include <math.h>
#include <gl/Gl.h>
#include <gl/glut.h>

const int screenWidth = 640;
const int screenHeight = 480; 
GLdouble A, B, C, D; 


void drawPlot1() 
{
	// f(x) = sin(2PI * x)

	glBegin(GL_POINTS);
	for (GLdouble x = 0; x <= 4.0; x += 0.0005)
	{
		GLdouble func = sinf(2 * 3.14159 * x);
		// glVertex2d(x, func);
		// Scaling to fit to window
		glVertex2d((x * screenWidth / 4.0), ((1.0 + func) * screenHeight / 2.0));
	}
	glEnd();


}

void drawPlot2()
{
	// f(x) = x ^ 2

	glBegin(GL_POINTS);
	for (GLdouble x = -2; x <= 2.0; x += 0.005)
	{
		GLdouble func = x * x;
		glVertex2d(((x + 2.0) * (screenWidth / 4.0)) , (func * screenHeight / 4.0));
	}
	glEnd();

}

void myDisplay()
{
	glClearColor(1.0, 1.0, 1.0, 0.0); // background color is white
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0f, 0.0f, 0.0f); // drawing color is black
	glPointSize(2.0); // a 'dot' is 2 by 2 pixels
	drawPlot2();
	glFlush();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(screenWidth, screenHeight);
	glutInitWindowPosition(100, 150);
	glutCreateWindow("My graph");

	glMatrixMode(GL_PROJECTION); 
	glLoadIdentity();
	gluOrtho2D(0.0, (GLdouble)screenWidth, 0.0, (GLdouble)screenHeight);

	glutDisplayFunc(myDisplay);
	glutMainLoop();
	return 0;
}