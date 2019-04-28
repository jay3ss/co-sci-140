#ifndef _FINAL_EXAM_V2_H
#define _FINAL_EXAM_V2_H

#include "GradedActivityV2.h"

class FinalExamV2 : public GradedActivityV2
{
private:
    int numQuestions;
    double pointsEach;
    int numMissed;

public:
    // Default constructor
    FinalExamV2()
    {
        numQuestions = 0;
        pointsEach = 0.0;
        numMissed = 0;
    }

    // Constructor
    FinalExamV2(int questions, int missed)
        { set(questions, missed); }

    // Mutator functions
    void set(int, int);
    void adjustScore();

    // Accessor functions
    double getNumQuestions() const
    {
        return numQuestions;
    }

    double getPointsEach() const
    {
        return pointsEach;
    }

    int getNumMissed() const
    {
        return numMissed;
    }
};

#endif // _FINAL_EXAM_V2_H