// Write a function that accepts either a pointer to a C-string, or a string,
// object, as its argument. The function should return the character that
// appears most frequently in the string. Demonstrate the function in a 
// complete program.
#include <iostream>
#include <cctype>

using namespace std;

// Counts the frequency of characters in a C-string and returns the most
// frequent character.
char mostFrequentCharacter(const char[]);

int main()
{
    const int SIZE = 128;
    char str[SIZE];
    cout << "Enter a string of characters (less than or equal to "
         << (SIZE - 1) << " digits): ";
    cin.getline(str, SIZE);

    char mostFrequent = mostFrequentCharacter(str);

    cout << "\nThe most frequent character is " << mostFrequent << endl;

    system("pause");
    return 0;
}

// Counts the frequency of characters in a C-string and returns the most
// frequent character.
char mostFrequentCharacter(const char characters[])
{
    int i = 0;
    int j;
    int size = strlen(characters);
    int *freqs = new int[size];

    for (int i = 0; i < size; i++)
    {
        freqs[i] = 0;
    }

    for (i = 0; i < size; i++)
    {
        for (j = i; j < size; j++)
        {
            if (characters[i] == characters[j])
            {
                freqs[i]++;
            }
        }
    }

    int mostFrequent = 0;
    for (i = 1; i < size; i++)
    {
        if (freqs[i] > freqs[mostFrequent])
        {
            mostFrequent = i;
        }
    }

    delete [] freqs;
    freqs = nullptr;
    char freqChar = characters[mostFrequent];
    return freqChar;
}