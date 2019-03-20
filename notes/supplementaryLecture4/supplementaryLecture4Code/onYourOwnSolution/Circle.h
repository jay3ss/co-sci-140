#ifndef Circle_H
#define Circle_H
class Circle
{

public:
	Circle();
	Circle(double r);
	void setRadius(double r);
	double getRadius() const;
	double getArea() const;
	double getCirumference() const;

private:
	double radius;
};
#endif