#include "FinalExamV2.h"

#include <iostream>

using namespace std;

//*******************************************************
// set function                                         *
// The parameters are the number of questions and the   *
// number of questions missed.                          *
//*******************************************************
void FinalExamV2::set(int questions, int missed)
{
    double numericScore;

    numQuestions = questions;
    numMissed = missed;

    pointsEach = 100.0 / static_cast<double>(numQuestions);

    numericScore = 100.0 - (missed * pointsEach);

    setScore(numericScore);
    adjustScore();
}

//**************************************************************
// Definition of Test::adjustScore. If score is within         *
// 0.5 points of the next whole point, it rounds the score up  *
// and recalculates the letter grade.                          *
//**************************************************************
void FinalExamV2::adjustScore()
{
    double fraction = score - static_cast<int>(score);

    if (fraction >= 0.5)
    {
        score += (1.0 - fraction);
    }
}