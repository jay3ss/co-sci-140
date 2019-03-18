// Class for a quiz question
#ifndef QUESTION_H
#define QUESTION_H
#include <memory>
#include <string>

using namespace std;

class Question
{
public:
    Question(int na = 4)
    { numAnswers = na;
      questionText = "";
      possibleAnswers = new string[na]; }

    ~Question()
    { delete [] possibleAnswers;
      possibleAnswers = nullptr; }

    bool checkAnswer(int ans) const
    { return ans == correctAnswer; }

    // Accessors
    string getQuestionText()
    { return questionText; }

    string *getPossibleAnswers()
    { return possibleAnswers; }

    int getCorrectAnswerNum() const
    { return correctAnswer; }

    int getNumAnswers() const
    { return numAnswers; }

    string getCorrectAnswerText()
    { return possibleAnswers[correctAnswer - 1]; }

    // Mutators
    void setQuestionText(string qt)
    { questionText = qt; }

    void setPossibleAnswer(string pAns, int idx)
    { possibleAnswers[idx] = pAns; }

    void setPossibleAnswers(string pa[]);

    void setCorrectAnswer(int ca)
    { correctAnswer = ca; }

private:
    int numAnswers;             // Number of answers (default=4)
    string questionText;        // The question text
    string* possibleAnswers;    // Possible answers to question
    int correctAnswer;          // Correct answer (1, 2, 3, or 4)
};

#endif // QUESTION_H