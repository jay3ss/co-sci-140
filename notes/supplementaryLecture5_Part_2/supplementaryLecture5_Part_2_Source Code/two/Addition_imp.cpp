#include <iostream>
#include "Addition.h" 
#include <time.h>       /* time */
using namespace std;
int Addition::totalWrong = 0;
int Addition::totalRight = 0;

int Addition::getProblemCount()
{
	return ++problemCount;
}
void Addition::displayStats()
{
	cout << "Total right = " << totalRight << endl;
	cout << "Total wrong = " << totalWrong << endl;
}

void Addition::updateStats(int userResponse, int theAnswer)
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

void Addition::checkUserResponse(int userResponse, int theAnswer)
{
	if(userResponse == theAnswer)
	{
		cout << "correct!\n";
	}
	else
	{
		cout << "incorrect!\n";
	}
}


Addition::Addition()
{
  num1 = 0;
  num2 = 0;
  problemCount = 0;
}

int Addition::generateOperand()
{
		/* initialize random seed: */
  srand (time(NULL));

  /* generate secret numbers between 1 and 10: */
  return rand() % 10 + 1;
}