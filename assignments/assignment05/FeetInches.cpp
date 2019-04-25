// Joshua Saunders
// CO SCI 140 (Section 15029) - Assignment 05
// Due March 31, 2019
// Implementation file for the FeetInches class
#include <cstdlib>  // needed for abs()
#include "FeetInches.h"

//**************************************************************
// Definition of member function simplify. This function       *
// Checks for values in the inches member greater than         *
// twelve or less than zero. If such a value is found,         *
// the numbers in feet and inches are adjusted to conform      *
// to a standard feet & inches expression. For example,        *
// 3 feet 14 inches would be adjusted to 4 feet 2 inches and   *
// 5 feet -2 inches would be adjusted to 4 feet 10 inches.     *
//**************************************************************
void FeetInches::simplify()
{
    if (inches >= 12)
    {
        feet += (inches / 12);
        inches %= 12;
    }
    else if (inches < 0)
    {
        feet -= ((abs(inches) / 12) + 1);
        inches = 12 - (abs(inches) % 12);
    }
}

//**************************************************************
// Overloaded binary + operator
//**************************************************************
FeetInches FeetInches::operator + (const FeetInches &right)
{
    FeetInches temp;

    temp.inches = inches + right.inches;
    temp.feet = feet + right.feet;
    temp.simplify();
    return temp;
}

//**************************************************************
// Overloaded binary - operator
//**************************************************************
FeetInches FeetInches::operator - (const FeetInches &right)
{
    FeetInches temp;

    temp.inches = inches - right.inches;
    temp.feet = feet - right.feet;
    temp.simplify();
    return temp;
}

//**************************************************************
// Overloaded binary >= operator
//**************************************************************
bool FeetInches::operator  >= (const FeetInches &right)
{
    bool status;
    
    if (feet > right.feet)
    {
        status = true;
    }
    else if (feet == right.feet && inches >= right.inches)
    {
        status = true;
    }
    else
    {
        status = false;
    }

    return status;
}

//**************************************************************
// Overloaded binary <= operator
//**************************************************************
bool FeetInches::operator <= (const FeetInches &right)
{
    bool status;

    if (feet < right.feet)
    {
        status = true;
    }
    else if (feet == right.feet && inches <= right.inches)
    {
        status = true;
    }
    else
    {
        status = false;
    }

    return status;
}

//**************************************************************
// Overloaded binary != operator
//**************************************************************
bool FeetInches::operator != (const FeetInches &right)
{
    bool status;

    if (feet != right.feet || inches != right.inches)
    {
        status = true;
    }
    else
    {
        status = false;
    }

    return status;
}

//**************************************************************
// Overloaded << operator
//**************************************************************
// This will print the object's data an dtakes care of
// pluralizing "foot" and "inch" when appropriate. It prints in
// the following format:
//
// 5 feet, 3 inches
//
// if the object has feet = 5 and inches = 3. And the format:
//
// 1 foot, 1 inch
//
// if the object has feet = 1 and inches = 1
ostream &operator<<(ostream &strm, const FeetInches &obj)
{
    // Use "foot" or "feet"?
    strm << obj.feet;
    strm << ((obj.feet == 1) ? " foot, " : " feet, ");

    // Use "inch" or "inches"?
    strm << obj.inches;
    strm << ((obj.inches == 1) ? " inch" : " inches");
    
    return strm;
}