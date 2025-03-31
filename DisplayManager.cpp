#include "DisplayManager.h"

void DisplayManager::createDisplay(std::string title,
	int width, int height) {

	window = glfwCreateWindow(width, height, title.c_str(), NULL, NULL);
	if (window == NULL) {
		std::cerr << "Failed to create GLFWWindow..";
		return;
	}

	glfwSetFramebufferSizeCallback(window, 
		framebuffer_size_callback);

	glfwMakeContextCurrent(window);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		std::cerr << "Failed to initialize GLAD\n";
		return;
	}

	glViewport(0, 0, width, height);

	glfwShowWindow(window);

	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

	std::cout << "window created..";
}	

void DisplayManager::updateDisplay() {
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS &&
		glfwWindowShouldClose(window) == 0) {
		std::cout << "escpae pressed shutting down....";
		return;
	}

	glClear(GL_COLOR_BUFFER_BIT);

	glfwSwapBuffers(window);
	glfwPollEvents();
}

void DisplayManager::closeDisplay() {
	glfwDestroyWindow(window);
}