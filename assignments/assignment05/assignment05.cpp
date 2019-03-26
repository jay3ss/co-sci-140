// Joshua Saunders
// CO SCI 140 (Section 15029) - Assignment 05
// Due March 31, 2019
//
// Prompt:
//
// Modify the FeetInches class discussed in this chapter on page 838 so it
// overloads the following operators:
// 
// - <=
// - >=
// - !=
// 
// Demonstrate the class’s capabilities in a simple program
#include <iostream>
#include "FeetInches.h"

using namespace std;

int main()
{
    int feet = 0;
    int inches = 0;

    // Prompt the user to enter the first distance
    cout << "Enter a distance in feet and inches: Feet: ";
    cin >> feet;
    cout << "Inches: ";
    cin >> inches;

    FeetInches distance1(feet, inches);

    // Prompt the user to enter the second distance
    cout << "Enter another distance in feet and inches: Feet: ";
    cin >> feet;
    cout << "Inches: ";
    cin >> inches;

    FeetInches distance2(feet, inches);

    if (distance1 != distance2)
    {
        cout << "The two are not equal.\n";
    }

    if (distance1 >= distance2)
    {
        cout << distance1.getFeet() << " feet, "
             << distance1.getInches() << " inches "
             << " is >= "
             << distance2.getFeet() << " feet, "
             << distance2.getInches() << " inches\n";
    }

    if (distance1 <= distance2)
    {
        cout << distance1.getFeet() << " feet, "
             << distance1.getInches() << " inches "
             << " is <= "
             << distance2.getFeet() << " feet, "
             << distance2.getInches() << " inches";
    }

    return 0;
}