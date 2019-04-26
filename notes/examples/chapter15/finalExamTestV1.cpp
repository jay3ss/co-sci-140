#include <iomanip>
#include <iostream>
#include "FinalExamV1.h"

using namespace std;

int main()
{
    int questions;  // Number of questions on the exam
    int missed;     // Number of questions missed by the student

    // Get the number of questions on the final exam
    cout << "How many questions are on the final exam? ";
    cin >> questions;

    // Get the number of questions the student missed
    cout << "How many questions did the student miss? ";
    cin >> missed;

    // Define a FinalExamV1 object and initialize it with
    // the values entered
    FinalExamV1 test(questions, missed);

    // Display the rest results
    cout << setprecision(2);
    cout << "\nEach question counts " << test.getPointsEach() << " points.\n"
         << "The exam score is " << test.getScore() << "\n"
         << "The exam grade is " << test.getLetterGrade() << "\n";
    
    return 0;
}
