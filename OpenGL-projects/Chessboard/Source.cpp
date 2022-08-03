// Chessbiard illustration with OpenGL

#include <Windows.h>
#include <gl/Gl.h>
#include <gl/glut.h>

using namespace std;

int screenHeight = 600;
int screenwidth = 800;
bool white = 0;

int random(int n)
{
	return (10 + rand() % n);
}

void drawSquare(GLint x1, GLint y1, GLint x2, GLint y2)
{
	if (white == 0)
	{
		glColor3f(0.0, 0.0, 0.0);
		white = 1;
	}
	else
	{
		glColor3f(1.0, 1.0, 1.0);
		white = 0;
	}

	glRecti(x1, y1, x2, y2);
}

void chessboard()
{
	glClear(GL_COLOR_BUFFER_BIT);
	GLint x, y;

	for (x = 0; x <= 800; x += 100)
	{
		for (y = 0; y <= 600; y += 75)
		{
			drawSquare(x, y, x + 100, y + 75);
		}
	}
	glFlush();
}


void myDisplay()
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0, 0.0, 0.0);
	chessboard();
	glFlush();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(screenwidth, screenHeight);
	glutInitWindowPosition(100, 150);
	glutCreateWindow("Chessboard");

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, screenwidth, 0, screenHeight);

	glutDisplayFunc(myDisplay);
	glutMainLoop();

}