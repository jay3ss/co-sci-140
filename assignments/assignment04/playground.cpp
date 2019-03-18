#include <fstream>
#include <iostream>
#include <string>

#include "Question.h"
#include "Quiz.h"

using namespace std;

void getOneQuestion(fstream &, string *, string[], int *);

int main()
{
    const int NUM_QUESTIONS = 10;
    Question questions[NUM_QUESTIONS];

    string answers[4] = {
        "This is 1",
        "This is 2",
        "This is 3",
        "This is 4"
    };

    // for (int i = 0; i < 4; i++)
    // {
    //     question.setPossibleAnswer(answers[i], i);
    // }
    // question.setPossibleAnswers(answers);

    // string* pa = question.getPossibleAnswers();

    // for (int i = 0; i < 4; i++)
    // {
    //     cout << pa[i] << endl;
    // }

    const string filename = "../trivia.txt";
    fstream triviaFile(filename, ios::in);

    string line = "";
    int lineCount = 0;
    int operation;
    int blah = 6;
    string lineType;
    int idx = 0;
    // while (getline(triviaFile, line))
    // {
    //     // cout << endl;
    //     // operation = lineCount % blah;
    //     switch (operation)
    //     {
    //         case 0:
    //             lineType = ": question text\n"; 
    //             break;
    //         case 1:
    //         case 2:
    //         case 3:
    //         case 4:
    //             lineType = ": possible answer\n";
    //             break;
    //         case 5:
    //             lineType = ": correct answer\n";
    //             break;
    //         default:
    //             break;
    //     }
    //     // line += lineType;
    //     cout << line;
    //     // cout << lineType;
    //     cout << endl;
    //     questions[idx].setPossibleAnswers();
    //     lineCount++;
    // }

    string qText;
    string strArr[4];
    int ansNum;

    for (int i = 0; i < NUM_QUESTIONS; i++)
    {
        getOneQuestion(triviaFile, &qText, strArr, &ansNum);
        questions[i].setQuestionText(qText);
        questions[i].setPossibleAnswers(strArr);
        questions[i].setCorrectAnswer(ansNum);
    }

    qText = "";
    string *pa;
    ansNum = -1;

    cout << "Here are all of the trivia questions";
    for (int i = 0; i < NUM_QUESTIONS; i++)
    {
        cout << endl << endl;
        cout << questions[i].getQuestionText() << endl;
        pa = questions[i].getPossibleAnswers();
        for (int j = 0; j < 4; j++)
        {
            cout << pa[j] << endl;
        }
        cout << "The correct answer is "
             << questions[i].getCorrectAnswer();
    }
    
    //  = questions[i].getPossibleAnswers();

    // cout << endl
    //      << "The following info was gathered from the trivia file:\n\n"
    //      << "Question text: " << qText << endl
    //      << "Possible answers:\n"
    //      << "\t1. " << strArr[0] << endl
    //      << "\t2. " << strArr[1] << endl
    //      << "\t3. " << strArr[2] << endl
    //      << "\t4. " << strArr[3] << endl
    //      << "\nCorrect answer: " << ansNum << endl;

    return 0;
}

void getOneQuestion(fstream &file, string *qText, string strArr[], int *ansNum)
{
    int NUM_QUESTIONS = 4;
    getline(file, *qText);

    for (int i = 0; i < NUM_QUESTIONS; i++)
    {
        getline(file, strArr[i]);
    }

    string ansString;
    getline(file, ansString);

    *ansNum = atoi(ansString.c_str());
}