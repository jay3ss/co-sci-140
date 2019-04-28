//
#ifndef _CIRCLE_H
#define _CIRCLE_H

#include "BasicShape.h"

class Circle : public BasicShape
{
private:
    long int centerX;
    long int centerY;
    double radius;
public:
    Circle(const long int cx = 0, const long int cy = 0, const double r = 0) :
        centerX(cx), centerY(cy), radius(r)
        { calcArea(); }
    void setCenterX(const long int cx)
        { centerX = cx; }
    void setCenterY(const long int cy)
        { centerY = cy; }
    long int getCenterX() const
        { return centerX; }
    long int getCenterY() const
        { return centerY; }
    void calcArea();
};

#endif // _CIRCLE_H
