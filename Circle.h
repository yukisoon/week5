#pragma once

#include <iostream>
#include "GeometricObject.h"

class Circle : public GeometricObject
{
public:
	GeometricObject* geo;

	Circle(){}
	Circle(GeometricObject* p) : geo(p) {}

	void draw(const int& x_s, const int& y_s, const int& x_e, const int& y_e, const float& red, const float& green, const float& blue)
	{
		geo->draw(x_s - 20, y_s - 20, x_e, y_e, red, green, blue); 

		//std::cout << "Circle" << std::endl;
		
		object(x_s, y_s, x_e - x_s, y_e - y_s, red, green, blue);
		object(x_s + 1, y_s + 1, x_e - x_s - 1, y_e - y_s - 1, 1.0f, 1.0f, 1.0f);
	}

	void object(const int& x, const int& y, const int& w, const int& h, const float& red, const float& green, const float& blue)
	{
		for (int i = 0; i<w * 2; i++)
		{
			for (int j = 0; j<h * 2; j++)
			{
				if (w*h >(i + 0.5 - w)*(i + 0.5 - w) + (j + 0.5 - h)*(j + 0.5 - h))
					geo->drawOnePixel(i + x, j + y, red, green, blue);
			}
		}
	}
};
