#ifndef _GRADED_ACTIVITY_V2_H
#define _GRADED_ACTIVITY_V2_H

class GradedActivityV2
{
protected:
    double score;
public:
    // Default constructor
    GradedActivityV2()
        { score = 0; }

    // Constructor
    GradedActivityV2(const double s)
        { score = s; }
    
    // Mutator function
    void setScore(const double s)
        { score = s; }
    
    // Accessor function
    double getScore() const
        { return score; }
    
    char getLetterGrade() const;
};

#endif // _GRADED_ACTIVITY_V2_H