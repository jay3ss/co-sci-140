// Joshua Saunders
// CO SCI 140 (Section 15029) - Assignment 07
// Due May 12, 2019
//
// Write a template for a function called total. The function should keep
// running total of values entered by the user, then return the total. The
// argument sent into the function should be the number of values the function
// is to read. Test the template in a simple driver program that sends values
// of various types as arguments and displays the results.
#include <iostream>

using namespace std;

// Function prototype
template<class T>
T total(const T numVals);

int main()
{
    int numIntVals;
    cout << "How many integer values do you wish to total? ";
    cin >> numIntVals;

    int intTotal = total(numIntVals);
    cout << "Total is " << intTotal << "\n\n";

    double numDblVals;
    cout << "How many double values do you wish to total? ";
    cin >> numDblVals;

    double dblTotal = total(numDblVals);
    cout << "Total is " << dblTotal << endl;
}

template <class T>
T total(const T numVals)
{
    T value, sum = 0, count = 0;

    // Prompt the user to enter a value and sum the value until
    // the desired number of values (numVals) has been reached
    while (count < numVals)
    {
        cout << "Enter a value: ";
        cin >> value;
        sum += value;

        count++;
    }

    return sum;
}
