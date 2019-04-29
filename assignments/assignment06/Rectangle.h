// Class that implements a rectangle. Derives from the BasicShape abstract
// base class
#ifndef _RECTANGLE_H
#define _RECTANGLE_H

#include "BasicShape.h"

class Rectangle : public BasicShape
{
private:
    long int length;    // The length of the rectangle
    long int width;     // The width of the rectangle
public:
    /** Constructor
     @param l The length of the rectangle
     @param w The width of the rectangle
     @post Calculates area of the rectange and sets the area data member to
           this value */
    Rectangle(const long int l = 0, const long int w = 0) : length(w), width(l)
        { calcArea(); }
    /** Returns the width of the rectangle
     @return The width of the rectange */
    long int getWidth() const
        { return width; }
    /** Returns the length of the rectangle
     @return The length of the rectange */
    long int getLength() const
        { return length; }
    /** Calculates the area of the rectangle and sets the area member to this
     value
     @pre The length and width of the rectangle must be set
     @post The area member will be set to the area of the rectangle */
    void calcArea();
};

#endif // _RECTANGLE_H
