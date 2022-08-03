#include "lve_window.h"
#include<string>

namespace lve {
	LveWindow::LveWindow(int w, int h, std::string name) : width{ w }, height{ h }, windowName{ name } {

		initWindow();
	}

	LveWindow::~LveWindow() {
		glfwDestroyWindow(window);
		glfwTerminate();
	}

	void LveWindow::initWindow() {
		glfwInit();
		glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API); // disable glfw opening in OpenGL context
		glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE); // diable window resizing

		window = glfwCreateWindow(width, height, windowName.c_str(), nullptr, nullptr);
	}
} // namespace lve
