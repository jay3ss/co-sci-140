#ifndef _FINAL_EXAM_V1_H
#define _FINAL_EXAM_V1_H

#include "GradedActivityV1.h"

class FinalExamV1 : public GradedActivityV1
{
private:
    int numQuestions;   // Number of questions
    double pointsEach;  // Points for each question
    int numMissed;      // Number of questions missed
public:
    // Default constructor
    FinalExamV1()
        { numQuestions = 0;
          pointsEach = 0.0;
          numMissed = 0; }
    
    // Constructor
    FinalExamV1(const int questions, const int missed)
        { set(questions, missed); }
    
    // Mutator function
    void set(const int, const int);

    // Accessor functions
    double getNumQuestions() const
        { return numQuestions; }
    
    double getPointsEach() const
        { return pointsEach; }
    
    int getNumMissed() const
        { return numMissed; }
};

#endif // _FINAL_EXAM_V1_H
