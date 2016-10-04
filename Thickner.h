#pragma once

#include <iostream>
#include "GeometricObject.h"

class Thickner : public GeometricObject
{
public:
	GeometricObject* geo;

	Thickner(GeometricObject* p) : geo(p) {}

	void draw(const int& x_s, const int& y_s, const int& x_e, const int& y_e, const float& red, const float& green, const float& blue)
	{	
		geo->draw(x_s - 25, y_s - 75, x_e, y_e, red, green, blue); //GeometricObject::draw();

		//std::cout << "Thickner" << std::endl;
		
		int y = y_s-60;
		
		for (int i = x_s; i >= (x_s - 4); i--)
		{

			for (int j = 0; j < 3; j++)
				geo->drawLine(i, y + j, i + 50, (y + j) + 50, red, green, blue);

			y += 2;
			if (y >= (y_s-50))
				y = y_s-60;
		}

		
	}
};