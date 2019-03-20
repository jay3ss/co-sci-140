// Implementation file for the NumberArray class
#include <iostream>
#include "NumberArray.h"
using namespace std;

//********************************************
// Constructor                               *
//********************************************

NumberArray::NumberArray(int s)
{
	arrayPointer = nullptr;
	arrayPointer = new double[s];
	size = s;
}

//********************************************
// Destructor                                *
//********************************************

NumberArray::~NumberArray()
{
	if (arrayPointer != nullptr)
	{
		delete[] arrayPointer;
		arrayPointer = nullptr;
	}
}

//********************************************
// setCell member function                   *
//********************************************

void NumberArray::setCell(int c, double val)
{
   if (arrayPointer != nullptr && c >= 0 && c <= size)
       arrayPointer[c] = val;
   else
   {
      cout << "Invalid cell number.\n";
      exit(EXIT_FAILURE);
   }
}

//********************************************
// getCell member function                   *
//********************************************

int NumberArray::getCell(int cellNum)
{
   if (cellNum < 0 || cellNum > size)
   {
      cout << "Invaild cell number.\n";
      exit(EXIT_FAILURE);
   }

   return arrayPointer[cellNum];
}

//********************************************
// getAverage member function                *
//********************************************

double NumberArray::getAverage()
{
   double total = 0;

   for (int count = 0; count < size; count++)
   {
	   total += arrayPointer[count];
   }
      
   return total / size;
}

//********************************************
// getHighest member function                *
//********************************************

double NumberArray::getHighest()
{
	double highest = arrayPointer[0];

	for (int count = 1; count < size; count++)
	{
		if (arrayPointer[count] > highest)
		{
			highest = arrayPointer[count];
		}
	}

	return highest;
}

//********************************************
// getLowest member function                 *
//********************************************

double NumberArray::getLowest()
{
	double lowest = arrayPointer[0];

	for (int count = 1; count < size; count++)
	{
		if (arrayPointer[count] < lowest)
		{
			lowest = arrayPointer[count];
		}
	}

	return lowest;
}