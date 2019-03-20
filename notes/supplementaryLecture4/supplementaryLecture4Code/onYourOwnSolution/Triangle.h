#ifndef Triangle_H
#define Triangle_H
class Triangle
{
public:
	Triangle();
	Triangle(double base, double height);
	void setBase(double b);
	void setHeigth(double h);
	double getBase() const;
	double getHeight()const;
	double getArea()const;

private:
	double base;
	double height;
};
#endif