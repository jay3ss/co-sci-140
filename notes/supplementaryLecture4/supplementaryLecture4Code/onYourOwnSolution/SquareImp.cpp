#include <iostream>
#include "Square.h" 
using namespace std;

	Square::Square()
	{
		length = 1;
	}
	Square::Square(double side)
	{
		length = side;
	}
	void Square::setLength(double side)
	{
		length = side;
	}
	double Square::getLength() const
	{
		return length;
	}
	double Square::getArea() const
	{
		return pow(length, 2.0);
	}
	double Square::getPerimeter() const
	{
		return 4*length;
	}