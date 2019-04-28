#ifndef _PASS_FAIL_ACTIVITY_V1_H
#define _PASS_FAIL_ACTIVITY_V1_H

#include "GradedActivityV3.h"

class PassFailActivity: public GradedActivity
{
protected:
    double minPassingScore;
public:
    // Constructors
    PassFailActivity() : GradedActivity()
        { minPassingScore = 0.0; }
    PassFailActivity(double mps) : GradedActivity()
        { minPassingScore = mps; }
    // Mutators
    void setMinPassingScore(double mps)
        { minPassingScore = mps; }
    // Accessors
    double getMinPassingScore() const
        { return minPassingScore; }
    char getLetterGrade() const;
};

#endif // _PASS_FAIL_ACTIVITY_V1_H