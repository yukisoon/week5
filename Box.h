#pragma once

#include "GeometricObject.h"

class Box : public GeometricObject
{
public:
	GeometricObject* geo;

	Box(GeometricObject* p) : geo(p) {}

	void draw(const int& x_s, const int& y_s, const int& x_e, const int& y_e, const float& red, const float& green, const float& blue);

};