#include <iostream>
#include "Circle.h" 
using namespace std;

	Circle::Circle()
	{
		radius = 1;
	}
	Circle::Circle(double r)
	{
		radius = r;
	}
	void Circle::setRadius(double r)
	{
		radius = r;
	}
	double Circle::getRadius()
	{
		return radius;
	}
	double Circle::getArea()
	{
		return 3.14*pow(radius, 2.0);
	}
	double Circle::getCirumference()
	{
		return 2*3.14*radius;
	}
	bool Circle::compareCircles(Circle someCircleObject)
	{
		return someCircleObject.radius == radius;
	}