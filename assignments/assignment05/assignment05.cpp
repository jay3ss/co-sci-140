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

// Function prototype
// Prints the results of the comparison of the two distances set by the user
void printResults(FeetInches&, FeetInches&);

int main()
{
    int feet = 0;       // Hold the feet for both FeetInches instances
    int inches = 0;     // Hold the inches for both FeetInches instances

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

    printResults(distance1, distance2);

    return 0;
}

// Prints the results of the comparison of the two distances set by the user
//
// Args:
// distance1:   FeetInches reference
// distance2:   FeetInches reference
// 
// Returns:
// Nothing
void printResults(FeetInches& distance1, FeetInches& distance2)
{
    if (distance1 != distance2)
    {
        cout << "The two are not equal.\n";
    }

    if (distance1 >= distance2)
    {
        cout << distance1 << " is >= " << distance2 << "\n";
    }

    if (distance1 <= distance2)
    {
        cout << distance1 << " is <= " << distance2 << "\n";
    }
}