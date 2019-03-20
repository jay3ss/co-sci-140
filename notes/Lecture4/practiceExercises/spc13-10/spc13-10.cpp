// Chapter 13, Programming Challenge 10: Number Array Class
#include <iostream>
#include "NumberArray.h"
using namespace std;

int main()
{
   int howMany;   // The number of numbers
   int count;     // Loop counter
   double val;    // To hold a value

   // Get the number of numbers to store.
   cout << "How many numbers do you want to store? ";
   cin >> howMany;
   
   // Create a NumberArray object.
   NumberArray numbers(howMany);
   
   // Get the numbers.
   cout << "\nEnter the " << howMany << " numbers:\n";
   for (count = 0; count < howMany; count++)
   {
      // Get a number.
      cout << "\tNumber " << (count+1) << ": ";
      cin >> val;
      
      // Store it in the object.
      numbers.setCell(count, val);
   }

   // Display the values in the object.
   cout << "\n---------------------------------\n";
   cout << "\nHere are the numbers you entered:\n";
   for (count = 0; count < howMany; count++)
   {
      cout << "Number " << (count+1) << ": "
           << numbers.getCell(count)
           << endl;
   }
   
   // Display the average of the values.
   cout << "\n---------------------------------\n";
   cout << "The average of those numbers is: ";
   cout << numbers.getAverage() << endl;

   // Display the highest of the values.
   cout << "The highest of those numbers is: ";
   cout << numbers.getHighest() << endl;

   // Display the lowest of the values.
   cout << "The lowest  of those numbers is: ";
   cout << numbers.getLowest() << endl << endl;

   return 0;
}