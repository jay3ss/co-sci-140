// Joshua Saunders
// CO SCI 140 (Section 15029) - Chapter 15 Quiz
// Due April 28, 2019
//
// A driver program that defines a Circle object and a Rectangle object.
// Demonstrates that each object properly calculates and reports its area.
#include <iomanip>
#include <iostream>
#include "BasicShape.h"
#include "Circle.h"
#include "Rectangle.h"

using namespace std;

void displayShape(BasicShape&);

int main()
{

    // To hold the data for the objects
    long int centerX, centerY, length, width;
    double radius;

    cout << "What is the x-coordinate of the center of the circle? ";
    cin >> centerX;

    cout << "What is the x-coordinate of the center of the circle? ";
    cin >> centerX;

    cout << "What is the radius of the circle? ";
    cin >> radius;

    Circle circle(centerX, centerY, radius);

    cout << "What is the length of the rectangle? ";
    cin >> length;

    cout << "What is the width of the rectangle? ";
    cin >> width;

    Rectangle rectangle(length, width);

    displayShape(circle);
    displayShape(rectangle);

    return 0;
}

void displayShape(BasicShape &shape)
{
    cout << shape.getArea() << " square units\n";
}
