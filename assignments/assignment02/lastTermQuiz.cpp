#include <cctype>
#include <cstring>
#include <iostream>

using namespace std;

/******************************************************************************
* Declarations
******************************************************************************/

/**
 * Prompts the user to input any sequence of characters and returns that input.
 *
 * @return              the user's input as a C string
 */
char *getInput();

/**
 * Appends a character to the end of a C string.
 *
 * @param   c           the character to be appended
 * @param   cstring     a pointer to the C string to which to append
 */
void appendChar(char c, char **cstring);

/**
 * Searches for given characters in a C string and returns their frequencies.
 * Returns nullptr if all frequencies are 0.
 *
 * @param   cstring     the C string to search
 * @param   chars       a C string of chars for which to search
 * @return              an array of ints representing the frequency for each
 *                      char in the same order as chars
 */
int *getFreqsChars(char *cstring, const char *chars);

/**
 * Prints the given characters and their frequency as a list. Prints the
 * character with the highest frequency on a separate line.
 *
 * If two or more characters share the highest frequency, a message
 * indicating a lack of a highest frequency is printed instead.
 *
 * @param   chars       a char array of chars to print
 * @param   freqs       an int array of frequencies for chars
 */
void printCharsFreqs(const char *chars, const int *freqs);

/******************************************************************************
* Definitions
******************************************************************************/

int main()
{
    char cont = 0;

    do
    {
        char *input = getInput();
        const char lowerVowels[] = {'a', 'e', 'i', 'o', 'u'};
        const char upperVowels[] = {'A', 'E', 'I', 'O', 'U'};
        const int *lowerFreqs = getFreqsChars(input, lowerVowels);
        const int *upperFreqs = getFreqsChars(input, upperVowels);
        delete[] input;

        if (lowerFreqs == nullptr)
        {
            cout << "\nLower-case vowels present: none" << endl;
        }
        else
        {
            cout << "\nLower-case vowels present: ";
            printCharsFreqs(lowerVowels, lowerFreqs);
            delete[] lowerFreqs;
        }

        if (upperFreqs == nullptr)
        {
            cout << "\nUpper-case vowels present: none" << endl;
        }
        else
        {
            cout << "\nUpper-case vowels present: ";
            printCharsFreqs(upperVowels, upperFreqs);
            delete[] upperFreqs;
        }

        cout << "\nEnter [q/Q] to quit or any other character to input a new "
                "sequence: ";
        cin.get(cont);

        while (cin.get() != '\n')
        {             // Ignores all following characters.
            cont = 0; // Continues if > 1 char entered.
        }

        cout << endl;
    } while (tolower(cont) != 'q');

    return 0;
}

char *getInput()
{
    cout << "Enter any sequence of characters: ";
    char c = cin.get();

    while (isspace(c) && c != ' ')
    {
        cout << endl
             << "Nothing was entered. Please try again: ";
        cin.get(c);
    }

    char *input = new char[2]{c, '\0'};
    cin.get(c);

    while (c != '\n')
    {
        appendChar(c, &input);
        cin.get(c);
    }

    return input;
}

void appendChar(char c, char **cstring)
{
    const size_t length = strlen(*cstring) + 1;

    // Copies current string.
    char *buffer = new char[length];
    strcpy(buffer, *cstring);

    // Recreates string from copy with a size increase of 1.
    delete[] * cstring;
    *cstring = new char[length + 1];
    strncpy(*cstring, buffer, length - 1); // Doesn't copy NULL.
    delete[] buffer;

    // Puts next char into string and terminates it with NULL.
    *(*cstring + length - 1) = c;
    *(*cstring + length) = '\0';
}

int *getFreqsChars(char *cstring, const char *chars)
{
    const size_t length = strlen(chars);
    int *freqs = new int[length];
    bool isEmpty = true;

    // Initialises array with zeroes.
    for (int i = 0; i < length; i++)
    {
        freqs[i] = 0;
    }

    for (int i = 0; i < length; i++)
    {
        for (int j = 0; cstring[j] != '\0'; j++)
        {
            if (cstring[j] == chars[i])
            {
                freqs[i]++;
                isEmpty = false;
            }
        }
    }

    if (isEmpty)
    {
        delete[] freqs;
        freqs = nullptr;
    }

    return freqs;
}

void printCharsFreqs(const char *chars, const int *freqs)
{
    const size_t length = strlen(chars);
    bool isFirst = true;
    int highestFreq = 0;
    int highestIndex = -1; // Index of char with highest frequency.
    bool noHighest = false;

    for (int i = 0; i < length; i++)
    {
        int freq = freqs[i];

        if (freq != 0)
        {
            if (!isFirst)
            {
                cout << ", ";
            }

            cout << chars[i] << " [" << freq << "]";
            isFirst = false;
        }

        // Prints line feed after the last char.
        if (i == length - 1)
        {
            cout << "\n";
        }

        if (freq == highestFreq)
        {
            noHighest = true;
        }
        else if (freq > highestFreq)
        {
            highestFreq = freq;
            highestIndex = i;
            noHighest = false;
        }
    }

    cout << "Most frequently occurring: ";

    if (noHighest)
    {
        cout << "none" << endl;
    }
    else
    {
        cout << chars[highestIndex] << " [" << highestFreq << "]" << endl;
    }
}
