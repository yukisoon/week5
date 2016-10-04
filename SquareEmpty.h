#pragma once

#include <iostream>
#include "GeometricObject.h"

class SquareEmpty : public GeometricObject
{
public:
	GeometricObject* geo;

	SquareEmpty(GeometricObject* p) : geo(p) {}

	void draw(const int& x_s, const int& y_s, const int& x_e, const int& y_e, const float& red, const float& green, const float& blue)
	{
		geo->draw(x_s-25, y_s-75, x_e, y_e, red, green, blue);

		//std::cout << "SquareEmpty" << std::endl;

		geo->drawLine(x_s,		y_s,		x_e,		y_e,		red, green, blue);
		geo->drawLine(x_s,		y_s - 50,	x_e,		y_e - 50,	red, green, blue);
		geo->drawLine(x_s,		y_s - 50,	x_e - 50,	y_e,		red, green, blue);
		geo->drawLine(x_s + 50,	y_s - 50,	x_e,		y_e,		red, green, blue);
	}
};