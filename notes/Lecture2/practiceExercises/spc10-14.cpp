// Chapter 10, Programming Challenge 14: Word Separator
#include <iostream>
#include <string>
using namespace std;

// Prototype
string format(string);

int main()
{
    string input;	// To hold the user's input

    // Get a sentence from the user.
    cout << "Enter a sentence with no spaces between the words\n";
    cout << "and the first letter of each word capitalized.\n";
    cout << "Example: StopAndSmellTheRoses\n";
    cout << ": ";
    cin >> input;

    // Display the formatted sentence.
    cout << format(input) << endl;

    return 0;
}

// **********************************************************
// The format function seperates the words in the sentence  *
// and changes the first character of each word (except     *
// the first) to lowercase.                                 *
// **********************************************************
string format(string sentence)
{
    // The following loop steps through each character in
    // sentence, starting with the 2nd character.
    for (int i = 1; i < sentence.size(); i++)
    {
        // If this character is uppercase, then change it
        // to lower case and insert a space before it.
        if (isupper(sentence[i]))
        {
            // Change this character to lowercase.
            sentence[i] = tolower(sentence[i]);

            // Insert a space before this character.
            sentence.insert(i, " ");
        }
    }

    // Return the formatted result.
    return sentence;
}