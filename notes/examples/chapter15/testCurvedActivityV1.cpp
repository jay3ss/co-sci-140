#include <iostream>
#include <iomanip>
#include "CurvedActivity.h"

using namespace std;

int main()
{
    double numericScore;
    double percentage;

    CurvedActivity exam;

    cout << "Enter the student's raw numeric score: ";
    cin >> numericScore;

    cout << "Enter the curve percentage for this student: ";
    cin >> percentage;

    exam.setPercentage(percentage);
    exam.setScore(numericScore);

    cout << fixed << setprecision(2);
    cout << "The raw score is " << exam.getRawScore() << endl
         << "The curved score is " << exam.getScore() << endl
         << "The curved grade is " << exam.getLetterGrade() << endl;

    return 0;
}