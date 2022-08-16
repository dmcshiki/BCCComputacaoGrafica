#include <iostream>
#include "GL/glew.h"
#include "GLFW/glfw3.h"

int main() {
	int bufferWidth;
	int bufferHeight;

	if (!glfwInit()) {
		printf("glfw não foi iniciado");
		return 1;
	}

	GLFWwindow* mainWindow = glfwCreateWindow(800, 600, "MAIN", NULL, NULL);

	if (!mainWindow) {
		printf("GLFW não conseguiu criar a janela");
		glfwTerminate();
		return 1;
	}

	glfwGetFramebufferSize(mainWindow, &bufferWidth, &bufferHeight);

	glfwMakeContextCurrent(mainWindow);

	if (glewInit() != GLEW_OK) {
		printf("Glew não pode ser iniciado");
		glfwDestroyWindow(mainWindow);
		glfwTerminate();
		return 1;
	}

	glViewport(0, 0, bufferWidth, bufferHeight);
	while (!glfwWindowShouldClose(mainWindow)){
		glfwPollEvents();
		
		glClearColor(1.0f, 0.75f, 0.79f, 1.0f);

		glClear(GL_COLOR_BUFFER_BIT);

		glfwSwapBuffers(mainWindow);
	}

	glfwDestroyWindow(mainWindow);
	glfwTerminate();
	return 0;
}



