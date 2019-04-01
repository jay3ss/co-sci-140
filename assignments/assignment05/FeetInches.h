// Joshua Saunders
// CO SCI 140 (Section 15029) - Assignment 05
// Due March 31, 2019
// The FeetInches class holds distances or measurements
// expressed in feet and inches.
#ifndef FEETINCHES_H
#define FEETINCHES_H

#include <ostream>

using namespace std;

class FeetInches
{
private:
    int feet;           // To hold a number of feet
    int inches;         // To hold a number of inches
    void simplify();    // Defined in FeetInches.cpp
public:
    // Constructor
    FeetInches(int f = 0, int i = 0)
    { feet = f;
      inches = i;
      simplify();
    }

    // Mutator functions
    void setFeet(int f)
        { feet = f; }
    
    void setInches(int i)
        { inches = i;
          simplify(); }
    
    // Accessor functions
    int getFeet() const
        { return feet; }
    
    int getInches() const
        { return inches; }
    
    // Overloaded operator functions
    FeetInches operator + (const FeetInches &);     // Overloaded +
    FeetInches operator - (const FeetInches &);     // Overloaded -
    bool operator >= (const FeetInches &);    // Overloaded >=
    bool operator <= (const FeetInches &);    // Overloaded <=
    bool operator != (const FeetInches &);    // Overloaded !=

    // Friend
    friend ostream &operator<<(ostream &, const FeetInches &);
};

#endif // FEETINCHES_H