// Joshua Saunders
// CO SCI 140 (Section 15029) - Assignment 04
// Due March 17, 2019
// 
// Prompt:
// 
// - Starting with player 1, each player gets a turn at answering five trivia
//   questions. (There are a total of 10 questions.) When a question is
//   displayed, four possible answers are also displayed. Only one of the
//   answers is correct, and if the player selects the correct answer, he or
//   she earns a point.
// - After answers have been selected for all of the questions, the program
//   displays the number of points earned by each player and declares the
//   player with the highest number of points the winner.
// - The program must load the questions from a text file in to the array of
//   10 Question objects.
// 
// In this program, you will design a Question class to hold the data for a
// trivia question.
// 
// The Question class should have member variables for the following data:
// - A trivia question
// - Possible answer #1
// - Possible answer #2
// - Possible answer #3
// - Possible answer #4
// - The number of the correct answer (1, 2, 3, or 4)
// 
// The Question class should have appropriate constructor(s), accessor, and
// mutator functions.

// The program should create an array of 10 Question objects, one for each
// trivia question. Make up your own questions on the subject or subjects of
// your choice for the objects.
#include <fstream>
#include <iostream>
#include <string>

#include "Question.h"

using namespace std;
/*
 * Function prototypes
 */
// Function that grabs one a question at a time from the trivia text file
void getOneQuestion(fstream &, string *, string[], int *, const int);
// Function that gets all of the questions from the trivia text file and
// populates a Question array with the data from the text file.
void getAllQuestions(fstream &, Question [], const int, const int);
// Function that displays a question
void displayQuestion(Question *, const int);
// Determines the winner
int determineWinner(int, int);
// Prints the winner
void printWinner(int);

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
    int playerNumber = 0;
    const int NUM_PLAYERS = 2;

	int playerChoice = 0;
    
    for (int i = 0; i < NUM_QUESTIONS; i++)
    {
        // Let the players know whose turn it is and display the question
		playerNumber = i % NUM_PLAYERS;
        cout << "Question for PLAYER " << (playerNumber + 1)
			 << "\n----------------------\n";
        displayQuestion(&questions[i], NUM_ANSWERS);
		
        // Prompt the player for their choice
		cout << "Enter the correct answer: ";
		cin >> playerChoice;
		
        // Was the answer correct? If they're correct, tell them! If not, tell
        // them wha the correct answer is
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
		 << "\nPLAYER 2: " << playersPoints[1]
		 << endl;

	cout << endl;

    int winner = determineWinner(playersPoints[0], playersPoints[1]);

    printWinner(winner);

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

// Function that determine which player won.
// Args:
// player1:     Player 1's points
// player2:     Player 2's points
//
// Returns:
// 1:           If player 1 wins
// 2:           If player 2 wins
// 0:           If there's a tie
int determineWinner(int player1, int player2)
{
    if (player1 > player2)
    {
        return 1;
    }
    else if (player1 < player2)
    {
        return 2;
    }
    else
    {
        return 0;
    }
}

// Prints the winner
// Args:
// winner:  the number of the winner
// Returns:
// Nothing
void printWinner(int winner)
{
    switch (winner)
    {
    case 0:
        cout << "IT'S A TIE!";
        break;
    case 1:
        cout << "PLAYER 1 WINS!";
        break;
    case 2:
        cout << "PLAYER 2 WINS!";
        break;
    default:
        cout << "SOMETHING WENT WRONG...";
        break;
    }
    cout << endl;
}