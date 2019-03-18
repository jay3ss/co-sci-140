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

    string getQuestionText()
    { return questionText; }

    // NOTE: Should this be an array, a pointer to an array, something else?
    string *getPossibleAnswers()
    { return possibleAnswers; }

    // Accessors
    int getCorrectAnswerNum() const
    { return correctAnswer; }

    int getNumAnswers() const
    { return numAnswers; }

    bool checkAnswer(int ans) const
    { return ans == correctAnswer; }

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
    int numAnswers;
    string questionText;
    string* possibleAnswers;
    int correctAnswer;
    void initialize();

};

#endif // QUESTION_H