// Chapter 10, Programming Challenge 8: Sum of Digits in a String
#include <iostream>
#include <cctype>
using namespace std;

// Function prototypes
int charToInt(char);

int main()
{
   // Constant for array size
   const int SIZE = 81;
   
   char input[SIZE]; // Array to hold the input.
   int total = 0;    // Accumulator
   int digit;        // To hold a digit
   int highest;      // To hold the highest digit
   int lowest;       // To hold the lowest digit
   
   // Get input from the user.
   cout << "Enter a series of digits with no "
        << "spaces between them.\n";
   cin.getline(input, SIZE);

   // Pass the first character to charToInt to convert
   // it to an integer. Assign the return value to
   // to the digit variable.
   digit = charToInt(input[0]);

   // Assign digit to total to start the accumulator.
   total = digit;

   // So far the first digit is the highest and the
   // lowest value in the series.
   highest = digit;
   lowest = digit;
   
   // Convert each remaining character to a digit,
   // accumulate a sum of the digits, and test for
   // highest and lowest.
   for (int count = 1; count < strlen(input); count++)
   {
      // Pass the character to charToInt to convert
      // it to an integer. Assign the return value to
      // to the digit variable.
      digit = charToInt(input[count]);
      
      // Add digit to the accumulator.
      total += digit;
      
      // Is this the highest so far?
      if (digit > highest)
         highest = digit;
         
      // Is this the lowest so far?
      if (digit < lowest)
         lowest = digit;
   }
   
   // Display the results.
   cout << "The sum of those digits is "
        << total << endl;
   cout << "The highest digit is "
        << highest << endl;
   cout << "The lowest digit is "
        << lowest << endl;
        
   return 0;
}
   
//************************************************
// The charToInt function accepts a char and     *
// returns the char's value as an integer digit. *
// If the char is not a digit, the function      *
// returns 0.                                    *
//************************************************

int charToInt(char ch)
{
   int value;  // The value to return
   
   // Make sure ch is a digit. If so,
   // convert it to an int and return that value.
   if (isdigit(ch))
   {
      // Define an array to hold a temporary string
      // Initialize the elements to null.
      char tempStr[] = { '\0', '\0' };
               
      // Store char in element 0. This
      // will make a string.
      tempStr[0] = ch;
      
      // Convert the temporary string to an int
      // and assign to value.
      value = atoi(tempStr);
   }
   else  // If ch is not a digit, return 0.
      value = 0;
   
   return value;
}