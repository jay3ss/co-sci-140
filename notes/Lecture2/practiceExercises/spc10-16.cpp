// Chapter 10, Programming Challenge 16: Pig Latin
#include <iostream>
#include <string>
using namespace std;

// Prototypes
string leftTrim(string);
string popWord(string &);
string toPigLatin(string);

int main()
{
    string str;        // To hold the user's input
    string pig = "";   // To hold the translated string

    // Get a sentence from the user.
    cout << "Enter a sentence and I will translate it to Pig Latin.\n";
    cout << "-> ";
    getline(cin, str);

    // Translate each word and create a new string.
    while (str.size() > 0)
    {
        // Get the next word from the string.
        string word = popWord(str);

        // Translate the word to Pig Latin.
        word = toPigLatin(word);

        // Add the word and a space to the pig string.
        pig = pig + word + " ";
    }

    // Display the translated sentence.
    cout << pig << endl;

    return 0;
}

// *************************************************
// The leftTrim function accepts a string argument *
// and returns that same argument with any leading *
// spaces removed.                                 *
// *************************************************
string leftTrim(string str)
{
    while (str[0] == ' ')
    {
        // Erase 1 character at index 0.
        str.erase(0, 1);
    }
    return str;
}

// *************************************************
// The popWord function accepts a string argument, *
// passed by reference. It removes the first word  *
// from the string and then returns that word.     *
// *************************************************
string popWord(string &sentence)
{
    // Trim any spaces from the beginning of the string.
    sentence = leftTrim(sentence);

    // Locate the first space, or the end of the string.
    int index = 0;
    while (sentence[index] != ' ' && index < sentence.size())
        index++;

    // Copy the substring from the beginning of sentence
    // up to index, and store the copy in word.
    string word = sentence.substr(0, index);

    // Remove the word from sentence.
    sentence.erase(0, index);

    // Return the extracted word.
    return word;
}

// *************************************************
// The toPigLatin function accepts a string        *
// containing a word. It returns that word         *
// translated to Pig Latin.                        *
// *************************************************
string toPigLatin(string word)
{
    // Get the first letter of the word.
    char first = word[0];

    // Append the letter to the end of the word.
    word.append(1, first);

    // Append "ay" to the word.
    word.append("ay");

    // Delete the first letter.
    word.erase(0, 1);

    // Return the word.
    return word;
}