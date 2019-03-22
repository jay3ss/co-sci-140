// This program uses the function nameSlice to cut the last
// name off of a string that contains the user's first and
// last names.
#include <iostream>
#include <cstring> // for use with cygwin
// #include <string> // for use with Visual Studio

using namespace std;

void nameSlice(char [], char [], char []); // Function prototype

int main()
{
   const int SIZE = 41;  // Array size
   char name[SIZE];      // To hold the user's name
    char firstName[SIZE];      // To hold the user's name
	char lastName[SIZE];

   cout << "Enter your first and last names, separated ";
   cout << "by a space:\n";
   cin.getline(name, SIZE);
   // strcpy(firstName, name);
  strcpy(lastName, name);
   nameSlice(name, firstName, lastName);
   cout << "Your first name is: " << firstName << endl;
   cout << "Your last name is: " << lastName << endl;
   system("pause");
   return 0;
}

//**************************************************************
// Definition of function nameSlice. This function accepts a   *
// character array as its argument. It scans the array looking *
// for a space. When it finds one, it replaces it with a null  *
// terminator.                                                 *
//**************************************************************

void nameSlice(char userName[], char firstName[], char lastName[])
{
   int count = 0;  // Loop counter
  // firstName = lastName = userName; 

   // Locate the first space, or the null terminator if there
   // are no spaces.
   while (userName[count] != ' ' && userName[count] != '\0')
   {
      count++;
   }

   // If a space was found, replace it with a null terminator.
   if (userName[count] == ' ')
   {
      firstName[count] = '\0';
   }
   int i, x;
   for( i=count+1, x=0; userName[i] != '\0'; i++, x++)
	{
		lastName[x] = userName[i];
	}
   lastName[x] = '\0';
  
}