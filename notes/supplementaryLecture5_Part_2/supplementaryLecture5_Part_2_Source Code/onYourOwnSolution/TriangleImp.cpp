#include <iostream>
#include "Triangle.h" 
using namespace std;

	Triangle::Triangle()
	{
		side1 = 0;
		side2 = 0;
		side3 = 0;
	}

	bool Triangle::isRightTriangle(double side1, double side2, double side3) const
	{
		if(pow(side1, 2.0) == pow(side2, 2.0) + pow(side3, 2.0))
		{
			return true;
		}
		else if(pow(side2, 2.0) == pow(side1, 2.0) + pow(side3, 2.0))
		{
			return true;
		}
		else if(pow(side3, 2.0) == pow(side1, 2.0) + pow(side2, 2.0))
		{
			return true;
		}
		else
		{
			return false;
		}

	}
	bool Triangle::isSimilar (Triangle someTriangle) const
	{
		if (isRightTriangle(side1, side2, side3) == someTriangle.isRightTriangle(someTriangle.getSide1(), someTriangle.getSide2(), someTriangle.getSide3()))
		return true;
		else
		return false;
	}
	void Triangle::setSide1(double s1)
	{
		side1 = s1;
	}
	void Triangle::setSide2(double s2)
		{
		side2 = s2;
	}
	void Triangle::setSide3(double s3)
		{
			side3 = s3;
	}
	double Triangle::getSide1() const
		{
			return side1;
	}
	double Triangle::getSide2() const
		{
			return side2;
	}
	double Triangle::getSide3() const
		{
			return side3;
	}