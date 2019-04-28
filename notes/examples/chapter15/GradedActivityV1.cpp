#include "GradedActivityV1.h"

char GradedActivityV1::getLetterGrade() const
{
    if (score > 89)
    {
        return 'A';
    }
    else if (score > 79)
    {
        return 'B';
    }
    else if (score > 69)
    {
        return 'C';
    }
    else if (score > 59)
    {
        return 'D';
    }
    else
    {
        return 'F';
    }
}