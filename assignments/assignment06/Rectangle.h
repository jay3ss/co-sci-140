//
#ifndef _RECTANGLE_H
#define _RECTANGLE_H

#include "BasicShape.h"

class Rectangle : public BasicShape
{
private:
    long int width;
    long int length;
public:
    Rectangle(const long int w = 0, const long int l = 0) : width(w), length(l)
        { calcArea(); }
    void setWidth(const long int w)
        { width = w; }
    void setLength(const long int l)
        { length = l; }
    long int getWidth() const
        { return width; }
    long int getLength() const
        { return length; }
    void calcArea();
};

#endif // _RECTANGLE_H
