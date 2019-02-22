// Chapter 10, Programming Challenge 12: Password Verifier
#include <iostream>
using namespace std;

// Global constants
const int SIZE = 80; // The maximum size of the array
const int MIN = 6;   // The minimum number characters

// Function prototypes
void displayRequirements();
void displayResult(char[]);
bool isValid(char[]);
bool hasLength(char[]);
bool hasLower(char[]);
bool hasUpper(char[]);
bool hasDigit(char[]);

int main()
{
   char cstring[SIZE];  // To hold the password

   // Display the password requirements.
   displayRequirements();

   // Get the password as input from the user.
   cout << "Enter a password: ";
   cin.getline(cstring, SIZE);

   // Display a message indicating whether
   // or not the password is valid.
   displayResult(cstring);

   return 0;
}

//*************************************************
// The displayRequirements function displays the  *
// requirments needed for a valid password.       *
//*************************************************
void displayRequirements()
{
   // Display the password requirements.
   cout << "Password Requirments:\n"
        << "  - The password should be at least "
        << MIN << " characters long.\n"
        << "  - The password should contain at least one uppercase\n"
        << "    and at least one lowercase letter.\n"
        << "  - The password should have at least one digit.\n\n";
}

//*************************************************
// The displayResult function displays a message  *
// indicating whether or not the password is      *
// valid. If the password is invalid, additional  *
// messages are displayed for each failed         *
// requirment.                                    *
//*************************************************
void displayResult(char str[])
{
   // Determine if password is valid.
   if (isValid(str))
   {
      // If so, display a message indicating that the
      // password is valid.
      cout << "The password is valid.\n";
   }
   else
   {
      // If not, display a message indicating that the
      // password is not valid.
      cout << "The password is invalid.\n";

      // Determine if the length of the string is invalid.
      if (!hasLength(str))
      {
         // If so, display a message indicating that the
         // password failed to meet the length requirment.
         cout << "It should be at least "
              << MIN << " characters long.\n";
      }
      // Determine if the string did not contain a lowercase
      // character.
      if (!hasLower(str))
      {
         // If so, display a message indicating that the
         // password failed to meet the lowercase requirment.
         cout << "It should contain at least "
              << "one lowercase letter.\n";
      }
      // Determine if the string did not contain an uppercase
      // character.
      if (!hasUpper(str))
      {
         // If so, display a message indicating that the
         // password failed to meet the uppercase requirment.
         cout << "It should contain at least "
              << "one uppercase letter.\n";
      }
      // Determine if the string did not contain a digit
      // character.
      if (!hasDigit(str))
      {
         // If so, display a message indicating that the
         // password failed to meet the digit requirment.
         cout << "It should have at least one digit.\n";
      }
   }
}

//*************************************************
// The isValid function returns true if the       *
// string meets all of the requirements of a      *
// valid password. Otherwise it returns false.    *
//*************************************************
bool isValid(char str[])
{
   bool status = false; // The status flag, set to false

   // Determine if the string meets the requirements for a
   // valid password.
   if ( hasLength(str) &&
        hasLower(str)  &&
        hasUpper(str)  &&
        hasDigit(str) )
   {
      // If so, set the status to true.
      status = true;
   }

   // Return the status.
   return status;
}

//*************************************************
// The hasLength function returns true if the     *
// string contains the minimum amount of          *
// characters. Otherwise, it returns false.       *
//*************************************************
bool hasLength(char str[])
{
   bool status = false; // The status flag, set to false
   int count = 0;       // To count the number of characters

   // Count each character in the string until the
   // null terminator is reached.
   while (*str != '\0')
   {
      // Increment the counter variable.
      count++;

      // Go to the next character.
      *str++;
   }

   // Determine if the character counter
   // variable is greater-than or equal-to the
   // minimum number of characters.
   if (count >= MIN)
   {
      // If so, set the status to true.
      status = true;
   }

   // Return the status.
   return status;
}

//*************************************************
// The hasLower function returns true if the      *
// string contains at least one lowercase         *
// character. Otherwise, it returns false.        *
//*************************************************
bool hasLower(char str[])
{
   bool status = false; // The status flag, set to false
   int count = 0;       // To count lowercase characters

   // Test each character until the null terminator
   // is reached or a lowercase character is found.
   while (*str != '\0' && count == 0)
   {
      // Determine if this character is lowercase.
      if (islower(*str))
      {
         // If so, increment the counter variable.
         count++;
      }
      else
      {
         // If not, go to the next character.
         *str++;
      }
   }

   // Determine if the lowercase character counter
   // variable is greater than zero.
   if (count > 0)
   {
      // If so, set the status to true.
      status = true;
   }

   // Return the status.
   return status;
}

//*************************************************
// The hasUpper function returns true if the      *
// string contains at least one uppercase         *
// character. Otherwise, it returns false.        *
//*************************************************
bool hasUpper(char str[])
{
   bool status = false; // The status flag, set to false
   int count = 0;       // To count uppercase characters.

   // Test each character until the null terminator
   // is reached or an uppercase character is found.
   while (*str != '\0' && count == 0)
   {
      // Determine if this character is uppercase.
      if (isupper(*str))
      {
         // If so, increment the counter variable.
         count++;
      }
      else
      {
         // If not, go to the next character.
         *str++;
      }
   }

   // Determine if the uppercase character
   // counter variable is greater than zero.
   if (count > 0)
   {
      // If so, set the status to true.
      status = true;
   }

   // Return the status.
   return status;
}

//*************************************************
// The hasDigit function returns true if the      *
// string contains at least one digit             *
// character. Otherwise, it returns false.        *
//*************************************************
bool hasDigit(char str[])
{
   bool status = false; // The status flag, set to false
   int count = 0;       // To count digit characters.

   // Test each character until the null terminator
   // is reached or a digit character is found.
   while (*str != '\0' && count == 0)
   {
      // Determine if this character is a digit.
      if (isdigit(*str))
      {
         // If so, increment the counter variable.
         count++;
      }
      else
      {
         // If not, go to the next character.
         *str++;
      }

   }

   // Determine if the digit character counter
   // variable is greater than zero.
   if (count > 0)
   {
      // If so, set the status to true.
      status = true;
   }

   // Return the status.
   return status;
}