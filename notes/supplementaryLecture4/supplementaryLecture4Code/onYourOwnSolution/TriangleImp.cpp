#include <iostream>
#include "Triangle.h" 
using namespace std;

	Triangle::Triangle()
	{
		base = 1;
		height = 1;
	}
	Triangle::Triangle(double b, double h)
	{
		base = b;
		height = h;
	}
	void Triangle::setBase(double b)	
	{
		base = b;
	}
	void Triangle::setHeigth(double h)	
	{
		height = h;
	}
	double Triangle::getBase()const	
	{
		return base;
	}
	double Triangle::getHeight() const	
	{
		return height;
	}
	double Triangle::getArea()const
	{
		return 0.5*base*height;
	}
