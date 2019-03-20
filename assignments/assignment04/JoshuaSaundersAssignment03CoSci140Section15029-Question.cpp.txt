// Joshua Saunders
// CO SCI 140 (Section 15029) - Assignment 04
// Due March 17, 2019
// Implementation the Question class
#include <memory>
#include "Question.h"

// Constructor
// Args:
// na:  Number of possible answers. Default of 4.
Question::Question(int na)
{
    numAnswers = na;
    questionText = "";
    // Allocate a block of memory that depends on the number of possible
    // answers
    possibleAnswers = new string[na];
}

// Destructor
// Args:
// None
Question::~Question()
{
    // Free up the dynamically allocated memory
    delete[] possibleAnswers;
    possibleAnswers = nullptr;
}

// Sets each of the possible answers for a question
// Args:
// pa:  Possible answers array.
// 
// Returns:
// Nothing
void Question::setPossibleAnswers(string pa[])
{
    for (int i = 0; i < numAnswers; i++)
    {
        possibleAnswers[i] = pa[i];
    }
}
