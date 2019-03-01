#include <cstring>
#include <iostream>
#include <string>

using namespace std;

char *stringToCstring(string);
int numVowels(char *cstr);
bool isVowel(char letter);

int main()
{
    string myString = "Hello, this is a string";
    char *myCharPtr = nullptr;
    myCharPtr = &myString[0];
    int vowelCount = numVowels(myCharPtr);
    cout << "There are " << vowelCount << " vowels in that string.\n";
    
    // myCharPtr = stringToCstring(myString);

    // cout << "The length of myString is " << myString.length() << " characters\n";

    
    while (*myCharPtr != '\0')
    {
        cout << *myCharPtr;
        myCharPtr++;
    }

    // delete [] myCharPtr;
    // myCharPtr = 0;
    myCharPtr = nullptr;
    return 0;
}

char *stringToCstring(string str)
{
    int length = str.length() + 1;
    char *cstr = nullptr;
    cstr = new char[length];

    for (int i = 0; i < length-1; i++)
    {
        *(cstr + i) = str[i];
    }
    *(cstr + length) = '\0';

    return cstr;
}

int numVowels(char *cstr)
{
    int size = strlen(cstr);
    int vowelCount = 0;

    for (int i = 0; i < size; i++)
    {
        if (isVowel(cstr[i]))
        {
            vowelCount++;
        }
    }

    return vowelCount;
}

bool isVowel(char letter)
{
    const int NUM_VOWELS = 5;
    char vowels[NUM_VOWELS] = {'a', 'e', 'i', 'o', 'u'};
    letter = tolower(letter);

    // Check if letter matches with one of the characters in the vowels array
    // and immediately return true if it does (i.e., letter is a vowel).
    // Otherwise, return false if it doesn't match with any character in the
    // vowels array.
    for (int i = 0; i < NUM_VOWELS; i++)
    {
        if (letter == vowels[i])
        {
            return true;
        }
    }

    return false;
}
