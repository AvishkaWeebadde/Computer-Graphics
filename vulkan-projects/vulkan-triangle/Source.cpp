#define GLFW_INCLUDE_VULKAN
#include<GLFW/glfw3.h>

#include<iostream>
#include<stdexcept>
#include<cstdlib>

const uint32_t WIDTH = 800;
const uint32_t HEIGHT = 600;

class Triangle
{
public:
	void run() 
	{
		initWindow();
		initVulkan();
		mainLoop();
		cleanUp();
	}

private:
	GLFWwindow* window;
	VkInstance instance;

	void initWindow() 
	{
		glfwInit(); // initialize GLFW library

		// dont create opengl context
		glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
		glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

		window = glfwCreateWindow(WIDTH, HEIGHT, "vulkan-triangle", nullptr, nullptr);
	}

	void createInstance()
	{
		VkApplicationInfo appInfo{}; // struct to provide useful information to the driver in order to optimize the application
		appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
		appInfo.pApplicationName = "vulkan-triangle";
		appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
		appInfo.pEngineName = "No Engine";
		appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
		appInfo.apiVersion = VK_API_VERSION_1_0;


		VkInstanceCreateInfo createInfo{};
		createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
		createInfo.pApplicationInfo = &appInfo;

		uint32_t glfwExtensionCount = 0;
		const char** glfwExtensions;

		glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);
		createInfo.enabledExtensionCount = glfwExtensionCount;
		createInfo.ppEnabledExtensionNames = glfwExtensions;
		createInfo.enabledLayerCount = 0;

		vkCreateInstance(&createInfo, nullptr, &instance);
	}

	void initVulkan() 
	{
		createInstance();
	}
	void mainLoop() 
	{
		while (!glfwWindowShouldClose(window))
		{
			glfwPollEvents();
		}
	}
	void cleanUp() 
	{
		glfwDestroyWindow(window);
		glfwTerminate();
	}


}; // class triangle

int main() 
{
	Triangle app;

	try
	{
		app.run();
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << "\n";
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
} // main