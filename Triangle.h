#pragma once

#include <iostream>
#include "GeometricObject.h"

class Triangle : public GeometricObject
{
public:
	GeometricObject* geo;

	Triangle(GeometricObject* p) : geo(p) {}

	void draw(const int& x_s, const int& y_s, const int& x_e, const int& y_e, const float& red, const float& green, const float& blue)
	{
		geo->draw(x_s - 20, y_s - 40, x_e, y_e, red, green, blue); 

		//std::cout << "Triangle" << std::endl;

		geo->drawLine(x_s,		y_s,		x_e,		y_e,		red, green, blue);
		geo->drawLine(x_s + 30,	y_s + 30,	x_e + 30,	y_e - 30,	red, green, blue);
		geo->drawLine(x_s,		y_s,		x_e + 30,	y_e - 30,	red, green, blue);
	}
};