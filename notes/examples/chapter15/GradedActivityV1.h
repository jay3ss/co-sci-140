#ifndef _GRADED_ACTIVITY_V1_H
#define _GRADED_ACTIVITY_V1_H

class GradedActivityV1
{
private:
    double score;
public:
    // Default constructor
    GradedActivityV1()
        { score = 0; }
    
    // Constructor
    GradedActivityV1(const double s)
        { score = s; }
    
    // Mutator function
    void setScore(const double s)
        { score = s; }
    
    // Accessor function
    double getScore() const
        { return score; }

    char getLetterGrade() const;
};

#endif // _GRADED_ACTIVITY_V1_H