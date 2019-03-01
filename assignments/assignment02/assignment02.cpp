// Joshua Saunders
// CO SCI 140 (Section 15029) - Assignment 02
// Due March 3, 2019
//
// Prompt:
// Write a function that accepts a pointer to a C-string as its argument. The
// function should count the number of vowels appearing in the string and return
// that number. Write another function that accepts a pointer to a C-string as its
// argument. This function should count the number of consonants appearing in the
// string and return that number.
//
//      Demonstrate these two functions in a program that performs the following
//      steps:
//
//     1. The user is asked to enter a string.
//     2. The program displays the following menu:
//         A) Count the number of vowels in the string
//         B) Count the number of consonants in the string
//         C) Count both the vowels and consonants in the string
//         D) Enter another string
//         E) Exit the program
//     3. The program performs the operation selected by the user and repeats
//        until the last user selects E to exit the program.
#include <cctype>
#include <cstring>
#include <iostream>
#include <string>

using namespace std;

/*
 * FUNCTION PROTOTYPES:
 */
// Function that counts the number of vowels in a string. A vowel is defined
// as an element of the set {a, e, i, o, u}. Every other character is
// considered to be a consonant including white spaces like "TAB", "SPACE BAR",
// digits, and special characters.
int numVowels(char *);

// Function that counts the number of consonants in a string. A vowel is
// defined as an element of the set {a, e, i, o, u}. Every other character is
// considered to be a consonant including white spaces like "TAB", "SPACE BAR",
// digits, and special characters.
int numConsonants(char *);

// Function that determines if a letter is a vowel or not. A vowel is defined
// as an element of the set {a, e, i, o, u}. Every other character is
// considered to be a consonant including white spaces like "TAB", "SPACE BAR",
// digits, and special characters.
bool isVowel(char);

// Function that checks if the option chosen by the user is a valid one.
// NOTE: This does NOT include the option to quit the program ('e').
bool isValidOption(char option);

int main()
{
    const int SIZE = 4097;
    char stringToCount[SIZE];

	// Strings for printing messages to the console
	// menuOptions:       holds the menu
	// enterStringPrompt: holds the prompt for the user to enter a string
	// optionPrompt:      holds the prompt for the user to enter a menu option
	// invalidOptionMsg:  holds a message indicating that the user entered an
	//					  invalid option
    string menuOptions = "\
\tA) Count the number of vowels in the string\n\
\tB) Count the number of consonants in the string\n\
\tC) Count both the vowels and consonants in the string\n\
\tD) Enter another string\n\
\tE) Exit the program\n\n";
    string enterStringPrompt = "Enter a string: ";
    string optionPrompt = "\tEnter A, B, C, D, or E.\n";
    string invalidOptionMsg = "\tEnter ONLY A, B, C, D, or E.\n";

    cout << enterStringPrompt;
    cin.getline(stringToCount, SIZE);
    char option = ' ';

	while (option != 'e')
	{
		if (option != 'e')
		{
			cout << menuOptions;
			cout << optionPrompt;
			cin >> option;
			cin.ignore();
			option = tolower(option);
		}

        if (!isValidOption(option) && option != 'e')
        {
            // Invalid option
            // Prompt the user to input anoter option again
            cout << invalidOptionMsg;
            cin >> option;
            cin.ignore();
            option = tolower(option);
        }

		switch (option)
		{
			case 'a':
                // Count the number of vowels in the string
                cout << "The string has " << numVowels(stringToCount)
					 << " vowels.\n";
				break;
			case 'b':
                // Count the number of consonants in the string
                cout << "The string has " << numConsonants(stringToCount)
					 << " consonants.\n";
				break;
			case 'c':
                // Count the number of vowels AND consonants in the string
				cout << "The string has " << numVowels(stringToCount) 
                     << " vowels and " << numConsonants(stringToCount)
					 << " consonants.\n";
				break;
			case 'd':
                // Enter a new string
				cout << enterStringPrompt;
				cin.getline(stringToCount, SIZE);
				cout << "\n";
				break;
			case 'e':
                // Exit the program
				// Print goodbye message
	            cout << "Goodbye!\n";
				break;
			default:
                // // Invalid option
                // // Prompt the user to input anoter option again
                // cout << invalidOptionMsg;
				// cin >> option;
				// cin.ignore();
                // option = tolower(option);
                break;
		}
	}

    system("pause");
    return 0;
}

// Function that counts the number of vowels in a string. A vowel is defined
// as an element of the set {a, e, i, o, u}. Every other character is
// considered to be a consonant including white spaces like "TAB", "SPACE BAR",
// digits, and special characters.
// Args:
// cstr (pointer):  a pointer to a C-string
//
// Returns: the number of vowels in the C-string pointed to by cstr
int numVowels(char *cstr)
{
    // int size = strlen(cstr);
    int vowelCount = 0;

    while (*cstr != '\0')
    {
        if (isVowel(*cstr))
        {
            vowelCount++;
        }
        cstr++;
    }

    // for (int i = 0; i < size; i++)
    // {
    //     if (isVowel(cstr[i]))
    //     {
    //         vowelCount++;
    //     }
    // }

    return vowelCount;
}

// Function that counts the number of consonants in a string. A vowel is
// defined as an element of the set {a, e, i, o, u}. Every other character is
// considered to be a consonant including white spaces like "TAB", "SPACE BAR",
// digits, and special characters.
// Args:
// cstr (pointer):  a pointer to a C-string
// 
// Returns: the number of consonants in the C-string pointed to by cstr
int numConsonants(char *cstr)
{
    // int vowelCount = numVowels(cstr);
    // int consonantCount = strlen(cstr) - vowelCount;
    // return consonantCount;
    return strlen(cstr) - numVowels(cstr);
}

// Function that determines if a letter is a vowel or not. A vowel is defined
// as an element of the set {a, e, i, o, u}. Every other character is
// considered to be a consonant including white spaces like "TAB", "SPACE BAR",
// digits, and special characters.
// Args:
// letter (char): an ASCII character
//
// Returns:
// true:    if letter is a member of the set {a, e, i, o, u}
// false:   otherwise
bool isVowel(char letter)
{
    char vowels[] = "aeiou";
    letter = tolower(letter);

    // Check if letter matches with one of the characters in the vowels array
    // and immediately return true if it does (i.e., letter is a vowel).
    // Otherwise, return false if it doesn't match with any character in the
    // vowels array.
    int i = 0;
    while(vowels[i] != '\0')
    {
        if (letter == vowels[i])
        {
            return true;
        }
        i++;
    }

    return false;
}

// Function that checks if the option chosen by the user is a valid one.
// NOTE: This does NOT include the option to quit the program ('e').
// Args:
// option (char): a menu option inputted by the user
// 
// Returns:
// true:    if option is in the set {a, b, c, e}
// false    otherwise
bool isValidOption(char option)
{
    if (option == 'a' || option == 'b' ||
        option == 'c' || option == 'd')
    {
        return true;
    }

    return false;
}
