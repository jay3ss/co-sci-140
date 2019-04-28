#include "Circle.h"

/** Calculates the area of the circle using the formula
 area = 3.14159 * radius * radius
 and sets the area data member to this value using the inherited setArea
 function. */
void Circle::calcArea()
{
    setArea(3.14159 * radius * radius);
}
