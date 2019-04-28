#include "PassFailActivityV1.h"

char PassFailActivity::getLetterGrade() const
{
    if (score >= minPassingScore)
    {
        return 'P';
    }
    else
    {
        return 'F';
    }
}