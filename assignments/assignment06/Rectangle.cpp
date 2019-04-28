#include "Rectangle.h"

/** Calculates the area of the rectangle using the formula
 area = length * width
 and sets the area data member to this value using the inherited setArea
 function. */
void Rectangle::calcArea()
{
    setArea(length * width);
}
