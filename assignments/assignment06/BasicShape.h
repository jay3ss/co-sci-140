// An abstract base class called BasicShape
#ifndef _BASIC_SHAPE_H
#define _BASIC_SHAPE_H

class BasicShape
{
private:
    double area;
public:
    void setArea(double a)
        { area = a; }
    double getArea() const
        { return area; }
    virtual void calcArea() = 0;
};

#endif // _BASIC_SHAPE_H