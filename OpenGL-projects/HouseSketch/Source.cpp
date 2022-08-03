// House Sketch Design with random points.

#include <Windows.h>
#include <gl/Gl.h>
#include <gl/glut.h>
using namespace std;

int screenHeight = 480;
int screenwidth = 640;

#include <cmath>
#include <time.h>

class GLintPoint {
public:
	GLint x, y;
};




void parameterizedHouse(GLintPoint peak, GLint width, GLint height)
// the top of house is at the peak; the size of house is given
// by height and width
{
	// draw shell of house
	glBegin(GL_LINE_LOOP);
	glVertex2i(peak.x, peak.y); 
	glVertex2i(peak.x + width / 2, peak.y - 3 * height / 8);
	glVertex2i(peak.x + width / 2, peak.y - height);
	glVertex2i(peak.x - width / 2, peak.y - height);
	glVertex2i(peak.x - width / 2, peak.y - 3 * height / 8);
	glEnd();

	// draw door of house
	glBegin(GL_LINE_LOOP);
	glVertex2i(peak.x - width / 4, peak.y - 3 * height / 5); 
	glVertex2i(peak.x - width / 4, peak.y - height);
	glVertex2i(peak.x, peak.y - height);
	glVertex2i(peak.x, peak.y - 3 * height / 5);
	glEnd();

	// draw window of house
	glBegin(GL_LINE_LOOP);
	glVertex2i(peak.x +  width / 4, peak.y - 3 * height / 8);
	glVertex2i(peak.x +  width / 4, peak.y - 3 * height / 5);
	glVertex2i(peak.x + 3 * width / 8, peak.y - 3 * height / 5);
	glVertex2i(peak.x + 3 * width / 8, peak.y - 3 * height / 8);
	glEnd();


	// to calculate the coordinates for the chimney

	// left roof
	// left.x = peak.x - width / 2    left.y = peak.y - 3 * height / 8

	GLdouble Ydiff = peak.y - (peak.y - 3 * height / 8);
	GLdouble Xdiff = peak.x - (peak.x - width / 2);

	GLdouble m = Ydiff / Xdiff;

	// y = mx + c --> c = y - mx;
	GLdouble c = peak.y - m * peak.x;

	// draw chimney of the house
	glBegin(GL_LINE_LOOP);
	srand(time(0));
	GLint chimneyH = peak.y + 20 + rand() % 20;
	glVertex2i(peak.x - 3 * width / 8, chimneyH);
	glVertex2i(peak.x - 3 * width / 8 , m * (peak.x - 3 * width / 8) + c);
	glVertex2i(peak.x - width / 4, m * (peak.x - width / 4) + c);
	glVertex2i(peak.x - width / 4, chimneyH);
	glEnd();

}

void myDisplay()
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0, 0.0, 0.0);
	srand(time(0));
	GLint x = 100 + rand() % 200;
	GLint y = 100 + rand() % 300;
	GLintPoint peak = { x, y };
	parameterizedHouse(peak, y, x); // drawFunction
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