#ifndef _PASS_FAIL_V1_EXAM_H
#define _PASS_FAIL_V1_EXAM_H

#include "PassFailActivityV1.h"

class PassFailExam : public PassFailActivity
{
private:
    int numQuestions;
    double pointsEach;
    int numMissed;
public:
    // Constructors
    PassFailExam() : PassFailActivity()
        { numQuestions = 0;
          pointsEach = 0.0;
          numMissed = 0; }
    PassFailExam(int questions, int missed, double mps) :
        PassFailActivity(mps)
        { set (questions, missed); }
    // Mutator
    void set(int, int);
    // Accessors
    int getNumQuestions() const
        { return numQuestions; }
    double getPointsEach() const
        { return pointsEach; }
    int getNumMissed() const
        { return numMissed; }
};

#endif //_PASS_FAIL_V1_EXAM_H