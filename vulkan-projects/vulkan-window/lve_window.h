#pragma once

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include<string>

namespace lve {

	class LveWindow {

	public: 
		LveWindow(int w, int h, std::string name);
		~LveWindow();

		// delete copy constructor & copy operator
		LveWindow(const LveWindow&) = delete;
		LveWindow& operator=(const LveWindow&) = delete;

		bool shouldClose() {
			return glfwWindowShouldClose(window);
		}

	private:
		void initWindow();  // helper function to initialize the window

		const int width;
		const int height;

		std::string windowName;

		GLFWwindow* window;
	}; // class LveWindow
} // namespace lve
