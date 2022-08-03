// Fractsl with OpenGL

#include<Windows.h>
#include<gl/Gl.h>
#include<gl/glut.h>
#include<cmath>
#include<iostream>

class GLintPoint {
public:
	GLint x, y;
};

int random(int m){

	return rand() % m;
}

int index = random(3);
GLintPoint T[3] = { {100, 100}, {500, 30}, {400, 300} };
GLintPoint point = T[index];

void drawDot(GLint x, GLint y)
{
	glPointSize(4.0);
	glBegin(GL_POINTS);
	glVertex2i(x, y);
	glEnd();
}


void sierpinski() {
	 // initial point
	drawDot(point.x, point.y); // draw initial point
	for (int i = 0; i < 1000; i++) // draw 1000 dots
	{
		index = random(3);
		point.x = (point.x + T[index].x) / 2;
		point.y = (point.y + T[index].y) / 2;
		drawDot(point.x, point.y);
	}	
	//glFlush();

}

void myDisplay() {

	glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0f, 0.0f, 0.0f);
	sierpinski();
	glFlush();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Sierpinsky gasket stimulation");
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 640, 0, 480);


	glutDisplayFunc(myDisplay);
	glutMainLoop();
}