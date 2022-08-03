/*
* 
**glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA)
* Depth buffer
* Double buffering (front and back buffer for smooth flicker free rendering)
* format of the frame buffer to be with RED, GREEN, BLUE and ALPHA channels
* 
**glutInitContextVersion(4, 3)
* set the required OpenGL context version we desire
* First parameter is the major version and second parameter is the minor version. (4, 3) => OpenGL version 4.3
* 
**glutInitContextFlags(GLUT_CORE_PROFILE | GLUT_DEBUG)
**glutInitContextProfile(GLUT_FORWARD_COMPATIBLE)
* we can register a callback when any OpenGL related error occurs. 
* Passing GLUT_DEBUG to the glutInitContextFlags functions creates the OpenGL context in debug mode which is needed for the debug message callback.
*	**
    * For any version of OpenGL including OpenGL v3.3 and above, there are two profiles 
	* available: the core profile (which is a pure shader based profile without support 
	* for OpenGL fixed functionality) and the compatibility profile (which supports the 
	* OpenGL fixed functionality). All of the matrix stack functionality glMatrixMode(*), 
	* glTranslate*, glRotate*, glScale*, and so on, and immediate mode calls 
	* such as glVertex*, glTexCoord*, and glNormal* of legacy OpenGL, are 
	* retained in the compatibility profile. However, they are removed from the core profile. 
	* In our case, we will request a forward compatible core profile which means that we 
	* will not have any fixed function OpenGL functionality available.
	**
* 
* 
*/

#include <glew.h>
#include <freeglut.h>
#include <iostream>
using namespace std;

const int WIDTH = 1280;
const int HEIGHT = 960;

void OnInit() {
	glClearColor(1, 0, 0, 0);
	cout << "Initialization successfull" << endl;
}
void OnShutdown() {
	cout << "Shutdown successfull" << endl;
}
void OnResize(int nw, int nh) { }

void OnRender() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glutSwapBuffers();
}

int main(int argc, char** argv) {

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE |GLUT_RGBA);
	glutInitContextVersion(3, 3);
	glutInitContextFlags(GLUT_CORE_PROFILE | GLUT_DEBUG);
	// glutInitContextProfile(GLUT_FORWARD_COMPATIBLE);

	glutInitWindowSize(WIDTH, HEIGHT);
	glutCreateWindow("Getting Started with newer version of OpenGL");

	/*
	* It is important to initialize the GLEW library after the OpenGL context has been created. 
	* If the function returns GLEW_OK the function succeeds, otherwise the GLEW initialization fails.
	* 
	* The glewExperimental global switch allows the GLEW library to report an extension 
	* if it is supported by the hardware but is unsupported by the experimental or 
    * pre-release drivers. After the function is initialized, the GLEW diagnostic information 
    * such as the GLEW version, the graphics vendor, the OpenGL renderer, and the shader 
    * language version are printed to the standard output.
	*/

	glewExperimental = GL_TRUE;
	GLenum err = glewInit();
	if (GLEW_OK != err) {
		cerr << "Error: " << glewGetErrorString(err) << endl;
	}
	else {
		if (GLEW_VERSION_4_3)
		{
			cout << "Driver supports OpenGL 4.3\nDetails:" << endl;
		}
	}
	cout << "\tUsing glew " << glewGetString(GLEW_VERSION) << endl;
	cout << "\tVendor: " << glGetString(GL_VENDOR) << endl;
	cout << "\tRenderer: " << glGetString(GL_RENDERER) << endl;
	cout << "\tVersion: " << glGetString(GL_VERSION) << endl;
	cout << "\tGLSL: "<< glGetString(GL_SHADING_LANGUAGE_VERSION)<<endl;

	OnInit();                   //  initialization function
	glutCloseFunc(OnShutdown);  //  uninitialization function
	glutDisplayFunc(OnRender);
	glutReshapeFunc(OnResize);
	glutMainLoop();             //  starts the application's main loop
	return 0;
}

