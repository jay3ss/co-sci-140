// Class for a quiz question
#include <string>

using namespace std;

class Question
{
public:
    Question(){};
    Question(string, string, string, string, string, int);
    string getQuestionText() const;

    // NOTE: Should this be an array, a pointer to an array, something else?
    string *getPossibleAnswers() const;

    bool checkAnswer();

private:
    string questionText;
    string possibleAnswer1;
    string possibleAnswer2;
    string possibleAnswer3;
    string possibleAnswer4;

    int correctAnswer;

    void initialize();
};