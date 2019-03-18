// Implementation the Question class
#include "Question.h"

void Question::setPossibleAnswers(string pa[])
{
    for (int i = 0; i < numAnswers; i++)
    {
        possibleAnswers[i] = pa[i];
    }
}
