//  Chapter 13, Programming Challenge 19: Trivia Game
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

// Question Class
class Question
{
    // Member variables
    private:
        // The trivia question
        string questionText;

        // An array to hold 4 possible answers.
        string possibleAnswers[4];

        // The number (1,2,3, or 4) of the
        // correct answer.
        int correctAnswer;
    
    // Member functions
    public:
        // Default constructor
        // (We will use the mutators to set the values of
        //  the member variables.)
        Question()
        { }

        // Accessors
        string getQuestion()
        {
            return questionText;
        }

        string getPossAnswer1()
        {
            return possibleAnswers[0];
        }

        string getPossAnswer2()
        {
            return possibleAnswers[1];
        }

        string getPossAnswer3()
        {
            return possibleAnswers[2];
        }

        string getPossAnswer4()
        {
            return possibleAnswers[3];
        }

        int getCorrectNumber()
        {
            return correctAnswer;
        }

        string getCorrectAnswer()
        {
            return possibleAnswers[correctAnswer-1];
        }

        // Mutators
        void setQuestionText(string q)
        {
            questionText = q;
        }

        void setPossAnswer1(string ans)
        {
            possibleAnswers[0] = ans;
        }

        void setPossAnswer2(string ans)
        {
            possibleAnswers[1] = ans;
        }

        void setPossAnswer3(string ans)
        {
            possibleAnswers[2] = ans;
        }

        void setPossAnswer4(string ans)
        {
            possibleAnswers[3] = ans;
        }

        void setCorrect(int correctNum)
        {
            correctAnswer = correctNum;
        }
};

// Function prototypes
void initQuestions(Question [], int);
void displayQuestion(Question);

int main()
{
    const int NUM_QUESTIONS = 10; // Number of questions
    int playerOnePoints = 0;      // Player 1's points
    int playerTwoPoints = 0;      // Player 2's points

    // Array of Question objects
    Question questions[NUM_QUESTIONS];

    // Initialize the array with data from the trivia.txt file.
    initQuestions(questions, NUM_QUESTIONS);

    // Play the game.
    int questionNum = 0;
    while (questionNum < 10)
    {
        int answer;   // To hold the player's answer

        // Player 1's turn.
        cout << "Question for PLAYER 1:\n";
        cout << "----------------------\n";
        displayQuestion(questions[questionNum]);
        cout << "Enter the correct answer: ";
        cin >> answer;

        // Score the answer.
        if (answer == questions[questionNum].getCorrectNumber())
        {
            cout << "Correct!\n\n";
            playerOnePoints++;
        }
        else
        {
            cout << "Sorry, that's incorrect. The correct answer is "
                 << questions[questionNum].getCorrectNumber() << ". "
                 << questions[questionNum].getCorrectAnswer()
                 << endl << endl;
        }

        // Increment the question number for player 2.
        questionNum++;

        // Player 2's turn.
        cout << "Question for PLAYER 2:\n";
        cout << "----------------------\n";
        displayQuestion(questions[questionNum]);
        cout << "Enter the correct answer: ";
        cin >> answer;

        // Score the answer.
        if (answer == questions[questionNum].getCorrectNumber())
        {
            cout << "Correct!\n\n";
            playerTwoPoints++;
        }
        else
        {
            cout << "Sorry, that's incorrect. The correct answer is "
                 << questions[questionNum].getCorrectNumber() << ". "
                 << questions[questionNum].getCorrectAnswer()
                 << endl << endl;
        }

        // Increment the question number for the next round.
        questionNum++;
    }

    // Show each player's points.
    cout << "Game over. Here are the points:\n";
    cout << "PLAYER 1: " << playerOnePoints << endl;
    cout << "PLAYER 2: " << playerTwoPoints << endl << endl;

    // Declare the winner.
    if (playerOnePoints > playerTwoPoints)
    {
        cout << "PLAYER 1 WINS!\n";
    }
    else if (playerTwoPoints > playerOnePoints)
    {
        cout << "PLAYER 2 WINS!\n";
    }
    else
    {
        cout << "It's a tie!\n";
    }

    return 0;
}

// The initQuestions function reads trivia question data
// from the file trivia.txt and stores it in the array
// of Question objects.

void initQuestions(Question quest[], int size)
{
   const int SIZE = 500;  // Size of input array
   char input[SIZE];      // To hold file input
   fstream inputFile;     // File stream object
   int index = 0;         // Array indexer

   // Open the file in input mode.
   inputFile.open("trivia.txt", ios::in);
   if (!inputFile)
   {
      cout << "ERROR: Cannot open trivia file.\n";
      exit(0);
   }

   // Read the file contents.
   inputFile.getline(input, SIZE); 
   while (!inputFile.eof() && index < size)
   {
        // Set the question text.
        quest[index].setQuestionText(input);

        // Read and store the first possible answer.
        inputFile.getline(input, SIZE);
        quest[index].setPossAnswer1(input);

        // Read and store the second possible answer.
        inputFile.getline(input, SIZE);
        quest[index].setPossAnswer2(input);

        // Read and store the third possible answer.
        inputFile.getline(input, SIZE);
        quest[index].setPossAnswer3(input);

        // Read and store the fourth possible answer.
        inputFile.getline(input, SIZE);
        quest[index].setPossAnswer4(input);

        // Read and store the number of the correct answer.
        inputFile.getline(input, SIZE);
        quest[index].setCorrect(atoi(input));

        // Increment index.
        index++;

        // Read the next question text.
        inputFile.getline(input, SIZE);
   }
}

// The displayQuestion function displays a trivia question.

void displayQuestion(Question quest)
{
    cout << quest.getQuestion() << endl;
    cout << "ANSWERS:\n";
    cout << "1. " << quest.getPossAnswer1() << endl;
    cout << "2. " << quest.getPossAnswer2() << endl;
    cout << "3. " << quest.getPossAnswer3() << endl;
    cout << "4. " << quest.getPossAnswer4() << endl;
}