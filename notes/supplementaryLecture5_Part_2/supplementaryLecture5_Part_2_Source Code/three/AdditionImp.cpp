#include <iostream>
#include "Addition.h" 
#include <time.h>       /* time */
using namespace std;
int Addition::totalWrong = 0;
int Addition::totalRight = 0;

void Addition::displayStats()
{
	cout << "Total right = " << totalRight << endl;
	cout << "Total wrong = " << totalWrong << endl;
}

void Addition::checkUserResponse(int userResponse)
{
	if(userResponse == getSum())//this is overkill---I could have just used--> userResponse == theAnswer
	{
			cout << "correct!\n";
	}
	else
	{
			cout << "incorrect!\n";
	}
}

void Addition::updateStats(int userResponse)
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

Addition::Addition()
{
	/* initialize random seed: */
  srand (time(NULL));

  /* generate secret numbers between 1 and 10: */
  num1 = rand() % 10 + 1;
  num2 = rand() % 10 + 1;
  theAnswer = num1 + num2;
}

Addition::Addition(int& number1, int& number2)
{
	/* initialize random seed: */
  srand (time(NULL));

  /* generate secret numbers between 1 and 10: */
  num1 = rand() % 10 + 1;
  num2 = rand() % 10 + 1;
  theAnswer = num1 + num2;
  number1 = num1;
  number2 = num2;
}
int Addition::getSum()
{
	return theAnswer;
}
void Addition::randomize(int& number1, int& number2)
{
		/* initialize random seed: */
  srand (time(NULL));

  /* generate secret numbers between 1 and 10: */
  num1 = rand() % 10 + 1;
  num2 = rand() % 10 + 1;
  theAnswer = num1 + num2;
  number1 = num1;
  number2 = num2;
}