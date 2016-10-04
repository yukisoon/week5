#pragma once

class GeometricObject
{
public:
	int width;
	int height;
	float *pixels;
	static GeometricObject* instance;

	GeometricObject();
	GeometricObject(const int& w, const int& h);

	~GeometricObject();

	static GeometricObject* getInstance();
	
	static GeometricObject* createGeometricObject(const int& object, GeometricObject* test);

	void backgroundColor(const float& red, const float& green, const float& blue);	

	virtual void draw(const int& x_s, const int& y_s, const int& x_e, const int& y_e, const float& red, const float& green, const float& blue);
	void drawOnePixel(const int& x, const int& y, const float& red, const float& green, const float& blue);
	void drawLine(const int& x_s, const int& y_s, const int& x_e, const int& y_e, const float& red, const float& green, const float& blue);
	

	//void openWindow();
};

