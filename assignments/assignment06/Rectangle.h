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
    void calcArea();
};

#endif // _RECTANGLE_H