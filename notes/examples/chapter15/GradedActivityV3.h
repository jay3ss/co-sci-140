#ifndef _GRADED_ACTIVITY_V3_H
#define _GRADED_ACTIVITY_V3_H

class GradedActivity
{
protected:
    char letter;
    double score;
    void determineGrade();
public:
    GradedActivity()
        { letter = ' '; score = 0.0; }
    void setScore(double s)
        { score = s;
          determineGrade(); }
    double getScore() const
        { return score; }
    char getLetterGrade() const
        { return letter; }
};

#endif // _GRADED_ACTIVITY_V3_H