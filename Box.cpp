#include <iostream>
#include "Box.h"

void Box::draw(const int& x_s, const int& y_s, const int& x_e, const int& y_e, const float& red, const float& green, const float& blue)
{
	geo->draw(x_s-25, y_s-25, x_e, y_e, red, green, blue);

	//std::cout << "Box" << std::endl;

	for (int i = x_s; i < x_e; i++)
	{
		for (int j = y_s; j < y_e; j++)
			geo->drawOnePixel(i, j, red, green, blue);
	}
}