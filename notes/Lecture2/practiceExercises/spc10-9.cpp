// Chapter 10, Programming Challenge 9: Most Frequent Character
#include <iostream>
using namespace std;

// Constant for the array size
const int SIZE = 81;

// Function prototype
char mostFrequent(char *);

int main()
{
   char input[SIZE];   // Array to hold input
   
   // Get a string.
   cout << "Enter a string: ";
   cin.getline(input, SIZE);
   
   if (mostFrequent(input) == 0)
   {
	   cout << "No string was entered\n\n";
   }
   else
   {
	   // Display the most frequent character.
	   cout << "The most frequently-appearing character "
		    << "in that string is "
		    << mostFrequent(input) << endl;
   }

   return 0;
}

//**************************************************
// The mostFrequent function returns the character *
// that appears the most frequently in str.        *
//**************************************************

char mostFrequent(char *str)
{
   int i;      // Loop counter
   
   // Index of most frequently appearing char.
   int indexOfMostFreq;
   
   // Get the number of characters in str.
   int size = strlen(str);
      
   // Create an int array to hold the frequencies
   // of the characters in str.
   int *frequencies = new int[size];
      
   // Initialize each element of the frequencies array
   // to 0.
   for (i = 0; i < size; i++)
      frequencies[i] = 0;
      
   // Calculate the frequencies of each character.
   for (i = 0; i < size; i++)
   {
      for (int f = 0; f < size; f++)
      {
         if (str[f] == str[i])
            frequencies[i]++;
      }
   }
   
   // Find the most frequent character.
  indexOfMostFreq = 0;
   for (i = 1; i < size; i++)
   {
      if (frequencies[i] > frequencies[indexOfMostFreq])
         indexOfMostFreq = i;
   }
      
   // Return the most frequent character.
   return str[indexOfMostFreq];
}