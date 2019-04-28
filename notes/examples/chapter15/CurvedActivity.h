#ifndef _CURVED_ACTIVITY_V1_H
#define _CURVED_ACTIVITY_V1_H

#include "GradedActivityV3.h"

class CurvedActivity: public GradedActivity
{
protected:
    double rawScore;
    double percentage;
public:
    CurvedActivity() : GradedActivity()
        { rawScore = 0.0; percentage = 0.0; }
    void setScore(double s)
        { rawScore = s;
          GradedActivity::setScore(rawScore * percentage); }
    void setPercentage(double p)
        { percentage = p; }
    double getPercentage() const
        { return percentage; }
    double getRawScore() const
        { return rawScore; }
};

#endif // _CURVED_ACTIVITY_V1_H