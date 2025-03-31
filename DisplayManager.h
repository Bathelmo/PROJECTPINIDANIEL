#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <math.h>

// Constant value for pi
constexpr double pi = 3.14159265358979323846;

// Function to convert degrees to radians
inline float degreesToRadians(float degrees) {
	return degrees * (pi / 180.0);
}

// Function to convert radians to degrees
inline float radiansToDegrees(float radians) {
	return radians * (180.0 / pi);
}

// Callback function to adjust the viewport when the framebuffer size changes
static void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
	glViewport(0, 0, width, height);
}

const static float FOV = degreesToRadians(60);
const static float Z_NEAR = 0.01f;
const static float Z_FAR = 1000.f;

#pragma once
class DisplayManager
{
public:
	DisplayManager()  {
		init();
	}
	~DisplayManager() {
		deinit();
	}

	void createDisplay(std::string title, int width, int height);
	void updateDisplay();
	void closeDisplay();

	glm::mat4  updatePerspectiveMatrix() {
		return perspectiveMatrix;
	}

	glm::mat4 getPerspectiveMatrix(float width, float height) {
		float aspectRatio = width / height;
		return glm::perspective(glm::radians(FOV), aspectRatio, Z_NEAR, Z_FAR);
	}

	int getWidth() { return width; }
	int getHeight() { return height; }

	bool isKeyPressed(int code) {
		return glfwGetKey(window, code) == GLFW_PRESS;
	}

	bool isResize() {
		return resize;
	}

	void setResize(bool value) {
		resize = value;
	}

	bool windowShouldClose() {
		return glfwWindowShouldClose(window);
	}

public:
	GLFWwindow* window;

private:
	void init() {
		bool ok = glfwInit();

		if (!ok) {
			// err
			std::cerr << "failed to load glfw..";
			return;
		}

		glfwWindowHint(GLFW_VISIBLE, GL_FALSE);
		glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,
			3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,
			3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

		if (width == 0 || height == 0) {
			width = 100;
			height = 100;
			glfwWindowHint(GLFW_MAXIMIZED,
				GLFW_TRUE);
		}
	}
	void deinit() {
		glfwTerminate();
	}

	bool resize;
	int width = 0;
	int height = 0;
	bool vsync = false;
	glm::mat4  perspectiveMatrix;

};


