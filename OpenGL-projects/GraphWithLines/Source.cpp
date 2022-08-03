#include <Windows.h>
#include <gl/Gl.h>
#include <gl/glut.h>
using namespace std;

#include<math.h>

int screenHeight = 480;
int screenwidth = 640;

GLdouble A, B, C, D;
const GLdouble pi = 3.14159;

void drawLines()
{
	glLineWidth(4.0);
	glBegin(GL_LINE_STRIP);
	glVertex2f(50.0, 100.0);
	glVertex2f(400.0, 200.0);
	glVertex2f(280.0, 400.0);
	glEnd();

}

void drawGraph() 
{
	// f(x) = 300 - 100 cos(2π x/100) + 30 cos(4π x/100) + 6 cos(6π x/100)
	glLineWidth(2.0);
	glBegin(GL_LINE_STRIP);
	for (GLdouble x = 0; x <= 300; x += 0.005)
	{
		GLdouble func = 300 - (100 * cos((2 * pi * x) / 100)) + (30 * cos((4 * pi * x) / 100)) + (6 * cos((6 * pi * x) / 100)) - 225.028;
		glVertex2d((x + 12.788) * (screenwidth / 300), func * (screenHeight / 198.972));
	}
	glEnd();
	glFlush;

}

void myDisplay()
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0, 0.0, 0.0);
	drawGraph(); // drawFunction
	glFlush();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(screenwidth, screenHeight);
	glutInitWindowPosition(100, 150);
	glutCreateWindow("lines Test");

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, screenwidth, 0, screenHeight);

	glutDisplayFunc(myDisplay);
	glutMainLoop();

}