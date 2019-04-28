#include <iomanip>
#include <iostream>
#include "PassFailExamV1.h"

using namespace std;

int main()
{
    int questions;
    int missed;
    double minPassing;

    cout << "How many questions are on the exam? ";
    cin >> questions;

    cout << "How many questions did the student miss? ";
    cin >> missed;

    cout << "Enter the minimum passing score for this test: ";
    cin >> minPassing;

    PassFailExam exam(questions, missed, minPassing);

    cout << setprecision(2) << fixed;
    cout << "\nEach questions counts " << exam.getPointsEach() << " points.\n"
         << "The minimum passing score is " << exam.getMinPassingScore() << endl
         << "The student's exam score is " << exam.getScore() << endl
         << "The student's grade is " << exam.getLetterGrade() << endl;

    return 0;
}