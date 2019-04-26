#include <iomanip>
#include <iostream>
#include "FinalExamV2.h"

using namespace std;

int main()
{
    int questions;
    int missed;

    cout << "How many questions are on the final exam? ";
    cin >> questions;

    cout << "How many questions did the student miss? ";
    cin >> missed;

    FinalExamV2 test(questions, missed);

    cout << setprecision(2) << fixed;
    cout << "\nEach questions counts " << test.getPointsEach() << " points.\n"
         << "The adjusted exam score is " << test.getScore() << endl
         << "The exam grade is " << test.getLetterGrade() << endl;

    return 0;
}