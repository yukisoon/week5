#include <iostream>
#include <GLFW/glfw3.h>
#include "GeometricObject.h"

void main()
{
	GeometricObject* geo = new GeometricObject(640, 480);
	geo->instance = geo;


	GLFWwindow* window;

	/* Initialize the library */
	if (!glfwInit())
		return;

	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(geo->width, geo->height, "week5", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return;
	}


	/* Make the window's context current */
	glfwMakeContextCurrent(window);


	geo->backgroundColor(1.0f, 1.0f, 1.0f);

	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window))
	{
		/* Render here */
		glClear(GL_COLOR_BUFFER_BIT);

		//assign all pixels red color
		//////////////////////////////////////////////////////////////////////

		for (int i = 0; i < 6; i++)
		{
			geo->createGeometricObject(i, geo);
		}

		//////////////////////////////////////////////////////////////////////

		glDrawPixels(geo->width, geo->height, GL_RGB, GL_FLOAT, geo->pixels);

		/* Swap front and back buffers */
		glfwSwapBuffers(window);

		/* Poll for and process events */
		glfwPollEvents();

	}

	glfwTerminate();

	delete geo;

	return;
}