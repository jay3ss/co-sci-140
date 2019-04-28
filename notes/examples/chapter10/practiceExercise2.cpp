// Write a program that asks the user to enter a series of single digit
// numbers with nothing separating them. Read the input as a C-string or a
// string object. The program should display the sum of all the single-digit
// numbers in the string.
// 
// For example, if the user enters 2514, the program should display 12, which
// is the sum of 2, 5, 1, and 4. The program should also display the highest
// and lowest digits in the string.
#include <cctype>
#include <iostream>

using namespace std;

// Function prototypes

// Converts a char to an int
int charToInt(char);

int main()
{
    const int SIZE = 81;
    char intChar[SIZE];
    
    cout << "Enter an integer (less than or equal to "
         << (SIZE - 1) << " digits): ";
    cin.getline(intChar, SIZE);

    int lowest = charToInt(intChar[0]);
    int highest = charToInt(intChar[0]);
    int count = 0;
    int total = 0;

    int digit;

    while (intChar[count] != '\0')
    {
        digit = charToInt(intChar[count]);
        if (digit < lowest)
        {
            lowest = digit;
        }

        if (highest < digit)
        {
            highest = digit;
        }

        total += digit;
        count++;
    }

    cout << "The lowest digit is " << lowest << endl
         << "The highest digit is " << highest << endl
         << "The sum of all digits of " << intChar
         << " is " << total << endl;

    system("pause");
    
    return 0;
}

// Converts an char to an int. If a char representation on an int is not
// passed, then 0 is returned
int charToInt(char c)
{
    if (!isdigit(c))
    {
        return 0;
    }
    
    int digit = c - '0';
    return digit;
}