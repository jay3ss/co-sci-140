#ifndef Triangle_H
#define Triangle_H
class Triangle
{
public:
	Triangle();
	Triangle::Triangle(double s1, double s2, double s3);
	//given the lengths of three sides of a trianle, determines if it is a
	//right triangle
	//returns true if it is; false otherwhise
	bool isRightTriangle(double side1, double side2, double side3) const;

	//given an object of type Triangle, determines if it is similar
	//to another object of type Triangle
	//in this case ASSUME that is two triangles are right triangles,
	//then they are similar, 
	//Of course we know that mathematically this is not true, but let's use this as a
	//definition of similarity in this program
	bool isSimilar (Triangle someTriangle) const;

	//the names of the next methods describles their purpose/function
	void setSide1(double s1);
	void setSide2(double s2);
	void setSide3(double s3);
	double getSide1() const;
	double getSide2() const;
	double getSide3() const;

private:
	double side1;
	double side2;
	double side3;
};
#endif