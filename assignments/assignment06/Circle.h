// Class that implements a circle. Derives from the BasicShape abstract
// base class
#ifndef _CIRCLE_H
#define _CIRCLE_H

#include "BasicShape.h"

class Circle : public BasicShape
{
private:
    long int centerX;   // The x-coordinate of the circle's center
    long int centerY;   // The y-coordinate of the circle's center
    double radius;      // Radius of the circle
public:
    /** Constructor
     @param cx The x-coorindate of the circle
     @param cy The y-coorindate of the circle
     @param r The radius of the circle
     @post Calculates area of the rectange and sets the area data member to
           this value */
    Circle(const long int cx = 0, const long int cy = 0, const double r = 0) :
        centerX(cx), centerY(cy), radius(r)
        { calcArea(); }
    /** Sets the x-coordinate of the center of the circle
     @param cx The x-coordinate of the center of the circle
     @post The centerX member will be set to the value of cx */
    void setCenterX(const long int cx)
        { centerX = cx; }
    /** Sets the x-coordinate of the center of the circle
     @param cy The y-coordinate of the center of the cicle
     @post The centerY member will be set to the value of cy*/
    void setCenterY(const long int cy)
        { centerY = cy; }
    /** Returns the x-coordinate of the center of the circle
     @return The x-coordinate of the center of the circle */
    long int getCenterX() const
        { return centerX; }
    /** Returns the y-coordinate of the center of the circle
     @return The y-coordinate of the center of the circle */
    long int getCenterY() const
        { return centerY; }
    /** Calculates the area of the circle and sets the area member to this
     value
     @pre The radius of the circle must be set
     @post The area member will be set to the area of the circle */
    void calcArea();
};

#endif // _CIRCLE_H
