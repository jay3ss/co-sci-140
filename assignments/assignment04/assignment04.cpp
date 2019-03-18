#include <fstream>
#include <iostream>
#include <string>

#include "Question.h"

using namespace std;

// Function prototypes
void getOneQuestion(fstream &, string *, string[], int *, const int);
void getAllQuestions(fstream &, Question [], const int, const int);
void displayQuestion(Question *, const int);

int main()
{
    // Create the file stream object to read the trivia text file
    const string filename = "trivia.txt";
    fstream triviaFile(filename, ios::in);
    
    // Create a Question array of 10 elements
    const int NUM_QUESTIONS = 10;
    const int NUM_ANSWERS = 4;
    Question questions[NUM_QUESTIONS];

    // Populate the Question array with the data from the trivia file
    getAllQuestions(triviaFile, questions, NUM_QUESTIONS, NUM_ANSWERS);

    // Create the players and prompt them for their answers for the quiz
    int playersPoints[] = {0, 0};
    int playerNumber = 1;
    const int NUM_PLAYERS = 2;

	int playerChoice = 1;
    
    for (int i = 0; i < NUM_QUESTIONS; i++)
    {
		playerNumber = i % NUM_PLAYERS;
        cout << "Question for PLAYER " << (playerNumber + 1)
			 << "\n----------------------\n";
        displayQuestion(&questions[i], NUM_ANSWERS);
		
		cout << "Enter the correct answer: ";
		cin >> playerChoice;
		
		if (questions[i].checkAnswer(playerChoice))
		{
			cout << "Correct!\n\n";
			playersPoints[playerNumber]++;
		}
		else
		{

			cout << "Sorry, that's incorrect. The correct answer is "
				 << questions[i].getCorrectAnswerNum() << ". "
				 << questions[i].getCorrectAnswerText() << "\n\n";
		}
    }

	cout << "Game over. Here are the points:"
		 << "\nPLAYER 1: " << playersPoints[0]
		 << "\nPLAYER 1: " << playersPoints[1]
		 << endl;

	cout << endl;
	if (playersPoints[0] > playersPoints[1])
	{
		cout << "PLAYER 1 WINS!";
	}
	else if (playersPoints[0] < playersPoints[1])
	{
		cout << "PLAYER 2 WINS!";
	}
	else
	{
		cout << "IT'S A TIE!";
	}
	cout << endl;

	system("pause");
    return 0;
}

// Function that gets all of the questions from the trivia text file and
// populates a Question array with the data from the text file.
// Args:
// file:    fstream object that is parsed. It is expected to have the following
//          format:
//          Question text (string)
//          Possible answer 1 (string)
//          Possible answer 2 (string)
//          ...
//          Possible answer n (string) where n is the number given by the numAns
//          argument
//          Correct answer  (string to be converted to an int)
// qs:      The array of Question obejcts
// size:    The length of the qs array
// numAns:  The number of possible answers
// Returns:
// Nothing
void getAllQuestions(fstream &file, Question qs[], const int size, const int numAns)
{
    string qText;
    string strArr[4];
    int ansNum;

    // Go through each question in the Question array and populate
    // each question with the data from the trivia file
    for (int i = 0; i < size; i++)
    {
        getOneQuestion(file, &qText, strArr, &ansNum, numAns);
        qs[i].setQuestionText(qText);
        qs[i].setPossibleAnswers(strArr);
        qs[i].setCorrectAnswer(ansNum);
    }
}

// Function that grabs one a question at a time from the trivia text file
// Args:
// file:    fstream object that is parsed. It is expected to have the following
//          format:
//          Question text (string)
//          Possible answer 1 (string)
//          Possible answer 2 (string)
//          ...
//          Possible answer n (string) where n is the number given by the size
//          argument
//          Correct answer  (string to be converted to an int)
// qText:   This will hold the question text
// strArr:  This will hold the the possible questions
// ansNum:  This will hold the number of the correct answer
// size:    The number of possible answers
// Returns:
// Nothing
void getOneQuestion(fstream &file, string *qText, string strArr[], 
                    int *ansNum, const int size)
{

    // Read the question text and save it
    getline(file, *qText);

    // Read each and save each possible answer
    for (int i = 0; i < size; i++)
    {
        getline(file, strArr[i]);
    }

    // Get the correct answer and convert it from a string to an int
    string ansString;
    getline(file, ansString);

    *ansNum = atoi(ansString.c_str());
}

// Function that displays a question
// Args:
// ques:    Question object that's going to be displayed
// numAns:  The number of possible answers that a question has
// Returns:
// Nothing
void displayQuestion(Question *ques, const int numAns)
{
    // Get a pointer to the array that holds all of the possible answers
    // and display the question text
    string *pa = ques->getPossibleAnswers();
    cout << ques->getQuestionText() << endl;

    // Display all of the possible answers and number them as well
    for (int i = 0; i < numAns; i++)
    {
        cout << (i + 1) << ". " << pa[i] << endl;
    }
}