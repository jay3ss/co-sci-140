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
#include <string>
#include "FeetInches.h"

using namespace std;

int main()
{
    int feet, inches;
    cout << "Enter a distance in feet and inches: Feet: ";
    cin >> feet;
    cout << "Inches: ";
    cin >> inches;

    FeetInches distance(feet, inches);

    cout << "Feet: " << distance.getFeet() << " feet and " << distance.getInches() << " inches.\n";

    return 0;
}