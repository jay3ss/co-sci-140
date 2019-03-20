#ifndef Square_H
#define Square_H
class Square
{
public:
	Square();
	Square(double side);
	void setLength(double side);
	double getLength() const;
	double getArea() const;
	double getPerimeter() const;

private:
	double length;
};
#endif