
class Circle
{

public:
	Circle();
	Circle(double r);
	void setRadius(double r);
	double getRadius();
	double getArea();
	double getCirumference();
	bool compareCircles(Circle someCircleObject);

private:
	double radius;
};