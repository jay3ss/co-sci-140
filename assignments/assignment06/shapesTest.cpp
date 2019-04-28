// Joshua Saunders
// CO SCI 140 (Section 15029) - Chapter 15 Quiz
// Due April 28, 2019
//
// A driver program that defines a Circle object and a Rectangle object.
// Demonstrates that each object properly calculates and reports its area.
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

    cout << "What is the y-coordinate of the center of the circle? ";
    cin >> centerY;

    cout << "What is the radius of the circle? ";
    cin >> radius;

    Circle circle(centerX, centerY, radius);

    cout << "What is the length of the rectangle? ";
    cin >> length;

    cout << "What is the width of the rectangle? ";
    cin >> width;

    Rectangle rectangle(length, width);

    cout << endl;

    cout << "The circle is centered at (" << circle.getCenterX()
         << ", " << circle.getCenterY() << ")." << endl
         << "The circle's area is " << circle.getArea() << " square units.\n\n";

    cout << "The rectangle's length and width are " << rectangle.getLength()
         << " units and " << rectangle.getWidth() << " units, respectively.\n"
         << "The rectangle's area is " << rectangle.getArea()
         << " square units.\n";

    return 0;
}

void displayShape(BasicShape &shape)
{
    cout << shape.getArea() << " square units\n";
}
