#include <iostream>
#include "GradedActivityV1.h"

using namespace std;

int main()
{
    double testScore; // To hold a test score

    // Create a GradedActivityV1 object for the test
    GradedActivityV1 test;

    // Get a numeric test score from the user
    cout << "Enter your numeric test score: ";
    cin >> testScore;

    // Store the numeric test score
    test.setScore(testScore);

    // Display the letter grade for the test.
    cout << "The grade for that test is "
         << test.getLetterGrade() << endl;

    return 0;
}