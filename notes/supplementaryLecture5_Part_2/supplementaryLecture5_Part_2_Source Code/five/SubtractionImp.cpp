#include <iostream>
#include "Subtraction.h" 
#include <time.h>       /* time */
using namespace std;
int Subtraction::totalWrong = 0;
int Subtraction::totalRight = 0;
int Subtraction::problemCount = 0;

int Subtraction::getProblemCount()
{
	return problemCount;
}
void Subtraction::displayStats()
{
	cout << "Total right = " << totalRight << endl;
	cout << "Total wrong = " << totalWrong << endl;
}

void Subtraction::checkUserResponse(int userResponse)
{
	if(userResponse == getDifference())//this is overkill---I could have just used--> userResponse == theAnswer
	{
			cout << "correct!\n";
	}
	else
	{
			cout << "incorrect!\n";
	}
}
void Subtraction::updateStats(int userResponse)
{
	if(userResponse == theAnswer)
	{
		totalRight +=1;
	}
	else
	{
		totalWrong += 1;
	}
}
Subtraction::Subtraction()
{
	/* initialize random seed: */
  srand (time(NULL));

  /* generate secret numbers between 1 and 10: */
  num1 = rand() % 10 + 1;
  num2 = rand() % 10 + 1;
  theAnswer = (num1 + num2) - num2;
  problemCount++;
}

Subtraction::Subtraction(int& number1, int& number2)
{
	/* initialize random seed: */
  srand (time(NULL));

  /* generate secret numbers between 1 and 10: */
  num1 = rand() % 10 + 1;
  num2 = rand() % 10 + 1;
  theAnswer = (num1 + num2) - num2;
  number1 = num1;
  number2 = num2;
  problemCount++;
}
int Subtraction::getDifference()
{
	return theAnswer;
}
void Subtraction::randomize(int& number1, int& number2)
{
		/* initialize random seed: */
  srand (time(NULL));

  /* generate secret numbers between 1 and 10: */
  num1 = rand() % 10 + 1;
  num2 = rand() % 10 + 1;
  theAnswer = (num1 + num2) - num2;
  number1 = num1;
  number2 = num2;
}