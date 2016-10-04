#include <iostream>

#include <GLFW/glfw3.h>

#include "GeometricObject.h"
#include "Thickner.h"
#include "SquareEmpty.h"
#include "Box.h"//"SquareFill.h"
#include "Triangle.h"
#include "Pentagon.h"
#include "Circle.h"


GeometricObject::GeometricObject() {}

GeometricObject::GeometricObject(const int& w, const int& h)
	: width(w), height(h)
{
	std::cout << width << std::endl;
	pixels = new float[width * height * 3];	
}

GeometricObject::~GeometricObject()
{
	delete[] pixels;
}

GeometricObject * GeometricObject::instance = NULL;
GeometricObject * GeometricObject::getInstance()
{
	if (!instance)
		instance = new GeometricObject();

	return instance;
}


//void GeometricObject::openWindow()
//{
//	GLFWwindow* window;
//
//	/* Initialize the library */
//	if (!glfwInit())
//		return;
//
//	/* Create a windowed mode window and its OpenGL context */
//	window = glfwCreateWindow(width, height, "week5", NULL, NULL);
//	if (!window)
//	{
//		glfwTerminate();
//		return;
//	}
//
//	/* Make the window's context current */
//	glfwMakeContextCurrent(window);
//
//	/* Loop until the user closes the window */
//	//while (!glfwWindowShouldClose(window))
//	while(true)
//	{
//		/* Render here */
//		glClear(GL_COLOR_BUFFER_BIT);
//
//		//assign all pixels red color
//		draw();
//
//		glDrawPixels(width, height, GL_RGB, GL_FLOAT, pixels);
//
//		/* Swap front and back buffers */
//		glfwSwapBuffers(window);
//
//		/* Poll for and process events */
//		glfwPollEvents();
//
//		if (glfwWindowShouldClose(window))
//			break;
//	}
//
//	glfwTerminate();
//	
//	//GeometricObject::~GeometricObject();
//
//	return;
//}

void GeometricObject::backgroundColor(const float& red, const float& green, const float& blue)
{
	for (int j = 0; j < height; j++)
	{
		for (int i = 0; i < width; i++)
			drawOnePixel(i, j, 1.0f, 1.0f, 1.0f);
	}
}


void GeometricObject::drawOnePixel(const int& x, const int& y, const float& red, const float& green, const float& blue)
{
	pixels[(x + width*y) * 3 + 0] = red;
	pixels[(x + width*y) * 3 + 1] = green;
	pixels[(x + width*y) * 3 + 2] = blue;
}


void GeometricObject::drawLine(const int& x_s, const int& y_s, const int& x_e, const int& y_e, const float& red, const float& green, const float& blue)
{
	if (x_e == x_s)
	{
		for (int y = y_s; y <= y_e; y++)
			drawOnePixel(x_s, y, red, green, blue);
	}
	else
	{
		for (int i = x_s; i <= x_e; i++)
		{
			const int j = (y_e - y_s)*(i - x_s) / (x_e - x_s) + y_s;
			drawOnePixel(i, j, red, green, blue);
		}
	}
}

void GeometricObject::draw(const int& x_s, const int& y_s, const int& x_e, const int& y_e, const float& red, const float& green, const float& blue)
{
	Circle * cir = new Circle(getInstance());

	cir->object(x_s, y_s, 50, 50, red, green, blue);
	cir->object(x_s + 1, y_s + 1, 49, 49, 1.0f, 1.0f, 1.0f);
}


//GeometricObject* GeometricObject::createGeometricObject(const int& object)
GeometricObject* GeometricObject::createGeometricObject(const int& object, GeometricObject* temp)
{
	int x_s, y_s, x_e, y_e;
	float red = 1.0f, green = 0.0f, blue = 0.0f;

	//factory pattern
	//GeometricObject* temp = nullptr;
	if (object == 0)
	{		
		temp = new Thickner(temp);
		x_s = 100; y_s = 350; x_e = 0; y_e = 0;
	}
	else if (object == 1)
	{
		temp = new SquareEmpty(temp);
		x_s = 250; y_s = 350; x_e = 300; y_e = 350;
	}
	else if (object == 2)
	{
		temp = new Box(temp);
		x_s = 400; y_s = 300; x_e = 450; y_e = 350;
	}
	else if (object == 3)
	{
		temp = new Triangle(temp);
		x_s = 100; y_s = 120; x_e = 130; y_e = 150;
	}
	else if (object == 4)
	{
		temp = new Pentagon(temp);
		x_s = 250; y_s = 130; x_e = 280; y_e = 160;
	}
	else if (object == 5)
	{
		temp = new Circle(temp);
		x_s = 400; y_s = 100; x_e = 430; y_e = 130;
	}

	temp->draw(x_s, y_s, x_e, y_e, red, green, blue);
	
	return nullptr;
}


