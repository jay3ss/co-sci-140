// An abstract base class called BasicShape
#ifndef _BASIC_SHAPE_H
#define _BASIC_SHAPE_H

class BasicShape
{
private:
    double area;    // The area of the shape
public:
    /** Sets the area of the shape
     @param a The area of the shape
     @post The area data member will be set to the value of a */
    void setArea(double a)
        { area = a; }
    /** Returns the area of the shape
     @return The area of the shape */
    double getArea() const
        { return area; }
    /** Calculates the area of the shape */
    virtual void calcArea() = 0;
};

#endif // _BASIC_SHAPE_H
